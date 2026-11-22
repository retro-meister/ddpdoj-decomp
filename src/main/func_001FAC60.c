#include "common.h"

extern u8 *reg_a6;
extern void func_0019C530(void);

void func_001FAC60(void)
{
    u8 *object = reg_a6;

    reg_d2.w = 0x1E7D;
    reg_d1.h[1] = *(u16 *)(object + 0x22);
    reg_d1.h[0] = *(u16 *)(object + 0x24);
    reg_d1.w += 0xF600F800U;
    reg_d3.h[0] = 0xA40;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = object[0x3C];
    func_0019C530();
}
