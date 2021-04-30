// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_LIBC_STDDEF
#define _GOS_LIBC_STDDEF

typedef long          int ptrdiff_t;
typedef long unsigned int size_t;
typedef long              ssize_t;
typedef               int wchar_t;
typedef      unsigned int wint_t;

#define NULL ((void*) 0)

#endif
