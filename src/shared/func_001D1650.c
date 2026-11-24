#include "common.h"

s32 func_0019C670();
extern u8 D_0026D3A0[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001D1650(void) {
    u16 temp_a0;
    u16 temp_a2;

    reg_a0 = D_0026D3A0;
    temp_a2 = *(u16 *)(reg_a6 + 0xBE);
    reg_a0 += temp_a2;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xBE);
    reg_d2.w = *(u32 *)(D_0026D3A0 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *)(reg_a6 + 0x42);
    temp_a0 = *(u16 *)(reg_a6 + 0x44);
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xE400F700;
    reg_d3.h[0] = 0x1C48;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a6 + 0x66);
    func_0019C670();
}
