#include "common.h"

s32 func_002093C0();
extern u16 D_00268350[];
extern u8 D_0028DFA0;
extern u16 *reg_a0;

void func_00209710(void) {
    reg_d0.w = 3;
    reg_d1.w = 4;
    reg_a0 = D_00268350;
    reg_d1.b[0] -= D_0028DFA0;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *reg_a0;
    reg_d2.w = -2U;
    func_002093C0();
}
