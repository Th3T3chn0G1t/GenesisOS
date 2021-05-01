#include "include/disk.h"
#include "../include/kio.h"

void gos_select_disk(uint8_t disk) {
    gos_io_port_out(0x1F6, disk); 
    for(int i = 0; i < 15; i++) _GOS_ATA_WAIT;
}

void gos_read_sector(uint32_t lba28_addr, uint8_t* target_buffer, uint8_t sector_count) { 
    if(!sector_count) return;

    gos_io_port_out(0x1F6, 0xF0 | ((lba28_addr >> 24) & 0x0F)); 
    _GOS_ATA_WAIT; 
    gos_io_port_out(0x1F2, sector_count); 
    gos_io_port_out(0x1F3, (uint8_t) lba28_addr); 
    gos_io_port_out(0x1F4, (uint8_t) (lba28_addr >> 8)); 
    gos_io_port_out(0x1F5, (uint8_t) (lba28_addr >> 16)); 
    gos_io_port_out(0x1F7, 0x20);
    _GOS_ATA_WAIT; 
    for(int i = 0; i < (256 * sector_count); i++) { 
        uint16_t inb = gos_io_port_in_16(0x1F0); 
        target_buffer[i * 2] = (uint8_t) inb; 
        target_buffer[(i * 2) + 1] = (uint8_t) (inb >> 8); 
        _GOS_ATA_WAIT;
    }
} 
