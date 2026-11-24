#include "common.h"

extern u8 D_0028DFA0;
extern void func_002093C0(void);

void func_00208660(void)
{
    reg_d0.w = 5;
    reg_d1.w = 9;
    reg_d2.w = 0;
    reg_d1.b[0] -= D_0028DFA0;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += 0x18;
    func_002093C0();
}
