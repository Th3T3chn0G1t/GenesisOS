CC = gcc
ASM = nasm

disk = boot/disk.hdd

src = 	$(wildcard src/kernel/*.c) \
		$(wildcard src/kernel/driver/*.c) \
		$(wildcard src/kernel/boot/*.c) \
		$(wildcard src/kernel/interrupt/*.c) \
		$(wildcard src/kernel/memory/*.c) \
		\
		$(wildcard src/libc/*.c)

asm = $(wildcard src/kernel/interrupt/*.asm)
obj = $(src:.c=.o) $(asm:.asm=.o)

out = boot/genesis.elf

file = $(shell find src/file)

fsout = boot/genesisfs.gfs

# FIXME:  -fsanitize=undefined
c_flags = -c -O0 \
	-m64 -mrdrnd -mno-80387 -mno-mmx -mno-3dnow -mno-sse -mno-sse2 -mcmodel=kernel -mno-red-zone \
	-ffreestanding -fno-pic \
	-Wall -Werror -Wextra -Wpedantic
asm_flags = -f elf64
l_flags = -Tsrc/kernel.ld -ffreestanding -O2 -nostdlib -static -no-pie

all: $(out)

genesis.asm: $(out)
	objdump $^ -dS -Mintel > $@

run: $(disk) $(fsout)
	qemu-system-x86_64 -s -no-reboot -no-shutdown -monitor stdio -hda $(disk) -hdb $(fsout)

$(fsout): $(file)
	tools/mkgfsimg $@ $^

$(disk): $(out)
	-rm $(disk)
	dd if=/dev/zero bs=1M count=0 seek=64 of=$(disk)
	parted -s $(disk) mklabel gpt
	parted -s $(disk) mkpart primary 2048s 100%
	echfs-utils -g -p0 $(disk) quick-format 512
	echfs-utils -g -p0 $(disk) import boot/limine.cfg limine.cfg
	echfs-utils -g -p0 $(disk) import /usr/local/share/limine/limine.sys limine.sys
	echfs-utils -g -p0 $(disk) import $^ kernel.elf
	limine-install $(disk)

$(out): $(obj)
	$(CC) $(l_flags) $^ -o $@

%.o: %.c
	$(CC) $(c_flags) $^ -o $@

%.o: %.asm
	$(ASM) $(asm_flags) $^ -o $@

clean:
	-rm $(obj)
	-rm $(out)
	-rm -f $(disk)
	-rm $(fsout)
	-rm genesis.asm
