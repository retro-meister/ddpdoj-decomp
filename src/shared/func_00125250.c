#include "common.h"

extern u16 D_002960B0[];
extern u8 *reg_a0;
extern s8 D_0028E408;

void func_00125250(void) {
    u8 *a0;
    s32 d0;
    s32 d1;
    s32 d2;
    u32 tmp;

    d1 = reg_d1.w;
    a0 = reg_a0;
    d0 = reg_d0.w;
    d2 = reg_d2.w;
    reg_a0 = (u8 *) D_002960B0;
    reg_d1.w = 9;
loop_1:
    reg_d2.h[0] = *(u16 *) reg_a0;
    if (reg_d2.h[0] == 0) goto next_1;
    reg_d2.h[0] &= 0xFF;
    if (reg_d0.h[0] != reg_d2.h[0]) goto next_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
    D_0028E408 = 1;
    return;
next_1:
    reg_a0 += 0x20;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
    D_0028E408 = 0;
}
