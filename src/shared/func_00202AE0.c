#include "common.h"

s32 func_00202B30();                            /* extern */
s32 func_00202C40();                            /* extern */
extern s16 *reg_a0;

void func_00202AE0(void) {
    reg_d0.h[0] = 0x7FFF;
    if (*reg_a0 >= 0) {
        func_00202C40();
        return;
    }
    func_00202B30();
}
