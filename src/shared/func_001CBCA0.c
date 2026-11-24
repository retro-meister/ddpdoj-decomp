#include "common.h"

extern u32 reg_a6_as_u32;
extern u32 reg_a0_as_u32;

void func_001CBCA0(void) {
    reg_a0_as_u32 = reg_a6_as_u32;
    reg_a0_as_u32 += reg_d0.h[0];
    *(u16 *)reg_a0_as_u32 = 0x8000;
}
