#include "common.h"


extern u16 D_0026EBF0[];
extern u8 D_0026EC60[];
extern u8 *reg_a0;

void func_001D7940(void) {
    u8 temp_a1;

    if ((s16)(reg_d0.h[0]) > 0x17) {
        reg_d0.h[0] -= 0x18;
    }
    reg_d1.w = 0;
    temp_a1 = *(D_0026EC60 + reg_d0.h[0]);
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)(D_0026EBF0);
    reg_d1.b[0] = temp_a1;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
}
