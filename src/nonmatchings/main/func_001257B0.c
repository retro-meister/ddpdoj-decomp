#include "common.h"

extern u16 D_0028E8A0;
extern u16 *D_0028E450;
extern u16 D_0028E0E4[];

void func_001257B0(void) {
    if (D_0028E8A0 == 0) {
        work_reg_0.h[0] = D_0028E0E4[0];
        D_0028E450[1] = (u16) (D_0028E450[1] + work_reg_0.h[0]);
    }
}
