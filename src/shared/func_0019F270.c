#include "common.h"

s32 func_0019C000();                            /* extern */
s32 func_0019DD20();                            /* extern */
extern s32 reg_a0_as_s32;
extern s32 reg_a3_as_s32;
extern s32 reg_a6_as_s32;

void func_0019F270(void) {
    s32 temp_s0;
    s32 temp_s0_2;

    temp_s0 = reg_a6_as_s32;
    func_0019DD20();
    reg_a6_as_s32 = reg_a0_as_s32 - 0x2C;
    func_0019C000();
    reg_a6_as_s32 = temp_s0;
    reg_a6_as_s32 += 0x20;
    temp_s0_2 = reg_a6_as_s32;
    reg_a0_as_s32 = reg_a3_as_s32;
    func_0019DD20();
    reg_a6_as_s32 = reg_a0_as_s32 - 0x2C;
    func_0019C000();
    reg_a6_as_s32 = temp_s0_2;
}
