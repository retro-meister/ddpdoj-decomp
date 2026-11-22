#include "common.h"

extern s32 D_0028E77C;
extern s32 D_0028E780;
extern void *work_reg_a4;

void func_001A34C0(void) {
    work_reg_a4 = &D_0028E780;
    if (work_reg_0.b[0] != 0) {
        work_reg_a4 = &D_0028E77C;
    }
}
