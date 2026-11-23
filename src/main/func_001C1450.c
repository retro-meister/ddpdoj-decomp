#include "common.h"

s32 func_00129280();
extern u16 D_00259870[];
extern u16 D_0028E47C;
extern u16 D_0028E47E;
extern u16 D_0028E910;
extern u8 *reg_a0;

void func_001C1450(void) {
    reg_a0 = (u8 *)(D_00259870);
    reg_d0.w = 0xFFFF0007;
    reg_d1.b[0] -= 2;
    if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    D_0028E47C = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&D_0028E47C;
    reg_d3.w += reg_d5.w;
    func_00129280();
    reg_d0.w = 0xFFFF0007;
    reg_d1.b[0] += 2;
    if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    D_0028E47C = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&D_0028E47C;
    reg_d3.w += reg_d5.w;
    func_00129280();
    reg_d0.w = 0xFFFF0007;
    reg_d1.b[0] += 2;
    if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    D_0028E47C = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&D_0028E47C;
    reg_d3.w += reg_d5.w;
    func_00129280();
    if (D_0028E910 != 0) {
        reg_d0.w = 0xFFFD0007;
        reg_d1.b[0] += 1;
        if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
            reg_d0.w += 0x80000;
        }
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        D_0028E47C = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&D_0028E47C;
        reg_d3.w += reg_d5.w;
        func_00129280();
        reg_d0.w = 0xFFFD0007;
        reg_d1.b[0] -= 6;
        if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
            reg_d0.w += 0x80000;
        }
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        D_0028E47C = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&D_0028E47C;
        reg_d3.w += reg_d5.w;
        func_00129280();
    }
}
