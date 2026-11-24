#include "common.h"

s32 func_00171400();
s32 func_002027A0();
extern s16 *D_0028E44C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E0C20(void) {
    s16 *temp_a0;
    s16 *var_a1;

    reg_a0 = (u8 *)(D_0029F260);
    reg_a1 = (u8 *)(D_0029F1F0);
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
        D_0028E44C = (s16 *)(reg_a0);
        reg_a0 = (u8 *)(reg_a1);
        reg_a1 = (u8 *)(D_0028E44C);
    }
    temp_a0 = (s16 *)(reg_a0);
    if ((*(s16 *)((u8 *)(temp_a0) + (0))) >= 0) {
        var_a1 = (s16 *)(reg_a1);
        if (*var_a1 >= 0) goto block_st;
        reg_a0 = (u8 *)(var_a1);
        D_0028E44C = (s16 *)(temp_a0);
        reg_a1 = (u8 *)(temp_a0);
    }
    func_00171400();
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] += 0x7FFF + 0x6101;
    reg_d1.h[0] += 0x1780;
    func_002027A0();
    (*(u8 *)((u8 *)(reg_a6) + (0x5A))) = (u8) reg_d1.b[0];
    return;
block_st:
    (*(s8 *)((u8 *)(reg_a5) + (0x2D))) = 4;
}
