#include "common.h"

extern Reg32 reg_d0;
extern u16 D_0028E220;
void func_00206910(void);

void func_00206D10(void) {
    u32 flags;

    reg_d0.h[0] = 1;
    flags = (u32)D_0028E220;
    flags |= (u32)(u16)reg_d0.h[0];
    D_0028E220 = (u16)flags;
    func_00206910();
}
