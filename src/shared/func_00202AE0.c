#include "common.h"

s32 func_00202B30();                            /* extern */
s32 func_00202C40();                            /* extern */
extern s16 *reg_a0_as_s16_p;

void func_00202AE0(void) {
    reg_d0.h[0] = 0x7FFF;
    if (*reg_a0_as_s16_p >= 0) {
        func_00202C40();
        return;
    }
    func_00202B30();
}
