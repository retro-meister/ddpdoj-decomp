#include "common.h"

extern u8 D_002555E0[];
extern u8 D_0028E078[];
extern u8 D_0028E080[];
extern u8 D_0029F260_as_u8_a[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a4;

void func_00145E70(u8 *arg0) {
    u8 *sa0;
    u8 *sa1;
    u8 *sa2;
    u8 *sa4;
    u32 sd0;
    u32 sd1;
    u32 stmp;

    sa0 = reg_a0;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa4 = reg_a4;
    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    stmp = reg_tmp.w;
    if (D_0029F260_as_u8_a == arg0) {
        reg_a4 = (u8 *)D_0028E080;
    } else {
        reg_a4 = (u8 *)D_0028E078;
    }
    reg_d1.w = 0;
    reg_d1.h[0] = *(u16 *)(arg0 + 0x20);
    reg_d0.h[0] = *(u16 *)(arg0 + 0x5A);
    reg_d0.h[0] -= 2;
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += *(u16 *)(arg0 + 0x58);
    reg_d0.h[0] <<= 2;
    reg_a2 = (u8 *)D_002555E0;
    *(u16 *)(reg_a4 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 2) = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 4) = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a2 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 6) = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a2 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a2;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
    reg_tmp.w += reg_d1.w;
    *(u16 *)(reg_a4 + 0) = reg_tmp.h[1];
    *(u16 *)(reg_a4 + 2) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 6);
    reg_tmp.w += reg_d1.w;
    *(u16 *)(reg_a4 + 4) = reg_tmp.h[1];
    *(u16 *)(reg_a4 + 6) = reg_tmp.h[0];
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a4 = sa4;
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_tmp.w = stmp;
}
