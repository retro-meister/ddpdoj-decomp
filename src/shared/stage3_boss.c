#include "common.h"
#include "entity.h"

void enemy_set_entity_count(s32 id);

void func_001D3C90(void) {
    enemy_set_entity_count(9);
}

s32 boss_slots_init();
s32 boss_phase_start();
s32 boss_part_show();
s32 enemy_set_task_work();
s32 enemy_init_entities();
s32 sprite_palette_load();
s32 func_001D45D0();
extern u8 D_002554B0[];
extern u8 D_0025FD30[];
extern u8 D_0025FD70[];
extern u8 D_0025FDB0[];
extern u8 D_0025FDF0[];
extern u8 D_0025FE30[];
extern u8 D_0026CAE0[];
extern u8 D_0026CBF0[];
extern u8 D_0026D2F0[];
extern u8 D_0026D7C0[];
extern u8 D_0026D9E0[];
extern u8 D_0026DA00[];
extern u8 D_0028DC18[];
extern s16 g_boss_hyper_wait_as_s16;
extern u8 *g_boss_hp;
extern s32 g_boss_hp_unit;
extern u8 D_0028E854;
extern u8 D_0028E855;
extern u16 g_loop;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];

void func_001D3CA0(void) {
    reg_a0 = (u8 *)D_0026DA00;
    enemy_init_entities();
    reg_a0 = (u8 *)D_0028DC18;
    reg_d0.h[0] = 2;
    enemy_set_task_work();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)D_0026D9E0;
    reg_a1 = (u8 *)D_0026CBF0;
    reg_a2 = (u8 *)D_0026D2F0;
    reg_a3 = (u8 *)D_0026CAE0;
    reg_a4 = (u8 *)D_0026D7C0;
    boss_slots_init();
    reg_d0.w = 9;
    boss_part_show();
    reg_d0.w = 0;
    boss_phase_start();
    reg_d0.h[0] = 0x10;
    reg_a0 = (u8 *)D_0025FD30;
    sprite_palette_load();
    reg_d0.h[0] = 0x11;
    reg_a0 = (u8 *)D_0025FD70;
    sprite_palette_load();
    reg_d0.h[0] = 0x12;
    reg_a0 = (u8 *)D_0025FDB0;
    sprite_palette_load();
    reg_d0.h[0] = 0x13;
    reg_a0 = (u8 *)D_0025FDF0;
    sprite_palette_load();
    reg_d0.h[0] = 0x14;
    reg_a0 = (u8 *)D_0025FE30;
    sprite_palette_load();
    reg_d0.h[0] = 0xA;
    reg_a0 = (u8 *)D_002554B0;
    sprite_palette_load();
    g_boss_hyper_wait_as_s16 = 1;
    D_0028E855 |= 1;
    g_boss_hp_unit = 0x4A0;
    D_0028E855 |= 4;
    D_0028E854 |= 1;
    reg_a0 = reg_a5 + 0x16;
    g_boss_hp = (u8 *)(reg_a0);
    func_001D45D0();
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    if (g_loop != 0) {
        D_0029976C_as_s16_a[0] = 1;
    }
}

s32 enemy_remove();                           /* extern */
s32 boss_slots_run();                            /* extern */
s32 enemy_hitbox_debug_draw();                            /* extern */
s32 func_001D3F00();                            /* extern */
s32 func_002035A0();                            /* extern */

void func_001D3E60(void) {
    func_001D3F00();
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
    reg_a0 = (u8 *)(((s32)reg_a6) + 0xC0);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0xE0);
    enemy_hitbox_debug_draw();
}
