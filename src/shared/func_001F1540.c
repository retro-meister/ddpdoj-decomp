#include "common.h"

s32 func_00124B20();
s32 func_0013B2E0();
s32 func_001F5640();
extern u8 D_00264EA0[];
extern u16 D_0028E2E8;
extern s16 D_0028E5B0_as_s16;
extern u8 *D_0028E620;
extern s32 D_0028E624;
extern u8 D_0028E854;
extern u8 D_0028E855;
extern s16 D_0028E908_as_s16;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001F1540(void) {
    u16 temp_v1;
    u16 var_a1;

    temp_v1 = (*(u16 *)((u8 *)(reg_a4) + (4)));
    if (temp_v1 != 0) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) = (u16) (temp_v1 - 1);
        if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            reg_tmp.w = 0x69000;
            D_0028E855 |= 1;
            D_0028E855 |= 4;
            D_0028E854 |= 1;
            (*(u16 *)((u8 *)(reg_a5) + (0x16))) = (u16) reg_tmp.h[1];
            var_a1 = reg_tmp.h[0];
            (*(u16 *)((u8 *)(reg_a5) + (0x18))) = var_a1;
            D_0028E624 = 0x780;
            reg_a0 = reg_a5 + 0x16;
            D_0028E620 = (u8 *)(reg_a0);
        }
    }
    (*(u16 *)((u8 *)(reg_a4) + (2))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
        D_0028E5B0_as_s16 = 1;
        if (D_0028E2E8 == 0) {
            D_0028E855 |= 2;
            D_0028E855 |= 0x10;
        } else {
            D_0028E908_as_s16 = 1;
        }
        func_001F5640();
        reg_a0 = (u8 *)D_00264EA0;
        func_0013B2E0();
        reg_d0.w = 6;
        func_00124B20();
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
    }
}
