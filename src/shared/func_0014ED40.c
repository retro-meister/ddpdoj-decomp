#include "common.h"

extern s8 *reg_a0_as_s8_p;
extern u16 *reg_a6_as_u16_p;

void func_0014ED40(void)
{
    reg_d0.b[0] = (u8)*reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d0.b[0] -= 1;

    if (reg_d0.b[0] == 0) {
        *reg_a6_as_u16_p &= 0xDFFE;
    } else {
        *reg_a6_as_u16_p |= 0x2001;
    }
}
