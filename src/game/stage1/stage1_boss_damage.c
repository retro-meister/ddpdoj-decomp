#include "common.h"
#include "entity.h"
#include "stage1_boss.h"

void stage1_boss_body_destroyed(void);
void stage1_boss_right_side_destroyed(void);
void stage1_boss_left_side_destroyed(void);
void stage1_boss_stop(void);
void stage1_boss_time_limit(void);

void stage1_boss_damage_init(void) {

}


s32 boss_phase_start();
s32 boss_phase_running();
s32 item_spawn();
s32 score_add_no_chain();
s32 score_add();
s32 bullet_cancel_on_boss_hit();
extern u8 g_game_mode;
extern s32 g_boss_score;
extern u16 g_damage_blink_counter;

void stage1_boss_damage(void) {
    s32 active_players_mask();
    u32 hp;
    u8 *v1;
    u8 *v2;
    u8 *v3;
    u8 *v4;

    v2 = (u8 *)(reg_a6);
    if ((*(u16 *)((u8 *)(v2) + (0xE6))) == 0) {
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(v2) + (1)));
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            (*(u8 *)((u8 *)(v2) + (1))) &= reg_d0.b[0];
            STAGE1_DAMAGE(reg_a6)->hit_by = (u16) reg_d1.h[0];
            score_add_no_chain();
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            if (reg_d0.b[0] == 0x19) {
                ENTITY(reg_a6)->attr.b.palette = 0x13U;
                ENTITY(reg_a6)[5].attr.b.palette = 0x16U;
            }
            reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
            reg_d0.b[0] ^= 0xC;
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            reg_d0.b[0] = ENTITY(reg_a6)[5].attr.b.palette;
            reg_d0.b[0] ^= 9;
            ENTITY(reg_a6)[5].attr.b.palette = (u8) reg_d0.b[0];
            v1 = (u8 *)(reg_a6);
            reg_d2.w = 0x7FFF;
            reg_d2.h[0] -= ENTITY(reg_a6)->hp.h;
            hp = ENTITY(reg_a6)->hp.h;
            if (STAGE1_DAMAGE(reg_a6)->shielded == 0) {
                reg_tmp.h[1] = STAGE1_BOSS(reg_a5)->body_hp[0];
                reg_tmp.h[0] = STAGE1_BOSS(reg_a5)->body_hp[1];
                if (g_game_mode == 2) {
                    if ((s32) hp > 0x7FFF) {
                        reg_tmp.w += hp - 0x7FFF;
                        if (reg_tmp.w >= 0x16C00) {
                            reg_tmp.w = 0x16C00;
                        }
                    } else {
                        reg_tmp.w -= reg_d2.w;
                    }
                } else {
                    reg_tmp.w -= reg_d2.w;
                }
                STAGE1_BOSS(reg_a5)->body_hp[0] = reg_tmp.h[1];
                STAGE1_BOSS(reg_a5)->body_hp[1] = reg_tmp.h[0];
            }
            reg_d0.h[0] = 0x7FFF;
            ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
        } else {
            (*(u8 *)((u8 *)(v2) + (0x1C))) = 0x13U;
            ENTITY(reg_a6)[5].attr.b.palette = 0x16U;
            v1 = (u8 *)(reg_a5);
            reg_d2.w = 0x6D33;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(v1) + (0x16)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(v1) + (0x18)));
            if (((u32) reg_tmp.w <= (u32) reg_d2.w) && (g_damage_blink_counter == 0)) {
                ENTITY(reg_a6)->attr.b.palette = 0x19U;
                ENTITY(reg_a6)[5].attr.b.palette = 0x19U;
            }
        }
        reg_tmp.h[1] = STAGE1_BOSS(reg_a5)->body_hp[0];
        reg_tmp.h[0] = STAGE1_BOSS(reg_a5)->body_hp[1];
        if ((s32) reg_tmp.w < 0) {
            active_players_mask();
            if (reg_d0.h[0] == 0) {
                reg_tmp.w = 0x200;
                STAGE1_BOSS(reg_a5)->body_hp[0] = (u16) reg_tmp.h[1];
                STAGE1_BOSS(reg_a5)->body_hp[1] = (u16) reg_tmp.h[0];
                goto next_1;
            }
            g_boss_score = 0x30000;
            stage1_boss_body_destroyed();
            return;
        }
next_1:
        if (ENTITY(reg_a6)[1].flags.h != 0x8000) {
            reg_d1.w = 0x5C;
            reg_d1.b[0] &= ENTITY(reg_a6)[1].flags.b[1];
            v3 = (u8 *)(reg_a6 + 0x21);
            if (reg_d1.b[0] != 0) {
                reg_d0.b[0] = 0xA3;
                ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
                STAGE1_DAMAGE(reg_a6)->hit_by = (u16) reg_d1.h[0];
                score_add_no_chain();
                reg_d0.b[0] = ENTITY(reg_a6)[1].attr.b.palette;
                if (reg_d0.b[0] == 0x19) {
                    ENTITY(reg_a6)[1].attr.b.palette = 0x15U;
                }
                reg_d0.b[0] = ENTITY(reg_a6)[1].attr.b.palette;
                reg_d0.b[0] ^= 0xA;
                ENTITY(reg_a6)[1].attr.b.palette = (u8) reg_d0.b[0];
                reg_d2.w = 0x7FFF;
                reg_d2.h[0] -= ENTITY(reg_a6)[1].hp.h;
                hp = ENTITY(reg_a6)[1].hp.h;
                if (STAGE1_DAMAGE(reg_a6)->shielded == 0) {
                    reg_tmp.h[1] = STAGE1_BOSS(reg_a5)->right_hp[0];
                    reg_tmp.h[0] = STAGE1_BOSS(reg_a5)->right_hp[1];
                    if (g_game_mode == 2) {
                        if ((s32) hp > 0x7FFF) {
                            reg_tmp.w += hp - 0x7FFF;
                            if (reg_tmp.w >= 0x9000) {
                                reg_tmp.w = 0x9000;
                            }
                        } else {
                            reg_tmp.w -= reg_d2.w;
                        }
                    } else {
                        reg_tmp.w -= reg_d2.w;
                    }
                    STAGE1_BOSS(reg_a5)->right_hp[0] = reg_tmp.h[1];
                    STAGE1_BOSS(reg_a5)->right_hp[1] = reg_tmp.h[0];
                }
                reg_d0.h[0] = 0x7FFF;
                ENTITY(reg_a6)[1].hp.h = (u16) reg_d0.h[0];
            } else {
                ENTITY(reg_a6)[1].attr.b.palette = 0x15U;
                reg_d2.w = 0x2B33;
                reg_tmp.h[1] = STAGE1_BOSS(reg_a5)->right_hp[0];
                reg_tmp.h[0] = STAGE1_BOSS(reg_a5)->right_hp[1];
                if (((u32) reg_tmp.w <= (u32) reg_d2.w) && (g_damage_blink_counter == 0)) {
                    ENTITY(reg_a6)[1].attr.b.palette = 0x19U;
                }
            }
            if (ENTITY(reg_a6)[3].misc.b.draw_layer == 0) {
                reg_tmp.h[1] = STAGE1_BOSS(reg_a5)->right_hp[0];
                reg_tmp.h[0] = STAGE1_BOSS(reg_a5)->right_hp[1];
                if ((s32) reg_tmp.w < 0) {
                    reg_d1.h[0] = STAGE1_DAMAGE(reg_a6)->hit_by;
                    reg_d0.w = 0x1000;
                    score_add();
                    reg_d0.w = 0xC;
                    if (!(reg_d1.w & 0x10)) {
                        reg_d0.w = 0x14;
                    }
                    reg_a6 += 0x20;
                    item_spawn();
                    reg_tmp.h[1] = ENEMY_STATE(reg_a5)->entities[0];
                    reg_tmp.h[0] = ENEMY_STATE(reg_a5)->entities[1];
                    reg_a6 = (void *) reg_tmp.w;
                    bullet_cancel_on_boss_hit();
                    STAGE1_BOSS(reg_a5)->bullet_clear_time = 0x6E;
                    if (STAGE1_EXTRA(reg_a6)->spinning != 0) {
                        reg_a6 += 0x60;
                        item_spawn();
                        reg_tmp.h[1] = ENEMY_STATE(reg_a5)->entities[0];
                        reg_tmp.h[0] = ENEMY_STATE(reg_a5)->entities[1];
                        reg_a6 = (void *) reg_tmp.w;
                    }
                    goto next_2;
                }
                goto next_3;
            }
next_2:
            stage1_boss_right_side_destroyed();
            return;
        }
next_3:
        if (ENTITY(reg_a6)[3].flags.h != 0x8000) {
            reg_d1.w = 0x5C;
            reg_d1.b[0] &= ENTITY(reg_a6)[3].flags.b[1];
            v4 = (u8 *)(reg_a6 + 0x61);
            if (reg_d1.b[0] != 0) {
                reg_d0.b[0] = 0xA3;
                ENTITY(reg_a6)[3].flags.b[1] &= reg_d0.b[0];
                STAGE1_DAMAGE(reg_a6)->hit_by = (u16) reg_d1.h[0];
                score_add_no_chain();
                reg_d0.b[0] = ENTITY(reg_a6)[3].attr.b.palette;
                if (reg_d0.b[0] == 0x19) {
                    ENTITY(reg_a6)[3].attr.b.palette = 0x15U;
                }
                reg_d0.b[0] = ENTITY(reg_a6)[3].attr.b.palette;
                reg_d0.b[0] ^= 0xA;
                ENTITY(reg_a6)[3].attr.b.palette = (u8) reg_d0.b[0];
                reg_d2.w = 0x7FFF;
                reg_d2.h[0] -= ENTITY(reg_a6)[3].hp.h;
                hp = ENTITY(reg_a6)[3].hp.h;
                if (STAGE1_DAMAGE(reg_a6)->shielded == 0) {
                    reg_tmp.h[1] = STAGE1_BOSS(reg_a5)->left_hp[0];
                    reg_tmp.h[0] = STAGE1_BOSS(reg_a5)->left_hp[1];
                    if (g_game_mode == 2) {
                        if ((s32) hp > 0x7FFF) {
                            reg_tmp.w += hp - 0x7FFF;
                            if (reg_tmp.w >= 0x9000) {
                                reg_tmp.w = 0x9000;
                            }
                        } else {
                            reg_tmp.w -= reg_d2.w;
                        }
                    } else {
                        reg_tmp.w -= reg_d2.w;
                    }
                    STAGE1_BOSS(reg_a5)->left_hp[0] = reg_tmp.h[1];
                    STAGE1_BOSS(reg_a5)->left_hp[1] = reg_tmp.h[0];
                }
                reg_d0.h[0] = 0x7FFF;
                ENTITY(reg_a6)[3].hp.h = (u16) reg_d0.h[0];
            } else {
                ENTITY(reg_a6)[3].attr.b.palette = 0x15U;
                reg_d2.w = 0x2B33;
                reg_tmp.h[1] = STAGE1_BOSS(reg_a5)->left_hp[0];
                reg_tmp.h[0] = STAGE1_BOSS(reg_a5)->left_hp[1];
                if (((u32) reg_tmp.w <= (u32) reg_d2.w) && (g_damage_blink_counter == 0)) {
                    ENTITY(reg_a6)[3].attr.b.palette = 0x19U;
                }
            }
            if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
                reg_tmp.h[1] = STAGE1_BOSS(reg_a5)->left_hp[0];
                reg_tmp.h[0] = STAGE1_BOSS(reg_a5)->left_hp[1];
                if ((s32) reg_tmp.w < 0) {
                    reg_d1.h[0] = STAGE1_DAMAGE(reg_a6)->hit_by;
                    reg_d0.w = 0x1000;
                    score_add();
                    reg_d0.w = 0xC;
                    if (!(reg_d1.w & 0x10)) {
                        reg_d0.w = 0x14;
                    }
                    reg_a6 += 0x60;
                    item_spawn();
                    reg_tmp.h[1] = ENEMY_STATE(reg_a5)->entities[0];
                    reg_tmp.h[0] = ENEMY_STATE(reg_a5)->entities[1];
                    reg_a6 = (void *) reg_tmp.w;
                    bullet_cancel_on_boss_hit();
                    STAGE1_BOSS(reg_a5)->bullet_clear_time = 0x6E;
                    if (STAGE1_EXTRA(reg_a6)->spinning != 0) {
                        reg_a6 += 0x20;
                        item_spawn();
                        reg_tmp.h[1] = ENEMY_STATE(reg_a5)->entities[0];
                        reg_tmp.h[0] = ENEMY_STATE(reg_a5)->entities[1];
                        reg_a6 = (void *) reg_tmp.w;
                    }
                    goto next_4;
                }
                goto next_5;
            }
next_4:
            stage1_boss_left_side_destroyed();
            return;
        }
next_5:
        reg_d0.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
        reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
        if (reg_d0.b[0] == 2) {
            reg_d0.w = 5;
            boss_phase_running();
            if (cond_flag == 0) {
                reg_d0.w = 5;
                boss_phase_start();
            }
        }
        if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
            reg_d0.w = 4;
            boss_phase_running();
            if (cond_flag == 0) {
                reg_d0.w = 4;
                boss_phase_start();
            }
        }
        if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
            reg_d0.w = 4;
            boss_phase_running();
            if (cond_flag == 0) {
                reg_d0.w = 4;
                boss_phase_start();
            }
        }
        stage1_boss_time_limit();
    }
}

s32 boss_phase_stop_all();
s32 boss_movement_start();
s32 boss_animation_start();
s32 boss_attack_stop_all();
s32 boss_kill_counter_clamp();
s32 boss_defeat_begin();
s32 slowdown_turn_off();
extern u8 g_boss_present_b1;

void stage1_boss_body_destroyed() {
    g_boss_present_b1 |= 0x40;
    g_boss_present_b1 |= 0x80;
    slowdown_turn_off();
    boss_kill_counter_clamp();
    boss_defeat_begin();
    stage1_boss_stop();
    stage1_boss_right_side_destroyed();
    stage1_boss_left_side_destroyed();
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_tmp.w = -1U;
    STAGE1_BOSS(reg_a5)->body_hp[0] = (u16) reg_tmp.h[1];
    STAGE1_BOSS(reg_a5)->body_hp[1] = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->misc.sb.draw_layer = 1;
    ENTITY(reg_a6)->flags.h = 0x8000;
    ENTITY(reg_a6)->attr.sb.palette = 0x13;
    ENTITY(reg_a6)[5].attr.sb.palette = 0x16;
    reg_d0.w = 1;
    boss_movement_start();
    reg_d0.w = 6;
    boss_animation_start();
}

s32 boss_animation_stop();

void stage1_boss_right_side_destroyed(void) {
    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        reg_tmp.w = -1U;
        STAGE1_BOSS(reg_a5)->right_hp[0] = (u16) reg_tmp.h[1];
        STAGE1_BOSS(reg_a5)->right_hp[1] = (u16) reg_tmp.h[0];
        ENTITY(reg_a6)[1].misc.b.draw_layer = 1U;
        ENTITY(reg_a6)[1].flags.h = 0x8000;
        ENTITY(reg_a6)[1].attr.sb.palette = 0x15;
        reg_d0.w = 0;
        boss_animation_stop();
        reg_d0.w = 2;
        boss_animation_stop();
        reg_d0.w = 8;
        boss_animation_stop();
        reg_d0.w = 0xA;
        boss_animation_stop();
        reg_d0.w = 0xC;
        boss_animation_stop();
        reg_d0.w = 4;
        boss_animation_start();
        return;
    }
}

void stage1_boss_left_side_destroyed(void) {
    if (ENTITY(reg_a6)[3].misc.b.draw_layer == 0) {
        reg_tmp.w = -1U;
        STAGE1_BOSS(reg_a5)->left_hp[0] = (u16) reg_tmp.h[1];
        STAGE1_BOSS(reg_a5)->left_hp[1] = (u16) reg_tmp.h[0];
        ENTITY(reg_a6)[3].misc.b.draw_layer = 1U;
        ENTITY(reg_a6)[3].flags.h = 0x8000;
        ENTITY(reg_a6)[3].attr.sb.palette = 0x15;
        reg_d0.w = 1;
        boss_animation_stop();
        reg_d0.w = 3;
        boss_animation_stop();
        reg_d0.w = 9;
        boss_animation_stop();
        reg_d0.w = 0xB;
        boss_animation_stop();
        reg_d0.w = 0xD;
        boss_animation_stop();
        reg_d0.w = 5;
        boss_animation_start();
        return;
    }
}

void stage1_boss_shield_on(void) {
    STAGE1_DAMAGE(reg_a6)->shielded = 1;
}

void stage1_boss_shield_off(void) {
    STAGE1_DAMAGE(reg_a6)->shielded = 0;
}

void stage1_boss_parts_enable(void) {
    reg_d0.h[0] = 0xA001;
    ENTITY(reg_a6)->flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[1].flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[3].flags.h |= reg_d0.h[0];
}


void stage1_boss_parts_disable(void) {
    reg_d0.h[0] = 0x8000;
    ((u16 *)reg_a6)[0x0 / 2] = (u16) reg_d0.h[0];
    ((u16 *)reg_a6)[0x20 / 2] = (u16) reg_d0.h[0];
    ((u16 *)reg_a6)[0x60 / 2] = (u16) reg_d0.h[0];
}

void stage1_boss_stop(void) {
    STAGE1_DAMAGE(reg_a6)->stopped = 1;
}

extern u16 g_enemies_stopped;

void stage1_boss_time_limit(void) {
    void active_players_mask(void);
#ifdef DEATH_LABEL
    if ((g_enemies_stopped == 0) && (STAGE1_BOSS(reg_a5)->time_left == 0)) {
#else
    if ((g_enemies_stopped == 0) && (STAGE1_BOSS(reg_a5)->time_left -= 1, STAGE1_BOSS(reg_a5)->time_left == 0)) {
#endif
        active_players_mask();
        if (reg_d0.h[0] == 0) {
            STAGE1_BOSS(reg_a5)->time_left = 0x78U;
            return;
        }
        STAGE1_DAMAGE(reg_a6)->hit_by = 0;
        stage1_boss_body_destroyed();
    }
}
