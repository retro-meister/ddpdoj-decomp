#include "common.h"

extern u16 D_0028E1A4;
extern u16 D_0028E1A8;
extern u16 D_0028E1AC;
extern u16 D_0028E1B0;
extern u16 D_0028E1B4;
extern u16 D_0028E1B8;

void func_0016A7F0(void) {
    s32 sd0 = reg_d0.w;
    s32 sd1 = reg_d1.w;
    s32 sd2 = reg_d2.w;
    s32 sd3 = reg_d3.w;
    s32 sd4 = reg_d4.w;
    s32 sd5 = reg_d5.w;
    s32 sd6 = reg_d6.w;
    s32 sd7 = reg_d7.w;

    reg_d0.h[0] = D_0028E1B8;
    reg_d1.h[0] = D_0028E1AC;
    reg_d2.h[0] = D_0028E1B0;
    reg_d3.h[0] = D_0028E1A4;
    reg_d2.h[0] = ~reg_d2.h[0];
    reg_d3.h[0] = ~reg_d3.h[0];
    D_0028E1B0 = reg_d0.h[0];
    D_0028E1A4 = reg_d1.h[0];
    reg_d2.h[0] &= reg_d0.h[0];
    reg_d3.h[0] &= reg_d1.h[0];
    D_0028E1B4 = reg_d2.h[0];
    D_0028E1A8 = reg_d3.h[0];
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
}
