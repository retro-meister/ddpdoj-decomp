#include "common.h"

s32 func_0013A780();
extern u8 *reg_a0;
extern u16 *reg_a1_as_u16_p;
extern u8 *reg_a6;

void func_0016CEA0(void) {
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1F)));
    (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1_as_u16_p + ((s16)reg_d0.h[0] & ~1)) : *reg_a1_as_u16_p;
    (*(s16 *)((u8 *)(reg_a0) + (0x10))) = 1;
}
