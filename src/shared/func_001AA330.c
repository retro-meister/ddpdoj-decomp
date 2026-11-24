#include "common.h"

extern void func_001A97F0(void);
extern s16 D_0028E644;
extern u16 D_0028E648;
extern s16 D_0028E650_as_s16;
extern u8 D_0028E720;
extern u8 *reg_a0;

void func_001AA330(void)
{
    if ((s32)D_0028E648 > 0x7FFF) {
        D_0028E648 = 0x7FFF;
    }

    reg_d0.w = reg_d3.w;
    reg_a0 = &D_0028E720;
    func_001A97F0();
    D_0028E650_as_s16 = 10;
    D_0028E644 = 7;
}
