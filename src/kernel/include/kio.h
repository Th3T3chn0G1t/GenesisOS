// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_KIO
#define _GOS_KIO

#include "../../libc/include/stdint.h"

void gos_io_port_out(uint16_t port, uint8_t value);

uint8_t gos_io_port_in(uint16_t port);

uint16_t gos_io_port_in_16(uint16_t port);

#define gos_io_wait() gos_io_port_out(0x80, 0)

#endif
