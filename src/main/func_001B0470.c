#include "common.h"

s32 func_0019C570();                            /* extern */
s32 func_0019CA40();                            /* extern */
extern u16 D_0028E3F0;

void func_001B0470(void) {
    if (D_0028E3F0 & 2) {
        func_0019C570();
        return;
    }
    func_0019CA40();
}
