#include "common.h"

extern s32 D_002B2950_as_s32_a[];
extern s32 *reg_a0_as_s32_p;

void func_0012FC30(void) {
    reg_a0_as_s32_p = D_002B2950_as_s32_a;
    reg_d0.h[0] = 0x1FF;
    do {
        *reg_a0_as_s32_p = 0;
        reg_a0_as_s32_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
