#include "common.h"
#include "entity.h"
#include "stage5_boss.h"

void stage5_boss_draw_belly(void);
void stage5_boss_draw_chest(void);
void stage5_boss_draw_stinger(void);
void stage5_boss_draw_left_arm_gun_low(void);
void stage5_boss_draw_left_arm_gun_mid(void);
void stage5_boss_draw_left_arm_gun_high(void);
void stage5_boss_draw_right_arm_gun_low(void);
void stage5_boss_draw_right_arm_gun_mid(void);
void stage5_boss_draw_right_arm_gun_high(void);
void stage5_boss_draw_head(void);
void stage5_boss_draw_form2_wings(void);
void stage5_boss_draw_form2_belly(void);
void stage5_boss_draw_form2_stinger(void);
void stage5_boss_draw_form2_chest(void);
void stage5_boss_draw_form2_exhaust(void);
void stage5_boss_draw_form2_head(void);
void stage5_boss_draw_form3_body(void);
void stage5_boss_draw_form3_tail(void);
void stage5_boss_draw_form3_bomb_barrier(void);

/* The draw routine of every part of the boss, by part number. */
void (*stage5_boss_draw_routines[])(void) = {
    stage5_boss_draw_belly,
    stage5_boss_draw_chest,
    stage5_boss_draw_stinger,
    stage5_boss_draw_left_arm_gun_low,
    stage5_boss_draw_left_arm_gun_mid,
    stage5_boss_draw_left_arm_gun_high,
    stage5_boss_draw_right_arm_gun_low,
    stage5_boss_draw_right_arm_gun_mid,
    stage5_boss_draw_right_arm_gun_high,
    stage5_boss_draw_head,
    stage5_boss_draw_form2_wings,
    stage5_boss_draw_form2_belly,
    stage5_boss_draw_form2_stinger,
    stage5_boss_draw_form2_chest,
    stage5_boss_draw_form2_exhaust,
    stage5_boss_draw_form2_head,
    stage5_boss_draw_form3_body,
    stage5_boss_draw_form3_tail,
    stage5_boss_draw_form3_bomb_barrier,
    (void (*)(void))-1,
};

s32 velocity_from_dir256();
extern u8 D_00264870[];

void stage5_boss_draw_belly(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a1;
    u32 temp_a2;

    reg_d1.w = 0;
    reg_d0.h[0] = 0x1A;
    reg_d1.b[0] = STAGE5_EXTRA(reg_a6)->belly_direction;
    velocity_from_dir256();
    STAGE5_EXTRA(reg_a6)->belly_direction += 2;
    ENTITY(reg_a6)->hit_y_plus.h = 0x1400U;
    ENTITY(reg_a6)->hit_y_plus.h += reg_d2.h[0];
    ENTITY(reg_a6)->hit_y_minus.h = 0x2200U;
    ENTITY(reg_a6)->hit_y_minus.h -= reg_d2.h[0];
    ENTITY(reg_a6)[13].hit_y_plus.h = 0xDE00U;
    ENTITY(reg_a6)[13].hit_y_plus.h += reg_d2.h[0];
    ENTITY(reg_a6)[13].hit_y_minus.h = 0x2600U;
    ENTITY(reg_a6)[13].hit_y_minus.h -= reg_d2.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    temp_a2 = reg_d1.w;
    reg_a0 = D_00264870;
    reg_d1.w = temp_a2 + 0xE6000000;
    temp_a1 = reg_d1.w;
    reg_d1.w = temp_a1 + 0xEA00F200;
    reg_a0 += STAGE5_EXTRA(reg_a6)->belly_anim;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = 0x1670;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->belly;
    sprite_draw_layer2_keep(reg_a0, temp_a1, temp_a2, reg_tmp.h[0]);
}

void stage5_boss_draw_chest(void) {
    s32 sprite_draw_layer2_keep();
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_dir256();
    STAGE5_ADJUST_B(reg_a6)->arms_y_shift = reg_d2.h[0];
    ENTITY(reg_a6)->move.b.dir += 2;
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFC000000;
    reg_d1.w += 0xE000DC00;
    reg_d2.w = 0x1E50;
    reg_d3.h[0] = 0x2120;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->chest;
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_stinger(void) {
    s32 sprite_draw_layer2_keep();
    reg_d0.h[0] = 0x1A;
    reg_d1.w = 0;
    reg_d1.b[0] = STAGE5_EXTRA(reg_a6)->belly_direction;
    velocity_from_dir256();
    reg_d1.h[0] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.w += 0xD0000000;
    reg_d1.w += 0xF400F900;
    reg_d2.w = 0x1DF4;
    reg_d3.h[0] = 0xC38;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->belly;
    sprite_draw_layer2_keep();
}

extern u16 D_00264890[];

void stage5_boss_draw_left_arm_gun_low(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    ENTITY(reg_a6)[3].hit_y_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    ENTITY(reg_a6)[3].hit_y_minus.h = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = ENTITY(reg_a6)[3].move.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)[3].y.h;
    reg_d1.h[0] += STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = ENTITY(reg_a6)[3].x.h;
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)[3].offset_y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[3].offset_x.h;
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = ENTITY(reg_a6)[3].look.h;
    reg_d4.h[0] = ENTITY(reg_a6)[3].attr.h;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->arm_guns;
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_left_arm_gun_mid(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    ENTITY(reg_a6)[2].hit_y_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    ENTITY(reg_a6)[2].hit_y_minus.h = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = ENTITY(reg_a6)[2].move.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)[2].y.h;
    reg_d1.h[0] += STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = ENTITY(reg_a6)[2].x.h;
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)[2].offset_y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[2].offset_x.h;
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = ENTITY(reg_a6)[2].look.h;
    reg_d4.h[0] = ENTITY(reg_a6)[2].attr.h;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->arm_guns;
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_left_arm_gun_high(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    ENTITY(reg_a6)[1].hit_y_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    ENTITY(reg_a6)[1].hit_y_minus.h = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = ENTITY(reg_a6)[1].move.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)[1].y.h;
    reg_d1.h[0] += STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)[1].offset_y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = ENTITY(reg_a6)[1].look.h;
    reg_d4.h[0] = ENTITY(reg_a6)[1].attr.h;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->arm_guns;
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_right_arm_gun_low(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    ENTITY(reg_a6)[6].hit_y_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    ENTITY(reg_a6)[6].hit_y_minus.h = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = ENTITY(reg_a6)[6].move.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)[6].y.h;
    reg_d1.h[0] += STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = ENTITY(reg_a6)[6].x.h;
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)[6].offset_y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[6].offset_x.h;
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = ENTITY(reg_a6)[6].look.h;
    reg_d4.h[0] = ENTITY(reg_a6)[6].attr.h;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->arm_guns;
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_right_arm_gun_mid(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    ENTITY(reg_a6)[5].hit_y_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    ENTITY(reg_a6)[5].hit_y_minus.h = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = ENTITY(reg_a6)[5].move.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)[5].y.h;
    reg_d1.h[0] += STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)[5].offset_y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[5].offset_x.h;
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = ENTITY(reg_a6)[5].look.h;
    reg_d4.h[0] = ENTITY(reg_a6)[5].attr.h;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->arm_guns;
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_right_arm_gun_high(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    ENTITY(reg_a6)[4].hit_y_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    ENTITY(reg_a6)[4].hit_y_minus.h = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = ENTITY(reg_a6)[4].move.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)[4].y.h;
    reg_d1.h[0] += STAGE5_ADJUST_B(reg_a6)->arms_y_shift;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = ENTITY(reg_a6)[4].x.h;
    temp_a0 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)[4].offset_y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[4].offset_x.h;
    reg_d1.w = temp_a0 + reg_tmp.w;
    reg_d3.h[0] = ENTITY(reg_a6)[4].look.h;
    reg_d4.h[0] = ENTITY(reg_a6)[4].attr.h;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->arm_guns;
    sprite_draw_layer2_keep();
}


void stage5_boss_draw_head(void) {
    stage5_boss_draw_form2_head();
}

extern u8 D_00264990[];

void stage5_boss_draw_form2_head(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a1;

    reg_d1.w = 0;
    reg_d0.h[0] = 0x10;
    reg_d1.b[0] = STAGE5_EXTRA(reg_a6)->head_direction;
    velocity_from_dir256();
    STAGE5_EXTRA(reg_a6)->head_direction += 2;
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    temp_a1 = reg_d1.w;
    reg_d1.w = temp_a1 + 0xEE00EC00;
    reg_a0 = D_00264990;
    reg_a0 += STAGE5_EXTRA(reg_a6)->head_anim;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = 0x12A0;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->head;
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_form2_belly(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a1;
    u32 temp_a2;

    reg_d1.w = 0;
    reg_d0.h[0] = 0x1C;
    reg_d1.b[0] = STAGE5_EXTRA(reg_a6)->belly_direction;
    velocity_from_dir256();
    STAGE5_EXTRA(reg_a6)->belly_direction += 3;
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    temp_a2 = reg_d1.w;
    reg_a0 = D_00264870;
    reg_d1.w = temp_a2 + 0xEE000000;
    temp_a1 = reg_d1.w;
    reg_d1.w = temp_a1 + 0xEA00F200;
    reg_a0 += STAGE5_EXTRA(reg_a6)->belly_anim;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = 0x1670;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->belly;
    sprite_draw_layer2_keep(reg_a0, temp_a1, temp_a2, reg_tmp.h[0]);
}


void stage5_boss_draw_form2_chest(void)
{
    extern void sprite_draw_layer2_keep(void);
    u8 *source;

    reg_d2.w = 0x1E51;
    source = (u8 *)((void *)reg_a6);
    reg_d1.h[1] = *(u16 *)(source + 2);
    reg_d1.h[0] = *(u16 *)(source + 4);
    reg_d1.w = reg_d1.w + 0x0200FFC0U;
    reg_d4.w = 0;
    reg_d1.w = reg_d1.w + 0xF200F400U;
    reg_d3.h[0] = 0xE60;
    *(u8 *)&reg_d4 = source[0xE6];
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_form2_stinger(void) {
    s32 sprite_draw_layer2_keep();
    reg_d0.h[0] = 0x1A;
    reg_d1.w = 0;
    reg_d1.b[0] = STAGE5_EXTRA(reg_a6)->belly_direction;
    velocity_from_dir256();
    reg_d1.h[0] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.w += 0xD8000000;
    reg_d1.w += 0xF400F900;
    reg_d2.w = 0x1DF4;
    reg_d3.h[0] = 0xC38;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->belly;
    sprite_draw_layer2_keep();
}

extern u8 D_002649A8[];

void stage5_boss_draw_form2_exhaust(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a1;

    reg_a0 = D_002649A8;
    reg_a0 += STAGE5_EXTRA(reg_a6)->exhaust_anim;
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF4000000;
    reg_d1.w += 0xF000DE00;
    reg_d3.h[0] = 0x1110;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->exhaust;
    sprite_draw_layer2_keep();
}

extern u16 D_002649C0[];

void stage5_boss_draw_form2_wings(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a3;
    u32 temp_a0;

    reg_a0 = (u8 *)(D_002649C0);
    reg_a0 += STAGE5_EXTRA(reg_a6)->wings_anim;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a3 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a3;
    reg_d1.w += 0x0C000000;
    temp_a0 = reg_d1.w + 0xF200E000;
    reg_d1.w = temp_a0;
    reg_d3.h[0] = 0xF00;
    reg_d4.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    sprite_draw_layer2_keep();
}

s32 sprite_draw_with_last_boss_keep();
extern u8 D_00264A50[];
extern u16 g_frame_mod3;

void stage5_boss_draw_form3_body(void) {
    s32 sprite_draw_layer2_keep();
#ifdef DEATH_LABEL
    s32 i;
    u16 x;
    u16 y;

    x = ENTITY(reg_a6)->y.h;
    y = ENTITY(reg_a6)->x.h;
    for (i = 0; i < 2; i++) {
        reg_a0 = D_00264A50;
        reg_a0 += STAGE5_EXTRA(reg_a6)->form3_body_anim;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = x;
        reg_d1.h[0] = y;
        x = ENTITY(reg_a6)[16].y.h;
        y = ENTITY(reg_a6)[16].x.h;
        reg_d1.w += 0xF400F900;
        reg_d3.h[0] = 0xC38;
        reg_d4.w = 0;
        reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->form3_body;
        if ((ENTITY(reg_a6)[10].misc.b.draw_layer == 0) && (g_frame_mod3 != 0)) {
            sprite_draw_with_last_boss_keep();
        } else {
            sprite_draw_layer2_keep();
        }
    }
#else
    u16 temp_a0;

    reg_a0 = D_00264A50;
    reg_a0 += STAGE5_EXTRA(reg_a6)->form3_body_anim;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF400F900;
    reg_d3.h[0] = 0xC38;
    reg_d4.w = 0;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->form3_body;
    if ((ENTITY(reg_a6)[10].misc.b.draw_layer == 0) && (g_frame_mod3 != 0)) {
        sprite_draw_with_last_boss_keep();
        return;
    }
    sprite_draw_layer2_keep();
#endif
}

extern u16 MAIN_OR_DEATH_LABEL(D_00264A70, death_D_0026A2E0)[];

#ifdef DEATH_LABEL
#define BOSS_X x
#define BOSS_Y y
#else
#define BOSS_X (ENTITY(reg_a6)->y.h)
#define BOSS_Y (ENTITY(reg_a6)->x.h)
#endif

void stage5_boss_draw_form3_tail(void) {
    s32 sprite_draw_layer2_keep();
#ifdef DEATH_LABEL
    s32 i;
    u16 x;
    u16 y;

    x = ENTITY(reg_a6)->y.h;
    y = ENTITY(reg_a6)->x.h;
    for (i = 0; i < 2; i++) {
#endif
    reg_a0 = (u8 *) MAIN_OR_DEATH_LABEL(D_00264A70, death_D_0026A2E0);
    reg_d2.h[0] = STAGE5_EXTRA(reg_a6)->tail_direction;
    reg_d2.h[0] -= 0x18;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = BOSS_X;
    reg_d1.h[0] = BOSS_Y;
    reg_d1.w += 0xFE00FF00;
    reg_d4.w = 0;
    reg_d1.w += 0xF7C00000;
    reg_d3.h[0] = 0x208;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->form3_body;
    sprite_draw_layer2_keep();
#ifdef DEATH_LABEL
        x = ENTITY(reg_a6)[16].y.h;
        y = ENTITY(reg_a6)[16].x.h;
    }
#endif
}

extern u8 D_00264AC0[];
extern u16 g_frame_mod2;

void stage5_boss_draw_form3_bomb_barrier(void) {
    s32 sprite_draw_layer2_keep();
#ifdef DEATH_LABEL
    s32 i;
    u16 x;
    u16 y;

    if (g_frame_mod2 == 0) {
        return;
    }
    x = ENTITY(reg_a6)->y.h;
    y = ENTITY(reg_a6)->x.h;
    for (i = 0; i < 2; i++) {
        reg_a0 = (u8 *)D_00264AC0;
        reg_a0 += STAGE5_EXTRA(reg_a6)->barrier_anim;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = x;
        reg_d1.h[0] = y;
        reg_d1.w += 0xFF800000;
        reg_d4.w = 0;
        reg_d1.w += 0xF000F800;
        reg_d3.h[0] = 0x1040;
        reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->barrier;
        sprite_draw_layer2_keep();
        x = ENTITY(reg_a6)[16].y.h;
        y = ENTITY(reg_a6)[16].x.h;
    }
#else
    u16 temp_a1;

    if (g_frame_mod2 != 0) {
        reg_a0 = (u8 *)D_00264AC0;
        reg_a0 += STAGE5_EXTRA(reg_a6)->barrier_anim;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a1 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFF800000;
        reg_d4.w = 0;
        reg_d1.w += 0xF000F800;
        reg_d3.h[0] = 0x1040;
        reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->barrier;
        sprite_draw_layer2_keep();
    }
#endif
}

u8 D_00264870[32] = {
    0x00, 0x00, 0xEE, 0x1D, 0x00, 0x00, 0xEF, 0x1D, 0x00, 0x00, 0xF0, 0x1D, 0x00, 0x00, 0xF1, 0x1D,
    0x00, 0x00, 0xF2, 0x1D, 0x00, 0x00, 0xF3, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 D_00264890[128] = {
    0x0000, 0x1E10, 0x0000, 0x1E11, 0x0000, 0x1E12, 0x0000, 0x1E13,
    0x0000, 0x1E14, 0x0000, 0x1E15, 0x0000, 0x1E16, 0x0000, 0x1E17,
    0x0000, 0x1E18, 0x0000, 0x1E19, 0x0000, 0x1E1A, 0x0000, 0x1E1B,
    0x0000, 0x1E1C, 0x0000, 0x1E1D, 0x0000, 0x1E1E, 0x0000, 0x1E1F,
    0x0000, 0x1E20, 0x0000, 0x1E21, 0x0000, 0x1E22, 0x0000, 0x1E23,
    0x0000, 0x1E24, 0x0000, 0x1E25, 0x0000, 0x1E26, 0x0000, 0x1E27,
    0x0000, 0x1E28, 0x0000, 0x1E29, 0x0000, 0x1E2A, 0x0000, 0x1E2B,
    0x0000, 0x1E2C, 0x0000, 0x1E2D, 0x0000, 0x1E2E, 0x0000, 0x1E2F,
    0x0000, 0x1E30, 0x0000, 0x1E31, 0x0000, 0x1E32, 0x0000, 0x1E33,
    0x0000, 0x1E34, 0x0000, 0x1E35, 0x0000, 0x1E36, 0x0000, 0x1E37,
    0x0000, 0x1E38, 0x0000, 0x1E39, 0x0000, 0x1E3A, 0x0000, 0x1E3B,
    0x0000, 0x1E3C, 0x0000, 0x1E3D, 0x0000, 0x1E3E, 0x0000, 0x1E3F,
    0x0000, 0x1E40, 0x0000, 0x1E41, 0x0000, 0x1E42, 0x0000, 0x1E43,
    0x0000, 0x1E44, 0x0000, 0x1E45, 0x0000, 0x1E46, 0x0000, 0x1E47,
    0x0000, 0x1E48, 0x0000, 0x1E49, 0x0000, 0x1E4A, 0x0000, 0x1E4B,
    0x0000, 0x1E4C, 0x0000, 0x1E4D, 0x0000, 0x1E4E, 0x0000, 0x1E4F,
};

u8 D_00264990[48] = {
    0x00, 0x00, 0xE8, 0x1D, 0x00, 0x00, 0xE9, 0x1D, 0x00, 0x00, 0xEA, 0x1D, 0x00, 0x00, 0xEB, 0x1D,
    0x00, 0x00, 0xEC, 0x1D, 0x00, 0x00, 0xED, 0x1D, 0x00, 0x00, 0xF5, 0x1D, 0x00, 0x00, 0xF6, 0x1D,
    0x00, 0x00, 0xF7, 0x1D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 D_002649C0[72] = {
    0x0000, 0x1DF8, 0x0014, 0x0000, 0x1DF9, 0x0014, 0x0000, 0x1DFA,
    0x0014, 0x0000, 0x1DFB, 0x0014, 0x0000, 0x1DFC, 0x0014, 0x0000,
    0x1DFD, 0x0014, 0x0000, 0x1DFE, 0x0014, 0x0000, 0x1DFF, 0x0014,
    0x0000, 0x1E00, 0x0014, 0x0000, 0x1E01, 0x0014, 0x0000, 0x1E02,
    0x0014, 0x0000, 0x1E03, 0x0014, 0x0000, 0x1E04, 0x0014, 0x0000,
    0x1E05, 0x0014, 0x0000, 0x1E06, 0x0014, 0x0000, 0x1E07, 0x0014,
    0x0000, 0x1E08, 0x0015, 0x0000, 0x1E09, 0x0015, 0x0000, 0x1E0A,
    0x0015, 0x0000, 0x1E0B, 0x0015, 0x0000, 0x1E0C, 0x0015, 0x0000,
    0x1E0D, 0x0015, 0x0000, 0x1E0E, 0x0015, 0x0000, 0x1E0F, 0x0015,
};

u8 D_00264A50[32] = {
    0x00, 0x00, 0x52, 0x1E, 0x00, 0x00, 0x53, 0x1E, 0x00, 0x00, 0x54, 0x1E, 0x00, 0x00, 0x55, 0x1E,
    0x00, 0x00, 0x56, 0x1E, 0x00, 0x00, 0x57, 0x1E, 0x00, 0x00, 0x58, 0x1E, 0x00, 0x00, 0x59, 0x1E,
};

u16 D_00264A70[40] = {
    0x0000, 0x1E5A, 0x0000, 0x1E5B, 0x0000, 0x1E5C, 0x0000, 0x1E5D,
    0x0000, 0x1E5E, 0x0000, 0x1E5F, 0x0000, 0x1E60, 0x0000, 0x1E61,
    0x0000, 0x1E62, 0x0000, 0x1E63, 0x0000, 0x1E64, 0x0000, 0x1E65,
    0x0000, 0x1E66, 0x0000, 0x1E67, 0x0000, 0x1E68, 0x0000, 0x1E69,
    0x0000, 0x1E6A, 0x0000, 0x1E6B, 0x0000, 0x0000, 0x0000, 0x0000,
};

u8 D_00264AC0[64] = {
    0x00, 0x00, 0x6C, 0x1E, 0x00, 0x00, 0x6D, 0x1E, 0x00, 0x00, 0x6E, 0x1E, 0x00, 0x00, 0x6F, 0x1E,
    0x00, 0x00, 0x70, 0x1E, 0x00, 0x00, 0x71, 0x1E, 0x00, 0x00, 0x72, 0x1E, 0x00, 0x00, 0x73, 0x1E,
    0x00, 0x00, 0x74, 0x1E, 0x00, 0x00, 0x75, 0x1E, 0x00, 0x00, 0x76, 0x1E, 0x00, 0x00, 0x77, 0x1E,
    0x00, 0x00, 0x78, 0x1E, 0x00, 0x00, 0x79, 0x1E, 0x00, 0x00, 0x7A, 0x1E, 0x00, 0x00, 0x7B, 0x1E,
};
