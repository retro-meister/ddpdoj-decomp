#include "common.h"

s32 func_002072F0();
extern u16 D_0028E0CC;
extern u16 D_002A0AF0[];
extern u8 *reg_a1;

void func_00207520(void) {
    if (D_0028E0CC == 0) return;
loop_1:
    D_0028E0CC -= 0x50;
    reg_a1 = (u8 *)D_002A0AF0;
    reg_d2.h[0] = D_0028E0CC;
    reg_d0.h[1] = (reg_d2.h[0]) ? *(u16 *)(reg_a1 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d0.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)(reg_a1 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    func_002072F0();
    if (D_0028E0CC != 0) goto loop_1;
}
