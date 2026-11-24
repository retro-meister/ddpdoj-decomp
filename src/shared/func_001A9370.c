#include "common.h"

void func_001A8FC0(void);
void func_001A97F0(void);
void func_001A9820(void);
extern u16 D_0028DADC[];
extern u16 D_0028E5FC;
extern u16 D_0028E614;
extern u16 D_0028E694;
extern s16 D_0028E698;
extern u16 D_0028E69C;
extern u16 D_0028E6A0;
extern u32 D_0028E6A4;
extern u32 D_0028E6A8;
extern u32 D_0028E6AC;
extern u16 D_0028E6B0;
extern u16 D_0028E6B4;
extern s16 D_0028E6B8;
extern u16 D_0028E6BC;
extern u16 D_0028E6C0;
extern s16 D_0028E6C4;
extern u16 D_0028E6C8;
extern u32 D_0028E6CC;
extern u32 D_0028E6D0;
extern u16 D_0028E6E4;
extern u16 D_0028E720;
extern u8 D_0028E854;
extern u16 D_0029CEA0[];
extern u16 D_0029F2B8[];
extern u8 *reg_a0;

void func_001A9370(void) {
    reg_d3.w = reg_d0.w;
    reg_d2.h[0] = D_0029F2B8[0];
    reg_a0 = (u8 *)D_0028DADC;
    D_0028E694 = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = D_0029CEA0[0];
    if ((s16) reg_d2.h[0] >= 0) {
        goto next_1;
    }
    if (reg_d2.w & 0x80) {
        goto next_1;
    }
    if (D_0028E6E4 == 0) {
        goto block_11;
    }
next_1:
    if (D_0028E854 & 1) {
        goto block_12;
    }
    D_0028E698 = 0x1E;
    if (D_0028E5FC != 0) {
        D_0028E698 = 1;
    }
    if (D_0028E6C8 != 0) {
        goto next_2;
    }
    func_001A9820();
block_11:
    D_0028E6A0 = 0;
block_12:
    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)&D_0028E720;
    func_001A97F0();
    D_0028E6D0 = reg_d3.w;
    D_0028E6CC = reg_d3.w;
    if (D_0028E6A4 == 0) {
        D_0028E6C4 = 0x50;
    }
    reg_d2.w = 0;
    D_0028E6AC = reg_d2.w;
    D_0028E6A8 = reg_d2.w;
    D_0028E6C0 = reg_d2.h[0];
    goto block_end;
next_2:
    if (D_0028E6D0 != 0) {
        reg_d0.w = D_0028E6D0;
        D_0028E6A0 = 1;
        D_0028E6AC = reg_d0.w;
        D_0028E6A8 = reg_d0.w;
        reg_d0.w = 0;
        D_0028E6D0 = reg_d0.w;
    }
    reg_a0 = (u8 *)&D_0028E6A0;
    func_001A8FC0();
    reg_d0.h[0] = D_0028E614;
    if ((s32) D_0028E6A0 > (s32) reg_d0.h[0]) {
        D_0028E614 = D_0028E6A0;
    }
    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)&D_0028E6B0;
    func_001A97F0();
    reg_d0.w = D_0028E6AC;
    reg_a0 = (u8 *)&D_0028E6AC;
    func_001A97F0();
    func_001A9820();
    reg_d0.w = D_0028E6AC;
    reg_a0 = (u8 *)&D_0028E720;
    func_001A97F0();
    if ((s32) D_0028E6A0 < 0x10) {
        if ((s32) D_0028E6A0 > 1) {
            D_0028E6C0 = 0x78;
        }
        D_0028E6BC = D_0028E6C8;
        if (D_0028E6A4 == 0) {
            D_0028E6C4 = 0xB4;
        }
        goto block_end;
    }
    if (D_0028E6A0 == 0x10) {
        D_0028E6B0 = 0;
        D_0028E6C0 = 0;
    }
    D_0028E69C = D_0028E6A0;
    D_0028E6B8 = 0xF0;
    D_0028E6C4 = 0xF0;
    D_0028E6B4 = D_0028E6C8;
    D_0028E6A4 = D_0028E6A8;
block_end:
    reg_d0.w = reg_d3.w;
}
