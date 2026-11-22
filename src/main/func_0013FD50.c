#include "common.h"

extern u16 D_0028E5B4;
extern u16 D_0028E5C4;
extern u16 D_0028E5CC;
extern u16 D_0028E5D8;
extern u16 D_0028E5E0;
extern u16 D_0028E5E8;
extern u16 D_0028E5F8;
extern s32 D_002BAEB0[];

void func_0013FD50(void) {
    work_reg_0.w = 0;
    D_002BAEB0[0] = 0;
    D_0028E5F8 = work_reg_0.h[0];
    D_0028E5E8 = work_reg_0.h[0];
    D_0028E5E0 = work_reg_0.h[0];
    D_0028E5D8 = work_reg_0.h[0];
    D_0028E5CC = work_reg_0.h[0];
    D_0028E5C4 = work_reg_0.h[0];
    D_0028E5B4 = work_reg_0.h[0];
}
