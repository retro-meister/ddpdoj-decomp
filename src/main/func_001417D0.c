#include "common.h"

s32 func_001340B0();
s32 func_0013E6C0();
s32 func_0013E710();
s32 func_0013FCA0();
s32 func_0013FCE0();
s32 func_001A7E90();
s32 func_001A8070();
extern u8 D_0028C608[];
extern s16 D_0028E050;
extern s16 D_0028E054;
extern u16 D_0028E058;
extern u16 D_0028E05A;
extern u16 D_0028E05C;
extern u16 D_0028E05E;
extern s16 D_0028E060;
extern s16 D_0028E064;
extern s16 D_0028E068;
extern s16 D_0028E06C;
extern s16 D_0028E070;
extern s16 D_0028E074;
extern s16 D_0028E5B4;
extern s16 D_0028E5B8;
extern s16 D_0028E5BC;
extern s16 D_0028E5C0;
extern s16 D_0028E5E0;
extern s16 D_0028E5E4;
extern s16 D_0028E5E8;
extern s16 D_0028E5EC;
extern s16 D_0029CD80[];
extern s16 D_0029CD8C[];
extern s16 D_0029CD90[];
extern s16 D_0029CD9C[];
extern u8 D_0029F1F0[];
extern u8 D_0029F1F1[];
extern u8 D_0029F260[];
extern u8 D_0029F261[];
extern u16 D_006E5BFC[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

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
    if (save_a6 == D_0029F260) {
        D_0028E06C = 2;
        D_0028E068 = 2;
        reg_d0.w = 0xC30;
        D_0028E054 = 0x101;
        D_0028E074 = 0;
        D_0028E05C = reg_d0.h[1];
        D_0028E05E = reg_d0.h[0];
        func_001A7E90();
        func_0013FCA0();
    } else {
        D_0028E064 = 2;
        D_0028E060 = 2;
        reg_d0.w = 0xC30;
        D_0028E050 = 0x101;
        D_0028E070 = 0;
        D_0028E058 = reg_d0.h[1];
        D_0028E05A = reg_d0.h[0];
        func_001A8070();
        func_0013FCE0();
    }
    reg_d1.w = 0;
    reg_d1.h[0] = 8;
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_d1.h[0];
    D_0028E5C0 = 0;
    D_0028E5BC = 0;
    for (i = 0; i < (s32) D_006E5BFC[0]; i++) {
        if (reg_a6 == D_0029F260) {
            func_0013E6C0();
        } else {
            func_0013E710();
        }
    }
    if (reg_a6 == D_0029F260) {
        (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xFE;
        D_0028E5B8 = 4;
        D_0028E5E4 = 0x95F;
        D_0028E5EC = 0xF;
    } else {
        (*(u8 *)((u8 *)(reg_a6) + (0))) &= 0xFE;
        D_0028E5B4 = 4;
        D_0028E5E0 = 0x95F;
        D_0028E5E8 = 0xF;
    }
    reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
    reg_a0 = (u8 *)D_0028C608;
    reg_d5.h[0] -= 2;
    lo = reg_d5.h[0] & 1;
    step = (lo != 0) ? -1 : 1;
    reg_d5.b[0] = *(reg_a0 + reg_d5.h[0] + step);
    reg_d5.b[0] *= 2;
    (*(u8 *)((u8 *)(reg_a6) + (0x24))) = (u8) reg_d5.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x24)));
    if (reg_a6 == D_0029F260) {
        D_0029CD90[0] = 0;
        D_0029CD9C[0] = 0;
        D_0029F261[0] |= 0x40;
        D_0029F260[0] &= 0xFD;
    } else {
        D_0029CD80[0] = 0;
        D_0029CD8C[0] = 0;
        D_0029F1F1[0] |= 0x40;
        D_0029F1F0[0] &= 0xFD;
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
