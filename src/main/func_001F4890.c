#include "common.h"

extern u8 *work_reg_a4;
extern u8 *D_0028E450;
u8 func_001F48C0(u8 value);

u8 func_001F4890(void) {
    u8 zero_byte;

    work_reg_0.w = 0;
    zero_byte = work_reg_0.b[0];
    work_reg_a4[1] = work_reg_0.b[0];
    zero_byte = work_reg_0.b[0];
    work_reg_a4[0] = work_reg_0.b[0];
    D_0028E450[0x1B] = 4;
    return func_001F48C0(zero_byte);
}
