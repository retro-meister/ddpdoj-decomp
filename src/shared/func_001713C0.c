#include "common.h"

s32 func_00124520();                            /* extern */

void func_001713C0(void) {
    reg_d0.h[0] = 0x78;
    func_00124520();
    reg_d0.w = 4;
}
