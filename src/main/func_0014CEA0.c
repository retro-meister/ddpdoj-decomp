#include "common.h"

extern u16 *reg_a1;
extern u16 *reg_a2;
extern s32 reg_a5;

void func_0014CEA0(void) {
    reg_a2 = (u16 *)(reg_a5 + 0x22);
    if (reg_d6.h[0] != 0) {
        reg_a2 = (u16 *)(reg_a5 + 0x1C);
    }
    *reg_a2 = *reg_a1;
    reg_a1 += 1;
}
