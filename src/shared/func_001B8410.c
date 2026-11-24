#include "common.h"

s32 func_001B8440();                            /* extern */
extern s32 reg_a5;

void func_001B8410(void) {
    s32 temp_s0;

    temp_s0 = reg_a5;
    func_001B8440();
    reg_a5 = temp_s0;
}
