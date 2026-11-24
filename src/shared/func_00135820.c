#include "common.h"

s32 func_001358A0();
extern s32 D_0028DEB8, D_0028DEBC, D_0028DEC0, D_0028DEC4, D_0028DEC8, D_0028DECC, D_0028DED0;
extern u32 D_0028DED4, D_0028DED8, D_0028DEDC, D_0028DEE0, D_0028DEE4, D_0028DEE8, D_0028DEEC, D_0028DEF0;
extern s32 reg_a0, reg_a1, reg_a2, reg_a3, reg_a4, reg_a5, reg_a6;

void func_00135820(void) {
    D_0028DEF0 = reg_d0.w;
    D_0028DEEC = reg_d1.w;
    D_0028DEE8 = reg_d2.w;
    D_0028DEE4 = reg_d3.w;
    D_0028DEE0 = reg_d4.w;
    D_0028DEDC = reg_d5.w;
    D_0028DED8 = reg_d6.w;
    D_0028DED4 = reg_d7.w;
    D_0028DED0 = reg_a0;
    D_0028DECC = reg_a1;
    D_0028DEC8 = reg_a2;
    D_0028DEC4 = reg_a3;
    D_0028DEC0 = reg_a4;
    D_0028DEBC = reg_a5;
    D_0028DEB8 = reg_a6;
    func_001358A0();
}
