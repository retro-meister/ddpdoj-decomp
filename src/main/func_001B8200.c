#include "common.h"

s32 func_0019C790();
extern u8 D_0026E5C0[];
extern u16 D_0028E4A2;
extern u16 D_0028E4A6;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_001B8200(void) {
    u32 temp_a0;

    reg_a2 = D_0026E5C0;
    reg_a2 += (*(u16 *)((u8 *)(reg_a6) + (0x11A)));
    D_0028E4A2 = (*(u16 *)((u8 *)(reg_a2) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
    D_0028E4A6 = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.w += 0xF8000080;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x11A))) < 0xB1) {
        reg_d1.w += 0xFE000100;
    }
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a2) + (4)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a2) + (6)));
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a2) + (8)));
    reg_d4.h[0] = 0x13;
    func_0019C790();
}
