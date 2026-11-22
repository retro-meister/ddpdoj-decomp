#include "common.h"

extern void *D_0028E450;

void func_00201FE0(void);

void func_00201FC0(void) {
    u8 *base = (u8 *)D_0028E450;

    work_reg_0.w = 0;
    work_reg_0.b[0] = base[0x1B];
    work_reg_1.w = 0;
    work_reg_1.b[0] = base[0x1A];
    func_00201FE0();
}
