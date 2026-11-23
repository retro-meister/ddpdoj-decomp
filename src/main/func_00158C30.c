#include "common.h"

void func_002026F0();
void func_00158CF0();
extern s8 D_0028E408;
extern u8 *reg_a6;

void func_00158C30(void) {
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d0.h[0] += 0x7FFF + 0x7D01;
    func_002026F0();
    if (D_0028E408 == 0) {
        reg_d1.b[0] -= 0x40;
        *(u8 *)(reg_a6 + 0x30) = reg_d1.b[0];
        reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_d0.h[0] += 0x7FFF + 0x7501;
        func_002026F0();
        reg_d1.b[0] += 0x38;
        *(u8 *)(reg_a6 + 0x31) = reg_d1.b[0];
        *(u16 *)(reg_a6 + 0x28) = 4;
        *(u16 *)(reg_a6 + 0x2C) = 8;
        func_00158CF0();
    }
}
