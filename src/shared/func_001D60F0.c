#include "common.h"

extern void func_00129280(void);
extern u32 D_00259970_as_u32_a[];
extern u8 *reg_a0;

void func_001D60F0(void)
{
    reg_d0.w = 0x80004;
    reg_d4.w = 0;
    reg_d7.w = 0xF;
    reg_a0 = (u8 *)D_00259970_as_u32_a;

    do {
        func_00129280();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
