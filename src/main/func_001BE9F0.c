#include "common.h"

extern u8 *D_0028E450;
extern u8 *work_reg_a4;

void func_001BEA20(s32 value);

void func_001BE9F0(void) {
    D_0028E450[0x1B] = 0;
    D_0028E450[0x1A] = 0x20;
    work_reg_a4[0x3] = 0x20;
    *(u16 *)(work_reg_a4 + 0x4) = 0x303;
    func_001BEA20(0x20);
}
