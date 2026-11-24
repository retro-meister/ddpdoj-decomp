#include "common.h"

void func_001A8FC0(void);
void func_001A97F0(void);
void func_001A9B60(void);
void func_001AA160(void);
extern u16 D_0028E5D0;
extern u16 D_0028E5FC;
extern u16 D_0028E60C;
extern u16 D_0028E614;
extern u16 D_0028E698;
extern u16 D_0028E69C;
extern u16 D_0028E6A0;
extern u32 D_0028E6A4;
extern u32 D_0028E6A8;
extern u32 D_0028E6AC;
extern u16 D_0028E6B0;
extern u16 D_0028E6B4;
extern s16 D_0028E6B8;
extern u16 D_0028E6BC;
extern u16 D_0028E6C0;
extern s16 D_0028E6C4;
extern u16 D_0028E6C8;
extern u32 D_0028E6CC;
extern u32 D_0028E6D0;
extern u32 D_0028E720;
extern u8 D_0028E855;
extern s16 D_0029CEA0[];
extern u16 D_0029F282[];
extern u16 D_0029F2BA[];
extern u8 *reg_a0;

void func_001A9D80(void) {
    u16 saved_d0;

    switch (D_0028E855 & 4) {
    case 0:
        break;
    default:
        func_001AA160();
        return;
    }
    reg_d3.w = reg_d0.w;
    if ((D_0029CEA0[0] >= 0) && (D_0028E6C8 == 0)) {
        reg_d0.w = 0;
        D_0028E6C8 = 0xA;
        reg_d2.w = 8;
        D_0028E6D0 = reg_d0.w;
        D_0028E6CC = reg_d0.w;
        D_0028E6AC = reg_d0.w;
        D_0028E6A8 = reg_d0.w;
        D_0028E6A0 = reg_d0.h[0];
        D_0028E6C0 = reg_d0.h[0];
        reg_d2.h[0] -= (s16) (u16) D_0029F282[0];
        reg_d0.h[0] = reg_d2.h[0];
        reg_d0.h[0] >>= 1;
        reg_d2.h[0] += reg_d0.h[0];
        reg_d2.h[0] += 0x12;
        D_0028E60C = reg_d2.h[0];
        if (D_0028E5FC != 0) {
            reg_d2.h[0] -= 0xC;
        }
        D_0028E698 = reg_d2.h[0];
        return;
    }
    func_001A9B60();
    D_0028E698 -= 1;
    if ((s16) D_0028E698 < 0) {
        if (D_0028E5FC != 0) {
            reg_d2.w = 6;
            reg_d2.h[0] -= D_0028E5D0;
        } else {
            reg_d2.w = 8;
            reg_d2.h[0] -= (s16) (u16) D_0029F282[0];
            reg_d0.h[0] = reg_d2.h[0];
            reg_d0.h[0] >>= 1;
            reg_d2.h[0] += reg_d0.h[0];
            reg_d2.h[0] += 1;
            reg_d2.h[0] += 0x11;
            if (D_0029F2BA[0] != 2) {
                reg_d2.h[0] -= 3;
            }
        }
        D_0028E698 = reg_d2.h[0];
        if (D_0028E6D0 != 0) {
            reg_d0.w = D_0028E6D0;
            D_0028E6A0 = 1;
            D_0028E6AC = reg_d0.w;
            D_0028E6A8 = reg_d0.w;
            reg_d0.w = 0;
            D_0028E6D0 = reg_d0.w;
        }
        reg_a0 = (u8 *)&D_0028E6A0;
        reg_d0.w = 0;
        if (reg_d1.w & 0x40) {
            reg_d0.h[0] += reg_d0.h[0];
        }
        do {
            saved_d0 = reg_d0.h[0];
            func_001A8FC0();
            reg_d0.h[0] = saved_d0;
        } while ((s16)(--reg_d0.h[0]) >= 0);
        reg_d0.h[0] = D_0028E614;
        if ((s32) D_0028E6A0 > (s32) reg_d0.h[0]) {
            D_0028E614 = D_0028E6A0;
        }
        reg_d0.w = reg_d3.w;
        reg_a0 = (u8 *)&D_0028E6B0;
        func_001A97F0();
        reg_d0.w = D_0028E6AC;
        reg_a0 = (u8 *)&D_0028E6AC;
        func_001A97F0();
        reg_d0.w = D_0028E6AC;
        reg_a0 = (u8 *)&D_0028E720;
        func_001A97F0();
    }
    if (D_0028E5FC == 0) {
        if ((s32) D_0028E6C8 < 0xA) {
            D_0028E6C8 = 0xA;
        }
    } else if ((s32) D_0028E6C8 < 0x19) {
        D_0028E6C8 = 0x19;
    }
    if ((s32) D_0028E6A0 < 0x10) {
        if ((s32) D_0028E6A0 > 1) {
            D_0028E6C0 = 0x78;
        }
        D_0028E6BC = D_0028E6C8;
        if (D_0028E6A4 == 0) {
            D_0028E6C4 = 0xB4;
        }
        return;
    }
    if (D_0028E6B4 == 0) {
        D_0028E6B0 = 0;
        D_0028E6C0 = 0;
    }
    D_0028E69C = D_0028E6A0;
    D_0028E6B8 = 0xF0;
    D_0028E6C4 = 0xF0;
    D_0028E6B4 = D_0028E6C8;
    D_0028E6A4 = D_0028E6A8;
}
