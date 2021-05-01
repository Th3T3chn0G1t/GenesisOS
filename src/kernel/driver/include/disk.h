#ifndef _GOS_DISK
#define _GOS_DISK

#include "../../../libc/include/stdint.h"

#define _GOS_ATA_WAIT while(gos_io_port_in(0x3F6) & 0x88) 

#define GOS_DISK_MASTER 0xA0
#define GOS_DISK_SLAVE 0xB0

void gos_select_disk(uint8_t disk);
void gos_read_sector(uint32_t lba28_addr, uint8_t* target_buffer, uint8_t sector_count);

#endif
