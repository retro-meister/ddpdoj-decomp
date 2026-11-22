#include "common.h"

extern s8 D_0028DF84;
extern s8 D_0028E368;
extern s8 D_0028ED7C;
extern u8 *reg_a5;

void func_00238910(void)
{
    u32 saved_d0;
    u32 saved_d1;
    u32 saved_d2;
    u32 saved_d3;
    u32 saved_d4;
    u32 saved_d5;
    u32 saved_d6;
    u32 saved_d7;

    D_0028ED7C = 2;

    saved_d0 = reg_d0.w;
    saved_d1 = reg_d1.w;
    saved_d2 = reg_d2.w;
    saved_d3 = reg_d3.w;
    saved_d4 = reg_d4.w;
    saved_d5 = reg_d5.w;
    saved_d6 = reg_d6.w;
    saved_d7 = reg_d7.w;

    D_0028DF84 = 0;
    D_0028E368 = 0;
    reg_a5[3] = 1;
    *(u16 *)(reg_a5 + 0xC) = 0;

    reg_d0.w = saved_d0;
    reg_d1.w = saved_d1;
    reg_d2.w = saved_d2;
    reg_d3.w = saved_d3;
    reg_d4.w = saved_d4;
    reg_d5.w = saved_d5;
    reg_d6.w = saved_d6;
    reg_d7.w = saved_d7;
}
