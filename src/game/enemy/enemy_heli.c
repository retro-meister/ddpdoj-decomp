#include "common.h"
#include "entity.h"
#include "explosion.h"
#include "enemy.h"

/*
 * The helicopters' part of the enemy state block (reg_a5). All eight kinds share it. Kind G keeps other
 * things in the four bytes from 0x26.
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];        /* EnemyState */
    /* 0x16 */ u8 other_16[2];
    /* 0x18 */ union { s16 h; struct { u8 other; u8 countdown; } b; } fire;  /* frames to the next shot */
    /* 0x1A */ u8 turn_interval;       /* frames between two turns towards the player */
    /* 0x1B */ u8 turn_countdown;
    /* 0x1C */ u16 facing_reached;
    /* 0x1E */ u8 facing_step;         /* +4 or -4 */
    /* 0x1F */ u8 other_1F;
    /* 0x20 */ u16 rotor_frame;        /* 0, 4, 8, 12 */
    /* 0x22 */ u8 facing;              /* direction the body is drawn in */
    /* 0x23 */ u8 facing_wanted;       /* set by the path */
    /* 0x24 */ union { u16 h; struct { u8 interval; u8 countdown; } b; } facing_timer;
    /* 0x26 */ Field16 facing_started;
    /* 0x28 */ Field16 turns_left;
    /* 0x2A */ u8 hit_palette;         /* mixed into the palette on the frame of a hit */
    /* 0x2B */ u8 palette;
    /* 0x2C */ u16 shadow_sprite[2];   /* the shadow drawn under it, high word first */
} HeliState;

#define HELI(pointer) ((HeliState *)(pointer))

void heli_draw(void);


s32 explosion_spawn();
s32 sfx_explosion_ground_small();
s32 score_add_no_chain();
s32 score_add();

void heli_take_hits(u32 arg0) {
    s32 enemy_remove();
    u8 temp_a0;
    u8 temp_a1;

    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = HELI(reg_a5)->palette;
        reg_d2.b[0] = HELI(reg_a5)->hit_palette;
        reg_d0.b[0] ^= reg_d2.b[0];
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = arg0;
            score_add();
            reg_d0.w = 2;
            explosion_spawn();
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)->y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)->x.h;
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
            reg_d0.b[0] += 8;
            EXPLOSION(reg_a0)->move.b.speed = (u8) reg_d0.b[0];
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d1.b[0] *= 4;
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d1.b[0];
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            sfx_explosion_ground_small();
            enemy_remove();
            cond_flag = 1;
            return;
        }
        goto block_4;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) HELI(reg_a5)->palette;
block_4:
    cond_flag = 0;
}

extern u16 D_002579D0[];

void heli_muzzle_offset(u8 arg0) {
    reg_d2.w = 0;
    reg_d2.b[0] = arg0;
    reg_a0 = (u8 *)(D_002579D0);
    reg_d2.h[0] += 1;
    reg_d2.h[0] &= 0x3E;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
}

void func_00150730(void) {
}

extern u16 g_enemy_signal_0;
extern u16 g_stage;

void heli_remove_on_signal_0(void) {
    s32 enemy_remove(u16);
    if ((g_stage == 1) && (g_enemy_signal_0 != 0)) {
        enemy_remove(g_stage);
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

extern u16 g_enemy_signal_f;

void heli_remove_on_signal_f(void) {
    s32 enemy_remove(u16);
    if ((g_stage == 2) && (g_enemy_signal_f != 0)) {
        enemy_remove(g_stage);
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

s32 enemy_hitbox_debug_draw(void);
s32 sprite_draw_layer4(void);
s32 sprite_draw_layer5(void);
extern u8 D_00257880[];
extern u16 g_frame_mod2;
extern u16 g_loop;

void heli_draw_rotor_and_shadow(void) {
    u32 offset;

    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if (g_frame_mod2 != 0) {
        reg_d1.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] += 0x7FFF + 0x7901;
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d3.h[0] = 0x828;
        reg_d1.h[0] += 0x7FFF + 0x7B01;
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        reg_d2.h[0] = HELI(reg_a5)->rotor_frame;
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)(D_00257880 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)D_00257880;
        offset = reg_d2.h[0] + 2;
        reg_d2.h[0] = (offset != 0) ? *(u16 *)(D_00257880 + ((s16)offset & ~1)) : *(u16 *)D_00257880;
        sprite_draw_layer5();
        HELI(reg_a5)->rotor_frame += 4;
        HELI(reg_a5)->rotor_frame &= 0xF;
    block_rts:
        return;
    }
    if (g_loop != 0) {
        goto block_rts;
    }
    switch (g_stage) {
    case 2:
        return;
    }
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] += 0x7FFF + 0x6C01;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x400;
    reg_d2.h[1] = HELI(reg_a5)->shadow_sprite[0];
    reg_d2.h[0] = HELI(reg_a5)->shadow_sprite[1];
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = 0x18;
    sprite_draw_layer4();
}


extern void enemy_set_entity_count(s32);

void heli_a_first(void) {
    enemy_set_entity_count(0);
}


s32 enemy_set_task_state();
s32 enemy_init_entities();
s32 enemy_path_start();
s32 heli_x_limit_check();
extern u16 D_00257890[];
extern u16 D_002578B0[];
extern u16 D_002578D0[];
extern u16 D_00257950[];
extern u16 g_enemy_signal_5;
extern u16 g_enemy_signal_4;
extern u16 g_enemy_signal_3;
extern u16 g_enemy_signal_2;
extern u16 g_enemy_signal_1;
extern u16 g_rank_2_16;
extern s8 enemy_move_end_requested;

void heli_a_start(void) {
    s32 enemy_remove();
    heli_remove_on_signal_0();
    if ((cond_flag == 0) && (reg_a0 = (u8 *)D_002578B0, enemy_init_entities(), reg_a0 = (u8 *)D_00257890, reg_d0.h[0] = 0xC, enemy_set_task_state(), ENTITY(reg_a6)->attr.b.palette = (u8) HELI(reg_a5)->palette, enemy_path_start(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        HELI(reg_a5)->shadow_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        HELI(reg_a5)->shadow_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        if (ENEMY_STATE(reg_a5)->kind & 0x20) {
            heli_x_limit_check();
        }
        reg_d0.h[0] = g_rank_2_16;
        reg_d0.b[0] -= 8;
        HELI(reg_a5)->fire.b.countdown -= reg_d0.b[0];
        if (g_stage == 4) {
            if (g_enemy_signal_1 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_2 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_3 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_4 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_5 != 0) {
                enemy_remove();
            }
        }
    }
}

s32 bullet_fire();
s32 func_00171430();
s32 entity_velocity();
s32 direction_to_target_player();
s32 entity_turn_to_target_player();
s32 entity_in_shot_limits();
extern u16 g_enemies_stopped;
extern u16 g_rank_5_16;

void heli_a(void) {
    u16 temp_a0_2;
    heli_take_hits(8);
    if ((cond_flag == 0) && (func_00171430(), (cond_flag == 0))) {
        if (g_enemies_stopped != 0) {
#ifndef DEATH_LABEL
            heli_draw();
#endif
            return;
        }
        entity_velocity();
        if (HELI(reg_a5)->turns_left.h != 0) {
            reg_tmp.b[0] = HELI(reg_a5)->turn_countdown;
            HELI(reg_a5)->turn_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                HELI(reg_a5)->turn_countdown = (u8) HELI(reg_a5)->turn_interval;
                HELI(reg_a5)->turns_left.h -= 1;
                entity_turn_to_target_player();
                if (cond_flag != 0) {
                    heli_draw();
                    return;
                }
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                HELI(reg_a5)->shadow_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                HELI(reg_a5)->shadow_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                goto block_21;
            }
        }
block_21:
        reg_tmp.b[0] = HELI(reg_a5)->fire.b.countdown;
        HELI(reg_a5)->fire.b.countdown -= 1;
        if ((s32) reg_tmp.b[0] > 0) {
            heli_draw();
            return;
        }
        reg_d0.w = 0x58;
        reg_d0.h[0] -= g_rank_5_16;
        reg_d0.h[0] += 2;
        HELI(reg_a5)->fire.b.countdown = (u8) reg_d0.b[0];
        entity_in_shot_limits();
        if (cond_flag != 0) {
            heli_draw();
            return;
        }
        direction_to_target_player();
        if (cond_flag != 0) {
            heli_draw();
            return;
        }
        heli_muzzle_offset(ENTITY(reg_a6)->move.b.dir);
        reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0_2 = ENTITY(reg_a6)->x.h;
        reg_tmp.h[0] = temp_a0_2;
        reg_d0.w = 0x3000D;
        reg_d2.w += reg_tmp.w;
        func_00150730();
        reg_d3.w = 0;
        bullet_fire();
        heli_draw();
    }
}

s32 entity_draw_layer5();                            /* extern */

void heli_draw(void) {
    entity_draw_layer5();
    heli_draw_rotor_and_shadow();
}

s32 entity_draw_layer5();

void heli_set_direction_sprite(void) {
    reg_a0 = (u8 *)(D_002578D0);
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_00257950);
    HELI(reg_a5)->shadow_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    HELI(reg_a5)->shadow_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    entity_draw_layer5();
    heli_draw_rotor_and_shadow();
}

void heli_b_first(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257A50[];
extern u16 D_00257A70[];

void heli_b_start(void) {
    heli_remove_on_signal_0();
    if (cond_flag == 0) {
        heli_remove_on_signal_f();
        if (cond_flag == 0) {
            reg_a0 = (u8 *)(D_00257A70);
            enemy_init_entities();
            reg_a0 = (u8 *)(D_00257A50);
            reg_d0.h[0] = 0xA;
            enemy_set_task_state();
            ENTITY(reg_a6)->attr.b.palette = (u8) HELI(reg_a5)->palette;
            enemy_path_start();
            if (enemy_move_end_requested == 0) {
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                HELI(reg_a5)->shadow_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                HELI(reg_a5)->shadow_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                if (ENEMY_STATE(reg_a5)->kind & 0x20) {
                    heli_x_limit_check();
                }
                reg_d0.h[0] = g_rank_2_16;
                reg_d0.b[0] -= 8;
                HELI(reg_a5)->fire.b.countdown -= reg_d0.b[0];
            }
        }
    }
}

s32 enemy_path_step();

void heli_b(void) {
    u16 temp_a0_2;
    heli_take_hits(8);
    if ((cond_flag == 0) && (func_00171430(), (cond_flag == 0))) {
        if (g_enemies_stopped != 0) {
            heli_draw();
            return;
        }
        if (HELI(reg_a5)->facing_reached != 0) {
            entity_velocity();
            goto block_7;
        }
        enemy_path_step();
        if (enemy_move_end_requested == 0) {
block_7:
            if ((s32) ENTITY(reg_a6)->move.b.dir >= 0x40) {
                HELI(reg_a5)->facing_reached = 1U;
            }
            if ((HELI(reg_a5)->turns_left.h != 0) && (HELI(reg_a5)->facing_reached != 0)) {
                reg_tmp.b[0] = HELI(reg_a5)->turn_countdown;
                HELI(reg_a5)->turn_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    HELI(reg_a5)->turn_countdown = (u8) HELI(reg_a5)->turn_interval;
                    HELI(reg_a5)->turns_left.b[1] -= 1;
                    entity_turn_to_target_player();
                    goto block_13;
                }
            } else {
block_13:
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                HELI(reg_a5)->shadow_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                HELI(reg_a5)->shadow_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            }
            reg_tmp.b[0] = HELI(reg_a5)->fire.b.countdown;
            HELI(reg_a5)->fire.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                heli_draw();
                return;
            }
            reg_d0.w = 0x58;
            reg_d0.h[0] -= g_rank_5_16;
            reg_d0.h[0] += 2;
            HELI(reg_a5)->fire.b.countdown = (u8) reg_d0.b[0];
            entity_in_shot_limits();
            if (cond_flag != 0) {
                heli_draw();
                return;
            }
            direction_to_target_player();
            if (cond_flag != 0) {
                heli_draw();
                return;
            }
            heli_muzzle_offset(ENTITY(reg_a6)->move.b.dir);
            reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
            temp_a0_2 = ENTITY(reg_a6)->x.h;
            reg_tmp.h[0] = temp_a0_2;
            reg_d0.w = 0x3000D;
            reg_d2.w += reg_tmp.w;
            func_00150730();
            reg_d3.w = 0;
            bullet_fire();
            heli_draw();
        }
    }
}

void heli_c_first(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257A90[];
extern u16 D_00257AB0[];

void heli_c_start(void) {
    heli_remove_on_signal_0();
    if (cond_flag == 0) {
        heli_remove_on_signal_f();
        if (cond_flag == 0) {
            reg_a0 = (u8 *)(D_00257AB0);
            enemy_init_entities();
            reg_a0 = (u8 *)(D_00257A90);
            reg_d0.h[0] = 0xA;
            enemy_set_task_state();
            ENTITY(reg_a6)->attr.b.palette = (u8) HELI(reg_a5)->palette;
            enemy_path_start();
            if (enemy_move_end_requested == 0) {
                reg_a0 = (u8 *)(D_002578D0);
                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d1.h[0] &= 0x3E;
                reg_d1.h[0] += reg_d1.h[0];
                ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_a0 = (u8 *)(D_00257950);
                HELI(reg_a5)->shadow_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
                HELI(reg_a5)->shadow_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                if (ENEMY_STATE(reg_a5)->kind & 0x20) {
                    heli_x_limit_check();
                }
                reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d0.b[0] += 0x20;
                reg_d0.b[0] &= 0x3C;
                HELI(reg_a5)->facing_wanted = (u8) reg_d0.b[0];
                direction_to_target_player();
                if (cond_flag != 0) {
                    reg_d1.w = 0x20;
                }
                HELI(reg_a5)->facing = (u8) reg_d1.b[0];
                reg_d0.h[0] = g_rank_2_16;
                reg_d0.b[0] -= 8;
                HELI(reg_a5)->fire.b.countdown -= reg_d0.b[0];
                if (g_stage == 2) {
                    HELI(reg_a5)->fire.b.countdown = 0xAU;
                }
            }
        }
    }
}

s32 direction_turn_toward();
extern u16 g_frame_mod4;

void heli_c(void) {
    heli_take_hits(8);
    if (cond_flag != 0) return;
    func_00171430();
    if (cond_flag != 0) return;
    reg_d1.b[0] = HELI(reg_a5)->facing;
    if (g_enemies_stopped != 0) {
        heli_set_direction_sprite();
        return;
    }
    entity_velocity();
    if (HELI(reg_a5)->facing_started.h != 0) goto next_4;
    if (ENTITY(reg_a6)->move.b.speed == 0) goto next_1;
    reg_tmp.b[0] = HELI(reg_a5)->facing_timer.b.countdown;
    HELI(reg_a5)->facing_timer.b.countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_1;
    HELI(reg_a5)->facing_timer.b.countdown = HELI(reg_a5)->facing_timer.b.interval;
    ENTITY(reg_a6)->move.b.speed -= 1;
    if (ENTITY(reg_a6)->move.b.speed != 0) goto next_1;
    HELI(reg_a5)->facing_timer.h = 3;
    HELI(reg_a5)->fire.b.countdown = 0x10;
    reg_d1.h[0] = 0x3000;
    reg_d1.b[0] = HELI(reg_a5)->facing;
    reg_d1.b[0] &= 0x3C;
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    HELI(reg_a5)->turn_countdown = 0x30;
    if (HELI(reg_a5)->facing_wanted == reg_d1.b[0]) goto next_1;
    if ((s32)HELI(reg_a5)->facing_wanted < (s32)reg_d1.b[0]) goto next_0;
    HELI(reg_a5)->facing_step = 0xFC;
    goto next_1;
next_0:
    HELI(reg_a5)->facing_step = 4;
next_1:
    reg_d1.b[0] = HELI(reg_a5)->facing;
    if (g_frame_mod4 != 0) goto next_2;
    direction_to_target_player();
    reg_d0.b[0] = HELI(reg_a5)->facing;
    direction_turn_toward();
    HELI(reg_a5)->facing = reg_d1.b[0];
next_2:
    if (ENTITY(reg_a6)->move.b.speed != 0) goto next_7;
    HELI(reg_a5)->facing_started.h = 1;
    goto next_7;
next_4:
    if (ENTITY(reg_a6)->move.b.speed == 0x1C) goto next_5;
    reg_tmp.b[0] = HELI(reg_a5)->facing_timer.b.countdown;
    HELI(reg_a5)->facing_timer.b.countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_5;
    HELI(reg_a5)->facing_timer.b.countdown = HELI(reg_a5)->facing_timer.b.interval;
    ENTITY(reg_a6)->move.b.speed += 1;
next_5:
    if (HELI(reg_a5)->facing_reached != 0) goto next_6;
    reg_tmp.b[0] = HELI(reg_a5)->turn_countdown;
    HELI(reg_a5)->turn_countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_6;
    HELI(reg_a5)->turn_countdown = HELI(reg_a5)->turn_interval;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] += HELI(reg_a5)->facing_step;
    reg_d1.b[0] &= 0x3C;
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    if (HELI(reg_a5)->facing_wanted != reg_d1.b[0]) {
        heli_set_direction_sprite();
        return;
    }
    HELI(reg_a5)->facing_reached = 1;
next_6:
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    heli_set_direction_sprite();
    return;
next_7:
    reg_tmp.b[0] = HELI(reg_a5)->fire.b.countdown;
    HELI(reg_a5)->fire.b.countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) {
        heli_set_direction_sprite();
        return;
    }
    reg_d0.w = 0x58;
    reg_d0.h[0] -= g_rank_5_16;
    reg_d0.h[0] += 2;
    HELI(reg_a5)->fire.b.countdown = reg_d0.b[0];
    entity_in_shot_limits();
    if (cond_flag != 0) {
        heli_set_direction_sprite();
        return;
    }
    direction_to_target_player();
    if (cond_flag != 0) {
        heli_set_direction_sprite();
        return;
    }
    heli_muzzle_offset(reg_d1.b[0]);
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w = 0x3000D;
    reg_d2.w += reg_tmp.w;
    func_00150730();
    reg_d3.w = 0;
    bullet_fire();
    heli_set_direction_sprite();
}

void heli_d_first(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257AD0[];
extern u16 D_00257AF0[];
extern u16 g_enemy_signal_7;
extern u16 g_enemy_signal_6;

void heli_d_start(void) {
    s32 enemy_remove();
    heli_remove_on_signal_0();
    if ((cond_flag == 0) && (heli_remove_on_signal_f(), (cond_flag == 0)) && (reg_a0 = (u8 *)D_00257AF0, enemy_init_entities(), reg_a0 = (u8 *)D_00257AD0, reg_d0.h[0] = 0xA, enemy_set_task_state(), ENTITY(reg_a6)->attr.b.palette = (u8) HELI(reg_a5)->palette, enemy_path_start(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        HELI(reg_a5)->shadow_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        HELI(reg_a5)->shadow_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        if (ENEMY_STATE(reg_a5)->kind & 0x20) {
            heli_x_limit_check();
        }
        reg_d1.w = 0x20;
        direction_to_target_player();
        HELI(reg_a5)->facing = (u8) reg_d1.b[0];
        reg_d0.h[0] = g_rank_2_16;
        reg_d0.b[0] -= 8;
        HELI(reg_a5)->fire.b.countdown -= reg_d0.b[0];
        if (g_stage == 4) {
            if (g_enemy_signal_4 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_5 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_6 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_7 != 0) {
                enemy_remove();
            }
        }
    }
}

#ifdef DEATH_LABEL
s32 entity_turn_to_target_player();
#endif

void heli_d(void) {
    heli_take_hits(8);
    if (cond_flag != 0) return;
    func_00171430();
    if (cond_flag != 0) return;
    reg_d1.b[0] = HELI(reg_a5)->facing;
    if (g_enemies_stopped != 0) {
        heli_set_direction_sprite();
        return;
    }
    entity_velocity();
    if (HELI(reg_a5)->facing_started.h != 0) goto next_4;
    if (ENTITY(reg_a6)->move.b.speed == 0) goto next_1;
    reg_tmp.b[0] = HELI(reg_a5)->facing_timer.b.countdown;
    HELI(reg_a5)->facing_timer.b.countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_1;
    HELI(reg_a5)->facing_timer.b.countdown = HELI(reg_a5)->facing_timer.b.interval;
    ENTITY(reg_a6)->move.b.speed -= 1;
    if (ENTITY(reg_a6)->move.b.speed != 0) goto next_1;
    HELI(reg_a5)->facing_timer.h = 2;
    HELI(reg_a5)->fire.b.countdown = 0x10;
    reg_d1.b[0] = HELI(reg_a5)->facing;
    reg_d1.b[0] &= 0x3C;
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    HELI(reg_a5)->turn_countdown = 0x30;
next_1:
    reg_d1.b[0] = HELI(reg_a5)->facing;
    if (g_frame_mod4 != 0) goto next_2;
    direction_to_target_player();
    reg_d0.b[0] = HELI(reg_a5)->facing;
    direction_turn_toward();
    HELI(reg_a5)->facing = reg_d1.b[0];
next_2:
    if (ENTITY(reg_a6)->move.b.speed != 0) goto next_7;
    HELI(reg_a5)->facing_started.h = 1;
    goto next_7;
next_4:
    if (ENTITY(reg_a6)->move.b.speed == MAIN_OR_DEATH_LABEL(0x1C, 0x20)) goto next_5;
    reg_tmp.b[0] = HELI(reg_a5)->facing_timer.b.countdown;
    HELI(reg_a5)->facing_timer.b.countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_5;
    HELI(reg_a5)->facing_timer.b.countdown = HELI(reg_a5)->facing_timer.b.interval;
    ENTITY(reg_a6)->move.b.speed += MAIN_OR_DEATH_LABEL(1, 2);
next_5:
#ifdef DEATH_LABEL
    if (HELI(reg_a5)->facing_reached == 0) goto next_6;
    reg_tmp.b[0] = HELI(reg_a5)->turn_countdown;
    HELI(reg_a5)->turn_countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_6;
    HELI(reg_a5)->turn_countdown = HELI(reg_a5)->turn_interval;
    HELI(reg_a5)->turns_left.h -= 1;
    entity_turn_to_target_player();
    heli_set_direction_sprite();
    return;
#else
    if (HELI(reg_a5)->facing_reached != 0) goto next_6;
    reg_tmp.b[0] = HELI(reg_a5)->turn_countdown;
    HELI(reg_a5)->turn_countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_6;
    HELI(reg_a5)->turn_countdown = HELI(reg_a5)->turn_interval;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] += HELI(reg_a5)->facing_step;
    reg_d1.b[0] &= 0x3C;
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    if (HELI(reg_a5)->facing_wanted != reg_d1.b[0]) {
        heli_set_direction_sprite();
        return;
    }
    HELI(reg_a5)->facing_reached = 1;
#endif
next_6:
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    heli_set_direction_sprite();
    return;
next_7:
    reg_tmp.b[0] = HELI(reg_a5)->fire.b.countdown;
    HELI(reg_a5)->fire.b.countdown -= 1;
    if ((s32)reg_tmp.b[0] > 0) {
        heli_set_direction_sprite();
        return;
    }
    reg_d0.w = 0x58;
    reg_d0.h[0] -= g_rank_5_16;
    reg_d0.h[0] += 2;
    HELI(reg_a5)->fire.b.countdown = reg_d0.b[0];
    entity_in_shot_limits();
    if (cond_flag != 0) {
        heli_set_direction_sprite();
        return;
    }
    direction_to_target_player();
    if (cond_flag != 0) {
        heli_set_direction_sprite();
        return;
    }
    heli_muzzle_offset(reg_d1.b[0]);
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w = 0x3000D;
    reg_d2.w += reg_tmp.w;
    func_00150730();
    reg_d3.w = 0;
    bullet_fire();
    heli_set_direction_sprite();
}

void heli_e_first(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257B10[];
extern u16 D_00257B30[];

void heli_e_start(void) {
    heli_remove_on_signal_0();
    if (cond_flag == 0) {
        reg_a0 = (u8 *)(D_00257B30);
        enemy_init_entities();
        reg_a0 = (u8 *)(D_00257B10);
        reg_d0.h[0] = 0xA;
        enemy_set_task_state();
        ENTITY(reg_a6)->attr.b.palette = (u8) HELI(reg_a5)->palette;
        enemy_path_start();
        if (enemy_move_end_requested == 0) {
            reg_a0 = (u8 *)(D_002578D0);
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d1.h[0] &= 0x3E;
            reg_d1.h[0] += reg_d1.h[0];
            ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_a0 = (u8 *)(D_00257950);
            HELI(reg_a5)->shadow_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            HELI(reg_a5)->shadow_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            if (ENEMY_STATE(reg_a5)->kind & 0x20) {
                heli_x_limit_check();
            }
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d0.b[0] += 0x20;
            reg_d0.b[0] &= 0x3C;
            HELI(reg_a5)->facing_wanted = (u8) reg_d0.b[0];
            direction_to_target_player();
            if (cond_flag != 0) {
                reg_d1.w = 0x20;
            }
            HELI(reg_a5)->facing = (u8) reg_d1.b[0];
            reg_d0.h[0] = g_rank_2_16;
            reg_d0.b[0] -= 8;
            HELI(reg_a5)->fire.b.countdown -= reg_d0.b[0];
        }
    }
}

void heli_e(void) {
    u16 temp_a0;
    u8 temp_v0;
    u8 *var_a0;

    heli_take_hits(8);
    if ((cond_flag == 0) && (func_00171430(), (cond_flag == 0))) {
        reg_d1.b[0] = HELI(reg_a5)->facing;
        if (g_enemies_stopped != 0) {
            heli_set_direction_sprite();
            return;
        }
        entity_velocity();
        HELI(reg_a5)->fire.b.countdown -= 1;
        if (HELI(reg_a5)->fire.b.countdown == 0) {
            reg_d0.w = 0x58;
            reg_d0.h[0] -= g_rank_5_16;
            reg_d0.h[0] += 2;
            HELI(reg_a5)->fire.b.countdown = (u8) reg_d0.b[0];
            entity_in_shot_limits();
            if (cond_flag == 0) {
                direction_to_target_player();
                if (cond_flag == 0) {
                    heli_muzzle_offset(reg_d1.b[0]);
                    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
                    temp_a0 = ENTITY(reg_a6)->x.h;
                    reg_tmp.h[0] = temp_a0;
                    reg_d0.w = 0xD;
                    reg_d2.w += reg_tmp.w;
                    func_00150730();
                    reg_d3.w = 0;
                    bullet_fire();
                }
            }
        }
        var_a0 = (u8 *)(reg_a5);
        if ((*(u16 *)((u8 *)(var_a0) + (0x26))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x25)));
            (*(u8 *)((u8 *)(var_a0) + (0x25))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                HELI(reg_a5)->facing_timer.b.countdown = (u8) HELI(reg_a5)->facing_timer.b.interval;
                ENTITY(reg_a6)->move.b.speed -= 1;
                if (ENTITY(reg_a6)->move.b.speed == 0) {
                    HELI(reg_a5)->facing_started.h = 1U;
                    HELI(reg_a5)->facing_timer.h = 2;
                    HELI(reg_a5)->fire.h = 0x3008;
                    var_a0 = (u8 *)((void *) HELI(reg_a5)->facing_wanted);
                    ENTITY(reg_a6)->move.sb.dir = (s8) var_a0;
                    HELI(reg_a5)->turn_countdown = 0x30U;
                }
            }
        } else {
            temp_v0 = (*(u8 *)((u8 *)(var_a0) + (0x1B)));
            if (temp_v0 != 0) {
                (*(u8 *)((u8 *)(var_a0) + (0x1B))) = (u8) (temp_v0 - 1);
            } else if (ENTITY(reg_a6)->move.b.speed != 0x20) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x25)));
                (*(u8 *)((u8 *)(var_a0) + (0x25))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    HELI(reg_a5)->facing_timer.b.countdown = (u8) HELI(reg_a5)->facing_timer.b.interval;
                    ENTITY(reg_a6)->move.b.speed += 2;
                }
            }
        }
        reg_d1.b[0] = HELI(reg_a5)->facing;
        if (g_frame_mod4 != 0) {
            heli_set_direction_sprite();
            return;
        }
        direction_to_target_player();
        reg_d0.b[0] = HELI(reg_a5)->facing;
        direction_turn_toward();
        HELI(reg_a5)->facing = (u8) reg_d1.b[0];
        heli_set_direction_sprite();
    }
}

void heli_f_first(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257B50[];
extern u16 D_00257B70[];

void heli_f_start(void) {
    heli_remove_on_signal_0();
    if (cond_flag == 0) {
        reg_a0 = (u8 *)(D_00257B70);
        enemy_init_entities();
        reg_a0 = (u8 *)(D_00257B50);
        reg_d0.h[0] = 0xA;
        enemy_set_task_state();
        ENTITY(reg_a6)->attr.b.palette = (u8) HELI(reg_a5)->palette;
        enemy_path_start();
        if (enemy_move_end_requested == 0) {
            reg_a0 = (u8 *)(D_002578D0);
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d1.h[0] &= 0x3E;
            reg_d1.h[0] += reg_d1.h[0];
            ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_a0 = (u8 *)(D_00257950);
            HELI(reg_a5)->shadow_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            HELI(reg_a5)->shadow_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            direction_to_target_player();
            if (cond_flag != 0) {
                reg_d1.w = 0x20;
            }
            HELI(reg_a5)->facing = (u8) reg_d1.b[0];
            if (ENEMY_STATE(reg_a5)->kind & 0x20) {
                heli_x_limit_check();
            }
            reg_d0.h[0] = g_rank_2_16;
            reg_d0.b[0] -= 8;
            HELI(reg_a5)->fire.b.countdown -= reg_d0.b[0];
        }
    }
}

void heli_f(void) {
    u16 temp_a0;

    heli_take_hits(8);
    if ((cond_flag == 0) && (func_00171430(), (cond_flag == 0))) {
        reg_d1.b[0] = HELI(reg_a5)->facing;
        if (g_enemies_stopped != 0) {
            heli_set_direction_sprite();
            return;
        }
        entity_velocity();
        HELI(reg_a5)->fire.b.countdown -= 1;
        if (HELI(reg_a5)->fire.b.countdown == 0) {
            reg_d0.w = 0x58;
            reg_d0.h[0] -= g_rank_5_16;
            reg_d0.h[0] += 2;
            HELI(reg_a5)->fire.b.countdown = (u8) reg_d0.b[0];
            entity_in_shot_limits();
            if (cond_flag == 0) {
                direction_to_target_player();
                if (cond_flag == 0) {
                    heli_muzzle_offset(HELI(reg_a5)->facing);
                    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
                    temp_a0 = ENTITY(reg_a6)->x.h;
                    reg_tmp.h[0] = temp_a0;
                    reg_d0.w = 0xD;
                    reg_d2.w += reg_tmp.w;
                    func_00150730();
                    reg_d3.w = 0;
                    bullet_fire();
                }
            }
        }
        reg_d1.b[0] = HELI(reg_a5)->facing;
        if (g_frame_mod4 != 0) {
            heli_set_direction_sprite();
            return;
        }
        direction_to_target_player();
        reg_d0.b[0] = HELI(reg_a5)->facing;
        direction_turn_toward();
        HELI(reg_a5)->facing = (u8) reg_d1.b[0];
        heli_set_direction_sprite();
    }
}

void enemy_set_entity_count(s32);

void heli_g_first(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257B90[];
extern u16 D_00257BB0[];
extern u16 g_scroll_line;

void heli_g_start(void) {
    s32 enemy_remove();
    heli_remove_on_signal_0();
    if ((cond_flag == 0) && (heli_remove_on_signal_f(), (cond_flag == 0)) && (reg_a0 = (u8 *)D_00257BB0, enemy_init_entities(), reg_a0 = (u8 *)D_00257B90, reg_d0.h[0] = 0xA, enemy_set_task_state(), ENTITY(reg_a6)->attr.b.palette = (u8) HELI(reg_a5)->palette, enemy_path_start(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        HELI(reg_a5)->shadow_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        HELI(reg_a5)->shadow_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        if (ENEMY_STATE(reg_a5)->kind & 0x20) {
            heli_x_limit_check();
        }
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d0.b[0] += 0x20;
        reg_d0.b[0] &= 0x3C;
        HELI(reg_a5)->facing_wanted = (u8) reg_d0.b[0];
        direction_to_target_player();
        if (cond_flag != 0) {
            reg_d1.w = 0x20;
        }
        HELI(reg_a5)->facing = (u8) reg_d1.b[0];
        reg_d0.h[0] = g_rank_2_16;
        reg_d0.b[0] -= 8;
        HELI(reg_a5)->fire.b.countdown -= reg_d0.b[0];
        if (g_stage == 4) {
            if ((s16)g_scroll_line >= 0x290) {
                if (g_enemy_signal_7 != 0) {
                    enemy_remove();
                }
            } else if ((s16)g_scroll_line > 0x1FC) {
                if ((((s16)g_scroll_line < 0x240) || ((s16)g_scroll_line > 0x274)) && (g_enemy_signal_4 != 0)) {
                    enemy_remove();
                    return;
                }
                if ((g_enemy_signal_5 != 0) && ((s16)g_scroll_line > 0x228)) {
                    enemy_remove();
                    return;
                }
                if (g_enemy_signal_6 != 0) {
                    enemy_remove();
                    return;
                }
                if (g_enemy_signal_7 != 0) {
                    enemy_remove();
                }
            }
        }
    }
}

void heli_g(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u8 temp_v1;

    heli_take_hits(8);
    if ((cond_flag == 0) && (func_00171430(), (cond_flag == 0))) {
        reg_d1.b[0] = HELI(reg_a5)->facing;
        if (g_enemies_stopped != 0) {
            heli_set_direction_sprite();
            return;
        }
        entity_velocity();
        if (HELI(reg_a5)->facing_started.b[1] == 0) {
            HELI(reg_a5)->turns_left.b[1] -= 1;
            if (HELI(reg_a5)->turns_left.b[1] == 0) {
                HELI(reg_a5)->turns_left.b[1] = (u8) HELI(reg_a5)->turns_left.b[0];
                entity_in_shot_limits();
                if (cond_flag == 0) {
                    direction_to_target_player();
                    if (cond_flag == 0) {
                        heli_muzzle_offset(HELI(reg_a5)->facing);
                        reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
                        temp_a0 = ENTITY(reg_a6)->x.h;
                        reg_tmp.h[0] = temp_a0;
                        reg_d0.w = 0xD;
                        reg_d2.w += reg_tmp.w;
                        func_00150730();
                        reg_d3.w = 0;
                        bullet_fire();
                    }
                }
            }
            reg_tmp.b[0] = HELI(reg_a5)->facing_timer.b.countdown;
            HELI(reg_a5)->facing_timer.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                HELI(reg_a5)->facing_timer.b.countdown = (u8) HELI(reg_a5)->facing_timer.b.interval;
                ENTITY(reg_a6)->move.b.speed -= 1;
                if (ENTITY(reg_a6)->move.b.speed == 0) {
                    HELI(reg_a5)->facing_started.b[1] = 1U;
                    HELI(reg_a5)->facing_timer.h = 2;
                    HELI(reg_a5)->fire.b.countdown = 1U;
                    reg_d1.b[0] = HELI(reg_a5)->facing;
                    reg_d1.b[0] &= 0x3C;
                    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                    HELI(reg_a5)->turn_countdown = 0x30U;
                    temp_v1 = HELI(reg_a5)->facing_wanted;
                    if (temp_v1 != reg_d1.b[0]) {
                        if ((s32) temp_v1 >= (s32) reg_d1.b[0]) {
                            HELI(reg_a5)->facing_step = 0xFC;
                        } else {
                            HELI(reg_a5)->facing_step = 4;
                        }
                    }
                }
            }
            reg_d1.b[0] = HELI(reg_a5)->facing;
            if (g_frame_mod4 != 0) {
                heli_set_direction_sprite();
                return;
            }
            direction_to_target_player();
            if (cond_flag != 0) {
                heli_set_direction_sprite();
                return;
            }
            reg_d0.b[0] = HELI(reg_a5)->facing;
            direction_turn_toward();
            HELI(reg_a5)->facing = (u8) reg_d1.b[0];
            heli_set_direction_sprite();
            return;
        }
        if (HELI(reg_a5)->facing_started.b[0] != 0) {
            HELI(reg_a5)->fire.b.countdown -= 1;
            if (HELI(reg_a5)->fire.b.countdown == 0) {
                HELI(reg_a5)->fire.b.countdown = (u8) HELI(reg_a5)->fire.b.other;
                HELI(reg_a5)->facing_started.b[0] -= 1;
                entity_in_shot_limits();
                if (cond_flag == 0) {
                    reg_d2.b[0] = HELI(reg_a5)->facing;
                    reg_d1.b[0] = reg_d2.b[0];
                    heli_muzzle_offset(reg_d1.b[0]);
                    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
                    temp_a0_2 = ENTITY(reg_a6)->x.h;
                    reg_tmp.h[0] = temp_a0_2;
                    reg_d0.w = 0xD;
                    reg_d2.w += reg_tmp.w;
                    func_00150730();
                    reg_d3.w = 0;
                    bullet_fire();
                }
            }
            goto block_33;
        }
        if (ENTITY(reg_a6)->move.b.speed != 0x1C) {
            reg_tmp.b[0] = HELI(reg_a5)->facing_timer.b.countdown;
            HELI(reg_a5)->facing_timer.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                HELI(reg_a5)->facing_timer.b.countdown = (u8) HELI(reg_a5)->facing_timer.b.interval;
                ENTITY(reg_a6)->move.b.speed += 1;
            }
        }
        if (HELI(reg_a5)->facing_reached == 0) {
            reg_tmp.b[0] = HELI(reg_a5)->turn_countdown;
            HELI(reg_a5)->turn_countdown -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                HELI(reg_a5)->turn_countdown = (u8) HELI(reg_a5)->turn_interval;
                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d1.b[0] += HELI(reg_a5)->facing_step;
                reg_d1.b[0] &= 0x3C;
                ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                if (HELI(reg_a5)->facing_wanted != reg_d1.b[0]) {
                    heli_set_direction_sprite();
                    return;
                }
                HELI(reg_a5)->facing_reached = 1U;
                goto block_33;
            }
        }
block_33:
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        heli_set_direction_sprite();
    }
}

void heli_h_first(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00257BD0[];
extern u16 D_00257BF0[];
extern u16 g_rank_4_16;

void heli_h_start(void) {
    s32 enemy_remove();
    heli_remove_on_signal_0();
    if ((cond_flag == 0) && (heli_remove_on_signal_f(), (cond_flag == 0)) && (reg_a0 = (u8 *)D_00257BF0, enemy_init_entities(), reg_a0 = (u8 *)D_00257BD0, reg_d0.h[0] = 0xA, enemy_set_task_state(), ENTITY(reg_a6)->attr.b.palette = (u8) HELI(reg_a5)->palette, enemy_path_start(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        HELI(reg_a5)->shadow_sprite[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        HELI(reg_a5)->shadow_sprite[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        direction_to_target_player();
        if (cond_flag != 0) {
            reg_d1.w = 0x20;
        }
        HELI(reg_a5)->facing = (u8) reg_d1.b[0];
        if (ENEMY_STATE(reg_a5)->kind & 0x20) {
            heli_x_limit_check();
        }
        reg_d0.h[0] = g_rank_4_16;
        reg_d0.b[0] -= 8;
        HELI(reg_a5)->fire.b.countdown -= reg_d0.b[0];
        if (g_stage == 4) {
            if (g_enemy_signal_4 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_5 != 0) {
                enemy_remove();
            }
        }
    }
}

void heli_h(void) {
    u16 temp_a0_2;

    heli_take_hits(8);
    if ((cond_flag == 0) && (func_00171430(), (cond_flag == 0))) {
        reg_d1.b[0] = HELI(reg_a5)->facing;
        if (g_enemies_stopped != 0) {
            heli_set_direction_sprite();
            return;
        }
        if (HELI(reg_a5)->facing_reached != 0) {
            entity_velocity();
            goto block_7;
        }
        enemy_path_step();
        if (enemy_move_end_requested == 0) {
block_7:
            if ((s32) ENTITY(reg_a6)->move.b.dir >= 0x40) {
                HELI(reg_a5)->facing_reached = 1U;
                ENTITY(reg_a6)->move.b.dir -= 0x40;
            }
            if ((HELI(reg_a5)->turns_left.h != 0) && (HELI(reg_a5)->facing_reached != 0)) {
                reg_tmp.b[0] = HELI(reg_a5)->turn_countdown;
                HELI(reg_a5)->turn_countdown -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    HELI(reg_a5)->turn_countdown = (u8) HELI(reg_a5)->turn_interval;
                    HELI(reg_a5)->turns_left.h -= 1;
                    entity_turn_to_target_player();
                    if (cond_flag != 0) {
                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                    }
                }
            }
            direction_to_target_player();
            reg_d0.b[0] = HELI(reg_a5)->facing;
            direction_turn_toward();
            HELI(reg_a5)->facing = (u8) reg_d1.b[0];
            reg_tmp.b[0] = HELI(reg_a5)->fire.b.countdown;
            HELI(reg_a5)->fire.b.countdown -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                heli_set_direction_sprite();
                return;
            }
            reg_d0.w = 0x58;
            reg_d0.h[0] -= g_rank_5_16;
            reg_d0.h[0] += 2;
            HELI(reg_a5)->fire.b.countdown = (u8) reg_d0.b[0];
            entity_in_shot_limits();
            if (cond_flag != 0) {
                heli_set_direction_sprite();
                return;
            }
            direction_to_target_player();
            if (cond_flag != 0) {
                heli_set_direction_sprite();
                return;
            }
            heli_muzzle_offset(reg_d1.b[0]);
            reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
            temp_a0_2 = ENTITY(reg_a6)->x.h;
            reg_tmp.h[0] = temp_a0_2;
            reg_d0.w = 0x3000D;
            reg_d2.w += reg_tmp.w;
            func_00150730();
            reg_d3.w = 0;
            bullet_fire();
            heli_set_direction_sprite();
        }
    }
}
