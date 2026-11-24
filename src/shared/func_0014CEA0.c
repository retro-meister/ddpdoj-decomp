#include "common.h"

extern u16 *reg_a1_as_u16_p;
extern u16 *reg_a2_as_u16_p;
extern s32 reg_a5_as_s32;

void func_0014CEA0(void) {
    reg_a2_as_u16_p = (u16 *)(reg_a5_as_s32 + 0x22);
    if (reg_d6.h[0] != 0) {
        reg_a2_as_u16_p = (u16 *)(reg_a5_as_s32 + 0x1C);
    }
    *reg_a2_as_u16_p = *reg_a1_as_u16_p;
    reg_a1_as_u16_p += 1;
}
