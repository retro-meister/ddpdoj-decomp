#include "common.h"

s32 func_0019D4D0();
s32 func_0019F620();
s32 func_00201C20();
s32 func_00201D10();
extern u16 D_0025F5A8[];
extern u16 D_0025F5C0[];
extern u16 D_0028DFC0;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001A2680(void) {
    u32 temp_a0;
    u32 temp_a0_2;
    reg_d1.w = 0x3F;
    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00201D10();
    reg_d0.h[0] = reg_d2.h[0];
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
    reg_d2.h[0] -= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d2.h[0];
    if ((*(u8 *)((u8 *)(reg_a4) + (0))) & 1) {
        reg_d0.h[0] = reg_d3.h[0];
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        reg_d3.h[0] += reg_d0.h[0];
    }
    if ((*(u16 *)((u8 *)(reg_a4) + (0x5A))) != 6) {
        reg_d0.h[0] = reg_d3.h[0];
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
    } else {
        reg_d0.h[0] = reg_d3.h[0];
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    }
    reg_d3.h[0] += reg_d0.h[0];
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (temp_a0 + reg_d3.h[0]);
    if (D_0028DFC0 == 0) {
        if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0))) >= 0) {
            func_0019D4D0();
            return;
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x38)));
        switch (reg_d0.h[0]) { case 0: break; default:
            reg_a0 = (u8 *)(D_0025F5C0);
            reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
            (*(u16 *)((u8 *)(reg_a6) + (2))) -= reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x38))) -= 2;
            func_0019F620();
            func_0019D4D0();
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x56)));
        (*(u16 *)((u8 *)(reg_a6) + (0x56))) -= 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x56))) < 0) {
            (*(u16 *)((u8 *)(reg_a6) + (0x56))) = 8U;
        }
        temp_a0_2 = reg_d0.h[0];
        reg_a0 = (u8 *)(D_0025F5A8);
        reg_d1.h[0] = ((temp_a0_2 + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(temp_a0_2 + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = (temp_a0_2 != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)temp_a0_2 & ~1)) : *(u16 *)reg_a0;
        func_00201C20();
        func_0019F620();
        func_0019D4D0();
    }
}
