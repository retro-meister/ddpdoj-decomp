#include "common.h"

extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;
extern u8 *reg_a5;

void func_0014E300(void)
{
    u32 savedCounter;
    u16 *savedSource;
    u16 *savedDestination;

    savedDestination = reg_a1_as_u16_p;
    savedCounter = reg_d0.w;
    savedSource = reg_a0_as_u16_p;
    reg_a1_as_u16_p = (u16 *)(reg_a5 + 0x16);

    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p++;
        reg_a1_as_u16_p++;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.w = savedCounter;
    reg_a0_as_u16_p = savedSource;
    reg_a1_as_u16_p = savedDestination;
}
