#include "common.h"

extern Reg32 D_0028E480;
extern u8 D_002BC7C0[];
extern u8 D_002BD440[];
extern u8 *reg_a5;
extern u8 *reg_a6;

s32 func_0014DCA0(void) {
    u32 count;
    s32 ret;

    ret = 0;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0xC);
    if ((s8)reg_d2.b[0] >= 0) goto block_2;
block_1:
    reg_a6 = (u8 *)D_002BD440;
    reg_d2.w = 0x32;
    goto loop_3;
block_2:
    if (reg_d2.w & 0x20) goto block_1;
    reg_a6 = (u8 *)D_002BC7C0;
    reg_d2.w = 0x64;
loop_3:
    D_0028E480.w = reg_d2.h[0];
    D_0028E480.w -= 1;
    reg_d2.h[0] = D_0028E480.h[0];
    if (D_0028E480.h[1] != 0) {
        ret = D_0028E480.h[1] & 0xFFFF;
        goto block_7;
    }
    if (*(u8 *)(reg_a6 + 1) != 0) goto block_4;
    reg_a6 += 0x20;
    goto block_5;
block_4:
    reg_a6 += 0x20;
    reg_d1.h[0] = reg_d0.h[0];
    goto loop_3;
block_5:
    count = reg_d1.h[0] - 1;
    reg_d1.h[0] = count;
    if (((s64)((s64)(u16) count << 0x30) >> 0x30) >= 0) goto loop_3;
loop_6:
    reg_a6 -= 0x20;
    *(u16 *)reg_a6 = 0x8000;
    count = reg_d0.h[0] - 1;
    reg_d0.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_6;
block_7:
    return ret;
}
