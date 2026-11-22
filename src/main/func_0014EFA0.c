#include "common.h"

extern u16 *D_0028E450;
extern s32 D_0028E468;
extern u16 D_0029C068[];
void func_0014EFA0(void) {
    work_reg_0.h[0] = D_0029C068[0];
    D_0028E450[2] -= work_reg_0.h[0];
    D_0028E468 += 1;
}
