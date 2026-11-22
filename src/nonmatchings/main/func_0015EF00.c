#include "common.h"

extern void func_001292C0(void);

void func_0015EF00(void)
{
    u32 savedPosition;
    u32 nextPosition;
    u32 command;

    savedPosition = reg_d1.h[0];
    reg_d0.w = 0xFFFF000D;
    nextPosition = savedPosition + 2;
    reg_d6.h[0] = savedPosition;
    reg_d1.h[0] = nextPosition;
    func_001292C0();

    nextPosition = reg_d1.h[0] + 5U;
    command = reg_d0.w + 0xFFFE0000;
    reg_d1.h[0] = nextPosition;
    reg_d0.w = command;
    func_001292C0();

    reg_d1.h[0] = reg_d6.h[0];
}
