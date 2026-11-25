#include "common.h"
#include "entity.h"

void enemy_set_entity_count(s32 id);

void func_001CA450(void) {
    enemy_set_entity_count(0xB);
}

s32 boss_slots_init();
s32 boss_phase_start();
s32 boss_part_show_all();
s32 enemy_set_task_work();
s32 enemy_init_entities();
s32 sprite_palette_load();
s32 func_001CA720();
s32 func_001CBBD0();
s32 func_001CBC10();
extern u8 g_default_sprite_palette[];
extern u8 D_0025FBB0[];
extern u8 D_0025FBF0[];
extern u8 D_0025FC30[];
extern u8 D_0025FC70[];
extern u8 D_0025FCF0[];
extern u8 D_0026C030[];
extern u8 D_0026C0C0[];
extern u8 D_0026C270[];
extern u8 D_0026C630[];
extern u8 D_0026C820[];
extern u8 D_0026C920[];
extern u8 D_0028DB18[];
extern s16 D_0028E3A8;
extern s16 g_boss_hyper_wait_as_s16;
extern u8 *g_boss_hp;
extern s32 g_boss_hp_unit;
extern u8 g_boss_present_b1;
extern u16 g_loop;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];
extern u16 g_side_scroll_x[];

void func_001CA460(void) {
    reg_a0 = (u8 *)D_0026C920;
    enemy_init_entities();
    reg_a0 = (u8 *)D_0028DB18;
    reg_d0.h[0] = 2;
    enemy_set_task_work();
    reg_tmp.w = 0x9C001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    reg_d0.h[0] = g_side_scroll_x[0];
    ENTITY(reg_a6)->x.h -= reg_d0.h[0];
    reg_a0 = (u8 *)D_0026C820;
    reg_a1 = (u8 *)D_0026C0C0;
    reg_a2 = (u8 *)D_0026C270;
    reg_a3 = (u8 *)D_0026C030;
    reg_a4 = (u8 *)D_0026C630;
    D_0028E3A8 = 0;
    boss_slots_init();
    boss_part_show_all();
    reg_d0.w = 0;
    boss_phase_start();
    reg_d0.h[0] = 0x10;
    reg_a0 = (u8 *)D_0025FBB0;
    sprite_palette_load();
    reg_d0.h[0] = 0x11;
    reg_a0 = (u8 *)D_0025FBF0;
    sprite_palette_load();
    reg_d0.h[0] = 0x12;
    reg_a0 = (u8 *)D_0025FC30;
    sprite_palette_load();
    reg_d0.h[0] = 0x17;
    reg_a0 = (u8 *)D_0025FC70;
    sprite_palette_load();
    reg_d0.h[0] = 0x13;
    reg_a0 = (u8 *)D_0025FCF0;
    sprite_palette_load();
    reg_d0.h[0] = 0x16;
    reg_a0 = (u8 *)g_default_sprite_palette;
    sprite_palette_load();
    g_boss_hyper_wait_as_s16 = 1;
    g_boss_present_b1 |= 1;
    g_boss_hp_unit = 0x322;
    reg_a0 = reg_a5 + 0x16;
    g_boss_present_b1 |= 4;
    g_boss_hp = (u8 *)(reg_a0);
    func_001CA720();
    func_001CBBD0();
    func_001CBC10();
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    if (g_loop != 0) {
        D_0029976C_as_s16_a[0] = 1;
    }
}

s32 enemy_remove();                           /* extern */
s32 boss_slots_run();                            /* extern */
s32 enemy_hitbox_debug_draw();                            /* extern */
s32 func_001CA730();                            /* extern */
s32 func_002035A0();                            /* extern */

void func_001CA640(void) {
    func_001CA730();
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
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x40);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x60);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x80);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0xA0);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0xC0);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0xE0);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x100);
    enemy_hitbox_debug_draw();
}
