// SPDX-License-Identifier: GPL-3.0-or-later 
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me> 
#include "include/terminal.h" 
#include "../include/kio.h" 
static uint16_t* _gos_vga_buffer = (uint16_t*) 0xB8000; 
static uint16_t _gos_terminal_cursor_x = 0;
static uint16_t _gos_terminal_cursor_y = 0;
static gos_vga_color _gos_terminal_color_fg = GOS_VGA_COLOR_LIGHT_GREY;
static gos_vga_color _gos_terminal_color_bg = GOS_VGA_COLOR_BLACK;
void _gos_vga_setcursor(int x, int y) { 
    uint16_t pos = (y * GOS_VGA_BUFF_WIDTH) + x;
    gos_io_port_out(0x3D4, 0x0F);
    gos_io_port_out(0x3D5, (uint8_t) (pos & 0xFF));
    gos_io_port_out(0x3D4, 0x0E);
    gos_io_port_out(0x3D5, (uint8_t) ((pos >> 8) & 0xFF)); 
} 

void gos_terminal_setcursor(uint16_t x, uint16_t y) {
    _gos_terminal_cursor_x = x;
    _gos_terminal_cursor_y = y;
    _gos_vga_setcursor(x, y);
}

void gos_terminal_setcolor(gos_vga_color fg, gos_vga_color bg) {
    _gos_terminal_color_fg = fg;
    _gos_terminal_color_bg = bg;
} 

void gos_terminal_clear(gos_vga_color col) {
    for(int i = 0; i < GOS_VGA_BUFF_WIDTH * GOS_VGA_BUFF_HEIGHT; i++) _gos_vga_buffer[i] = gos_vga_entry(' ', GOS_VGA_COLOR_BLACK, col); 
    gos_terminal_setcursor(0, 0); 
} 

void gos_terminal_putchar(char c) {
    if(!c) return;
    if(c == '\n') {
        _gos_terminal_cursor_x = 0;
        _gos_terminal_cursor_y++;
    }
    else if(c == '\b') {
        _gos_terminal_cursor_x--;
        if(_gos_terminal_cursor_x > GOS_VGA_BUFF_WIDTH) {
            _gos_terminal_cursor_x = GOS_VGA_BUFF_WIDTH;
            _gos_terminal_cursor_y--;
            if(_gos_terminal_cursor_y == 0xFFFF) {
                _gos_terminal_cursor_x = 0;
                _gos_terminal_cursor_y = 0;
            }
        }
        gos_terminal_putentry(gos_vga_entry(' ', _gos_terminal_color_fg, _gos_terminal_color_bg), _gos_terminal_cursor_x, _gos_terminal_cursor_y);
    }
    else if(c == '\t') {
        _gos_terminal_cursor_x += 4;
        if(_gos_terminal_cursor_x > GOS_VGA_BUFF_WIDTH) {
            _gos_terminal_cursor_x = 0;
            _gos_terminal_cursor_y++;
        }
    }
    else {
        gos_terminal_putentry(gos_vga_entry(c, _gos_terminal_color_fg, _gos_terminal_color_bg), _gos_terminal_cursor_x, _gos_terminal_cursor_y);
        _gos_terminal_cursor_x++;
        if(_gos_terminal_cursor_x > GOS_VGA_BUFF_WIDTH) {
            _gos_terminal_cursor_x = 0;
            _gos_terminal_cursor_y++;
        }
    }
    _gos_vga_setcursor(_gos_terminal_cursor_x, _gos_terminal_cursor_y);
}

void gos_terminal_puts(const char* str) {
    for(int i = 0; str[i]; i++) gos_terminal_putchar(str[i]);
}

const char _gos_hexcnvrt_table[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', };
void gos_terminal_puthex(uint8_t value) {
    gos_terminal_putchar(_gos_hexcnvrt_table[value >> 4]);
    gos_terminal_putchar(_gos_hexcnvrt_table[value & 0x0F]);
}
