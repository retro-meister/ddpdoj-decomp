#include "common.h"

extern u16 D_00264560[];
extern u32 D_0028D9F8;
extern u16 *reg_a0;
extern u16 *reg_a1;
extern u8 *reg_a4;

void func_001ED160(void) {
    reg_a0 = D_00264560;
    reg_a1 = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9F8 >> 1) - 1;
    do {
        *reg_a1 = *reg_a0;
        reg_a0 += 1;
        reg_a1 += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0x404;
}
