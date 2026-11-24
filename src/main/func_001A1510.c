#include "common.h"

s32 func_0019D4D0();
s32 func_0019F2E0();
extern u16 D_0025F1D0[];
extern u16 D_0028DFC0;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001A1510(void) {
    u32 p0;
    *(u16 *)(reg_a6 + 2) = (u16) *(u16 *)(reg_a4 + 2);
    *(u16 *)(reg_a6 + 4) = (u16) *(u16 *)(reg_a4 + 4);
    reg_d2.w = 0;
    reg_d1.h[0] &= 0x3F;
    reg_d5.h[0] = reg_d1.h[0];
    *(u8 *)(reg_a6 + 0x1D) &= 0xBF;
    if ((s32) reg_d5.b[0] > 0x20) {
        *(u8 *)(reg_a6 + 0x1D) |= 0x40;
        reg_d5.b[0] *= -1;
        reg_d2.w = 1;
        reg_d5.h[0] &= 0x3F;
    }
    reg_d5.h[0] *= 4;
    *(u16 *)(reg_a6 + 0xA) = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a6 + 0xC) = ((reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d6.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_d6.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
    reg_a3 = (u8 *)(D_0025F1D0);
    reg_d0.h[0] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_d5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
    if (*(u8 *)reg_a4 & 1) {
        reg_d1.h[0] = reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 2);
        reg_d5.h[0] += reg_d1.h[0];
    }
    if (reg_d2.h[0] != 0) {
        reg_d5.h[0] *= 0xFFFF;
    }
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    p0 = *(u16 *)(reg_a6 + 4);
    *(u16 *)(reg_a6 + 4) = (u16) (p0 + reg_d5.h[0]);
    if (D_0028DFC0 == 0) {
        func_0019F2E0();
        func_0019D4D0();
    }
}
