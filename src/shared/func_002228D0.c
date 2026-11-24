#include "common.h"

void text_queue_sjis(s16 x, s16 y, u8 *text, s32 a3, s32 w, s32 h, u16 attr, s32 z);
void text_queue_glyph(s16 x, s16 y, s32 glyph, s32 w, s32 a4, s32 h, u16 attr, s32 z);
void text_queue_ascii(s16 x, s16 y, u8 *text, s32 a3, s32 w, s32 h, u16 attr, s32 z);
extern s8 *reg_a0_as_s8_p;
extern u16 D_0028E3F0;
extern s32 D_0028EB90;

void func_002228D0(s32 x, s32 y) {
    u8 buf[4];
    s32 n;
    s32 single;
    s32 i;
    s32 cx;
    s32 cy;

    cy = y;
    cx = x;
    for (i = 0; i < 0x100; i++) {
        buf[0] = *reg_a0_as_s8_p;
        reg_a0_as_s8_p++;
        if (buf[0] < 0x81) {
            buf[1] = 0;
            single = 1;
        } else {
            single = 0;
            buf[1] = *reg_a0_as_s8_p;
            reg_a0_as_s8_p++;
        }
        *(u16 *)&buf[2] = 0;
        switch (*(u16 *)buf) {
        case 0x5E81:
            cx -= 0x14;
            cy = y;
            break;
        case 0x8F81:
            return;
        case 0x6781:
            text_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
            cy += 0xC;
            break;
        case 0x6881:
            text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
            cy += 0xC;
            break;
        case 0x6981:
            text_queue_sjis(cx, cy - 4, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
            cy += 0xC;
            break;
        case 0x6A81:
            text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
            cy += 0xC;
            break;
        case 0x9B81:
            text_queue_glyph(cx - 0x10, cy + 2, 0x227C, 0x14, 0x26, 0x14, D_0028EB90, 0x12C);
            cy += 0x10;
            break;
        case 0x7E81:
            text_queue_glyph(cx - 0x10, cy + 2, 0x227D, 0x14, 0x26, 0x14, D_0028EB90, 0x12C);
            cy += 0x10;
            break;
        case 0x9781:
            buf[0] = 0x81;
            buf[1] = 0x44;
            for (n = (D_0028E3F0 >> 5) & 3; n > 0; n--) {
                text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
                cy += 5;
            }
            return;
        default:
            if (single != 0) {
                text_queue_ascii(cx, cy, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
                cy += 8;
            } else {
                text_queue_sjis(cx, cy, buf, 0, 0x14, 0x10, D_0028EB90, 0x12C);
                cy += 0x10;
            }
            break;
        }
    }
}
