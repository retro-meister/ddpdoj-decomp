#include "common.h"

extern u8 D_0028E38C;
extern u32 D_0028E480;
extern u16 D_0028E904;

void func_00124520(void)
{
    s32 quotient;

    reg_d1.w = 0;
    reg_d0.h[0] = (u16)((s16)reg_d0.h[0] >> 2);
    reg_d2.h[0] = D_0028E904;
    reg_d1.h[0] = reg_d0.h[0];
    D_0028E480 = (u32)(s16)reg_d2.h[0];
    reg_d2.w = D_0028E480;
    quotient = (s16)reg_d2.h[0] / (s16)reg_d1.h[0];
    reg_d1.b[0] = D_0028E38C;
    reg_d0.w = 4;
    reg_d2.h[0] = (u16)quotient;
    reg_d1.b[0] -= 1;
}
