#include "common.h"

s32 func_0019C790();
extern u16 D_00257DB0[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001563B0(void) {
    u16 temp_a2;
    u32 temp_a1;

    if ((*(u8 *)((u8 *)(reg_a5) + (0x1F))) == 0) {
        (*(u16 *)((u8 *)(reg_a5) + (0x30))) += 4;
        (*(u16 *)((u8 *)(reg_a5) + (0x30))) &= 0xF;
        reg_a0 = (u8 *)(D_00257DB0);
        reg_d2.w = 0;
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
        reg_d2.b[0] += 1;
        reg_d2.h[0] &= 0x3E;
        reg_d2.h[0] *= 4;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x30)));
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        temp_a1 = reg_d1.w;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (6)));
        temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (8)));
        reg_tmp.h[0] = temp_a2;
        reg_d4.w = 0;
        reg_d1.w = temp_a1 + reg_tmp.w;
        reg_d1.w += 0xF400F600;
        reg_d3.h[0] = 0xC50;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
        func_0019C790();
    }
}
