#include "common.h"

extern u16 D_0025AEA8[];
extern u16 *reg_a0_as_u16_p;
extern u8 *reg_a6;

void func_00170CA0(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1E)));
    reg_a0_as_u16_p = D_0025AEA8;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0_as_u16_p + ((s16)reg_d0.h[0] & ~1)) : *reg_a0_as_u16_p;
}
