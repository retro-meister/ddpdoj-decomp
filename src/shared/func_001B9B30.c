#include "common.h"

void func_00124D90(void);
void func_001B9DE0(void);
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B9B30(void) {
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3E);
    reg_d0.b[0] += *(u8 *)(reg_a6 + 0x7E);
    if (reg_d0.b[0] == 2) {
        func_001B9DE0();
        return;
    }
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 6) = 0x2020;
    *(s16 *)(reg_a4 + 4) = 0x10;
    reg_d0.w = 8;
    func_00124D90();
}
