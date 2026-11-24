#include "common.h"

s32 func_00201A00();
extern u32 D_0028E40C;
extern u32 D_0028E410;
extern u32 D_0028E414;
extern u32 D_0028E418;
extern u32 D_0028E41C;
extern u32 D_0028E420;
extern u32 D_0028E424;
extern u32 D_0028E428;
extern u8 *D_0028E42C;
extern u8 *D_0028E430;
extern u8 *D_0028E434_as_u8_p;
extern u8 *D_0028E438_as_u8_p;
extern u8 *D_0028E43C;
extern u8 *D_0028E440;
extern u8 *D_0028E444_as_u8_p;
extern s16 D_0029F1F0[];
extern u8 D_0029F1F1[];
extern s16 D_0029F260[];
extern u8 D_0029F261[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00201920(void) {
    D_0028E428 = reg_d0.w;
    D_0028E424 = reg_d1.w;
    D_0028E420 = reg_d2.w;
    D_0028E41C = reg_d3.w;
    D_0028E418 = reg_d4.w;
    D_0028E414 = reg_d5.w;
    D_0028E410 = reg_d6.w;
    D_0028E40C = reg_d7.w;
    D_0028E444_as_u8_p = reg_a0;
    D_0028E440 = reg_a1;
    D_0028E43C = reg_a2;
    D_0028E438_as_u8_p = reg_a3;
    D_0028E434_as_u8_p = reg_a4;
    D_0028E430 = reg_a5;
    D_0028E42C = reg_a6;
    reg_d1.h[0] = 0x8000;
    if ((D_0029F260[0] < 0) && !(D_0029F261[0] & 1)) {
        reg_d1.h[0] |= 0x10;
    }
    if ((D_0029F1F0[0] < 0) && !(D_0029F1F1[0] & 1)) {
        reg_d1.h[0] |= 8;
    }
    func_00201A00();
}
