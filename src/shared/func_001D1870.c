#include "common.h"

s32 func_0019C670();
extern u16 D_002590F0[];
extern Reg32 D_0028E480;
extern Reg32 D_0028E484;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001D1870(void) {
    u16 temp_a0;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xB2)));
    reg_a0 = (u8 *)(D_002590F0);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    D_0028E480.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    D_0028E480.h[0] = (((reg_d2.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d2.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = D_0028E480.w;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
    reg_d1.h[0] += 0xD00;
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
    reg_d1.h[0] = temp_a0;
    reg_d3.h[0] = 0x418;
    reg_d4.w = 0;
    reg_d1.h[0] += 0x7FFF + 0x7C81;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x66)));
    func_0019C670();
}
