#include "common.h"

s32 func_0019C670();
extern u8 D_0026C2C0[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001C3F50(void) {
    u16 temp_a0;
    u16 temp_a2;

    reg_a0 = D_0026C2C0;
    temp_a2 = *(u16 *)(reg_a6 + 6);
    reg_a0 += temp_a2;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 6);
    reg_d2.w = *(u32 *)(D_0026C2C0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    temp_a0 = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xEE00FA00;
    reg_d3.h[0] = 0x1230;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x126);
    func_0019C670();
}
