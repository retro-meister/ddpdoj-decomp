#include "common.h"

s32 func_002114C0();
extern u16 D_0025B150[];
extern u16 *reg_a0_as_u16_p;
extern u8 *reg_a6;

void func_0016CF40(void) {
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1E)));
    reg_a0_as_u16_p = D_0025B150;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0_as_u16_p + ((s16)reg_d1.h[0] & ~1)) : *reg_a0_as_u16_p;
    func_002114C0();
}
