#include "common.h"

s32 func_0013C300();
extern u8 D_002553F0[];
extern u8 D_002554F0[];
extern u32 D_0028E40C;
extern u32 D_0028E410;
extern u32 D_0028E414;
extern u32 D_0028E418;
extern u32 D_0028E41C;
extern u32 D_0028E420;
extern u32 D_0028E424;
extern u16 *D_0028E434_as_u16_p;
extern u32 D_0028E438_as_u32;
extern u8 *D_0028E43C;
extern u8 *D_0028E440;
extern u16 *D_0028E444_as_u16_p;
extern u8 D_0029C0C0[];
extern u8 D_0029C150[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;

void func_0013B990(void) {
    u8 *saved_a0;
    u8 *saved_a1;
    u32 t;
    u16 t5;

    reg_a1 = (u8 *)D_0029C0C0;
    reg_d7.w = 2;
loop_1:
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_3;
    *(u16 *)(reg_a1 + 0) = 0x8000;
    *(u16 *)(reg_a1 + 4) = reg_d6.h[0];
    saved_a0 = reg_a0;
    saved_a1 = reg_a1;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d6.h[0] = 0x13;
    reg_a2 = (u8 *)D_0029C150;
loop_2:
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_1;
    *(u16 *)(reg_a2 + 0) = 0x8000U;
    *(s16 *)(reg_a2 + 0x20) = 0;
    *(s16 *)(reg_a2 + 0x2C) = 0;
    *(s16 *)(reg_a2 + 0x2E) = 0;
    reg_tmp.w = (u32) reg_a2;
    *(u16 *)(reg_a1 + 0x2C) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 0x2E) = reg_tmp.h[0];
    reg_a1 = reg_a2;
    *(s16 *)(reg_a2 + 0x1E) = 0;
    *(s16 *)(reg_a2 + 2) = 0;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.w = (*(u32 *)((u8 *)((D_002554F0 + (reg_d2.h[0] & ~3))) + (4)));
    *(u16 *)(reg_a2 + 6) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 8) = reg_tmp.h[0];
    reg_a3 = *(u8 **)(D_002554F0 + (reg_d2.h[0] & ~3));
    t5 = *(u16 *)reg_a0;
    reg_a3 += t5;
    reg_a0 += 2;
    reg_tmp.w = (u32)reg_a3;
    *(u16 *)(reg_a2 + 0xE) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x10) = reg_tmp.h[0];
    *(u16 *)(reg_a2 + 0xA) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a2 + 0xC) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a2 + 4) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a3 = (u8 *)((u32) D_002553F0);
    reg_d3.h[0] &= 0x1F;
    reg_d3.h[0] *= 4;
    reg_a3 += reg_d3.h[0];
    *(u16 *)(reg_a2 + 0x16) = *(u16 *)reg_a3;
    reg_a3 += 2;
    *(u16 *)(reg_a2 + 0x14) = *(u16 *)(reg_a2 + 0x16);
    *(u16 *)(reg_a2 + 0x1C) = *(u16 *)reg_a3;
    reg_tmp.w = 0xFFFF0000;
    *(u16 *)(reg_a2 + 0x18) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x1A) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 0xE);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0x10);
    reg_a3 = (u8 *)(reg_tmp.w);
    reg_d4.h[0] = *(u16 *)(reg_a2 + 4);
    reg_a4 = (u8 *)(reg_a2 + 0x30);
    do {
        *(u16 *)reg_a4 = *(u16 *)reg_a3;
        reg_a3 += 2;
        reg_a4 += 2;
    } while ((s16)(--reg_d4.h[0]) >= 0);
    reg_d0.h[0] -= 1;
    if (reg_d0.h[0] == 0) goto next_2;
next_1:
    reg_a2 += 0x70;
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d0.w = -1;
next_2:
    reg_a0 = saved_a0;
    reg_a1 = saved_a1;
    if ((s16) reg_d0.h[0] >= 0) goto next_4;
    reg_d0.w = (u32) reg_a1;
    func_0013C300();
    goto next_5;
next_4:
    reg_d0.w = (u32) reg_a1;
    reg_d1.w = D_0028E424;
    reg_d2.w = D_0028E420;
    reg_d3.w = D_0028E41C;
    reg_d4.w = D_0028E418;
    reg_d5.w = D_0028E414;
    reg_d6.w = D_0028E410;
    reg_d7.w = D_0028E40C;
    reg_a0 = (u8 *) D_0028E444_as_u16_p;
    reg_a1 = (u8 *)D_0028E440;
    reg_a2 = (u8 *)D_0028E43C;
    reg_a3 = (u8 *) D_0028E438_as_u32;
    reg_a4 = (u8 *) D_0028E434_as_u16_p;
    return;
next_3:
    reg_a1 += 0x30;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_5:
    reg_d0.w = -1;
    reg_d1.w = D_0028E424;
    reg_d2.w = D_0028E420;
    reg_d3.w = D_0028E41C;
    reg_d4.w = D_0028E418;
    reg_d5.w = D_0028E414;
    reg_d6.w = D_0028E410;
    reg_d7.w = D_0028E40C;
    reg_a0 = (u8 *) D_0028E444_as_u16_p;
    reg_a1 = (u8 *)D_0028E440;
    reg_a2 = (u8 *)D_0028E43C;
    reg_a3 = (u8 *) D_0028E438_as_u32;
    reg_a4 = (u8 *) D_0028E434_as_u16_p;
}
