#include "common.h"
#pragma opt_propagation off

extern s16 D_0028E644;
extern s16 D_0028E648_as_s16;
extern s16 D_0028E64C_as_s16;
extern s16 D_0028E650_as_s16;
extern u16 D_0028E698;
extern u16 D_0029F282[];

void func_001AA1C0(void)
{
    u16 adjustment;

    D_0028E650_as_s16 = 10;
    adjustment = D_0029F282[0];
    D_0028E644 = 7;
    D_0028E648_as_s16 = 0;
    reg_d2.w = 8;
    D_0028E64C_as_s16 = 0;
    reg_d2.h[0] -= adjustment;
    reg_d2.h[0] += 8;
    D_0028E698 = reg_d2.h[0];
}
