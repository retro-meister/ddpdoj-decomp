#include "common.h"

s32 func_002021F0();
s32 func_00202500();
extern s16 *D_0028E44C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001CDEA0(void) {
    s16 *temp_a0;
    u32 temp_s0;
    u32 temp_s1;

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
        if ((*(s16 *)((u8 *)(temp_a0) + (0))) >= 0) {
            if (*(s16 *)reg_a1 < 0) {
                reg_a0 = (u8 *)(reg_a1);
                D_0028E44C = (s16 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
            temp_s1 = reg_d3.w;
            temp_s0 = reg_d2.w;
            if ((*(u16 *)((u8 *)(reg_a6) + (0xB6))) == 0) {
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
                reg_d0.h[0] += 0x1100;
                reg_d1.h[0] += 0x80;
                func_002021F0();
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xB0)));
                func_00202500();
                (*(u16 *)((u8 *)(reg_a6) + (0xB0))) = (u16) reg_d1.h[0];
            }
            reg_d2.w = temp_s0;
            reg_d3.w = temp_s1;
            if ((*(u16 *)((u8 *)(reg_a6) + (0xB8))) == 0) {
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
                reg_d0.h[0] += 0x1100;
                reg_d1.h[0] += 0x7FFF + 0x7F81;
                func_002021F0();
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xB2)));
                func_00202500();
                (*(u16 *)((u8 *)(reg_a6) + (0xB2))) = (u16) reg_d1.h[0];
            }
        }
    }
}
