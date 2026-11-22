#include "common.h"
extern void func_0019C430(void);
extern s32 bcd_result;
extern s16 D_0028E498;
extern s16 D_0028E49C;
void func_0015C250(void) {
    work_reg_1.w = 0x0E000200;
    bcd_result = 0x155C;
    D_0028E498 = 0;
    D_0028E49C = 0x30C0;
    func_0019C430();
}
