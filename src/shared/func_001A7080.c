#include "common.h"

s32 func_0018DA10();
s32 func_0018DED0();
s32 func_001A7410();
s32 func_001A7B30();
s32 func_001A9180();
s32 func_001A9190();
s32 func_001A97F0();
extern s8 D_0028E408;
extern s8 D_0028E2A0;
extern s8 D_0028E2A4;
extern u32 D_0028E638;
extern u32 D_0028E63C;
extern u16 D_0028E640;
extern u16 D_0028E648;
extern u16 D_0028E64C;
extern u8 D_0028E854;
extern u16 D_0028E91C;
extern u8 D_0028ED80;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;

void func_001A7080(void) {
    u8 flags;
    u8 *p;

    flags = D_0028E854;
    switch (flags & 8) {
    case 0:
        return;
    }
    if (flags & 0x10) goto next_0;
    D_0028E854 = flags | 0x10;
    D_0028E640 = 7;
    reg_a0 = (u8 *)&D_0028E640;
    reg_d0.w = D_0028E638;
    reg_d0.w <<= 4;
    func_001A97F0();
next_0:
    if (!(D_0028E854 & 4)) {
        func_001A7B30();
        return;
    }
    if (D_0028E854 & 2) {
        func_001A7B30();
        return;
    }
    func_001A7410();
    if (D_0028E408 != 0) goto next_6;
    D_0028E640 -= 1;
    if ((s16)D_0028E640 >= 0) goto next_9;
    if (D_0028E63C == 0) goto next_1;
    func_0018DA10();
next_1:
    reg_d0.w = 0x10;
    reg_d0.h[0] -= D_0028E648;
    if ((s16)reg_d0.h[0] < 0) goto next_2;
    reg_d0.h[0] >>= 2;
    reg_d0.h[0] += 1;
    goto next_3;
next_2:
    reg_d0.w = 0;
next_3:
    D_0028E640 = reg_d0.h[0];
    reg_d7.w = 0;
    if (D_0028E648 < 0x32) goto next_4;
    D_0028E648 -= 1;
    reg_d7.w = 1;
next_4:
    if (D_0028E648 < 0x64) goto next_5;
    D_0028E648 -= 1;
    reg_d7.w = 2;
next_5:
    if (D_0028E648 < 0x96) goto next_7;
    D_0028E648 -= 1;
    reg_d7.w = 3;
next_7:
    reg_tmp.w = 0;
    reg_tmp.h[0] = D_0028E648;
    D_0028E648 -= 1;
    reg_tmp.w -= 1;
    if (D_0028E648 == 0) goto next_6;
    if ((s16)D_0028E648 >= 0) goto next_8;
    if (reg_tmp.h[1] != 0) goto next_10;
    D_0028E2A0 = 0;
    D_0028E2A4 = 0;
    D_0028E854 |= 2;
    if (D_0028ED80 == 0) goto next_11;
    D_0028E2A4 = 0x78;
    func_0018DED0();
    goto next_12;
next_11:
    if (D_0028E91C == 4) goto next_12;
    D_0028E2A4 = 0x78;
    func_0018DED0();
next_12:
    reg_d0.w = 0;
    D_0028E648 = reg_d0.h[0];
    D_0028E640 = reg_d0.h[0];
    D_0028E63C = reg_d0.w;
    func_001A7B30();
    return;
next_10:
    D_0028E640 = 8;
    D_0028E64C = 0xFFFF;
    goto next_9;
next_6:
    D_0028E648 = 0xFFFF;
    D_0028E64C = 0x17;
    D_0028E640 = 0x12;
next_8:
    reg_d0.w = D_0028E638;
    reg_d0.w >>= 8;
loop_0:
    p = (u8 *)&D_0028E640;
    reg_a0 = p;
    func_001A97F0();
    reg_a0 = p;
    func_001A97F0();
    reg_a0 = p;
    func_001A97F0();
    reg_a0 = p;
    func_001A97F0();
    reg_a0 = p;
    func_001A97F0();
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
next_9:
    if (D_0028E648 == 0) goto next_13;
    if ((s16)D_0028E648 < 0) goto next_13;
    func_001A7B30();
    return;
next_13:
    if (D_0028E640 == 8) goto next_14;
    func_001A7B30();
next_14:
    reg_d1.w = D_0028E63C;
    if (reg_d1.w == 0) goto next_15;
    func_0018DA10();
    reg_d0.w = reg_d1.w;
    reg_d0.w >>= 4;
    if (D_0029F260[0] >= 0) goto next_16;
    func_001A9180();
next_16:
    if (D_0029F1F0[0] >= 0) goto next_17;
    func_001A9190();
next_17:
    reg_d0.w = 0;
    D_0028E63C = reg_d0.w;
next_15:
    func_001A7B30();
}
