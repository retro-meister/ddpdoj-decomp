#include "common.h"

extern s16 D_0028E0C0;
extern u16 D_0029FCB0[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_001A3130(void) {
    s32 d0;
    s32 d1;
    u8 *a0;
    u8 *a1;
    u32 tmp;

    d0 = reg_d0.w;
    d1 = reg_d1.w;
    a0 = reg_a0;
    a1 = reg_a1;
    reg_a1 = (u8 *) D_0029FCB0;
    reg_d0.h[0] <<= 6;
    reg_a1 += reg_d0.h[0];
loop_1:
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = d0;
    D_0028E0C0 = 1;
    reg_d1.w = d1;
    reg_a0 = a0;
    reg_a1 = a1;
}
