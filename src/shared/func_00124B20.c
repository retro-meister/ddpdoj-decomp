#include "common.h"

extern s16 D_00296214_as_s16_a[];
extern s16 D_002962B4[];
extern u8 *reg_a0;

void func_00124B20(void) {
    s32 d0 = reg_d0.w;
    s32 d1 = reg_d1.w;
    u32 tmp;

    reg_a0 = (u8 *) D_00296214_as_s16_a;
    reg_d1.w = 4;
loop_1:
    if (*(s16 *) reg_a0 != 0) goto next_1;
    reg_d0.h[0] |= 0x8000;
    *(s16 *) reg_a0 = reg_d0.h[0];
    reg_d1.w = d1;
    reg_d0.w = d0;
    return;
next_1:
    reg_a0 += 0x20;
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_a0 = (u8 *) D_002962B4;
    reg_d1.w = d1;
    reg_d0.w = d0;
}
