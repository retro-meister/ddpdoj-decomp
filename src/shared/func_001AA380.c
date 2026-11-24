#include "common.h"

void func_001A8FC0(void);
void func_001A97F0(void);
void func_001A9C70(void);
void func_001AA6D0(void);
extern u16 D_0028E5CC;
extern u16 D_0028E5F8;
extern u16 D_0028E608;
extern u16 D_0028E610;
extern u16 D_0028E658;
extern u16 D_0028E65C;
extern u16 D_0028E660;
extern u32 D_0028E664_as_u32;
extern u32 D_0028E668_as_u32;
extern u32 D_0028E66C_as_u32;
extern u16 D_0028E670;
extern u16 D_0028E674;
extern s16 D_0028E678;
extern u16 D_0028E67C;
extern u16 D_0028E680;
extern s16 D_0028E684;
extern u16 D_0028E688;
extern u32 D_0028E68C_as_u32;
extern u32 D_0028E690_as_u32;
extern u32 D_0028E71C_as_u32;
extern u8 D_0028E855;
extern s16 D_0029CEA0_as_s16_a[];
extern u16 D_0029F212[];
extern u16 D_0029F24A[];
extern u8 *reg_a0;

void func_001AA380(void) {
    u16 saved_d0;

    switch (D_0028E855 & 4) {
    case 0:
        break;
    default:
        func_001AA6D0();
        return;
    }
    reg_d3.w = reg_d0.w;
    if ((D_0029CEA0_as_s16_a[0] >= 0) && (D_0028E688 == 0)) {
        reg_d0.w = 0;
        D_0028E688 = 0xA;
        reg_d2.w = 8;
        D_0028E690_as_u32 = reg_d0.w;
        D_0028E68C_as_u32 = reg_d0.w;
        D_0028E66C_as_u32 = reg_d0.w;
        D_0028E668_as_u32 = reg_d0.w;
        D_0028E660 = reg_d0.h[0];
        D_0028E680 = reg_d0.h[0];
        reg_d2.h[0] -= (s16) (u16) D_0029F212[0];
        reg_d0.h[0] = reg_d2.h[0];
        reg_d0.h[0] >>= 1;
        reg_d2.h[0] += reg_d0.h[0];
        reg_d2.h[0] += 0x12;
        D_0028E608 = reg_d2.h[0];
        if (D_0028E5F8 != 0) {
            reg_d2.h[0] -= 0xC;
        }
        D_0028E658 = reg_d2.h[0];
        return;
    }
    func_001A9C70();
    D_0028E658 -= 1;
    if ((s16) D_0028E658 < 0) {
        if (D_0028E5F8 != 0) {
            reg_d2.w = 6;
            reg_d2.h[0] -= D_0028E5CC;
        } else {
            reg_d2.w = 8;
            reg_d2.h[0] -= (s16) (u16) D_0029F212[0];
            reg_d0.h[0] = reg_d2.h[0];
            reg_d0.h[0] >>= 1;
            reg_d2.h[0] += reg_d0.h[0];
            reg_d2.h[0] += 1;
            reg_d2.h[0] += 0x11;
            if (D_0029F24A[0] != 2) {
                reg_d2.h[0] -= 3;
            }
        }
        D_0028E658 = reg_d2.h[0];
        if (D_0028E690_as_u32 != 0) {
            reg_d0.w = D_0028E690_as_u32;
            D_0028E660 = 1;
            D_0028E66C_as_u32 = reg_d0.w;
            D_0028E668_as_u32 = reg_d0.w;
            reg_d0.w = 0;
            D_0028E690_as_u32 = reg_d0.w;
        }
        reg_a0 = (u8 *)&D_0028E660;
        reg_d0.w = 0;
        if (reg_d1.w & 0x40) {
            reg_d0.h[0] += reg_d0.h[0];
        }
        do {
            saved_d0 = reg_d0.h[0];
            func_001A8FC0();
            reg_d0.h[0] = saved_d0;
        } while ((s16)(--reg_d0.h[0]) >= 0);
        reg_d0.h[0] = D_0028E610;
        if ((s32) D_0028E660 > (s32) reg_d0.h[0]) {
            D_0028E610 = D_0028E660;
        }
        reg_d0.w = reg_d3.w;
        reg_a0 = (u8 *)&D_0028E670;
        func_001A97F0();
        reg_d0.w = D_0028E66C_as_u32;
        reg_a0 = (u8 *)&D_0028E66C_as_u32;
        func_001A97F0();
        reg_d0.w = D_0028E66C_as_u32;
        reg_a0 = (u8 *)&D_0028E71C_as_u32;
        func_001A97F0();
    }
    if (D_0028E5F8 == 0) {
        if ((s32) D_0028E688 < 0xA) {
            D_0028E688 = 0xA;
        }
    } else if ((s32) D_0028E688 < 0x19) {
        D_0028E688 = 0x19;
    }
    if ((s32) D_0028E660 < 0x10) {
        if ((s32) D_0028E660 > 1) {
            D_0028E680 = 0x78;
        }
        D_0028E67C = D_0028E688;
        if (D_0028E664_as_u32 == 0) {
            D_0028E684 = 0xB4;
        }
        return;
    }
    if (D_0028E674 == 0) {
        D_0028E670 = 0;
        D_0028E680 = 0;
    }
    D_0028E65C = D_0028E660;
    D_0028E678 = 0xF0;
    D_0028E684 = 0xF0;
    D_0028E674 = D_0028E688;
    D_0028E664_as_u32 = D_0028E668_as_u32;
}
