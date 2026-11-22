#include "common.h"

void func_00201B30(void)
{
    u32 savedD4;
    u32 savedD5;
    u32 savedD3;
    u32 savedD2;
    u32 savedD1;
    u32 savedD0;
    u32 savedD7;
    u32 savedD6;

    savedD4 = *(volatile u32 *)&reg_d4.w;
    savedD5 = *(volatile u32 *)&reg_d5.w;
    savedD0 = *(volatile u32 *)&reg_d0.w;
    savedD1 = *(volatile u32 *)&reg_d1.w;
    savedD2 = *(volatile u32 *)&reg_d2.w;
    savedD3 = *(volatile u32 *)&reg_d3.w;

    *(volatile u32 *)&reg_d4.w = savedD4;
    *(volatile u32 *)&reg_d5.w = savedD5;

    savedD6 = *(volatile u32 *)&reg_d6.w;
    savedD7 = *(volatile u32 *)&reg_d7.w;

    *(volatile u32 *)&reg_d0.w = savedD0;
    *(volatile u32 *)&reg_d1.w = savedD1;
    *(volatile u32 *)&reg_d2.w = savedD2;
    *(volatile u32 *)&reg_d3.w = savedD3;
    *(volatile u32 *)&reg_d6.w = savedD6;
    *(volatile u32 *)&reg_d7.w = savedD7;
}
