#include "common.h"

extern s32 D_002B2750[];
extern s32 *reg_a0;
extern s32 reg_a1;

void func_00208A60(void)
{
    s32 *source = reg_a0;
    s32 *destination = D_002B2750;
    s32 offset;

    reg_d0.h[0] <<= 5;
    offset = (s32)reg_d0.h[0] >> 2;
    reg_a1 = reg_a1 + offset;
    reg_d0.w = 7;

    do {
        *destination++ = *source++;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
