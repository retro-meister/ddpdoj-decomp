#include "common.h"

extern u8 D_0029F1F0[];
extern u8 D_0029F260[];
extern u8 *reg_a0;

extern void func_00202AE0(void);

void func_00202A80(void)
{
    s16 firstResult;

    reg_a0 = D_0029F260;
    func_00202AE0();
    firstResult = (s16)reg_d0.h[0];

    reg_a0 = D_0029F1F0;
    func_00202AE0();
    reg_d1.h[0] = (u16)firstResult;

    if (reg_d0.h[0] > reg_d1.h[0]) {
        reg_d0.h[0] = reg_d1.h[0];
    }
}
