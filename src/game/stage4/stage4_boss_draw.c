#include "common.h"
#include "entity.h"
#include "stage4_boss.h"

void stage4_boss_piece_0_draw(void);
void stage4_boss_piece_1_draw(void);
void stage4_boss_piece_2_draw(void);
void stage4_boss_piece_3_draw(void);
void stage4_boss_piece_4_draw(void);
void stage4_boss_piece_5_draw(void);
void stage4_boss_piece_6_draw(void);
void stage4_boss_piece_7_draw(void);
void stage4_boss_piece_8_draw(void);
void stage4_boss_piece_9_draw(void);
void stage4_boss_piece_10_draw(void);
void stage4_boss_piece_11_draw(void);

/* The draw routine of every part of the boss, by part number. */
void (*stage4_boss_draw_routines[])(void) = {
    stage4_boss_piece_0_draw,
    stage4_boss_piece_1_draw,
    stage4_boss_piece_2_draw,
    stage4_boss_piece_3_draw,
    stage4_boss_piece_4_draw,
    stage4_boss_piece_5_draw,
    stage4_boss_piece_6_draw,
    stage4_boss_piece_7_draw,
    stage4_boss_piece_8_draw,
    stage4_boss_piece_9_draw,
    stage4_boss_piece_10_draw,
    stage4_boss_piece_11_draw,
    (void (*)(void))-1,
};

void sprite_draw_layer4_keep(void);

void sprite_draw_layer4_keep_entry(void) {
    sprite_draw_layer4_keep();
}

void sprite_draw_layer4_keep_entry_2(void) {
    sprite_draw_layer4_keep();
}

extern u32 D_0026EE10[];

void stage4_boss_piece_0_draw(void) {
    u8 *object = reg_a6;
    u16 *entry;

    reg_a0 = (u8 *)D_0026EE10;
    reg_a0 += *(u16 *)(object + 0x26);
    entry = (u16 *)reg_a0;
    reg_d2.h[1] = entry[0];
    reg_d2.h[0] = entry[1];
    reg_d1.h[1] = *(u16 *)(object + 0x22);
    reg_d1.h[0] = *(u16 *)(object + 0x24);
    reg_d1.w += 0xEE00EE00u;
    reg_d3.h[0] = 0x1290;
    reg_d4.h[0] = *(u16 *)(object + 0x3C);
    *(u8 *)&reg_d4 = object[0x147];
    sprite_draw_layer4_keep_entry();
}

extern u8 D_0026EE30[];

void stage4_boss_piece_6_draw(void) {
    reg_a0 = D_0026EE30;
    reg_a0 += ENTITY(reg_a6)[8].offset_y.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
    reg_d1.w += 0xFC000000;
    reg_d1.w += 0xE600EA00;
    reg_d3.h[0] = 0x1AB0;
    reg_d4.h[0] = ENTITY(reg_a6)[1].attr.h;
    reg_d4.b[0] = STAGE4_PALETTES(reg_a6)->body_a;
    sprite_draw_layer4_keep_entry();
}

extern u8 D_0026EE70[];

void stage4_boss_piece_9_draw(void) {
    u16 temp_a1;
    u16 temp_a1_2;

    reg_a0 = (u8 *)D_0026EE70;
    reg_a0 += ENTITY(reg_a6)[8].offset_y.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
    temp_a1 = ENTITY(reg_a6)[1].x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFE000000;
    reg_d1.w += 0xEC00E300;
    reg_d3.h[0] = 0x14E8;
    reg_d4.h[0] = ENTITY(reg_a6)[1].attr.h;
    reg_d4.b[0] = STAGE4_PALETTES(reg_a6)->body_a;
    sprite_draw_layer4_keep_entry_2();
    reg_d2.w = 0x1D05;
    reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
    temp_a1_2 = ENTITY(reg_a6)[1].x.h;
    reg_d1.h[0] = temp_a1_2;
    reg_d1.w += 0x0D000000;
    reg_d1.w += 0xF600F600;
    reg_d3.h[0] = 0xA50;
    reg_d4.h[0] = ENTITY(reg_a6)[1].attr.h;
    reg_d4.b[0] = STAGE4_PALETTES(reg_a6)->body_a;
    sprite_draw_layer4_keep_entry();
}

extern u8 D_0026EEB0[];

void stage4_boss_piece_1_draw(void) {
    u8 *object = reg_a6;
    u16 *table_entry;

    reg_a0 = D_0026EEB0;
    reg_a0 += *(u16 *)(object + 0x46);
    table_entry = (u16 *)reg_a0;
    reg_d2.h[1] = table_entry[0];
    reg_d2.h[0] = table_entry[1];
    reg_d1.h[1] = *(u16 *)(object + 0x42);
    reg_d1.h[0] = *(u16 *)(object + 0x44);
    reg_d1.w += 0xE800EC00U;
    reg_d3.h[0] = 0x18A0;
    reg_d4.h[0] = *(u16 *)(object + 0x5C);
    *(u8 *)&reg_d4 = object[0x146];
    sprite_draw_layer4_keep_entry();
}

extern u16 D_0026EED0[];

void stage4_boss_piece_2_draw(void) {
    u8 *object = reg_a6;
    u16 *entry;

    reg_a0 = (u8 *)D_0026EED0;
    reg_a0 += *(u16 *)(object + 0x66);
    entry = (u16 *)reg_a0;
    reg_d2.h[1] = entry[0];
    reg_d2.h[0] = entry[1];
    reg_d1.h[1] = *(u16 *)(object + 0x62);
    reg_d1.h[0] = *(u16 *)(object + 0x64);
    reg_d1.w += 0xF600FA00u;
    reg_d3.h[0] = 0x0A30;
    reg_d4.h[0] = *(u16 *)(object + 0x7C);
    *(u8 *)&reg_d4 = object[0x149];
    sprite_draw_layer4_keep_entry();
}

extern u8 D_0026EEF0[];

void stage4_boss_piece_3_draw(void) {
    reg_a0 = D_0026EEF0;
    reg_d0.h[0] = ENTITY(reg_a6)[6].offset_y.h;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[6].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[6].x.h;
    reg_d1.w += 0xF800FA00;
    reg_d3.h[0] = 0x830;
    reg_d4.h[0] = ENTITY(reg_a6)[6].attr.h;
    reg_d4.b[0] = STAGE4_PALETTES(reg_a6)->right_spinner;
    sprite_draw_layer4_keep_entry();
}

void stage4_boss_piece_4_draw(void) {
    reg_a0 = D_0026EEF0;
    reg_d0.h[0] = ENTITY(reg_a6)[7].offset_y.h;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[7].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[7].x.h;
    reg_d1.w += 0xF800FA00;
    reg_d3.h[0] = 0x830;
    reg_d4.h[0] = ENTITY(reg_a6)[7].attr.h;
    reg_d4.b[0] = STAGE4_PALETTES(reg_a6)->left_spinner;
    sprite_draw_layer4_keep_entry();
}

extern u16 D_0026EF50[];

void stage4_boss_piece_5_draw(void) {
    u16 temp_a1;
    reg_d0.w = 0;
    reg_a0 = (u8 *)(D_0026EF50);
    reg_d0.b[0] = ENTITY(reg_a6)[8].move.b.dir;
    reg_d0.b[0] += 1;
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = ENTITY(reg_a6)[8].y.h;
    temp_a1 = ENTITY(reg_a6)[8].x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FB00;
    reg_d3.h[0] = 0x628;
    reg_d4.h[0] = ENTITY(reg_a6)[8].attr.h;
    reg_d4.b[0] = STAGE4_PALETTES(reg_a6)->gun;
    sprite_draw_layer4_keep_entry();
}

s32 sprite_draw_layer2();
extern u8 D_0026EFD0[];
extern u8 D_0026EFF0[];

void stage4_boss_piece_7_draw(void) {
    u16 temp_a0;
    u16 temp_a1;

    reg_a0 = (u8 *)D_0026EFD0;
    reg_a0 += ENTITY(reg_a6)[4].offset_y.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[4].y.h;
    temp_a0 = ENTITY(reg_a6)[4].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF000F800;
    reg_d3.h[0] = 0x1040;
    reg_d4.h[0] = ENTITY(reg_a6)[4].attr.h;
    reg_d4.b[0] = STAGE4_PALETTES(reg_a6)->right_pod;
    sprite_draw_layer2();
    reg_a0 = (u8 *)D_0026EFF0;
    reg_a0 += ENTITY(reg_a6)[4].offset_x.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[4].y.h;
    temp_a1 = ENTITY(reg_a6)[4].x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FC00;
    reg_d1.w += 0xF9400200;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = ENTITY(reg_a6)[4].attr.h;
    reg_d4.b[0] = STAGE4_PALETTES(reg_a6)->right_pod;
    sprite_draw_layer2();
}

extern u8 D_0026F020[];

void stage4_boss_piece_8_draw(void) {
    u16 temp_a0;
    u16 temp_a1;

    reg_a0 = (u8 *)D_0026F020;
    reg_a0 += ENTITY(reg_a6)[5].offset_y.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[5].y.h;
    temp_a0 = ENTITY(reg_a6)[5].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF000F800;
    reg_d3.h[0] = 0x1040;
    reg_d4.h[0] = ENTITY(reg_a6)[5].attr.h;
    reg_d4.b[0] = STAGE4_PALETTES(reg_a6)->left_pod;
    sprite_draw_layer2();
    reg_a0 = (u8 *)D_0026EFF0;
    reg_a0 += ENTITY(reg_a6)[5].offset_x.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)[5].y.h;
    temp_a1 = ENTITY(reg_a6)[5].x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FC00;
    reg_d1.w += 0xF93FFE40;
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = ENTITY(reg_a6)[5].attr.h;
    reg_d4.b[0] = STAGE4_PALETTES(reg_a6)->right_pod;
    sprite_draw_layer2();
}

extern void sprite_draw_layer5(void);
extern u32 D_0026F040[];

void stage4_boss_piece_10_draw(void) {
    u8 *entity = reg_a6;
    u16 *tableEntry;

    reg_a0 = (u8 *)D_0026F040;
    reg_a0 += *(u16 *)(entity + 0x126);
    tableEntry = (u16 *)reg_a0;
    reg_d2.h[1] = tableEntry[0];
    reg_d2.h[0] = tableEntry[1];
    reg_d1.h[1] = *(u16 *)(entity + 0x122);
    reg_d1.h[0] = *(u16 *)(entity + 0x124);
    reg_d1.w += 0xD800E800U;
    reg_d3.h[0] = 0x28C0;
    reg_d4.w = 0x15;
    sprite_draw_layer5();
}

extern u8 D_0026F080[];

void stage4_boss_piece_11_draw(void) {
    u8 *entity = reg_a6;
    u16 *tableEntry;

    reg_a0 = D_0026F080;
    reg_a0 += *(u16 *)(entity + 0x128);
    tableEntry = (u16 *)reg_a0;
    reg_d2.h[1] = tableEntry[0];
    reg_d2.h[0] = tableEntry[1];
    reg_d1.h[1] = *(u16 *)(entity + 0x122);
    reg_d1.h[0] = *(u16 *)(entity + 0x124);
    reg_d1.w += 0xDC00EE00U;
    reg_d3.h[0] = 0x2490;
    reg_d4.w = 0x15;
    sprite_draw_layer5();
}

u32 D_0026EE10[8] = {
    0x1CD50000, 0x1CD60000, 0x1CD70000, 0x1CD80000, 0x1CD90000, 0x1CDA0000, 0x1CDB0000, 0x1CDC0000,
};

u8 D_0026EE30[64] = {
    0x00, 0x00, 0xF6, 0x1C, 0x00, 0x00, 0xF7, 0x1C, 0x00, 0x00, 0xF8, 0x1C, 0x00, 0x00, 0xF9, 0x1C,
    0x00, 0x00, 0xFA, 0x1C, 0x00, 0x00, 0xFB, 0x1C, 0x00, 0x00, 0xFC, 0x1C, 0x00, 0x00, 0xFD, 0x1C,
    0x00, 0x00, 0xFE, 0x1C, 0x00, 0x00, 0xFF, 0x1C, 0x00, 0x00, 0x00, 0x1D, 0x00, 0x00, 0x01, 0x1D,
    0x00, 0x00, 0x02, 0x1D, 0x00, 0x00, 0x03, 0x1D, 0x00, 0x00, 0x04, 0x1D, 0x00, 0x00, 0x00, 0x00,
};

u8 D_0026EE70[64] = {
    0x00, 0x00, 0x19, 0x1D, 0x00, 0x00, 0x1A, 0x1D, 0x00, 0x00, 0x1B, 0x1D, 0x00, 0x00, 0x1C, 0x1D,
    0x00, 0x00, 0x1D, 0x1D, 0x00, 0x00, 0x1E, 0x1D, 0x00, 0x00, 0x1F, 0x1D, 0x00, 0x00, 0x20, 0x1D,
    0x00, 0x00, 0x21, 0x1D, 0x00, 0x00, 0x22, 0x1D, 0x00, 0x00, 0x23, 0x1D, 0x00, 0x00, 0x24, 0x1D,
    0x00, 0x00, 0x25, 0x1D, 0x00, 0x00, 0x26, 0x1D, 0x00, 0x00, 0x27, 0x1D, 0x00, 0x00, 0x28, 0x1D,
};

u8 D_0026EEB0[32] = {
    0x00, 0x00, 0xDD, 0x1C, 0x00, 0x00, 0xDE, 0x1C, 0x00, 0x00, 0xDF, 0x1C, 0x00, 0x00, 0xE0, 0x1C,
    0x00, 0x00, 0xE1, 0x1C, 0x00, 0x00, 0xE2, 0x1C, 0x00, 0x00, 0xE3, 0x1C, 0x00, 0x00, 0xE4, 0x1C,
};

u16 D_0026EED0[16] = {
    0x0000, 0x1CE5, 0x0000, 0x1CE6, 0x0000, 0x1CE7, 0x0000, 0x1CE8,
    0x0000, 0x1CE9, 0x0000, 0x1CEA, 0x0000, 0x1CEB, 0x0000, 0x1CEC,
};

u8 D_0026EEF0[96] = {
    0x00, 0x00, 0xEE, 0x1C, 0x00, 0x00, 0xEF, 0x1C, 0x00, 0x00, 0xF0, 0x1C, 0x00, 0x00, 0xF1, 0x1C,
    0x00, 0x00, 0xF2, 0x1C, 0x00, 0x00, 0xF3, 0x1C, 0x00, 0x00, 0xF4, 0x1C, 0x00, 0x00, 0xF5, 0x1C,
    0x00, 0x00, 0xEE, 0x1C, 0x00, 0x00, 0xEF, 0x1C, 0x00, 0x00, 0xF0, 0x1C, 0x00, 0x00, 0xF1, 0x1C,
    0x00, 0x00, 0xF2, 0x1C, 0x00, 0x00, 0xF3, 0x1C, 0x00, 0x00, 0xF4, 0x1C, 0x00, 0x00, 0xF5, 0x1C,
    0x00, 0x00, 0xEE, 0x1C, 0x00, 0x00, 0xEF, 0x1C, 0x00, 0x00, 0xF0, 0x1C, 0x00, 0x00, 0xF1, 0x1C,
    0x00, 0x00, 0xF2, 0x1C, 0x00, 0x00, 0xF3, 0x1C, 0x00, 0x00, 0xF4, 0x1C, 0x00, 0x00, 0xF5, 0x1C,
};

u16 D_0026EF50[64] = {
    0x0000, 0x1D4A, 0x0000, 0x1D4B, 0x0000, 0x1D4C, 0x0000, 0x1D4D,
    0x0000, 0x1D4E, 0x0000, 0x1D4F, 0x0000, 0x1D50, 0x0000, 0x1D51,
    0x0000, 0x1D52, 0x0000, 0x1D53, 0x0000, 0x1D54, 0x0000, 0x1D55,
    0x0000, 0x1D56, 0x0000, 0x1D57, 0x0000, 0x1D58, 0x0000, 0x1D59,
    0x0000, 0x1D5A, 0x0000, 0x1D5B, 0x0000, 0x1D5C, 0x0000, 0x1D5D,
    0x0000, 0x1D5E, 0x0000, 0x1D5F, 0x0000, 0x1D60, 0x0000, 0x1D61,
    0x0000, 0x1D62, 0x0000, 0x1D63, 0x0000, 0x1D64, 0x0000, 0x1D65,
    0x0000, 0x1D66, 0x0000, 0x1D67, 0x0000, 0x1D68, 0x0000, 0x1D69,
};

u8 D_0026EFD0[32] = {
    0x00, 0x00, 0x29, 0x1D, 0x00, 0x00, 0x2A, 0x1D, 0x00, 0x00, 0x2B, 0x1D, 0x00, 0x00, 0x2C, 0x1D,
    0x00, 0x00, 0x2D, 0x1D, 0x00, 0x00, 0x2E, 0x1D, 0x00, 0x00, 0x2F, 0x1D, 0x00, 0x00, 0x30, 0x1D,
};

u8 D_0026EFF0[48] = {
    0x00, 0x00, 0x39, 0x1D, 0x00, 0x00, 0x3A, 0x1D, 0x00, 0x00, 0x3B, 0x1D, 0x00, 0x00, 0x3C, 0x1D,
    0x00, 0x00, 0x3D, 0x1D, 0x00, 0x00, 0x3E, 0x1D, 0x00, 0x00, 0x3F, 0x1D, 0x00, 0x00, 0x40, 0x1D,
    0x00, 0x00, 0x41, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 D_0026F020[32] = {
    0x00, 0x00, 0x31, 0x1D, 0x00, 0x00, 0x32, 0x1D, 0x00, 0x00, 0x33, 0x1D, 0x00, 0x00, 0x34, 0x1D,
    0x00, 0x00, 0x35, 0x1D, 0x00, 0x00, 0x36, 0x1D, 0x00, 0x00, 0x37, 0x1D, 0x00, 0x00, 0x38, 0x1D,
};

u32 D_0026F040[16] = {
    0x1D6A0000, 0x1D6B0000, 0x1D6C0000, 0x1D6D0000, 0x1D6E0000, 0x1D6F0000, 0x1D700000, 0x1D710000,
    0x1D720000, 0x1D730000, 0x1D740000, 0x1D750000, 0x1D760000, 0x1D770000, 0x1D780000, 0x1D790000,
};

u8 D_0026F080[32] = {
    0x00, 0x00, 0x7A, 0x1D, 0x00, 0x00, 0x7B, 0x1D, 0x00, 0x00, 0x7C, 0x1D, 0x00, 0x00, 0x7D, 0x1D,
    0x00, 0x00, 0x7E, 0x1D, 0x00, 0x00, 0x7F, 0x1D, 0x00, 0x00, 0x80, 0x1D, 0x00, 0x00, 0x81, 0x1D,
};
