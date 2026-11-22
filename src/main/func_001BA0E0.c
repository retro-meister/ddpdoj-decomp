#include "common.h"

s32 func_00124B20();                            /* extern */
extern s16 *reg_a4;

void func_001BA0E0(void) {
    reg_d0.w = 6;
    func_00124B20();
    *reg_a4 = 0;
}
