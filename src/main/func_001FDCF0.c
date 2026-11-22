#include "common.h"

extern void *reg_a6;
extern void func_001FDBD0(void);

void func_001FDCF0(void)
{
    u8 *object;

    reg_d2.w = 0x1E93;
    object = reg_a6;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.h[1] += *(u16 *)(object + 0x68);
    reg_d1.w += 0xF47FFC00u;
    reg_d4.w = 0;
    reg_d1.w += 0xF600FE00u;
    reg_d3.h[0] = 0xA10;
    *(u8 *)&reg_d4 = object[0x7C];
    func_001FDBD0();
}
