#include "common.h"

s32 func_00128930();                            /* extern */
extern u16 D_0028E910;

void func_001BF210(void) {
    if (D_0028E910 != 0) {
        func_00128930();
        reg_d1.b[0] -= 1;
        func_00128930();
        reg_d1.b[0] += 2;
    }
    func_00128930();
}
