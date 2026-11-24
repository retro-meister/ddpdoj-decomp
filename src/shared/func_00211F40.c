#include "common.h"

s32 func_002119A0();
extern u8 D_00251700[];
extern u32 D_0028E9A0;
extern u8 *reg_a0;
extern u16 *reg_a2_as_u16_p;

void func_00211F40(void) {
    D_0028E9A0 = reg_d0.w;
    *(s8 *)(reg_a0 + 0x1E) = 0x1F;
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] &= 0x3C;
    reg_a2_as_u16_p = *(u16 **)(D_00251700 + (reg_d3.h[0] & ~3));
    *(u16 *)(reg_a0 + 0) = *reg_a2_as_u16_p;
    reg_a2_as_u16_p += 1;
    *(u16 *)(reg_a0 + 2) = reg_d2.h[1];
    *(u16 *)(reg_a0 + 4) = reg_d2.h[0];
    func_002119A0();
}
