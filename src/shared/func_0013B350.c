#include "common.h"

extern void func_0013B3C0(void);

extern u32 D_0028E40C;
extern u32 D_0028E410;
extern u32 D_0028E414;
extern u32 D_0028E418;
extern u32 D_0028E41C;
extern u32 D_0028E420;
extern u32 D_0028E424;
extern s32 D_0028E434;
extern s32 D_0028E438;
extern s32 D_0028E43C_as_s32;
extern s32 D_0028E440_as_s32;
extern s32 D_0028E444;

extern s32 reg_a0_as_s32;
extern s32 reg_a1_as_s32;
extern s32 reg_a2_as_s32;
extern s32 reg_a3_as_s32;
extern s32 reg_a4_as_s32;

void func_0013B350(void)
{
    D_0028E424 = reg_d1.w;
    D_0028E420 = reg_d2.w;
    D_0028E41C = reg_d3.w;
    D_0028E418 = reg_d4.w;
    D_0028E414 = reg_d5.w;
    D_0028E410 = reg_d6.w;
    D_0028E40C = reg_d7.w;
    D_0028E444 = reg_a0_as_s32;
    D_0028E440_as_s32 = reg_a1_as_s32;
    D_0028E43C_as_s32 = reg_a2_as_s32;
    D_0028E438 = reg_a3_as_s32;
    D_0028E434 = reg_a4_as_s32;
    reg_d6.h[0] = 0;
    func_0013B3C0();
}
