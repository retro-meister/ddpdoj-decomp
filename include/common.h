#ifndef DDPDOJ_COMMON_H
#define DDPDOJ_COMMON_H

#include "types.h"

#define SJIS(s) s

typedef union {
    u32 w;
    s32 sw;
    u16 h[2];
    s16 sh[2];
    u8 b[4];
    s8 sb[4];
} Reg32;

extern u16 rng_cursor;
extern s8 rng_values[256];
extern u8 bcd_digits[4];

#endif
