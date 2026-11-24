#include "common.h"
#include "entity.h"

void enemy_set_entity_count(s32);

void func_001E7A10(void) {
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
s32 func_0020ED10();
extern u8 D_002554B0[];
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
extern u8 D_0028E854;
extern u8 D_0028E855;
extern s16 g_enemy_signal_c_as_s16;
extern s16 g_enemy_signal_9_as_s16;
extern s16 g_enemy_signal_8_as_s16;
extern s16 g_enemy_signal_7_as_s16;
extern s16 g_enemy_signal_6_as_s16;
extern u16 g_loop;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];

void func_001E7A20(void) {
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
    reg_a0 = (u8 *)D_002554B0;
    sprite_palette_load();
    g_boss_hyper_wait_as_s16 = 1;
    func_0020ED10();
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    if (g_loop != 0) {
        D_0029976C_as_s16_a[0] = 1;
    }
    D_0028E855 |= 1;
    D_0028E855 |= 4;
    g_boss_hp_unit = 0x500;
    g_enemy_signal_c_as_s16 = 0;
    g_enemy_signal_6_as_s16 = 0;
    g_enemy_signal_7_as_s16 = 0;
    D_0028E854 |= 1;
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
extern s32 reg_a0_as_s32;
extern s32 reg_a6_as_s32;

void func_001E7BB0(void) {
    boss_slots_run();
    if (cond_flag != 0) {
        func_002035A0();
        enemy_remove();
        return;
    }
    func_001E7C60();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x20;
    enemy_hitbox_debug_draw();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x40;
    enemy_hitbox_debug_draw();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x60;
    enemy_hitbox_debug_draw();
    reg_a0_as_s32 = reg_a6_as_s32 + 0x80;
    enemy_hitbox_debug_draw();
    reg_a0_as_s32 = reg_a6_as_s32 + 0xA0;
    enemy_hitbox_debug_draw();
}
