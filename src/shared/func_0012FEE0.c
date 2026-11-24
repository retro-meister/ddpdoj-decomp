#include "common.h"

s32 func_0012FF50(u8);                          /* extern */
s32 func_0012FFC0(u8);                          /* extern */
extern u8 D_0028E1D4;
extern u8 D_0028E1D8[];
extern u8 D_0028E1E4[];
extern u8 D_0028E390;

void func_0012FEE0(void) {
    reg_d0.b[0] = D_0028E1E4[0];
    if (D_0028E390 == 1) {
        reg_d0.b[0] = D_0028E1D8[0];
    }
    reg_d1.b[0] = D_0028E1D4;
    if (reg_d0.h[0] == reg_d1.h[0]) {
        func_0012FF50(D_0028E1E4[0]);
        return;
    }
    D_0028E1D4 = reg_d0.b[0];
    func_0012FFC0(D_0028E1E4[0]);
}
