#include "common.h"
#pragma opt_propagation off

extern s16 D_0028E644;
extern s16 D_0028E648_as_s16;
extern s16 D_0028E64C_as_s16;
extern s16 D_0028E650_as_s16;
extern u16 D_0028E658;
extern u16 D_0029F212[];

void func_001AA730(void)
{
    u32 adjustment;
    u32 counter;

    D_0028E650_as_s16 = 10;
    adjustment = D_0029F212[0];
    D_0028E644 = 7;
    D_0028E648_as_s16 = 0;
    reg_d2.w = 8;
    counter = reg_d2.h[0];
    D_0028E64C_as_s16 = 0;
    reg_d2.h[0] = counter - adjustment;
    reg_d2.h[0] += 8;
    D_0028E658 = reg_d2.h[0];
}
