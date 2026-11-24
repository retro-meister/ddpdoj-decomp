#include "common.h"

extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
extern void func_00224BA0(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag, s32 kind);
extern s8 D_002714F2[];
extern u8 *D_00271560[];
extern s16 D_00271800[];
extern u8 *D_0028DD18[2];
extern s8 D_0028EB20;
extern s8 D_0028EB44;
extern s32 D_0028EBAC;
extern u8 D_00685010[];
extern s8 D_0068DC10[];
extern u8 *reg_a0;

void func_002201A0(void) {
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    u8 *item;

    count = D_002714F2[0];
    switch (D_0028EB44) {
    case 0:
        break;
    case 1:
        D_0028EBAC += 4;
        if (D_0028EBAC >= 0x80) {
            D_0028EB44 = 0;
            D_0028EBAC = 0x80;
        }
        break;
    case 2:
        D_0028EBAC -= 4;
        if (D_0028EBAC <= 0) {
            D_0028EBAC = 0;
            D_0028EB44 = 0;
        }
        break;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x734) == 0) {
            continue;
        }
        *(s32 *)(item + 0x72C) = D_0028EBAC;
        reg_a0 = D_00271560[i];
        x = *(s32 *)(item + 0x700);
        alpha = *(s32 *)(item + 0x72C);
        top = *(s32 *)(item + 0x704);
        z = *(s32 *)(item + 0x730);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0x20 + i];
        if (i == 3) {
            reg_a0 = D_0028DD18[index];
            glyph_queue_add(x, y + 16, z, 0, 0x80, alpha, 1);
            if (D_0028EB20 == 3) {
                func_00224BA0(x, y + 16, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
}
