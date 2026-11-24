#include "common.h"

s32 func_00128760();                            /* extern */
s32 func_00128B10();                            /* extern */
extern u16 D_0028E910;

void func_00128AC0(void) {
    if (D_0028E910 != 0) {
        func_00128760();
        return;
    }
    func_00128B10();
}
