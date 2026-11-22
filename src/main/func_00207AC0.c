#include "common.h"

extern u8 D_00267B40[];
extern u8 D_0028E384;
extern u8 *reg_a0;

extern void func_002092F0(void);

void func_00207AC0(void)
{
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E384;
    reg_d0.h[0] <<= 5;
    reg_a0 = D_00267B40;
    reg_a0 += reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x1E;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
}
