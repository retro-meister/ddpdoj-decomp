#include "common.h"

s32 func_001713B0();
s32 func_001B6BA0();
extern u16 D_0026E160[];
extern u16 *reg_a0_as_u16_p;
extern u8 *reg_a4;

void func_001B6B20(void) {
    *(s16 *)(reg_a4 + 2) = 8;
    func_001713B0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0_as_u16_p = D_0026E160;
    *(u16 *)(reg_a4 + 4) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0_as_u16_p + ((s16)reg_d0.h[0] & ~1)) : *reg_a0_as_u16_p;
    func_001B6BA0();
}
