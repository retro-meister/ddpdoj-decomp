#include "common.h"

s32 func_0019C670();
extern u8 D_002649A8[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001F1150(void) {
    u16 temp_a1;

    reg_a0 = D_002649A8;
    reg_a0 += *(u16 *)(reg_a6 + 0x12A);
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    temp_a1 = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF4000000;
    reg_d1.w += 0xF000DE00;
    reg_d3.h[0] = 0x1110;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0xEB);
    func_0019C670();
}
