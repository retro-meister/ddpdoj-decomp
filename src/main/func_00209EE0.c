#include "common.h"

extern s32 work_reg_a4;
extern s32 D_0028E570;
extern u16 D_0028E160;

void func_00209EE0(void) {
    work_reg_a4 -= D_0028E570;
    *(s32 *)bcd_digits = work_reg_a4;
    D_0028E160 = *(u16 *)bcd_digits;
}
