#include "common.h"

extern s16 D_002960B0_as_s16_a[];
extern s16 *reg_a0_as_s16_p;

void func_001253B0(void)
{
    s16 *savedAddressRegister;
    u32 savedDataRegister;

    savedDataRegister = reg_d0.w;
    savedAddressRegister = reg_a0_as_s16_p;
    reg_a0_as_s16_p = D_002960B0_as_s16_a;
    reg_d0.w = 9;

    do {
        *reg_a0_as_s16_p = 0;
        reg_a0_as_s16_p += 0x10;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_a0_as_s16_p = savedAddressRegister;
    reg_d0.w = savedDataRegister;
}
