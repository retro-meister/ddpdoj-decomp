#include "common.h"

extern s8 *reg_a0;
extern u16 *reg_a6;

void func_0014ED40(void)
{
    reg_d0.b[0] = (u8)*reg_a0;
    reg_a0 += 1;
    reg_d0.b[0] -= 1;

    if (reg_d0.b[0] == 0) {
        *reg_a6 &= 0xDFFE;
    } else {
        *reg_a6 |= 0x2001;
    }
}
