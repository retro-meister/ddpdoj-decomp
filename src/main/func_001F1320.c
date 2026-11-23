#include "common.h"

s32 func_0019C670();
extern u16 D_00264A70[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001F1320(void) {
    u16 temp_a2;
    reg_a0 = (u8 *)(D_00264A70);
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x12E)));
    reg_d2.h[0] -= 0x18;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a2;
    reg_d1.w += 0xFE00FF00;
    reg_d4.w = 0;
    reg_d1.w += 0xF7C00000;
    reg_d3.h[0] = 0x208;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xEC)));
    func_0019C670();
}
