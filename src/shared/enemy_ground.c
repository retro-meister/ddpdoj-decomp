#include "common.h"
#include "entity.h"

void func_001554E0(void);
void func_001555F0(void);
void func_00155700(void);
void func_00155810(void);
void func_00155920(void);
void func_001563B0(void);
void func_00157740(void);
void func_00158B80(void);
void func_00158CF0(void);
void func_00158ED0(void);
void func_001594D0(void);
void func_001597C0(void);
void func_00159A10(void);
void func_00159B20(void);

s32 explosion_spawn();

void func_00153650(arg2)
    u16 *arg2;
{
    u16 *var_a2;
    u16 temp_a1;

    var_a2 = (u16 *)(arg2);
loop_1:
    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        explosion_spawn();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
        var_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(var_a2);
        *(u16 *)(reg_a0 + 2) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
        *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d3.h[0];
        *(s16 *)(reg_a0 + 0x10) = 2;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(u16 *)(reg_a0 + 0x1A) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        goto loop_1;
    }
}

s32 bullet_fire();
s32 rng_next();
extern u16 D_00259870[];

void func_00153770(void) {
    u16 temp_a0;
    rng_next();
    temp_a0 = reg_d0.h[0];
    reg_a1 = (u8 *)(D_00259870);
    reg_d4.w = 0;
    reg_tmp.h[0] = temp_a0;
    reg_d0.h[0] = 5;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
    reg_d1.b[0] -= 4;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
    reg_d1.b[0] -= 4;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
    reg_d1.b[0] -= 4;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
    reg_d1.b[0] += 0x10;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
    reg_d1.b[0] += 4;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
    reg_d1.b[0] += 4;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] *= 4;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    bullet_fire();
}

extern void enemy_set_entity_count(s32);

void battleship_first(void) {
    enemy_set_entity_count(6);
}

extern u8 D_00257C10[];
extern u8 D_0028C9B0;
extern u16 g_enemy_signal_f;
extern u16 g_enemy_signal_e;
extern s16 g_enemy_signal_d_as_s16;
extern u16 g_scroll_line;
extern s8 enemy_move_end_requested;

void battleship_start(void) {
    s32 enemy_remove();
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)D_00257C10;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0 = &D_0028C9B0;
    reg_d0.w = 3;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested != 0) return;
    ENTITY(reg_a6)[2].attr.sb.flip = 0x10;
    ENTITY(reg_a6)[2].misc.sb.user = 0xF;
    ENTITY(reg_a6)[3].attr.sb.flip = 0x10;
    ENTITY(reg_a6)[3].misc.sb.user = 0xF;
    ENTITY(reg_a6)[4].attr.sb.flip = 0x10;
    ENTITY(reg_a6)[4].misc.sb.user = 0xF;
    ENTITY(reg_a6)[5].attr.sb.flip = 0x10;
    ENTITY(reg_a6)[5].misc.sb.user = 0xF;
    if (g_scroll_line != 0x26) goto next_1;
    if (g_enemy_signal_e == 0) goto block_f3;
    enemy_remove();
    return;
next_1:
    if (g_scroll_line != 0x1B) goto next_2;
    if (g_enemy_signal_f == 0) goto block_f2;
    enemy_remove();
    return;
next_2:
    g_enemy_signal_f = 1;
    g_enemy_signal_e = 1;
    g_enemy_signal_d_as_s16 = 1;
    return;
block_f2:
    ENTITY(reg_a6)[6].hp.sb[0] = 1;
    g_enemy_signal_e = 1;
    g_enemy_signal_d_as_s16 = 1;
    return;
block_f3:
    g_enemy_signal_d_as_s16 = 1;
}

s32 bullet_fire_fast();
s32 bullet_fire_2way();
s32 func_00136980();
s32 enemy_hitbox_debug_draw();
s32 sfx_explosion_air_small();
s32 sfx_explosion_ground_large();
s32 sprite_draw_layer4_keep();
s32 score_add_no_chain();
s32 score_add();
s32 aim_at_player();
s32 direction_turn_toward();
extern u16 D_00257D20[];
extern u8 D_002593F0[];
extern u8 D_00259570_as_u8_a[];
extern u8 D_00259870_as_u8_a[];
extern u16 g_enemy_signal_d;
extern u16 g_bullets_blocked;
extern u16 g_enemies_stopped;
extern u16 g_rank_1_16;
extern u16 g_rank_2_16;

void battleship(void) {
    s32 enemy_remove();
    s32 enemy_path_step();
    u16 temp_a0;
    u16 temp_a1_2;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 temp_a2_3;
    u16 var_a0;
    u8 *temp_a3;
    u8 *var_a1;

    if ((s16)ENTITY(reg_a6)->y.h <= -0x2400) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            g_enemy_signal_d = 0;
            enemy_remove();
            return;
        }
        goto block_4;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_4:
    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        if ((s32) g_scroll_line >= 0x7F) {
            g_enemy_signal_d = 0;
            g_enemy_signal_f = 0;
        }
        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
        ENTITY(reg_a6)[1].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[1].x.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[2].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[2].x.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[2].y.h += 0xA00;
        ENTITY(reg_a6)[2].x.h -= 0x600;
        ENTITY(reg_a6)[3].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[3].x.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[3].y.h += 0xA00;
        ENTITY(reg_a6)[3].x.h += 0x600;
        ENTITY(reg_a6)[4].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[4].x.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[4].y.h -= 0x300;
        ENTITY(reg_a6)[5].y.h = (u16) reg_d0.h[1];
        ENTITY(reg_a6)[5].x.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[5].y.h -= 0x1000;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
        reg_d1.h[0] &= 0x5C;
        if (reg_d1.h[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[2].attr.b.palette;
            reg_d2.b[0] = ENTITY(reg_a6)[2].misc.b.user;
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)[2].attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[3].attr.b.palette;
            reg_d2.b[0] = ENTITY(reg_a6)[3].misc.b.user;
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)[3].attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[4].attr.b.palette;
            reg_d2.b[0] = ENTITY(reg_a6)[4].misc.b.user;
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)[4].attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[5].attr.b.palette;
            reg_d2.b[0] = ENTITY(reg_a6)[5].misc.b.user;
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)[5].attr.b.palette = (u8) reg_d0.b[0];
            reg_d2.w = 0x7FFF;
            reg_d2.h[0] -= ENTITY(reg_a6)->hp.h;
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
            reg_tmp.w -= reg_d2.w;
            *(u16 *)(reg_a5 + 0x1A) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a5 + 0x1C) = (u16) reg_tmp.h[0];
            reg_d2.w = 0x7FFF;
            var_a1 = reg_a5;
            reg_d2.h[0] -= ENTITY(reg_a6)[1].hp.h;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(var_a1) + (0x1A)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(var_a1) + (0x1C)));
            reg_tmp.w -= reg_d2.w;
            (*(u16 *)((u8 *)(var_a1) + (0x1A))) = (u16) reg_tmp.h[1];
            var_a0 = reg_tmp.h[0];
            *(u16 *)(reg_a5 + 0x1C) = var_a0;
            reg_d0.h[0] = 0x7FFF;
            ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
            ENTITY(reg_a6)[1].hp.h = (u16) reg_d0.h[0];
            if (ENTITY(reg_a6)[2].misc.b.draw_layer == 0) {
                reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
                reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
                if ((s32) reg_tmp.w < 0x1001) {
                    reg_d0.w = 0x13;
                    score_add();
                    reg_d0.w = 0x13;
                    score_add();
                    sfx_explosion_air_small();
                    ENTITY(reg_a6)[2].misc.b.draw_layer = 1U;
                    ENTITY(reg_a6)[3].misc.b.draw_layer = 1U;
                    reg_d0.h[0] = 0x83;
                    explosion_spawn();
                    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)[2].y.h;
                    temp_a2 = ENTITY(reg_a6)[2].x.h;
                    *(u16 *)(reg_a0 + 4) = temp_a2;
                    *(s16 *)(reg_a0 + 0x12) = 0;
                    *(s16 *)(reg_a0 + 0x14) = 0;
                    *(s16 *)(reg_a0 + 0x1E) = 0x10;
                    *(s16 *)(reg_a0 + 0x10) = 2;
                    *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
                    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                    reg_d0.b[0] *= 4;
                    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                    reg_d0.h[0] = 0x83;
                    explosion_spawn();
                    var_a0 = 0x10;
                    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)[3].y.h;
                    var_a1 = (void *) ENTITY(reg_a6)[3].x.h;
                    *(u16 *)(reg_a0 + 4) = (u16) var_a1;
                    *(s16 *)(reg_a0 + 0x12) = 0;
                    *(s16 *)(reg_a0 + 0x14) = 0;
                    *(s16 *)(reg_a0 + 0x1E) = 0x10;
                    *(s16 *)(reg_a0 + 0x10) = 2;
                    *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
                    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                    reg_d0.b[0] *= 4;
                    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                }
            }
            if (ENTITY(reg_a6)[5].misc.b.draw_layer == 0) {
                reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
                reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
                if ((s32) reg_tmp.w < 0x2A01) {
                    reg_d0.w = 0x11;
                    score_add();
                    ENTITY(reg_a6)[5].misc.b.draw_layer = 1U;
                    reg_d0.h[0] = 0x84;
                    explosion_spawn();
                    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)[5].y.h;
                    temp_a2_2 = ENTITY(reg_a6)[5].x.h;
                    *(u16 *)(reg_a0 + 4) = temp_a2_2;
                    *(s16 *)(reg_a0 + 0x12) = 0;
                    *(s16 *)(reg_a0 + 0x14) = 0x800;
                    *(s16 *)(reg_a0 + 0x1E) = 0x10;
                    *(s16 *)(reg_a0 + 0x10) = 2;
                    *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
                    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                    reg_d0.b[0] *= 4;
                    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                    sfx_explosion_air_small();
                }
            }
            if (ENTITY(reg_a6)[4].misc.b.draw_layer == 0) {
                reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
                reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
                if ((s32) reg_tmp.w < 0x2001) {
                    reg_d0.w = 0x32;
                    score_add();
                    ENTITY(reg_a6)[4].misc.b.draw_layer = 1U;
                    reg_d0.h[0] = 0x84;
                    explosion_spawn();
                    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)[4].y.h;
                    temp_a2_3 = ENTITY(reg_a6)[4].x.h;
                    *(u16 *)(reg_a0 + 4) = temp_a2_3;
                    *(s16 *)(reg_a0 + 0x12) = 0;
                    *(s16 *)(reg_a0 + 0x14) = 0x800;
                    *(s16 *)(reg_a0 + 0x1E) = 0x10;
                    *(s16 *)(reg_a0 + 0x10) = 2;
                    *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
                    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                    reg_d0.b[0] *= 4;
                    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                    sfx_explosion_air_small();
                }
            }
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x1A);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
            if ((s32) reg_tmp.w < 0) {
                reg_d0.w = 0x174;
                score_add();
                reg_a1 = (u8 *)((u16 *)D_00257D20);
loop_19:
                temp_a0 = *(u16 *)reg_a1;
                reg_d1.h[0] = temp_a0;
                reg_a1 += 2;
                if ((s16) reg_d1.h[0] != -1) {
                    reg_d0.h[0] = *(u16 *)reg_a1;
                    reg_a1 += 2;
                    explosion_spawn();
                    reg_d0.h[0] = *(u16 *)reg_a1;
                    reg_a1 += 2;
                    *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
                    *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                    reg_a1 += 2;
                    *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                    reg_a1 += 2;
                    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
                    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
                    *(s16 *)(reg_a0 + 0x1E) = 0x10;
                    *(s16 *)(reg_a0 + 0x12) = 0;
                    *(s16 *)(reg_a0 + 0x14) = 0;
                    *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
                    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                    reg_d0.b[0] *= 4;
                    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                    reg_a1 += 2;
                    goto loop_19;
                }
                sfx_explosion_ground_large();
                func_00155920();
                if (ENTITY(reg_a6)[6].hp.b[0] != 0) {
                    g_enemy_signal_e = 0;
                }
                g_enemy_signal_f = 0;
                g_enemy_signal_d = 0;
                ENTITY(reg_a6)->flags.h = 0x8000;
                ENTITY(reg_a6)[1].flags.h = 0x8000;
                ENTITY(reg_a6)[6].move.b.speed = 1U;
                goto block_24;
            }
        } else {
block_24:
            ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
            ENTITY(reg_a6)[2].attr.b.palette = (u8) ENTITY(reg_a6)[2].attr.b.flip;
            ENTITY(reg_a6)[3].attr.b.palette = (u8) ENTITY(reg_a6)[3].attr.b.flip;
            ENTITY(reg_a6)[4].attr.b.palette = (u8) ENTITY(reg_a6)[4].attr.b.flip;
            ENTITY(reg_a6)[5].attr.b.palette = (u8) ENTITY(reg_a6)[5].attr.b.flip;
        }
        if (ENTITY(reg_a6)[6].move.b.speed != 0) {
            ENTITY(reg_a6)[6].move.b.dir -= 1;
            if (ENTITY(reg_a6)[6].move.b.dir == 0) {
                enemy_remove();
                return;
            }
        }
        reg_d0.h[1] = *(u16 *)(reg_a5 + 0x1A);
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1C);
        func_00136980();
        if (g_enemies_stopped == 0) {
            reg_d0.h[0] = ENTITY(reg_a6)[2].y.h;
            reg_d1.h[0] = ENTITY(reg_a6)[2].x.h;
            aim_at_player();
            if (cond_flag == 0) {
                reg_d0.b[0] = ENTITY(reg_a6)[2].move.b.dir;
                direction_turn_toward();
                ENTITY(reg_a6)[2].move.b.dir = (u8) reg_d1.b[0];
                reg_d0.h[0] = ENTITY(reg_a6)[3].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[3].x.h;
                aim_at_player();
                reg_d0.b[0] = ENTITY(reg_a6)[3].move.b.dir;
                direction_turn_toward();
                ENTITY(reg_a6)[3].move.b.dir = (u8) reg_d1.b[0];
                reg_tmp.b[0] = ENTITY(reg_a6)[6].offset_y.b[1];
                ENTITY(reg_a6)[6].offset_y.b[1] -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    reg_d0.h[0] = 0x20;
                    reg_d0.h[0] -= g_rank_1_16;
                    ENTITY(reg_a6)[6].offset_y.b[1] = (u8) reg_d0.b[0];
                    if ((s16) ENTITY(reg_a6)[3].y.h > 0x1800) {
                        if ((ENTITY(reg_a6)[2].misc.b.draw_layer == 0) && (g_bullets_blocked == 0)) {
                            reg_d3.w = 0;
                            reg_a4 = D_00259570_as_u8_a;
                            reg_d3.b[0] = ENTITY(reg_a6)[2].move.b.dir;
                            reg_d3.b[0] += 1;
                            reg_d3.h[0] &= 0x3E;
                            reg_d3.h[0] += reg_d3.h[0];
                            reg_a4 += reg_d3.h[0];
                            reg_d5.h[1] = *(u16 *)reg_a4;
                            reg_d5.h[0] = *(u16 *)(reg_a4 + 2);
                            reg_d1.w = 0;
                            reg_d1.b[0] = ENTITY(reg_a6)[2].move.b.dir;
                            reg_d2.h[1] = ENTITY(reg_a6)[2].y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)[2].x.h;
                            reg_a0 = reg_a6 + 0x40;
                            func_00153770();
                        }
                        if ((ENTITY(reg_a6)[3].misc.b.draw_layer == 0) && (g_bullets_blocked == 0)) {
                            reg_d3.w = 0;
                            reg_a4 = D_00259570_as_u8_a;
                            reg_d3.b[0] = ENTITY(reg_a6)[3].move.b.dir;
                            reg_d3.b[0] += 1;
                            reg_d3.h[0] &= 0x3E;
                            reg_d3.h[0] += reg_d3.h[0];
                            reg_a4 += reg_d3.h[0];
                            reg_d5.h[1] = *(u16 *)reg_a4;
                            reg_d5.h[0] = *(u16 *)(reg_a4 + 2);
                            reg_d1.w = 0;
                            reg_d1.b[0] = ENTITY(reg_a6)[3].move.b.dir;
                            reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
                            reg_a0 = reg_a6 + 0x60;
                            func_00153770();
                        }
                    }
                }
                if (ENTITY(reg_a6)[4].misc.b.draw_layer == 0) {
                    reg_d0.h[0] = ENTITY(reg_a6)[4].y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)[4].x.h;
                    aim_at_player();
                    reg_d0.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                    direction_turn_toward();
                    ENTITY(reg_a6)[4].move.b.dir = (u8) reg_d1.b[0];
                    reg_tmp.b[0] = ENTITY(reg_a6)[6].offset_x.b[1];
                    ENTITY(reg_a6)[6].offset_x.b[1] -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        reg_d0.h[0] = 0x30;
                        reg_d0.h[0] -= g_rank_2_16;
                        ENTITY(reg_a6)[6].offset_x.b[1] = (u8) reg_d0.b[0];
                        if (((s16) ENTITY(reg_a6)[4].y.h > 0x1800) && (g_bullets_blocked == 0)) {
                            reg_d3.w = 0;
                            reg_a4 = D_002593F0;
                            reg_d3.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                            reg_d1.w = 0;
                            reg_d3.h[0] &= 0x3E;
                            reg_d3.h[0] *= 4;
                            reg_a4 += reg_d3.h[0];
                            reg_d1.b[0] = ENTITY(reg_a6)[4].move.b.dir;
                            reg_d1.b[0] += 1;
                            reg_d1.b[0] &= 0x3E;
                            reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
                            reg_d3.h[1] = *(u16 *)reg_a4;
                            reg_d3.h[0] = *(u16 *)(reg_a4 + 2);
                            reg_a0 = reg_a6 + 0x80;
                            reg_d0.w = 0x60004;
                            reg_d4.w = 0;
                            bullet_fire_2way();
                            reg_d0.w = 0x20004;
                            bullet_fire_2way();
                            reg_d1.b[0] += 2;
                            reg_d0.w = 0x60004;
                            bullet_fire_2way();
                            reg_d0.w = 0x20004;
                            bullet_fire_2way();
                            reg_d1.b[0] -= 4;
                            reg_d0.w = 0x60004;
                            bullet_fire_2way();
                            reg_d0.w = 0x20004;
                            bullet_fire_2way();
                        }
                    }
                }
                if (ENTITY(reg_a6)[5].misc.b.draw_layer == 0) {
                    if (ENTITY(reg_a6)[6].look.b.size == 0) {
                        reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
                        reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
                        aim_at_player();
                        reg_d0.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                        direction_turn_toward();
                        ENTITY(reg_a6)[5].move.b.dir = (u8) reg_d1.b[0];
                        ENTITY(reg_a6)[6].draw.b.priority -= 1;
                        if (ENTITY(reg_a6)[6].draw.b.priority == 0) {
                            ENTITY(reg_a6)[6].draw.b.priority = (u8) ENTITY(reg_a6)[6].draw.b.flip;
                            ENTITY(reg_a6)[6].look.b.size = (u8) ENTITY(reg_a6)[6].look.b.palette;
                            goto block_47;
                        }
                    } else {
block_47:
                        reg_tmp.b[0] = ENTITY(reg_a6)[6].sprite.b[1];
                        ENTITY(reg_a6)[6].sprite.b[1] -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            reg_d0.h[0] = 8;
                            reg_d1.h[0] = g_rank_1_16;
                            reg_d1.h[0] >>= 3;
                            reg_d0.h[0] -= reg_d1.h[0];
                            ENTITY(reg_a6)[6].sprite.b[1] = (u8) reg_d0.b[0];
                            if (((s16) ENTITY(reg_a6)[5].y.h > 0x1800) && (g_bullets_blocked == 0)) {
                                reg_d3.w = 0;
                                reg_a4 = D_002593F0;
                                reg_d3.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                                reg_d1.w = 0;
                                reg_d3.b[0] += 1;
                                reg_d3.h[0] &= 0x3E;
                                reg_d3.h[0] *= 4;
                                reg_a4 += reg_d3.h[0];
                                reg_d0.w = 0x10005;
                                reg_d1.b[0] = ENTITY(reg_a6)[5].move.b.dir;
                                reg_d1.b[0] += 1;
                                reg_d1.b[0] &= 0x3E;
                                reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
                                reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
                                reg_d3.h[1] = *(u16 *)reg_a4;
                                reg_d3.h[0] = *(u16 *)(reg_a4 + 2);
                                reg_a0 = reg_a6 + 0xA0;
                                reg_d4.w = 0;
                                bullet_fire_fast();
                                reg_d3.h[1] = *(u16 *)(reg_a4 + 4);
                                reg_d3.h[0] = *(u16 *)(reg_a4 + 6);
                                bullet_fire_fast();
                                ENTITY(reg_a6)[6].look.b.size -= 1;
                            }
                        }
                    }
                }
                reg_d0.b[0] = ENTITY(reg_a6)[5].misc.b.draw_layer;
                reg_d0.b[0] += ENTITY(reg_a6)[4].misc.b.draw_layer;
                reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
                reg_d0.b[0] += ENTITY(reg_a6)[2].misc.b.draw_layer;
                if (reg_d0.b[0] == 4) {
                    ENTITY(reg_a6)[6].hit_x_minus.sb[0] = 1;
                    if (ENTITY(reg_a6)[6].hit_x_plus.b[1] == 0) {
                        reg_tmp.b[0] = ENTITY(reg_a6)[6].hit_y_plus.b[1];
                        ENTITY(reg_a6)[6].hit_y_plus.b[1] -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            ENTITY(reg_a6)[6].hit_y_plus.b[1] = (u8) ENTITY(reg_a6)[6].hit_y_plus.b[0];
                            ENTITY(reg_a6)[6].hit_x_plus.b[1] = (u8) ENTITY(reg_a6)[6].hit_x_plus.b[0];
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0x400;
                            aim_at_player();
                            if (cond_flag == 0) {
                                ENTITY(reg_a6)[6].hit_x_minus.b[1] = (u8) reg_d1.b[0];
                            }
                            goto block_56;
                        }
                    } else {
block_56:
                        reg_tmp.b[0] = ENTITY(reg_a6)[6].hit_y_minus.b[1];
                        ENTITY(reg_a6)[6].hit_y_minus.b[1] -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            reg_d0.h[0] = 0x10;
                            reg_d1.h[0] = g_rank_1_16;
                            reg_d1.h[0] >>= 2;
                            reg_d0.h[0] -= reg_d1.h[0];
                            ENTITY(reg_a6)[6].hit_y_minus.b[1] = (u8) reg_d0.b[0];
                            temp_a3 = reg_a6 + 2;
                            if ((ENTITY(reg_a6)->y.sh > 0x1800) && (g_bullets_blocked == 0)) {
                                reg_d1.w = 0;
                                reg_d1.b[0] = ENTITY(reg_a6)[6].hit_x_minus.b[1];
                                reg_d0.w = 0x20004;
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                temp_a1_2 = ENTITY(reg_a6)->x.h;
                                reg_d2.h[0] = temp_a1_2;
                                reg_d5.w = 0x04000000;
                                reg_a0 = D_00259870_as_u8_a;
                                reg_d4.w = 0;
                                reg_d7.b[0] = reg_d1.b[0];
                                if (!(ENTITY(reg_a6)[6].hit_x_plus.b[1] & 1)) {
                                    ENTITY(reg_a6)[6].hp.sb[1] = 1;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] += 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] += 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] = reg_d7.b[0];
                                    reg_d1.b[0] -= 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] -= 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                } else {
                                    reg_d1.b[0] += 2;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] += 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] = reg_d7.b[0];
                                    reg_d1.b[0] -= 2;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                    reg_d1.b[0] -= 4;
                                    reg_d3.h[0] = reg_d1.h[0];
                                    reg_d3.h[0] &= 0x3F;
                                    reg_d3.h[0] *= 4;
                                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                    reg_d3.w += reg_d5.w;
                                    bullet_fire();
                                }
                                ENTITY(reg_a6)[6].hit_x_plus.b[1] -= 1;
                            }
                        }
                    }
                }
            }
        }
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.w += 0xDC00F600;
        reg_d3.h[0] = 0x2450;
        reg_d2.w = 0x18C9;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        sprite_draw_layer4_keep();
        func_001554E0();
        func_001555F0();
        func_00155810();
        func_00155700();
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
        reg_a0 = reg_a6 + 0x20;
        enemy_hitbox_debug_draw();
    }
}

extern u16 D_00259170[];

void func_001554E0(void) {
    u16 temp_a1;
    if (ENTITY(reg_a6)[2].misc.b.draw_layer == 0) {
        reg_d2.w = 0;
        reg_a0 = (u8 *)(D_00259170);
        reg_d2.b[0] = ENTITY(reg_a6)[2].move.b.dir;
        reg_d2.b[0] += 1;
        reg_d2.h[0] &= 0x3E;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = ENTITY(reg_a6)[2].y.h;
        temp_a1 = ENTITY(reg_a6)[2].x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[2].attr.b.palette;
        sprite_draw_layer4_keep();
    }
}

void func_001555F0(void) {
    u16 temp_a1;
    if (ENTITY(reg_a6)[3].misc.b.draw_layer == 0) {
        reg_d2.w = 0;
        reg_a0 = (u8 *)(D_00259170);
        reg_d2.b[0] = ENTITY(reg_a6)[3].move.b.dir;
        reg_d2.b[0] += 1;
        reg_d2.h[0] &= 0x3E;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = ENTITY(reg_a6)[3].y.h;
        temp_a1 = ENTITY(reg_a6)[3].x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[3].attr.b.palette;
        sprite_draw_layer4_keep();
    }
}

extern u16 D_00259070[];

void func_00155700(void) {
    u16 temp_a1;
    if (ENTITY(reg_a6)[4].misc.b.draw_layer == 0) {
        reg_d2.w = 0;
        reg_a0 = (u8 *)(D_00259070);
        reg_d2.b[0] = ENTITY(reg_a6)[4].move.b.dir;
        reg_d2.b[0] += 1;
        reg_d2.h[0] &= 0x3E;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = ENTITY(reg_a6)[4].y.h;
        temp_a1 = ENTITY(reg_a6)[4].x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[4].attr.b.palette;
        sprite_draw_layer4_keep();
    }
}

void func_00155810(void) {
    u16 temp_a1;
    if (ENTITY(reg_a6)[5].misc.b.draw_layer == 0) {
        reg_d2.w = 0;
        reg_a0 = (u8 *)(D_00259070);
        reg_d2.b[0] = ENTITY(reg_a6)[5].move.b.dir;
        reg_d2.b[0] += 1;
        reg_d2.h[0] &= 0x3E;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = ENTITY(reg_a6)[5].y.h;
        temp_a1 = ENTITY(reg_a6)[5].x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)[5].attr.b.palette;
        sprite_draw_layer4_keep();
    }
}

extern u16 D_00259970[];

void func_00155920(void) {
    u16 temp_a0;
    if (ENTITY(reg_a6)[6].hp.b[1] == 0) {
        temp_a0 = ENTITY(reg_a6)->y.h;
        if ((s16)(temp_a0) > 0x1000) {
            reg_d0.h[0] = temp_a0;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.h[0] += 0x400;
            aim_at_player();
            if (cond_flag == 0) {
                reg_d0.w = 0x40004;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d5.w = 0x04000000;
                reg_d4.w = 0;
                reg_d7.b[0] = reg_d1.b[0];
                reg_a0 = (u8 *)(D_00259970);
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
                reg_d1.b[0] += 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
                reg_d1.b[0] += 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
                reg_d1.b[0] += 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
                reg_d1.b[0] = reg_d7.b[0];
                reg_d1.b[0] -= 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
                reg_d1.b[0] -= 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
                reg_d1.b[0] -= 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                bullet_fire_2way();
            }
        }
    }
}

void stage3_gun_a_first(void) {
    enemy_set_entity_count(0);
}

extern u32 D_00257D70[];
extern u32 D_00257D90[];

void stage3_gun_a_start(void)
{
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
    reg_a0 = (u8 *)D_00257D90;
    enemy_init_entities();

    reg_a0 = (u8 *)D_00257D70;
    reg_d0.w = 0xD;
    enemy_set_task_state();
    enemy_path_start();

    if (enemy_move_end_requested == 0) {
        ENTITY(reg_a6)->x.h -= 0x280;
        ENTITY(reg_a6)->y.h -= 0x80;
    }
}

s32 bullet_fire256_fixed();
s32 bullet_fire256_2way();
s32 sfx_explosion_ground_medium();
s32 entity_follow_scroll();
s32 func_00202F50();
s32 func_002115E0();
extern u8 D_00257FB0[];
extern u8 D_00258030[];

void stage3_gun_a(void) {
    s32 enemy_remove();
    s32 sprite_draw_layer3_keep();
    u32 temp_a0;
    u32 temp_a0_3;
    u32 temp_a1;
    u32 temp_a0_2;
    u32 temp_a0_4;
    u32 temp_a0_5;

    if (ENTITY(reg_a6)->y.sh < -0x1800) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_4:
    entity_follow_scroll();
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1A);
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
        reg_d0.b[0] ^= reg_d2.b[0];
        *(u8 *)(reg_a5 + 0x1A) = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x47;
            score_add();
            ENTITY(reg_a6)->flags.h = 0x8000;
            *(u8 *)(reg_a5 + 0x1F) = 1U;
            reg_a1 = (u8 *)D_00258030;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_tmp.h[1] = ENTITY(reg_a6)->offset_y.h;
            temp_a0 = ENTITY(reg_a6)->offset_x.h;
            reg_tmp.h[0] = temp_a0;
            reg_d3.h[0] = 0xC;
            reg_d2.w += reg_tmp.w;
            func_00153650();
            reg_d0.w = 4;
            reg_d1.h[0] = 0xC;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0_2 = reg_d2.w;
            reg_tmp.h[1] = ENTITY(reg_a6)->offset_y.h;
            reg_tmp.h[0] = ENTITY(reg_a6)->offset_x.h;
            reg_d2.w = temp_a0_2 + reg_tmp.w;
            reg_d2.w += 0xFC000000;
            func_002115E0();
            sfx_explosion_ground_medium();
            goto block_7;
        }
    } else {
block_7:
        *(u8 *)(reg_a5 + 0x1A) = (u8) *(u8 *)(reg_a5 + 0x1D);
    }
    if (*(u8 *)(reg_a5 + 0x1F) == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        temp_a0_3 = reg_d0.h[0];
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] = temp_a0_3 + *(u32 *)(reg_a6 + 6);
        reg_d1.h[0] += ENTITY(reg_a6)->offset_x.h;
        aim_at_player();
        if (cond_flag == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
            direction_turn_toward();
            *(u8 *)(reg_a5 + 0x1B) = (u8) reg_d1.b[0];
            if (*(u8 *)(reg_a5 + 0x25) == 0) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
                *(u8 *)(reg_a5 + 0x21) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    reg_d0.h[0] = 0x18;
                    reg_d0.h[0] -= g_rank_1_16;
                    *(u8 *)(reg_a5 + 0x21) = (u8) reg_d0.b[0];
                    reg_d0.h[0] = 4;
                    reg_d1.h[0] = g_rank_1_16;
                    reg_d1.h[0] >>= 3;
                    reg_d0.h[0] -= reg_d1.h[0];
                    *(u8 *)(reg_a5 + 0x25) = (u8) reg_d0.b[0];
                    *(u8 *)(reg_a5 + 0x1E) = (u8) *(u8 *)(reg_a5 + 0x1B);
                    goto block_13;
                }
            } else {
block_13:
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                *(u8 *)(reg_a5 + 0x23) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                    func_00202F50();
                    if (cond_flag == 0) {
                        reg_d3.w = 0;
                        reg_a4 = (u8 *)D_00257FB0;
                        reg_d3.b[0] = *(u8 *)(reg_a5 + 0x1B);
                        reg_d3.b[0] += 1;
                        reg_d3.h[0] &= 0x3E;
                        reg_d3.h[0] += reg_d3.h[0];
                        reg_a4 += reg_d3.h[0];
                        reg_d3.h[1] = *(u16 *)reg_a4;
                        reg_d3.h[0] = *(u16 *)(reg_a4 + 2);
                        temp_a0_4 = reg_d3.w;
                        reg_tmp.h[1] = ENTITY(reg_a6)->offset_y.h;
                        temp_a1 = ENTITY(reg_a6)->offset_x.h;
                        reg_tmp.h[0] = temp_a1;
                        reg_d0.w = 0xA0016;
                        reg_d1.w = 0;
                        reg_d3.w = temp_a0_4 + reg_tmp.w;
                        reg_d1.b[0] = *(u8 *)(reg_a5 + 0x1B);
                        reg_d1.b[0] += 1;
                        reg_d1.h[0] &= 0x3E;
                        reg_d1.h[0] *= 4;
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d4.w = 0;
                        bullet_fire256_fixed();
                        reg_d1.b[0] += 2;
                        bullet_fire256_2way();
                        reg_d1.b[0] -= 4;
                        bullet_fire256_2way();
                        *(u8 *)(reg_a5 + 0x25) -= 1;
                    }
                }
            }
        }
    }
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    temp_a0_5 = reg_d1.w;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x2C);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x2E);
    reg_d1.w = temp_a0_5 + reg_tmp.w;
    reg_d3.h[0] = *(u16 *)(reg_a5 + 0x26);
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x28);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x2A);
    reg_d4.w = 0;
    reg_d4.h[0] = 0x15;
    sprite_draw_layer3_keep();
    func_001563B0();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

s32 sprite_draw_layer5_keep();
extern u16 D_00257DB0[];

void func_001563B0(void) {
    u16 temp_a2;
    u32 temp_a1;

    if (*(u8 *)(reg_a5 + 0x1F) == 0) {
        *(u16 *)(reg_a5 + 0x30) += 4;
        *(u16 *)(reg_a5 + 0x30) &= 0xF;
        reg_a0 = (u8 *)(D_00257DB0);
        reg_d2.w = 0;
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1B);
        reg_d2.b[0] += 1;
        reg_d2.h[0] &= 0x3E;
        reg_d2.h[0] *= 4;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[0] += *(u16 *)(reg_a5 + 0x30);
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        temp_a1 = reg_d1.w;
        reg_tmp.h[1] = ENTITY(reg_a6)->offset_y.h;
        temp_a2 = ENTITY(reg_a6)->offset_x.h;
        reg_tmp.h[0] = temp_a2;
        reg_d4.w = 0;
        reg_d1.w = temp_a1 + reg_tmp.w;
        reg_d1.w += 0xF400F600;
        reg_d3.h[0] = 0xC50;
        reg_d4.b[0] = *(u8 *)(reg_a5 + 0x1A);
        sprite_draw_layer5_keep();
    }
}

void enemy_set_entity_count(s32);

void stage3_gun_b_first(void) {
    enemy_set_entity_count(0);
}

extern u8 D_00258040[];
extern u8 D_00258060[];

void stage3_gun_b_start(void)
{
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
    reg_a0 = D_00258060;
    enemy_init_entities();

    reg_a0 = D_00258040;
    reg_d0.w = 0xD;
    enemy_set_task_state();
    enemy_path_start();

    if (enemy_move_end_requested == 0) {
        ((u16 *)reg_a6)[1] -= 0x180;
    }
}

void stage3_gun_c_first(void) {
    enemy_set_entity_count(0);
}

extern u8 D_00258080[];
extern u8 D_002580A0[];


void stage3_gun_c_start(void)
{
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
    reg_a0 = D_002580A0;
    enemy_init_entities();

    reg_a0 = D_00258080;
    reg_d0.w = 0xD;
    enemy_set_task_state();
    enemy_path_start();

    if (enemy_move_end_requested == 0) {
        ((u16 *)reg_a6)[1] -= 0x400;
    }
}

void stage3_gun_d_first(void) {
    enemy_set_entity_count(0);
}

extern u8 D_002580C0[];
extern u8 D_002580E0[];

void stage3_gun_d_start(void)
{
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
    reg_a0 = D_002580E0;
    enemy_init_entities();

    reg_a0 = D_002580C0;
    reg_d0.w = 0xD;
    enemy_set_task_state();
    enemy_path_start();

    if (enemy_move_end_requested == 0) {
        ENTITY(reg_a6)->x.h -= 0x400;
        ENTITY(reg_a6)->y.h -= 0x600;
    }
}

extern u16 g_loop;

void func_00156690(void) {
    reg_d6.sw = 0;
    if (g_loop != 0) {
        reg_d6.sw = 0x20000;
    }
}

void stage3_large_gun_first(void) {
    enemy_set_entity_count(0);
}

s32 rng_next_unsigned();
extern u8 D_00258100[];
extern u8 D_00258130[];
extern s16 g_enemy_signal_2_as_s16;
extern s16 g_enemy_signal_1_as_s16;
extern s16 g_enemy_signal_0_as_s16;
extern s16 D_00299768[];

void stage3_large_gun_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = D_00258130;
    enemy_init_entities();
    reg_a0 = D_00258100;
    reg_d0.w = 0x14;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        D_00299768[0] = 1;
        reg_d0.h[0] = g_scroll_line;
        *(u16 *)(reg_a5 + 0x3A) = (u16) reg_d0.h[0];
        if (reg_d0.h[0] == 0x48) {
            g_enemy_signal_0_as_s16 = 1;
            g_enemy_signal_1_as_s16 = 1;
            g_enemy_signal_2_as_s16 = 1;
            ENTITY(reg_a6)->y.h += 0x900;
            ENTITY(reg_a6)->x.h -= 0x100;
        }
        if (reg_d0.h[0] == 0x8D) {
            g_enemy_signal_1_as_s16 = 1;
            ENTITY(reg_a6)->y.h += 0x900;
            ENTITY(reg_a6)->x.h -= 0x100;
        }
        if (reg_d0.h[0] == 0xAC) {
            g_enemy_signal_2_as_s16 = 1;
            ENTITY(reg_a6)->y.h += 0x900;
            ENTITY(reg_a6)->x.h -= 0x100;
        }
        *(u8 *)(reg_a5 + 0x39) = 0xFE;
        rng_next_unsigned();
        if ((s8) reg_d0.b[0] < 0) {
            *(s8 *)(reg_a5 + 0x39) = 2;
        }
    }
}

void func_00156810(void) {
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x3A);
    if (reg_d0.h[0] == 0x48) {
        g_enemy_signal_0_as_s16 = 0;
    }
    if (reg_d0.h[0] == 0x8D) {
        g_enemy_signal_1_as_s16 = 0;
    }
    if (reg_d0.h[0] == 0xAC) {
        g_enemy_signal_2_as_s16 = 0;
    }
}

s32 velocity_from_dir256();
extern u8 D_00258150[];
extern u8 D_00258190[];
extern u8 D_002581D0[];
extern u16 g_rank;
extern u16 g_bomb_entities[];

void stage3_large_gun(void) {
    s32 enemy_remove();
    s32 sprite_draw_layer3_keep();
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a0_6;
    u32 temp_a0_7;
    u32 temp_a0_8;
    u32 temp_a0_9;

    if (ENTITY(reg_a6)->y.sh < -0x2200) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            func_00156810();
            enemy_remove();
            return;
        }
        goto block_4;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_4:
    entity_follow_scroll();
    if (*(s16 *)(reg_a5 + 0x3E) >= 0) {
        ENTITY(reg_a6)->hp.sh = 0x7FFF;
        reg_d0.h[0] = 1;
        if (g_bomb_entities[0] != 0) {
            reg_d0.h[0] = 2;
        }
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x3E);
        *(u16 *)(reg_a5 + 0x3E) -= reg_d0.h[0];
        if ((s32) reg_tmp.h[0] < (s32) reg_d0.h[0]) {
            ENTITY(reg_a6)->hp.sh = 0x1C00;
        }
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1A);
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
        reg_d0.b[0] ^= reg_d2.b[0];
        *(u8 *)(reg_a5 + 0x1A) = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x632;
            score_add();
            func_00156810();
            reg_a1 = (u8 *)D_002581D0;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.h[0] = 0xC;
            func_00153650();
            sfx_explosion_ground_large();
            enemy_remove();
            return;
        }
        goto block_13;
    }
    *(u8 *)(reg_a5 + 0x1A) = (u8) *(u8 *)(reg_a5 + 0x1D);
block_13:
    *(u8 *)(reg_a5 + 0x1B) += 1;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x39);
    *(u8 *)(reg_a5 + 0x16) += reg_d0.b[0];
    reg_d7.h[0] = 0x40;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x1B);
    velocity_from_dir256();
    temp_a0_2 = (s16) reg_d2.h[0] * 4;
    reg_d2.h[0] = temp_a0_2;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    reg_d2.h[0] += 0x400;
    *(u16 *)(reg_a5 + 0x28) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a5 + 0x2A) = (u16) reg_d3.h[0];
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x1B);
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0x40;
    reg_d1.h[0] = (u16) reg_d1.b[0];
    velocity_from_dir256();
    temp_a0_3 = (s16) reg_d2.h[0] * 4;
    reg_d2.h[0] = temp_a0_3;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    reg_d2.h[0] += 0x400;
    *(u16 *)(reg_a5 + 0x2C) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a5 + 0x2E) = (u16) reg_d3.h[0];
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x1B);
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0x80;
    reg_d1.h[0] = (u16) reg_d1.b[0];
    velocity_from_dir256();
    temp_a0_4 = (s16) reg_d2.h[0] * 4;
    reg_d2.h[0] = temp_a0_4;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    reg_d2.h[0] += 0x400;
    *(u16 *)(reg_a5 + 0x30) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a5 + 0x32) = (u16) reg_d3.h[0];
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x1B);
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0xC0;
    reg_d1.h[0] = (u16) reg_d1.b[0];
    velocity_from_dir256();
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] = (s16) reg_d3.h[0] * 4;
    reg_d2.h[0] += 0x400;
    *(u16 *)(reg_a5 + 0x34) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a5 + 0x36) = (u16) reg_d3.h[0];
    if (*(u8 *)(reg_a5 + 0x27) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
        *(u8 *)(reg_a5 + 0x1F) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
            *(u8 *)(reg_a5 + 0x27) = (u8) *(u8 *)(reg_a5 + 0x26);
            reg_d0.h[0] = 4;
            if ((s32) g_rank >= 0xC0) {
                reg_d0.h[0] = 3;
                if ((s32) g_rank >= 0xE0) {
                    reg_d0.h[0] = 2;
                }
            }
            *(u8 *)(reg_a5 + 0x24) = (u8) reg_d0.b[0];
            goto block_19;
        }
    } else {
block_19:
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
        *(u8 *)(reg_a5 + 0x25) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
            if (ENTITY(reg_a6)->y.sh > 0x1800) {
                reg_d1.w = 0;
                reg_d1.b[0] = *(u8 *)(reg_a5 + 0x16);
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d5.h[0] = 0x40;
                reg_d4.w = 0;
                if ((s8) *(u8 *)(reg_a5 + 0x39) < 0) {
                    reg_d5.h[0] *= 0xFFFF;
                }
                reg_d3.h[1] = *(u16 *)(reg_a5 + 0x28);
                reg_d3.h[0] = *(u16 *)(reg_a5 + 0x2A);
                func_00156690();
                reg_d0.w = 0x20004;
                reg_d0.w += reg_d6.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += reg_d5.b[0];
                func_00156690();
                reg_d0.w = 4;
                reg_d0.w += reg_d6.w;
                bullet_fire256_2way();
                reg_d3.h[1] = *(u16 *)(reg_a5 + 0x2C);
                reg_d3.h[0] = *(u16 *)(reg_a5 + 0x2E);
                func_00156690();
                reg_d0.w = 0x20004;
                reg_d0.w += reg_d6.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += reg_d5.b[0];
                func_00156690();
                reg_d0.w = 4;
                reg_d0.w += reg_d6.w;
                bullet_fire256_2way();
                reg_d3.h[1] = *(u16 *)(reg_a5 + 0x30);
                reg_d3.h[0] = *(u16 *)(reg_a5 + 0x32);
                func_00156690();
                reg_d0.w = 0x20004;
                reg_d0.w += reg_d6.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += reg_d5.b[0];
                func_00156690();
                reg_d0.w = 4;
                reg_d0.w += reg_d6.w;
                bullet_fire256_2way();
                reg_d3.h[1] = *(u16 *)(reg_a5 + 0x34);
                reg_d3.h[0] = *(u16 *)(reg_a5 + 0x36);
                func_00156690();
                reg_d0.w = 0x20004;
                reg_d0.w += reg_d6.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += reg_d5.b[0];
                func_00156690();
                reg_d0.w = 4;
                reg_d0.w += reg_d6.w;
                bullet_fire256_2way();
                *(u8 *)(reg_a5 + 0x27) -= 1;
            }
        }
    }
    *(u16 *)(reg_a5 + 0x3C) += 4;
    *(u16 *)(reg_a5 + 0x3C) &= 0x3C;
    reg_a0 = (u8 *)D_00258150;
    reg_a0 += *(u16 *)(reg_a5 + 0x3C);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0_5 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0_5;
    reg_d1.w += 0xDE00EB00;
    reg_d3.h[0] = 0x22A8;
    reg_d4.w = 0;
    reg_d4.b[0] = *(u8 *)(reg_a5 + 0x1A);
    sprite_draw_layer3_keep();
    reg_a0 = (u8 *)D_00258190;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = *(u16 *)(reg_a5 + 0x28);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x2A);
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0_6 = ENTITY(reg_a6)->x.h;
    reg_tmp.h[0] = temp_a0_6;
    reg_d4.w = 0;
    reg_d1.w += reg_tmp.w;
    reg_d1.w += 0xFC00FD00;
    reg_d3.h[0] = 0x418;
    reg_d4.b[0] = *(u8 *)(reg_a5 + 0x1A);
    sprite_draw_layer4_keep();
    reg_d1.h[1] = *(u16 *)(reg_a5 + 0x2C);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x2E);
    temp_a0_7 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w = temp_a0_7 + reg_tmp.w;
    reg_d1.w += 0xFC00FD00;
    sprite_draw_layer4_keep();
    reg_d1.h[1] = *(u16 *)(reg_a5 + 0x30);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x32);
    temp_a0_8 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w = temp_a0_8 + reg_tmp.w;
    reg_d1.w += 0xFC00FD00;
    sprite_draw_layer4_keep();
    reg_d1.h[1] = *(u16 *)(reg_a5 + 0x34);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x36);
    temp_a0_9 = reg_d1.w;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w = temp_a0_9 + reg_tmp.w;
    reg_d1.w += 0xFC00FD00;
    sprite_draw_layer4_keep();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

s32 bullet_fire_fixed();
s32 rng_next_masked();

void func_001570B0(void) {
    u8 var_a0;

    rng_next_masked();
    var_a0 = reg_d0.b[0];
    reg_d1.b[0] = var_a0;
    reg_d0.w = 0xFFFC0005;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d7.w = 0xF;
    reg_d3.w = 0;
    reg_d4.w = 0;
    do {
        bullet_fire_fixed();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void func_00157140(void) {
    rng_next_masked();
    reg_d1.b[0] = reg_d0.b[0];
    reg_d0.w = 0x80004;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d7.w = 0xF;
    reg_d4.w = 0;
    reg_d3.w = 0;
    do {
        bullet_fire_fixed();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void func_001571D0(void) {
    enemy_set_entity_count(1);
}

extern u8 D_00258220[];
extern u8 D_00258240[];
extern s16 g_scroll_line_as_s16;

void func_001571E0(void) {
    s32 enemy_remove();
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = D_00258240;
    enemy_init_entities();
    reg_a0 = D_00258220;
    reg_d0.w = 9;
    enemy_set_task_state();
    enemy_path_start();
    if ((enemy_move_end_requested == 0) && (g_scroll_line_as_s16 > 0x10) && (g_scroll_line_as_s16 < 0x36) && (g_enemy_signal_d != 0)) {
        enemy_remove();
    }
}

s32 bullet_fire256_3way();
s32 bullet_fire256();
s32 sfx_explosion_ground_small();
s32 entity_velocity();
s32 func_00202490();
s32 entity_check_bounds();
extern u8 D_00259970_as_u8_a[];
extern u16 g_rank_3_16;
extern u16 g_stage;

void func_00157260(void) {
    s32 enemy_remove();
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a1;
    u16 temp_v1;

    entity_check_bounds();
    if (cond_flag != 0) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_4:
    entity_velocity();
    temp_v1 = *(u16 *)(reg_a5 + 0x1C);
    if ((temp_v1 != 0) && (g_enemies_stopped == 0)) {
        *(u16 *)(reg_a5 + 0x1C) = (u16) (temp_v1 - 1);
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
        *(u8 *)(reg_a5 + 0x1B) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
            func_00202490();
        }
    }
    ENTITY(reg_a6)[1].y.h = (u16) ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[1].x.h = (u16) ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
        reg_d0.b[0] ^= reg_d2.b[0];
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        reg_d2.w = 0x7FFF;
        reg_d2.h[0] -= ENTITY(reg_a6)->hp.h;
        reg_d3.w = 0x7FFF;
        reg_d3.h[0] -= ENTITY(reg_a6)[1].hp.h;
        if ((s32) reg_d2.w < (s32) reg_d3.w) {
            reg_d2.w = reg_d3.w;
        }
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x26);
        reg_tmp.w -= reg_d2.w;
        *(u16 *)(reg_a5 + 0x24) = (u16) reg_tmp.h[1];
        temp_a0 = reg_tmp.h[0];
        *(u16 *)(reg_a5 + 0x26) = temp_a0;
        reg_d0.h[0] = 0x7FFF;
        ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[1].hp.h = (u16) reg_d0.h[0];
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x26);
        if ((s32) reg_tmp.w < 0) {
            reg_d0.w = 0x19;
            score_add();
            reg_d0.h[0] = 0x82;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a0_2 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a0_2;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d0.b[0] *= 4;
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            sfx_explosion_ground_small();
            enemy_remove();
            return;
        }
        goto block_14;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
block_14:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        reg_d0.h[0] = 0x30;
        reg_d0.h[0] -= g_rank_3_16;
        reg_d0.h[0] += 0xA;
        *(u8 *)(reg_a5 + 0x1F) = (u8) reg_d0.b[0];
        *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
        *(u8 *)(reg_a5 + 0x16) = (u8) ENTITY(reg_a6)->move.b.dir;
        if ((s16) ENTITY(reg_a6)->y.h >= 0x2800) {
            reg_d1.w = 0;
            reg_d1.b[0] = *(u8 *)(reg_a5 + 0x16);
            reg_d1.b[0] *= 4;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            reg_d2.h[0] = temp_a1;
            reg_a0 = (u8 *)D_00259970_as_u8_a;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            *(u8 *)(reg_a5 + 0x23) -= 1;
            if (g_stage != 4) {
                reg_d0.w = 0x2000C;
                bullet_fire256_3way();
                reg_d1.b[0] += 8;
                bullet_fire256_fixed();
                reg_d1.b[0] -= 0x10;
                bullet_fire256_fixed();
            } else {
                reg_d0.w = 0x6000C;
                reg_d7.h[0] = reg_d1.h[0];
                bullet_fire256();
                reg_d1.b[0] += 8;
                bullet_fire256();
                reg_d1.b[0] -= 0x10;
                bullet_fire256();
                reg_d0.w = 0x4000D;
                reg_d1.h[0] = reg_d7.h[0];
                reg_d1.b[0] += 4;
                bullet_fire256();
                reg_d1.h[0] = reg_d7.h[0];
                reg_d1.b[0] -= 4;
                bullet_fire256();
            }
        }
    }
    func_00157740();
}

s32 sprite_draw_layer5();
extern u16 D_00258280[];
extern u16 g_game_frame;

void func_00157740(void) {
    u16 temp_a1;
    if (g_game_frame & 1) {
        *(u16 *)(reg_a5 + 0x28) += 4;
        *(u16 *)(reg_a5 + 0x28) &= 7;
    }
    reg_d0.w = 0;
    reg_a0 = (u8 *)(D_00258280);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d0.b[0] += 1;
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] *= 4;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x28);
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a1;
    reg_d1.w += 0xFA00FB00;
    reg_d3.h[0] = 0x628;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer5();
    reg_a0 = (u8 *)(reg_a6);
    enemy_hitbox_debug_draw();
}

void func_001578A0(void) {
    enemy_set_entity_count(1);
}

s32 rng_next_word();
extern u8 D_00258380[];
extern u8 D_002583A0[];
extern u16 g_side_scroll_x[];

void func_001578B0(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = D_002583A0;
    enemy_init_entities();
    reg_a0 = D_00258380;
    reg_d0.w = 9;
    enemy_set_task_state();
    if (g_stage == 4) {
        *(s8 *)(reg_a5 + 0x19) = 0xF;
        *(s8 *)(reg_a5 + 0x18) = 0x10;
        reg_tmp.w = 0x74001C00;
        ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
        reg_d0.h[0] = g_side_scroll_x[0];
        ENTITY(reg_a6)->x.h -= reg_d0.h[0];
        goto block_3;
    }
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
block_3:
        rng_next_word();
        reg_d0.h[0] += 0x1C00;
        ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)->move.sh = 0x2820;
    }
}

s32 bullet_fire_3way();

void func_001579A0(void) {
    s32 enemy_remove();
    u16 temp_a0;
    u16 temp_v1;
    u8 temp_a0_2;
    u8 *var_a0;
    u8 *var_a1;

    entity_check_bounds();
    if (cond_flag != 0) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_4:
    entity_velocity();
    temp_v1 = *(u16 *)(reg_a5 + 0x1C);
    if ((temp_v1 != 0) && (g_enemies_stopped == 0)) {
        *(u16 *)(reg_a5 + 0x1C) = (u16) (temp_v1 - 1);
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
        *(u8 *)(reg_a5 + 0x1B) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
            func_00202490();
        }
    }
    ENTITY(reg_a6)[1].y.h = (u16) ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[1].x.h = (u16) ENTITY(reg_a6)->x.h;
    var_a0 = (u8 *)(reg_a6);
    reg_d1.b[0] = (*(u8 *)((u8 *)(var_a0) + (1)));
    reg_d1.b[0] |= (*(u8 *)((u8 *)(var_a0) + (0x21)));
    reg_d1.h[0] &= 0x5C;
    var_a1 = (u8 *)(var_a0 + 1);
    if (reg_d1.h[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(var_a0) + (1))) &= reg_d0.b[0];
        ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
        reg_d0.b[0] ^= reg_d2.b[0];
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        reg_d2.w = 0x7FFF;
        reg_d2.h[0] -= ENTITY(reg_a6)->hp.h;
        reg_d3.w = 0x7FFF;
        reg_d3.h[0] -= ENTITY(reg_a6)[1].hp.h;
        if ((s32) reg_d2.w < (s32) reg_d3.w) {
            reg_d2.w = reg_d3.w;
        }
        var_a1 = (u8 *)(reg_a5);
        reg_tmp.h[1] = (*(u16 *)((u8 *)(var_a1) + (0x24)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(var_a1) + (0x26)));
        reg_tmp.w -= reg_d2.w;
        (*(u16 *)((u8 *)(var_a1) + (0x24))) = (u16) reg_tmp.h[1];
        var_a0 = (u8 *)((void *) reg_tmp.h[0]);
        *(u16 *)(reg_a5 + 0x26) = (u16) var_a0;
        reg_d0.h[0] = 0x7FFF;
        ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
        ENTITY(reg_a6)[1].hp.h = (u16) reg_d0.h[0];
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x26);
        if ((s32) reg_tmp.w < 0) {
            reg_d0.w = 0x19;
            score_add();
            reg_d0.h[0] = 0x82;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a0 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a0;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d0.b[0] *= 4;
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            sfx_explosion_ground_small();
            if ((s32) ENTITY(reg_a6)->y.h >= 0x3200) {
                reg_d1.w = 0;
                reg_d0.w = 0x1000C;
                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0;
                bullet_fire_2way();
            }
            enemy_remove();
            return;
        }
        goto block_16;
    }
    (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) *(u8 *)(reg_a5 + 0x19);
block_16:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
    *(u8 *)(reg_a5 + 0x21) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
        func_00202F50();
        if (cond_flag == 0) {
            reg_d1.w = 0;
            temp_a0_2 = ENTITY(reg_a6)->move.b.dir;
            reg_d1.b[0] = temp_a0_2;
            if (g_stage != 4) {
                reg_d0.w = 0x1000C;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0;
                bullet_fire_3way();
            } else {
                reg_d0.w = 0xFFFC000C;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0;
                bullet_fire_2way();
                reg_d1.h[0] += 2;
                bullet_fire_fast();
                reg_d1.h[0] -= 4;
                bullet_fire_2way();
            }
        }
    }
    func_00157740();
}

void func_00157D80(void) {
    enemy_set_entity_count(0);
}

s32 enemy_init_entities();                            /* extern */
extern s32 D_002583E0[];

void func_00157D90(void) {
    reg_a0 = (u8 *)D_002583E0;
    enemy_init_entities();
    *(s16 *)(reg_a5 + 0x18) = 6;
}

s32 spawn_request_add();
extern u16 g_enemy_signal_0;

void func_00157DC0() {
    s32 enemy_remove();
    if (g_scroll_line_as_s16 >= 0x9C) {
        enemy_remove();
        return;
    }
    if ((g_enemies_stopped == 0) && (g_enemy_signal_0 == 0)) {
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
        *(u8 *)(reg_a5 + 0x19) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x19) = (u8) *(u8 *)(reg_a5 + 0x18);
            reg_d0.w = 0x3F;
            spawn_request_add();
        }
    }
}

void stage3_cloud_first(void) {
    enemy_set_entity_count(1);
}

extern u8 D_00258400[];
extern u8 D_00258410[];
extern u16 g_side_scroll_x_prev[];

void stage3_cloud_start(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    reg_a0 = D_00258410;
    enemy_init_entities();
    reg_a0 = D_00258400;
    reg_d0.w = 6;
    enemy_set_task_state();
    reg_tmp.w = 0x70000000;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    reg_d1.w = 0;
    reg_d1.h[0] -= 0x800;
    reg_d1.h[0] -= g_side_scroll_x_prev[0];
    ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
    ENTITY(reg_a6)[1].y.h = (u16) ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[1].x.h = (u16) ENTITY(reg_a6)->x.h;
}

s32 entity_draw_layer3_keep();
s32 velocity_from_direction();
extern u8 D_00258450[];

void stage3_cloud(void) {
    s32 enemy_remove();
    u16 t1;

    if (g_scroll_line == 0x118) {
        enemy_remove();
        return;
    }
    if (g_enemies_stopped == 0) {
        if (*(s16 *)(reg_a5 + 0x1E) < 2) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
            *(u8 *)(reg_a5 + 0x21) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
            }
        }
        reg_d1.w = 0;
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        velocity_from_direction();
        ENTITY(reg_a6)->y.h += reg_d2.h[0];
        ENTITY(reg_a6)[1].y.h += reg_d2.h[0];
        ENTITY(reg_a6)[1].x.h = (u16) ENTITY(reg_a6)->x.h;
        *(u16 *)(reg_a5 + 0x18) += reg_d2.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
        reg_d0.h[0] *= -1;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7000;
        reg_tmp.w = 0;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] -= 0x7000;
        reg_tmp.w -= reg_tmp1.sw;
        if (reg_tmp.h[1] == 0) {
            reg_d0.h[0] *= -1;
            *(u16 *)(reg_a5 + 0x18) = (u16) reg_d0.h[0];
            reg_a0 = reg_a6;
            reg_a0 += *(u16 *)(reg_a5 + 0x1A);
            *(u16 *)(reg_a5 + 0x1A) += 0x20;
            *(u16 *)(reg_a5 + 0x1A) &= 0x3F;
            *(s8 *)(reg_a0 + 0x1E) = 1;
            reg_d1.h[0] = 0x7000;
            reg_d1.h[0] += reg_d0.h[0];
            *(u16 *)(reg_a0 + 2) = (u16) reg_d1.h[0];
            reg_a1 = (u8 *)D_00258450;
            reg_a1 += *(u16 *)(reg_a5 + 0x1C);
            *(u16 *)(reg_a0 + 0xA) = (u16) *(u16 *)reg_a1;
            *(u16 *)(reg_a0 + 0xC) = (u16) *(u16 *)(reg_a1 + 2);
            if ((*(u16 *)(reg_a5 + 0x1C) == 0) && (g_enemy_signal_e == 0)) {
                t1 = *(u16 *)(reg_a5 + 0x1E);
                if (t1 != 0) {
                    *(s16 *)(reg_a5 + 0x1E) = (s16) (t1 - 1);
                    if (*(u16 *)(reg_a5 + 0x1E) == 0) {
                        *(u16 *)(reg_a5 + 0x22) = 1U;
                    }
                }
            }
            *(u16 *)(reg_a5 + 0x1C) += 4;
            *(u16 *)(reg_a5 + 0x1C) &= 0xF;
            if (*(u16 *)(reg_a5 + 0x22) != 0) {
                *(s8 *)(reg_a0 + 0x1E) = 0;
            }
        }
    }
    reg_d7.w = 1;
    do {
        if (ENTITY(reg_a6)->misc.b.draw_layer != 0) {
            entity_draw_layer3_keep();
        }
        reg_a6 += 0x20;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void func_001581E0(void) {
    enemy_set_entity_count(0);
}

s32 enemy_request_start();
s32 enemy_request_start_flags();
extern u8 D_00258460[];
extern u8 D_00258490[];

void func_001581F0(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)D_00258490;
    enemy_init_entities();
    reg_a0 = (u8 *)D_00258460;
    reg_d0.w = 0x10;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_scroll_line == 0x168) {
            reg_d0.w = 0x18;
            enemy_request_start();
            *(u16 *)(reg_a0 + 0x16) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 0x18) = (u16) ENTITY(reg_a6)->x.h;
            reg_tmp.h[1] = *(u16 *)(reg_a0 + 0x16);
            reg_tmp.h[0] = *(u16 *)(reg_a0 + 0x18);
            reg_tmp.w += 0x10000400;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_tmp.h[0];
            *(u16 *)(reg_a0 + 0x1A) = (u16) ENTITY(reg_a6)->move.h;
            *(u16 *)(reg_a0 + 0x1C) = ENTITY(reg_a6)->attr.h;
        } else {
            reg_d0.w = 0x17;
            reg_d1.h[0] = 0x20;
            enemy_request_start_flags();
            *(u16 *)(reg_a0 + 0x16) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 0x18) = (u16) ENTITY(reg_a6)->x.h;
            reg_tmp.h[1] = *(u16 *)(reg_a0 + 0x16);
            reg_tmp.h[0] = *(u16 *)(reg_a0 + 0x18);
            reg_tmp.w += 0x10000400;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_tmp.h[0];
            *(u16 *)(reg_a0 + 0x1A) = (u16) ENTITY(reg_a6)->move.h;
            *(u16 *)(reg_a0 + 0x1C) = ENTITY(reg_a6)->attr.h;
        }
    }
}

void sprite_draw_layer1_keep(void);

void func_00158370(void) {
    void enemy_remove(void);
    void enemy_path_step(void);
    void sprite_draw_layer3_keep(void);
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    if ((s16) reg_d2.h[0] >= 0x6000) {
        goto next_1;
    }
    if ((s16) reg_d2.h[0] <= -0x2800) {
        goto next_1;
    }
    if ((s16) reg_d1.h[0] <= -0x3C00) {
        goto next_1;
    }
    *(u8 *)(reg_a5 + 0x17) = 1;
    goto next_2;
next_1:
    if (*(u8 *)(reg_a5 + 0x17) == 0) {
        goto next_2;
    }
    enemy_remove();
    return;
next_2:
    enemy_path_step();
    if (enemy_move_end_requested != 0) {
        return;
    }
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    reg_d2.w = 0x1CBB;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] -= 0x2800;
    reg_d7.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d6.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((s16) reg_d7.h[0] <= -0x2800) {
        goto next_3;
    }
    if ((s16) reg_d7.h[0] >= 0x3900) {
        goto next_3;
    }
    if ((s16) reg_d6.h[0] <= -0x3C00) {
        goto next_3;
    }
    if ((s16) reg_d6.h[0] >= 0x7000) {
        goto next_3;
    }
    reg_d3.h[0] = 0x1EA0;
    sprite_draw_layer1_keep();
next_3:
    reg_d2.w = 0x1CBC;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d7.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d6.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((s16) reg_d7.h[0] <= -0x2800) {
        goto next_4;
    }
    if ((s16) reg_d7.h[0] >= 0x3900) {
        goto next_4;
    }
    if ((s16) reg_d6.h[0] <= -0x3C00) {
        goto next_4;
    }
    if ((s16) reg_d6.h[0] >= 0x7000) {
        goto next_4;
    }
    reg_d3.h[0] = 0x1EA0;
    sprite_draw_layer1_keep();
next_4:
    reg_d2.w = 0x1CBD;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w -= 0x2C002000;
    reg_d7.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d6.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((s16) reg_d7.h[0] <= -0x2400) {
        goto next_5;
    }
    if ((s16) reg_d7.h[0] >= 0x3900) {
        goto next_5;
    }
    if ((s16) reg_d6.h[0] <= -0x4000) {
        goto next_5;
    }
    if ((s16) reg_d6.h[0] >= 0x7000) {
        goto next_5;
    }
    reg_d3.h[0] = 0x2090;
    sprite_draw_layer3_keep();
next_5:
    reg_d2.w = 0x1CBE;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w -= 0x2BFFFC00;
    reg_d7.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d6.h[0] = reg_d1.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((s16) reg_d7.h[0] <= -0x2400) {
        return;
    }
    if ((s16) reg_d7.h[0] >= 0x3900) {
        return;
    }
    if ((s16) reg_d6.h[0] <= -0x4000) {
        return;
    }
    if ((s16) reg_d6.h[0] >= 0x7000) {
        return;
    }
    reg_d3.h[0] = 0x2090;
    sprite_draw_layer3_keep();
}

void battleship_b_first(void) {
    enemy_set_entity_count(1);
}

extern u8 D_002584B0[];
extern u8 D_002584E0[];
extern s16 g_slowdown_boss_allowed;

void battleship_b_start() {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    u16 temp_a1;

    reg_a0 = D_002584E0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    temp_a1 = *(u16 *)(reg_a5 + 0x1A);
    ENTITY(reg_a6)->move.h = temp_a1;
    reg_a0 = D_002584B0;
    reg_d0.w = 0x11;
    enemy_set_task_state();
    D_00299768[0] = 1;
    g_slowdown_boss_allowed = 1;
}

s32 sprite_draw_layer4();
s32 func_00201710();
extern u8 D_00258520[];
extern u16 g_slowdown_boss_allowed_as_u16;

void battleship_b(void) {
    s32 enemy_remove();
    s32 sprite_draw_layer2();
    s16 temp_v1_2;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a0_3;
    u32 temp_a0_4;
    u32 temp_a1;
    u8 temp_v1;
    u8 var_a0_2;
    u8 *var_p;
    u8 *var_a0;

    entity_velocity();
    reg_d1.w = 0x5C;
    var_a0 = (u8 *)(reg_a6 + 1);
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        var_a0 = (u8 *)((void *) reg_d0.b[0]);
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
        reg_d0.b[0] = (s32) var_a0 ^ reg_d2.b[0];
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        if (*(u8 *)(reg_a5 + 0x16) != 2) {
            ENTITY(reg_a6)->hp.sh = 0x2400;
        }
        if (ENTITY(reg_a6)->hp.sh < 0) {
            *(u16 *)(reg_a5 + 0x36) = 0x40U;
            *(u16 *)(reg_a5 + 0x38) = (u16) reg_d1.h[0];
            reg_d0.w = 0x234;
            score_add();
            var_a0 = (u8 *)((void *)0x8000);
            g_slowdown_boss_allowed_as_u16 = 0;
            ENTITY(reg_a6)->flags.h = 0x8000;
            *(u16 *)(reg_a5 + 0x2E) = 1U;
            goto block_5;
        }
    } else {
block_5:
        ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
    }
    func_001594D0();
    if (*(u16 *)(reg_a5 + 0x36) != 0) {
        reg_d1.h[0] = *(u16 *)(reg_a5 + 0x38);
        func_00201710();
        *(u16 *)(reg_a5 + 0x36) -= 1;
        if (*(u16 *)(reg_a5 + 0x36) == 0) {
            enemy_remove();
            return;
        }
        if (*(u16 *)(reg_a5 + 0x2E) == 0) {
            return;
        }
        goto block_37;
    }
    if ((g_enemies_stopped == 0) && (*(u16 *)(reg_a5 + 0x2E) == 0)) {
        temp_a0 = ENTITY(reg_a6)->y.h;
        if (((s16)(temp_a0) >= 0) && ((s32)(temp_a0 & 0xFFFF) < 0x6401)) {
            *(u8 *)(reg_a5 + 0x23) = 1U;
        }
        if (*(u8 *)(reg_a5 + 0x23) != 0) {
            temp_v1 = *(u8 *)(reg_a5 + 0x22);
            if (temp_v1 != 0) {
                *(u8 *)(reg_a5 + 0x22) = (u8) (temp_v1 - 1);
            }
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
            *(u8 *)(reg_a5 + 0x25) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
                temp_a0_2 = *(u16 *)(reg_a5 + 0x26);
                if ((s16)(temp_a0_2) < 0x80) {
                    *(u16 *)(reg_a5 + 0x26) = (u16) (temp_a0_2 + 1);
                }
            }
            reg_d0.h[0] = *(u16 *)(reg_a5 + 0x26);
            temp_a1 = ENTITY(reg_a6)->y.h;
            ENTITY(reg_a6)->y.h = (u16) (temp_a1 + reg_d0.h[0]);
            temp_a0_3 = ENTITY(reg_a6)->y.h;
            if ((s32) temp_a0_3 >= 0x9800) {
                g_slowdown_boss_allowed_as_u16 = 0;
                enemy_remove();
                return;
            }
            goto block_24;
        }
block_24:
        if (*(u8 *)(reg_a5 + 0x16) == 0) {
            temp_v1_2 = (s16) ENTITY(reg_a6)->y.h;
            if ((temp_v1_2 >= 0) && (temp_v1_2 < 0x6601)) {
                *(u8 *)(reg_a5 + 0x16) = 1U;
            }
        }
        if (*(u8 *)(reg_a5 + 0x16) == 1) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
            *(u8 *)(reg_a5 + 0x21) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
                *(u16 *)(reg_a5 + 0x1E) += 4;
                if ((s16) *(u16 *)(reg_a5 + 0x1E) >= 0x3C) {
                    *(u8 *)(reg_a5 + 0x16) = 2U;
                }
            }
        }
        var_a0_2 = *(u8 *)(reg_a5 + 0x16);
        if (var_a0_2 == 2) {
            if (*(u16 *)(reg_a5 + 0x2C) == 0) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x29);
                *(u8 *)(reg_a5 + 0x29) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    var_p = reg_a5;
                    (*(u8 *)((u8 *)(var_p) + (0x29))) = (u8) (*(u8 *)((u8 *)(var_p) + (0x28)));
                    *(u16 *)(reg_a5 + 0x2C) = 1U;
                    goto block_36;
                }
            } else {
block_36:
                func_00158B80();
            }
        }
        goto block_37;
    }
block_37:
    if (ENTITY(reg_a6)->misc.b.draw_layer == 0) {
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        reg_a0 = (u8 *)D_00258520;
        reg_a0 += *(u16 *)(reg_a5 + 0x1E);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0_4 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0_4;
        reg_d1.w += 0xD800F200;
        reg_d3.h[0] = 0x2870;
        if (*(u8 *)(reg_a5 + 0x22) == 0) {
            sprite_draw_layer4();
        } else {
            sprite_draw_layer2();
        }
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
    }
}

void func_00158B40(void) {
    *(s16 *)(reg_a5 + 0x2C) = 0;
    *(u16 *)(reg_a5 + 0x2A) += 1;
    if (*(u16 *)(reg_a5 + 0x2A) == 4) {
        *(u16 *)(reg_a5 + 0x2A) = 0U;
    }
}

typedef void (*Fn)(void);
extern u8 *reg_call_target_as_u8_p;
extern u16 D_00258560[];

void func_00158B80(void) {
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
    if (*(u16 *)(reg_a5 + 0x2C) != 2) {
        *(u16 *)(reg_a5 + 0x2C) += 1;
    }
    reg_d0.h[0] -= 1;
    reg_d0.h[0] <<= 2;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x2A);
    reg_a0 = (u8 *)D_00258560;
    reg_d1.h[0] <<= 3;
    reg_a0 += reg_d1.h[0];
    reg_a0 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    reg_call_target_as_u8_p = (u8 *)reg_tmp.w;
    ((Fn)reg_call_target_as_u8_p)();
}


void func_00158C30(void) {
    void aim256_at_player();
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x7D01;
    aim256_at_player();
    if (cond_flag == 0) {
        reg_d1.b[0] -= 0x40;
        ENTITY(reg_a6)[1].hit_y_plus.b[0] = reg_d1.b[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x7FFF + 0x7501;
        aim256_at_player();
        reg_d1.b[0] += 0x38;
        ENTITY(reg_a6)[1].hit_y_plus.b[1] = reg_d1.b[0];
        ENTITY(reg_a6)[1].offset_x.h = 4;
        ENTITY(reg_a6)[1].sprite.h = 8;
        func_00158CF0();
    }
}


void func_00158CF0() {
    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_x.b[1];
    ENTITY(reg_a6)[1].offset_x.b[1] -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ENTITY(reg_a6)[1].offset_x.b[1] = (u8) ENTITY(reg_a6)[1].offset_x.b[0];
        reg_d0.w = 0x40007;
        reg_d4.w = 0;
        reg_d3.w = 0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.b[0] = ENTITY(reg_a6)[1].hit_y_plus.b[0];
        reg_d3.w = 0xFD000000;
        bullet_fire256();
        reg_d3.w = 0xFCFFFF00;
        bullet_fire256();
        reg_d3.w = 0xFD000100;
        bullet_fire256();
        ENTITY(reg_a6)[1].hit_y_plus.b[0] += 0x14;
        reg_d1.b[0] = ENTITY(reg_a6)[1].hit_y_plus.b[1];
        reg_d3.w = 0xF5000000;
        bullet_fire256();
        reg_d3.w = 0xF4FFFF00;
        bullet_fire256();
        reg_d3.w = 0xF5000100;
        bullet_fire256();
        ENTITY(reg_a6)[1].hit_y_plus.b[1] -= 0x14;
        ENTITY(reg_a6)[1].sprite.h -= 1;
        if (ENTITY(reg_a6)[1].sprite.h == 0) {
            func_00158B40();
        }
    }
}


void func_00158E10() {
    s32 aim256_at_player();
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    aim256_at_player();
    if (cond_flag == 0) {
        ENTITY(reg_a6)[1].look.b.palette = (u8) reg_d1.b[0];
        reg_d1.b[0] -= 0x30;
        ENTITY(reg_a6)[1].hit_y_plus.b[0] = (u8) reg_d1.b[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        aim256_at_player();
        ENTITY(reg_a6)[1].look.b.size = (u8) reg_d1.b[0];
        reg_d1.b[0] += 0x30;
        ENTITY(reg_a6)[1].hit_y_plus.b[1] = (u8) reg_d1.b[0];
        ENTITY(reg_a6)[1].offset_x.sh = 2;
        ENTITY(reg_a6)[1].sprite.sh = 0x16;
        func_00158ED0();
    }
}

s32 bullet_fire256_fast();
s32 func_00202590();

void func_00158ED0(void) {
    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_x.b[1];
    ENTITY(reg_a6)[1].offset_x.b[1] -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ENTITY(reg_a6)[1].offset_x.b[1] = (u8) ENTITY(reg_a6)[1].offset_x.b[0];
        reg_d7.w = 1;
        do {
            reg_d1.b[0] = ENTITY(reg_a6)[1].look.b.palette;
            reg_d0.b[0] = ENTITY(reg_a6)[1].hit_y_plus.b[0];
            func_00202590();
            ENTITY(reg_a6)[1].hit_y_plus.b[0] = (u8) reg_d1.b[0];
            reg_d1.b[0] = ENTITY(reg_a6)[1].look.b.size;
            reg_d0.b[0] = ENTITY(reg_a6)[1].hit_y_plus.b[1];
            func_00202590();
            ENTITY(reg_a6)[1].hit_y_plus.b[1] = (u8) reg_d1.b[0];
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d4.w = 0;
        reg_d0.w = 0x160007;
        reg_d3.w = 0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.b[0] = ENTITY(reg_a6)[1].hit_y_plus.b[0];
        reg_d3.w = 0x078005C0;
        bullet_fire256_fixed();
        reg_d1.b[0] += 6;
        bullet_fire256_fast();
        reg_d1.b[0] = ENTITY(reg_a6)[1].hit_y_plus.b[1];
        reg_d3.w = 0x077FFA40;
        bullet_fire256_fixed();
        reg_d1.b[0] -= 6;
        bullet_fire256_fast();
        ENTITY(reg_a6)[1].sprite.h -= 1;
        if (ENTITY(reg_a6)[1].sprite.h == 0) {
            func_00158B40();
        }
    }
}

void func_00159030(void) {
    enemy_set_entity_count(3);
}

extern u8 D_00258580[];
extern u8 D_002585B0[];

void func_00159040() {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    u16 temp_a1;

    reg_a0 = D_002585B0;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    temp_a1 = *(u16 *)(reg_a5 + 0x1A);
    ENTITY(reg_a6)->move.h = temp_a1;
    reg_a0 = D_00258580;
    reg_d0.w = 0x11;
    enemy_set_task_state();
}

extern u8 D_00258620[];

void func_001590B0(void) {
    s32 enemy_remove();
    s32 sprite_draw_layer2();
    s16 temp_v1;
    s16 temp_v1_3;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a0_4;
    u32 temp_a1;
    u8 temp_a0_3;
    u8 temp_v1_2;
    u8 *var_a0;

    entity_velocity();
    reg_d1.w = 0x5C;
    var_a0 = (u8 *)(reg_a6 + 1);
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        var_a0 = (u8 *)((void *) reg_d0.b[0]);
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
        reg_d0.b[0] = (s32) var_a0 ^ reg_d2.b[0];
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        if (*(u8 *)(reg_a5 + 0x16) != 2) {
            ENTITY(reg_a6)->hp.sh = 0x2400;
        }
        if (ENTITY(reg_a6)->hp.sh < 0) {
            *(u16 *)(reg_a5 + 0x36) = 0x40U;
            *(u16 *)(reg_a5 + 0x38) = (u16) reg_d1.h[0];
            reg_d0.w = 0x563;
            score_add();
            var_a0 = (u8 *)((void *)0x8000);
            ENTITY(reg_a6)->flags.h = 0x8000;
            *(u16 *)(reg_a5 + 0x2E) = 1U;
            goto block_5;
        }
    } else {
block_5:
        ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
    }
    func_001594D0();
    if (*(u16 *)(reg_a5 + 0x36) != 0) {
        reg_d1.h[0] = *(u16 *)(reg_a5 + 0x38);
        func_00201710();
        *(u16 *)(reg_a5 + 0x36) -= 1;
        if (*(u16 *)(reg_a5 + 0x36) == 0) {
            enemy_remove();
            return;
        }
        if (*(u16 *)(reg_a5 + 0x2E) == 0) {
            return;
        }
        goto block_37;
    }
    if ((g_enemies_stopped == 0) && (*(u16 *)(reg_a5 + 0x2E) == 0)) {
        temp_v1 = ENTITY(reg_a6)->y.sh;
        if ((temp_v1 >= 0) && (temp_v1 < 0x5A01)) {
            *(u8 *)(reg_a5 + 0x23) = 1U;
        }
        if (*(u8 *)(reg_a5 + 0x23) != 0) {
            temp_v1_2 = *(u8 *)(reg_a5 + 0x22);
            if (temp_v1_2 != 0) {
                *(u8 *)(reg_a5 + 0x22) = (u8) (temp_v1_2 - 1);
            }
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
            *(u8 *)(reg_a5 + 0x25) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
                temp_a0 = *(u16 *)(reg_a5 + 0x26);
                if ((s16)(temp_a0) < 0x80) {
                    *(u16 *)(reg_a5 + 0x26) = (u16) (temp_a0 + 1);
                }
            }
            reg_d0.h[0] = *(u16 *)(reg_a5 + 0x26);
            temp_a1 = ENTITY(reg_a6)->y.h;
            ENTITY(reg_a6)->y.sh = (s16) (temp_a1 + reg_d0.h[0]);
            temp_a0_2 = ENTITY(reg_a6)->y.h;
            if ((s32) temp_a0_2 >= 0x9800) {
                enemy_remove();
                return;
            }
            goto block_24;
        }
block_24:
        if (*(u8 *)(reg_a5 + 0x16) == 0) {
            temp_v1_3 = ENTITY(reg_a6)->y.sh;
            if ((temp_v1_3 >= 0) && (temp_v1_3 < 0x6601)) {
                *(u8 *)(reg_a5 + 0x16) = 1U;
            }
        }
        if (*(u8 *)(reg_a5 + 0x16) == 1) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
            *(u8 *)(reg_a5 + 0x21) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
                *(u16 *)(reg_a5 + 0x1E) += 4;
                if ((s16) *(u16 *)(reg_a5 + 0x1E) >= 0x3C) {
                    *(u8 *)(reg_a5 + 0x16) = 2U;
                }
            }
        }
        temp_a0_3 = *(u8 *)(reg_a5 + 0x16);
        if (temp_a0_3 == 2) {
            func_001597C0();
            if (*(u16 *)(reg_a5 + 0x2C) == 0) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x29);
                *(u8 *)(reg_a5 + 0x29) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x29) = (u8) *(u8 *)(reg_a5 + 0x28);
                    *(u16 *)(reg_a5 + 0x2C) = 1U;
                    goto block_36;
                }
            } else {
block_36:
                func_00159A10();
            }
        }
        goto block_37;
    }
block_37:
    if (ENTITY(reg_a6)->misc.b.draw_layer == 0) {
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        reg_a0 = (u8 *)D_00258620;
        reg_a0 += *(u16 *)(reg_a5 + 0x1E);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0_4 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0_4;
        reg_d1.w += 0xD600F000;
        reg_d3.h[0] = 0x2A80;
        if (*(u8 *)(reg_a5 + 0x22) == 0) {
            sprite_draw_layer4();
        } else {
            sprite_draw_layer2();
        }
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
    }
}

extern u16 D_00258660[];

void func_001594D0(void) {
    u16 temp_a0;
    u16 *temp_a2;
    u16 temp_a1;
    u16 temp_v1;

    temp_v1 = *(u16 *)(reg_a5 + 0x2E);
    temp_a0 = temp_v1 & 0xFFFF;
    if (temp_v1 == 0) {
        cond_flag = 0;
        return;
    }
    if (temp_a0 == 1) {
        *(u16 *)(reg_a5 + 0x2E) = 2U;
        *(u16 *)(reg_a5 + 0x30) = 0U;
        *(s16 *)(reg_a5 + 0x32) = 3;
        *(u16 *)(reg_a5 + 0x34) = 0U;
        sfx_explosion_ground_large();
    }
    ENTITY(reg_a6)->y.h -= 0x26;
    if (*(u16 *)(reg_a5 + 0x2E) == 2) {
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x33);
        *(u8 *)(reg_a5 + 0x33) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x33) = *(u8 *)(reg_a5 + 0x32);
            reg_a1 = (u8 *)(D_00258660);
            reg_a1 += *(u16 *)(reg_a5 + 0x30);
            reg_d1.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            explosion_spawn();
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
            *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
            temp_a2 = (u16 *)(reg_a1 + 2);
            reg_a1 = (u8 *)(temp_a2);
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a1;
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            if (*(u16 *)(reg_a5 + 0x34) != 0) {
                rng_next();
                reg_d0.b[0] += 0xC;
                *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
                rng_next_unsigned();
                *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            }
            reg_a1 += 2;
            *(u16 *)(reg_a5 + 0x30) += 0xC;
            if ((s16) *(u16 *)(reg_a5 + 0x30) >= 0x54) {
                *(s16 *)(reg_a5 + 0x32) = 0x601;
                *(u16 *)(reg_a5 + 0x30) = 0U;
                ENTITY(reg_a6)->misc.sb.draw_layer = 1;
                *(u16 *)(reg_a5 + 0x34) += 1;
                if (*(u16 *)(reg_a5 + 0x34) == 1) {
                    *(u16 *)(reg_a5 + 0x2E) = 0U;
                    reg_d0.w = 0;
                    cond_flag = 1;
                    reg_d0.h[0] -= 1;
                    return;
                }
            }
            goto block_11;
        }
    }
block_11:
    cond_flag = 0;
}

void func_00159740(void) {
    ENTITY(reg_a6)[2].offset_y.sb[1] = 1;
    reg_d7.w = 5;
    reg_a0 = reg_a6 + 0x66;
    do {
        *(s16 *)reg_a0 = 0;
        *(s16 *)(reg_a0 + 2) = 4;
        reg_a0 += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    ENTITY(reg_a6)[2].offset_x.sh = 8;
    ENTITY(reg_a6)[2].draw.sh = 0;
    func_001597C0();
}

extern u16 D_002586C0[];
extern s8 D_0028C9C0;

void func_001597C0(void) {
    u32 temp_a1;
    if (ENTITY(reg_a6)[2].offset_y.b[1] == 0) {
        func_00159740();
        return;
    }
    reg_tmp.b[0] = ENTITY(reg_a6)[2].offset_x.b[1];
    ENTITY(reg_a6)[2].offset_x.b[1] -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ENTITY(reg_a6)[2].offset_x.b[1] = (u8) ENTITY(reg_a6)[2].offset_x.b[0];
        reg_a4 = reg_a6 + 0x66;
        reg_a4 += ENTITY(reg_a6)[2].draw.h;
        *(u8 *)(reg_a4 + 1) = 4U;
        *(s16 *)(reg_a4 + 2) = 4;
        ENTITY(reg_a6)[2].draw.h += 4;
        if ((s16) ENTITY(reg_a6)[2].draw.h >= 0x18) {
            ENTITY(reg_a6)[2].draw.h = 0U;
        }
    }
    reg_a4 = reg_a6 + 0x66;
    reg_d7.w = 5;
    do {
        if (*(u8 *)(reg_a4 + 1) != 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
            *(u8 *)(reg_a4 + 3) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 3) = *(u8 *)(reg_a4 + 2);
                reg_d6.h[0] = reg_d7.h[0];
                temp_a1 = reg_d6.h[0];
                reg_d1.b[0] = *(&D_0028C9C0 + temp_a1);
                reg_a0 = (u8 *)(D_002586C0);
                reg_d6.h[0] = temp_a1 * 4;
                reg_d3.h[1] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = (((reg_d6.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d6.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d4.w = 0;
                reg_d0.w = 5;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                bullet_fire256_2way();
                *(u8 *)(reg_a4 + 1) -= 1;
            }
        }
        reg_a4 += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void func_001599D0(void) {
    *(s16 *)(reg_a5 + 0x2C) = 0;
    *(u16 *)(reg_a5 + 0x2A) += 1;
    if (*(u16 *)(reg_a5 + 0x2A) == 2) {
        *(u16 *)(reg_a5 + 0x2A) = 0U;
    }
}

extern u16 D_002586E0[];

void func_00159A10(void) {
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
    if (*(u16 *)(reg_a5 + 0x2C) != 2) {
        *(u16 *)(reg_a5 + 0x2C) += 1;
    }
    reg_d0.h[0] -= 1;
    reg_d0.h[0] <<= 2;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x2A);
    reg_a0 = (u8 *)D_002586E0;
    reg_d1.h[0] <<= 3;
    reg_a0 += reg_d1.h[0];
    reg_a0 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    reg_call_target_as_u8_p = (u8 *)reg_tmp.w;
    ((Fn)reg_call_target_as_u8_p)();
}


void func_00159AC0(void) {
    void aim256_at_player();
    ENTITY(reg_a6)[1].offset_y.h = 2;
    ENTITY(reg_a6)[1].offset_x.h = 0xE;
    ENTITY(reg_a6)[1].sprite.h = 4;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    aim256_at_player();
    ENTITY(reg_a6)[1].look.b.size = reg_d1.b[0];
    func_00159B20();
}


void func_00159B20() {
    s32 aim256_at_player();
    u16 temp_a0;

    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_y.b[1];
    ENTITY(reg_a6)[1].offset_y.b[1] -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ENTITY(reg_a6)[1].offset_y.b[1] = (u8) ENTITY(reg_a6)[1].offset_y.b[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        aim256_at_player();
        reg_d0.b[0] = ENTITY(reg_a6)[1].look.b.size;
        func_00202590();
        ENTITY(reg_a6)[1].look.b.size = (u8) reg_d0.b[0];
        reg_d1.b[0] = ENTITY(reg_a6)[1].look.b.size;
        reg_d4.w = 0;
        reg_d3.w = 0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] = ENTITY(reg_a6)[1].sprite.h;
        temp_a0 = reg_d0.h[0];
        reg_tmp.h[0] = temp_a0;
        reg_d0.h[0] = 7;
        reg_d0.h[1] = reg_tmp.h[0];
        ENTITY(reg_a6)[1].sprite.h += 4;
        reg_d3.w = 0x133FFD00;
        bullet_fire256_fast();
        reg_d3.w = 0x13400300;
        bullet_fire256_fast();
        reg_d3.w = 0x13400640;
        bullet_fire256_fast();
        reg_d3.w = 0x133FF9C0;
        bullet_fire256_fast();
        ENTITY(reg_a6)[1].offset_x.h -= 1;
        if (ENTITY(reg_a6)[1].offset_x.h == 0) {
            func_001599D0();
        }
    }
}

void func_00159C50(void) {
    enemy_set_entity_count(0);
}

extern u8 D_002586F0[];
extern u8 D_00258720[];


void func_00159C60(void)
{
    extern void enemy_set_task_state(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
    reg_a0 = D_00258720;
    enemy_init_entities();

    reg_a0 = D_002586F0;
    reg_d0.w = 0x11;
    enemy_set_task_state();

    enemy_path_start();
    if (enemy_move_end_requested != 0) {
        return;
    }
}

typedef void (*Fn)();

s32 sfx_explosion_air_medium();
extern u16 D_00258760[];
extern u16 D_00258770[];
extern u8 D_00258790[];
extern u32 reg_call_target_as_u32;

void func_00159CB0(void) {
    s32 enemy_remove();
    s32 enemy_path_step();
    u16 temp_a1;
    u32 temp_a0;

    if (ENTITY(reg_a6)->y.sh < -0x1000) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_4:
    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if (*(u8 *)(reg_a5 + 0x27) == 0) {
                ENTITY(reg_a6)->hp.sh = 0xC00;
            }
            if (ENTITY(reg_a6)->hp.sh < 0) {
                reg_d0.w = 0x72;
                score_add();
                sfx_explosion_air_medium();
                reg_a1 = (u8 *)D_00258790;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.h[0] = 0x10;
                func_00153650();
                enemy_remove();
                return;
            }
            goto block_11;
        }
        ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
block_11:
        if (g_enemies_stopped == 0) {
            if (*(u8 *)(reg_a5 + 0x16) == 3) {
                *(u16 *)(reg_a5 + 0x1A) -= 0x40;
                ENTITY(reg_a6)->hit_x_plus.h -= 0x40;
                ENTITY(reg_a6)->hit_x_minus.h -= 0x40;
                if (0 >= (s16) *(u16 *)(reg_a5 + 0x1A)) {
                    *(u16 *)(reg_a5 + 0x1A) = 0U;
                    *(u8 *)(reg_a5 + 0x16) = 0U;
                }
            }
            if (*(u8 *)(reg_a5 + 0x16) == 2) {
                *(u8 *)(reg_a5 + 0x27) = 1U;
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                *(u8 *)(reg_a5 + 0x1F) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                    reg_a0 = (u8 *)(D_00258760);
                    if ((s32) g_scroll_line >= 0x100) {
                        reg_a0 = (u8 *)(D_00258770);
                    }
                    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x24);
                    reg_d0.h[0] *= 4;
                    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_call_target_as_u32 = reg_tmp.w;
                    ((Fn)reg_call_target_as_u32)();
                    *(u16 *)(reg_a5 + 0x24) += 1;
                    reg_d0.w = 4;
                    reg_d1.w = 3;
                    if ((s32) g_scroll_line >= 0x100) {
                        reg_d0.w = 8;
                        reg_d1.w = 2;
                    }
                    *(u16 *)(reg_a5 + 0x22) += reg_d1.h[0];
                    if (*(u16 *)(reg_a5 + 0x24) == reg_d0.h[0]) {
                        *(u8 *)(reg_a5 + 0x16) = 3U;
                    }
                }
            }
            if (*(u8 *)(reg_a5 + 0x16) == 1) {
                *(u16 *)(reg_a5 + 0x1A) += 0x40;
                ENTITY(reg_a6)->hit_x_plus.h += 0x40;
                ENTITY(reg_a6)->hit_x_minus.h += 0x40;
                if ((s16) *(u16 *)(reg_a5 + 0x1A) >= 0x380) {
                    *(u16 *)(reg_a5 + 0x1A) = 0x380U;
                    *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
                    *(u16 *)(reg_a5 + 0x22) = 1U;
                    *(u16 *)(reg_a5 + 0x24) = 0U;
                    *(u8 *)(reg_a5 + 0x16) = 2U;
                }
            }
            if (*(u8 *)(reg_a5 + 0x16) == 0) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
                *(u8 *)(reg_a5 + 0x1D) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
                    *(u8 *)(reg_a5 + 0x16) = 1U;
                }
            }
        }
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a1 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xF200F900;
        reg_d3.h[0] = 0xE38;
        reg_d2.w = 0x187A;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        sprite_draw_layer5_keep();
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.w += 0xFEBFFB40;
        reg_d7.h[0] = *(u16 *)(reg_a5 + 0x1A);
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] -= reg_d7.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] -= *(u16 *)(reg_a5 + 0x1A);
        temp_a0 = reg_d1.w;
        reg_d3.h[0] = 0xE28;
        reg_d2.w = 0x187B;
        reg_d4.w = 0;
        reg_d1.w = temp_a0 + 0xF200FB00;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        sprite_draw_layer5_keep();
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d1.w += 0xFEC00480;
        reg_d7.h[0] = *(u16 *)(reg_a5 + 0x1A);
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] -= reg_d7.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] += *(u16 *)(reg_a5 + 0x1A);
        reg_d1.w += 0xF200FB00;
        reg_d3.h[0] = 0xE28;
        reg_d2.w = 0x187C;
        reg_d4.w = 0;
        reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
        sprite_draw_layer5_keep();
        reg_a0 = (u8 *)(reg_a6);
        enemy_hitbox_debug_draw();
    }
}

extern u8 D_00258740[];

void func_0015A290(void) {
    u32 t1;

    reg_a4 = (u8 *)D_00258740;
    reg_d7.w = 5;
loop_1:
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += *(u16 *)reg_a4;
    reg_d1.h[0] += *(u16 *)(reg_a4 + 2);
    aim_at_player();
    if (cond_flag == 0) {
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d4.w = 0;
        reg_d3.h[1] = *(u16 *)reg_a4;
        reg_d3.h[0] = *(u16 *)(reg_a4 + 2);
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x22);
        reg_d0.h[0] += 4;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] = 5;
        reg_d0.h[1] = reg_tmp.h[0];
        bullet_fire_fast();
        reg_a4 += 4;
        t1 = reg_d7.h[0] - 1;
        reg_d7.h[0] = t1;
        if (((s64) ((s64) (t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
    }
}

extern s8 D_0028C9C8;
extern u8 D_0028C9D0;

void func_0015A390(void) {
    u16 temp_a0;
    reg_a4 = D_00258740;
    reg_a3 = (u8 *)(&D_0028C9C8);
    reg_a2 = &D_0028C9D0;
    reg_d7.w = 5;
    do {
        reg_d1.w = 0;
        reg_d1.b[0] = (u8) *(s8 *)reg_a3;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d4.w = (u32) reg_a6;
        reg_d3.h[1] = *(u16 *)reg_a4;
        temp_a0 = *(u16 *)(reg_a4 + 2);
        reg_d3.h[0] = temp_a0;
        if (g_stage != 4) {
            reg_d0.h[0] = 6;
            reg_tmp.h[0] = reg_d0.h[0];
            reg_d0.h[0] = 0xB;
            reg_d0.h[1] = reg_tmp.h[0];
            bullet_fire256_2way();
        } else {
            reg_d0.h[0] = 0xFFFC;
            reg_tmp.h[0] = reg_d0.h[0];
            reg_d0.h[0] = 0xB;
            reg_d0.h[1] = reg_tmp.h[0];
            bullet_fire256_fixed();
            reg_d0.w += 0x40000;
            bullet_fire256_2way();
            reg_d0.w += 0x40000;
            bullet_fire256_fixed();
            reg_d0.w += 0x40000;
            bullet_fire256_2way();
            reg_d0.w += 0x40000;
            bullet_fire256_fixed();
        }
        reg_a4 += 4;
        reg_a3 += 1;
        reg_a2 += 1;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

void func_0015A500(void) {
    enemy_set_entity_count(0);
}

s32 func_00202180();
extern u8 D_002587C0[];
extern u8 D_002587E0[];

void func_0015A510(void) {
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = D_002587E0;
    enemy_init_entities();
    reg_a0 = D_002587C0;
    reg_d0.w = 0xA;
    enemy_set_task_state();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        func_00202180();
        *(u8 *)(reg_a5 + 0x23) = (u8) reg_d1.b[0];
        if (g_stage == 4) {
            ENTITY(reg_a6)->flags.h = 0xA200;
            *(s8 *)(reg_a5 + 0x19) = 0xF;
            *(s8 *)(reg_a5 + 0x18) = 0x10;
        }
    }
}

s32 bullet_fire256_double();
extern u8 D_00258800[];
extern u8 D_0028C9D8;

void func_0015A5B0(void) {
    s32 enemy_remove();
    s32 enemy_path_step();
    s32 aim256_at_player();
    u16 temp_a1;
    u16 temp_a2;
    u8 temp_a0_3;
    u8 *temp_a0_2;

    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] -= *(u16 *)(reg_a5 + 0x1E);
    ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        entity_check_bounds();
        if (cond_flag != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_5:
        if (g_stage != 4) {
            reg_d1.w = 0;
            reg_d0.w = 0;
            reg_d0.b[0] = 0x28;
            reg_d1.b[0] = *(u8 *)(reg_a5 + 0x20);
            *(u8 *)(reg_a5 + 0x20) += 2;
            velocity_from_dir256();
            *(u16 *)(reg_a5 + 0x1E) = (u16) reg_d2.h[0];
            reg_d1.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] += *(u16 *)(reg_a5 + 0x1E);
            ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
        }
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
            score_add_no_chain();
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
            reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
            reg_d0.b[0] ^= reg_d2.b[0];
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if (ENTITY(reg_a6)->hp.sh < 0) {
                reg_d0.w = 0x31;
                score_add();
                reg_d0.h[0] = 2;
                explosion_spawn();
                *(u16 *)(reg_a0 + 0x26) = (u16) ENTITY(reg_a6)->offset_y.h;
                *(u16 *)(reg_a0 + 0x28) = (u16) ENTITY(reg_a6)->offset_x.h;
                *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
                temp_a1 = ENTITY(reg_a6)->x.h;
                *(u16 *)(reg_a0 + 4) = temp_a1;
                *(s16 *)(reg_a0 + 0x1E) = 0xC;
                *(s16 *)(reg_a0 + 0x12) = 0;
                *(s16 *)(reg_a0 + 0x14) = 0;
                *(s16 *)(reg_a0 + 0x10) = 2;
                *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
                reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d0.b[0] *= 4;
                *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
                sfx_explosion_ground_small();
                enemy_remove();
                return;
            }
            goto block_11;
        }
        ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
block_11:
        temp_a0_2 = (u8 *)(reg_a6 + 2);
        if ((s16) ENTITY(reg_a6)->y.h > 0x1400) {
            if (g_stage == 4) {
                reg_d0.b[0] = *(u8 *)(reg_a5 + 0x26);
                if (*(u8 *)(reg_a5 + 0x27) == reg_d0.b[0]) {
                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d0.h[0] += 0x3C0;
                    aim_at_player();
                    if (cond_flag == 0) {
                        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x23);
                        direction_turn_toward();
                        *(u8 *)(reg_a5 + 0x23) = (u8) reg_d1.b[0];
                    }
                }
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
                *(u8 *)(reg_a5 + 0x25) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d0.h[0] += 0x3C0;
                    aim256_at_player();
                    if (cond_flag == 0) {
                        reg_d0.h[0] = reg_d1.h[0];
                        reg_a0 = (u8 *)D_00258800;
                        reg_d0.h[0] &= 0xF8;
                        reg_d0.h[0] >>= 1;
                        reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d4.w = 0;
                        reg_d0.w = 0x10007;
                        reg_d1.h[0] += 4;
                        reg_d1.h[0] &= 0xF8;
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.w = 0xFFFC0007;
                        bullet_fire256_double();
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x27);
                        *(u8 *)(reg_a5 + 0x27) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x27) = (u8) *(u8 *)(reg_a5 + 0x26);
                            reg_d0.h[0] = 0xA;
                            reg_d1.h[0] = g_rank_1_16;
                            reg_d1.h[0] >>= 1;
                            reg_d0.h[0] -= reg_d1.h[0];
                            *(u8 *)(reg_a5 + 0x25) = reg_d0.b[0];
                        }
                    }
                }
            } else {
                reg_d0.b[0] = *(u8 *)(reg_a5 + 0x26);
                if (*(u8 *)(reg_a5 + 0x27) == reg_d0.b[0]) {
                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d0.h[0] += 0x3C0;
                    aim_at_player();
                    if (cond_flag == 0) {
                        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x23);
                        direction_turn_toward();
                        *(u8 *)(reg_a5 + 0x23) = (u8) reg_d1.b[0];
                    }
                }
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
                *(u8 *)(reg_a5 + 0x25) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
                    reg_d1.w = 0;
                    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x23);
                    reg_a0 = (u8 *)D_00258800;
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d1.b[0] += 1;
                    reg_d1.h[0] &= 0x3E;
                    reg_d3.b[0] += 2;
                    reg_d7.b[0] = reg_d1.b[0];
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d3.h[0] &= 0x3C;
                    reg_d0.h[0] *= 2;
                    reg_d1.h[0] = reg_d3.h[0];
                    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d4.w = 0;
                    reg_d0.w = 0x4000C;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    bullet_fire_fixed();
                    reg_d0.w = 0xFFFE000D;
                    reg_d1.h[0] = reg_d7.h[0];
                    bullet_fire_2way();
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x27);
                    *(u8 *)(reg_a5 + 0x27) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x27) = (u8) *(u8 *)(reg_a5 + 0x26);
                        reg_d0.h[0] = 0xA;
                        reg_d1.h[0] = g_rank_1_16;
                        reg_d1.h[0] >>= 2;
                        reg_d0.h[0] -= reg_d1.h[0];
                        *(u8 *)(reg_a5 + 0x25) = reg_d0.b[0];
                    }
                }
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
        *(u8 *)(reg_a5 + 0x1D) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
            *(u16 *)(reg_a5 + 0x1A) += 4;
            *(u16 *)(reg_a5 + 0x1A) &= 7;
        }
        reg_a0 = &D_0028C9D8;
        reg_a0 += *(u16 *)(reg_a5 + 0x1A);
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d0.w = 0;
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x23);
        reg_d0.b[0] += 1;
        reg_d0.h[0] &= 0x3E;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a2 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a2;
        reg_d1.w += 0xF600FA00;
        reg_d3.h[0] = 0xA30;
        reg_d4.w = 0;
        temp_a0_3 = ENTITY(reg_a6)->attr.b.palette;
        reg_d4.b[0] = temp_a0_3;
        if (g_stage != 4) {
            sprite_draw_layer5_keep();
        } else {
            sprite_draw_layer4_keep();
        }
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
    }
}

void func_0015AE00(void) {
    enemy_set_entity_count(0);
}

s32 enemy_init_entities();                            /* extern */
extern s32 D_00258980[];

void func_0015AE10(void) {
    reg_a0 = (u8 *)D_00258980;
    enemy_init_entities();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a5 + 0x16) = 4;
    *(s16 *)(reg_a5 + 0x18) = 0x303;
}

extern s16 g_enemy_signal_8_as_s16;

void func_0015AE70(void) {
    g_enemy_signal_8_as_s16 = 0;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x17);
    *(u8 *)(reg_a5 + 0x17) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x17) = (u8) *(u8 *)(reg_a5 + 0x16);
        g_enemy_signal_8_as_s16 = 1;
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
        *(u8 *)(reg_a5 + 0x19) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x19) = (u8) *(u8 *)(reg_a5 + 0x18);
            *(u8 *)(reg_a5 + 0x17) = 0x10U;
        }
    }
}

void func_0015AEF0(void) {
    enemy_set_entity_count(0);
}

extern u16 D_002589A0[];
extern u16 D_002589B0[];
extern u16 D_002589D0[];
extern u16 D_0025B610_as_u16_a[];
extern u16 g_enemy_signal_2;
extern u16 g_enemy_signal_1;
extern u16 g_rank_6_16;
extern u16 g_stage_x2;
void entity_draw_layer2();

void func_0015AF00(void) {
    s32 enemy_remove();
    s32 enemy_set_task_state();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    void sprite_draw_layer2();
    s16 temp_v1_2;
    u16 *temp_a2;
    u16 temp_a3;
    reg_a0 = (u8 *)(D_002589D0);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_002589B0);
    reg_d0.w = 0xF;
    enemy_set_task_state();
    reg_d0.h[0] = g_rank_6_16;
    *(u8 *)(reg_a5 + 0x29) -= reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x1B) -= reg_d0.b[0];
    rng_next_masked();
    reg_d0.b[0] >>= 1;
    *(u8 *)(reg_a5 + 0x29) += reg_d0.b[0];
    reg_d0.h[0] = g_rank_1_16;
    reg_d0.h[0] >>= 4;
    *(u8 *)(reg_a5 + 0x19) -= reg_d0.b[0];
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
        reg_a6 = (u8 *)reg_tmp.w;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        *(u8 *)(reg_a5 + 0x32) = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(D_0025B610_as_u16_a);
        reg_d1.b[0] += 1;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x22) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x24) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_002589A0);
        reg_d0.h[0] = g_stage_x2;
        temp_a3 = reg_d0.h[0];
        reg_a0 += temp_a3;
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        *(s8 *)(reg_a5 + 0x35) = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(s8 *)(reg_a5 + 0x34) = *(s8 *)reg_a0;
        reg_tmp.w = (u32) (void *)entity_draw_layer2;
        temp_a2 = (u16 *)(reg_a0 + 1);
        reg_a0 = (u8 *)(temp_a2);
        *(u16 *)(reg_a5 + 0x2A) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0x2C) = (u16) reg_tmp.h[0];
        reg_tmp.w = (u32) (void *)sprite_draw_layer2;
        *(u16 *)(reg_a5 + 0x2E) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0x30) = (u16) reg_tmp.h[0];
        reg_d0.h[0] = g_scroll_line;
        if ((s16) reg_d0.h[0] >= 0xAC) {
            if ((ENTITY(reg_a6)->y.sh < 0x6400) && (g_enemy_signal_2 == 0)) {
                enemy_remove();
            }
        } else if ((s16) reg_d0.h[0] >= 0x8D) {
            temp_v1_2 = ENTITY(reg_a6)->y.sh;
            if ((temp_v1_2 > -0x3C00) && (temp_v1_2 < 0x6400) && (g_enemy_signal_1 == 0)) {
                enemy_remove();
            }
        } else if (((s16) reg_d0.h[0] >= 0x48) && (g_enemy_signal_0 == 0)) {
            enemy_remove();
        }
    }
}

extern u8 D_0025B490[];
extern u8 D_0025B510[];
extern u8 D_0025B610[];

s32 func_0016D040();
s32 score_add_masked();
s32 func_002031E0();
s32 wreck_spawn();
extern u16 g_frame_mod2;
extern u16 g_rank_10_16;

void func_0015B210(void) {
    s32 enemy_remove();
    s32 enemy_path_step();
    s32 sprite_draw_layer2();
    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    func_002031E0();
    switch (cond_flag) { case 0: goto skip_1; }
    if (*(u16 *)(reg_a5 + 0x16) == 0) goto block_touch;
    enemy_remove();
    return;
skip_1:
    *(u16 *)(reg_a5 + 0x16) = 1;
block_touch:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto block_pal;
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x34);
    ENTITY(reg_a6)->attr.b.palette ^= reg_d0.b[0];
    score_add_no_chain();
    if (ENTITY(reg_a6)->hp.sh >= 0) goto block_body;
    if (*(s8 *)(reg_a5 + 0x21) < 0) goto block_dead;
    ENTITY(reg_a6)->hp.h = *(u16 *)(reg_a5 + 0x26);
    reg_d0.w = 8;
    score_add_masked();
    *(u8 *)(reg_a5 + 0x21) |= 0x80;
    reg_d0.w = 3;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x10) = 2;
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    goto block_body;
block_pal:
    ENTITY(reg_a6)->attr.b.palette = *(u8 *)(reg_a5 + 0x35);
block_body:
    if (g_enemies_stopped != 0) goto block_obj;
    reg_d7.h[0] = ENTITY(reg_a6)->move.h;
    reg_d1.w = 0x3E;
    reg_d1.h[0] &= reg_d7.h[0];
    reg_d1.h[0] *= 4;
    if (reg_d7.h[0] & 0x40) goto skip_2;
    if (!(g_game_frame & 4)) goto skip_2;
    reg_d1.h[0] += 4;
skip_2:
    reg_a0 = (u8 *)D_0025B510;
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
block_obj:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x2A);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x2C);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target = (Fn)reg_a0;
    reg_call_target();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if (*(s8 *)(reg_a5 + 0x21) >= 0) goto block_turret;
    if (g_frame_mod2 == 0) return;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.w = 0;
    reg_d1.w += 0x0100FE00;
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x1E);
    reg_d2.h[0] += 1;
    if (reg_d2.h[0] != 4) goto skip_3;
    reg_d2.w = 0;
skip_3:
    *(u16 *)(reg_a5 + 0x1E) = reg_d2.h[0];
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x1E;
    reg_d2.w += 0x13D8;
    sprite_draw_layer2();
    return;
block_turret:
    if (g_enemies_stopped != 0) goto block_turret_obj;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x32);
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
    *(u8 *)(reg_a5 + 0x19) -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_shotint;
    *(u8 *)(reg_a5 + 0x19) = *(u8 *)(reg_a5 + 0x18);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x200;
    aim_at_player();
    if (cond_flag != 0) goto block_turret_obj;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x32);
    direction_turn_toward();
    *(u8 *)(reg_a5 + 0x32) = reg_d1.b[0];
    reg_a0 = (u8 *)D_0025B610;
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    *(u16 *)(reg_a5 + 0x22) = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x24) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
block_shotint:
    *(u8 *)(reg_a5 + 0x29) -= 1;
    if (*(u8 *)(reg_a5 + 0x29) == 0) goto block_shot;
block_turret_obj:
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFC00FC00;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x22);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x24);
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x2E);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x30);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target = (Fn)reg_a0;
    reg_call_target();
    return;
block_shot:
    reg_d0.h[0] = 0xA0;
    reg_d0.h[0] -= g_rank_10_16;
    reg_d0.h[0] += 4;
    *(u8 *)(reg_a5 + 0x29) = reg_d0.b[0];
    func_0016D040();
    if (cond_flag != 0) goto block_turret_obj;
    if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) goto block_turret_obj;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x32);
    reg_a0 = (u8 *)D_0025B490;
    reg_d1.b[0] += 2;
    reg_d1.h[0] &= 0x3C;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.w += reg_tmp.w;
    reg_d0.w = 0xD;
    reg_d3.w = 0x02000000;
    bullet_fire_fast();
    goto block_turret_obj;
block_dead:
    reg_d0.w = 0x10;
    score_add();
    reg_d0.w = 7;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x10) = 2;
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    reg_d0.w = 4;
    reg_d1.h[0] = 4;
    wreck_spawn();
    sfx_explosion_air_small();
    enemy_remove();
}
