#include "common.h"

s32 func_0019C670();
extern u8 D_0026C370[];
extern Reg32 D_0028E484;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_001C41D0(void) {
    u16 temp_a1;
    u16 temp_a3;
    u32 temp_a2;

    reg_a2 = D_0026C370;
    temp_a3 = (*(u16 *)((u8 *)(reg_a6) + (0xE6)));
    reg_a2 += temp_a3;
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE6)));
    reg_d2.w = *(u32 *)(D_0026C370 + (reg_tmp.h[0] & ~3));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE2)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x168)));
    temp_a2 = reg_d1.w;
    D_0028E484.w = temp_a2;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0xE4)));
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF600FC00;
    reg_d3.h[0] = 0xA20;
    reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x12F)));
    func_0019C670();
}
