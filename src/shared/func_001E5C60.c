#include "common.h"

s32 func_00124D90();
s32 func_00124F00();
s32 func_0013A780();
s32 func_0013AB50();
s32 func_0018D4E0();
s32 func_0018D500();
s32 func_0018D560();
s32 func_0018D580();
s32 func_001E58E0();
s32 func_002010A0();
s32 func_002011A0();
s32 func_002012F0();
extern u8 D_0026F260[];
extern u8 D_0026F280[];
extern u8 D_0026F290[];
extern u8 D_0026F2D0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E5C60(void) {
    u16 temp_a0_4;
    u16 temp_a0_5;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;

    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (7)));
    if (temp_a0 != -1) {
        reg_tmp.b[0] = temp_a0;
        (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
            reg_d0.w = 1;
            func_0013A780();
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
            (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x10;
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x102)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x104)));
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) -= 0x200;
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) reg_d0.h[0];
        }
    }
    temp_a0_2 = (*(u8 *)((u8 *)(reg_a4) + (9)));
    if (temp_a0_2 != -1U) {
        reg_tmp.b[0] = temp_a0_2;
        (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            reg_d0.w = 0x10;
            func_0013A780();
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
            (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x10;
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0xC2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0xC4)));
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) -= 0x400;
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) reg_d0.h[0];
            reg_d0.w = 0x10;
            func_0013A780();
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0xC;
            (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x10;
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0xE2)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0xE4)));
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a0) + (0x26))) -= 0x400;
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            (*(u16 *)((u8 *)(reg_a0) + (0x28))) = (u16) reg_d0.h[0];
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) < 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = 0U;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x102)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x104)));
            reg_a1 = (u8 *)D_0026F260;
            func_001E58E0();
            reg_d0.w = 5;
            func_00124F00();
            func_0018D560();
            (*(u16 *)((u8 *)(reg_a4) + (4))) = 8U;
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 1) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) < 0) {
            (*(u8 *)((u8 *)(reg_a4) + (9))) = 0U;
            func_002011A0();
            reg_d1.b[0] = reg_d0.b[0];
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xC2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC4)));
            reg_d3.h[0] = 0x10;
            reg_d0.h[0] = 0;
            func_0013AB50();
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xC2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC4)));
            reg_a1 = (u8 *)D_0026F280;
            func_001E58E0();
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xE2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xE4)));
            reg_a1 = (u8 *)D_0026F280;
            func_001E58E0();
            reg_d0.w = 3;
            func_00124F00();
            reg_d0.w = 4;
            func_00124F00();
            func_0018D4E0();
            (*(u16 *)((u8 *)(reg_a4) + (4))) = 8U;
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
        }
    }
    temp_a0_3 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_3 == 2) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) < 0) {
            func_0018D500();
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
            reg_a1 = (u8 *)D_0026F290;
            func_001E58E0();
            reg_d0.w = 2;
            func_00124F00();
            (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x60U;
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 3U;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 3) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) < 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = 0xFFU;
            (*(u8 *)((u8 *)(reg_a4) + (9))) = 0xFFU;
            func_002010A0();
            reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
            reg_d1.b[0] = reg_d0.b[0];
            reg_d1.b[0] += 0x30;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
            temp_a0_4 = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
            reg_d2.h[0] = temp_a0_4;
            reg_d2.w += 0xF0000400;
            reg_d3.h[0] = 0x10;
            reg_d0.h[0] = 0;
            func_0013AB50();
            func_002010A0();
            reg_d1.b[0] = reg_d0.b[0];
            reg_d1.b[0] += 0xD0;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x62)));
            temp_a0_5 = (*(u16 *)((u8 *)(reg_a6) + (0x64)));
            reg_d2.h[0] = temp_a0_5;
            reg_d2.w += 0xEBFFFC00;
            reg_d3.h[0] = 0x10;
            reg_d0.h[0] = 0;
            func_0013AB50();
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
            reg_a1 = (u8 *)D_0026F2D0;
            func_001E58E0();
            reg_d0.w = 1;
            func_00124F00();
            reg_d0.w = 3;
            func_00124D90();
            func_0018D580();
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
