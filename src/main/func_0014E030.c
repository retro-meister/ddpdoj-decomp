#include "common.h"

extern s32 bcd_result;
extern u32 D_0028DF3C;
extern u32 D_0028DF40;
extern u32 D_0028DF44;
void func_0014E070(u32 value);

void func_0014E030(void) {
    D_0028DF40 = work_reg_1.w;
    D_0028DF44 = work_reg_0.w;
    D_0028DF3C = bcd_result;
    *(u16 *)&work_reg_1 = 0;
    func_0014E070(work_reg_0.w);
}
