#include "common.h"

s32 func_001358A0();
extern u8 *D_0028DEB8_as_u8_p;
extern u8 *D_0028DEBC;
extern u8 *D_0028DEC0;
extern u8 *D_0028DEC4;
extern u8 *D_0028DEC8;
extern u8 *D_0028DECC;
extern u8 *D_0028DED0;
extern u32 D_0028DED4;
extern u32 D_0028DED8;
extern u32 D_0028DEDC;
extern u32 D_0028DEE0;
extern u32 D_0028DEE4;
extern u32 D_0028DEE8;
extern u32 D_0028DEEC;
extern u32 D_0028DEF0;
extern u16 D_0028E92C;
extern u16 D_0028E930;
extern u16 D_0028E934;
extern u16 D_0028E938;
extern u8 D_002BF390[];
extern u8 D_002BF3B4[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00135740(void) {
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
    D_0028DEB8_as_u8_p = (u8 *)(reg_a6);
    if (reg_d2.h[0] != 0) {
        reg_a6 = (u8 *)D_002BF3B4;
        D_0028E934 = reg_d0.h[0];
        D_0028E92C = reg_d1.h[0];
        func_001358A0();
        return;
    }
    reg_a6 = (u8 *)D_002BF390;
    D_0028E938 = reg_d0.h[0];
    D_0028E930 = reg_d1.h[0];
    func_001358A0();
}
