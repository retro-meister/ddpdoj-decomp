#include "common.h"

extern void *reg_a4_as_void_p;
extern void (*jtbl_0026ECD0[])(void);
extern void func_001D9BA0(void);

void func_001D9B40(void)
{
    reg_d0.h[0] = ((u16 *)reg_a4_as_void_p)[1];
    reg_d0.h[0] *= 2;
    jtbl_0026ECD0[(u16)reg_d0.h[0]]();
    func_001D9BA0();
}
