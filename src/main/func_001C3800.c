#include "common.h"

s32 func_001292C0();
extern u16 D_00259870[];
extern u16 D_0028E47C;
extern u16 D_0028E47E;
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C3800(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u32 temp_a0;
    u32 temp_a0_2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x13)));
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d5.w = 0x08000000;
    reg_a0 = (u8 *)(D_00259870);
    D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    D_0028E47C = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&D_0028E47C;
    reg_d3.w += reg_d5.w;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d4.w = 0;
    func_001292C0();
    reg_d7.w = 0;
    reg_d7.b[0] = 9;
    reg_d6.b[0] = reg_d1.b[0];
    if ((*(u16 *)((u8 *)(reg_a4) + (0x16))) == 4) {
        reg_d7.b[0] = 2;
    }
    do {
        reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (7)));
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        D_0028E47C = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&D_0028E47C;
        reg_d3.w += reg_d5.w;
        func_001292C0();
        if (D_0028E910 != 0) {
            temp_a0 = reg_d0.w;
            reg_d0.w = temp_a0 + 0xFFFC0000;
            reg_d1.b[0] -= 2;
            func_001292C0();
            reg_d1.b[0] += 2;
            reg_d0.w += 0x40000;
        }
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d7.w = 0;
    reg_d7.b[0] = 9;
    reg_d1.b[0] = reg_d6.b[0];
    if ((*(u16 *)((u8 *)(reg_a4) + (0x16))) == 4) {
        reg_d7.b[0] = 2;
    }
    do {
        reg_d1.b[0] -= (*(u8 *)((u8 *)(reg_a4) + (7)));
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        D_0028E47C = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&D_0028E47C;
        reg_d3.w += reg_d5.w;
        func_001292C0();
        if (D_0028E910 != 0) {
            temp_a0_2 = reg_d0.w;
            reg_d0.w = temp_a0_2 + 0xFFFC0000;
            reg_d1.b[0] += 2;
            func_001292C0();
            reg_d1.b[0] -= 2;
            reg_d0.w += 0x40000;
        }
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}
