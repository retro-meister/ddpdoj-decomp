#include "common.h"

s32 func_001713B0();
s32 func_001B64D0();
s32 func_002011A0();
extern u16 D_0026E100[];
extern u16 D_0026E110[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_001B63D0(void) {
    func_001713B0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)(D_0026E110);
    (*(u16 *)((u8 *)(reg_a4) + (2))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_0026E100);
    (*(u16 *)((u8 *)(reg_a4) + (4))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x18;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = 0U;
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 2;
    func_002011A0();
    reg_d0.h[0] &= 1;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_d0.h[0];
    func_001B64D0();
}
