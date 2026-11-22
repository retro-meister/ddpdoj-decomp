#include "common.h"

extern s16 D_0028E498;
extern s16 D_0028E49C;
extern s32 bcd_result;

void func_0019C430(void);

void func_0015C310(void) {
    bcd_result = 0x155B;
    D_0028E498 = 0;
    work_reg_1.w = 0x04000400;
    D_0028E49C = 0x620;
    func_0019C430();
}
