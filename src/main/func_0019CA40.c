#include "common.h"

extern void func_0019BC10(void);
extern void func_0019BD40(void);
extern u16 D_0028E190;
extern u8 D_002A9AE0[];
extern u8 *reg_a0;

void func_0019CA40(void)
{
    u8 *saved_a0;
    u32 saved_d4;
    u32 saved_d7;

    saved_d4 = reg_d4.w;
    saved_d7 = reg_d7.w;
    saved_a0 = reg_a0;

    func_0019BC10();
    reg_a0 = D_002A9AE0;
    reg_a0 += D_0028E190;
    func_0019BD40();

    reg_d4.w = saved_d4;
    reg_d7.w = saved_d7;
    reg_a0 = saved_a0;
    D_0028E190 += 0xC;
}
