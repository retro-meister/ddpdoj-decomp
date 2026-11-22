#include "common.h"

extern u32 reg_a6;
extern u32 reg_a0;

void func_001CBCA0(void) {
    reg_a0 = reg_a6;
    reg_a0 += reg_d0.h[0];
    *(u16 *)reg_a0 = 0x8000;
}
