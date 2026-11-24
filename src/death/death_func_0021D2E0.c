#include "common.h"

s32 func_00171400();
s32 death_func_0021D0F0();
s32 func_001EBA00();
s32 func_00201160();
s32 func_002027A0();
extern u8 death_D_00269860[];
extern s16 *D_0028E44C;
extern u16 D_0028E89C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void death_func_0021D2E0(void) {
    s16 *temp_v1;

    if (D_0028E89C != 0) {
        func_001EBA00();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (7)));
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
            D_0028E44C = (s16 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(D_0028E44C);
        }
        temp_v1 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_v1) + (0))) {
            if (0 > (s64)*(s16 *)reg_a1) {
                reg_a0 = (u8 *)(reg_a1);
                D_0028E44C = (s16 *)(temp_v1);
                reg_a1 = (u8 *)(temp_v1);
                goto block_8;
            }
        } else {
block_8:
            reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d6.h[0] = reg_d2.h[0];
            reg_d7.h[0] = reg_d3.h[0];
            reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
            func_002027A0();
            func_00201160();
            reg_d0.b[0] -= 0x20;
            reg_d1.b[0] += reg_d0.b[0];
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_a3 = (u8 *)death_D_00269860;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            reg_a3 += reg_d4.h[0];
            reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a3) + (0)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a3) + (2)));
            reg_d4.w = 0;
            death_func_0021D0F0();
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            (*(u16 *)((u8 *)(reg_a4) + (0xE))) -= 4;
            if ((s32) reg_tmp.h[0] < 4) {
                (*(u16 *)((u8 *)(reg_a4) + (0xE))) = 0x14U;
            }
        }
        func_00171400();
    }
}
