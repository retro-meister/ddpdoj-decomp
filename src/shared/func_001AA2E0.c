#include "common.h"

s32 func_001AA330(u16);                         /* extern */
extern u16 D_0028E648;

void func_001AA2E0(void) {
    D_0028E648 += reg_d0.h[0];
    if (!(reg_d1.w & 0x40)) {
        func_001AA330(reg_d0.h[0]);
        return;
    }
    D_0028E648 += reg_d0.h[0];
    func_001AA330(reg_d0.h[0]);
}
