#include "common.h"

extern u8 D_0028E0AC;
extern u16 D_0028E0B0;
extern u16 D_0028E0B4;
extern s16 fade_areas_5;
extern s16 fade_areas_3;
extern s16 fade_areas_1;
extern u8 fade_areas_4[];
extern u8 g_palette_bank_a[];
extern u8 g_palette_bank_b[];
void palettes_init(void) {
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
        temp_t0 = (u8 *)(g_palette_bank_b + var_a3);
        temp_t1 = (u8 *)(g_palette_bank_a + var_a3);
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
        temp_a2 = (u8 *)(fade_areas_4 + var_a1);
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
    fade_areas_1 = 0;
    (*(s16 *)&D_0028E0AC) = 0x101;
    fade_areas_3 = 0;
    D_0028E0B0 = 1;
    fade_areas_5 = 0;
    D_0028E0B4 = 0x20;
}


void palette_words_copy(void) {
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
    *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
    (*(u16 **)&reg_a0) += 1;
    (*(u16 **)&reg_a1) += 1;
}

void palette_flush_unused(void) {
}

s32 color_at_brightness();
s32 text_palette_upload();
s32 sprite_palette_upload();
s32 bg_palette_upload();
extern u8 D_0028E0AC;
extern u8 palette_banks_flush_state;
extern u16 D_0028E0B0;
extern u16 D_0028E0B4;
extern u16 g_scroll_line;
extern u16 g_stage;
extern s32 g_text_palette[128];
extern u8 g_bg_palette[];
extern u8 g_sprite_palette[];

void palette_banks_flush(void) {
    if ((u16)fade_areas_1 != 0) {
        reg_a0 = (u8 *)g_palette_bank_b;
        reg_a1 = (u8 *)g_sprite_palette;
        reg_d0.w = 0x1F;
        do {
            palette_words_copy();
            palette_words_copy();
        } while ((s16)(--reg_d0.h[0]) >= 0);
        fade_areas_1 = 0;
        palette_flush_unused();
        sprite_palette_upload();
    }
    if ((u16)fade_areas_3 != 0) {
        reg_a0 = (u8 *)g_palette_bank_a;
        reg_a1 = (u8 *)g_bg_palette;
        reg_d0.w = 0x1F;
        do {
            palette_words_copy();
            palette_words_copy();
        } while ((s16)(--reg_d0.h[0]) >= 0);
        fade_areas_3 = 0;
        palette_flush_unused();
        bg_palette_upload();
    }
    if ((u16)fade_areas_5 != 0) {
        reg_a0 = (u8 *)fade_areas_4;
        reg_a1 = (u8 *)((u8 *)g_text_palette);
        reg_d0.w = 0xE;
        do {
            palette_words_copy();
        } while ((s16)(--reg_d0.h[0]) >= 0);
        fade_areas_5 = 0;
        palette_flush_unused();
        text_palette_upload();
    }
    if ((g_stage == 0) && ((s16)g_scroll_line < 0x130)) {
        reg_a1 = (u8 *)g_bg_palette;
        reg_a0 = (u8 *)g_palette_bank_a;
        reg_a1 += 0x540;
        reg_a0 += 0x540;
        reg_d1.h[0] = D_0028E0B4;
        reg_d0.h[0] = *(u16 *)(reg_a0 + 6);
        color_at_brightness();
        *(u16 *)(reg_a1 + 6) = (u16) reg_d0.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a0 + 4);
        color_at_brightness();
        *(u16 *)(reg_a1 + 4) = (u16) reg_d0.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a0 + 2);
        color_at_brightness();
        *(u16 *)(reg_a1 + 2) = (u16) reg_d0.h[0];
        reg_d0.h[0] = *(u16 *)reg_a0;
        color_at_brightness();
        *(u16 *)reg_a1 = (u16) reg_d0.h[0];
        bg_palette_upload();
        reg_tmp.b[0] = palette_banks_flush_state;
        palette_banks_flush_state -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            reg_d0.h[0] = D_0028E0B0;
            palette_banks_flush_state = D_0028E0AC;
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


void palette_run_copy(void)
{
    do {
        *(u16 *)(*(u32 *)&reg_a1) = *(u16 *)(*(u32 *)&reg_a0);
        (*(u32 *)&reg_a0) += 2;
        (*(u32 *)&reg_a1) += 2;

        *(u16 *)(*(u32 *)&reg_a1) = *(u16 *)(*(u32 *)&reg_a0);
        (*(u32 *)&reg_a0) += 2;
        (*(u32 *)&reg_a1) += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}


void text_palette_load(void) {
    u32 temp_s0 = reg_d0.w;
    s32 temp_s1 = (s32)reg_a0;
    u8 *temp_s2 = reg_a1;

    reg_a1 = fade_areas_4;
    reg_d0.h[0] <<= 5;
    reg_a1 += reg_d0.h[0];
    reg_d0.w = 7;
    palette_run_copy();
    reg_d0.w = temp_s0;
    fade_areas_5 = 1;
    reg_a0 = (u8 *)temp_s1;
    reg_a1 = temp_s2;
}

void sprite_palette_load(void) {
    u32 temp_s0 = reg_d0.w;
    s32 temp_s1 = (s32)reg_a0;
    u8 *temp_s2 = reg_a1;

    reg_a1 = g_palette_bank_b;
    reg_d0.h[0] <<= 6;
    reg_a1 += reg_d0.h[0];
    reg_d0.w = 0xF;
    palette_run_copy();
    reg_d0.w = temp_s0;
    fade_areas_1 = 1;
    reg_a0 = (u8 *)temp_s1;
    reg_a1 = temp_s2;
}

/* .sbss (the compiler lays these out in reverse) */
s16 fade_areas_1 __attribute__((aligned(4)));
s16 fade_areas_3 __attribute__((aligned(4)));
s16 fade_areas_5 __attribute__((aligned(4)));
u16 D_0028E0B4 __attribute__((aligned(4)));
u16 D_0028E0B0 __attribute__((aligned(4)));
u8 palette_banks_flush_state;
u8 D_0028E0AC __attribute__((aligned(4)));

/* .bss (the compiler lays these out in reverse) */
u8 g_palette_bank_b[2048];
u8 g_palette_bank_a[2048];
u8 fade_areas_4[480];
