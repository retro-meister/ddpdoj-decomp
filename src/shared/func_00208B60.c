#include "common.h"

s32 func_00209410();                            /* extern */
s32 func_002095E0();                            /* extern */
extern s8 D_0028DFA4;
extern s8 D_0028DFB0;
extern s8 D_0028E408;

void func_00208B60(void) {
    D_0028DFB0 = 0x3C;
    D_0028DFA4 = 0;
    func_002095E0();
    if (D_0028E408 != 0) {
        func_00209410();
    }
}
