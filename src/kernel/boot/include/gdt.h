// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_GDT
#define _GOS_GDT

#include "../../../libc/include/stdint.h"

#define GOS_GDT_KERNEL_CODE_SELECTOR 0x08
#define GOS_GDT_KERNEL_DATA_SELECTOR 0x10

typedef struct {
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t  base_middle;
	uint8_t  access;
	uint8_t  granularity;
	uint8_t  base_high;
} __attribute__((packed)) _gos_gdt_entry_T;

typedef struct {
	uint16_t limit;
	uint64_t base;
} __attribute__((packed)) gos_gdt_ptr_T;

typedef union {
	_gos_gdt_entry_T entry;
	uint64_t integer;
} gos_gdt_entry;

void _gos_gdt_flush();
void _gos_gdt_set_gate(int num, uint8_t access, uint8_t gran);
void _gos_gdt_install();

#endif
