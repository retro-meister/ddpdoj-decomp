#include "common.h"
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BE1E0(void) {
    reg_d0.b[0] = reg_a4[3];
    reg_d1.b[0] = reg_a6[0x1B];
    reg_tmp.b[0] = reg_a4[5];
    reg_a4[5] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_1;
    reg_a4[5] = reg_a4[4];
    if (reg_d0.b[0] == reg_d1.b[0]) goto block_1;
    if ((s8) reg_d0.b[0] < (s8) reg_d1.b[0]) goto next_1;
    reg_d1.b[0] += 1;
    goto block_1;
next_1:
    reg_d1.b[0] -= 1;
block_1:
    reg_a6[0x1B] = reg_d1.b[0];
}
