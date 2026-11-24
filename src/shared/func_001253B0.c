#include "common.h"

extern s16 D_002960B0[];
extern s16 *reg_a0;

void func_001253B0(void)
{
    s16 *savedAddressRegister;
    u32 savedDataRegister;

    savedDataRegister = reg_d0.w;
    savedAddressRegister = reg_a0;
    reg_a0 = D_002960B0;
    reg_d0.w = 9;

    do {
        *reg_a0 = 0;
        reg_a0 += 0x10;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_a0 = savedAddressRegister;
    reg_d0.w = savedDataRegister;
}
