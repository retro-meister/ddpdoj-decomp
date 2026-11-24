#include "common.h"

extern void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag);
extern void func_00224BA0(s32 x, s32 y, s32 z, s32 page, s32 bright, s32 alpha, s32 flag, s32 kind);
extern s8 D_002714FE[];
extern u8 *D_002715B0[];
extern s16 D_00271800[];
extern u8 *D_0028DD18[2];
extern s8 D_0028EB18;
extern s8 D_0028EB3C;
extern s32 D_0028EBA4;
extern u8 D_00685010[];
extern s8 D_0068DC10[];
extern u8 *reg_a0;

void func_002207C0(void) {
    s32 i;
    s32 x;
    s32 z;
    s32 alpha;
    s32 y;
    s32 top;
    s32 count;
    s32 index;
    u8 *item;

    count = D_002714FE[0];
    switch (D_0028EB3C) {
    case 0:
        break;
    case 1:
        D_0028EBA4 += 4;
        if (D_0028EBA4 >= 0x80) {
            D_0028EB3C = 0;
            D_0028EBA4 = 0x80;
        }
        break;
    case 2:
        D_0028EBA4 -= 4;
        if (D_0028EBA4 <= 0) {
            D_0028EBA4 = 0;
            D_0028EB3C = 0;
        }
        break;
    }
    for (i = 0; i < count; i++) {
        item = D_00685010 + i * 0x38;
        if (*(s32 *)(item + 0x3134) == 0) {
            continue;
        }
        *(s32 *)(item + 0x312C) = D_0028EBA4;
        reg_a0 = D_002715B0[i];
        x = *(s32 *)(item + 0x3100);
        alpha = *(s32 *)(item + 0x312C);
        top = *(s32 *)(item + 0x3104);
        z = *(s32 *)(item + 0x3130);
        if (alpha == 0) {
            continue;
        }
        glyph_queue_add(x, top, z, 0, 0x80, alpha, 1);
        y = D_00271800[i];
        index = D_0068DC10[0xE0 + i];
        if (i == 4) {
            reg_a0 = D_0028DD18[index];
            glyph_queue_add(x, y + 32, z, 0, 0x80, alpha, 1);
            if (D_0028EB18 == 4) {
                func_00224BA0(x, y + 32, z, 0, 0x80, alpha, 1, 3);
            }
        }
    }
}
