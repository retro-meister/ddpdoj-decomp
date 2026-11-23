#include "common.h"

s32 func_0019C670();
extern u8 D_0026C470[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001C4460(void) {
    u16 temp_a0;

    reg_d2.w = 0;
    reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xBA)));
    reg_a0 = D_0026C470;
    reg_d2.b[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(D_0026C470 + (reg_d2.h[0] & ~3));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF600FA00;
    reg_d3.h[0] = 0xA30;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x12D)));
    func_0019C670();
}
