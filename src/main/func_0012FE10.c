#include "common.h"

extern u8 D_0028E1E0;
extern u8 D_0028E1E4[];
void func_0012FE80(void);
void func_0012FEE0(void);
void func_0012FFC0(void);

void func_0012FE10(void) {
    if (reg_d0.h[0] != 0) {
        func_0012FEE0();
        return;
    }
    reg_d0.b[0] = D_0028E1E4[0];
    reg_d1.b[0] = D_0028E1E0;
    if (reg_d0.h[0] == reg_d1.h[0]) {
        func_0012FE80();
        return;
    }
    D_0028E1E0 = reg_d0.b[0];
    func_0012FFC0();
}
