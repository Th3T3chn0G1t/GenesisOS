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



#define ATA_WAIT while(gos_io_port_in(0x3F6) & 0x88) 

void read_sector(uint32_t lba28_addr, uint8_t* target_buffer) { 
    // FIXME: More sectors
    uint8_t sector_count = 1; 
    gos_io_port_out(0x1F6, 0xF0 | ((lba28_addr >> 24) & 0x0F)); 
    ATA_WAIT; 
    gos_io_port_out(0x1F2, sector_count); 
    gos_io_port_out(0x1F3, (uint8_t) lba28_addr); 
    gos_io_port_out(0x1F4, (uint8_t) (lba28_addr >> 8)); 
    gos_io_port_out(0x1F5, (uint8_t) (lba28_addr >> 16)); 
    gos_io_port_out(0x1F7, 0x20);
    ATA_WAIT; 
    for(int i = 0; i < 256; i++) { 
        uint16_t inb = gos_io_port_in_16(0x1F0); 
        target_buffer[i * 2] = (uint8_t) inb; 
        target_buffer[(i * 2) + 1] = (uint8_t) (inb >> 8); 
        ATA_WAIT; 
    }
} 

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
    
    for(int i = 0; i < 32; i++) gos_register_interrupt_callback(i, _gos_exception_handler);
    
    // Sets PIT to 1000hz 
    gos_io_port_out(0x40, 1000 & 0x00FF);
    gos_io_port_out(0x40, ((uint16_t) 1000 >> 8));
    
    gos_register_interrupt_callback(33, _gos_kbd_callback); 

    // Select slave
    gos_io_port_out(0x1F6, 0xB0); 
    for(int i = 0; i < 15; i++) ATA_WAIT; 
    gos_file_T fs_root[10]; 
    for(int i = 0; i < 10; i++) { 
        for(int j = 0; j < 100; j++) fs_root[i].name[j] = 0; 
        fs_root[i].address = 0; 
        fs_root[i].size = 0; 
        fs_root[i].data = 0; 
    } 
    uint8_t data[512]; 
    uint32_t sector = 0; 
    for(int i = 0;;i++) { 
        read_sector(sector, (uint8_t*)data); 
        gos_file_header_raw_T* file = (gos_file_header_raw_T*) data; 
        if(strncmp(file->magic, "ustar", 5)) break; 
        strncpy(file->name, fs_root[i].name, strlen(file->name)); 
        fs_root[i].address = sector; 
        fs_root[i].size = octoi(file->size); 
        fs_root[i].data = 0; sector += octoi(file->size); 
    } 
    gos_terminal_puts("GOS Kernel v0.1.1\n\n> "); 
    for(int i = 0; fs_root[i].name[0]; i++) gos_terminal_puts(fs_root[i].name); 
    while(true) {} 
}
