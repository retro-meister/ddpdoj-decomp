#include "common.h"

extern u8 *work_reg_a4;
extern u8 *D_0028E450;
void func_001F4630(u8 value);

void func_001F4600(void) {
    u8 value;

    work_reg_0.w = 0;
    work_reg_a4[1] = work_reg_0.b[0];
    value = work_reg_0.b[0];
    work_reg_a4[0] = value;
    D_0028E450[0x1B] = 2;
    func_001F4630(value);
}
