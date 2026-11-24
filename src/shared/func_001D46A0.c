#include "common.h"

s32 func_00128AC0();
extern u16 D_00259870[];
extern u8 *reg_a0;

void func_001D46A0(void) {
    reg_d0.w = 0xFFFC0004;
    reg_d1.h[0] -= 0xC;
    reg_d7.w = 6;
    reg_a0 = (u8 *)(D_00259870);
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] *= 4;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w += reg_d5.w;
        func_00128AC0();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
