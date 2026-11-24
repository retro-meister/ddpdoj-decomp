#include "common.h"

s32 memset();
extern u8 D_00295E50[];
extern s32 D_00295E54[];
extern u16 D_00295E5A[];
extern u32 *D_00295E9C[];
extern u8 D_00295EA0[];
extern s32 D_00295F40[];
extern s64 D_002960A8[];
extern s32 D_00296210[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00124320(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    memset(D_00295E50, 0, MAIN_OR_DEATH_LABEL(0x490, 0x4D0));
    if (reg_a0 != 0) {
        D_00295E54[0] = (int)reg_a0;
        D_00295E5A[0] = 0xFFFF;
    }
    if (reg_a3 != 0) {
        D_00295F40[0] = (int)reg_a3;
    }
    if (reg_a1 != 0) {
        D_002960A8[0] = (s32)reg_a1;
    }
    if (reg_a2 != 0) {
        D_00295E9C[0] = (u32 *)reg_a2;
        reg_a6 = (u8 *)D_00295EA0;
loop_8:
        reg_d0.w = *(u32 *)reg_a2;
        reg_a2 += 4;
        if (reg_d0.w != -1U) {
            (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
            (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d0.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d0.h[0];
            reg_a6 += 8;
            goto loop_8;
        }
    }
    if (reg_a4 != 0) {
        D_00296210[0] = (int)reg_a4;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}
