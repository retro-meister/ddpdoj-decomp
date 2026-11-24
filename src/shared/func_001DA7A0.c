#include "common.h"

extern u8 *reg_a4;

void func_001DA7A0(s16 arg0) {
    *(s16 *)(reg_a4 + 4) = arg0;
    reg_a4[5] += 0x40;
    *(s16 *)(reg_a4 + 6) = 0x202;
}
