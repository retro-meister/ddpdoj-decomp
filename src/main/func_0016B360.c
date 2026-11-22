#include "common.h"

extern void *reg_a6;
extern void func_00201160(void);

void func_0016B360(void)
{
    *(u16 *)((u8 *)reg_a6 + 0x18) = 0x700;
    *(u16 *)((u8 *)reg_a6 + 0x1A) = 0xB00;
    func_00201160();
    *((u8 *)reg_a6 + 0x1A) = reg_d0.b[0];
    *((u8 *)reg_a6 + 0x1A) |= 8;
}
