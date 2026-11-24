#include "common.h"

extern s8 D_0028E408;

s32 func_001E8FF0();
s32 func_002021F0();
extern s16 *D_0028E44C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E8DA0(void) {
    s16 *temp_a0;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
            D_0028E44C = (s16 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(D_0028E44C);
        }
        temp_a0 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
            if (0 > (s64)*(s16 *)reg_a1) {
                reg_a0 = (u8 *)(reg_a1);
                D_0028E44C = (s16 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
            if ((*(u8 *)((u8 *)(reg_a6) + (0x131))) == 0) {
                reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d0.h[0] += 0x7FFF + 0x77C1;
                func_002021F0();
                reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x12E)));
                func_001E8FF0();
                if (D_0028E408 == 0) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x12E))) = (u16) reg_d1.h[0];
                }
            }
        }
    }
}
