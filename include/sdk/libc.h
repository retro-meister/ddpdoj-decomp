#ifndef DDPDOJ_SDK_LIBC_H
#define DDPDOJ_SDK_LIBC_H

#include "types.h"

#ifdef DDPDOJ_PC
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *memalign(size_t alignment, size_t size);
#else
f32 sinf(f32 x);
void *memalign(u32 alignment, u32 size);
void *malloc(u32 size);
void free(void *ptr);
void *memcpy(void *dst, const void *src, u32 size);
void *memset(void *dst, s32 val, u32 size);
s32 printf(const char *fmt, ...);
s32 strlen(const char *s);
#endif

#endif
