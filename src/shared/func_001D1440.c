#include "common.h"

extern u8 *reg_a6;
extern u16 D_0028E4A6;
extern void func_0019C670(void);

void func_001D1440(void)
{
    u8 *object = reg_a6;

    reg_d2.w = 0x1BFA;
    D_0028E4A6 = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.w = reg_d1.w + 0xDE00EC00U;
    reg_d3.h[0] = 0x22A0;
    reg_d4.h[0] = *(u16 *)(object + 0x1C);
    *(u8 *)&reg_d4 = object[0x67];
    func_0019C670();
}
