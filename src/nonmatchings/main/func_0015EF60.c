#include "common.h"

extern void func_001292C0(void);

void func_0015EF60(void)
{
    reg_d0.w = 0xFFFF000D;
    reg_d6.h[0] = reg_d1.h[0];
    reg_d1.h[0] -= 2;
    func_001292C0();

    reg_d1.h[0] -= 5;
    reg_d0.w += 0xFFFE0000;
    func_001292C0();

    reg_d1.h[0] = reg_d6.h[0];
}
