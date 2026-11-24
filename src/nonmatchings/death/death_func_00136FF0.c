#include "common.h"

s32 func_0012FAB0();
s32 func_0012FB00();
s32 func_0013B190();
s32 func_00168BA0();
s32 func_0018DEE0();
s32 func_001A2FA0();
s32 func_00217A20();
s32 func_00218B50();
s32 func_00219570();
s32 func_00225630();
s32 func_002256B0();
extern u8 D_00269160[];
extern u8 D_0028E2F4;
extern u8 D_0028E350;
extern u8 D_0028E368;
extern u8 D_0028E378;
extern s16 D_0028E3FC;
extern u16 D_0028E91C;
extern s8 D_0028E9B8;
extern s8 D_0028E9BC;
extern s8 D_0028EB88;
extern u8 *reg_a0;
extern u8 *reg_a5;

void death_func_00136FF0(void) {
    if (reg_a5[2] == 0) {
        reg_a5[2] = 1U;
        func_0012FB00();
        func_0012FAB0();
        reg_d0.w = 0;
        reg_a0 = D_00269160;
        func_001A2FA0();
        func_0013B190();
        func_0018DEE0();
        D_0028E368 = 0;
        D_0028E378 = 0xFF;
        D_0028E2F4 = 0;
        func_00217A20();
        func_00219570();
        D_0028E350 = 0;
        D_0028E9BC = 1;
        D_0028E9B8 = 0;
        func_00225630();
    }
    if (reg_a5[2] == 1) {
        D_0028E91C = 0;
        func_00218B50();
        if (D_0028E3FC == D_0028E91C) {
            reg_a5[2] = 2U;
            func_002256B0();
        }
    }
    if (D_0028E350 == 0) {
        D_0028EB88 = 0;
        reg_d0.h[0] = 0xF;
        func_00168BA0();
    }
}
