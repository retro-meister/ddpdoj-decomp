#include "common.h"

s32 func_0019C000();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0019E980(void) {
    u8 *save_a1;
    u8 *save_a6;

    save_a1 = reg_a1;
    save_a6 = reg_a6;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d3.w = 0;
    reg_d0.w = 0;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x14);
    reg_d0.h[0] &= 0x3E;
    if ((reg_d0.h[0] != 0) && ((s32)reg_d0.b[0] > 0x20)) {
        reg_d0.b[0] *= -1;
        reg_d3.h[0] = 0xFFFF;
        reg_d0.h[0] &= 0x3E;
    }
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] += *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    if ((s8)reg_d3.b[0] < 0) {
        reg_d1.h[0] *= 0xFFFF;
    }
    *(u16 *)reg_a0 = *(u16 *)(reg_a6 + 4);
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.w = 0;
    reg_a5 = (u8 *)reg_tmp.w;
    *(u16 *)reg_a0 = (reg_d6.h[0] != 0) ? *(u16 *)(reg_a5 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a5;
    reg_a0 += 2;
    *(u16 *)reg_a0 = ((reg_d6.h[0] + 2) != 0) ? *(u16 *)(reg_a5 + ((s16)(reg_d6.h[0] + 2) & ~1)) : *(u16 *)reg_a5;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u8 *)(reg_a0 - 2) = *(u8 *)(reg_a4 + 0x57);
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d7.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a4 + 0x5A);
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a4 + 0x20);
    reg_a0 += 2;
    if ((s8)reg_d3.b[0] < 0) {
        *(u8 *)(reg_a0 - 0x12) *= -1;
        *(u8 *)(reg_a0 - 0xF) |= 0x40;
    }
    reg_a6 = reg_a0 - 0x2C;
    func_0019C000();
    *(u16 *)(reg_a6 + 4) += reg_d1.h[0];
    reg_a1 = save_a1;
    reg_a6 = save_a6;
}
