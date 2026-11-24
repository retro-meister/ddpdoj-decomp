#include "common.h"

void func_002025E0(void) {
    u32 tmp;

    reg_d0.h[0] = reg_d0.b[0];
    reg_d1.h[0] = reg_d1.b[0];
    reg_d2.h[0] = reg_d1.h[0];
    reg_d5.h[0] -= 1;
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] == 0) goto block_5;
    if (reg_d1.b[0] < 0x80) goto next_2;
    goto next_4;
loop_1:
    reg_d1.h[0] = reg_d2.h[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] == 0) goto block_5;
next_2:
    reg_d0.b[0] += 1;
    tmp = reg_d5.h[0] - 1;
    reg_d5.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d1.h[0] = reg_d0.h[0];
    return;
loop_3:
    reg_d1.h[0] = reg_d2.h[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] == 0) goto block_5;
next_4:
    reg_d0.b[0] -= 1;
    tmp = reg_d5.h[0] - 1;
    reg_d5.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_3;
block_5:
    reg_d1.h[0] = reg_d0.h[0];
}
