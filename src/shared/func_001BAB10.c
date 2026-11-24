#include "common.h"

extern u8 *reg_a6;
extern u8 *reg_a4;

void func_001BAB10(void) {
    *(s16 *)(reg_a6 + 0x1A) = 0x1E20;
    *(s16 *)(reg_a4 + 0x2) = 0x101;
    reg_a4[0x5] = 0;
    *(s16 *)(reg_a4 + 0x6) = 0x101;
}
