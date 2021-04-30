// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_LIBC_ASSERT
#define _GOS_LIBC_ASSERT

#include "stdint.h"

// TODO: Assertions properly?
#define assert(expr) ((expr) ? (void) 0 : (void) 0)

#endif
