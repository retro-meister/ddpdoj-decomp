#include "common.h"

extern u16 D_00261CB0[];
extern u16 D_00261E30[];
extern u16 D_00261E70[];
extern u16 D_00261EB0[];

extern u16 D_00255580[];
extern u16 D_00255582[];
extern u16 D_00255588[];
extern u16 D_0025558A[];
extern u16 D_00255590[];
extern u16 D_00255592[];
extern u16 D_002555A0[];
extern u16 D_002555A2[];
extern u16 D_002555A8[];
extern u16 D_002555AA[];
extern u16 D_002555B0[];
extern u16 D_002555B2[];
extern u16 D_0028C5E8[];
extern u16 D_0028C5EA[];
extern u16 D_0028C5F0[];
extern u16 D_0028C5F2[];

void func_001828A0(void) {
    reg_tmp.w = (u32)D_00261CB0;
    D_00255580[0] = reg_tmp.h[1];
    D_00255582[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261E30;
    D_00255588[0] = reg_tmp.h[1];
    D_0025558A[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261E70;
    D_00255590[0] = reg_tmp.h[1];
    D_00255592[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261EB0;
    D_0028C5E8[0] = reg_tmp.h[1];
    D_0028C5EA[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261CB0;
    D_002555A0[0] = reg_tmp.h[1];
    D_002555A2[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261E30;
    D_002555A8[0] = reg_tmp.h[1];
    D_002555AA[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261E70;
    D_002555B0[0] = reg_tmp.h[1];
    D_002555B2[0] = reg_tmp.h[0];
    reg_tmp.w = (u32)D_00261EB0;
    D_0028C5F0[0] = reg_tmp.h[1];
    D_0028C5F2[0] = reg_tmp.h[0];
}
