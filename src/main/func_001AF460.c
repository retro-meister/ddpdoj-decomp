#include "common.h"

s32 func_00135740();
s32 func_002075F0();
extern u16 D_0028C11C[];
extern u16 D_0028C120[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001AF460(void) {
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (8)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0xA)));
    reg_d0.w = 0;
    reg_a4 = (u8 *)reg_tmp.w;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0xF)));
    reg_a0 = (u8 *)(D_0028C11C);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0xE)));
    reg_a0 = (u8 *)(D_0028C120);
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 0;
    reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
    func_00135740();
    func_002075F0();
}
