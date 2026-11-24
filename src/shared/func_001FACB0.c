#include "common.h"

extern u8 *reg_a6;
extern void func_0019C530(void);

void func_001FACB0(void)
{
    u8 *object = reg_a6;

    reg_d2.w = 0x1E7E;
    reg_d1.h[1] = *(u16 *)(object + 0x42);
    reg_d1.h[0] = *(u16 *)(object + 0x44);
    reg_d4.w = 0;
    reg_d1.w += 0xF600F800U;
    reg_d3.h[0] = 0xA40;
    *(u8 *)&reg_d4 = object[0x5C];
    func_0019C530();
}
