#include "common.h"

extern u8 D_002A04B0[];
extern u8 D_002A1770[];
extern u8 *reg_a0;
extern s8 D_0028E408;

void func_00207600(void) {
    s32 d0;
    s32 d1;
    s32 d2;
    u32 tmp;

    d1 = reg_d1.w;
    d0 = reg_d0.w;
    d2 = reg_d2.w;
    reg_a0 = (u8 *)D_002A04B0;
    reg_d1.w = 0x13;
loop_1:
    reg_d2.h[1] = *(u16 *) (reg_a0 + 0x4C);
    reg_d2.h[0] = *(u16 *) (reg_a0 + 0x4E);
    if (reg_d2.w == 0) goto next_1;
    if (reg_d2.w != reg_d0.w) goto next_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    D_0028E408 = 0;
    return;
next_1:
    reg_a0 += 0x50;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_a0 = (u8 *)D_002A1770;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    D_0028E408 = 1;
}
