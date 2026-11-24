#include "common.h"

s32 func_00125310();
s32 func_00171400();
s32 death_func_0021B180(void);
s32 death_func_0021B420();
s32 func_002027A0();
extern s16 *D_0028E44C;
extern u16 D_0028E89C;
extern u16 D_0029F1F0[];
extern u16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void death_func_0021BC30(u8 *arg0, s16 *arg1) {
    s16 *temp_a0;
    s16 *var_a1;
    u8 temp_a1;
    u8 temp_a2;
    u8 *var_a0;

    var_a0 = (u8 *)(arg0);
    var_a1 = (s16 *)(arg1);
    if (D_0028E89C == 0) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
        (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
        if (reg_tmp.b[0] == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (7)));
            reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
            if ((*(u8 *)((u8 *)(reg_a4) + (4))) == reg_d2.b[0]) {
                reg_a0 = (u8 *)(D_0029F260);
                reg_a1 = (u8 *)(D_0029F1F0);
                if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
                    D_0028E44C = (s16 *)(reg_a0);
                    reg_a0 = (u8 *)(reg_a1);
                    reg_a1 = (u8 *)(D_0028E44C);
                }
                temp_a0 = (s16 *)(reg_a0);
                if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
                    var_a1 = (s16 *)(reg_a1);
                    if (0 > *var_a1) {
                        reg_a0 = (u8 *)(var_a1);
                        D_0028E44C = (s16 *)(temp_a0);
                        reg_a1 = (u8 *)(temp_a0);
                        goto block_8;
                    }
                } else {
block_8:
                    reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
                    reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
                    reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_d0.h[0] += 0x7FFF + 0x7A01;
                    func_002027A0();
                    reg_d1.h[0] = 0x80;
                    (*(u8 *)((u8 *)(reg_a4) + (6))) = (u8) reg_d1.b[0];
                    goto block_9;
                }
            } else {
block_9:
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (6)));
                reg_d6.b[0] = 0xB7;
                reg_d7.h[0] = reg_d1.h[0];
                temp_a1 = (*(u8 *)((u8 *)(reg_a4) + (5)));
                reg_d6.b[0] -= temp_a1;
                reg_d1.b[0] += reg_d6.b[0];
                reg_d6.h[0] = 0x16;
                death_func_0021B420();
                reg_d6.b[0] = 0xB7;
                reg_d1.h[0] = reg_d7.h[0];
                temp_a2 = (*(u8 *)((u8 *)(reg_a4) + (5)));
                reg_d6.b[0] -= temp_a2;
                reg_d6.b[0] *= -1;
                reg_d1.b[0] += reg_d6.b[0];
                reg_d6.h[0] = 0xFFEA;
                death_func_0021B420();
            }
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
            var_a1 = (s16 *)(reg_a4 + 0xD);
            if ((*(u8 *)((u8 *)(reg_a4) + (0xD))) == 0) {
                (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
                (*(u8 *)((u8 *)(reg_a4) + (3))) = 4U;
            }
            var_a0 = (u8 *)(reg_a4);
            reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (5)));
            (*(u8 *)((u8 *)(var_a0) + (5))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                goto block_13;
            }
        }
    } else {
block_13:
        func_00171400();
        if (death_func_0021B180()) {
            reg_d0.w = 0x12;
        } else {
            reg_d0.w = 0x13;
        }
        func_00125310();
    }
}
