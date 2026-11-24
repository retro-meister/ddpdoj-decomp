#include "common.h"

s32 func_0011C2B0();
extern u16 D_0028E474;
extern u16 D_0028E478;

void func_00208EB0(void) {
    s32 s_d0;
    s32 s_d1;
    s32 s_d2;
    s32 s_d3;
    s32 s_d4;
    s32 s_d5;
    s32 s_d6;
    s32 s_d7;
    s32 i;

    s_d0 = reg_d0.w;
    s_d1 = reg_d1.w;
    s_d2 = reg_d2.w;
    s_d3 = reg_d3.w;
    s_d4 = reg_d4.w;
    s_d5 = reg_d5.w;
    s_d6 = reg_d6.w;
    s_d7 = reg_d7.w;
    reg_d3.w &= 0xFFFF;
    reg_d5.w = reg_d3.w;
    D_0028E474 = reg_d5.h[0];
    reg_d5.h[0] = reg_d5.h[1];
    reg_d5.h[1] = D_0028E474;
    reg_d6.h[0] = reg_d2.h[0];
    reg_d2.w = 0;
    reg_d3.w = 0;
    reg_d7.w = 3;
loop_1:
    i = 0;
loop_2:
    if (reg_d5.w & 0x80000000) {
        reg_d5.w = reg_d5.w * 2;
        reg_d5.w = reg_d5.w | 1;
    } else {
        reg_d5.w = reg_d5.w * 2;
    }
    i += 1;
    if (i < 4) {
        goto loop_2;
    }
    reg_d4.w = reg_d5.w;
    reg_d4.w &= 0xF;
    if (reg_d4.b[0] < 0xA) goto next_1;
    reg_d4.h[0] += 7;
next_1:
    reg_d4.h[0] += 0x30;
    D_0028E478 = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = D_0028E478;
    reg_d4.h[0] = reg_d6.h[0];
    func_0011C2B0();
    reg_d0.h[0] += 1;
    if ((s16)(--reg_d7.h[0]) >= 0) goto loop_1;
    reg_d0.w = s_d0;
    reg_d1.w = s_d1;
    reg_d2.w = s_d2;
    reg_d3.w = s_d3;
    reg_d4.w = s_d4;
    reg_d5.w = s_d5;
    reg_d6.w = s_d6;
    reg_d7.w = s_d7;
}
