#include "common.h"

s32 func_0019C670();
s32 func_00201E20();
extern u8 D_00264870[];
extern u16 D_0028E4A2;
extern u16 D_0028E4A6;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001F0330(void) {
    u32 temp_a1;
    u32 temp_a2;

    reg_d1.w = 0;
    reg_d0.h[0] = 0x1A;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x13C)));
    func_00201E20();
    (*(u8 *)((u8 *)(reg_a6) + (0x13C))) += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0x10))) = 0x1400U;
    (*(u16 *)((u8 *)(reg_a6) + (0x10))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) = 0x2200U;
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) -= reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x1B0))) = 0xDE00U;
    (*(u16 *)((u8 *)(reg_a6) + (0x1B0))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x1B2))) = 0x2600U;
    (*(u16 *)((u8 *)(reg_a6) + (0x1B2))) -= reg_d2.h[0];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    D_0028E4A6 = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    temp_a2 = reg_d1.w;
    reg_a0 = D_00264870;
    reg_d1.w = temp_a2 + 0xE6000000;
    temp_a1 = reg_d1.w;
    reg_d1.w = temp_a1 + 0xEA00F200;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x128)));
    D_0028E4A2 = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d3.h[0] = 0x1670;
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xE9)));
    func_0019C670(reg_a0, temp_a1, temp_a2, reg_tmp.h[0]);
}
