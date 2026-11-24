#include "common.h"

extern s8 D_0028E408;

s32 func_0012FAB0();
s32 func_0013B190();
s32 func_0015BA20();
s32 func_0015BBD0();
s32 func_0015BD00();
s32 func_0015BEF0();
s32 func_00168BA0();
s32 func_00169B40();
s32 func_0018DEE0();
s32 fade_reset();
s32 func_00217EC0();
s32 stage_load_step();
s32 func_00219570();
s32 func_00225630();
s32 func_002256B0();
extern s8 D_0028DF84;
extern u8 D_0028E284;
extern u8 D_0028E288;
extern u8 D_0028E290;
extern u8 D_0028E2E4;
extern u8 D_0028E2F4;
extern s16 D_0028E314;
extern s16 D_0028E318;
extern u8 D_0028E350;
extern u8 D_0028E368;
extern u8 D_0028E378;
extern u8 D_0028E39C;
extern s16 D_0028E3FC;
extern u16 D_0028E91C;
extern u8 g_cd_async_state;
extern u8 g_cd_async_busy;
extern u8 *reg_a5;

void func_00168FD0(void) {
    if (reg_a5[2] == 0) {
        reg_a5[2] = 1U;
        func_0012FAB0();
        func_0013B190();
        func_0015BA20();
        func_0018DEE0();
        D_0028E368 = 0;
        D_0028E378 = 0xFF;
        D_0028E2F4 = 0;
        fade_reset();
        func_00219570();
        func_00217EC0();
        D_0028E350 = 0;
        g_cd_async_busy = 1;
        g_cd_async_state = 0;
        func_00225630();
    }
    if (reg_a5[2] == 1) {
        D_0028E91C = 0;
        stage_load_step();
        if (D_0028E3FC == D_0028E91C) {
            reg_a5[2] = 2U;
            func_002256B0();
        }
    }
    if (D_0028E39C != 0x12) {
        func_0015BD00();
        if (D_0028E350 == 0) {
            func_00169B40();
        }
    } else {
        if (D_0028DF84 != 0) {
            func_0015BEF0();
        } else {
            func_0015BBD0();
        }
        switch (D_0028E408) { case 0: goto block_set; }
        if (D_0028E350 == 0) {
            func_00169B40();
        }
        return;
    block_set:
        D_0028E318 = 1;
        D_0028E314 = 1;
        reg_d0.h[0] = 5;
        D_0028E288 = 0;
        D_0028E284 = 0;
        D_0028E378 = 0;
        D_0028E290 = 0;
        D_0028E2E4 = 0;
        D_0028DF84 = 0;
        func_00168BA0();
    }
}
