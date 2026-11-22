#include "common.h"

extern s16 D_0028E644;
extern s16 D_0028E648;
extern s16 D_0028E64C;
extern s16 D_0028E650;
extern u16 D_0028E658;
extern u16 D_0029F212[];

void func_001AA730(void)
{
    u32 adjustment;
    u32 counter;

    D_0028E650 = 10;
    adjustment = *(volatile u16 *)&D_0029F212[0];
    D_0028E644 = 7;
    D_0028E648 = 0;
    reg_d2.w = 8;
    counter = reg_d2.h[0];
    D_0028E64C = 0;
    reg_d2.h[0] = counter - adjustment;
    reg_d2.h[0] += 8;
    D_0028E658 = reg_d2.h[0];
}
