#include "common.h"

extern s32 bcd_result;
extern u32 D_0028DF3C;
extern u32 D_0028DF40;
extern u32 D_0028DF44;
void func_0014E070(u32, u32);

void func_0014E000(void) {
    u32 saved_reg0 = work_reg_0.w;
    u32 saved_reg1 = work_reg_1.w;
    s32 saved_bcd = bcd_result;

    D_0028DF44 = saved_reg0;
    D_0028DF40 = saved_reg1;
    D_0028DF3C = saved_bcd;
    *(u16 *)&work_reg_1 = 0x80;

    func_0014E070(saved_reg1, saved_reg0);
}
