#include "common.h"

extern s8 D_0028E408;

s32 func_0011C920();
s32 func_00135100();
s32 func_00135110();
s32 func_00137CC0();
s32 func_001719A0();
s32 func_001719B0();
s32 func_001719D0();
s32 func_0018D190();
s32 func_001A33C0();
extern void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b);
extern void func_00236DF0(void);
s32 func_00237DF0();
s32 func_0023B6B0();
void *memcpy(void *dst, const void *src, u32 n);
s32 printf(const char *format, ...);
extern char D_0028BF20[];
extern u8 D_0028DEF8;
extern u16 D_0028DFC0;
extern u8 D_0028E2E4;
extern u8 D_0028E2EC;
extern u8 D_0028E304;
extern u8 D_0028E368;
extern u8 D_0028E384;
extern u8 D_0028E388;
extern u8 D_0028E38C;
extern u16 D_0028E3C0;
extern u16 D_0028E3DC;
extern u16 D_0028E3E0;
extern u16 D_0028E3E4;
extern u16 D_0028E3E8;
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern u16 D_0028E598;
extern u16 D_0028E59C;
extern u16 D_0028E8A8;
extern u16 D_0028E8AC;
extern s32 D_0028E8BC;
extern u16 D_0028E8C0;
extern u16 D_0028E8C4;
extern u16 D_0028E910;
extern s32 D_0028E998;
extern s32 D_0028E99C;
extern s8 D_0028EC58;
extern u8 D_0028ED5C;
extern u8 D_0028ED6C;
extern u16 D_0029F1F0[];
extern u16 D_0029F260[];
extern u16 D_006C58A2[];
extern u16 D_006C58A6[];
extern u8 D_006C58C4[];
extern u8 D_006C5CA0[];
extern u8 D_006C68B6[];
extern u8 D_006C6918[];
extern u16 D_006C8E56[];
extern s32 D_006C8E88[];
extern u16 D_006C8E90[];
extern u16 D_006C8E94[];
extern u16 D_006C91A0[];
extern u8 D_006C91AC[];
extern u8 D_006C91AD[];
extern u8 D_006C91AE[];
extern u8 D_006C91AF[];
extern u8 D_006C91B0[];
extern u16 D_006E5BEE[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_00238010(void) {
    s32 base;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    s32 step;

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
    step = *(u16 *)(reg_a5 + 10);
    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_00237DF0();
        func_00215DB0(0, 0, 0x1C2, 0xE0, 0x50, 0x80, 0xFF, 0xFF, 0xFF);
        D_0028E998 = -1;
        D_0028E99C = -1;
        reg_d0.h[0] = 0;
        reg_d1.h[0] = D_006C58A2[0];
        func_001A33C0();
        reg_d0.h[0] = 1;
        reg_d1.h[0] = D_006C58A6[0];
        func_001A33C0();
        func_0023B6B0(D_006C5CA0);
        D_0028E598 = 0;
        return;
    }
    if (step < 0xC8) {
        D_0028E368 = 0;
        D_0028E598 = 0;
        if ((D_006C8E56[0] != 0) && (step < 0x65)) {
            func_0011C920();
#ifndef DEATH_LABEL
            if (D_0028E3C0 != 0) {
                func_00137CC0();
            }
#endif
            D_0028E8C0 = 0xFFFF;
            D_0028E8C4 = 0xFFFF;
        }
    }
    func_001719D0();
    switch (step) {
    case 0x0:
        func_001719A0();
        func_00215DB0(0, 0, 0x1C2, 0xE0, 0x50, 0x80, 0xFF, 0xFF, 0xFF);
        step += 1;
        break;
    default:
        if (step < 16) {
            step += 1;
        }
        break;
    case 0x10:
        D_0028E38C = D_006C91AC[0];
        D_0028E384 = D_006C91AE[0];
        D_0028E388 = D_006C91AD[0];
        D_0028E2EC = D_006C91AF[0];
        D_0028E304 = D_006C91B0[0];
        D_0028E2E4 = D_006C58C4[0];
        func_00236DF0();
        func_00135100();
        step = 0x64;
        break;
    case 0xC8:
        step += 1;
        D_0028E368 = 1;
    case 0xC9:
        func_001719B0();
        if (D_0028E408 == 0) {
            *(u8 *)(reg_a5 + 3) = 2;
        }
        break;
    }
    if (D_006C8E56[0] == 0) {
        switch (step) {
        case 0x64:
            if (D_0028EC58 != 0) {
                step += 1;
#ifdef DEATH_LABEL
                if (D_006E5BEE[0] == 0) {
#else
                if ((D_006E5BEE[0] == 0) && (D_0028E3C0 == 0)) {
#endif
                    func_0018D190();
                }
                func_00135110();
                D_0028ED5C = 0;
                if (D_0028E910 == 0) {
                    memcpy(D_0029F260, D_006C68B6, 0x62);
                    memcpy(D_0029F1F0, D_006C6918, 0x62);
                    D_0029F260[0] = 0;
                    D_0029F1F0[0] = 0;
                } else {
                    D_0028DFC0 = 1;
                }
            }
            break;
        case 0x65:
            if ((D_0028E910 != 0) && (D_0028E8A8 == 0x69) && (D_0028E8AC == 0x140)) {
                memcpy(D_0029F260, D_006C68B6, 0x62);
                memcpy(D_0029F1F0, D_006C6918, 0x62);
                D_0028DFC0 = 0;
                D_0028ED5C = 0;
            }
            if (D_0028E8A8 == 0x38) {
                D_0028E3F0 = 0x11A;
                D_0028E3E4 = 2;
                D_0028E3E0 = 2;
                D_0028E3EC = 0;
                D_0028E3DC = 0xA;
                D_0028E3E8 = 0;
                base = D_006C91A0[0] - 0x11A;
                D_0028E8BC = D_006C8E88[0] - base + 1;
            }
            if ((D_0028E8A8 == D_006C8E90[0]) && (D_0028E8AC == D_006C8E94[0])) {
                D_0028E598 = 1;
                D_0028ED6C = 1;
                step = 0xC8;
#ifndef DEATH_LABEL
                D_0028DEF8 = 1;
#endif
                printf(D_0028BF20, D_0028E8A8);
            }
            break;
        }
    } else {
        switch (step) {
        case 0x64:
            if (D_0028EC58 != 0) {
                step += 1;
            case 0x65:
                if (D_0028E59C == 0) {
                    D_0028ED5C = 0;
                    D_0028ED6C = 1;
#ifndef DEATH_LABEL
                    D_0028DEF8 = 1;
#endif
                    func_00135110();
                    step += 1;
                    printf(D_0028BF20);
                }
            }
            break;
        case 0x66:
            step = 0xC8;
            D_0028E598 = 1;
            break;
        }
    }
    *(u16 *)(reg_a5 + 10) = step;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
}
