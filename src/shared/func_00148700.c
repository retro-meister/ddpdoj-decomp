#include "common.h"

s32 func_0014BE20();                            /* extern */
s32 func_0019D530();                            /* extern */
extern s32 reg_a0_as_s32;
extern s32 reg_a6_as_s32;

void func_00148700(void) {
    reg_a0_as_s32 = reg_a6_as_s32;
    func_0014BE20();
    func_0019D530();
}
