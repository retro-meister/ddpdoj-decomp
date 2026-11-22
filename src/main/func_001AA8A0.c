#include "common.h"

extern void func_001A97F0(void);
extern s16 D_0028E644;
extern u16 D_0028E648;
extern s16 D_0028E650;
extern u8 D_0028E71C;
extern void *reg_a0;

void func_001AA8A0(void)
{
    if ((s32)D_0028E648 > 0x7FFF) {
        D_0028E648 = 0x7FFF;
    }

    reg_d0.w = reg_d3.w;
    reg_a0 = &D_0028E71C;
    func_001A97F0();
    D_0028E650 = 10;
    D_0028E644 = 7;
}
