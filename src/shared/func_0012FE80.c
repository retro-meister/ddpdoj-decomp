#include "common.h"

s32 func_0012FFC0();                            /* extern */
s32 func_0012FFD0();                            /* extern */
extern u8 D_0028E1DC;
extern u8 D_0028E1E6[];

void func_0012FE80(void) {
    reg_d0.b[0] = D_0028E1E6[0];
    reg_d1.b[0] = D_0028E1DC;
    if (reg_d0.h[0] == reg_d1.h[0]) {
        func_0012FFD0();
        return;
    }
    D_0028E1DC = reg_d0.b[0];
    func_0012FFC0();
}
