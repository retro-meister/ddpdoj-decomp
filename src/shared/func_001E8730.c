#include "common.h"

extern u8 *reg_a6;
extern u8 *reg_a0;
void func_001E8730(void) {
    reg_a0 = reg_a6;
    reg_a0 += reg_d0.h[0];
    *(u16 *)reg_a0 = 0xA001;
}
