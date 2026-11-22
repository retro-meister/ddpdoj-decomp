#include "common.h"

extern u16 D_0028E3EC;
extern u16 D_0028E988;
extern void func_0019D290(void);

void func_00125590(void)
{
    if (D_0028E988 < 0x34 ||
        (reg_d0.w = 1, reg_d0.h[0] &= reg_d7.h[0],
         D_0028E3EC != reg_d0.h[0])) {
        func_0019D290();
    }
}
