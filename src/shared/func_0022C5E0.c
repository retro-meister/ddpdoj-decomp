#include "common.h"

extern s32 reg_a0_as_s32;
extern void func_00222F90(s32 x, s32 y, s32 value);

void func_0022C5E0(s64 x, s32 workAddress, s32 unusedA2, s32 unusedA3,
                   s32 unusedT0, s32 value)
{
    s32 savedWorkAddress = reg_a0_as_s32;

    reg_a0_as_s32 = workAddress;
    func_00222F90(0x1C0 - (s16)x, 0x18, value & 0xFFFF);
    reg_a0_as_s32 = savedWorkAddress;
}
