// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_IDT
#define _GOS_IDT

#include "../../../libc/include/stdint.h"
#include "../../../libc/include/stdbool.h"

#define GOS_IDT_TYPE_TASK32 0x5
#define GOS_IDT_TYPE_INT16  0x6
#define GOS_IDT_TYPE_TRAP16 0x7
#define GOS_IDT_TYPE_INT32  0xE
#define GOS_IDT_TYPE_TRAP32 0xF

#define GOS_IDT_GATE_LIMIT 256

typedef struct {
   uint16_t offset_low;
   uint16_t selector;
   uint8_t ist;
   uint8_t type_attr;
   uint16_t offset_mid;
   uint32_t offset_high;
   uint32_t zero;
} __attribute__((packed)) gos_idt_entry_T;

typedef struct {
	uint16_t limit;
	gos_idt_entry_T* base;
} __attribute__((packed)) gos_idt_ptr_T;

void _gos_idt_set_gate(uint8_t num, uint64_t base, uint16_t sel, uint8_t type, bool active);
void _gos_idt_install();

#endif
