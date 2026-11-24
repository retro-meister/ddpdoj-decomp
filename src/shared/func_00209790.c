#include "common.h"

s32 func_002093C0();
extern u16 D_00268350[];
extern u8 D_0028DFA0_as_u8;
extern u16 *reg_a0_as_u16_p;

void func_00209790(void) {
    reg_d0.w = 3;
    reg_d1.w = 4;
    reg_a0_as_u16_p = D_00268350;
    reg_d1.b[0] -= D_0028DFA0_as_u8;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0_as_u16_p + ((s16)reg_d1.h[0] & ~1)) : *reg_a0_as_u16_p;
    reg_d2.w = 0;
    func_002093C0();
}
