#include "common.h"


extern s8 D_0028E408;

s32 func_002037B0();
s32 func_002037E0();
extern u8 D_0029F1F0[];
extern u8 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_002036F0(void) {
    u16 temp_a0;

    D_0028E408 = 0;
    reg_a0 = D_0029F260;
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) & 1) {
        reg_a0 = D_0029F1F0;
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
    reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= 0x1C00;
    temp_a0 = (u32)reg_d6.h[0] + 0x800;
    reg_d6.h[0] = temp_a0;
    if ((s32) reg_tmp.h[0] >= 0x1C00) {
        func_002037E0();
        return;
    }
    reg_tmp.h[0] = reg_d6.h[0];
    reg_d6.h[0] -= 0x2400;
    if ((s32) reg_tmp.h[0] < 0x2400) {
        func_002037B0();
    }
}
