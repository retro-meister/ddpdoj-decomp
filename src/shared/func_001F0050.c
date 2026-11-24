#include "common.h"

extern u16 D_00264800[];
extern u32 D_0028DA14;
extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;
extern s32 reg_a4_as_s32;

void func_001F0050(void) {
    reg_a0_as_u16_p = D_00264800;
    reg_a1_as_u16_p = (u16 *)(reg_a4_as_s32 + 2);
    reg_d0.w = ((u32) D_0028DA14 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
