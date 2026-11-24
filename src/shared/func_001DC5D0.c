#include "common.h"


s32 func_001DC160();
extern u16 D_0026EF50[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001DC5D0(void) {
    u16 temp_a1;
    reg_d0.w = 0;
    reg_a0 = (u8 *)(D_0026EF50);
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x11A)));
    reg_d0.b[0] += 1;
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x102)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x104)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FB00;
    reg_d3.h[0] = 0x628;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x11C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x14A)));
    func_001DC160();
}
