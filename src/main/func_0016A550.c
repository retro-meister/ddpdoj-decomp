#include "common.h"

s32 func_00130200();
s32 func_0016A2D0();
s32 func_0016A630();
s32 func_0016A690();

void func_0016A550(void) {
    func_00130200();
    if (reg_d0.h[0] == 1) {
        func_0016A690();
        return;
    }
    if ((s16)(reg_d0.h[0]) >= 2) {
        func_0016A2D0();
        return;
    }
    func_0016A630();
}
