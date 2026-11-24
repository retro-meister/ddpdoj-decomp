#include "common.h"
extern u8 *reg_a6;
void func_001CBBF0(void) {
    reg_d0.h[0] = 0xA000;
    *(u16 *)(reg_a6 + 0x100) |= reg_d0.h[0];
}
