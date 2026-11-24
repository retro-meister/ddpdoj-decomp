#include "common.h"

s32 func_00129BE0();
s32 func_00129EF0();
extern s16 D_0024F330[];
extern u8 *D_0028DEAC;
extern u16 D_0028E158;
extern u16 D_0028E15C;
extern s8 D_0028E310;
extern u8 D_0028E37C;
extern u8 D_0028E855;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern s16 D_00299760[];
extern u8 *D_00299770[];
extern u8 D_002A4670[];
extern u8 D_002A5050[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_00129DB0(void) {
    func_00129BE0();
    D_00299760[0] = 0;
    reg_a4 = (u8 *)D_002A4670;
    reg_a0 = (u8 *)D_002A5050;
    D_0028DEAC = (u8 *)(reg_a4);
    reg_a0 += D_0028E15C;
    D_00299770[0] = reg_a0;
    func_00129EF0();
    reg_d1.w = (u32) D_002A5050;
    reg_d0.w = (u32) D_00299770[0];
    reg_d0.w -= reg_d1.w;
    reg_a4 = (u8 *)((u32)reg_a4 - (u32)D_0028DEAC);
    reg_tmp.w = (u32) reg_a4;
    D_0028E15C = reg_d0.h[0];
    D_0028E158 = reg_tmp.h[0];
    if (D_0028E37C != 0) {
        reg_tmp.h[0] = (s16) D_0028E158 + (s16) D_0028E15C;
        reg_tmp.h[0] /= 0xC;
        if ((D_0028E855 & 2) && (D_0028E910 != 0) && (reg_tmp.h[0] > D_0024F330[D_0028E91C])) {
            D_0028E310 = 2;
        }
    }
}
