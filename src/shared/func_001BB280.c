#include "common.h"

s32 func_001BB300();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BB280(void) {
    *(s16 *)(reg_a4 + 0) = 0;
    *(u8 *)(reg_a6 + 0x1B) = 4U;
    *(u8 *)(reg_a4 + 3) = *(u8 *)(reg_a6 + 0x1B);
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3E);
    reg_d0.b[0] += *(u8 *)(reg_a6 + 0x7E);
    if (reg_d0.b[0] != 2) {
        func_001BB300();
        return;
    }
    *(u8 *)(reg_a6 + 0x1B) = 8U;
}
