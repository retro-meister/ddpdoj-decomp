#include "common.h"
#pragma opt_propagation off

#pragma divbyzerocheck on

extern u8 D_0028E38C;
extern u32 D_0028E480_as_u32;
extern u16 D_0028E904;

void func_00124520(void) {
    u8 val = D_0028E38C;
    s32 quotient;

    reg_d1.w = 0;
    reg_d0.h[0] = (u16)((s16)reg_d0.h[0] >> 2);
    reg_d2.h[0] = D_0028E904;
    reg_d1.h[0] = reg_d0.h[0];
    D_0028E480_as_u32 = (u32)(s16)reg_d2.h[0];
    reg_d2.w = D_0028E480_as_u32;
    quotient = (s16)reg_d2.h[0] / (s16)reg_d1.h[0];
    reg_d1.b[0] = val;
    reg_d1.b[0] -= 1;
    reg_d0.w = 4;
    reg_d2.h[0] = (u16)quotient;
}
