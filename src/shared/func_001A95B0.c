#include "common.h"

void func_001A8FC0(void);
void func_001A97F0(void);
void func_001A99C0(void);
extern u16 D_0028DADC[];
extern u16 D_0028E5F8;
extern u16 D_0028E610;
extern s16 D_0028E658_as_s16;
extern u16 D_0028E65C;
extern u16 D_0028E660;
extern u32 D_0028E664_as_u32;
extern u32 D_0028E668_as_u32;
extern u32 D_0028E66C_as_u32;
extern u16 D_0028E670;
extern u16 D_0028E674;
extern s16 D_0028E678;
extern u16 D_0028E67C;
extern u16 D_0028E680;
extern s16 D_0028E684;
extern u16 D_0028E688;
extern u32 D_0028E68C_as_u32;
extern u32 D_0028E690_as_u32;
extern u16 D_0028E694;
extern u16 D_0028E6E0;
extern u16 D_0028E71C_as_u16;
extern u8 D_0028E854;
extern u16 D_0029CEA0[];
extern u16 D_0029F248[];
extern u8 *reg_a0;

void func_001A95B0(void) {
    reg_d3.w = reg_d0.w;
    reg_d2.h[0] = D_0029F248[0];
    reg_a0 = (u8 *)D_0028DADC;
    D_0028E694 = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = D_0029CEA0[0];
    if ((s16) reg_d2.h[0] >= 0) {
        goto next_1;
    }
    if (!(reg_d2.w & 0x80)) {
        goto next_1;
    }
    if (D_0028E6E0 == 0) {
        goto block_11;
    }
next_1:
    if (D_0028E854 & 1) {
        goto block_12;
    }
    D_0028E658_as_s16 = 0x1E;
    if (D_0028E5F8 != 0) {
        D_0028E658_as_s16 = 1;
    }
    if (D_0028E688 != 0) {
        goto next_2;
    }
    func_001A99C0();
block_11:
    D_0028E660 = 0;
block_12:
    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)&D_0028E71C_as_u16;
    func_001A97F0();
    D_0028E690_as_u32 = reg_d3.w;
    D_0028E68C_as_u32 = reg_d3.w;
    if (D_0028E664_as_u32 == 0) {
        D_0028E684 = 0x50;
    }
    reg_d2.w = 0;
    D_0028E66C_as_u32 = reg_d2.w;
    D_0028E668_as_u32 = reg_d2.w;
    D_0028E680 = reg_d2.h[0];
    goto block_end;
next_2:
    if (D_0028E690_as_u32 != 0) {
        reg_d0.w = D_0028E690_as_u32;
        D_0028E660 = 1;
        D_0028E66C_as_u32 = reg_d0.w;
        D_0028E668_as_u32 = reg_d0.w;
        reg_d0.w = 0;
        D_0028E690_as_u32 = reg_d0.w;
    }
    reg_a0 = (u8 *)&D_0028E660;
    func_001A8FC0();
    reg_d0.h[0] = D_0028E610;
    if ((s32) D_0028E660 > (s32) reg_d0.h[0]) {
        D_0028E610 = D_0028E660;
    }
    reg_d0.w = reg_d3.w;
    reg_a0 = (u8 *)&D_0028E670;
    func_001A97F0();
    reg_d0.w = D_0028E66C_as_u32;
    reg_a0 = (u8 *)&D_0028E66C_as_u32;
    func_001A97F0();
    func_001A99C0();
    reg_d0.w = D_0028E66C_as_u32;
    reg_a0 = (u8 *)&D_0028E71C_as_u16;
    func_001A97F0();
    if ((s32) D_0028E660 < 0x10) {
        if ((s32) D_0028E660 > 1) {
            D_0028E680 = 0x78;
        }
        D_0028E67C = D_0028E688;
        if (D_0028E664_as_u32 == 0) {
            D_0028E684 = 0xB4;
        }
        goto block_end;
    }
    if (D_0028E660 == 0x10) {
        D_0028E670 = 0;
        D_0028E680 = 0;
    }
    D_0028E65C = D_0028E660;
    D_0028E678 = 0xF0;
    D_0028E684 = 0xF0;
    D_0028E674 = D_0028E688;
    D_0028E664_as_u32 = D_0028E668_as_u32;
block_end:
    reg_d0.w = reg_d3.w;
}
