#include "common.h"

extern s32 reg_d2;
extern u32 D_0028DF3C;
extern u32 D_0028DF40;
extern u32 D_0028DF44;
void func_0014E070(u32 value);

void func_0014E030(void) {
    D_0028DF40 = reg_d1.w;
    D_0028DF44 = reg_d0.w;
    D_0028DF3C = reg_d2;
    *(u16 *)&reg_d1 = 0;
    func_0014E070(reg_d0.w);
}
