#include "common.h"

s32 func_00128B00();                            /* extern */
s32 func_00128B10();                            /* extern */
extern u16 D_0028E910;

void func_00128970(void) {
    if (D_0028E910 == 0) {
        func_00128B10();
        return;
    }
    reg_d0.w += 0x40000;
    func_00128B00();
    reg_d0.w += 0xFFFC0000;
}
