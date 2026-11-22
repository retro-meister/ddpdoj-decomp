#include "common.h"

extern s32 reg_d7;

void func_0020ED20(void) {
    reg_d0.w = 0;
    if (reg_d7 == 0) {
        reg_d0.w = 1;
    }
}
