#include "common.h"

s32 func_0019C670();
extern u8 D_00264AC0[];
extern u16 D_0028E3EC;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001F1420(void) {
    u16 temp_a1;

    if (D_0028E3EC != 0) {
        reg_a0 = (u8 *)D_00264AC0;
        reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0x138)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFF800000;
        reg_d4.w = 0;
        reg_d1.w += 0xF000F800;
        reg_d3.h[0] = 0x1040;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xEF)));
        func_0019C670();
    }
}
