#include "common.h"

s32 func_00127400();
s32 func_00201270();
void func_001273D0(void) {
    func_00201270();
    reg_d0.h[0] >>= 1;
    func_00127400();
}
