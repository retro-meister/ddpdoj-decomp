#include "common.h"

extern u16 D_00264800[];
extern u32 D_0028DA14;
extern u16 *reg_a0;
extern u16 *reg_a1;
extern s32 reg_a4;

void func_001F0050(void) {
    reg_a0 = D_00264800;
    reg_a1 = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DA14 >> 1) - 1;
    do {
        *reg_a1 = *reg_a0;
        reg_a0 += 1;
        reg_a1 += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
