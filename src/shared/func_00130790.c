#include "common.h"

extern u8 D_0028E1C0[];
extern u8 D_0028E1C8[];
extern u8 D_0028E228;
extern u8 D_0028E350;
extern u8 D_0028E39C;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00130790(void) {
    u8 *sa0, *sa1, *sa2, *sa3, *sa4, *sa5, *sa6;
    u32 sd0, sd1, sd2, sd3, sd4, sd5, sd6, sd7;
    u8 v;
    u16 c;
    u32 count;

    if (D_0028E350 != 0) return;
    if (D_0028E39C == 0x12) return;
    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    sd2 = reg_d2.w;
    sd3 = reg_d3.w;
    sd4 = reg_d4.w;
    sd5 = reg_d5.w;
    sd6 = reg_d6.w;
    sd7 = reg_d7.w;
    sa0 = reg_a0;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa3 = reg_a3;
    sa4 = reg_a4;
    sa5 = reg_a5;
    sa6 = reg_a6;
    reg_a0 = &D_0028E228;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 = (u8 *)D_0028E1C8;
    reg_d7.w = 1;
    reg_d0.h[0] = ~(s16)reg_d0.h[0];
loop_1:
    v = *(u8 *)(reg_a0 + 1);
    if (v != 0) goto next_2;
    if ((reg_d0.w & 1) == 0) goto next_5;
    *(u8 *)(reg_a0 + 1) = 1;
    *(s16 *)(reg_a0 + 4) = 0;
    *(u16 *)(reg_a0 + 2) = 1;
    goto next_5;
next_2:
    if (v != 1) goto next_3;
    if ((reg_d0.w & 1) == 0) goto block_1;
    c = *(u16 *)(reg_a0 + 2);
    if (c == 0xFFFF) goto next_5;
    *(u16 *)(reg_a0 + 2) = c + 1;
    goto next_5;
block_1:
    *(u8 *)(reg_a0 + 1) = 2;
    goto next_5;
next_3:
    if (v != 2) goto next_5;
    if (reg_d0.w & 1) goto block_3;
    *(u8 *)(reg_a0 + 1) = 0;
    reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
    *(u16 *)(reg_a0 + 2) = 0;
    if ((s16)reg_d1.h[0] < 3) goto block_2;
    if ((s16)reg_d1.h[0] >= 0x27) goto block_2;
    *(s16 *)(reg_a0 + 4) = 0x80;
    goto next_5;
block_2:
    *(s16 *)(reg_a0 + 4) = 1;
    goto next_5;
block_3:
    *(u8 *)(reg_a0 + 1) = 1;
next_5:
    if (reg_d0.h[0] & 1) {
        reg_d0.h[0] = (s32)(reg_d0.h[0] & 0xFFFF) >> 1;
        reg_d0.h[0] |= 0x8000;
    } else {
        reg_d0.h[0] = (s32)(reg_d0.h[0] & 0xFFFF) >> 1;
    }
    reg_a0 = (u8 *)D_0028E1C0;
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
}
