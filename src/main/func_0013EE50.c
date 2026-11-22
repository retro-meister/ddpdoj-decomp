#include "common.h"

extern Reg32 work_reg_1;
extern s32 D_0028E498;

void func_0013EE50(void) {
    work_reg_1.h[0] = 0x100;
    D_0028E498 = 0x2CC000A;
    func_0013EEA0();
}
