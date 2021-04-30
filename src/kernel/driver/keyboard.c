// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#include "include/keyboard.h"
#include "../include/kio.h"

// TODO: Remove terminal stuff
#include "include/terminal.h"

uint8_t flags = 0;

void _gos_kbd_callback(uint8_t ino, uint64_t rax) { 
    (void) ino; 
    (void) rax; 
    uint8_t scancode = gos_io_port_in(0x60);
    char c;
    // Keydown
    if(!(scancode & 0x80)) {
        c = gos_kbd[scancode];

        switch(c) {
            case GOS_KB_SHIFT: {
                flags |= GOS_KB_FLAG_SHIFT;
                break;
            }
            case GOS_KB_ALT: {
                flags |= GOS_KB_FLAG_ALT;
                break;
            }
            case GOS_KB_CTRL: {
                flags |= GOS_KB_FLAG_CTRL;
                break;
            }
            default: {
                if(flags & GOS_KB_FLAG_SHIFT) c = gos_kbd[scancode + 128];
                gos_terminal_putchar(c);
            }                
        }
    }
    // Keyup
    else {
        c = gos_kbd[scancode - 128];

        switch(c) {
            case GOS_KB_SHIFT: {
                flags &= ~GOS_KB_FLAG_SHIFT;
                break;
            }
            case GOS_KB_ALT: {
                flags &= ~GOS_KB_FLAG_ALT;
                break;
            }
            case GOS_KB_CTRL: {
                flags &= ~GOS_KB_FLAG_CTRL;
                break;
            }
            default: {
                if(flags & GOS_KB_FLAG_SHIFT) c = gos_kbd[scancode + 128];
            }                
        }
    }
}
