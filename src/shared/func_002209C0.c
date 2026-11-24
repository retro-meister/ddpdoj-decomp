#include "common.h"
#pragma opt_dead_assignments off

extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
extern void func_00224BA0(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag, s32 kind);
void text_queue_glyph(s16 x, s16 y, u16 glyph, s32 w, s32 a4, s32 h, u16 attr, u16 z);
void text_queue_clear(void);
void text_flush(void);
extern s8 D_002714FF[];
extern u8 *D_002715D0[];
extern u8 *D_002716B0[];
extern u8 *D_002716C0[];
extern s16 D_00271800[];
extern u16 D_00271A10[];
extern u8 *D_0028DD48[2];
extern u8 *D_0028DD50[2];
extern u8 *D_0028DD58[2];
extern u8 *D_0028DD60[2];
extern u8 *D_0028DD68[2];
extern u8 D_0028E358;
extern s8 D_0028EB14;
extern s8 D_0028EB38;
extern s32 D_0028EBA0;
extern u8 D_00685010[];
extern s8 D_0068DC10[];
extern s8 D_0068DD09[];
extern s8 D_0068DD0A[];
extern s8 D_0068DD0B[];
extern s8 D_0068DD0D[];
extern s8 D_0068DD0E[];
extern s8 D_0068DD0F[];
extern u8 *reg_a0;

void func_002209C0(void) {
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    u8 *item;
    u16 glyph;

    count = D_002714FF[0];
    switch (D_0028EB38) {
    case 0:
        break;
    case 1:
        D_0028EBA0 += 4;
        if (D_0028EBA0 >= 0x80) {
            D_0028EB38 = 0;
            D_0028EBA0 = 0x80;
        }
        break;
    case 2:
        D_0028EBA0 -= 4;
        if (D_0028EBA0 <= 0) {
            D_0028EBA0 = 0;
            D_0028EB38 = 0;
        }
        break;
    }
    text_queue_clear();
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x34B4) == 0) {
            continue;
        }
        *(s32 *)(item + 0x34AC) = D_0028EBA0;
        reg_a0 = D_002715D0[i];
        x = *(s32 *)(item + 0x3480);
        alpha = *(s32 *)(item + 0x34AC);
        top = *(s32 *)(item + 0x3484);
        z = *(s32 *)(item + 0x34B0);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0xF0 + i];
        if (i == 1) {
            reg_a0 = D_0028DD50[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 1) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 2) {
            if (D_0028E358 == 0) {
                reg_a0 = D_002716B0[index];
            } else {
                reg_a0 = D_0028DD48[index];
            }
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 2) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 3) {
            reg_a0 = D_0028DD58[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 3) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 4) {
            reg_a0 = D_002716C0[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 4) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 5) {
            reg_a0 = D_0028DD60[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 5) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 6) {
            reg_a0 = D_0028DD68[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB14 == 6) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
        if (i == 9) {
            glyph = D_00271A10[D_0068DD09[0]];
            text_queue_glyph(x - 22, y - 4, glyph, 20, 32, 32, alpha, z);
            glyph = D_00271A10[D_0068DD0D[0]];
            text_queue_glyph(x - 22, y + 100, glyph, 20, 32, 32, alpha, z);
        }
        if (i == 10) {
            glyph = D_00271A10[D_0068DD0A[0]];
            text_queue_glyph(x - 22, y - 4, glyph, 20, 32, 32, alpha, z);
            glyph = D_00271A10[D_0068DD0E[0]];
            text_queue_glyph(x - 22, y + 100, glyph, 20, 32, 32, alpha, z);
        }
        if (i == 11) {
            glyph = D_00271A10[D_0068DD0B[0]];
            text_queue_glyph(x - 22, y - 4, glyph, 20, 32, 32, alpha, z);
            glyph = D_00271A10[D_0068DD0F[0]];
            text_queue_glyph(x - 22, y + 100, glyph, 20, 32, 32, alpha, z);
        }
    }
    text_flush();
}
