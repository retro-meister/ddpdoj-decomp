#include "common.h"

extern u8 *reg_a4;
extern void func_001DBBE0(void);

void func_001DBB90(void)
{
    reg_a4[0x3] = 0;
    *(u16 *)(reg_a4 + 0x4) = 0x20;
    *(u16 *)(reg_a4 + 0x6) = 0x808;
    *(u16 *)(reg_a4 + 0x8) = 1;
    *(u16 *)(reg_a4 + 0xA) = 0;
    reg_a4[0x8] = reg_a4[0x10];
    func_001DBBE0();
}
