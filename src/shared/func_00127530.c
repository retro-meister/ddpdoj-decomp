#include "common.h"

extern u16 D_0028E4AA;
extern void *reg_a0_as_void_p;
extern void func_00127400(void);
extern void func_002010A0(void);

void func_00127530(void) {
    reg_tmp.w = reg_d0.w;
    D_0028E4AA = reg_d0.h[0];
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)((u8 *)reg_a0_as_void_p + 0x1A) = 0x420;
    func_002010A0();
    if ((s8)reg_d0.b[0] < 0) {
        reg_d0.b[0] *= -1;
    }
    reg_d0.h[0] = (s8)reg_d0.b[0];
    reg_d0.h[0] >>= 1;
    func_00127400();
}
