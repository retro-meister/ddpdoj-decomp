#include "common.h"

#pragma divbyzerocheck on

extern u8 D_002670C0[];
extern u8 D_002670D0[];
extern u16 D_0028E484_as_u16;

void func_002027A0(void) {
    reg_d4.h[0] = 0x1800;
    reg_d0.h[0] += reg_d4.h[0];
    reg_d1.h[0] += reg_d4.h[0];
    reg_d2.h[0] += reg_d4.h[0];
    reg_d3.h[0] += reg_d4.h[0];
    reg_d4.w = 8;
    D_0028E484_as_u16 = reg_d1.h[0];
    reg_d1.h[0] -= reg_d3.h[0];
    if ((s32) D_0028E484_as_u16 < (s32) reg_d3.h[0]) {
        reg_d4.w = 0;
        reg_d1.h[0] *= 0xFFFF;
    }
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s32) reg_tmp.h[0] < (s32) reg_d2.h[0]) {
        reg_d0.h[0] *= 0xFFFF;
        reg_d4.h[0] += 4;
    }
    reg_d2.h[0] = reg_d1.h[0];
    reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 1);
    reg_d1.h[0] += reg_d2.h[0];
    if (!((s32) reg_d0.h[0] > (s32) reg_d1.h[0])) goto next_1;
    reg_d4.h[0] += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.w = reg_d1.w;
    reg_d1.w = reg_tmp.w;
next_1:
    reg_d0.h[1] = 0;
    if (reg_d1.h[0] == 0) goto block_rts;
    reg_d0.w <<= 5;
    reg_d2.h[0] = reg_d0.w % reg_d1.h[0];
    reg_d0.w = reg_d0.w / (u32) (u16) reg_d1.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] *= 2;
    if (!((s32) reg_d2.h[0] > (s32) reg_d1.h[0])) goto next_2;
    reg_d0.h[0] += 1;
next_2:
    reg_d0.b[0] = *(s8 *)(D_002670D0 + reg_d0.h[0]);
    reg_d1.h[0] = *(s16 *)(D_002670C0 + (reg_d4.h[0] & ~1));
    switch ((s32) reg_d4.h[0] >> 1) {
    case 0:
        reg_d1.h[0] += reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 1:
        reg_d1.h[0] -= reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 2:
        reg_d1.h[0] -= reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 3:
        reg_d1.h[0] += reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 4:
        reg_d1.h[0] -= reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 5:
        reg_d1.h[0] += reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 6:
        reg_d1.h[0] += reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 7:
        reg_d1.h[0] -= reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    }
block_rts:
    return;
}
