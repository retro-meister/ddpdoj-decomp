#include "common.h"

extern void func_0019BC10(void);
extern void func_0019BD40(void);

extern u16 D_0028E198;
extern u8 D_002AC9A0[];
extern u8 *reg_a0;

void func_0019C940(void)
{
    u8 *saved_a0;
    u32 saved_d4;
    u32 saved_d7;

    saved_d4 = reg_d4.w;
    saved_d7 = reg_d7.w;
    saved_a0 = reg_a0;

    func_0019BC10();
    reg_a0 = D_002AC9A0;
    reg_a0 += D_0028E198;
    func_0019BD40();

    reg_d4.w = saved_d4;
    reg_d7.w = saved_d7;
    reg_a0 = saved_a0;
    D_0028E198 += 0xC;
}
