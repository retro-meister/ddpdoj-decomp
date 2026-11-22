#include "common.h"

extern u16 *D_0028E450;
extern u16 *D_0028E454;
extern u16 D_0028E8A8;

void func_0014CEE0(void) {
    D_0028E454[4] = 1;
    work_reg_0.h[0] = D_0028E8A8;
    work_reg_0.h[0] += 4;
    D_0028E450[12] = (u16) work_reg_0.h[0];
}
