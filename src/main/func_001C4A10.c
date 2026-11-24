#include "common.h"

s32 func_0014E290();
s32 func_0019D620();
s32 func_00201F20();
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C4A10(void) {
    reg_d1.w = 0x5C;
    if ((reg_d1.b[0] &= *(u8 *)(reg_a6 + 1)) != 0) {
        reg_d0.b[0] = 0xA3;
        *(u8 *)(reg_a6 + 1) &= reg_d0.b[0];
        *(s16 *)(reg_a6 + 0x18) = 0x7FFF;
    }
    func_00201F20();
    if (0 > *(s16 *)(reg_a6 + 2)) goto block_e1;
    if (*(s16 *)(reg_a6 + 2) > 0x7000) goto block_e1;
    if (0 > *(s16 *)(reg_a6 + 4)) goto block_e1;
    if (*(s16 *)(reg_a6 + 4) > 0x3800) goto block_e1;
    goto block_l1;
block_e1:
    func_0014E290();
block_l1:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
        reg_a0 = (u8 *)(reg_tmp.w);
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
        *(u16 *)(reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x20) += 4;
        *(u16 *)(reg_a5 + 0x20) &= 0xF;
    }
    func_0019D620();
}
