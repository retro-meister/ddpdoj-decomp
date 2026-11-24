#include "common.h"

extern u16 D_00264560[];
extern u32 D_0028D9F8;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;

void death_func_0021BBB0(void) {
    reg_a0 = (u8 *) D_00264560;
    reg_a1 = reg_a4 + 2;
    reg_d0.w = ((u32) D_0028D9F8 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    *(u16 *)(reg_a4 + 0xC) = 0x404;
}
