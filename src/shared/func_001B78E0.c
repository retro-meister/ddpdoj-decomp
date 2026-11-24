#include "common.h"

extern void *reg_a6_as_void_p;
extern void func_0019C6D0(void);

void func_001B78E0(void)
{
    u16 *work;

    reg_d2.w = 0x195E;
    work = (u16 *)reg_a6_as_void_p;
    reg_d1.h[1] = work[1];
    reg_d1.h[0] = work[2];
    reg_d1.w += 0xE600F400U;
    reg_d3.h[0] = 0x1A60;
    reg_d4.h[0] = work[0xE];
    func_0019C6D0();
}
