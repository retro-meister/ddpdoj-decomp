#include "common.h"


extern s8 D_0028E408;

s32 func_0012FAB0();
s32 func_00168BA0();
s32 func_001A2FA0();
s32 func_001A3D20();
s32 func_001A3D30();
s32 func_001A3E70();
s32 func_0020EAA0();
s32 func_00218B50();
s32 func_00225630();
s32 func_002256B0();
extern u8 D_00269160[];
extern u8 D_0028DF84;
extern u8 D_0028E294;
extern u8 D_0028E304;
extern u8 D_0028E310;
extern u8 D_0028E350;
extern u8 D_0028E368;
extern u8 D_0028E378;
extern s16 D_0028E3FC;
extern u16 D_0028E91C;
extern u8 D_0028E9B8;
extern u8 D_0028E9BC;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_00168EF0(void) {
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) == 0) {
        (*(u8 *)((u8 *)(reg_a5) + (2))) = 1U;
        func_0012FAB0();
        reg_d0.w = 0;
        reg_a0 = D_00269160;
        func_001A2FA0();
        D_0028E304 = 0;
        func_0020EAA0();
        D_0028E310 = 0;
        D_0028E294 = 0;
        func_001A3D30();
        D_0028E368 = 0;
        D_0028E378 = 0xFF;
        D_0028DF84 = 0;
        D_0028E9BC = 1;
        D_0028E350 = 0;
        D_0028E9B8 = 0;
        func_00225630();
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) == 1) {
        D_0028E91C = 0;
        func_00218B50();
        if (D_0028E3FC == D_0028E91C) {
            (*(u8 *)((u8 *)(reg_a5) + (2))) = 2U;
            func_002256B0();
            func_001A3D20();
        }
    }
    func_001A3E70();
    if (D_0028E408 == 0) {
        reg_d0.h[0] = 0xC;
        func_00168BA0();
    }
}
