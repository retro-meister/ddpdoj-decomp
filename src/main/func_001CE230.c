#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;
void func_001CE260(s32 value);

void func_001CE230(void) {
    *(u16 *)(reg_a4 + 2) = 0x6001;
    reg_d0.h[0] = 0x84;
    *(u16 *)(reg_a6 + 0x2A) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x4A) = reg_d0.h[0];
    func_001CE260(0x6001);
}
