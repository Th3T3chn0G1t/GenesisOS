// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_KEYBOARD
#define _GOS_KEYBOARD

#include "../../../libc/include/stdint.h"
#include "layouts/common.h"

extern unsigned char gos_kbd[];

extern uint8_t flags;
typedef enum {
    GOS_KB_FLAG_SHIFT = 1 << GOS_KB_SHIFT,
    GOS_KB_FLAG_ALT = 1 << GOS_KB_ALT,
    GOS_KB_FLAG_CTRL = 1 << GOS_KB_CTRL
} gos_kbd_flags;

void _gos_kbd_callback(uint8_t ino, uint64_t rax);

#endif
