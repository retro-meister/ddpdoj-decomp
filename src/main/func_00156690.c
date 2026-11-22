#include "common.h"

extern s32 reg_d6;
extern u16 D_0028E910;

void func_00156690(void) {
    reg_d6 = 0;
    if (D_0028E910 != 0) {
        reg_d6 = 0x20000;
    }
}
