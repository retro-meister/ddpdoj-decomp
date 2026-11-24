#include "common.h"

s32 func_0013AFF0();
s32 func_001A29E0();
s32 func_001A2C70();
s32 func_00219010();
s32 func_00219120();
s32 func_002192F0();
extern u8 D_0028E0AC;
extern u8 D_0028E0AD;
extern u16 D_0028E0B0;
extern u16 D_0028E0B4;
extern u16 D_0028E0B8;
extern u16 D_0028E0BC;
extern u16 D_0028E0C0;
extern s16 D_0028E8A8;
extern u16 D_0028E91C;
extern u8 D_0029F2D0[];
extern u8 D_0029F4B0[];
extern u8 D_0029FCB0[];
extern u8 D_002B2750[];
extern u8 D_002B2950[];
extern u8 D_002B3150[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_001A2C80(void) {
    if (D_0028E0C0 != 0) {
        reg_a0 = (u8 *)D_0029FCB0;
        reg_a1 = (u8 *)D_002B3150;
        reg_d0.w = 0x1F;
        do {
            func_001A29E0();
            func_001A29E0();
        } while ((s16)(--reg_d0.h[0]) >= 0);
        D_0028E0C0 = 0;
        func_001A2C70();
        func_00219120();
    }
    if (D_0028E0BC != 0) {
        reg_a0 = (u8 *)D_0029F4B0;
        reg_a1 = (u8 *)D_002B2950;
        reg_d0.w = 0x1F;
        do {
            func_001A29E0();
            func_001A29E0();
        } while ((s16)(--reg_d0.h[0]) >= 0);
        D_0028E0BC = 0;
        func_001A2C70();
        func_002192F0();
    }
    if (D_0028E0B8 != 0) {
        reg_a0 = (u8 *)D_0029F2D0;
        reg_a1 = (u8 *)D_002B2750;
        reg_d0.w = 0xE;
        do {
            func_001A29E0();
        } while ((s16)(--reg_d0.h[0]) >= 0);
        D_0028E0B8 = 0;
        func_001A2C70();
        func_00219010();
    }
    if ((D_0028E91C == 0) && (D_0028E8A8 < 0x130)) {
        reg_a1 = (u8 *)D_002B2950;
        reg_a0 = (u8 *)D_0029F4B0;
        reg_a1 += 0x540;
        reg_a0 += 0x540;
        reg_d1.h[0] = D_0028E0B4;
        reg_d0.h[0] = *(u16 *)(reg_a0 + 6);
        func_0013AFF0();
        *(u16 *)(reg_a1 + 6) = (u16) reg_d0.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a0 + 4);
        func_0013AFF0();
        *(u16 *)(reg_a1 + 4) = (u16) reg_d0.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a0 + 2);
        func_0013AFF0();
        *(u16 *)(reg_a1 + 2) = (u16) reg_d0.h[0];
        reg_d0.h[0] = *(u16 *)reg_a0;
        func_0013AFF0();
        *(u16 *)reg_a1 = (u16) reg_d0.h[0];
        func_002192F0();
        reg_tmp.b[0] = D_0028E0AD;
        D_0028E0AD -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            reg_d0.h[0] = D_0028E0B0;
            D_0028E0AD = D_0028E0AC;
            if ((s16)(reg_d0.h[0]) < 0) {
                D_0028E0B4 += reg_d0.h[0];
                if ((s16) D_0028E0B4 < 0x18) {
                    D_0028E0B0 *= -1;
                }
            } else {
                D_0028E0B4 += reg_d0.h[0];
                if ((s16) D_0028E0B4 >= 0x3C) {
                    D_0028E0B0 *= -1;
                }
            }
        }
    }
}
