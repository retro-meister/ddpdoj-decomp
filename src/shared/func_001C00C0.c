#include "common.h"

s32 func_00128AC0();
extern u16 D_0028E4A2;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C00C0() {
    u8 temp_a1;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        temp_a1 = (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u8 *)((u8 *)(reg_a4) + (3))) = temp_a1;
        reg_d0.w = 7;
        reg_d1.w = 0x20;
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0xE2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE4)));
        reg_d3.w = 0xF7000080;
        func_00128AC0();
        reg_d0.w = 7;
        reg_d1.w = 0x20;
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0xC2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC4)));
        reg_d3.w = 0xF6FFFF80;
        func_00128AC0();
        (*(u16 *)((u8 *)(reg_a4) + (6))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (6))) == 0) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
