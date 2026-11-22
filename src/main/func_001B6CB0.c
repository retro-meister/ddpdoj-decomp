#include "common.h"

s32 func_001713B0();
s32 func_001B6D30();
extern u16 D_0026E180[];
extern u16 *reg_a0;
extern u8 *reg_a4;

void func_001B6CB0(void) {
    func_001713B0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = D_0026E180;
    *(u16 *)(reg_a4 + 2) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *reg_a0;
    *(s16 *)(reg_a4 + 4) = 2;
    func_001B6D30();
}
