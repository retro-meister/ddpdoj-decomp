#include "common.h"

extern s32 *D_0028E464;
extern s32 D_0028E468;
extern s32 D_0028E6E8;
extern s16 bcd_result;

extern void func_001AE9A0(s32 *, s32);

void func_001A97F0(void) {
    D_0028E468 -= 4;
    D_0028E464 = &D_0028E6E8;
    *D_0028E464 = work_reg_0.w;
    bcd_result = 0;
    func_001AE9A0(D_0028E464, D_0028E468);
}
