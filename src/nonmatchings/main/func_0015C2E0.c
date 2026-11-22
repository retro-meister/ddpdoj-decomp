#include "common.h"

extern s32 bcd_result;
extern void func_0019C430(void);

extern s16 D_0028E498;
extern s16 D_0028E49C;

void func_0015C2E0(void) {
    bcd_result = 0x1558;
    D_0028E498 = 0;
    work_reg_1.w = 0x64003000;
    D_0028E49C = 0x410;
    func_0019C430();
}
