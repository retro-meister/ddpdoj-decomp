#include "common.h"


s32 func_0019D2C0();
extern u32 D_002697E0[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001285A0(void) {
    u16 temp_a2;
    u16 temp_a3;
    u32 temp_a0;

    temp_a3 = (u32)reg_d1.h[0] + 0x400;
    reg_d1.h[0] = temp_a3;
    temp_a2 = (u32)reg_d1.h[1] + 0x40;
    reg_d1.h[1] = temp_a2;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x12)));
    reg_a0 = (u8 *)(D_002697E0);
    reg_a0 += reg_d0.h[0];
    temp_a0 = *(u32 *)reg_a0;
    reg_d2.w = temp_a0;
    reg_d3.h[0] = 0x420;
    reg_d4.h[0] = 0x1D;
    func_0019D2C0();
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) -= 4;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x12))) < 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x12))) = 0x10U;
    }
}
