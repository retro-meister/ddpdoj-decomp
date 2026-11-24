#include "common.h"

extern void *reg_a4_as_void_p;
extern u16 D_0028E864;
extern void func_001DB2B0(void);

void func_001DB260(void)
{
    ((u16 *)reg_a4_as_void_p)[1] = 0x820;
    ((u16 *)reg_a4_as_void_p)[2] = 4;
    ((u16 *)reg_a4_as_void_p)[3] = 0xC;
    ((u8 *)reg_a4_as_void_p)[9] = 0x48;
    ((u8 *)reg_a4_as_void_p)[8] = 0xA0;
    D_0028E864 = 0;
    func_001DB2B0();
}
