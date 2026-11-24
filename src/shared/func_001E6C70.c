#include "common.h"

extern void *reg_a4_as_void_p;
extern void func_002011D0(void);
extern void func_00201160(void);

void func_001E6C70(void)
{
    *(u16 *)((u8 *)reg_a4_as_void_p + 4) = 0;
    func_002011D0();
    ((u8 *)reg_a4_as_void_p)[4] = reg_d0.b[0];
    func_00201160();
    ((u8 *)reg_a4_as_void_p)[2] = reg_d0.b[0];
    func_00201160();
    *(u16 *)((u8 *)reg_a4_as_void_p + 6) = reg_d0.h[0];
    ((u8 *)reg_a4_as_void_p)[3] = 0;
}
