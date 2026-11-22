#include "common.h"

extern u8 *work_reg_a4;

void func_001B45E0(void) {
    *(u16 *)(work_reg_a4 + 2) = 0x101;
}
