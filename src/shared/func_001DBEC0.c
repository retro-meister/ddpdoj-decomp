#include "common.h"

extern void *reg_a4;
extern void func_001DBF10(void);

void func_001DBEC0(void)
{
    ((u8 *)reg_a4)[3] = 0;
    ((u16 *)reg_a4)[2] = 0x404;
    ((u16 *)reg_a4)[3] = 0x303;
    ((u16 *)reg_a4)[4] = 5;
    ((u16 *)reg_a4)[5] = 0;
    ((u16 *)reg_a4)[6] = 0x8000;
    ((u16 *)reg_a4)[7] = 0;
    func_001DBF10();
}
