#include "common.h"

s32 func_0012FFC0(u8);                          /* extern */
s32 func_0012FFD0(u8);                          /* extern */
extern u8 D_0028E1D0;
extern u8 D_0028E1DA[];
extern u8 D_0028E1E6[];
extern u8 D_0028E390;

void func_0012FF50(void) {
    reg_d0.b[0] = D_0028E1E6[0];
    if (D_0028E390 == 1) {
        reg_d0.b[0] = D_0028E1DA[0];
    }
    reg_d1.b[0] = D_0028E1D0;
    if (reg_d0.h[0] == reg_d1.h[0]) {
        func_0012FFD0(D_0028E1E6[0]);
        return;
    }
    D_0028E1D0 = reg_d0.b[0];
    func_0012FFC0(D_0028E1E6[0]);
}
