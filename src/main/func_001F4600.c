#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;
void func_001F4630(u8 value);

void func_001F4600(void) {
    u8 value;

    reg_d0.w = 0;
    reg_a4[1] = reg_d0.b[0];
    value = reg_d0.b[0];
    reg_a4[0] = value;
    reg_a6[0x1B] = 2;
    func_001F4630(value);
}
