#include "common.h"


s32 func_0014BE20();
s32 func_0019D560();
extern u16 D_00257800[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00148730(void) {
    u32 temp_s0;

    temp_s0 = reg_d6.w;
    reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
    reg_a0 = (u8 *)(D_00257800);
    reg_d6.h[0] *= 2;
    reg_d6.h[1] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d6.h[0] = ((reg_d6.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d6.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_0019D560();
    reg_d6.w = temp_s0;
    reg_a0 = (u8 *)(reg_a6);
    func_0014BE20();
}
