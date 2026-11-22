#include "common.h"

extern u16 D_0028E8A0;
extern u8 *reg_a6;
extern void func_00201CC0(void);

void func_00201C60(void)
{
    reg_d0.w = 0;
    reg_d0.b[0] = reg_a6[0x1B];
    reg_d1.w = 0x3F;
    reg_d1.b[0] &= reg_a6[0x1A];

    if (D_0028E8A0 != 0) {
        reg_d2.w = 0;
        reg_d3.w = 0;
    } else {
        func_00201CC0();
    }
}
