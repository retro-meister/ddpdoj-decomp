#include "common.h"

s32 func_0013EA30();
s32 func_001A8070();
s32 func_001AAA20();
s32 func_001ABA50();
s32 func_001ABA70();
s32 func_001ABB00();
extern u8 D_0028E284;
extern u8 D_0028E370;
extern u16 D_0028E3B4;
extern u16 D_0028E5BC;
extern u16 D_0028E5C4;
extern u16 D_0028E5CC;
extern s8 D_0028E5D8_as_s8;
extern s8 D_0028E5D9_as_s8;
extern u16 D_0028E5E8;
extern u16 D_0028E5F0;
extern u16 D_0028E5F8;
extern u16 D_0028E660;
extern u16 D_0028E674;
extern s16 D_0028E678;
extern s16 D_0028E684;
extern u16 D_0028E688;
extern u16 D_0028E6DC;
extern u8 D_0028E855;
extern u8 D_0028EC4C;
extern u8 D_0029F1F1[];
void func_001A7EE0(void) {
    u32 temp_a0;
    u32 temp_v1;

    if (D_0028E5F8 == 0) {
        if (D_0028E5C4 == 0) {
            func_001ABB00();
            return;
        }
        reg_d0.w = 0x11;
        temp_a0 = reg_d0.b[0];
        temp_v1 = temp_a0 & D_0029F1F1[0];
        reg_d0.b[0] = temp_v1;
        if (!(temp_v1 & 0xFF)) {
            D_0028E5F8 = 1;
            func_001ABA50();
            func_001AAA20();
            if (D_0028E688 != 0) {
                D_0028E688 = D_0028E6DC;
            }
            reg_d0.h[0] = D_0028E5BC;
            D_0028E5E8 += reg_d0.h[0];
            D_0028E5CC = reg_d0.h[0];
            if (D_0028E5E8 > 0xF) {
                D_0028E5E8 = 0xF;
            }
            D_0028E5D9_as_s8 = 0;
            D_0028E5D8_as_s8 = 0;
            D_0028E5BC = 0;
            func_0013EA30();
            goto block_9;
        }
    } else {
block_9:
        func_001ABA70();
        if (D_0029F1F1[0] & 1) {
            func_001A8070();
            return;
        }
        if (((s32) D_0028E660 >= 0x10) && (D_0028E688 != 0)) {
            D_0028E674 = D_0028E688;
            D_0028E678 = 0x78;
            D_0028E684 = 0x78;
        }
        if (!(D_0028E855 & 0x40) && (D_0028E3B4 == 0) && (D_0028EC4C == 0) && (D_0028E370 != 0)) {
            D_0028E5F0 -= 2;
            if ((s16) D_0028E5F0 < 0) {
                func_001A8070();
                if (D_0028E284 == 0x78) {
                    D_0028E284 = 0xA;
                }
            }
        }
    }
}
