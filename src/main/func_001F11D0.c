#include "common.h"

s32 func_0019C670();
extern u16 D_002649C0[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001F11D0(void) {
    u16 temp_a3;
    u32 temp_a0;

    reg_a0 = (u8 *)(D_002649C0);
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x12C)));
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a3;
    reg_d1.w += 0x0C000000;
    temp_a0 = reg_d1.w + 0xF200E000;
    reg_d1.w = temp_a0;
    reg_d3.h[0] = 0xF00;
    reg_d4.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    func_0019C670();
}
