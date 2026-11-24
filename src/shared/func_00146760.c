#include "common.h"

typedef void (*Fn)();

extern u8 D_00257760[];
extern u8 D_002577B0[];
extern u16 D_0028DFE4;
extern u16 D_0028E5AC;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u16 D_0029D790_as_u16_a[];
extern u16 D_0029DD90_as_u16_a[];
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00146760(void) {
    s32 temp_s0;
    temp_s0 = (s32)reg_a5;
    D_0028E5AC = 0;
    D_0028DFE4 = 0;
    if (D_0029F260[0] < 0) {
        reg_a6 = (u8 *)(D_0029DD90_as_u16_a);
        reg_d7.w = 0x1F;
        D_0028E5AC = D_0028E5FC;
        do {
            reg_d0.h[0] = *(u16 *)reg_a6;
            if (reg_d0.h[0] != 0) {
                reg_d1.w = 0x1F;
                D_0028DFE4 += 1;
                reg_d1.h[0] &= reg_d0.h[0];
                ((Fn)*(u32 *)((u8 *)D_00257760 + (reg_d1.h[0] * 4)))();
            }
            reg_a6 += 0x30;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    if (D_0029F1F0[0] < 0) {
        reg_a6 = (u8 *)(D_0029D790_as_u16_a);
        reg_d7.w = 0x1F;
        D_0028E5AC = D_0028E5F8;
        do {
            reg_d0.h[0] = *(u16 *)reg_a6;
            if (reg_d0.h[0] != 0) {
                reg_d1.w = 0x1F;
                D_0028DFE4 += 1;
                reg_d1.h[0] &= reg_d0.h[0];
                ((Fn)*(u32 *)((u8 *)D_002577B0 + (reg_d1.h[0] * 4)))();
            }
            reg_a6 += 0x30;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    reg_a5 = (u8 *)temp_s0;
}
