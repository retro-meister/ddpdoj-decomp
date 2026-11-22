#include "common.h"

s32 func_00130200();
s32 func_0016A2E0();
s32 func_0016A630();
s32 func_0016A690();

void func_0016A5C0(void) {
    func_00130200();
    reg_d0.h[0] = reg_d1.h[0];
    if (reg_d0.h[0] == 1) {
        func_0016A690();
        return;
    }
    if ((s16)(reg_d0.h[0]) >= 2) {
        func_0016A2E0();
        return;
    }
    func_0016A630();
}
