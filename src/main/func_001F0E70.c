#include "common.h"


s32 func_0019C670();
s32 func_00201E20();
extern u8 D_00264990[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001F0E70(void) {
    u32 temp_a1;

    reg_d1.w = 0;
    reg_d0.h[0] = 0x10;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x130)));
    func_00201E20();
    (*(u8 *)((u8 *)(reg_a6) + (0x130))) += 2;
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    temp_a1 = reg_d1.w;
    reg_d1.w = temp_a1 + 0xEE00EC00;
    reg_a0 = D_00264990;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x126)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d3.h[0] = 0x12A0;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xE7)));
    func_0019C670();
}
