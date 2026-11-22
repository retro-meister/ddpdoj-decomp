#include "common.h"

extern u8 *work_reg_a4;

void func_001B44A0(void) {
    *(u16 *)(work_reg_a4 + 2) = 0;
    *(u16 *)(work_reg_a4 + 4) = 0x20;
    work_reg_a4[7] = 0;
}
