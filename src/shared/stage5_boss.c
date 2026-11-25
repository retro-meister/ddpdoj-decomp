#include "common.h"
#include "entity.h"

extern void enemy_set_entity_count(s32);

void func_001F4B50(void) {
    enemy_set_entity_count(MAIN_OR_DEATH_LABEL(0xF, 18));
}

s32 boss_slots_init();
s32 boss_phase_start();
s32 boss_part_show();
s32 enemy_set_task_work();
s32 enemy_init_entities();
s32 sprite_palette_load();
s32 func_001F5750();
extern u8 D_0025FF70[];
extern u8 D_0025FFB0[];
extern u8 D_0025FFF0[];
extern u8 D_00260030[];
extern u8 D_00260070[];
extern u8 D_002600B0[];
extern u8 D_002600F0[];
extern u8 D_00260130[];
extern u8 D_00260170[];
extern u8 D_00264090[];
extern u8 D_002640D0[];
extern u8 D_002645B0[];
extern u8 D_00264820[];
extern u8 D_00264B00[];
extern u8 D_00264EE0[];
extern u8 D_00264F40[];
extern u8 D_00264F50[];
extern u32 D_0028D9C8;
extern u8 D_0028E290;
extern u16 D_0028E2E8;
extern u16 g_loop;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];

void func_001F4B60(void) {
    reg_a0 = D_00264F50;
    enemy_init_entities();
    reg_a0 = D_00264F40;
    reg_d0.h[0] = ((u32) D_0028D9C8 >> 1) - 1;
    enemy_set_task_work();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    reg_a0 = D_00264EE0;
    reg_a1 = D_002640D0;
    reg_a2 = D_00264820;
    reg_a3 = D_00264090;
    reg_a4 = D_00264B00;
    D_0028E2E8 = g_loop;
    if (D_0028E290 == 2) {
        D_0028E2E8 = 1;
    }
    if (D_0028E2E8 == 0) {
        reg_a1 = D_002645B0;
    }
    boss_slots_init();
    reg_d0.w = 0;
    boss_part_show();
    reg_d0.w = 1;
    boss_part_show();
    reg_d0.w = 2;
    boss_part_show();
    reg_d0.w = 5;
    boss_part_show();
    reg_d0.w = 4;
    boss_part_show();
    reg_d0.w = 3;
    boss_part_show();
    reg_d0.w = 8;
    boss_part_show();
    reg_d0.w = 7;
    boss_part_show();
    reg_d0.w = 6;
    boss_part_show();
    reg_d0.w = 9;
    boss_part_show();
    reg_d0.w = 0;
    boss_phase_start();
    reg_d0.h[0] = 0x10;
    reg_a0 = D_0025FF70;
    sprite_palette_load();
    reg_d0.h[0] = 0x11;
    reg_a0 = D_0025FFB0;
    sprite_palette_load();
    reg_d0.h[0] = 0x12;
    reg_a0 = D_0025FFF0;
    sprite_palette_load();
    reg_d0.h[0] = 0x13;
    reg_a0 = D_00260030;
    sprite_palette_load();
    reg_d0.h[0] = 0x14;
    reg_a0 = D_00260070;
    sprite_palette_load();
    reg_d0.h[0] = 0x15;
    reg_a0 = D_002600B0;
    sprite_palette_load();
    reg_d0.h[0] = 0x16;
    reg_a0 = D_002600F0;
    sprite_palette_load();
    reg_d0.h[0] = 0x17;
    reg_a0 = D_00260130;
    sprite_palette_load();
    reg_d0.h[0] = 0xF;
    reg_a0 = D_00260170;
    sprite_palette_load();
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    D_0029976C_as_s16_a[0] = 1;
    func_001F5750();
}

s32 enemy_remove();                           /* extern */
s32 boss_slots_run();                            /* extern */
s32 enemy_hitbox_debug_draw();                            /* extern */
s32 func_001F4EB0();                            /* extern */
s32 func_002035A0();                            /* extern */

void func_001F4DB0(void) {
    func_001F4EB0();
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
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x1A0);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x140);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x160);
    enemy_hitbox_debug_draw();
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x180);
    enemy_hitbox_debug_draw();
#ifdef DEATH_LABEL
    reg_a0 = (u8 *)(((s32)reg_a6) + 0x200);
    enemy_hitbox_debug_draw();
#endif
}
