// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>

#include "boot/include/boot.h" 
#include "boot/include/gdt.h" 
#include "interrupt/include/idt.h" 
#include "interrupt/include/isr.h" 
#include "interrupt/include/pic.h" 
#include "driver/include/terminal.h" 
#include "include/file.h" 
#include "driver/include/layouts/us.h" 
#include "include/kio.h" 
#include "include/error.h" 
#include "../libc/include/string.h" 
#include "driver/include/keyboard.h"
#include "driver/include/disk.h"

#define ATA_WAIT while(gos_io_port_in(0x3F6) & 0x88) 

int octoi(const char* str) {
    int ret = 0;
    for(char* c = (char*)str; *c; c++) ret += (*c - '0');
    return ret;
}

void _start(struct stivale2_struct *stivale2_struct) {
    (void) stivale2_struct;
    _gos_gdt_install();
    _gos_idt_install();
    _gos_isr_install();
    _gos_pic_install();
    
    int pit_freq = 1000;
    gos_io_port_out(0x40, pit_freq & 0x00FF);
    gos_io_port_out(0x40, ((uint16_t) pit_freq >> 8));

    for(int i = 0; i < 32; i++) gos_register_interrupt_callback(i, _gos_exception_handler);
    gos_register_interrupt_callback(33, _gos_kbd_callback); 

    gos_select_disk(GOS_DISK_SLAVE);

    uint32_t sector = 0;
    while(true) {
        gos_file_header_raw_T file_header;
        gos_read_sector(sector, (uint8_t*)&file_header, 1); 
        if(strncmp(file_header.magic, "ustar", 5)) {
            gos_terminal_putchar('\n');
            for(long unsigned int i = 0; i < sizeof(gos_file_header_raw_T); i++)
                gos_terminal_puthex(((char*)&file_header)[i]);
            gos_terminal_putchar('\n');
            break;
        }
        gos_terminal_puts(file_header.size);
        gos_terminal_putchar('\n');
        gos_terminal_puthex(octoi(file_header.size));
        gos_terminal_putchar('\n');
        gos_terminal_puthex(sector);
        gos_terminal_putchar('\n');

        sector += octoi(file_header.size);

        gos_terminal_puts(file_header.name);
        gos_terminal_putchar('\n');
    }
    
    gos_terminal_puts("GOS Kernel v0.2.1\n\n> "); 
    while(true) {} 
}
