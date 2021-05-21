// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_FILE
#define _GOS_FILE

#include "../../libc/include/stdint.h"

typedef struct {
    char magic[4];
    union {
        char size_raw[4];
        int size;
    };
    char name[504];
} __attribute__((packed)) gos_file_header_raw_T;

#endif
