#include "common.h"

extern u32 reg_d2;
extern u32 D_0028DF3C;
extern u32 D_0028DF40;
extern u32 D_0028DF44;
void func_0014E070(u32);

void func_0014E050(void) {
    D_0028DF44 = reg_d0.w;
    D_0028DF40 = reg_d1.w;
    D_0028DF3C = reg_d2;
    func_0014E070(reg_d0.w);
}
