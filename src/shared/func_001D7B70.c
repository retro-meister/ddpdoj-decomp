#include "common.h"

extern void *reg_a4;
extern void (*jtbl_0026EC80[])(void);
extern void func_001D7BD0(void);

void func_001D7B70(void)
{
    reg_d0.h[0] = ((u16 *)reg_a4)[1];
    reg_d0.h[0] <<= 1;
    jtbl_0026EC80[(u16)reg_d0.h[0]]();
    func_001D7BD0();
}
