#include "common.h"

extern u16 *work_reg_a4;
extern u16 *D_0028E450;
void func_001CE070(s32 value);

void func_001CE040(void) {
    u16 flag = 0x8001;
    work_reg_a4[1] = flag;
    work_reg_0.w = 4;
    D_0028E450[21] = (u16) work_reg_0.h[0];
    D_0028E450[37] = (u16) work_reg_0.h[0];
    func_001CE070(flag);
}
