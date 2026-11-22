#include "common.h"

extern u8 *D_0028E450;
extern u8 *work_reg_a4;

void func_001BAB10(void) {
    *(s16 *)(D_0028E450 + 0x1A) = 0x1E20;
    *(s16 *)(work_reg_a4 + 0x2) = 0x101;
    work_reg_a4[0x5] = 0;
    *(s16 *)(work_reg_a4 + 0x6) = 0x101;
}
