#include "common.h"

extern u8 *reg_a6;
extern u16 reg_d2;

void func_00170DE0(void) {
    reg_d2 = *(u16 *)(reg_a6 + 0x1E);
}
