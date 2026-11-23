#include "common.h"

void func_002026F0();
void func_00159B20();
extern u8 *reg_a6;

void func_00159AC0(void) {
    *(u16 *)(reg_a6 + 0x26) = 2;
    *(u16 *)(reg_a6 + 0x28) = 0xE;
    *(u16 *)(reg_a6 + 0x2C) = 4;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    func_002026F0();
    *(u8 *)(reg_a6 + 0x2F) = reg_d1.b[0];
    func_00159B20();
}
