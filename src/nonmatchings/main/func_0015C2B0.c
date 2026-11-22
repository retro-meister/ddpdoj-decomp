#include "common.h"

extern s16 D_0028E498;
extern s16 D_0028E49C;
extern s32 bcd_result;
extern void func_0019C430(void);

void func_0015C2B0(void) {
    bcd_result = 0x1559;
    D_0028E498 = 0;
    work_reg_1.w = 0x4A001C00;
    D_0028E49C = 0x260;
    func_0019C430();
}
