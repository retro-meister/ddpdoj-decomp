#include "common.h"

extern s8 D_0028E408;

s32 func_0014E290();
s32 func_0019C570();
s32 func_00201C60();
s32 func_00203060();
extern u16 D_0028E574[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C4650(void) {
    u16 temp_a2;

    reg_d1.w = 0x5C;
    if ((reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)))) != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x7FFF;
        if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
            func_0014E290();
        }
    }
    func_00203060();
    if (D_0028E408 != 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_7;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_7:
    func_00201C60();
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a2;
    reg_d1.w += 0xF800FC00;
    reg_d3.h[0] = 0x820;
    reg_d4.h[0] = 0x1A;
    reg_a0 = (u8 *)(D_0028E574);
    reg_d2.w = 0;
    reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    if ((s16)(reg_d2.h[0]) > 0x20) {
        reg_d4.h[0] |= 0x40;
    }
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_0019C570();
}
