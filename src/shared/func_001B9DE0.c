#include "common.h"

s32 func_00124B20();                            /* extern */
extern s16 *reg_a4;

void func_001B9DE0(void) {
    reg_d0.w = 1;
    func_00124B20();
    *reg_a4 = 0;
}
