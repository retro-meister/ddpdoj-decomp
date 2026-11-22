#include "common.h"


extern u16 D_002579D0[];
extern u8 *reg_a0;

void func_00150670(u8 arg0) {
    reg_d2.w = 0;
    reg_d2.b[0] = arg0;
    reg_a0 = (u8 *)(D_002579D0);
    reg_d2.h[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
}
