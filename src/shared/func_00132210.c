#include "common.h"

extern s32 reg_a1;
extern void func_0019C470(void);

void func_00132210(void)
{
    reg_d2.h[0] = (s16)reg_d7.h[0] & 0xF;
    reg_d2.w = ((u32 *)reg_a1)[reg_d2.h[0]];
    reg_d1.h[0] -= 0x200;
    func_0019C470();
}
