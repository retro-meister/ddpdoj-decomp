#include "common.h"

extern void *reg_a6;
extern void func_001FDBD0(void);

void func_001FDD60(void)
{
    u8 *object = (u8 *)reg_a6;

    reg_d2.w = 0x1E93;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.h[1] += *(u16 *)(object + 0x6A);
    reg_d4.w = 0;
    reg_d1.w = reg_d1.w + 0xF4800400U;
    reg_d1.w = 0xF600FE00U + reg_d1.w;
    reg_d3.h[0] = 0x0A10;
    *(u8 *)&reg_d4.w = object[0x7C];
    func_001FDBD0();
}
