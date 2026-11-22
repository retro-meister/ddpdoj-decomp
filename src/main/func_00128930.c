#include "common.h"

s32 func_00128B00();                            /* extern */
s32 func_00128B10();                            /* extern */
extern u16 D_0028E910;

void func_00128930(void) {
    if (D_0028E910 == 0) {
        func_00128B10();
        return;
    }
    func_00128B00();
}
