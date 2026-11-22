#include "common.h"

s32 func_0019BB40();                            /* extern */
s32 func_0019D5F0();                            /* extern */
extern s32 reg_a0;

void func_0019D6D0(void) {
    s32 temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0;
    temp_s1 = reg_d0.w;
    func_0019D5F0();
    func_0019BB40();
    reg_d0.w = temp_s1;
    reg_a0 = temp_s0;
}
