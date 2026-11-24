#include "common.h"


s32 func_00129280();
extern u8 D_002641C0[];
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E9220(void) {
    u16 temp_a0;
    u16 temp_a2;
    u16 temp_a2_2;
    u32 temp_a1;

    reg_a2 = D_002641C0;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.w = 0;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d1.b[0] += reg_d2.b[0];
    reg_a2 += reg_d3.h[0];
    reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
    temp_a2 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[1] = temp_a2;
    temp_a1 = reg_d3.w;
    temp_a2_2 = *(u16 *)reg_a3;
    reg_tmp.h[0] = temp_a2_2;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d3.w = temp_a1 + reg_tmp.w;
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[1] = temp_a0;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0xC;
    func_00129280();
    reg_d1.h[0] -= 0x18;
    func_00129280();
}
