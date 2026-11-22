#include "common.h"

extern void *reg_a0;
extern void func_00127400(void);
extern void func_002010A0(void);

void func_00127530(void)
{
    reg_tmp.w = reg_d0.w;
    reg_d7.w = reg_d1.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)((u8 *)reg_a0 + 0x1A) = 0x420;
    func_002010A0();

    if ((s8)reg_d0.b[0] < 0) {
        reg_d0.b[0] *= -1;
    }
    reg_d0.h[0] = (s8)reg_d0.b[0];
    reg_d0.h[0] >>= 1;
    func_00127400();
}
