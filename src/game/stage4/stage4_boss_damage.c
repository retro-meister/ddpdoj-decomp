#include "common.h"
#include "entity.h"
#include "stage4_boss.h"

void stage4_boss_take_damage(void);
void stage4_boss_defeated(void);
void stage4_boss_part4_blow_off(void);
void stage4_boss_part5_blow_off(void);
void stage4_boss_stop_damage(void);
void stage4_boss_leave_timer(void);

void stage4_boss_damage_none(void) {
}


void stage4_boss_damage(void) {
    if (ENTITY(reg_a6)[11].offset_y.h == 0) {
        stage4_boss_take_damage();
    }
}

s32 boss_phase_start();
s32 boss_phase_stop();
s32 boss_phase_stop_all();
s32 boss_attack_stop_all();
s32 score_add_no_chain();
s32 score_add();
s32 func_002016D0();
extern u8 g_game_mode;
extern s32 g_boss_score;
extern u16 g_enemy_signal_c;
extern u16 g_enemy_signal_9;
extern u16 g_enemy_signal_8;
extern u16 g_enemy_signal_7;
extern u16 g_damage_blink_counter;
extern s16 g_bomb_entities_as_s16_a[];
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
extern u16 D_00684C80[];
#endif

void stage4_boss_take_damage(void) {
    s32 active_players_mask();
    s32 hp;
    s32 mid;
    s32 low;

    g_enemy_signal_7 = 0;
    if (g_enemy_signal_8 == 0) goto check_body_hit;
    reg_d1.h[0] = g_enemy_signal_9;
    ENTITY(reg_a6)[11].draw.h = reg_d1.h[0];
    goto body_hit;
check_body_hit:
    reg_d1.b[0] = ENTITY(reg_a6)[1].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[2].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[3].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] == 0) goto body_not_hit;
    ENTITY(reg_a6)[11].draw.h = reg_d1.h[0];
body_hit:
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[2].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[3].flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)[10].offset_y.b[1];
    if (reg_d0.b[0] != 0x19) goto body_flash;
    ENTITY(reg_a6)[10].offset_y.b[1] = 0x13;
    ENTITY(reg_a6)[10].offset_y.b[0] = 0x14;
    ENTITY(reg_a6)[10].offset_x.b[1] = 0x15;
    ENTITY(reg_a6)[10].offset_x.b[0] = 0x15;
    ENTITY(reg_a6)[10].draw.b.priority = 0x15;
    ENTITY(reg_a6)[10].draw.b.flip = 0x14;
body_flash:
    reg_d0.b[0] = ENTITY(reg_a6)[10].offset_y.b[1];
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)[10].offset_y.b[1] = reg_d0.b[0];
    if (ENTITY(reg_a6)[2].misc.b.draw_layer != 0) goto body_flash_done;
    reg_d0.b[0] = ENTITY(reg_a6)[10].offset_y.b[0];
    reg_d0.b[0] ^= 0xB;
    ENTITY(reg_a6)[10].offset_y.b[0] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[10].offset_x.b[1];
    reg_d0.b[0] ^= 0xA;
    ENTITY(reg_a6)[10].offset_x.b[1] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[10].offset_x.b[0];
    reg_d0.b[0] ^= 0xA;
    ENTITY(reg_a6)[10].offset_x.b[0] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[10].draw.b.priority;
    reg_d0.b[0] ^= 0xA;
    ENTITY(reg_a6)[10].draw.b.priority = reg_d0.b[0];
body_flash_done:
    reg_d0.b[0] = ENTITY(reg_a6)[10].draw.b.flip;
    reg_d0.b[0] ^= 0xB;
    ENTITY(reg_a6)[10].draw.b.flip = reg_d0.b[0];
    if (g_game_mode != 2) goto find_damage;
    hp = ENTITY(reg_a6)[1].hp.h;
    mid = ENTITY(reg_a6)[2].hp.h;
    low = ENTITY(reg_a6)[3].hp.h;
    if (hp > (s32)mid) goto largest_of_two;
    hp = mid;
largest_of_two:
    if (hp > (s32)low) goto find_damage;
    hp = low;
find_damage:
    reg_d2.w = 0x7FFF;
    reg_d2.h[0] -= ENTITY(reg_a6)[1].hp.h;
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= ENTITY(reg_a6)[2].hp.h;
    if (!((s32)reg_d2.w < (s32)reg_d3.w)) goto damage_of_two;
    reg_d2.w = reg_d3.w;
damage_of_two:
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= ENTITY(reg_a6)[3].hp.h;
    if (!((s32)reg_d2.w < (s32)reg_d3.w)) goto damage_found;
    reg_d2.w = reg_d3.w;
damage_found:
    reg_d0.w = 0;
    reg_d0.h[0] = g_enemy_signal_8;
    if (reg_d0.h[0] == 0) goto subtract_hp;
    reg_d0.h[0] = (s32)(reg_d0.h[0] & 0xFFFF) >> 1;
    g_enemy_signal_8 = 0;
    reg_d2.w = reg_d0.w;
    if (g_bomb_entities_as_s16_a[0] >= 0) goto cutter_damage_seen;
#ifdef DEATH_LABEL
    hp = reg_d2.w;
    if (hp != 0) {
        if (death_D_00290DC0 == 0) {
            if (D_00684C80[9] == 2) {
                hp = 0;
            }
            if (D_00684C80[9] == 4) {
                hp /= 5;
            }
            if (D_00684C80[9] == 6) {
                hp /= 10;
            }
        } else {
            if (D_00684C80[9] == 2) {
                hp *= 2;
            }
            if (D_00684C80[9] == 4) {
                hp *= 2;
            }
            if (D_00684C80[9] == 6) {
                hp *= 2;
            }
        }
    }
    if (hp != 0) {
        hp += 0x7FFF;
    }
#else
    hp = 0;
    if (reg_d2.w == 0) goto cutter_damage_add;
    hp = reg_d2.w / 6;
cutter_damage_add:
    hp += 0x7FFF;
#endif
cutter_damage_seen:
    g_enemy_signal_7 = 1;
subtract_hp:
    if (ENTITY(reg_a6)[11].offset_x.h != 0) goto refill_body;
    reg_tmp.h[1] = STAGE4_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE4_BOSS(reg_a5)->hp[1];
    if (g_game_mode != 2) goto subtract_other_mode;
    if (hp <= 0x7FFF) goto subtract_plain;
    reg_tmp.w += hp - 0x7FFF;
    if (reg_tmp.w < 0x46000) goto store_hp;
    reg_tmp.w = 0x46000;
    goto store_hp;
subtract_plain:
    reg_tmp.w -= reg_d2.w;
    goto store_hp;
subtract_other_mode:
    reg_tmp.w -= reg_d2.w;
store_hp:
    STAGE4_BOSS(reg_a5)->hp[0] = reg_tmp.h[1];
    STAGE4_BOSS(reg_a5)->hp[1] = reg_tmp.h[0];
refill_body:
    reg_d0.h[0] = 0x7FFF;
    ENTITY(reg_a6)[1].hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[2].hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[3].hp.h = reg_d0.h[0];
    goto check_part4;
body_not_hit:
    ENTITY(reg_a6)[10].offset_y.b[1] = 0x13;
    ENTITY(reg_a6)[10].offset_y.b[0] = 0x14;
    ENTITY(reg_a6)[10].offset_x.b[1] = 0x15;
    ENTITY(reg_a6)[10].offset_x.b[0] = 0x15;
    ENTITY(reg_a6)[10].draw.b.priority = 0x15;
    ENTITY(reg_a6)[10].draw.b.flip = 0x14;
    reg_d2.w = 0xC400;
    reg_tmp.h[1] = STAGE4_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE4_BOSS(reg_a5)->hp[1];
    if (reg_tmp.w > reg_d2.w) goto check_part4;
    if (g_damage_blink_counter != 0) goto check_part4;
    reg_d0.w = 0x19;
    ENTITY(reg_a6)[10].offset_y.b[1] = reg_d0.b[0];
    ENTITY(reg_a6)[10].offset_y.b[0] = reg_d0.b[0];
    ENTITY(reg_a6)[10].offset_x.b[1] = reg_d0.b[0];
    ENTITY(reg_a6)[10].offset_x.b[0] = reg_d0.b[0];
    ENTITY(reg_a6)[10].draw.b.priority = reg_d0.b[0];
    ENTITY(reg_a6)[10].draw.b.flip = reg_d0.b[0];
check_part4:
    reg_d1.b[0] = ENTITY(reg_a6)[4].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] == 0) goto part4_not_hit;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[4].flags.b[1] &= reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[10].sprite.b[1];
    if (reg_d0.b[0] != 0x19) goto part4_flash;
    ENTITY(reg_a6)[10].sprite.b[1] = 0x13;
part4_flash:
    reg_d0.b[0] = ENTITY(reg_a6)[10].sprite.b[1];
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)[10].sprite.b[1] = reg_d0.b[0];
    reg_d0.h[0] = 0x7FFF;
    reg_d0.h[0] -= ENTITY(reg_a6)[4].hp.h;
    if (!((s16)g_enemy_signal_8 < (s16)reg_d0.h[0])) goto part4_refill;
    g_enemy_signal_8 = reg_d0.h[0];
    g_enemy_signal_9 = reg_d1.h[0];
part4_refill:
    ENTITY(reg_a6)[4].hp.h = 0x7FFF;
    goto check_part5;
part4_not_hit:
    ENTITY(reg_a6)[10].sprite.b[1] = 0x13;
check_part5:
    reg_d1.b[0] = ENTITY(reg_a6)[5].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] == 0) goto part5_not_hit;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[5].flags.b[1] &= reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[10].sprite.b[0];
    if (reg_d0.b[0] != 0x19) goto part5_flash;
    ENTITY(reg_a6)[10].sprite.b[0] = 0x13;
part5_flash:
    reg_d0.b[0] = ENTITY(reg_a6)[10].sprite.b[0];
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)[10].sprite.b[0] = reg_d0.b[0];
    reg_d0.h[0] = 0x7FFF;
    reg_d0.h[0] -= ENTITY(reg_a6)[5].hp.h;
    if (!((s16)g_enemy_signal_8 < (s16)reg_d0.h[0])) goto part5_refill;
    g_enemy_signal_8 = reg_d0.h[0];
    g_enemy_signal_9 = reg_d1.h[0];
part5_refill:
    ENTITY(reg_a6)[5].hp.h = 0x7FFF;
    goto check_defeated;
part5_not_hit:
    ENTITY(reg_a6)[10].sprite.b[0] = 0x13;
check_defeated:
    reg_tmp.h[1] = STAGE4_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE4_BOSS(reg_a5)->hp[1];
    if ((s32)reg_tmp.w >= 0) goto check_second_form;
    active_players_mask();
    if (reg_d0.h[0] != 0) goto defeated;
    reg_tmp.w = 0x200;
    STAGE4_BOSS(reg_a5)->hp[0] = reg_tmp.h[1];
    STAGE4_BOSS(reg_a5)->hp[1] = reg_tmp.h[0];
    goto check_second_form;
defeated:
    reg_d1.h[0] = ENTITY(reg_a6)[11].draw.h;
    reg_d0.w = 0x60000;
    score_add();
    g_boss_score = 0x60000;
    stage4_boss_defeated();
    return;
check_second_form:
    if (ENTITY(reg_a6)[11].sprite.b[1] != 0) goto check_parts_off;
#ifndef DEATH_LABEL
    STAGE4_BOSS(reg_a5)->form2_delay -= 1;
#endif
    if (STAGE4_BOSS(reg_a5)->form2_delay == 0) goto second_form;
    reg_tmp.h[1] = STAGE4_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE4_BOSS(reg_a5)->hp[1];
    if (!((s32)reg_tmp.w < 0x23000)) goto check_parts_off;
second_form:
    ENTITY(reg_a6)[11].sprite.b[1] = 1;
    boss_attack_stop_all();
    boss_phase_stop_all();
    func_002016D0();
    reg_d0.w = 1;
    boss_phase_start();
    ENTITY(reg_a6)[2].misc.b.draw_layer = 1;
check_parts_off:
    if (ENTITY(reg_a6)[11].sprite.b[0] != 0) goto check_leave;
    reg_tmp.h[1] = STAGE4_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE4_BOSS(reg_a5)->hp[1];
    if (!((s32)reg_tmp.w < 0xC400)) goto check_leave;
    ENTITY(reg_a6)[11].sprite.b[0] = 1;
    g_enemy_signal_c = 1;
    reg_d0.w = 5;
    boss_phase_stop();
    reg_d0.w = 6;
    boss_phase_start();
    stage4_boss_part4_blow_off();
    stage4_boss_part5_blow_off();
    func_002016D0();
check_leave:
    stage4_boss_leave_timer();
}

s32 func_0013F3C0();
s32 func_00201490();
s32 func_00203460();
s32 slowdown_turn_off();
extern u8 g_boss_present_b1;

void stage4_boss_defeated(void) {
    g_boss_present_b1 |= 0x40;
    g_enemy_signal_c = 1;
    g_boss_present_b1 |= 0x80;
    slowdown_turn_off();
    func_0013F3C0();
    func_00203460();
    func_00201490();
    stage4_boss_stop_damage();
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_tmp.w = -1U;
    STAGE4_BOSS(reg_a5)->hp[0] = (u16) reg_tmp.h[1];
    STAGE4_BOSS(reg_a5)->hp[1] = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)[1].misc.sb.draw_layer = 1;
    ENTITY(reg_a6)[1].flags.h = 0x8000;
    ENTITY(reg_a6)[10].offset_y.sb[1] = 0x13;
    ENTITY(reg_a6)[10].offset_y.sb[0] = 0x14;
    ENTITY(reg_a6)[10].offset_x.sb[1] = 0x15;
    ENTITY(reg_a6)[10].offset_x.sb[0] = 0x15;
    ENTITY(reg_a6)[10].draw.sb.priority = 0x15;
    ENTITY(reg_a6)[10].draw.sb.flip = 0x14;
    stage4_boss_part4_blow_off();
    stage4_boss_part5_blow_off();
    reg_d0.w = 2;
    boss_phase_start();
}

s32 boss_part_hide(s32, s32, s32);
s32 explosion_burst_small(void *);
s32 sfx_explosion_ground_medium();
s32 stage4_boss_explosions_from_table();
s32 rng_next_unsigned();
extern u8 D_0026F640[];

void stage4_boss_part4_blow_off(void) {
    if (ENTITY(reg_a6)[4].misc.b.draw_layer == 0) {
        ENTITY(reg_a6)[4].hp.h = 0xFFFF;
        ENTITY(reg_a6)[4].misc.b.draw_layer = 1U;
        ENTITY(reg_a6)[4].flags.h = 0x8000;
        ENTITY(reg_a6)[10].sprite.sb[1] = 0x13;
        reg_d0.w = 7;
        boss_part_hide(0x13, 0x8000, 1);
        sfx_explosion_ground_medium();
        reg_a1 = D_0026F640;
        reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
        stage4_boss_explosions_from_table();
        rng_next_unsigned();
        reg_d1.b[0] = reg_d0.b[0];
        reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
        reg_d3.h[0] = 0x10;
        reg_d0.h[0] = 0;
        explosion_burst_small(reg_a6);
    }
}

extern u8 D_0026F670[];

void stage4_boss_part5_blow_off(void) {
    if (ENTITY(reg_a6)[5].misc.b.draw_layer == 0) {
        ENTITY(reg_a6)[5].hp.h = 0xFFFF;
        ENTITY(reg_a6)[5].misc.b.draw_layer = 1U;
        ENTITY(reg_a6)[5].flags.h = 0x8000;
        ENTITY(reg_a6)[10].sprite.sb[0] = 0x13;
        reg_d0.w = 8;
        boss_part_hide(0x13, 0x8000, 1);
        sfx_explosion_ground_medium();
        reg_a1 = D_0026F670;
        reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
        stage4_boss_explosions_from_table();
        rng_next_unsigned();
        reg_d1.b[0] = reg_d0.b[0];
        reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
        reg_d3.h[0] = 0x10;
        reg_d0.h[0] = 0;
        explosion_burst_small(reg_a6);
    }
}

void stage4_boss_shield_on(void) {
    ENTITY(reg_a6)[11].offset_x.sh = 1;
}

void stage4_boss_shield_off(void) {
    ENTITY(reg_a6)[11].offset_x.sh = 0;
}

void stage4_boss_start_none(void) {
}

void stage4_boss_part_take_hits(void) {
    reg_a0 = reg_a6;
    reg_a0 += reg_d0.h[0];
    *(u16 *)reg_a0 = 0xA001;
}

void stage4_boss_part_stop_hits(void) {
    reg_a0 = reg_a6;
    reg_a0 += reg_d0.h[0];
    *(u16 *)reg_a0 = 0x8000;
}

void stage4_boss_stop_damage(void) {
    ENTITY(reg_a6)[11].offset_y.sh = 1;
}

extern u16 g_enemies_stopped;

void stage4_boss_leave_timer(void) {
    void active_players_mask(void);
#ifdef DEATH_LABEL
    if ((g_enemies_stopped == 0) && (ENTITY(reg_a6)[11].sprite.b[1] != 0) && (STAGE4_BOSS(reg_a5)->leave_delay == 0)) {
#else
    if ((g_enemies_stopped == 0) && (ENTITY(reg_a6)[11].sprite.b[1] != 0) && (STAGE4_BOSS(reg_a5)->leave_delay -= 1, STAGE4_BOSS(reg_a5)->leave_delay == 0)) {
#endif
        active_players_mask();
        if (reg_d0.h[0] == 0) {
            STAGE4_BOSS(reg_a5)->leave_delay = 0x78U;
            return;
        }
        ENTITY(reg_a6)[11].draw.sh = 0;
        stage4_boss_defeated();
    }
}

u8 D_0026F640[96] = {
    0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0xFA, 0x00, 0xFE, 0xA0, 0x04, 0x02, 0x00, 0x87, 0x00,
    0x00, 0x00, 0x00, 0xF8, 0x00, 0x04, 0x50, 0x04, 0x04, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x00, 0xFE,
    0x00, 0x00, 0x00, 0x02, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0xFA, 0x00, 0x02, 0x50, 0x04, 0x02, 0x00, 0x87, 0x00,
    0x00, 0x00, 0x00, 0xF8, 0x00, 0xFC, 0xA0, 0x04, 0x04, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x00, 0xFE,
    0x00, 0x00, 0x00, 0x02, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
