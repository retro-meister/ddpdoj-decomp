#include "common.h"

extern s8 *D_0026B230[];
extern u16 D_0028E29C;
extern u16 D_0028E788;
extern s8 *reg_a0_as_s8_p;

void func_00172090(void)
{
    reg_d0.w = 0;
    reg_a0_as_s8_p = *(s8 **)((u8 *)D_0026B230 + (D_0028E29C & ~3));
    reg_a0_as_s8_p += 7;
    reg_a0_as_s8_p -= D_0028E788;
    reg_d0.b[0] = (u8)*reg_a0_as_s8_p;
}
