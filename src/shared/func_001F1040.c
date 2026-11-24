#include "common.h"

extern void *reg_a6_as_void_p;
extern u16 D_0028E4A6;
extern void func_0019C670(void);

void func_001F1040(void)
{
    u8 *source;

    reg_d2.w = 0x1E51;
    source = (u8 *)reg_a6_as_void_p;
    D_0028E4A6 = *(u16 *)(source + 2);
    reg_d1.h[0] = *(u16 *)(source + 4);
    reg_d1.w = reg_d1.w + 0x0200FFC0U;
    reg_d4.w = 0;
    reg_d1.w = reg_d1.w + 0xF200F400U;
    reg_d3.h[0] = 0xE60;
    *(u8 *)&reg_d4 = source[0xE6];
    func_0019C670();
}
