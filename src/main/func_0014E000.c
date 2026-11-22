#include "common.h"
extern s32 reg_d2;
extern u32 D_0028DF3C;
extern u32 D_0028DF40;
extern u32 D_0028DF44;
void func_0014E070(void);
void func_0014E000(void) {
    D_0028DF44 = reg_d0.w;
    D_0028DF40 = reg_d1.w;
    D_0028DF3C = reg_d2;
    reg_d1.h[0] = 0x80;
    func_0014E070();
}
