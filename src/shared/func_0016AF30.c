#include "common.h"

extern void *reg_a6_as_void_p;
extern void func_00201160(void);

void func_0016AF30(void)
{
    ((u16 *)reg_a6_as_void_p)[0xC] = 0x700;
    ((u16 *)reg_a6_as_void_p)[0xD] = 0xB00;
    func_00201160();
    reg_d0.b[0] >>= 1;
    reg_d0.b[0] += 0x10;
    ((u8 *)reg_a6_as_void_p)[0x1A] = reg_d0.b[0];
}
