#include "common.h"
#include "entity.h"
#include "stage1_boss.h"

u16 stage1_boss_state_init[] = {
    0x0001, 0x6C00, 0x0000, 0x9000, 0x0000, 0x9000, 0x2A30,
};

u16 stage1_boss_entities[] = {
    0xA001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0E00, 0x1780,
    0x0800, 0x0800, 0x7FFF, 0x1000, 0x0013, 0x0000, 0xA001, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0B00, 0x0D00, 0x0780, 0x0500,
    0x7FFF, 0x1000, 0x0015, 0x0000, 0x8000, 0x8000, 0x8000, 0x8240,
    0x0000, 0x0000, 0x0B00, 0x0D00, 0x0780, 0x0500, 0x7FFF, 0x1000,
    0x0015, 0x0000, 0xA001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0B00, 0x0D00, 0x0500, 0x0780, 0x7FFF, 0x1000, 0x0015,
};

void enemy_set_entity_count(s32 id);

void stage1_boss_first(void) {
    enemy_set_entity_count(8);
}

s32 boss_slots_init();
s32 boss_phase_start();
s32 boss_part_show();
s32 enemy_set_task_state();
s32 enemy_init_entities();
s32 sprite_palette_load();
s32 stage1_boss_damage_init();
s32 stage1_boss_shield_on();
s32 stage1_boss_parts_disable();
extern u8 g_default_sprite_palette[];
extern u8 D_0025FA70[];
extern u8 D_0025FAB0[];
extern u8 D_0025FAF0[];
extern u8 D_0025FB70[];
extern void (*stage1_boss_anim_routines[])(void);
extern void (*stage1_boss_fire_routines[])(void);
extern void (*stage1_boss_draw_routines[])(void);
extern void (*stage1_boss_mode_routines[])(void);
extern void (*stage1_boss_move_routines[])(void);
extern s32 D_0028DC90;
extern s16 g_boss_hyper_wait_as_s16;
extern u8 *g_boss_hp;
extern s32 g_boss_hp_unit;
extern u8 g_boss_present;
extern u8 g_boss_present_b1;
extern u16 g_loop;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];
extern u16 g_side_scroll_x[];

void stage1_boss_start(void) {
    s32 t;

    reg_a0 = (u8 *)stage1_boss_entities;
    enemy_init_entities();
    reg_a0 = (u8 *)stage1_boss_state_init;
    t = (s32) D_0028DC90 >> 1;
    if (D_0028DC90 < 0) {
        t = (s32) (D_0028DC90 + 1) >> 1;
    }
    reg_d0.h[0] = t - 1;
    enemy_set_task_state();
    reg_tmp.w = 0x97FFFE00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    reg_d0.h[0] = g_side_scroll_x[0];
    ENTITY(reg_a6)->x.h -= reg_d0.h[0];
    reg_a0 = (u8 *)stage1_boss_move_routines;
    reg_a1 = (u8 *)stage1_boss_fire_routines;
    reg_a2 = (u8 *)stage1_boss_draw_routines;
    reg_a3 = (u8 *)stage1_boss_anim_routines;
    reg_a4 = (u8 *)stage1_boss_mode_routines;
    boss_slots_init();
    reg_d0.w = 6;
    boss_part_show();
    reg_d0.w = 0;
    boss_phase_start();
    reg_d0.h[0] = 0x15;
    reg_a0 = (u8 *)D_0025FA70;
    sprite_palette_load();
    reg_d0.h[0] = 0x16;
    reg_a0 = (u8 *)D_0025FAB0;
    sprite_palette_load();
    reg_d0.h[0] = 0x17;
    reg_a0 = (u8 *)D_0025FAF0;
    sprite_palette_load();
    reg_d0.h[0] = 0x12;
    reg_a0 = (u8 *)g_default_sprite_palette;
    sprite_palette_load();
    reg_d0.h[0] = 0x11;
    reg_a0 = (u8 *)D_0025FB70;
    sprite_palette_load();
    g_boss_hyper_wait_as_s16 = 1;
    g_boss_present_b1 |= 1;
    g_boss_present_b1 |= 4;
    g_boss_hp_unit = 0x1A0;
    g_boss_present |= 1;
    reg_a0 = reg_a5;
    reg_a0 += 0x16;
    g_boss_hp = (u8 *)(reg_a0);
    stage1_boss_damage_init();
    stage1_boss_shield_on();
    stage1_boss_parts_disable();
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    if (g_loop != 0) {
        D_0029976C_as_s16_a[0] = 1;
    }
}

s32 enemy_remove();                           /* extern */
s32 boss_slots_run();                            /* extern */
s32 enemy_hitbox_debug_draw();                            /* extern */
s32 stage1_boss_damage();                            /* extern */
s32 func_002016D0();                            /* extern */
s32 func_002035A0();                            /* extern */

void stage1_boss_main(void) {
    u16 temp_v0;

    stage1_boss_damage();
    temp_v0 = STAGE1_BOSS(reg_a5)->bullet_clear_time;
    if (temp_v0 != 0) {
        STAGE1_BOSS(reg_a5)->bullet_clear_time = (u16) (temp_v0 - 1);
        func_002016D0();
    }
    boss_slots_run();
    if (cond_flag != 0) {
        func_002035A0();
        enemy_remove();
        return;
    }
    reg_a0 = (u8 *)(((s32)reg_a6));
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x20);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x60);
    enemy_hitbox_debug_draw();
}

u16 D_0026EA60[72] = {
    0x8000, 0x8000, 0x8000, 0x82C0, 0x0000, 0x0000, 0x0B00, 0x0D00,
    0x0780, 0x0500, 0x7FFF, 0x1000, 0x0015, 0x0000, 0x8000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0808, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1000, 0x0016, 0x0000, 0x8000, 0x2020, 0x2020, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x8000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x8000, 0x0000, 0x0008, 0x1000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

s32 D_0028DC90 = 16;
