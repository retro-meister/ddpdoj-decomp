#include "common.h"

extern u16 D_00295E2E[];
extern u16 D_00295E30[];
extern u16 D_00295E32[];

void func_00123000(void) {
    if (D_00295E2E[0] == 0) {
        D_00295E2E[0] = 1;
        D_00295E30[0] = reg_d0.h[0];
        D_00295E32[0] = reg_d1.h[0];
    }
}
