#include "common.h"

typedef void (*Fn)(void);

s32 func_00211430();
extern u8 D_00299780_as_u8_a[];
extern u16 D_00299D20[];
extern u8 *jtbl_0028E3F4;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_00211720(void) {
    u32 t1;

    reg_a6 = (u8 *)D_00299780_as_u8_a;
    goto loop_1;
skip_1:
    reg_a6 += 0x30;
loop_1:
    if (!(0 > (s64)*(s16 *)reg_a6)) {
        goto skip_1;
    }
    if (0 > (s64)(s32)reg_d6.w) {
        goto block_1;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x14);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x16);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x10);
    *(u16 *)(reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0xC) = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x10) -= 4;
    if (0 > (s64)*(s16 *)(reg_a6 + 0x10)) {
        *(u16 *)(reg_a6 + 0x10) = *(u16 *)(reg_a6 + 0x12);
    }
block_1:
    func_00211430();
    if (reg_d6.h[0] != 0) {
        goto block_2;
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    if (*(s16 *)(reg_a6 + 2) < reg_d0.sh[0]) {
        goto block_3;
    }
block_2:
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1F);
    reg_a0 = *(u8 **)(reg_a4 + reg_d0.h[0]);
    jtbl_0028E3F4 = reg_a0;
    ((Fn)jtbl_0028E3F4)();
    reg_a6 += 0x30;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
    return;
block_3:
    *(s16 *)reg_a6 = 0;
    D_00299D20[0] -= 1;
    reg_a6 += 0x30;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}
