#include "common.h"

s32 func_00124D90();
s32 func_001BA0E0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B9E10(void) {
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3E);
    reg_d0.b[0] += *(u8 *)(reg_a6 + 0x7E);
    if (reg_d0.b[0] == 2) {
        func_001BA0E0();
        return;
    }
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 6) = 0x2020;
    reg_d0.w = 3;
    func_00124D90();
}
