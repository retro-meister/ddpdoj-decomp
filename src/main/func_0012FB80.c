#include "common.h"

extern s32 D_002B3950[];
extern s32 *reg_a0;

void func_0012FB80(void) {
    reg_a0 = D_002B3950;
    reg_d0.h[0] = 0x4FF;
    do {
        *reg_a0 = 0;
        reg_a0 += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
