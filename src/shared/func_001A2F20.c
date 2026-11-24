#include "common.h"

extern u32 reg_a0_as_u32;
extern u32 reg_a1_as_u32;

void func_001A2F20(void)
{
    do {
        *(u16 *)reg_a1_as_u32 = *(u16 *)reg_a0_as_u32;
        reg_a0_as_u32 += 2;
        reg_a1_as_u32 += 2;

        *(u16 *)reg_a1_as_u32 = *(u16 *)reg_a0_as_u32;
        reg_a0_as_u32 += 2;
        reg_a1_as_u32 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
