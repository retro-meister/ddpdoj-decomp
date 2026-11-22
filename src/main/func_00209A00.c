#include "common.h"

extern u8 D_002686D0[];
extern u8 D_0028E398;
extern u8 *reg_a0;
extern void func_002092F0(void);

void func_00209A00(void)
{
    u8 *label;

    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E398;
    reg_a0 = D_002686D0;
    reg_d0.h[0] <<= 5;
    label = reg_a0 + reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x24;
    reg_d2.h[0] = reg_d7.h[0];
    reg_a0 = label;
    func_002092F0();
}
