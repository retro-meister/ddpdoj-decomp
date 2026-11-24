#include "common.h"

s32 func_00131440();
s32 func_00138110();
s32 func_00138CC0();
s32 stage_load_step();
s32 func_002195A0();
s32 func_002256B0();
extern s32 D_0028DF1C;
extern u8 D_0028E25C;
extern u8 D_0028E280;
extern s8 D_0028E284;
extern s8 D_0028E288;
extern u8 D_0028E2BD;
extern u8 D_0028E304;
extern s8 D_0028E368;
extern u8 D_0028E370;
extern s8 D_0028E378;
extern u16 D_0028E3C0;
extern s16 D_0028E3FC;
extern u16 D_0028E5BC;
extern u16 D_0028E5C0;
extern s16 D_0028E5F0;
extern s16 D_0028E5F4;
extern u16 D_0028E748;
extern u16 D_0028E750;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern s8 D_0028EC58;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a5;

void func_001394A0(void) {
    stage_load_step();
    D_0028DF1C += 1;
    if (D_0028EC58 == 0) {
        if ((D_0028E3FC == D_0028E91C) && (D_0028DF1C >= 0)) {
            D_0028EC58 = 1;
            func_00131440();
        }
    } else if (D_0028E370 != 0) {
        if (D_0028E3C0 == 0) {
            D_0028E378 = 0;
        }
        (*(u8 *)((u8 *)(reg_a5) + (2))) |= 2;
        D_0028EC58 = 0;
        if (D_0028E3C0 == 0) {
            D_0028E368 = 1;
        }
        func_00138CC0();
        func_002256B0();
        func_00138110();
        func_002195A0();
#ifdef DEATH_LABEL
        if (D_0028E910 == 0) {
            D_0028E288 = 0;
            D_0028E284 = 0;
        }
#else
        if (D_0028ED80 == 0) {
            if (D_0028E910 == 0) {
                D_0028E288 = 0;
                D_0028E284 = 0;
            }
        } else if (D_0028E280 != 5) {
            D_0028E288 = 0;
            D_0028E284 = 0;
        }
#endif
        if ((D_0028ED80 == 0) && (D_0028E910 == 1) && (D_0028E91C == 0)) {
            if (D_0029F260[0] < 0) {
                if (D_0028E5C0 != 0) {
                    D_0028E5F4 = 0;
                    D_0028E288 = 0x78;
                }
            } else if ((D_0029F1F0[0] < 0) && (D_0028E5BC != 0)) {
                D_0028E5F0 = 0;
                D_0028E284 = 0x78;
            }
        }
        if ((D_0028ED80 == 0) && (D_0028ED7C != 2)) {
            if ((D_0028E750 == 0) && (D_0029F260[0] < 0)) {
                D_0028E25C = D_0028E91C + (D_0028E910 * 5);
                if (D_0028E304 != 0) {
                    D_0028E25C = D_0028E91C + 5;
                }
            } else if ((D_0028E748 == 0) && (D_0029F1F0[0] < 0)) {
                D_0028E25C = D_0028E91C + (D_0028E910 * 5);
                if (D_0028E304 != 0) {
                    D_0028E25C = D_0028E91C + 5;
                }
            }
            D_0028E2BD = D_0028E25C;
        }
    }
}
