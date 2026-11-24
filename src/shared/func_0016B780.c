#include "common.h"

extern u8 *reg_a6;
extern void func_002021D0(void);

void func_0016B780(void)
{
    u16 savedD1;

    *(u16 *)(reg_a6 + 0x18) = 0x700;
    *(u16 *)(reg_a6 + 0x1A) = 0xB20;
    savedD1 = reg_d1.h[0];
    reg_d2.h[0] = 0x4600;
    reg_d3.h[0] = 0x1C00;
    func_002021D0();
    reg_a6[0x1A] = reg_d1.b[0];
    reg_d1.h[0] = savedD1;
    *(u16 *)(reg_a6 + 0x1E) = 0x714;
}
