#include "common.h"
#include "arcade_gameplay.h"
#include "entity.h"
#include "stage3_boss.h"

void stage3_boss_legs_draw(void);
void stage3_boss_body_draw(void);
void stage3_boss_bar_left_draw(void);
void stage3_boss_bar_right_draw(void);
void stage3_boss_lid_left_draw(void);
void stage3_boss_lid_right_draw(void);
void stage3_boss_turret_left_draw(void);
void stage3_boss_turret_right_draw(void);
void stage3_boss_six_gun_draw(void);
void stage3_boss_entrance_draw(void);

/* The draw routine of every part of the boss, by part number. */
void (*stage3_boss_draw_routines[])(void) = {
    stage3_boss_legs_draw,
    stage3_boss_body_draw,
    stage3_boss_bar_left_draw,
    stage3_boss_bar_right_draw,
    stage3_boss_lid_left_draw,
    stage3_boss_lid_right_draw,
    stage3_boss_turret_left_draw,
    stage3_boss_turret_right_draw,
    stage3_boss_six_gun_draw,
    stage3_boss_entrance_draw,
    (void (*)(void))-1,
};

extern u8 stage3_boss_legs_draw_table[];

void stage3_boss_legs_draw(void) {
    u16 temp_a1;
    u16 temp_a3;

    reg_a0 = (u8 *)stage3_boss_legs_draw_table;
    temp_a3 = STAGE3_EXTRA(reg_a6)->legs_anim;
    reg_a0 += temp_a3;
    reg_tmp.h[0] = STAGE3_EXTRA(reg_a6)->legs_anim;
    reg_d2.w = *(u32 *)(stage3_boss_legs_draw_table + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xE4400000;
    reg_d1.w += 0xEC00E800;
    reg_d3.h[0] = 0x14C0;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = STAGE3_PALETTES(reg_a6)->legs;
    sprite_draw_layer2_keep();
}


void stage3_boss_body_draw(void)
{
    u8 *object = reg_a6;

    reg_d2.w = 0x1BFA;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.w = reg_d1.w + 0xDE00EC00U;
    reg_d3.h[0] = 0x22A0;
    reg_d4.h[0] = *(u16 *)(object + 0x1C);
    *(u8 *)&reg_d4 = object[0x67];
    sprite_draw_layer2_keep();
}

extern u8 D_0026D360[];

void stage3_boss_bar_left_draw(void) {
    reg_a0 = (u8 *)D_0026D360;
    reg_a0 += *(u16 *) (reg_a6 + 0xAA);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0xAA);
    reg_d2.w = *(u32 *) (D_0026D360 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.h[1] += 0x4C0;
    reg_d1.h[0] += 0xF600;
    reg_d1.w += 0xF000FC00;
    reg_d3.h[0] = 0x1020;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE3_PALETTES(reg_a6)->drone;
    sprite_draw_layer2_keep();
}

void stage3_boss_bar_right_draw(void) {
    reg_a0 = (u8 *)D_0026D360;
    reg_a0 += *(u16 *) (reg_a6 + 0xAC);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0xAC);
    reg_d2.w = *(u32 *) (D_0026D360 + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.h[1] += 0x4C0;
    reg_d1.h[0] += 0xA00;
    reg_d1.w += 0xF000FC00;
    reg_d3.h[0] = 0x1020;
    reg_d4.h[0] = 0x4000;
    reg_d4.b[0] = STAGE3_PALETTES(reg_a6)->drone;
    sprite_draw_layer2_keep();
}

extern u8 stage3_boss_lid_left_draw_table[];

void stage3_boss_lid_left_draw(void) {
    u16 temp_a0;
    u16 temp_a2;

    reg_a0 = stage3_boss_lid_left_draw_table;
    temp_a2 = STAGE3_EXTRA(reg_a6)->lid_anim;
    reg_a0 += temp_a2;
    reg_tmp.h[0] = STAGE3_EXTRA(reg_a6)->lid_anim;
    reg_d2.w = *(u32 *)(stage3_boss_lid_left_draw_table + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)[1].y.h;
    temp_a0 = ENTITY(reg_a6)[1].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xE400F700;
    reg_d3.h[0] = 0x1C48;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE3_PALETTES(reg_a6)->lid;
    sprite_draw_layer2_keep();
}

extern u8 stage3_boss_lid_right_draw_table[];

void stage3_boss_lid_right_draw(void) {
    u16 temp_a0;
    u16 temp_a2;

    reg_a0 = stage3_boss_lid_right_draw_table;
    temp_a2 = STAGE3_EXTRA(reg_a6)->lid_anim;
    reg_a0 += temp_a2;
    reg_tmp.h[0] = STAGE3_EXTRA(reg_a6)->lid_anim;
    reg_d2.w = *(u32 *)(stage3_boss_lid_right_draw_table + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = ENTITY(reg_a6)[2].y.h;
    temp_a0 = ENTITY(reg_a6)[2].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xE400F700;
    reg_d3.h[0] = 0x1C48;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE3_PALETTES(reg_a6)->lid;
    sprite_draw_layer2_keep();
}

extern u8 stage3_boss_six_gun_draw_table[];

void stage3_boss_six_gun_draw(void) {
    reg_a0 = (u8 *)stage3_boss_six_gun_draw_table;
    reg_a0 += *(u16 *) (reg_a6 + 0xA8);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0xA8);
    reg_d2.w = *(u32 *) (stage3_boss_six_gun_draw_table + (reg_tmp.h[0] & ~3));
    reg_d1.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.w += 0xF6400000;
    reg_d1.w += 0xF600F400;
    reg_d3.h[0] = 0xA60;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE3_PALETTES(reg_a6)->lid;
    sprite_draw_layer2_keep();
}

extern u16 g_direction_sprites_c[];

void stage3_boss_turret_left_draw(void) {
    u16 temp_a0;
    reg_d2.h[0] = STAGE3_EXTRA(reg_a6)->left_turret_direction;
    reg_a0 = (u8 *)(g_direction_sprites_c);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_tmp2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp2.h[0] = (((reg_d2.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d2.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = reg_tmp2.w;
    reg_d1.h[0] = ENTITY(reg_a6)[1].y.h;
    reg_d1.h[0] += 0xD00;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    temp_a0 = ENTITY(reg_a6)[1].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d3.h[0] = 0x418;
    reg_d4.w = 0;
    reg_d1.h[0] += 0x7FFF + 0x7D81;
    reg_d4.b[0] = STAGE3_PALETTES(reg_a6)->lid;
    sprite_draw_layer2_keep();
}

void stage3_boss_turret_right_draw(void) {
    u16 temp_a0;
    reg_d2.h[0] = STAGE3_EXTRA(reg_a6)->right_turret_direction;
    reg_a0 = (u8 *)(g_direction_sprites_c);
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_tmp2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp2.h[0] = (((reg_d2.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d2.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = reg_tmp2.w;
    reg_d1.h[0] = ENTITY(reg_a6)[2].y.h;
    reg_d1.h[0] += 0xD00;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    temp_a0 = ENTITY(reg_a6)[2].x.h;
    reg_d1.h[0] = temp_a0;
    reg_d3.h[0] = 0x418;
    reg_d4.w = 0;
    reg_d1.h[0] += 0x7FFF + 0x7C81;
    reg_d4.b[0] = STAGE3_PALETTES(reg_a6)->lid;
    sprite_draw_layer2_keep();
}

extern u16 stage3_boss_entrance_draw_table[];

void stage3_boss_entrance_draw(void) {
    reg_a0 = (u8 *)stage3_boss_entrance_draw_table;
    reg_a0 += STAGE3_EXTRA(reg_a6)->start_anim;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF7000000;
    reg_tmp1.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.w += reg_tmp1.w;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d4.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    sprite_draw_layer2_keep();
}

u8 stage3_boss_legs_draw_table[64] = {
    0x0B, 0x1C, 0x00, 0x00, 0x0C, 0x1C, 0x00, 0x00, 0x0D, 0x1C, 0x00, 0x00, 0x0E, 0x1C, 0x00, 0x00,
    0x0F, 0x1C, 0x00, 0x00, 0x10, 0x1C, 0x00, 0x00, 0x11, 0x1C, 0x00, 0x00, 0x12, 0x1C, 0x00, 0x00,
    0x13, 0x1C, 0x00, 0x00, 0x14, 0x1C, 0x00, 0x00, 0x15, 0x1C, 0x00, 0x00, 0x16, 0x1C, 0x00, 0x00,
    0x17, 0x1C, 0x00, 0x00, 0x18, 0x1C, 0x00, 0x00, 0x19, 0x1C, 0x00, 0x00, 0x1A, 0x1C, 0x00, 0x00,
};

u8 D_0026D360[32] = {
    0x23, 0x1C, 0x00, 0x00, 0x24, 0x1C, 0x00, 0x00, 0x25, 0x1C, 0x00, 0x00, 0x26, 0x1C, 0x00, 0x00,
    0x27, 0x1C, 0x00, 0x00, 0x28, 0x1C, 0x00, 0x00, 0x29, 0x1C, 0x00, 0x00, 0x2A, 0x1C, 0x00, 0x00,
};

u8 stage3_boss_lid_left_draw_table[32] = {
    0xFB, 0x1B, 0x00, 0x00, 0xFC, 0x1B, 0x00, 0x00, 0xFD, 0x1B, 0x00, 0x00, 0xFE, 0x1B, 0x00, 0x00,
    0xFF, 0x1B, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x01, 0x1C, 0x00, 0x00, 0x02, 0x1C, 0x00, 0x00,
};

u8 stage3_boss_lid_right_draw_table[32] = {
    0x0A, 0x1C, 0x00, 0x00, 0x09, 0x1C, 0x00, 0x00, 0x08, 0x1C, 0x00, 0x00, 0x07, 0x1C, 0x00, 0x00,
    0x06, 0x1C, 0x00, 0x00, 0x05, 0x1C, 0x00, 0x00, 0x04, 0x1C, 0x00, 0x00, 0x03, 0x1C, 0x00, 0x00,
};

u8 stage3_boss_six_gun_draw_table[32] = {
    0x1B, 0x1C, 0x00, 0x00, 0x1C, 0x1C, 0x00, 0x00, 0x1D, 0x1C, 0x00, 0x00, 0x1E, 0x1C, 0x00, 0x00,
    0x1F, 0x1C, 0x00, 0x00, 0x20, 0x1C, 0x00, 0x00, 0x21, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 stage3_boss_entrance_draw_table[240] = {
    0x0000, 0x1C3A, 0xE200, 0xEE00, 0x1E90, 0x0013, 0x0000, 0x1C3B,
    0xE200, 0xEE00, 0x1E90, 0x0013, 0x0000, 0x1C3C, 0xE200, 0xEE00,
    0x1E90, 0x0013, 0x0000, 0x1C3D, 0xE200, 0xEE00, 0x1E90, 0x0013,
    0x0000, 0x1C3E, 0xE200, 0xEE00, 0x1E90, 0x0013, 0x0000, 0x1C3F,
    0xE200, 0xEE00, 0x1E90, 0x0013, 0x0000, 0x1C40, 0xE200, 0xEE00,
    0x1E90, 0x0013, 0x0000, 0x1C41, 0xE200, 0xEE00, 0x1E90, 0x0013,
    0x0000, 0x1C42, 0xE200, 0xEE00, 0x1E90, 0x0013, 0x0000, 0x1C43,
    0xE200, 0xEE00, 0x1E90, 0x0013, 0x0000, 0x1C44, 0xE200, 0xEE00,
    0x1E90, 0x0013, 0x0000, 0x1C45, 0xE200, 0xEE00, 0x1E90, 0x0013,
    0x0000, 0x1C46, 0xE200, 0xEE00, 0x1E90, 0x0013, 0x0000, 0x1C47,
    0xE200, 0xEE00, 0x1E90, 0x0013, 0x0000, 0x1C48, 0xE200, 0xEE00,
    0x1E90, 0x0013, 0x0000, 0x1C49, 0xE200, 0xEE00, 0x1E90, 0x0013,
    0x0000, 0x1C4A, 0xDC00, 0xEE00, 0x2490, 0x0013, 0x0000, 0x1C4B,
    0xDC00, 0xEE00, 0x2490, 0x0013, 0x0000, 0x1C4C, 0xDC00, 0xEE00,
    0x2490, 0x0013, 0x0000, 0x1C4D, 0xDC00, 0xEE00, 0x2490, 0x0013,
    0x0000, 0x1C4E, 0xDC00, 0xEE00, 0x2490, 0x0013, 0x0000, 0x1C4F,
    0xDC00, 0xEE00, 0x2490, 0x0013, 0x0000, 0x1C50, 0xDC00, 0xEE00,
    0x2490, 0x0013, 0x0000, 0x1C51, 0xDC00, 0xEE00, 0x2490, 0x0013,
    0x0000, 0x1C52, 0xDC00, 0xEE00, 0x2490, 0x0013, 0x0000, 0x1C53,
    0xDC00, 0xEE00, 0x2490, 0x0013, 0x0000, 0x1C54, 0xDC00, 0xEE00,
    0x2490, 0x0013, 0x0000, 0x1C55, 0xDC00, 0xEE00, 0x2490, 0x0013,
    0x0000, 0x1C56, 0xDC00, 0xEE00, 0x2490, 0x0013, 0x0000, 0x1C57,
    0xDC00, 0xEE00, 0x2490, 0x0013, 0x0000, 0x1C58, 0xDC00, 0xEE00,
    0x2490, 0x0013, 0x0000, 0x1C59, 0xDC00, 0xEE00, 0x2490, 0x0013,
    0x0000, 0x1C5A, 0xD800, 0xE900, 0x28B8, 0x0014, 0x0000, 0x1C5B,
    0xD800, 0xE900, 0x28B8, 0x0014, 0x0000, 0x1C5C, 0xD800, 0xE900,
    0x28B8, 0x0014, 0x0000, 0x1C5D, 0xD800, 0xE900, 0x28B8, 0x0014,
    0x0000, 0x1C5E, 0xD800, 0xE900, 0x28B8, 0x0014, 0x0000, 0x1C5F,
    0xD800, 0xE900, 0x28B8, 0x0014, 0x0000, 0x1C60, 0xD800, 0xE900,
    0x28B8, 0x0014, 0x0000, 0x1C61, 0xD800, 0xE900, 0x28B8, 0x0014,
};
