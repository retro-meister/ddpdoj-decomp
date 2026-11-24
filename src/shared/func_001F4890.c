#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;
u8 func_001F48C0(u8 value);

u8 func_001F4890(void) {
    u8 zero_byte;

    reg_d0.w = 0;
    zero_byte = reg_d0.b[0];
    reg_a4[1] = reg_d0.b[0];
    zero_byte = reg_d0.b[0];
    reg_a4[0] = reg_d0.b[0];
    reg_a6[0x1B] = 4;
    return func_001F48C0(zero_byte);
}
