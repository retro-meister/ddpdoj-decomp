#include "common.h"

s32 func_00131610();                            /* extern */
s32 func_001B0160();                            /* extern */
extern s8 D_0028E408;

void func_001B00D0(void) {
    func_00131610();
    if (D_0028E408 == 0) {
        func_001B0160();
    }
}
