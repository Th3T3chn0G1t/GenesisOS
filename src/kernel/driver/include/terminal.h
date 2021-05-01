// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_TERMINAL
#define _GOS_TERMINAL

#include "../../../libc/include/stdint.h"

#define GOS_VGA_BUFF_WIDTH 80
#define GOS_VGA_BUFF_HEIGHT 25

typedef enum {
	GOS_VGA_COLOR_BLACK         	= 0,
	GOS_VGA_COLOR_BLUE          	= 1,
	GOS_VGA_COLOR_GREEN         	= 2,
	GOS_VGA_COLOR_CYAN          	= 3,
	GOS_VGA_COLOR_RED           	= 4,
	GOS_VGA_COLOR_MAGENTA       	= 5,
	GOS_VGA_COLOR_BROWN         	= 6,
	GOS_VGA_COLOR_LIGHT_GREY    	= 7,
	GOS_VGA_COLOR_DARK_GREY     	= 8,
	GOS_VGA_COLOR_LIGHT_BLUE    	= 9,
	GOS_VGA_COLOR_LIGHT_GREEN   	= 10,
	GOS_VGA_COLOR_LIGHT_CYAN    	= 11,
	GOS_VGA_COLOR_LIGHT_RED     	= 12,
	GOS_VGA_COLOR_LIGHT_MAGENTA 	= 13,
	GOS_VGA_COLOR_LIGHT_BROWN   	= 14,
	GOS_VGA_COLOR_WHITE         	= 15
} gos_vga_color;


#define gos_vga_entry(c, fg, bg) ((uint16_t) c | (uint16_t) (fg | bg << 4) << 8)
#define gos_terminal_putentry(e, x, y) _gos_vga_buffer[(y * GOS_VGA_BUFF_WIDTH) + x] = e

void gos_terminal_setcursor(uint16_t x, uint16_t y);
void gos_terminal_setcolor(gos_vga_color fg, gos_vga_color bg);
void gos_terminal_clear(gos_vga_color col);

void gos_terminal_putchar(char c);
void gos_terminal_puts(const char* str);
void gos_terminal_puthex(uint8_t value);

#endif
