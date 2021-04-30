// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_FILE
#define _GOS_FILE

#include "../../libc/include/stdint.h"

/*
0 	    100 	File name
100 	8 	    File mode
108 	8 	    Owner's numeric user ID
116 	8 	    Group's numeric user ID
124 	12 	    File size in bytes (octal base)
136 	12 	    Last modification time in numeric Unix time format (octal)
148 	8 	    Checksum for header record
156 	1 	    Type flag
157 	100 	Name of linked file
257 	6 	    UStar indicator "ustar" then NUL
263 	2 	    UStar version "00"
265 	32 	    Owner user name
297 	32 	    Owner group name
329 	8 	    Device major number
337 	8 	    Device minor number
345 	155 	Filename prefix 
*/

// FIXME: Non-USTAR files?
typedef struct {
    char name[100];
    char mode[8];
    char owner_id[8];
    char group_id[8];
    char size[12];
    char last_mod[12];
    char checksum[8];
    char type;
    char link_name[100];
    char magic[6];
    char version[2];
    char owner_name[32];
    char group_name[32];
    char devnum_maj[8];
    char devnum_min[8];
    char prefix[155];
} __attribute__((packed)) gos_file_header_raw_T;

typedef struct {
    char name[100];
    uint64_t size;

    uint32_t address;
    uint8_t* data;
} gos_file_T;

#endif
