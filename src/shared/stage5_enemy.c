#include "common.h"
#include "entity.h"

void func_001F7100(void);
void func_001F71A0(void);

s32 boss_phase_start();
s32 boss_phase_stop_all();
s32 boss_part_hide();
s32 boss_attack_stop_all();
s32 func_0013F3C0();
s32 func_001F57D0();
s32 func_002016D0();
s32 func_00203460();
s32 slowdown_turn_off();
extern u8 g_boss_present_b1;

void func_001F6080() {
    g_boss_present_b1 |= 0x40;
    g_boss_present_b1 |= 0x80;
    slowdown_turn_off();
    func_0013F3C0();
    func_00203460();
    func_002016D0();
    func_001F57D0();
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_tmp.w = -1U;
    *(u16 *)(reg_a5 + 0x16) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x18) = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)[10].misc.sb.draw_layer = 1;
    ENTITY(reg_a6)[12].flags.h = 0x8000;
#ifdef DEATH_LABEL
    ENTITY(reg_a6)[16].flags.h = 0x8000;
#endif
    ENTITY(reg_a6)[7].sprite.sb[0] = 0x17;
    reg_d0.w = 0x12;
    boss_part_hide();
    reg_d0.w = 5;
    boss_phase_start();
}

void active_players_mask(void);
extern u16 g_enemies_stopped;

void func_001F6140(void) {
    #ifdef DEATH_LABEL
    if ((g_enemies_stopped == 0) && (*(u16 *)(reg_a5 + 0x1A) == 0)) {
#else
    if ((g_enemies_stopped == 0) && (*(u16 *)(reg_a5 + 0x1A) -= 1, *(u16 *)(reg_a5 + 0x1A) == 0)) {
#endif
        active_players_mask();
        if (reg_d0.h[0] == 0) {
            *(u16 *)(reg_a5 + 0x1A) = 0x78U;
            return;
        }
        ENTITY(reg_a6)[8].draw.sh = 0;
        func_001F6080();
    }
}

s32 explosion_spawn();

void func_001F61B0(arg2)
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
        *(s16 *)(reg_a0 + 0x1E) = 4;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(u16 *)(reg_a0 + 0x1A) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        goto loop_1;
    }
}


void stage5_small_turret_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 D_00265110[];
extern u8 D_00265130[];
extern s16 D_00299768[];
extern s8 enemy_move_end_requested;

void stage5_small_turret_start(void)
{
    extern void enemy_set_task_work(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
    reg_a0 = D_00265130;
    enemy_init_entities();

    reg_a0 = D_00265110;
    reg_d0.w = 8;
    enemy_set_task_work();
    enemy_path_start();

    if (enemy_move_end_requested == 0) {
        ENTITY(reg_a6)->attr.b.palette = reg_a5[0x19];
        D_00299768[0] = 1;
    }
}


s32 func_00125EC0();
s32 bullet_fire_fast();
s32 enemy_remove();
s32 sfx_explosion_air_small();
s32 score_add_no_chain();
s32 score_add();
s32 entity_follow_scroll();
s32 func_00202180();
extern u8 D_00265150[];

void stage5_small_turret(void) {
    s32 enemy_hitbox_debug_draw();
    s32 sprite_draw_layer1();
    u16 temp_a0;
    u16 temp_a1;

    if (ENTITY(reg_a6)->y.sh < -0x7FF) {
        enemy_remove();
        return;
    }
    entity_follow_scroll();
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
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x34;
            score_add();
            reg_d0.h[0] = 0x88;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a1;
            *(s16 *)(reg_a0 + 0x1E) = 4;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(s16 *)(reg_a0 + 0x10) = 2;
            sfx_explosion_air_small();
            reg_d1.w = 0;
            reg_d0.w = 8;
            reg_d2.w = 1;
            func_00125EC0();
            enemy_remove();
            return;
        }
        goto block_6;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
block_6:
    if (*(u8 *)(reg_a5 + 0x16) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
        *(u8 *)(reg_a5 + 0x1B) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
            *(u8 *)(reg_a5 + 0x16) = 1U;
        }
    }
    if (*(u8 *)(reg_a5 + 0x16) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
        *(u8 *)(reg_a5 + 0x1D) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
            *(u16 *)(reg_a5 + 0x1E) += 4;
            if ((s16) *(u16 *)(reg_a5 + 0x1E) >= 0x1C) {
                *(u16 *)(reg_a5 + 0x1E) = 0x1CU;
                func_00202180();
                if (cond_flag == 0) {
                    reg_d1.b[0] += 2;
                    reg_d1.h[0] &= 0x3C;
                    *(u8 *)(reg_a5 + 0x27) = (u8) reg_d1.b[0];
                    *(u8 *)(reg_a5 + 0x16) = 2U;
                    *(s16 *)(reg_a5 + 0x20) = 0x808;
                    *(s16 *)(reg_a5 + 0x22) = 3;
                    *(s16 *)(reg_a5 + 0x24) = 3;
                }
            }
        }
    }
    if (*(u8 *)(reg_a5 + 0x16) == 2) {
        if (ENTITY(reg_a6)->y.sh < 0x1400) {
            *(u8 *)(reg_a5 + 0x16) = 3U;
        }
        if (*(u8 *)(reg_a5 + 0x25) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
            *(u8 *)(reg_a5 + 0x21) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x21) = *(u8 *)(reg_a5 + 0x20);
                *(u8 *)(reg_a5 + 0x25) = *(u8 *)(reg_a5 + 0x24);
                goto block_20;
            }
        } else {
block_20:
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
            *(u8 *)(reg_a5 + 0x23) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x22);
                reg_d0.w = 0xFFFE0006;
                reg_d1.w = 0;
                reg_d1.b[0] = *(u8 *)(reg_a5 + 0x27);
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d4.w = 0;
                reg_d3.w = 0;
                bullet_fire_fast();
                *(u8 *)(reg_a5 + 0x25) -= 1;
                if (*(u8 *)(reg_a5 + 0x25) == 0) {
                    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x27);
                    func_00202180();
                    *(u8 *)(reg_a5 + 0x27) = (u8) reg_d1.b[0];
                }
            }
        }
    }
    if (*(u8 *)(reg_a5 + 0x16) == 3) {
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
        *(u8 *)(reg_a5 + 0x1D) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
            *(u16 *)(reg_a5 + 0x1E) -= 4;
            if (0 >= (s16) *(u16 *)(reg_a5 + 0x1E)) {
                *(u16 *)(reg_a5 + 0x1E) = 0U;
                *(u8 *)(reg_a5 + 0x16) = 4U;
            }
        }
    }
    reg_a0 = (u8 *)D_00265150;
    reg_a0 += *(u16 *)(reg_a5 + 0x1E);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xFC00FC00;
    reg_d3.h[0] = 0x420;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer1();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

void stage5_bee_hatch_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern u8 D_00265170[];
extern u8 D_00265180[];
extern u16 g_scroll_line;

void stage5_bee_hatch_start(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = D_00265180;
    enemy_init_entities();
    reg_a0 = D_00265170;
    reg_d0.w = 6;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        *(u16 *)(reg_a5 + 0x22) = (u16) g_scroll_line;
        if (g_scroll_line == 0xE6) {
            *(s8 *)(reg_a5 + 0x19) = 0x60;
        }
        if (g_scroll_line == 0xE4) {
            *(u8 *)(reg_a5 + 0x19) = 0xF0;
        }
        if (g_scroll_line == 0x108) {
            *(s8 *)(reg_a5 + 0x19) = 0x40;
        }
        if (g_scroll_line == 0x106) {
            *(u8 *)(reg_a5 + 0x19) = 0xF0;
        }
        if (g_scroll_line == 0x116) {
            *(u8 *)(reg_a5 + 0x19) = 0x80;
        }
    }
}

s32 spawn_request_add();
s32 rng_next_unsigned();
extern u8 D_002651A0[];

void stage5_bee_hatch(void) {
    s32 sprite_draw_layer1();
    s16 temp_v0;
    s16 temp_v0_2;
    u16 temp_a0;

    reg_d0.w = 0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x2001) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            return;
        }
        goto block_4;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_4:
    entity_follow_scroll();
    if (g_enemies_stopped == 0) {
        if ((*(u8 *)(reg_a5 + 0x16) == 0) && (*(u8 *)(reg_a5 + 0x17) != 0)) {
            temp_v0 = (s16) ENTITY(reg_a6)->y.h;
            if ((temp_v0 < 0x7000) && (temp_v0 > 0x5000)) {
                temp_v0_2 = ENTITY(reg_a6)->x.sh;
                if ((0 < temp_v0_2) && (temp_v0_2 < 0x3800)) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
                    *(u8 *)(reg_a5 + 0x19) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        rng_next_unsigned();
                        reg_d0.h[0] &= 0x3F;
                        reg_d0.h[0] += 0x20;
                        *(u8 *)(reg_a5 + 0x19) = (u8) reg_d0.b[0];
                        *(u8 *)(reg_a5 + 0x16) = 1U;
                    }
                }
            }
        }
        if ((*(u8 *)(reg_a5 + 0x16) == 1) && ((*(u16 *)(reg_a5 + 0x1C) != 0) || ((s16) ENTITY(reg_a6)->y.h > 0x3C00))) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
            *(u8 *)(reg_a5 + 0x1B) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
                *(u16 *)(reg_a5 + 0x1C) += 4;
                if ((s16) *(u16 *)(reg_a5 + 0x1C) >= 0x1C) {
                    *(u16 *)(reg_a5 + 0x1C) = 0x1CU;
                    *(u8 *)(reg_a5 + 0x16) = 2U;
                    *(s16 *)(reg_a5 + 0x1E) = 0x28;
                    rng_next_unsigned();
                    reg_d0.h[0] &= 3;
                    reg_d0.h[0] += 2;
                    *(u16 *)(reg_a5 + 0x20) = (u16) reg_d0.h[0];
                }
            }
        }
        if (*(u8 *)(reg_a5 + 0x16) == 2) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
            *(u8 *)(reg_a5 + 0x1F) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x1E);
                reg_d0.w = 0x55;
                spawn_request_add();
                *(u16 *)(reg_a0 + 0x16) = (u16) ENTITY(reg_a6)->y.h;
                *(u16 *)(reg_a0 + 0x18) = ENTITY(reg_a6)->x.h;
                reg_tmp.w = (u32) reg_a5;
                *(u16 *)(reg_a0 + 0x1A) = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a0 + 0x1C) = (u16) reg_tmp.h[0];
                *(u8 *)(reg_a5 + 0x16) = 4U;
                *(u8 *)(reg_a5 + 0x1B) = 0x40U;
            }
        }
        if (*(u8 *)(reg_a5 + 0x16) == 3) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
            *(u8 *)(reg_a5 + 0x1B) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
                *(u16 *)(reg_a5 + 0x1C) -= 4;
                if (0 >= (s16) *(u16 *)(reg_a5 + 0x1C)) {
                    *(u16 *)(reg_a5 + 0x1C) = 0U;
                    *(u8 *)(reg_a5 + 0x16) = 4U;
                }
            }
        }
    }
    reg_a0 = (u8 *)D_002651A0;
    reg_a0 += *(u16 *)(reg_a5 + 0x1C);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xF000F000;
    reg_d3.h[0] = 0x1080;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer1();
}

void stage5_small_spider_turret_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(1);
}

extern u8 D_002651C0[];
extern u8 D_002651E0[];
extern s16 D_0029976A[];

void stage5_small_spider_turret_start(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = D_002651E0;
    enemy_init_entities();
    reg_a0 = D_002651C0;
    reg_d0.w = 8;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_scroll_line == 0x201) {
            ENTITY(reg_a6)->attr.sb.flip = 0x40;
            *(s8 *)(reg_a5 + 0x16) = 1;
        }
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
        rng_next_unsigned();
        *(u8 *)(reg_a5 + 0x21) = (u8) reg_d0.b[0];
        rng_next_unsigned();
        *(u8 *)(reg_a5 + 0x20) = (u8) reg_d0.b[0];
    }
}

s32 bullet_fire256_double();
s32 sfx_explosion_ground_large();
s32 aim256_at_player();
extern u8 D_00265240[];
extern u8 D_0028DA18;
extern u8 D_0028DA1C;

void stage5_small_spider_turret(void) {
    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        if (ENTITY(reg_a6)->y.sh > 0x2800) {
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
                if (ENTITY(reg_a6)->hp.sh < 0) {
                    reg_d0.w = 0x230;
                    score_add();
                    goto block_5;
                }
            } else {
                goto block_6;
            }
        } else {
block_5:
            ENTITY(reg_a6)->flags.h = 0x8000;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)D_00265240;
            func_001F61B0();
            sfx_explosion_ground_large();
            ENTITY(reg_a6)[1].misc.b.draw_layer = 1U;
            goto block_6;
        }
    } else {
block_6:
        ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
    }
    reg_d0.w = 0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x2C01) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            return;
        }
        goto block_11;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_11:
    entity_follow_scroll();
    func_001F71A0();
    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        if (*(u8 *)(reg_a5 + 0x25) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
            *(u8 *)(reg_a5 + 0x1F) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
                goto block_15;
            }
        } else {
block_15:
            reg_a1 = &D_0028DA18;
            if (*(u8 *)(reg_a5 + 0x16) == 0) {
                reg_a1 = &D_0028DA1C;
            }
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d0.h[0] += *(u16 *)reg_a1;
            reg_d1.h[0] += *(u16 *)(reg_a1 + 2);
            aim256_at_player();
            if (cond_flag == 0) {
                *(u8 *)(reg_a5 + 0x21) = (u8) reg_d1.b[0];
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x27);
                *(u8 *)(reg_a5 + 0x27) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x27) = (u8) *(u8 *)(reg_a5 + 0x26);
                    reg_d1.w = 0;
                    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x21);
                    reg_d0.w = 0xFFFE000B;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_a1 = &D_0028DA18;
                    if (*(u8 *)(reg_a5 + 0x16) == 0) {
                        reg_a1 = &D_0028DA1C;
                    }
                    reg_tmp.h[1] = *(u16 *)reg_a1;
                    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                    reg_d2.w += reg_tmp.w;
                    reg_d1.h[0] -= 0xA;
                    reg_d7.h[0] = 4;
                    reg_d4.w = 0;
                    reg_d3.w = 0;
                    do {
                        bullet_fire256_double();
                        reg_d1.b[0] += 5;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x23);
                    *(u8 *)(reg_a5 + 0x21) += reg_d0.b[0];
                    *(u8 *)(reg_a5 + 0x25) -= 1;
                }
            }
        }
    }
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
    *(u8 *)(reg_a5 + 0x1B) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
        *(u16 *)(reg_a5 + 0x1C) += 4;
        *(u16 *)(reg_a5 + 0x1C) &= 0x1F;
    }
    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        func_001F7100();
    }
}

extern u8 D_00265220[];

void func_001F7100(void) {
    void enemy_hitbox_debug_draw();
    void sprite_draw_layer1();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = D_00265220;
    reg_a0 += *(u16 *)(reg_a5 + 0x1C);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xF600F600;
    reg_d4.w = 0;
    reg_d3.h[0] = 0xA50;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer1();
}

void func_001F71A0(void) {
}

void stage5_small_spider_head_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern s16 D_00265280[];
extern s16 D_00265290[];
extern s16 g_enemy_signal_6_as_s16;
extern s16 g_enemy_signal_4_as_s16;

void stage5_small_spider_head_start(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_00265290);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_00265280);
    reg_d0.w = 6;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested != 0) return;
    if (g_scroll_line != 0x1F3) goto next_1;
    ENTITY(reg_a6)->attr.sb.flip = 0x40;
    *(s8 *)(reg_a5 + 0x16) = 1;
next_1:
    ENTITY(reg_a6)->attr.b.palette = *(u8 *)(reg_a5 + 0x19);
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    reg_a0 = (u8 *)(&g_enemy_signal_4_as_s16);
    if ((s32) g_scroll_line < 0x260) goto next_2;
    reg_a0 = (u8 *)(&g_enemy_signal_6_as_s16);
next_2:
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x20) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x22) = reg_tmp.h[0];
    *(s16 *)reg_a0 = 1;
}

s32 bullet_fire256_fixed();
s32 bullet_fire256_2way();
extern u8 D_002652B0[];
extern u8 D_00265330[];
extern u8 D_002653B0[];
extern u8 D_00265430[];
extern u8 D_002654B0[];
extern u16 g_bullets_blocked;

void stage5_small_spider_head(void) {
    s32 enemy_hitbox_debug_draw();
    s32 sprite_draw_layer1();
    u16 temp_a0;
    u16 temp_v1;
    u32 temp_v0;
    u8 *var_a0;

    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    var_a0 = (u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        var_a0 = (u8 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x350;
            score_add();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)D_002654B0;
            func_001F61B0();
            sfx_explosion_ground_large();
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
            reg_a0 = (u8 *)reg_tmp.w;
            *(u16 *)reg_a0 = 0U;
            enemy_remove();
            return;
        }
        goto block_4;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
block_4:
    reg_d0.w = 0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x2001) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x20);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x22);
            reg_a0 = (u8 *)reg_tmp.w;
            *(u16 *)reg_a0 = 0U;
            enemy_remove();
            return;
        }
        goto block_8;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_8:
    entity_follow_scroll();
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
    *(u8 *)(reg_a5 + 0x1B) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
        if (g_bullets_blocked == 0) {
            reg_a1 = (u8 *)D_00265430;
            if (*(u8 *)(reg_a5 + 0x16) != 0) {
                reg_a1 = (u8 *)D_002653B0;
            }
            reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1C);
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
            reg_a1 += reg_d0.h[0];
            temp_v1 = *(u16 *)reg_a1;
            reg_a1 = (u8 *)D_00265330;
            reg_d1.h[0] = temp_v1;
            reg_a1 += *(u16 *)(reg_a5 + 0x1C);
            reg_d3.h[1] = *(u16 *)reg_a1;
            reg_d3.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            if (*(u8 *)(reg_a5 + 0x16) != 0) {
                reg_d3.h[0] *= 0xFFFF;
            }
            reg_d0.w = 4;
            reg_d4.w = 0;
            temp_v0 = reg_d2.w + reg_d3.w;
            reg_d3.w = 0;
            reg_d2.w = temp_v0;
            bullet_fire256_fixed();
            reg_d0.w = 0xFFFC0005;
            bullet_fire256_2way();
            if ((s32) g_scroll_line >= 0x268) {
                reg_d0.w = 0x40003;
                bullet_fire256_double();
            }
        }
        *(u16 *)(reg_a5 + 0x1C) += 4;
        if ((s16) *(u16 *)(reg_a5 + 0x1C) >= 0x78) {
            *(u16 *)(reg_a5 + 0x1C) = 0U;
        }
    }
    reg_a0 = (unsigned char *)reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = (unsigned char *)D_002652B0;
    reg_a0 += *(u16 *)(reg_a5 + 0x1C);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d4.w = 0;
    reg_d1.w += 0xF000F600;
    reg_d3.h[0] = 0x1050;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer1();
}

void stage5_large_spider_turret_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(1);
}

extern u8 D_002654F0[];
extern u8 D_00265510[];

void stage5_large_spider_turret_start(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = D_00265510;
    enemy_init_entities();
    reg_a0 = D_002654F0;
    reg_d0.w = 8;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_scroll_line == 0x2B6) {
            ENTITY(reg_a6)->attr.sb.flip = 0x40;
            *(s8 *)(reg_a5 + 0x16) = 1;
        }
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
        rng_next_unsigned();
        *(u8 *)(reg_a5 + 0x21) = (u8) reg_d0.b[0];
        rng_next_unsigned();
        *(u8 *)(reg_a5 + 0x20) = (u8) reg_d0.b[0];
    }
}

extern u8 D_00265550[];
extern u8 D_00265570[];
extern u8 D_0028DA20;
extern u8 D_0028DA24;

void stage5_large_spider_turret(void) {
    s32 enemy_hitbox_debug_draw();
    s32 sprite_draw_layer1();
    u32 temp_a0_3;
    u8 var_a0;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        if (ENTITY(reg_a6)->y.sh < 0x2801) {
            if (*(u8 *)(reg_a5 + 0x17) == 0) {
                goto block_4;
            }
            goto block_7;
        }
block_4:
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
            if (ENTITY(reg_a6)->hp.sh < 0) {
                reg_d0.w = 0x280;
                score_add();
block_7:
                ENTITY(reg_a6)->flags.h = 0x8000;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_a1 = (u8 *)D_00265570;
                func_001F61B0();
                sfx_explosion_ground_large();
                ENTITY(reg_a6)[1].misc.b.draw_layer = 1U;
                goto block_8;
            }
        } else {
            goto block_8;
        }
    } else {
block_8:
        var_a0 = *(u8 *)(reg_a5 + 0x19);
        ENTITY(reg_a6)->attr.b.palette = var_a0;
    }
    reg_d0.w = 0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x1C01) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            return;
        }
        goto block_13;
    }
    var_a0 = 1;
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_13:
    if (g_enemies_stopped == 0) {
        entity_follow_scroll();
        func_001F71A0();
        if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
            if (*(u8 *)(reg_a5 + 0x25) == 0) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                *(u8 *)(reg_a5 + 0x1F) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                    *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
                    goto block_18;
                }
            } else {
block_18:
                reg_a1 = &D_0028DA20;
                if (*(u8 *)(reg_a5 + 0x16) == 0) {
                    reg_a1 = &D_0028DA24;
                }
                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += *(u16 *)reg_a1;
                reg_d1.h[0] += *(u16 *)(reg_a1 + 2);
                aim256_at_player();
                *(u8 *)(reg_a5 + 0x21) = (u8) reg_d1.b[0];
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x27);
                *(u8 *)(reg_a5 + 0x27) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x27) = (u8) *(u8 *)(reg_a5 + 0x26);
                    reg_d1.w = 0;
                    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x21);
                    reg_d0.w = 0xFFFF000B;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_a1 = &D_0028DA20;
                    if (*(u8 *)(reg_a5 + 0x16) == 0) {
                        reg_a1 = &D_0028DA24;
                    }
                    reg_tmp.h[1] = *(u16 *)reg_a1;
                    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                    reg_d2.w += reg_tmp.w;
                    reg_d1.h[0] -= 9;
                    reg_d7.h[0] = 6;
                    reg_d4.w = 0;
                    reg_d3.w = 0;
                    do {
                        bullet_fire256_2way();
                        reg_d1.b[0] += 3;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x23);
                    *(u8 *)(reg_a5 + 0x21) += reg_d0.b[0];
                    *(u8 *)(reg_a5 + 0x25) -= 1;
                }
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
        *(u8 *)(reg_a5 + 0x1B) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
            *(u16 *)(reg_a5 + 0x1C) += 4;
            *(u16 *)(reg_a5 + 0x1C) &= 0x1F;
        }
    }
    if (ENTITY(reg_a6)[1].misc.b.draw_layer == 0) {
        reg_a0 = (u8 *)D_00265550;
        reg_a0 += *(u16 *)(reg_a5 + 0x1C);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        temp_a0_3 = ENTITY(reg_a6)->x.h;
        reg_d1.h[0] = temp_a0_3;
        reg_d1.w += 0xEE00EC00;
        reg_d3.h[0] = 0x12A0;
        reg_d4.w = 0;
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        sprite_draw_layer1();
        reg_a0 = reg_a6;
        enemy_hitbox_debug_draw();
    }
}

void stage5_large_spider_head_first(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(0);
}

extern s16 D_002655E0[];
extern s16 D_00265600[];
extern s16 g_enemy_signal_7_as_s16;
extern s16 g_enemy_signal_5_as_s16;

void stage5_large_spider_head_start(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_00265600);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_002655E0);
    reg_d0.w = 9;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested != 0) return;
    if (g_scroll_line != 0x299) goto next_1;
    ENTITY(reg_a6)->attr.sb.flip = 0x40;
    *(s8 *)(reg_a5 + 0x16) = 1;
next_1:
    ENTITY(reg_a6)->attr.b.palette = *(u8 *)(reg_a5 + 0x19);
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    g_enemy_signal_5_as_s16 = 1;
    reg_a0 = (u8 *)(&g_enemy_signal_5_as_s16);
    if ((s32) g_scroll_line < 0x280) goto next_2;
    reg_a0 = (u8 *)(&g_enemy_signal_7_as_s16);
    *(s16 *)(reg_a5 + 0x1A) = 0x202;
next_2:
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x26) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x28) = reg_tmp.h[0];
    *(s16 *)reg_a0 = 1;
}

extern u8 D_00265620[];
extern u8 D_002656A0[];
extern u8 D_002656F0[];
extern u8 D_00265770[];
extern u8 D_002657B0[];

void stage5_large_spider_head(void) {
    s32 enemy_hitbox_debug_draw();
    s32 sprite_draw_layer1();
    u8 *temp_a1;
    s16 temp_a2;
    u16 temp_a0;
    u8 *var_a0;

    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    var_a0 = (u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        var_a0 = (u8 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x390;
            score_add();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)D_002656A0;
            func_001F61B0();
            sfx_explosion_ground_large();
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x26);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x28);
            reg_a0 = (u8 *)reg_tmp.w;
            *(u16 *)reg_a0 = 0U;
            enemy_remove();
            return;
        }
        goto block_4;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
block_4:
    reg_d0.w = 0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x401) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x26);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x28);
            reg_a0 = (u8 *)reg_tmp.w;
            *(u16 *)reg_a0 = 0U;
            enemy_remove();
            return;
        }
        goto block_8;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_8:
    if (g_enemies_stopped == 0) {
        entity_follow_scroll();
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
        *(u8 *)(reg_a5 + 0x1B) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
            *(u16 *)(reg_a5 + 0x1C) += 4;
            if ((s16) *(u16 *)(reg_a5 + 0x1C) >= 0x78) {
                *(u16 *)(reg_a5 + 0x1C) = 0U;
            }
            reg_a1 = (u8 *)D_002656F0;
            reg_a1 += *(u16 *)(reg_a5 + 0x1C);
            reg_d3.h[1] = *(u16 *)reg_a1;
            reg_d3.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)D_00265770;
            if (*(u8 *)(reg_a5 + 0x16) != 0) {
                reg_a1 = (u8 *)D_002657B0;
                reg_d3.h[0] *= 0xFFFF;
            }
            temp_a1 = (u8 *)(reg_a1);
            reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1C);
            temp_a2 = (s16) reg_d0.h[0];
            reg_d0.h[0] = (u16) (temp_a2 >> 1);
            reg_a1 = temp_a1 + reg_d0.h[0];
            temp_a0 = *(u16 *)reg_a1;
            reg_d1.h[0] = temp_a0;
            reg_d2.w += reg_d3.w;
            reg_d0.w = 0x10003;
            reg_d4.w = 0;
            reg_d3.w = 0;
            bullet_fire256_double();
            reg_d0.w = 0xFFFD0004;
            reg_d1.h[0] += 2;
            bullet_fire256_fixed();
            reg_d1.h[0] -= 4;
            bullet_fire256_fixed();
            reg_d1.h[0] += 3;
            reg_d0.w = 0xFFF90005;
            bullet_fire256_fixed();
            *(u8 *)(reg_a5 + 0x24) += 1;
            *(u8 *)(reg_a5 + 0x24) &= 1;
            *(u8 *)(reg_a5 + 0x23) -= 1;
        }
    }
    reg_a0 = (unsigned char *)D_00265620;
    reg_a0 += *(u16 *)(reg_a5 + 0x1C);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_d1.w += 0xE200EA00;
    reg_d3.h[0] = 0x1EB0;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer1();
    reg_a0 = (unsigned char *)reg_a6;
    enemy_hitbox_debug_draw();
}

void stage5_spiderling_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 sprite_palette_load();
extern u8 D_00261BB0[];
extern u8 D_002657F0[];
extern u8 D_00265810[];

void stage5_spiderling_start(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    reg_a0 = D_00265810;
    enemy_init_entities();
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a5 + 0x16);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a5 + 0x18);
    ENTITY(reg_a6)->move.h = (u16) *(u16 *)(reg_a5 + 0x1A);
    ENTITY(reg_a6)->misc.h = (u16) *(u16 *)(reg_a5 + 0x1C);
    ENTITY(reg_a6)->misc.h -= 1;
    reg_a0 = D_002657F0;
    reg_d0.w = 0xB;
    enemy_set_task_work();
    reg_d0.h[0] = 0x15;
    reg_a0 = D_00261BB0;
    sprite_palette_load();
    ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
}

s32 bullet_fire256();
s32 sprite_draw_layer5();
s32 sprite_draw_layer5_zoom_keep();
s32 rng_next();
s32 func_00201100();
s32 entity_velocity();
s32 func_00202490();
s32 func_00202730();
s32 entity_check_bounds();
extern u8 D_00265830[];
extern u8 D_0028DA28;
extern u16 g_frame_mod2;
extern u16 g_game_frame;

void stage5_spiderling(void) {
    s32 enemy_hitbox_debug_draw();
    u8 *var_a0;
    u16 temp_a0_2;
    u16 temp_a2;

    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    var_a0 = (u8 *)(reg_a6 + 1);
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        score_add_no_chain();
        var_a0 = (u8 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) reg_d0.b[0];
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x10;
            score_add();
            func_00202730();
            if (cond_flag == 0) {
                reg_d0.w = 0xFFFC0006;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d4.w = 0;
                reg_d3.w = 0;
                bullet_fire256();
                func_00201100();
                reg_d1.b[0] += reg_d5.b[0];
                reg_d0.w += 0x30000;
                bullet_fire256();
            }
            reg_d0.h[0] = 1;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a0_2 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a0_2;
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d0.b[0] *= 4;
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            sfx_explosion_air_small();
            enemy_remove();
            return;
        }
        goto block_6;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
block_6:
    entity_check_bounds();
    if (cond_flag != 0) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            return;
        }
        goto block_10;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_10:
    if (g_enemies_stopped == 0) {
        entity_velocity();
        if (*(u8 *)(reg_a5 + 0x16) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
            *(u8 *)(reg_a5 + 0x21) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
                ENTITY(reg_a6)->move.b.speed -= 1;
                if ((s8) ENTITY(reg_a6)->move.b.speed < 3) {
                    *(s16 *)(reg_a5 + 0x22) = 0;
                    *(u8 *)(reg_a5 + 0x16) = 1U;
                    *(u16 *)(reg_a5 + 0x24) = 0x40U;
                }
            }
        }
        if (*(u8 *)(reg_a5 + 0x16) == 1) {
            *(u16 *)(reg_a5 + 0x24) -= 1;
            if (*(u16 *)(reg_a5 + 0x24) == 0) {
                *(u16 *)(reg_a5 + 0x26) = 0x3CU;
                *(u8 *)(reg_a5 + 0x16) = 2U;
                ENTITY(reg_a6)->move.b.speed = 0x18U;
                func_00202180();
                if (cond_flag == 0) {
                    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                }
            }
        }
        if (*(u8 *)(reg_a5 + 0x16) == 2) {
            func_00202490();
            ENTITY(reg_a6)->move.b.speed -= 1;
            if ((s8) ENTITY(reg_a6)->move.b.speed < 3) {
                ENTITY(reg_a6)->move.b.dir += 0x20;
                ENTITY(reg_a6)->move.b.dir &= 0x3F;
                *(u16 *)(reg_a5 + 0x24) = 0x40U;
                *(u8 *)(reg_a5 + 0x16) = 1U;
            }
        }
        if (*(u8 *)(reg_a5 + 0x2B) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
            *(u8 *)(reg_a5 + 0x1B) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
                *(u8 *)(reg_a5 + 0x2B) = (u8) *(u8 *)(reg_a5 + 0x2A);
                *(u8 *)(reg_a5 + 0x2D) = 0x20U;
                func_00202180();
                if (cond_flag == 0) {
                    *(u8 *)(reg_a5 + 0x2D) = (u8) reg_d1.b[0];
                    rng_next();
                    *(u8 *)(reg_a5 + 0x2D) += reg_d0.b[0];
                    goto block_26;
                }
            }
        } else {
block_26:
            if (*(u8 *)(reg_a5 + 0x16) != 2) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x29);
                *(u8 *)(reg_a5 + 0x29) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x29) = (u8) *(u8 *)(reg_a5 + 0x28);
                    if (g_bullets_blocked == 0) {
                        reg_d1.w = 0;
                        reg_d1.b[0] = *(u8 *)(reg_a5 + 0x2D);
                        reg_d0.w = 0xFFFC0006;
                        reg_d1.b[0] &= 0x3F;
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d4.w = 0;
                        reg_d3.w = 0;
                        *(u8 *)(reg_a5 + 0x2B) -= 1;
                    }
                }
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
        *(u8 *)(reg_a5 + 0x1D) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
            *(u16 *)(reg_a5 + 0x1E) += 4;
            *(u16 *)(reg_a5 + 0x1E) &= 7;
        }
        if (*(u16 *)(reg_a5 + 0x26) != 0) {
            reg_d0.w = 1;
            reg_d0.h[0] &= g_game_frame;
            if (reg_d0.h[0] == 0) {
                *(u16 *)(reg_a5 + 0x26) -= 4;
                if (0 >= (s16) *(u16 *)(reg_a5 + 0x26)) {
                    *(u16 *)(reg_a5 + 0x26) = 0U;
                }
            }
        }
    }
    reg_a0 = &D_0028DA28;
    reg_a0 += *(u16 *)(reg_a5 + 0x1E);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a2 = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_d1.h[0] = temp_a2;
    reg_d1.w += 0xFE00FE00;
    reg_d3.h[0] = 0x210;
    reg_d4.b[0] = 0x19;
    if (g_frame_mod2 != 0) {
        reg_a1 = (u8 *)D_00265830;
        reg_a1 += *(u16 *)(reg_a5 + 0x26);
        reg_d6.h[1] = *(u16 *)reg_a1;
        reg_d6.h[0] = *(u16 *)(reg_a1 + 2);
        sprite_draw_layer5_zoom_keep();
    }
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer5();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

void stage5_bee_drone_first(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 D_00260870[];
extern u8 D_00265870[];
extern u8 D_00265890[];

void stage5_bee_drone_start(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    u16 temp_a0;
    u32 temp_a2;

    reg_a0 = D_00265890;
    enemy_init_entities();
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    temp_a2 = reg_d0.w;
    reg_d0.w = temp_a2 + 0x02000000;
    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
    *(u16 *)(reg_a5 + 0x30) = (u16) *(u16 *)(reg_a5 + 0x1A);
    temp_a0 = *(u16 *)(reg_a5 + 0x1C);
    *(u16 *)(reg_a5 + 0x32) = temp_a0;
    reg_a0 = D_00265870;
    reg_d0.w = 0xE;
    enemy_set_task_work();
    if ((s16) ENTITY(reg_a6)->y.h < 0x2801) {
        enemy_remove();
        return;
    }
    reg_d0.h[0] = 0x15;
    reg_a0 = D_00260870;
    sprite_palette_load();
}

s32 velocity_from_dir256();
extern u8 D_00259870_as_u8_a[];
extern u8 D_002658B0[];
extern u8 D_002659B0[];

void stage5_bee_drone(void) {
    s32 enemy_hitbox_debug_draw();
    s64 temp_v0_10;
    s64 temp_v0_11;
    s64 temp_v0_3;
    s64 temp_v0_4;
    s64 temp_v0_5;
    s64 temp_v0_7;
    s64 temp_v0_8;
    s64 temp_v0_9;
    u16 temp_v0;
    if ((*(u8 *)(reg_a5 + 0x16) != 0) && (*(u16 *)(reg_a5 + 0x30) != 0)) {
        ENTITY(reg_a6)->hp.sh = 0x7FFF;
        *(u16 *)(reg_a5 + 0x30) -= 1;
        if (*(u16 *)(reg_a5 + 0x30) == 0) {
            ENTITY(reg_a6)->hp.sh = 0x1100;
        }
    }
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
        if (ENTITY(reg_a6)->hp.sh < 0) {
            reg_d0.w = 0x213;
            score_add();
            sfx_explosion_ground_large();
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = D_002659B0;
            func_001F61B0();
            enemy_remove();
            return;
        }
        goto block_8;
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) *(u8 *)(reg_a5 + 0x19);
block_8:
    if (g_enemies_stopped == 0) {
        reg_d1.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] -= *(u16 *)(reg_a5 + 0x2A);
        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
        entity_follow_scroll();
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7400;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1400;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0x7400;
        reg_tmp.w += reg_tmp1.w;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto block_13;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_13:
        if (*(u8 *)(reg_a5 + 0x16) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
            *(u8 *)(reg_a5 + 0x1D) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
                *(u16 *)(reg_a5 + 0x1E) += 0x10;
                if (*(u16 *)(reg_a5 + 0x1E) == 0x80) {
                    ENTITY(reg_a6)->flags.h = 0xA001;
                    *(u8 *)(reg_a5 + 0x16) = 1U;
                    *(u8 *)(reg_a5 + 0x16) = 2U;
                    *(s16 *)(reg_a5 + 0x20) = 4;
                    *(u16 *)(reg_a5 + 0x22) = 0xFFFD;
                    *(s16 *)(reg_a5 + 0x26) = 0x1060;
                    *(s8 *)(reg_a5 + 0x28) = 0x10;
                    *(s16 *)(reg_a5 + 0x24) = 0x606;
                }
            }
        }
        if ((s8) *(u8 *)(reg_a5 + 0x16) >= 2) {
            reg_d1.w = 0;
            reg_d0.w = 0;
            reg_d0.b[0] = 0x28;
            reg_d1.b[0] = *(u8 *)(reg_a5 + 0x2D);
            *(u8 *)(reg_a5 + 0x2D) += 2;
            velocity_from_dir256();
            *(u16 *)(reg_a5 + 0x2A) = (u16) reg_d2.h[0];
            reg_d1.h[0] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] += *(u16 *)(reg_a5 + 0x2A);
            ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
            temp_v0 = *(u16 *)(reg_a5 + 0x32);
            if ((s32) temp_v0 < 0x600) {
                *(u16 *)(reg_a5 + 0x32) = (u16) (temp_v0 + 0x40);
                ENTITY(reg_a6)->hit_y_plus.h += 0x40;
                ENTITY(reg_a6)->hit_y_minus.h -= 0x40;
            }
        }
        if (*(u8 *)(reg_a5 + 0x16) == 2) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
            *(u8 *)(reg_a5 + 0x1D) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
                *(u16 *)(reg_a5 + 0x1E) += 0x10;
                if ((s16) *(u16 *)(reg_a5 + 0x1E) >= 0xF0) {
                    *(u16 *)(reg_a5 + 0x1E) = 0xF0U;
                    *(u8 *)(reg_a5 + 0x16) = 3U;
                }
            }
        }
        if (*(u8 *)(reg_a5 + 0x16) == 3) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x27);
            *(u8 *)(reg_a5 + 0x27) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x27) = 0x10U;
                if ((g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h > 0x2000)) {
                    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x2F);
                    if (*(u8 *)(reg_a5 + 0x2E) == reg_d0.b[0]) {
                        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.h[0] += 0x7FFF + 0x7A01;
                        aim256_at_player();
                        if (cond_flag != 0) {
                            reg_d1.h[0] = 0x80;
                        }
                        *(u8 *)(reg_a5 + 0x29) = (u8) reg_d1.b[0];
                    }
                    reg_d1.w = 0;
                    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x29);
                    reg_d0.w = 0xFFFF0005;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d5.w = 0x02000000;
                    reg_d4.w = 0;
                    reg_d3.w = 0;
                    if (*(u8 *)(reg_a5 + 0x2F) != 0) {
                        reg_d1.h[0] -= 0x34;
                        reg_d7.h[0] = 4;
                        reg_a0 = D_00259870_as_u8_a;
                        do {
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_fixed();
                            reg_d1.b[0] += 4;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_fixed();
                            reg_d1.b[0] += 4;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_fixed();
                            reg_d1.b[0] += 0x10;
                        } while ((s16)(--reg_d7.h[0]) >= 0);
                    } else {
                        reg_d0.w = 0xFFFF0004;
                        reg_d1.h[0] -= 0x22;
                        reg_d7.h[0] = 3;
                        reg_a0 = D_00259870_as_u8_a;
                        do {
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_double();
                            reg_d1.b[0] += 2;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_double();
                            reg_d1.b[0] += 2;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_double();
                            reg_d1.b[0] += 2;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_double();
                            reg_d1.b[0] += 2;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            bullet_fire256_double();
                            reg_d1.b[0] += 0xC;
                        } while ((s16)(--reg_d7.h[0]) >= 0);
                    }
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x2F);
                    *(u8 *)(reg_a5 + 0x2F) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x2F) = (u8) *(u8 *)(reg_a5 + 0x2E);
                        *(u8 *)(reg_a5 + 0x27) = *(u8 *)(reg_a5 + 0x26);
                    }
                }
            }
        }
        goto block_88;
    }
block_88:
    reg_a0 = D_002658B0;
    reg_a0 += *(u16 *)(reg_a5 + 0x1E);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 6);
    reg_d1.w += reg_tmp.w;
    reg_d1.h[1] += *(u16 *)(reg_a5 + 0x32);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 8);
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer5();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

void func_001F93C0(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 D_0025FF30[];
extern u8 D_002659F0[];
extern u8 D_00265A00[];

void func_001F93D0(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    reg_a0 = D_00265A00;
    enemy_init_entities();
    reg_a0 = D_002659F0;
    reg_d0.w = 4;
    enemy_set_task_work();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    reg_d0.h[0] = 0x15;
    reg_a0 = D_0025FF30;
    sprite_palette_load();
}

s32 entity_move_by_p2_stick();
extern u8 D_00265A20[];

void func_001F9450(void) {
    s32 enemy_hitbox_debug_draw();
    u16 temp_a0;

    entity_move_by_p2_stick();
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
    *(u8 *)(reg_a5 + 0x1D) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
        *(u16 *)(reg_a5 + 0x1E) += 4;
        *(u16 *)(reg_a5 + 0x1E) &= 0x3F;
    }
    reg_a0 = D_00265A20;
    reg_a0 += *(u16 *)(reg_a5 + 0x1E);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xD800E800;
    reg_d3.h[0] = 0x28C0;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer5();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

void func_001F9540(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

extern u8 D_00265A60[];
extern u8 D_00265A70[];

void func_001F9550(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    reg_a0 = D_00265A70;
    enemy_init_entities();
    reg_a0 = D_00265A60;
    reg_d0.w = 4;
    enemy_set_task_work();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    reg_d0.h[0] = 0x15;
    reg_a0 = D_0025FF30;
    sprite_palette_load();
}

extern u8 D_00265A90[];

void func_001F95D0(void) {
    s32 enemy_hitbox_debug_draw();
    u16 temp_a0;

    entity_move_by_p2_stick();
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
    *(u8 *)(reg_a5 + 0x1D) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
        *(u16 *)(reg_a5 + 0x1E) += 4;
        *(u16 *)(reg_a5 + 0x1E) &= 0x1F;
    }
    reg_a0 = D_00265A90;
    reg_a0 += *(u16 *)(reg_a5 + 0x1E);
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_d1.w += 0xDC00EE00;
    reg_d3.h[0] = 0x2490;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
    sprite_draw_layer5();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}
