#include "common.h"

extern s32 D_002B2750[];
extern s32 *reg_a0;

void func_0012FBE0(void) {
    reg_a0 = D_002B2750;
    reg_d0.h[0] = 0x7F;
    do {
        *reg_a0 = 0;
        reg_a0 += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
