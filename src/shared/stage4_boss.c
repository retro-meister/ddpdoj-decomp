#include "common.h"
#include "entity.h"

void enemy_set_entity_count(s32);

void stage4_boss_first(void) {
    enemy_set_entity_count(0xC);
}

s32 boss_slots_init();
s32 boss_phase_start();
s32 enemy_set_task_work();
s32 enemy_init_entities();
s32 sprite_palette_load();
s32 func_001E7C50();
s32 func_001E8700();
s32 func_001E8720();
s32 slowdown_turn_off();
extern u8 g_default_sprite_palette[];
extern u8 D_0025FE70[];
extern u8 D_0025FEB0[];
extern u8 D_0026EAF0[];
extern u8 D_0026EB50[];
extern u8 D_0026EDD0[];
extern u8 D_0026F200[];
extern u8 D_0026F3F0[];
extern u8 D_0026F4D0[];
extern u8 D_0028DC88[];
extern s16 g_boss_hyper_wait_as_s16;
extern u8 *g_boss_hp;
extern s32 g_boss_hp_unit;
extern u8 g_boss_present;
extern u8 g_boss_present_b1;
extern s16 g_enemy_signal_c_as_s16;
extern s16 g_enemy_signal_9_as_s16;
extern s16 g_enemy_signal_8_as_s16;
extern s16 g_enemy_signal_7_as_s16;
extern s16 g_enemy_signal_6_as_s16;
extern u16 g_loop;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];

void stage4_boss_start(void) {
    reg_a0 = (u8 *)D_0026F4D0;
    enemy_init_entities();
    reg_a0 = (u8 *)D_0028DC88;
    reg_d0.h[0] = 3;
    enemy_set_task_work();
    reg_tmp.w = 0xC8001C00;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    reg_a0 = (u8 *)D_0026F3F0;
    reg_a1 = (u8 *)D_0026EB50;
    reg_a2 = (u8 *)D_0026EDD0;
    reg_a3 = (u8 *)D_0026EAF0;
    reg_a4 = (u8 *)D_0026F200;
    boss_slots_init();
    reg_d0.w = 0;
    boss_phase_start();
    reg_d0.h[0] = 0x13;
    reg_a0 = (u8 *)D_0025FE70;
    sprite_palette_load();
    reg_d0.h[0] = 0x14;
    reg_a0 = (u8 *)D_0025FEB0;
    sprite_palette_load();
    reg_d0.h[0] = 0x12;
    reg_a0 = (u8 *)g_default_sprite_palette;
    sprite_palette_load();
    g_boss_hyper_wait_as_s16 = 1;
    slowdown_turn_off();
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    if (g_loop != 0) {
        D_0029976C_as_s16_a[0] = 1;
    }
    g_boss_present_b1 |= 1;
    g_boss_present_b1 |= 4;
    g_boss_hp_unit = 0x500;
    g_enemy_signal_c_as_s16 = 0;
    g_enemy_signal_6_as_s16 = 0;
    g_enemy_signal_7_as_s16 = 0;
    g_boss_present |= 1;
    reg_a0 = reg_a5;
    g_enemy_signal_8_as_s16 = 0;
    g_enemy_signal_9_as_s16 = 0;
    reg_a0 += 0x16;
    g_boss_hp = (u8 *)(reg_a0);
    func_001E7C50();
    func_001E8700();
    func_001E8720();
}

s32 enemy_remove();                           /* extern */
s32 boss_slots_run();                            /* extern */
s32 enemy_hitbox_debug_draw();                            /* extern */
s32 func_001E7C60();                            /* extern */
s32 func_002035A0();                            /* extern */

void stage4_boss_main(void) {
    boss_slots_run();
    if (cond_flag != 0) {
        func_002035A0();
        enemy_remove();
        return;
    }
    func_001E7C60();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x20);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x40);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x60);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x80);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0xA0);
    enemy_hitbox_debug_draw();
}
