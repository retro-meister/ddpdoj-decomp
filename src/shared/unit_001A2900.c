#include "common.h"

extern s16 D_0028E0AC_as_s16;
extern s16 D_0028E0B0_as_s16;
extern s16 D_0028E0B4_as_s16;
extern s16 D_0028E0B8;
extern s16 D_0028E0BC;
extern s16 D_0028E0C0;
extern u8 D_0029F2D0[];
extern u8 D_0029F4B0[];
extern u8 D_0029FCB0[];
void func_001A2900(void) {
    s32 var_a1;
    u8 *temp_a2;
    s32 var_a2;
    s32 var_a3;
    s32 var_a3_2;
    u8 *temp_t0;
    u8 *temp_t1;

    var_a2 = 0;
    var_a3 = 0;
    do {
        temp_t0 = (u8 *)(D_0029FCB0 + var_a3);
        temp_t1 = (u8 *)(D_0029F4B0 + var_a3);
        (*(s16 *)((u8 *)(temp_t0) + (0))) = 0;
        var_a2 += 8;
        (*(s16 *)((u8 *)(temp_t1) + (0))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (2))) = 0;
        var_a3 += 0x10;
        (*(s16 *)((u8 *)(temp_t1) + (2))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (4))) = 0;
        (*(s16 *)((u8 *)(temp_t1) + (4))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (6))) = 0;
        (*(s16 *)((u8 *)(temp_t1) + (6))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (8))) = 0;
        (*(s16 *)((u8 *)(temp_t1) + (8))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (0xA))) = 0;
        (*(s16 *)((u8 *)(temp_t1) + (0xA))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (0xC))) = 0;
        (*(s16 *)((u8 *)(temp_t1) + (0xC))) = 0;
        (*(s16 *)((u8 *)(temp_t0) + (0xE))) = 0;
        (*(s16 *)((u8 *)(temp_t1) + (0xE))) = 0;
    } while (var_a2 < 0x400);
    var_a3_2 = 0;
    var_a1 = 0;
    do {
        temp_a2 = (u8 *)(D_0029F2D0 + var_a1);
        var_a3_2 += 8;
        (*(s16 *)((u8 *)(temp_a2) + (0))) = 0;
        (*(s16 *)((u8 *)(temp_a2) + (2))) = 0;
        var_a1 += 0x10;
        (*(s16 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s16 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s16 *)((u8 *)(temp_a2) + (8))) = 0;
        (*(s16 *)((u8 *)(temp_a2) + (0xA))) = 0;
        (*(s16 *)((u8 *)(temp_a2) + (0xC))) = 0;
        (*(s16 *)((u8 *)(temp_a2) + (0xE))) = 0;
    } while (var_a3_2 < 0xF0);
    D_0028E0C0 = 0;
    D_0028E0AC_as_s16 = 0x101;
    D_0028E0BC = 0;
    D_0028E0B0_as_s16 = 1;
    D_0028E0B8 = 0;
    D_0028E0B4_as_s16 = 0x20;
}

extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;

void func_001A29E0(void) {
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
    *reg_a1_as_u16_p = *reg_a0_as_u16_p;
    reg_a0_as_u16_p += 1;
    reg_a1_as_u16_p += 1;
}

void func_001A2C70(void) {
}

s32 func_0013AFF0();
s32 text_palette_upload();
s32 sprite_palette_upload();
s32 bg_palette_upload();
extern u8 D_0028E0AC;
extern u8 D_0028E0AD;
extern u16 D_0028E0B0;
extern u16 D_0028E0B4;
extern u16 D_0028E0B8_as_u16;
extern u16 D_0028E0BC_as_u16;
extern u16 D_0028E0C0_as_u16;
extern s16 D_0028E8A8_as_s16;
extern u16 g_stage;
extern u8 g_text_palette_as_u8_a[];
extern u8 g_bg_palette[];
extern u8 g_sprite_palette[];

void func_001A2C80(void) {
    if (D_0028E0C0_as_u16 != 0) {
        reg_a0 = (u8 *)D_0029FCB0;
        reg_a1 = (u8 *)g_sprite_palette;
        reg_d0.w = 0x1F;
        do {
            func_001A29E0();
            func_001A29E0();
        } while ((s16)(--reg_d0.h[0]) >= 0);
        D_0028E0C0_as_u16 = 0;
        func_001A2C70();
        sprite_palette_upload();
    }
    if (D_0028E0BC_as_u16 != 0) {
        reg_a0 = (u8 *)D_0029F4B0;
        reg_a1 = (u8 *)g_bg_palette;
        reg_d0.w = 0x1F;
        do {
            func_001A29E0();
            func_001A29E0();
        } while ((s16)(--reg_d0.h[0]) >= 0);
        D_0028E0BC_as_u16 = 0;
        func_001A2C70();
        bg_palette_upload();
    }
    if (D_0028E0B8_as_u16 != 0) {
        reg_a0 = (u8 *)D_0029F2D0;
        reg_a1 = (u8 *)g_text_palette_as_u8_a;
        reg_d0.w = 0xE;
        do {
            func_001A29E0();
        } while ((s16)(--reg_d0.h[0]) >= 0);
        D_0028E0B8_as_u16 = 0;
        func_001A2C70();
        text_palette_upload();
    }
    if ((g_stage == 0) && (D_0028E8A8_as_s16 < 0x130)) {
        reg_a1 = (u8 *)g_bg_palette;
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
        bg_palette_upload();
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

extern u32 reg_a0_as_u32;
extern u32 reg_a1_as_u32;

void func_001A2F20(void)
{
    do {
        *(u16 *)reg_a1_as_u32 = *(u16 *)reg_a0_as_u32;
        reg_a0_as_u32 += 2;
        reg_a1_as_u32 += 2;

        *(u16 *)reg_a1_as_u32 = *(u16 *)reg_a0_as_u32;
        reg_a0_as_u32 += 2;
        reg_a1_as_u32 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern s32 reg_a0_as_s32;

void func_001A2FA0(void) {
    u32 temp_s0 = reg_d0.w;
    s32 temp_s1 = reg_a0_as_s32;
    u8 *temp_s2 = reg_a1;

    reg_a1 = D_0029F2D0;
    reg_d0.h[0] <<= 5;
    reg_a1 += reg_d0.h[0];
    reg_d0.w = 7;
    func_001A2F20();
    reg_d0.w = temp_s0;
    D_0028E0B8 = 1;
    reg_a0_as_s32 = temp_s1;
    reg_a1 = temp_s2;
}

void func_001A3020(void) {
    u32 temp_s0 = reg_d0.w;
    s32 temp_s1 = reg_a0_as_s32;
    u8 *temp_s2 = reg_a1;

    reg_a1 = D_0029FCB0;
    reg_d0.h[0] <<= 6;
    reg_a1 += reg_d0.h[0];
    reg_d0.w = 0xF;
    func_001A2F20();
    reg_d0.w = temp_s0;
    D_0028E0C0 = 1;
    reg_a0_as_s32 = temp_s1;
    reg_a1 = temp_s2;
}
