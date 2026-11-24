#include "common.h"
#pragma opt_propagation off

extern u32 D_0028E484_as_u32;
extern u16 D_0028E4A6;
extern s16 D_0028E8C4_as_s16;

extern void func_001A53D0(u32 savedRegister);
extern void func_001A80D0(void);

void func_001A6B70(void)
{
    if (D_0028E8C4_as_s16 >= 0) {
        u16 offset = reg_d6.h[0];
        u32 savedRegister;

        reg_d1.h[0] = 0x5BC0;
        reg_d2.w = 0xE65;
        reg_d3.h[0] = 0x840;
        reg_d4.h[0] = 9;
        savedRegister = reg_d1.w;
        D_0028E484_as_u32 = savedRegister;
        D_0028E4A6 = reg_d1.h[0];
        reg_d1.h[0] = 0;
        reg_d1.h[0] += offset;
        func_001A53D0(savedRegister);
        reg_d7.w = 0;
        func_001A80D0();
    }
}
