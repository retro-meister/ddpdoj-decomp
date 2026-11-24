#include "common.h"

s32 func_002010A0();
s32 func_00201E20();
extern u8 *reg_a6;

void func_001E4D90(s32 arg0, s32 arg1) {
    u16 *p0;
    u8 *p1;

    p0 = (u16 *)(reg_a6 + arg0);
    reg_d0.h[0] = *p0;
    p1 = reg_a6;
    p1 += arg1;
    if (reg_d0.h[0] == 0) goto next_3;
    if ((s16)reg_d0.h[0] >= 0) goto next_1;
    if (*(s16 *)p1 > 0x5A00) goto block_rts;
    reg_d1.b[0] = 0;
    func_002010A0();
    reg_d0.b[0] = (s8)reg_d0.b[0] >> 1;
    reg_d0.b[0] += 4;
    goto next_5;
next_1:
    if (*(s16 *)p1 < 0x6400) goto block_rts;
    reg_d1.b[0] = 0x80;
    func_002010A0();
    reg_d0.b[0] = (s8)reg_d0.b[0] >> 1;
    reg_d0.b[0] += 4;
    goto next_5;
next_3:
    func_002010A0();
    reg_d1.w = 0;
    if ((s8)reg_d0.b[0] >= 0) goto next_4;
    reg_d1.b[0] = 0x80;
next_4:
    func_002010A0();
    reg_d0.b[0] = (s8)reg_d0.b[0] >> 1;
    reg_d0.b[0] += 4;
next_5:
    reg_d0.h[0] = reg_d0.b[0];
    reg_d1.h[0] = reg_d1.b[0];
    func_00201E20();
    *p0 = reg_d2.h[0];
block_rts:
    return;
}
