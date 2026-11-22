#include "common.h"

extern Reg32 work_reg_1;
extern s32 bcd_result;
extern s16 D_0028E498;
extern s16 D_0028E49C;
void func_0019C430(void);

void func_0015C280(void) {
    work_reg_1.w = 0x1A000800;
    bcd_result = 0x155A;
    D_0028E49C = 0x20A0;
    D_0028E498 = 1;
    func_0019C430();
}
