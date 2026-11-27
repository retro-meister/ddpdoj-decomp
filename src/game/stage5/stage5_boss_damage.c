#include "common.h"
#include "black_label.h"
#include "arcade_gameplay.h"
#include "entity.h"
#include "stage5_boss.h"

void stage5_boss_form1_defeated(void);
void stage5_boss_shield_on(void);
void stage5_boss_form1_stop_hits(void);
void stage5_boss_stop_damage(void);
void stage5_boss_form1_time_limit(void);
void stage5_boss_form2_take_damage(void);
void stage5_boss_form2_defeated(void);

s32 boss_phase_stop_all();
s32 boss_attack_stop_all();
s32 score_add_no_chain();
s32 score_add();
s32 bullet_cancel_on_boss_hit();
extern u8 g_game_mode;
extern u16 g_stage5_boss_all_forms;
extern s32 g_boss_score;
extern u16 g_damage_blink_counter;

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define TW(o) (*(u16 *)(reg_a5 + (o)))

void stage5_boss_form1_take_damage(void) {
    s32 top;
    s32 p1;
    s32 p2;
    s32 p3;
    s32 p4;
    s32 p5;
#ifdef DEATH_LABEL
    s32 p6;
    s32 p7;
#endif
    u16 hp;

    if (W(0x106) != 0) return;
    if (STAGE5_DAMAGE(reg_a6)->form != 0) {
        stage5_boss_form2_take_damage();
        return;
    }
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[2].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[3].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[4].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[5].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[6].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[13].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_1;
    STAGE5_PALETTES(reg_a6)->head = 0x10;
    STAGE5_PALETTES(reg_a6)->chest = 0x11;
    STAGE5_PALETTES(reg_a6)->belly = 0x12;
    STAGE5_PALETTES(reg_a6)->arm_guns = 0x16;
    reg_tmp.h[1] = TW(0x16);
    reg_tmp.h[0] = TW(0x18);
    if (reg_tmp.w >= GAME_RULE(0x15000, 0x62000 * 15 / 100)) goto block_chk;
    if (g_damage_blink_counter != 0) goto block_chk;
    reg_d0.w = 0x19;
    STAGE5_PALETTES(reg_a6)->head = reg_d0.b[0];
    STAGE5_PALETTES(reg_a6)->chest = reg_d0.b[0];
    STAGE5_PALETTES(reg_a6)->belly = reg_d0.b[0];
    STAGE5_PALETTES(reg_a6)->arm_guns = reg_d0.b[0];
    goto block_chk;
next_1:
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[2].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[3].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[4].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[5].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[6].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[13].flags.b[1] &= reg_d0.b[0];
    W(0x10A) = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = STAGE5_PALETTES(reg_a6)->head;
    reg_d2.b[0] = STAGE5_PALETTES(reg_a6)->chest;
    reg_d3.b[0] = STAGE5_PALETTES(reg_a6)->belly;
    reg_d4.b[0] = STAGE5_PALETTES(reg_a6)->arm_guns;
    if (reg_d0.b[0] != 0x19) goto next_2;
    reg_d0.b[0] = 0x10;
    reg_d2.b[0] = 0x11;
    reg_d3.b[0] = 0x12;
    reg_d4.b[0] = 0x16;
next_2:
    reg_d0.b[0] ^= 0xF;
    STAGE5_PALETTES(reg_a6)->head = reg_d0.b[0];
    reg_d2.b[0] ^= 0xE;
    STAGE5_PALETTES(reg_a6)->chest = reg_d2.b[0];
    reg_d3.b[0] ^= 0xD;
    STAGE5_PALETTES(reg_a6)->belly = reg_d3.b[0];
    reg_d4.b[0] ^= 9;
    STAGE5_PALETTES(reg_a6)->arm_guns = reg_d4.b[0];
    if (g_game_mode == 2) {
#ifdef DEATH_LABEL
        top = W(0x18);
        p1 = W(0x38);
        p2 = W(0x58);
        p3 = W(0x78);
        p4 = W(0x98);
        p5 = W(0xB8);
        p6 = W(0xD8);
        p7 = W(0x1B8);
        if (top > p1) goto skip_1;
        top = p1;
skip_1:
        if (p2 > p3) goto skip_2;
        p2 = p3;
skip_2:
        if (p4 > p5) goto skip_3;
        p4 = p5;
skip_3:
        if (p6 > p7) goto skip_4;
        p6 = p7;
skip_4:
        if (top > p2) goto skip_5;
        top = p2;
skip_5:
        if (p4 > p6) goto skip_6;
        p4 = p6;
skip_6:
        if (top > p4) goto skip_7;
        top = p4;
skip_7:;
#else
        top = W(0x18);
        p1 = W(0x38);
        p2 = W(0x58);
        p3 = W(0x78);
        p4 = W(0xD8);
        p5 = W(0x1B8);
        if (top > p1) goto skip_1;
        top = p1;
skip_1:
        if (p2 > p3) goto skip_2;
        p2 = p3;
skip_2:
        if (p4 > p5) goto skip_3;
        p4 = p5;
skip_3:
        if (top > p2) goto skip_4;
        top = p2;
skip_4:
        if (top > p4) goto skip_5;
        top = p4;
skip_5:;
#endif
    }
    reg_d4.h[0] = W(0x18);
    hp = W(0x38);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0x58);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0x78);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0x98);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0xB8);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0xD8);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0x1B8);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    reg_d5.w = 0x7FFF;
    W(0x18) = reg_d5.h[0];
    W(0x38) = reg_d5.h[0];
    W(0x58) = reg_d5.h[0];
    W(0x78) = reg_d5.h[0];
    W(0x98) = reg_d5.h[0];
    W(0xB8) = reg_d5.h[0];
    W(0xD8) = reg_d5.h[0];
    W(0x1B8) = reg_d5.h[0];
    reg_d5.h[0] -= reg_d4.h[0];
    if (W(0x108) != 0) goto block_chk;
    reg_tmp.h[1] = TW(0x16);
    reg_tmp.h[0] = TW(0x18);
    if (g_game_mode == 2) {
        if (top > 0x7FFF) {
            reg_tmp.w += top - 0x7FFF;
            if (reg_tmp.w >= 0x3F000) reg_tmp.w = 0x3F000;
        } else {
            reg_tmp.w -= reg_d5.w;
        }
    } else {
        reg_tmp.w -= reg_d5.w;
    }
    TW(0x16) = reg_tmp.h[1];
    TW(0x18) = reg_tmp.h[0];
    if (0 > (s32) reg_tmp.w) goto next_9;
    goto block_chk;
next_9:
    active_players_mask();
    if (reg_d0.h[0] != 0) goto next_6;
    reg_tmp.w = 0x200;
    TW(0x16) = reg_tmp.h[1];
    TW(0x18) = reg_tmp.h[0];
    goto block_chk;
next_6:
    if (g_stage5_boss_all_forms != 0) goto next_7;
    g_boss_score = 0x70000;
    stage5_boss_form1_defeated();
    return;
next_7:
    reg_d1.h[0] = W(0x10A);
    reg_d0.w = 0x70000;
    score_add();
    stage5_boss_form1_defeated();
    return;
block_chk:
    if (STAGE5_DAMAGE(reg_a6)->form1_second_phase != 0) goto next_8;
    if (g_stage5_boss_all_forms != 0) goto next_8;
    reg_d0.h[1] = TW(0x16);
    reg_d0.h[0] = TW(0x18);
    reg_d0.w += 0xFFFD6000;
    if (0 > (s32) reg_d0.w) goto next_10;
    goto next_8;
next_10:
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_d0.w = 0xE;
    boss_phase_start();
    stage5_boss_shield_on();
    STAGE5_DAMAGE(reg_a6)->form1_second_phase = 1;
    bullet_cancel_on_boss_hit();
next_8:
    stage5_boss_form1_time_limit();
}

s32 boss_phase_stop_all();                            /* extern */
s32 boss_animation_stop();                            /* extern */
s32 boss_attack_stop_all();                            /* extern */
s32 boss_kill_counter_clamp();                            /* extern */
s32 music_stop();                            /* extern */
s32 bullet_cancel_on_boss_hit();                            /* extern */
s32 boss_defeat_begin();                            /* extern */
s32 slowdown_turn_off();                            /* extern */
extern u8 g_boss_present_b1;

void stage5_boss_form1_defeated(void) {
    music_stop();
    slowdown_turn_off();
    if (g_stage5_boss_all_forms == 0) {
        g_boss_present_b1 |= 0x40;
        g_boss_present_b1 |= 0x80;
        boss_defeat_begin();
        ENTITY(reg_a6)->misc.sb.draw_layer = 1;
    } else {
        STAGE5_BOSS(reg_a5)->time_left = 0x6270;
    }
    boss_kill_counter_clamp();
    bullet_cancel_on_boss_hit();
    boss_attack_stop_all();
    boss_phase_stop_all();
    stage5_boss_stop_damage();
    stage5_boss_form1_stop_hits();
    reg_d0.w = 2;
    boss_animation_stop();
    reg_tmp.w = -1U;
    STAGE5_BOSS(reg_a5)->hp[0] = (u16) reg_tmp.h[1];
    STAGE5_BOSS(reg_a5)->hp[1] = (u16) reg_tmp.h[0];
    STAGE5_PALETTES(reg_a6)->head = 0x10;
    STAGE5_PALETTES(reg_a6)->chest = 0x11;
    STAGE5_PALETTES(reg_a6)->belly = 0x12;
    STAGE5_PALETTES(reg_a6)->arm_guns = 0x16;
    reg_d0.w = 1;
    ARCADE_REGISTER_CALL(boss_phase_start, 0x16, 0x12, 0x11, 0x10);
}

void stage5_boss_shield_on(void) {
    STAGE5_DAMAGE(reg_a6)->shielded = 1;
}

void stage5_boss_shield_off(void) {
    STAGE5_DAMAGE(reg_a6)->shielded = 0;
}

void stage5_boss_form1_take_hits(void) {
    reg_d0.h[0] = 0xA001;
    ENTITY(reg_a6)->flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[1].flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[2].flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[3].flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[4].flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[5].flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[6].flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[13].flags.h |= reg_d0.h[0];
}

void stage5_boss_form2_take_hits(void) {
    reg_d0.h[0] = 0xA001;
    ENTITY(reg_a6)[10].flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[11].flags.h |= reg_d0.h[0];
}


void stage5_boss_form3_take_hits(void) {
    u16 *flags;
    u32 combined;

    reg_d0.h[0] = 0xA001;
    flags = (u16 *)((void *)reg_a6);
    combined = (u32)flags[0xC0] | (u32)reg_d0.h[0];
    flags[0xC0] = (u16)combined;
#ifdef DEATH_LABEL
    flags = (u16 *)((void *)reg_a6);
    combined = (u32)flags[0x100] | (u32)reg_d0.h[0];
    flags[0x100] = (u16)combined;
#endif
}

void stage5_boss_form1_stop_hits(void) {
    reg_d0.h[0] = 0x8000;
    ENTITY(reg_a6)->flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[1].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[2].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[3].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[4].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[5].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[6].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[13].flags.h = (u16) reg_d0.h[0];
}


void stage5_boss_start_damage(void) {
    STAGE5_DAMAGE(reg_a6)->stopped = 0;
}

void stage5_boss_stop_damage(void) {
    STAGE5_DAMAGE(reg_a6)->stopped = 1;
}

extern u16 g_enemies_stopped;

void stage5_boss_form1_time_limit(void) {
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
        stage5_boss_form1_defeated();
    }
}

s32 stage5_boss_form2_time_limit();
s32 stage5_boss_form3_take_damage();

void stage5_boss_form2_take_damage(void) {
    u32 big;
    u16 t;

    if (STAGE5_DAMAGE(reg_a6)->form != 1) {
        stage5_boss_form3_take_damage();
        return;
    }
    reg_d1.b[0] = ENTITY(reg_a6)[10].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[11].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) {
        goto next_1;
    }
    STAGE5_PALETTES(reg_a6)->head = 0x10;
    STAGE5_PALETTES(reg_a6)->chest = 0x11;
    STAGE5_PALETTES(reg_a6)->belly = 0x12;
    reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
    if (reg_tmp.w >= GAME_RULE(0xE000, 0x2BC00 * 40 / 100)) {
        goto next_9;
    }
    if (g_damage_blink_counter != 0) {
        goto next_9;
    }
    reg_d0.w = 0x19;
    STAGE5_PALETTES(reg_a6)->head = reg_d0.b[0];
    STAGE5_PALETTES(reg_a6)->chest = reg_d0.b[0];
    STAGE5_PALETTES(reg_a6)->belly = reg_d0.b[0];
    goto next_9;
next_1:
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[10].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[11].flags.b[1] &= reg_d0.b[0];
    *(u16 *) (reg_a6 + 0x10A) = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = STAGE5_PALETTES(reg_a6)->head;
    reg_d2.b[0] = STAGE5_PALETTES(reg_a6)->chest;
    reg_d3.b[0] = STAGE5_PALETTES(reg_a6)->belly;
    if (reg_d0.b[0] != 0x19) {
        goto next_2;
    }
    reg_d0.b[0] = 0x10;
    reg_d2.b[0] = 0x11;
    reg_d3.b[0] = 0x12;
next_2:
    reg_d0.b[0] ^= 0xF;
    STAGE5_PALETTES(reg_a6)->head = reg_d0.b[0];
    reg_d2.b[0] ^= 0xE;
    STAGE5_PALETTES(reg_a6)->chest = reg_d2.b[0];
    reg_d3.b[0] ^= 0xD;
    STAGE5_PALETTES(reg_a6)->belly = reg_d3.b[0];
    if (g_game_mode != 2) {
        goto next_3;
    }
    big = *(u16 *) (reg_a6 + 0x158);
    t = *(u16 *) (reg_a6 + 0x178);
    if ((s32) big <= (s32) t) {
        big = t;
    }
next_3:
    reg_d4.h[0] = *(u16 *) (reg_a6 + 0x158);
    t = *(u16 *) (reg_a6 + 0x178);
    if (!((s16) t < (s16) reg_d4.h[0])) {
        goto next_4;
    }
    reg_d4.h[0] = t;
next_4:
    reg_d5.w = 0x7FFF;
    *(u16 *) (reg_a6 + 0x158) = reg_d5.h[0];
    *(u16 *) (reg_a6 + 0x178) = reg_d5.h[0];
    reg_d5.h[0] -= reg_d4.h[0];
    if (*(u16 *) (reg_a6 + 0x108) != 0) {
        goto next_9;
    }
    reg_tmp.h[1] = STAGE5_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE5_BOSS(reg_a5)->hp[1];
    if (g_game_mode != 2) {
        goto next_6;
    }
    if ((s32) big <= 0x7FFF) {
        goto next_5;
    }
    reg_tmp.w += big - 0x7FFF;
    if (reg_tmp.w < 0x2A000) {
        goto next_7;
    }
    reg_tmp.w = 0x2A000;
    goto next_7;
next_5:
    reg_tmp.w -= reg_d5.w;
    goto next_7;
next_6:
    reg_tmp.w -= reg_d5.w;
next_7:
    STAGE5_BOSS(reg_a5)->hp[0] = reg_tmp.h[1];
    STAGE5_BOSS(reg_a5)->hp[1] = reg_tmp.h[0];
    if (0 <= (s64) (s32) reg_tmp.w) {
        goto next_9;
    }
    active_players_mask();
    if (reg_d0.h[0] != 0) {
        goto next_8;
    }
    reg_tmp.w = 0x200;
    STAGE5_BOSS(reg_a5)->hp[0] = reg_tmp.h[1];
    STAGE5_BOSS(reg_a5)->hp[1] = reg_tmp.h[0];
    goto next_9;
next_8:
    reg_d1.h[0] = *(u16 *) (reg_a6 + 0x10A);
    reg_d0.w = 0x80000;
    score_add();
    stage5_boss_form2_defeated();
    return;
next_9:
    stage5_boss_form2_time_limit();
}

s32 boss_part_hide();
s32 boss_kill_counter_clamp();
s32 music_stop();
s32 slowdown_turn_off();

void stage5_boss_form2_defeated(void) {
    music_stop();
    slowdown_turn_off();
    STAGE5_BOSS(reg_a5)->time_left = 0x6270;
    boss_kill_counter_clamp();
    bullet_cancel_on_boss_hit();
    stage5_boss_stop_damage();
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_tmp.w = -1U;
    STAGE5_BOSS(reg_a5)->hp[0] = (u16) reg_tmp.h[1];
    STAGE5_BOSS(reg_a5)->hp[1] = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)[10].misc.sb.user = 1;
    ENTITY(reg_a6)[10].flags.h = 0x8000;
    ENTITY(reg_a6)[11].flags.h = 0x8000;
    STAGE5_PALETTES(reg_a6)->head = 0x10;
    STAGE5_PALETTES(reg_a6)->chest = 0x11;
    STAGE5_PALETTES(reg_a6)->belly = 0x12;
    reg_d0.w = 0xE;
    boss_part_hide(0x12, 0x11, 0x10, 0x8000);
    reg_d0.w = 0xA;
    boss_part_hide();
    reg_d0.w = 3;
    boss_phase_start();
}
