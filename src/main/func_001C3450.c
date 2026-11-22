#include "common.h"

extern void func_00128AC0(u32, u16);

void func_001C3450(void)
{
    u32 savedD6;
    u32 adjustedD0;
    u16 lowD6;

    reg_d0.h[0] = 0xFFEA;
    savedD6 = reg_d6.w;
    reg_d3.w = 0;
    reg_d4.w = 0;
    reg_d0.h[0] += reg_d7.h[0];
    adjustedD0 = reg_d0.w;
    lowD6 = reg_d6.h[0];
    reg_d1.h[0] = lowD6;
    reg_tmp.w = adjustedD0;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 7;
    func_00128AC0(adjustedD0, lowD6);
    reg_d6.w = savedD6;
}
