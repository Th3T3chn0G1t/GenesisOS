// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_ERROR
#define _GOS_ERROR

#include "../../libc/include/stdint.h"

void _gos_exception_handler(uint8_t ino, uint64_t rax);
void gos_panic(const char* msg);

#endif
