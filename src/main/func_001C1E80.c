#include "common.h"

s32 func_00128930();
extern u16 D_00259870[];
extern u16 D_0028E47C;
extern u16 D_0028E47E;
extern u16 D_0028E910;
extern u8 *reg_a0;

void func_001C1E80(void) {
    u32 var_a1;
    reg_a0 = (u8 *)(D_00259870);
    reg_d0.w = 7;
    reg_d7.w = 3;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w = 0x170007;
        reg_d7.w = 1;
    }
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[0] += reg_d3.h[0];
        D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        D_0028E47C = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&D_0028E47C;
        reg_d3.w += reg_d5.w;
        func_00128930();
        var_a1 = reg_d0.w;
        reg_d0.w = var_a1 + 0x20000;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    if (D_0028E910 != 0) {
        reg_d0.w = 7;
        reg_d1.b[0] += 4;
        reg_d7.w = 1;
        reg_d1.h[0] &= 0x3F;
        if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
            reg_d7.w = 0;
            reg_d0.w = 0x170007;
        }
        do {
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] &= 0x3F;
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            D_0028E47C = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&D_0028E47C;
            reg_d3.w += reg_d5.w;
            func_00128930();
            var_a1 = reg_d0.w;
            reg_d0.w = var_a1 + 0x20000;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}
