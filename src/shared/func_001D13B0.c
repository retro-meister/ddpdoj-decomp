#include "common.h"

s32 func_0019C670();
extern u8 D_0026D320[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001D13B0(void) {
    u16 temp_a1;
    u16 temp_a3;

    reg_a0 = (u8 *)D_0026D320;
    temp_a3 = (*(u16 *)((u8 *)(reg_a6) + (0xA6)));
    reg_a0 += temp_a3;
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA6)));
    reg_d2.w = *(u32 *)(D_0026D320 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xE4400000;
    reg_d1.w += 0xEC00E800;
    reg_d3.h[0] = 0x14C0;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x69)));
    func_0019C670();
}
