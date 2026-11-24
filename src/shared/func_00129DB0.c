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
extern u8 D_002962E0[];
#ifdef DEATH_LABEL
extern s16 death_D_002512A0[];
extern s16 death_D_002512B0[];
#endif
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
    *(u8 **)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3490, 0x10690)) = reg_a0;
    func_00129EF0();
    reg_d1.w = (u32) D_002A5050;
    reg_d0.w = (u32) *(u8 **)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3490, 0x10690));
    reg_d0.w -= reg_d1.w;
    reg_a4 = (u8 *)((u32)reg_a4 - (u32)D_0028DEAC);
    reg_tmp.w = (u32) reg_a4;
    D_0028E15C = reg_d0.h[0];
    D_0028E158 = reg_tmp.h[0];
#ifdef DEATH_LABEL
    if (D_0028E37C != 0) {
        s16 *limit;

        if (D_0028E910 == 0) {
            limit = &death_D_002512A0[D_0028E91C];
        } else {
            limit = &death_D_002512B0[D_0028E91C];
        }
        reg_tmp.h[0] = (s16) D_0028E158 + (s16) D_0028E15C;
        reg_tmp.h[0] /= 0xC;
        if ((D_0028E855 & 2) && (reg_tmp.h[0] >= *limit)) {
            D_0028E37C |= 0x80;
            D_0028E310 = 1;
        }
    }
#else
    if (D_0028E37C != 0) {
        reg_tmp.h[0] = (s16) D_0028E158 + (s16) D_0028E15C;
        reg_tmp.h[0] /= 0xC;
        if ((D_0028E855 & 2) && (D_0028E910 != 0) && (reg_tmp.h[0] > D_0024F330[D_0028E91C])) {
            D_0028E310 = 2;
        }
    }
#endif
}
