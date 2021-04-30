// SPDX-License-Identifier: GPL-3.0-or-later
// Copyright (C) 2021 TTG <prs.ttg+gos@pm.me>
#ifndef _GOS_LIBC_STRING
#define _GOS_LIBC_STRING

unsigned long strlen(const char* str);
int strncmp(const char* a, const char* b, unsigned long n);
void strncpy(const char* src, char* dest, unsigned long n);

#endif
