#include "common.h"

s32 func_0019DAF0();
extern u16 D_00255568[];
extern u16 D_0028E060;
extern u16 D_0028E064;
extern u16 D_0028E068;
extern u16 D_0028E06C;
extern u16 D_0028E070;
extern u16 D_0028E074;
extern u16 D_0028E3B4;
extern u16 D_0028E3EC;
extern u8 D_0028E855;
extern u16 D_0028E908;
extern u16 D_0029CD80[];
extern u16 D_0029CD90[];
extern u16 D_0029F1F0[];
extern u8 D_0029F240[];
extern u16 D_0029F260[];
extern u8 D_0029F2B0[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_0013D090(void) {
    if (D_0028E3B4 == 0) {
        reg_d0.h[0] = D_0029F260[0];
        if (((s16)(reg_d0.h[0]) < 0) && !(reg_d0.h[0] & 0xFFFF & 0x4000) && (D_0029CD90[0] != 0)) {
            reg_a1 = (u8 *)D_0029F2B0;
            reg_d0.h[0] = D_0028E074;
            reg_d4.h[0] = 7;
            reg_tmp.h[0] = D_0028E06C;
            D_0028E06C -= 1;
            if ((s32) reg_tmp.h[0] <= 0) {
                D_0028E06C = D_0028E068;
            }
            switch (D_0028E3EC) { case 0: break; default:
                reg_a0 = (u8 *)(D_00255568);
                reg_d4.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d4.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            }
            if (((D_0028E908 == 0) && !(D_0028E855 & 1)) || (reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0))), reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2))), (reg_tmp.w != 0xC41))) {
                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                reg_tmp.w += 1;
                (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                if (reg_tmp.w == 0xCA1) {
                    reg_tmp.w = 0xC41;
                    (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                    (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                }
            }
            reg_d1.w = 0xFF010200;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
            reg_d3.h[0] = 0x460;
            func_0019DAF0();
        }
        reg_d0.h[0] = D_0029F1F0[0];
        if (((s16)(reg_d0.h[0]) < 0) && !(reg_d0.h[0] & 0xFFFF & 0x4000) && (D_0029CD80[0] != 0)) {
            reg_a1 = (u8 *)D_0029F240;
            reg_d0.h[0] = D_0028E070;
            reg_d4.h[0] = 8;
            reg_tmp.h[0] = D_0028E064;
            D_0028E064 -= 1;
            if ((s32) reg_tmp.h[0] <= 0) {
                D_0028E064 = D_0028E060;
            }
            if (D_0028E3EC != 0) {
                reg_a0 = (u8 *)(D_00255568);
                reg_d4.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d4.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            }
            if (((D_0028E908 == 0) && !(D_0028E855 & 1)) || (reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0))), reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2))), (reg_tmp.w != 0xC41))) {
                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                reg_tmp.w += 1;
                (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                if (reg_tmp.w == 0xCA1) {
                    reg_tmp.w = 0xC41;
                    (*(u16 *)((u8 *)(reg_a1) + (0))) = (u16) reg_tmp.h[1];
                    (*(u16 *)((u8 *)(reg_a1) + (2))) = (u16) reg_tmp.h[0];
                }
            }
            reg_d1.w = 0xFF011E00;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
            reg_d3.h[0] = 0x460;
            func_0019DAF0();
        }
    }
}
