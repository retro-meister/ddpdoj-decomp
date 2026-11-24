#include "common.h"

s32 func_00125310();
s32 func_00171400();
s32 func_001EC790();
s32 func_002027A0();
extern s16 *D_0028E44C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001EC920(void) {
    s16 *temp_v1;
    s16 *var_a0;
    u16 temp_v0_2;
    u8 temp_v0;

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
            var_a0 = (s16 *)(reg_a1);
            if (0 > *var_a0) {
                reg_a0 = (u8 *)(var_a0);
                D_0028E44C = (s16 *)(temp_v1);
                reg_a1 = (u8 *)(temp_v1);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d6.h[0] = reg_d2.h[0];
            reg_d7.h[0] = reg_d3.h[0];
            reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
            func_002027A0();
            reg_d5.h[0] = reg_d1.h[0];
            if ((*(u8 *)((u8 *)(reg_a4) + (5))) & 1) {
                reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0xF)));
                reg_d1.h[0] -= 0x23;
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
                func_001EC790();
            } else {
                reg_d1.h[0] = reg_d5.h[0];
                reg_d1.b[0] -= (*(u8 *)((u8 *)(reg_a4) + (0xF)));
                reg_d1.h[0] -= 0x23;
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                func_001EC790();
            }
            var_a0 = (s16 *)(reg_a4);
            reg_d1.b[0] = (*(u8 *)((u8 *)(var_a0) + (0xE)));
            if (0 <= (s8)(reg_d1.b[0])) {
                (*(u8 *)((u8 *)(var_a0) + (0xF))) += reg_d1.b[0];
                if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0xF))) > 0x10) {
                    goto block_13;
                }
                goto block_end;
            } else {
                (*(u8 *)((u8 *)(var_a0) + (0xF))) += reg_d1.b[0];
                if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0xF))) < -0x10) {
block_13:
                    var_a0 = (s16 *)(reg_a4);
                    (*(u8 *)((u8 *)(var_a0) + (0xE))) *= -1;
                }
            }
        }
block_end:
        func_00171400();
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x1F7)));
            if ((s32) temp_v0 < 0x1E) {
                (*(u8 *)((u8 *)(reg_a6) + (0x1F7))) = (u8) (temp_v0 + 0x14);
            }
            temp_v0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x1F8)));
            if ((s32) temp_v0_2 < 2) {
                (*(u16 *)((u8 *)(reg_a6) + (0x1F8))) = (u16) (temp_v0_2 + 1);
            }
            reg_d0.w = 9;
            func_00125310();
        }
    }
}
