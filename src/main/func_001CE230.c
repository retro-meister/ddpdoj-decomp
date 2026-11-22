#include "common.h"

extern u8 *work_reg_a4;
extern u8 *D_0028E450;
void func_001CE260(s32 value);

void func_001CE230(void) {
    *(u16 *)(work_reg_a4 + 2) = 0x6001;
    work_reg_0.h[0] = 0x84;
    *(u16 *)(D_0028E450 + 0x2A) = work_reg_0.h[0];
    *(u16 *)(D_0028E450 + 0x4A) = work_reg_0.h[0];
    func_001CE260(0x6001);
}
