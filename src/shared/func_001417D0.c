#include "common.h"

s32 func_001340B0();
s32 func_0013E6C0();
s32 func_0013E710();
s32 func_0013FCA0();
s32 func_0013FCE0();
s32 func_001A7E90();
s32 func_001A8070();
extern u8 D_0028C608[];
extern s16 D_0028E050_as_s16;
extern s16 D_0028E054_as_s16;
extern u16 D_0028E058_as_u16;
extern u16 D_0028E05A;
extern u16 D_0028E05C_as_u16;
extern u16 D_0028E05E;
extern s16 D_0028E060_as_s16;
extern s16 D_0028E064_as_s16;
extern s16 D_0028E068_as_s16;
extern s16 D_0028E06C_as_s16;
extern s16 D_0028E070_as_s16;
extern s16 D_0028E074_as_s16;
extern s16 D_0028E5B4_as_s16;
extern s16 D_0028E5B8_as_s16;
extern s16 D_0028E5BC_as_s16;
extern s16 D_0028E5C0_as_s16;
extern s16 D_0028E5E0_as_s16;
extern s16 D_0028E5E4_as_s16;
extern s16 D_0028E5E8_as_s16;
extern s16 D_0028E5EC_as_s16;
extern s16 D_0029CD80_as_s16_a[];
extern s16 D_0029CD8C_as_s16_a[];
extern s16 D_0029CD90_as_s16_a[];
extern s16 D_0029CD9C_as_s16_a[];
extern u8 D_0029F1F0_as_u8_a[];
extern u8 D_0029F1F1[];
extern u8 D_0029F260_as_u8_a[];
extern u8 D_0029F261[];
extern u16 D_006E5BFC[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
extern u16 D_0028DFFC;
extern u16 D_0028E7F0;
#endif

void func_001417D0(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    s32 lo;
    s32 step;
    s32 i;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    if (save_a6 == D_0029F260_as_u8_a) {
        D_0028E06C_as_s16 = 2;
        D_0028E068_as_s16 = 2;
        reg_d0.w = 0xC30;
        D_0028E054_as_s16 = 0x101;
        D_0028E074_as_s16 = 0;
        D_0028E05C_as_u16 = reg_d0.h[1];
        D_0028E05E = reg_d0.h[0];
        func_001A7E90();
        func_0013FCA0();
    } else {
        D_0028E064_as_s16 = 2;
        D_0028E060_as_s16 = 2;
        reg_d0.w = 0xC30;
        D_0028E050_as_s16 = 0x101;
        D_0028E070_as_s16 = 0;
        D_0028E058_as_u16 = reg_d0.h[1];
        D_0028E05A = reg_d0.h[0];
        func_001A8070();
        func_0013FCE0();
    }
    reg_d1.w = 0;
    reg_d1.h[0] = 8;
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_d1.h[0];
    D_0028E5C0_as_s16 = 0;
    D_0028E5BC_as_s16 = 0;
    for (i = 0; i < (s32) D_006E5BFC[0]; i++) {
        if (reg_a6 == D_0029F260_as_u8_a) {
            func_0013E6C0();
        } else {
            func_0013E710();
        }
    }
#ifdef DEATH_LABEL
    if (reg_a6 == D_0029F260_as_u8_a) {
        (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xFE;
        if (death_D_00290DC0 == 0) {
            D_0028E5B8_as_s16 = 4;
            D_0028E5E4_as_s16 = 0x95F;
        } else {
            D_0028E5B8_as_s16 = 0;
            D_0028E5E4_as_s16 = 0;
        }
        D_0028E5EC_as_s16 = 0xF;
    } else {
        (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xFE;
        if (death_D_00290DC0 == 0) {
            D_0028E5B4_as_s16 = 4;
            D_0028E5E0_as_s16 = 0x95F;
        } else {
            D_0028E5B4_as_s16 = 0;
            D_0028E5E0_as_s16 = 0;
        }
    }
    D_0028E5E8_as_s16 = 0xF;
    D_0028DFFC = 0xA;
    D_0028E7F0 = 2;
#else
    if (reg_a6 == D_0029F260_as_u8_a) {
        (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xFE;
        D_0028E5B8_as_s16 = 4;
        D_0028E5E4_as_s16 = 0x95F;
        D_0028E5EC_as_s16 = 0xF;
    } else {
        (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xFE;
        D_0028E5B4_as_s16 = 4;
        D_0028E5E0_as_s16 = 0x95F;
        D_0028E5E8_as_s16 = 0xF;
    }
#endif
    reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
    reg_a0 = (u8 *)D_0028C608;
    reg_d5.h[0] -= 2;
    lo = reg_d5.h[0] & 1;
    step = (lo != 0) ? -1 : 1;
    reg_d5.b[0] = *(reg_a0 + reg_d5.h[0] + step);
    reg_d5.b[0] *= 2;
    (*(u8 *)((u8 *)(reg_a6) + (0x24))) = (u8) reg_d5.b[0];
#ifdef DEATH_LABEL
    if (death_D_00290DC0 == 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x24)));
    } else {
        (*(u8 *)((u8 *)(reg_a6) + (0x25))) = 0;
        (*(u8 *)((u8 *)(reg_a6) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x24)));
    }
#else
    (*(u8 *)((u8 *)(reg_a6) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x24)));
#endif
    if (reg_a6 == D_0029F260_as_u8_a) {
        D_0029CD90_as_s16_a[0] = 0;
        D_0029CD9C_as_s16_a[0] = 0;
        D_0029F261[0] |= 0x40;
        D_0029F260_as_u8_a[0] &= 0xFD;
    } else {
        D_0029CD80_as_s16_a[0] = 0;
        D_0029CD8C_as_s16_a[0] = 0;
        D_0029F1F1[0] |= 0x40;
        D_0029F1F0_as_u8_a[0] &= 0xFD;
    }
    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
    func_001340B0();
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}
