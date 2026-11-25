#include "common.h"
#include "entity.h"

void enemy_set_entity_count(s32);

void func_00168110(void) {
    enemy_set_entity_count(0);
}


s32 enemy_remove();
s32 enemy_set_task_work();
s32 enemy_init_entities();
s32 enemy_path_start();
s32 func_00202180();
extern u16 D_0025AEF0[];
extern u16 D_0025AF00[];
extern u16 D_0025AF20[];
extern u16 D_0025AF40[];
extern u16 D_0025AFC0[];
extern u16 g_enemy_signal_2;
extern u16 g_rank_1_16;
extern u16 g_stage_x2;
extern u16 g_stage;
extern s8 enemy_move_end_requested;

void func_00168120(void) {
    if ((g_stage == 3) && (g_enemy_signal_2 != 0)) {
        enemy_remove();
        return;
    }
    reg_a0 = (u8 *)(D_0025AF20);
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(D_0025AF00);
    reg_d0.w = 8;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        func_00202180();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        *(u8 *)(reg_a5 + 0x26) = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(D_0025AF40);
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_0025AFC0);
        *(u16 *)(reg_a5 + 0x22) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x24) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = g_rank_1_16;
        reg_d0.b[0] >>= 1;
        *(u8 *)(reg_a5 + 0x1B) -= reg_d0.b[0];
        reg_d0.h[0] = g_rank_1_16;
        *(u8 *)(reg_a5 + 0x1A) -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025AEF0);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        *(s8 *)(reg_a5 + 0x19) = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(s8 *)(reg_a5 + 0x18) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

s32 bullet_fire_fast();
s32 bullet_fire256_double();
s32 explosion_spawn();
s32 enemy_hitbox_debug_draw();
s32 enemy_path_step();
s32 func_0018D540();
s32 entity_draw_layer5();
s32 sprite_draw_layer4();
s32 score_add_no_chain();
s32 score_add();
s32 direction_between();
s32 direction_turn_toward();
s32 func_00202730();
extern u16 D_0025B040[];
extern u16 D_0028E3EC;
extern s16 *reg_save_atmp;
extern u16 g_enemy_signal_1;
extern u16 g_bullets_blocked;
extern u16 g_enemies_stopped;
extern u16 g_scroll_line;
extern u16 D_0028E8B8;
extern u16 g_rank_4_16;
extern u16 g_loop;
extern u16 D_0029C068[];
extern u16 g_player2_as_u16_a[];
extern u16 g_player1_as_u16_a[];

void func_001683C0(void) {
    u16 swap;
    s16 *t1;
    s16 *t2;
    u16 *t3;
    u16 t4;
    u16 t5;

    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    {
        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
        reg_tmp1.w = 0;
        reg_tmp.w = 0;
        reg_d0.h[0] += D_0029C068[0];
        reg_tmp1.h[0] = 0xAC00;
        reg_d0.h[0] += 0xE00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x7FFF + 0x2C01;
        if (reg_tmp.h[1] != 0) goto next_20;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x8400;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] = reg_d0.h[1];
        swap = reg_tmp.h[0];
        reg_d0.h[0] += 0x600;
        reg_tmp.w = 0;
        reg_d0.h[1] = swap;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x7FFF + 0x401;
        if (reg_tmp.h[1] == 0) goto next_30;
next_20:
        if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_1;
        enemy_remove();
        return;
next_30:
        *(u8 *)(reg_a5 + 0x17) = 1U;
next_1:
        t2 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(t2) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
            if (((s32) (*(u16 *)((u8 *)(t2) + (0x18))) < 0x1C) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto next_2;
        }
        (*(u8 *)((u8 *)(t2) + (1))) &= 0xA3;
        score_add_no_chain();
        t2 = (s16 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(t2) + (0x1C)));
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
        }
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) (*(u16 *)((u8 *)(t2) + (0x18))) >= 0) {
next_2:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                reg_a0 = (u8 *)(g_player1_as_u16_a);
                reg_a1 = (u8 *)(g_player2_as_u16_a);
                if (*(u8 *)(reg_a5 + 2) != 0) {
                    reg_save_atmp = (s16 *)(reg_a1);
                    reg_a1 = (u8 *)(reg_a0);
                    reg_a0 = (u8 *)(reg_save_atmp);
                }
                if (*(s16 *)reg_a0 >= 0) {
                    t1 = (s16 *)(reg_a1);
                    if (*t1 < 0) {
                        reg_a1 = (u8 *)(reg_a0);
                        reg_save_atmp = (s16 *)(t1);
                        reg_a0 = (u8 *)(t1);
                        goto next_3;
                    }
                } else {
next_3:
                    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                    direction_between();
                    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x26);
                    direction_turn_toward();
                    *(u16 *)(reg_a5 + 0x26) = (u16) reg_d1.h[0];
                    reg_a3 = (u8 *)(D_0025AF40);
                    reg_d1.h[0] &= 0x3E;
                    reg_d1.h[0] += reg_d1.h[0];
                    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                    reg_a3 = (u8 *)(D_0025AFC0);
                    *(u16 *)(reg_a5 + 0x22) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                    *(u16 *)(reg_a5 + 0x24) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                }
                t2 = (s16 *) ((s16) ENTITY(reg_a6)->y.h < 0x1000);
                if (t2 == 0) {
                    t2 = (s16 *) g_enemy_signal_1;
                    if (t2 != 0) {
                        t5 = g_stage;
                        reg_a4 = (u8 *)(D_0025B040);
                        reg_d1.h[0] = *(u16 *)(reg_a5 + 0x26);
                        reg_d5.h[0] = reg_d1.h[0];
                        reg_d5.h[0] &= 0x3E;
                        reg_d5.h[0] += reg_d5.h[0];
                        reg_a4 += reg_d5.h[0];
                        reg_d3.h[1] = *(u16 *)reg_a4;
                        reg_a4 += 2;
                        t3 = (u16 *)(reg_a4 + 2);
                        reg_d3.h[0] = *(u16 *)reg_a4;
                        reg_a4 = (u8 *)(t3);
                        reg_d0.w = 0x30007;
                        reg_d4.w = 0;
                        if ((t5 == 3) && ((s32) g_scroll_line >= 0x240)) {
                            reg_d0.w = 0xFFFE0007;
                        }
                        if (g_loop != 0) {
                            reg_d0.w += 0x20000;
                        }
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                        bullet_fire_fast();
                        *(u8 *)(reg_a5 + 0x1D) -= 1;
                        t2 = (s16 *)(reg_a5 + 0x1D);
                        if ((s8) *(u8 *)(reg_a5 + 0x1D) < 0) {
                            *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
                            reg_d0.h[0] = 0x20;
                            reg_d0.h[0] -= g_rank_4_16;
                            reg_d0.h[0] += 8;
                            *(u8 *)(reg_a5 + 0x1B) = (u8) reg_d0.b[0];
                        }
                    }
                }
            }
            entity_draw_layer5();
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            switch (D_0028E3EC) {
            case 0:
                return;
            default:
                break;
            }
            {
                reg_d1.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] += 0x7FFF + 0x6E01;
                reg_tmp1.h[0] = reg_d1.h[0];
                reg_d1.h[0] = reg_d1.h[1];
                reg_d1.h[1] = reg_tmp1.h[0];
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.h[0] += 0x200;
                reg_d2.h[1] = *(u16 *)(reg_a5 + 0x22);
                t4 = *(u16 *)(reg_a5 + 0x24);
                reg_d2.h[0] = t4;
                reg_d3.h[0] = 0x410;
                reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
                reg_d4.b[0] = 0x18;
                sprite_draw_layer4();
            }
        } else {
            reg_d0.w = 0x11;
            score_add();
            if (g_loop != 0) {
                func_00202730();
                if (cond_flag == 0) {
                    reg_d0.w = 0x1000C;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d4.w = 0;
                    reg_d3.w = 0;
                    bullet_fire256_double();
                }
            }
            reg_d0.w = 2;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
            reg_d0.b[0] += 8;
            *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d1.b[0] *= 4;
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d1.b[0];
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            func_0018D540();
            enemy_remove();
        }
    }
}
