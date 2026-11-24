#include "common.h"

s32 func_0014D220();
s32 func_0019C570();
extern u16 D_00258280[];
extern u16 D_0028E3F0;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00157740(void) {
    u16 temp_a1;
    if (D_0028E3F0 & 1) {
        (*(u16 *)((u8 *)(reg_a5) + (0x28))) += 4;
        (*(u16 *)((u8 *)(reg_a5) + (0x28))) &= 7;
    }
    reg_d0.w = 0;
    reg_a0 = (u8 *)(D_00258280);
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_d0.b[0] += 1;
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] *= 4;
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x28)));
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FB00;
    reg_d3.h[0] = 0x628;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C570();
    reg_a0 = (u8 *)(reg_a6);
    func_0014D220();
}
