#include "common.h"

s32 func_001B5D20();
extern u16 D_0028E4A2;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B5E70() {
    u32 temp_a1;
    u8 temp_v1;
    u8 *var_a0;

    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
        var_a0 = reg_a4;
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        temp_a1 = reg_d2.w;
        reg_d3.w = 0;
        reg_d4.w = 0;
        reg_d2.w = temp_a1 + 0xF6C00140;
        reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (3)));
        (*(u8 *)((u8 *)(var_a0) + (3))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xF)));
            (*(u8 *)((u8 *)(reg_a4) + (0xF))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (0xF))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xE)));
                var_a0 = reg_a4 + 2;
                temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (2)));
                if (temp_v1 != 3) {
                    (*(u8 *)((u8 *)(reg_a4) + (2))) = (u8) (temp_v1 - 1);
                }
            }
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x11)));
            (*(u8 *)((u8 *)(reg_a4) + (0x11))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (0x11))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x10)));
            }
            func_001B5D20();
            (*(u8 *)((u8 *)(reg_a4) + (0xB))) += 0xB;
        }
    }
}
