#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_001A3020();
extern u8 D_002618B0[];
extern u8 D_00263D00[];
extern u8 D_0028D9B0;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_001E2470(void) {
    reg_a0 = D_00263D00;
    func_0014E370();
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a5 + 0x44) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = reg_tmp.h[0];
    reg_a0 = &D_0028D9B0;
    reg_d0.w = 2;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a0 = D_002618B0;
        reg_d0.h[0] = 0x12;
        func_001A3020();
    }
}
