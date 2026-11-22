#include "common.h"

extern u32 D_00262A30[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;
extern void func_0019C530(void);

void func_001BDFC0(void)
{
    reg_a0 = (u8 *)D_00262A30;
    reg_a0 += *(u16 *)(reg_a5 + 0x24);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d4.h[0] = 0x11;
    reg_d1.w += 0xDC00E600U;
    reg_d3.h[0] = 0x24D0;
    func_0019C530();
}
