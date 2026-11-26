#include "common.h"
#include "entity.h"
#include "stage5_boss.h"

s32 stage5_boss_form2_defeated();
extern u16 g_enemies_stopped;

void stage5_boss_form2_time_limit(void) {
    void active_players_mask(void);
#ifdef DEATH_LABEL
    if ((g_enemies_stopped == 0) && (STAGE5_BOSS(reg_a5)->time_left == 0)) {
#else
    if ((g_enemies_stopped == 0) && (STAGE5_BOSS(reg_a5)->time_left -= 1, STAGE5_BOSS(reg_a5)->time_left == 0)) {
#endif
        active_players_mask();
        if (reg_d0.h[0] == 0) {
            STAGE5_BOSS(reg_a5)->time_left = 0x78U;
            return;
        }
        STAGE5_DAMAGE(reg_a6)->hit_by = 0;
        stage5_boss_form2_defeated();
    }
}

s32 boss_phase_start();
s32 boss_phase_stop_all();
s32 boss_movement_start();
s32 boss_part_show();
s32 boss_part_hide();
s32 boss_attack_stop_all();
s32 score_add_no_chain();
s32 stage5_boss_shield_on();
void stage5_boss_form3_defeated();
void stage5_boss_form3_time_limit(void);
s32 func_002016D0();
extern s32 g_boss_score;
extern u16 g_bullets_blocked;
extern u16 g_damage_blink_counter;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];
extern s16 D_0029976E_as_s16_a[];
extern u16 g_bomb_entities[];

void stage5_boss_form3_take_damage(void) {
    s32 active_players_mask();
#ifdef DEATH_LABEL
    u16 hp;

#endif
    reg_d1.b[0] = ENTITY(reg_a6)[12].flags.b[1];
#ifdef DEATH_LABEL
    reg_d1.b[0] |= ENTITY(reg_a6)[16].flags.b[1];
#endif
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) {
        goto next_2;
    }
next_1:
    STAGE5_PALETTES(reg_a6)->form3_body = 0x17;
    reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
    if (reg_tmp.w >= 0x1ECCC) {
        goto next_7;
    }
    if (g_damage_blink_counter != 0) {
        goto next_7;
    }
    reg_d0.w = 0x19;
    STAGE5_PALETTES(reg_a6)->form3_body = reg_d0.b[0];
    goto next_7;
next_2:
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[12].flags.b[1] &= reg_d0.b[0];
#ifdef DEATH_LABEL
    ENTITY(reg_a6)[16].flags.b[1] &= reg_d0.b[0];
#endif
    *(u16 *) (reg_a6 + 0x10A) = reg_d1.h[0];
    if (g_bullets_blocked != 0) {
        goto next_3;
    }
    if (g_bomb_entities[0] == 0) {
        goto next_4;
    }
    *(u16 *) (reg_a6 + 0x13A) = 40;
next_3:
    reg_d0.w = 0x12;
    boss_part_show();
    reg_d5.h[0] = 0x7FFF;
    *(u16 *) (reg_a6 + 0x198) = reg_d5.h[0];
#ifdef DEATH_LABEL
    *(u16 *) (reg_a6 + 0x218) = reg_d5.h[0];
#endif
    STAGE5_BOSS(reg_a5)->hp[0] = STAGE5_BOSS(reg_a5)->hp_scratch[0];
    STAGE5_BOSS(reg_a5)->hp[1] = STAGE5_BOSS(reg_a5)->hp_scratch[1];
    goto next_1;
next_4:
    if (*(u16 *) (reg_a6 + 0x13A) != 0) {
        goto next_3;
    }
    score_add_no_chain();
    reg_d0.b[0] = STAGE5_PALETTES(reg_a6)->form3_body;
    if (reg_d0.b[0] != 0x19) {
        goto next_5;
    }
    reg_d0.b[0] = 0x17;
next_5:
    reg_d0.b[0] ^= 8;
    STAGE5_PALETTES(reg_a6)->form3_body = reg_d0.b[0];
    reg_d4.h[0] = *(u16 *) (reg_a6 + 0x198);
#ifdef DEATH_LABEL
    hp = *(u16 *) (reg_a6 + 0x218);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
#endif
    reg_d5.w = 0x7FFF;
    *(u16 *) (reg_a6 + 0x198) = reg_d5.h[0];
#ifdef DEATH_LABEL
    *(u16 *) (reg_a6 + 0x218) = reg_d5.h[0];
#endif
    reg_d5.h[0] -= reg_d4.h[0];
    if (*(u16 *) (reg_a6 + 0x108) != 0) {
        goto next_7;
    }
    reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
    reg_tmp.w -= reg_d5.w;
    STAGE5_BOSS(reg_a5)->hp[0] = reg_tmp.h[1];
    STAGE5_BOSS(reg_a5)->hp[1] = reg_tmp.h[0];
    if (0 <= (s64) (s32) reg_tmp.w) {
        goto next_7;
    }
    active_players_mask();
    if (reg_d0.b[0] != 0) {
        goto next_6;
    }
    reg_tmp.w = 0x200;
    STAGE5_BOSS(reg_a5)->hp[0] = reg_tmp.h[1];
    STAGE5_BOSS(reg_a5)->hp[1] = reg_tmp.h[0];
    goto next_7;
next_6:
    g_boss_score = 0x100000;
    stage5_boss_form3_defeated();
    return;
next_7:
    STAGE5_BOSS(reg_a5)->hp_scratch[0] = STAGE5_BOSS(reg_a5)->hp[0];
    STAGE5_BOSS(reg_a5)->hp_scratch[1] = STAGE5_BOSS(reg_a5)->hp[1];
    reg_d0.h[0] = 0x500;
    if (*(u16 *) (reg_a6 + 0x13A) == 0) {
        goto next_8;
    }
    *(u16 *) (reg_a6 + 0x13A) -= 1;
    reg_d0.h[0] = 0x800;
next_8:
    *(u16 *) (reg_a6 + 0x194) = reg_d0.h[0];
    *(u16 *) (reg_a6 + 0x196) = reg_d0.h[0];
#ifdef DEATH_LABEL
    *(u16 *) (reg_a6 + 0x214) = reg_d0.h[0];
    *(u16 *) (reg_a6 + 0x216) = reg_d0.h[0];
#endif
    reg_d0.w = 0x12;
    if (g_bullets_blocked != 0) {
        goto next_9;
    }
    if (g_bomb_entities[0] != 0) {
        goto next_9;
    }
    if (*(u16 *) (reg_a6 + 0x13A) != 0) {
        goto next_9;
    }
    boss_part_hide();
    goto next_10;
next_9:
    boss_part_show();
next_10:
#ifdef DEATH_LABEL
    if (STAGE5_DAMAGE(reg_a6)->form3_second_phase == 0) {
        reg_d0.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
        reg_d0.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
        reg_d0.w -= 0x23000;
        if (0 <= (s64) (s32) reg_d0.w) {
            goto next_11;
        }
        boss_attack_stop_all();
        boss_phase_stop_all();
        reg_d0.w = 0x10;
        boss_movement_start();
        reg_d0.w = 0x1A;
        boss_phase_start();
        stage5_boss_shield_on();
        STAGE5_DAMAGE(reg_a6)->form3_second_phase = 1;
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C_as_s16_a[0] = 1;
        D_0029976E_as_s16_a[0] = 1;
        func_002016D0();
    }
    if (STAGE5_DAMAGE(reg_a6)->form3_second_phase < 2) {
        reg_d0.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
        reg_d0.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
        reg_d0.w -= 0x174C0;
        if (0 <= (s64) (s32) reg_d0.w) {
            goto next_11;
        }
        boss_attack_stop_all();
        boss_phase_stop_all();
        reg_d0.w = 0x10;
        boss_movement_start();
        reg_d0.w = 0x19;
        boss_phase_start();
        stage5_boss_shield_on();
        STAGE5_DAMAGE(reg_a6)->form3_second_phase = 2;
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C_as_s16_a[0] = 1;
        D_0029976E_as_s16_a[0] = 1;
        func_002016D0();
    }
#else
    if (STAGE5_DAMAGE(reg_a6)->form3_second_phase != 0) {
        goto next_11;
    }
    reg_d0.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
    reg_d0.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
    reg_d0.w -= 0x23000;
    if (0 <= (s64) (s32) reg_d0.w) {
        goto next_11;
    }
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_d0.w = 0xB;
    boss_movement_start();
    reg_d0.w = 0x13;
    boss_phase_start();
    stage5_boss_shield_on();
    STAGE5_DAMAGE(reg_a6)->form3_second_phase = 1;
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    D_0029976C_as_s16_a[0] = 1;
    D_0029976E_as_s16_a[0] = 1;
    func_002016D0();
#endif
next_11:
    stage5_boss_form3_time_limit();
}

s32 boss_phase_start();
s32 boss_phase_stop_all();
s32 boss_part_hide();
s32 boss_attack_stop_all();
s32 func_0013F3C0();
s32 stage5_boss_stop_damage();
s32 func_002016D0();
s32 func_00203460();
s32 slowdown_turn_off();
extern u8 g_boss_present_b1;

void stage5_boss_form3_defeated() {
    g_boss_present_b1 |= 0x40;
    g_boss_present_b1 |= 0x80;
    slowdown_turn_off();
    func_0013F3C0();
    func_00203460();
    func_002016D0();
    stage5_boss_stop_damage();
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_tmp.w = -1U;
    STAGE5_BOSS(reg_a5)->hp[0] = (u16) reg_tmp.h[1];
    STAGE5_BOSS(reg_a5)->hp[1] = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)[10].misc.sb.draw_layer = 1;
    ENTITY(reg_a6)[12].flags.h = 0x8000;
#ifdef DEATH_LABEL
    ENTITY(reg_a6)[16].flags.h = 0x8000;
#endif
    STAGE5_PALETTES(reg_a6)->form3_body = 0x17;
    reg_d0.w = 0x12;
    boss_part_hide();
    reg_d0.w = 5;
    boss_phase_start();
}

void active_players_mask(void);
extern u16 g_enemies_stopped;

void stage5_boss_form3_time_limit(void) {
    #ifdef DEATH_LABEL
    if ((g_enemies_stopped == 0) && (STAGE5_BOSS(reg_a5)->time_left == 0)) {
#else
    if ((g_enemies_stopped == 0) && (STAGE5_BOSS(reg_a5)->time_left -= 1, STAGE5_BOSS(reg_a5)->time_left == 0)) {
#endif
        active_players_mask();
        if (reg_d0.h[0] == 0) {
            STAGE5_BOSS(reg_a5)->time_left = 0x78U;
            return;
        }
        STAGE5_DAMAGE(reg_a6)->hit_by = 0;
        stage5_boss_form3_defeated();
    }
}
