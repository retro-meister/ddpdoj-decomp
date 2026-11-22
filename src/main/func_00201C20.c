#include "common.h"

s32 func_00201CC0();                            /* extern */
extern u16 D_0028E8A0;

void func_00201C20(void) {
    if (D_0028E8A0 == 0) {
        func_00201CC0();
        return;
    }
    reg_d2.w = 0;
    reg_d3.w = 0;
}
