#include "common.h"

extern u16 D_0028E910;

void func_00156690(void) {
    reg_d6.sw = 0;
    if (D_0028E910 != 0) {
        reg_d6.sw = 0x20000;
    }
}
