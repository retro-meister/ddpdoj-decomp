#include "common.h"

s32 func_0014E370();
s32 func_00202180();
extern u8 D_0026C5D0[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C4EF0(void) {
    reg_a0 = D_0026C5D0;
    func_0014E370();
    *(u16 *)(reg_a6 + 2) = *(u16 *)(reg_a5 + 0x16);
    *(u16 *)(reg_a6 + 4) = *(u16 *)(reg_a5 + 0x18);
    *(u16 *)(reg_a6 + 0x1A) = *(u16 *)(reg_a5 + 0x1A);
    func_00202180();
    *(u8 *)(reg_a6 + 0x1A) = reg_d1.b[0];
    *(s8 *)(reg_a5 + 0x17) = 0;
    *(s16 *)(reg_a5 + 0x1E) = 2;
    *(s16 *)(reg_a5 + 0x20) = 0;
}
