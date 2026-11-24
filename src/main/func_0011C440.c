#include "common.h"

extern u8 D_002B6D50[];
extern u8 *reg_a0;

void func_0011C440(void) {
    u32 d0 = reg_d0.w;

    reg_d0.h[0] <<= 6;
    reg_a0 = D_002B6D50;
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] <<= 2;
    reg_a0 += reg_d0.h[0];
    reg_d0.w = d0;
    reg_d1.w = (u32)reg_d1.w;
}
