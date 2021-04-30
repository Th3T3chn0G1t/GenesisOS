// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_BOOTSTRAP
#define _GOS_BOOTSTRAP

#include "../../../libc/include/stdint.h"
#include "../../../libc/include/stddef.h"
#include "../../../vendor/stivale/stivale2.h"
#include "../../driver/include/terminal.h"

void *stivale2_get_tag(struct stivale2_struct *stivale2_struct, uint64_t id);

#endif
