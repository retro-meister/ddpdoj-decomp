#include "common.h"

extern u16 *reg_a0;
extern u16 *reg_a1;
extern u8 *reg_a5;

void func_0014E300(void)
{
    u32 savedCounter;
    u16 *savedSource;
    u16 *savedDestination;

    savedDestination = reg_a1;
    savedCounter = reg_d0.w;
    savedSource = reg_a0;
    reg_a1 = (u16 *)(reg_a5 + 0x16);

    do {
        *reg_a1 = *reg_a0;
        reg_a0++;
        reg_a1++;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.w = savedCounter;
    reg_a0 = savedSource;
    reg_a1 = savedDestination;
}
