#include "common.h"

extern s8 D_0028E408;

void func_001E8FF0(void) {
    if (reg_d3.b[0] != reg_d1.b[0]) {
        reg_d6.w = 0x3F;
        if (((s32) reg_d1.b[0] < 0x18) || ((s32) reg_d1.b[0] > 0x28)) {
            reg_d4.b[0] = reg_d1.b[0];
            reg_d5.b[0] = reg_d3.b[0];
            reg_d4.b[0] -= 0x20;
            reg_d5.b[0] -= reg_d1.b[0];
            reg_d4.h[0] &= reg_d6.h[0];
            reg_d5.h[0] &= reg_d6.h[0];
            if ((s32) reg_d4.b[0] >= 0x20) {
                if ((s32) reg_d5.b[0] <= 0x20) {
                    goto block_7;
                }
                goto block_9;
            }
            if ((s32) reg_d5.b[0] <= 0x20) {
                goto block_9;
            }
        }
block_7:
        reg_d1.b[0] -= reg_d3.b[0];
        reg_d1.h[0] &= reg_d6.h[0];
        if ((s32) reg_d1.b[0] < 0x20) {
            goto block_11;
        }
        goto block_13;
block_9:
        reg_d1.b[0] -= reg_d3.b[0];
        reg_d1.h[0] &= reg_d6.h[0];
        if ((s32) reg_d1.b[0] < 0x20) {
            goto block_13;
        }
block_11:
        if (reg_d3.b[0] != 0x28) {
            reg_d3.b[0] += 1;
            goto block_15;
        }
        goto block_16;
block_13:
        if (reg_d3.b[0] != 0x18) {
            reg_d3.b[0] -= 1;
block_15:
            D_0028E408 = 0;
            reg_d3.h[0] &= reg_d6.h[0];
            reg_d1.b[0] = reg_d3.b[0];
            return;
        }
    }
block_16:
    D_0028E408 = 1;
}
