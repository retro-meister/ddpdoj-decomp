#include "common.h"

extern void *reg_a4_as_void_p;
extern void func_001DBF10(void);

void func_001DBEC0(void)
{
    ((u8 *)reg_a4_as_void_p)[3] = 0;
    ((u16 *)reg_a4_as_void_p)[2] = 0x404;
    ((u16 *)reg_a4_as_void_p)[3] = 0x303;
    ((u16 *)reg_a4_as_void_p)[4] = 5;
    ((u16 *)reg_a4_as_void_p)[5] = 0;
    ((u16 *)reg_a4_as_void_p)[6] = 0x8000;
    ((u16 *)reg_a4_as_void_p)[7] = 0;
    func_001DBF10();
}
