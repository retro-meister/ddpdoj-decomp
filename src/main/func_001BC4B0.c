#include "common.h"


s32 func_00129410();
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001BC4B0(void) {

    reg_d0.w = 0x50003;
    reg_d7.w = 3;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w += 0x12000000;
        if (!((*(u8 *)((u8 *)(reg_a6) + (0xC))) & 1)) {
            func_00129410();
        }
        reg_d1.h[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
