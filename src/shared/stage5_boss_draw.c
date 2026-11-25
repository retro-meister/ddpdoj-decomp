#include "common.h"
#include "entity.h"

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
    reg_d1.b[0] = ENTITY(reg_a6)[9].attr.b.palette;
    velocity_from_dir256();
    ENTITY(reg_a6)[9].attr.b.palette += 2;
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
    reg_a0 += ENTITY(reg_a6)[9].offset_x.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = 0x1670;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[7].offset_x.b[1];
    sprite_draw_layer2_keep(reg_a0, temp_a1, temp_a2, reg_tmp.h[0]);
}

void stage5_boss_draw_chest(void) {
    s32 sprite_draw_layer2_keep();
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_dir256();
    ENTITY(reg_a6)[15].move.h = reg_d2.h[0];
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
    reg_d4.b[0] = ENTITY(reg_a6)[7].offset_y.b[0];
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_stinger(void) {
    s32 sprite_draw_layer2_keep();
    reg_d0.h[0] = 0x1A;
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)[9].attr.b.palette;
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
    reg_d4.b[0] = ENTITY(reg_a6)[7].offset_x.b[1];
    sprite_draw_layer2_keep();
}

extern u16 D_00264890[];

void stage5_boss_draw_left_arm_gun_low(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += ENTITY(reg_a6)[15].move.h;
    ENTITY(reg_a6)[3].hit_y_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= ENTITY(reg_a6)[15].move.h;
    ENTITY(reg_a6)[3].hit_y_minus.h = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = ENTITY(reg_a6)[3].move.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)[3].y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[15].move.h;
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
    reg_d4.b[0] = ENTITY(reg_a6)[7].offset_x.b[0];
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_left_arm_gun_mid(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += ENTITY(reg_a6)[15].move.h;
    ENTITY(reg_a6)[2].hit_y_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= ENTITY(reg_a6)[15].move.h;
    ENTITY(reg_a6)[2].hit_y_minus.h = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = ENTITY(reg_a6)[2].move.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)[2].y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[15].move.h;
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
    reg_d4.b[0] = ENTITY(reg_a6)[7].offset_x.b[0];
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_left_arm_gun_high(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += ENTITY(reg_a6)[15].move.h;
    ENTITY(reg_a6)[1].hit_y_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= ENTITY(reg_a6)[15].move.h;
    ENTITY(reg_a6)[1].hit_y_minus.h = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = ENTITY(reg_a6)[1].move.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)[1].y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[15].move.h;
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
    reg_d4.b[0] = ENTITY(reg_a6)[7].offset_x.b[0];
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_right_arm_gun_low(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += ENTITY(reg_a6)[15].move.h;
    ENTITY(reg_a6)[6].hit_y_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= ENTITY(reg_a6)[15].move.h;
    ENTITY(reg_a6)[6].hit_y_minus.h = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = ENTITY(reg_a6)[6].move.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)[6].y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[15].move.h;
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
    reg_d4.b[0] = ENTITY(reg_a6)[7].offset_x.b[0];
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_right_arm_gun_mid(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += ENTITY(reg_a6)[15].move.h;
    ENTITY(reg_a6)[5].hit_y_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= ENTITY(reg_a6)[15].move.h;
    ENTITY(reg_a6)[5].hit_y_minus.h = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = ENTITY(reg_a6)[5].move.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)[5].y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[15].move.h;
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
    reg_d4.b[0] = ENTITY(reg_a6)[7].offset_x.b[0];
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_right_arm_gun_high(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a0;

    reg_d0.h[0] = 0xA00;
    reg_d0.h[0] += ENTITY(reg_a6)[15].move.h;
    ENTITY(reg_a6)[4].hit_y_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x600;
    reg_d0.h[0] -= ENTITY(reg_a6)[15].move.h;
    ENTITY(reg_a6)[4].hit_y_minus.h = (u16) reg_d0.h[0];
    reg_a0 = (u8 *)(D_00264890);
    reg_d2.h[0] = ENTITY(reg_a6)[4].move.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)[4].y.h;
    reg_d1.h[0] += ENTITY(reg_a6)[15].move.h;
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
    reg_d4.b[0] = ENTITY(reg_a6)[7].offset_x.b[0];
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
    reg_d1.b[0] = ENTITY(reg_a6)[9].hit_y_plus.b[0];
    velocity_from_dir256();
    ENTITY(reg_a6)[9].hit_y_plus.b[0] += 2;
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] += reg_d2.h[0];
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    temp_a1 = reg_d1.w;
    reg_d1.w = temp_a1 + 0xEE00EC00;
    reg_a0 = D_00264990;
    reg_a0 += ENTITY(reg_a6)[9].offset_y.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = 0x12A0;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[7].offset_y.b[1];
    sprite_draw_layer2_keep();
}

void stage5_boss_draw_form2_belly(void) {
    s32 sprite_draw_layer2_keep();
    u32 temp_a1;
    u32 temp_a2;

    reg_d1.w = 0;
    reg_d0.h[0] = 0x1C;
    reg_d1.b[0] = ENTITY(reg_a6)[9].attr.b.palette;
    velocity_from_dir256();
    ENTITY(reg_a6)[9].attr.b.palette += 3;
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
    reg_a0 += ENTITY(reg_a6)[9].offset_x.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = 0x1670;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[7].offset_x.b[1];
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
    reg_d1.b[0] = ENTITY(reg_a6)[9].attr.b.palette;
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
    reg_d4.b[0] = ENTITY(reg_a6)[7].offset_x.b[1];
    sprite_draw_layer2_keep();
}

extern u8 D_002649A8[];

void stage5_boss_draw_form2_exhaust(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a1;

    reg_a0 = D_002649A8;
    reg_a0 += ENTITY(reg_a6)[9].draw.h;
    reg_d2.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xF4000000;
    reg_d1.w += 0xF000DE00;
    reg_d3.h[0] = 0x1110;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[7].draw.b.priority;
    sprite_draw_layer2_keep();
}

extern u16 D_002649C0[];

void stage5_boss_draw_form2_wings(void) {
    s32 sprite_draw_layer2_keep();
    u16 temp_a3;
    u32 temp_a0;

    reg_a0 = (u8 *)(D_002649C0);
    reg_a0 += ENTITY(reg_a6)[9].sprite.h;
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
        reg_a0 += ENTITY(reg_a6)[9].hit_y_minus.h;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = x;
        reg_d1.h[0] = y;
        x = ENTITY(reg_a6)[16].y.h;
        y = ENTITY(reg_a6)[16].x.h;
        reg_d1.w += 0xF400F900;
        reg_d3.h[0] = 0xC38;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[7].sprite.b[0];
        if ((ENTITY(reg_a6)[10].misc.b.draw_layer == 0) && (g_frame_mod3 != 0)) {
            sprite_draw_with_last_boss_keep();
        } else {
            sprite_draw_layer2_keep();
        }
    }
#else
    u16 temp_a0;

    reg_a0 = D_00264A50;
    reg_a0 += ENTITY(reg_a6)[9].hit_y_minus.h;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF400F900;
    reg_d3.h[0] = 0xC38;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[7].sprite.b[0];
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
    reg_d2.h[0] = ENTITY(reg_a6)[9].look.h;
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
    reg_d4.b[0] = ENTITY(reg_a6)[7].sprite.b[0];
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
        reg_a0 += ENTITY(reg_a6)[9].hp.h;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = x;
        reg_d1.h[0] = y;
        reg_d1.w += 0xFF800000;
        reg_d4.w = 0;
        reg_d1.w += 0xF000F800;
        reg_d3.h[0] = 0x1040;
        reg_d4.b[0] = ENTITY(reg_a6)[7].look.b.size;
        sprite_draw_layer2_keep();
        x = ENTITY(reg_a6)[16].y.h;
        y = ENTITY(reg_a6)[16].x.h;
    }
#else
    u16 temp_a1;

    if (g_frame_mod2 != 0) {
        reg_a0 = (u8 *)D_00264AC0;
        reg_a0 += ENTITY(reg_a6)[9].hp.h;
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a1 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFF800000;
        reg_d4.w = 0;
        reg_d1.w += 0xF000F800;
        reg_d3.h[0] = 0x1040;
        reg_d4.b[0] = ENTITY(reg_a6)[7].look.b.size;
        sprite_draw_layer2_keep();
    }
#endif
}
