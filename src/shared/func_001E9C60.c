#include "common.h"

s32 func_00125310();
s32 func_00129280();
s32 func_00129370();
s32 func_00171400();
s32 func_001E9AA0();
s32 func_002010A0();
s32 func_002027A0();
extern s16 *D_0028E44C;
extern u16 D_0028E89C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E9C60(s16 *arg1) {
    s16 *temp_a0;
    s16 *var_a1;
    u32 temp_v1;
    u32 temp_v1_2;
    u8 temp_v0;

    var_a1 = (s16 *)(arg1);
    if (D_0028E89C != 0) {
        func_001E9AA0();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (7)));
        if ((*(u8 *)((u8 *)(reg_a4) + (5))) & 1) {
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
                    goto block_9;
                }
            } else {
block_9:
                reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
                reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
                reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d0.h[0] += 0x7FFF + 0x70C1;
                func_002027A0();
                func_002010A0();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
                reg_d1.b[0] += reg_d0.b[0];
                reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d3.w = 0xF0C00000;
                reg_d4.w = 0;
                func_00129280();
                func_00171400();
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
                if ((*(u8 *)((u8 *)(reg_a4) + (4))) == reg_d0.b[0]) {
                    reg_d1.b[0] += 0x40;
                    (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) reg_d1.b[0];
                    reg_d1.b[0] += 0x80;
                    reg_d1.b[0] *= -1;
                    (*(u8 *)((u8 *)(reg_a4) + (8))) = (u8) reg_d1.b[0];
                }
                goto block_11;
            }
        } else {
block_11:
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d3.w = 0xF2C0FC00;
            reg_d4.w = 0;
            func_00129370();
            reg_d1.b[0] += 0x20;
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
            func_00129370();
            reg_d1.b[0] += 0x60;
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x16)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x18)));
            func_00129280();
            if ((*(u8 *)((u8 *)(reg_a4) + (5))) & 1) {
                reg_d1.b[0] += 0x20;
                reg_d0.w = 0x10003;
                func_00129280();
            }
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (8)));
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d3.h[0] = 0x400;
            reg_d4.w = 0;
            func_00129370();
            reg_d1.b[0] += 0x20;
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
            func_00129370();
            reg_d1.b[0] += 0x60;
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x16)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x18)));
            func_00129280();
            if ((*(u8 *)((u8 *)(reg_a4) + (5))) & 1) {
                reg_d0.w = 0x10003;
                func_00129280();
            }
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1F)));
            (*(u8 *)((u8 *)(reg_a4) + (9))) += reg_d0.b[0];
            var_a1 = (s16 *)(reg_a4);
            reg_d0.b[0] = (*(u8 *)((u8 *)(var_a1) + (0x1E)));
            (*(u8 *)((u8 *)(var_a1) + (8))) += reg_d0.b[0];
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
            (*(u8 *)((u8 *)(reg_a4) + (0x1F))) *= -1;
            (*(u8 *)((u8 *)(reg_a4) + (0x1E))) *= -1;
            temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x1CD)));
            if ((s32) temp_v0 < 0x3C) {
                (*(u8 *)((u8 *)(reg_a6) + (0x1CD))) = (u8) (temp_v0 + 0x14);
            }
            temp_v1 = (*(u16 *)((u8 *)(reg_a6) + (0x1CE)));
            if ((s16)(temp_v1) < 4) {
                (*(u16 *)((u8 *)(reg_a6) + (0x1CE))) = (u16) (temp_v1 + 1);
            }
            temp_v1_2 = (*(u16 *)((u8 *)(reg_a6) + (0x1D0)));
            if ((s16)(temp_v1_2) < 0x1A) {
                (*(u16 *)((u8 *)(reg_a6) + (0x1D0))) = (u16) (temp_v1_2 + 1);
            }
            (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 0;
            reg_d0.w = 1;
            func_00125310();
        }
    }
}
