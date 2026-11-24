#include "common.h"

s32 func_002119A0();
extern u8 D_00251700[];
extern u32 D_0028E9A0;
extern u8 *reg_a0;
extern u16 *reg_a2_as_u16_p;
extern u8 *reg_a6;

void func_00211920(void) {
    D_0028E9A0 = reg_d0.w;
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] &= 0x3C;
    reg_a2_as_u16_p = *(u16 **)(D_00251700 + (reg_d3.h[0] & ~3));
    *(u16 *)(reg_a0 + 0) = *reg_a2_as_u16_p;
    reg_a2_as_u16_p += 1;
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    func_002119A0();
}
