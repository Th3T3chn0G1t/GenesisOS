// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_PIC
#define _GOS_PIC

#include "../../../libc/include/stdint.h"
#include "../../include/kio.h"

#define _GOS_PIC_MASTER 0x20
#define _GOS_PIC_SLAVE  0xA0
#define _GOS_PIC_DATA_SEL(pic) (pic + 1)

#define _GOS_EOI 0x20

void _gos_pic_install();

void gos_pic_eoi(uint8_t ino);

#endif
