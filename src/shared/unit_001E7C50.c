#include "common.h"
#include "entity.h"

void func_001E7C90(void);
void func_001E8480(void);
void func_001E8580(void);
void func_001E8640(void);
void func_001E8790(void);
void func_001E87A0(void);

void func_001E7C50(void) {
}


void func_001E7C60(void) {
    if (ENTITY(reg_a6)[11].offset_y.h == 0) {
        func_001E7C90();
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

void func_001E7C90(void) {
    s32 func_00203400();
    s32 hp;
    s32 mid;
    s32 low;

    g_enemy_signal_7 = 0;
    if (g_enemy_signal_8 == 0) goto next_100_chk;
    reg_d1.h[0] = g_enemy_signal_9;
    ENTITY(reg_a6)[11].draw.h = reg_d1.h[0];
    goto next_100_set;
next_100_chk:
    reg_d1.b[0] = ENTITY(reg_a6)[1].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[2].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[3].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] == 0) goto next_100;
    ENTITY(reg_a6)[11].draw.h = reg_d1.h[0];
next_100_set:
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[2].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[3].flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)[10].offset_y.b[1];
    if (reg_d0.b[0] != 0x19) goto next_r_pal;
    ENTITY(reg_a6)[10].offset_y.b[1] = 0x13;
    ENTITY(reg_a6)[10].offset_y.b[0] = 0x14;
    ENTITY(reg_a6)[10].offset_x.b[1] = 0x15;
    ENTITY(reg_a6)[10].offset_x.b[0] = 0x15;
    ENTITY(reg_a6)[10].draw.b.priority = 0x15;
    ENTITY(reg_a6)[10].draw.b.flip = 0x14;
next_r_pal:
    reg_d0.b[0] = ENTITY(reg_a6)[10].offset_y.b[1];
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)[10].offset_y.b[1] = reg_d0.b[0];
    if (ENTITY(reg_a6)[2].misc.b.draw_layer != 0) goto next_dm_skip;
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
next_dm_skip:
    reg_d0.b[0] = ENTITY(reg_a6)[10].draw.b.flip;
    reg_d0.b[0] ^= 0xB;
    ENTITY(reg_a6)[10].draw.b.flip = reg_d0.b[0];
    if (g_game_mode != 2) goto next_max_end;
    hp = ENTITY(reg_a6)[1].hp.h;
    mid = ENTITY(reg_a6)[2].hp.h;
    low = ENTITY(reg_a6)[3].hp.h;
    if (hp > (s32)mid) goto next_max1;
    hp = mid;
next_max1:
    if (hp > (s32)low) goto next_max_end;
    hp = low;
next_max_end:
    reg_d2.w = 0x7FFF;
    reg_d2.h[0] -= ENTITY(reg_a6)[1].hp.h;
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= ENTITY(reg_a6)[2].hp.h;
    if (!((s32)reg_d2.w < (s32)reg_d3.w)) goto next_dmg0;
    reg_d2.w = reg_d3.w;
next_dmg0:
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= ENTITY(reg_a6)[3].hp.h;
    if (!((s32)reg_d2.w < (s32)reg_d3.w)) goto next_dmg1;
    reg_d2.w = reg_d3.w;
next_dmg1:
    reg_d0.w = 0;
    reg_d0.h[0] = g_enemy_signal_8;
    if (reg_d0.h[0] == 0) goto next_dec_cut;
    reg_d0.h[0] = (s32)(reg_d0.h[0] & 0xFFFF) >> 1;
    g_enemy_signal_8 = 0;
    reg_d2.w = reg_d0.w;
    if (g_bomb_entities_as_s16_a[0] >= 0) goto next_flag7;
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
    if (reg_d2.w == 0) goto next_div;
    hp = reg_d2.w / 6;
next_div:
    hp += 0x7FFF;
#endif
next_flag7:
    g_enemy_signal_7 = 1;
next_dec_cut:
    if (ENTITY(reg_a6)[11].offset_x.h != 0) goto next_nodec;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (g_game_mode != 2) goto next_sub2;
    if (hp <= 0x7FFF) goto next_sub1;
    reg_tmp.w += hp - 0x7FFF;
    if (reg_tmp.w < 0x46000) goto next_store;
    reg_tmp.w = 0x46000;
    goto next_store;
next_sub1:
    reg_tmp.w -= reg_d2.w;
    goto next_store;
next_sub2:
    reg_tmp.w -= reg_d2.w;
next_store:
    *(u16 *)(reg_a5 + 0x16) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x18) = reg_tmp.h[0];
next_nodec:
    reg_d0.h[0] = 0x7FFF;
    ENTITY(reg_a6)[1].hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[2].hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[3].hp.h = reg_d0.h[0];
    goto next_110;
next_100:
    ENTITY(reg_a6)[10].offset_y.b[1] = 0x13;
    ENTITY(reg_a6)[10].offset_y.b[0] = 0x14;
    ENTITY(reg_a6)[10].offset_x.b[1] = 0x15;
    ENTITY(reg_a6)[10].offset_x.b[0] = 0x15;
    ENTITY(reg_a6)[10].draw.b.priority = 0x15;
    ENTITY(reg_a6)[10].draw.b.flip = 0x14;
    reg_d2.w = 0xC400;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (reg_tmp.w > reg_d2.w) goto next_110;
    if (g_damage_blink_counter != 0) goto next_110;
    reg_d0.w = 0x19;
    ENTITY(reg_a6)[10].offset_y.b[1] = reg_d0.b[0];
    ENTITY(reg_a6)[10].offset_y.b[0] = reg_d0.b[0];
    ENTITY(reg_a6)[10].offset_x.b[1] = reg_d0.b[0];
    ENTITY(reg_a6)[10].offset_x.b[0] = reg_d0.b[0];
    ENTITY(reg_a6)[10].draw.b.priority = reg_d0.b[0];
    ENTITY(reg_a6)[10].draw.b.flip = reg_d0.b[0];
next_110:
    reg_d1.b[0] = ENTITY(reg_a6)[4].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] == 0) goto next_hr_100;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[4].flags.b[1] &= reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[10].sprite.b[1];
    if (reg_d0.b[0] != 0x19) goto next_hr_r_pal;
    ENTITY(reg_a6)[10].sprite.b[1] = 0x13;
next_hr_r_pal:
    reg_d0.b[0] = ENTITY(reg_a6)[10].sprite.b[1];
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)[10].sprite.b[1] = reg_d0.b[0];
    reg_d0.h[0] = 0x7FFF;
    reg_d0.h[0] -= ENTITY(reg_a6)[4].hp.h;
    if (!((s16)g_enemy_signal_8 < (s16)reg_d0.h[0])) goto next_hr_kangen;
    g_enemy_signal_8 = reg_d0.h[0];
    g_enemy_signal_9 = reg_d1.h[0];
next_hr_kangen:
    ENTITY(reg_a6)[4].hp.h = 0x7FFF;
    goto next_hr_110;
next_hr_100:
    ENTITY(reg_a6)[10].sprite.b[1] = 0x13;
next_hr_110:
    reg_d1.b[0] = ENTITY(reg_a6)[5].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] == 0) goto next_hl_100;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[5].flags.b[1] &= reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[10].sprite.b[0];
    if (reg_d0.b[0] != 0x19) goto next_hl_r_pal;
    ENTITY(reg_a6)[10].sprite.b[0] = 0x13;
next_hl_r_pal:
    reg_d0.b[0] = ENTITY(reg_a6)[10].sprite.b[0];
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)[10].sprite.b[0] = reg_d0.b[0];
    reg_d0.h[0] = 0x7FFF;
    reg_d0.h[0] -= ENTITY(reg_a6)[5].hp.h;
    if (!((s16)g_enemy_signal_8 < (s16)reg_d0.h[0])) goto next_hl_kangen;
    g_enemy_signal_8 = reg_d0.h[0];
    g_enemy_signal_9 = reg_d1.h[0];
next_hl_kangen:
    ENTITY(reg_a6)[5].hp.h = 0x7FFF;
    goto next_hl_110;
next_hl_100:
    ENTITY(reg_a6)[10].sprite.b[0] = 0x13;
next_hl_110:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if ((s32)reg_tmp.w >= 0) goto next_death_chk;
    func_00203400();
    if (reg_d0.h[0] != 0) goto next_elix;
    reg_tmp.w = 0x200;
    *(u16 *)(reg_a5 + 0x16) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x18) = reg_tmp.h[0];
    goto next_death_chk;
next_elix:
    reg_d1.h[0] = ENTITY(reg_a6)[11].draw.h;
    reg_d0.w = 0x60000;
    score_add();
    g_boss_score = 0x60000;
    func_001E8480();
    return;
next_death_chk:
    if (ENTITY(reg_a6)[11].sprite.b[1] != 0) goto next_mode2_chk;
#ifndef DEATH_LABEL
    *(u16 *)(reg_a5 + 0x1A) -= 1;
#endif
    if (*(u16 *)(reg_a5 + 0x1A) == 0) goto next_mode2_set;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (!((s32)reg_tmp.w < 0x23000)) goto next_mode2_chk;
next_mode2_set:
    ENTITY(reg_a6)[11].sprite.b[1] = 1;
    boss_attack_stop_all();
    boss_phase_stop_all();
    func_002016D0();
    reg_d0.w = 1;
    boss_phase_start();
    ENTITY(reg_a6)[2].misc.b.draw_layer = 1;
next_mode2_chk:
    if (ENTITY(reg_a6)[11].sprite.b[0] != 0) goto next_hakyo_chk;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (!((s32)reg_tmp.w < 0xC400)) goto next_hakyo_chk;
    ENTITY(reg_a6)[11].sprite.b[0] = 1;
    g_enemy_signal_c = 1;
    reg_d0.w = 5;
    boss_phase_stop();
    reg_d0.w = 6;
    boss_phase_start();
    func_001E8580();
    func_001E8640();
    func_002016D0();
next_hakyo_chk:
    func_001E87A0();
}

s32 func_0013F3C0();
s32 func_00201490();
s32 func_00203460();
s32 slowdown_turn_off();
extern u8 g_boss_present_b1;

void func_001E8480(void) {
    g_boss_present_b1 |= 0x40;
    g_enemy_signal_c = 1;
    g_boss_present_b1 |= 0x80;
    slowdown_turn_off();
    func_0013F3C0();
    func_00203460();
    func_00201490();
    func_001E8790();
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_tmp.w = -1U;
    *(u16 *)(reg_a5 + 0x16) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x18) = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)[1].misc.sb.draw_layer = 1;
    ENTITY(reg_a6)[1].flags.h = 0x8000;
    ENTITY(reg_a6)[10].offset_y.sb[1] = 0x13;
    ENTITY(reg_a6)[10].offset_y.sb[0] = 0x14;
    ENTITY(reg_a6)[10].offset_x.sb[1] = 0x15;
    ENTITY(reg_a6)[10].offset_x.sb[0] = 0x15;
    ENTITY(reg_a6)[10].draw.sb.priority = 0x15;
    ENTITY(reg_a6)[10].draw.sb.flip = 0x14;
    func_001E8580();
    func_001E8640();
    reg_d0.w = 2;
    boss_phase_start();
}

s32 boss_part_hide(s32, s32, s32);
s32 explosion_burst_small(void *);
s32 sfx_explosion_ground_medium();
s32 func_001E58E0();
s32 rng_next_unsigned();
extern u8 D_0026F640[];

void func_001E8580(void) {
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
        func_001E58E0();
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

void func_001E8640(void) {
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
        func_001E58E0();
        rng_next_unsigned();
        reg_d1.b[0] = reg_d0.b[0];
        reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
        reg_d3.h[0] = 0x10;
        reg_d0.h[0] = 0;
        explosion_burst_small(reg_a6);
    }
}

void func_001E8700(void) {
    ENTITY(reg_a6)[11].offset_x.sh = 1;
}

void func_001E8710(void) {
    ENTITY(reg_a6)[11].offset_x.sh = 0;
}

void func_001E8720(void) {
}

void func_001E8730(void) {
    reg_a0 = reg_a6;
    reg_a0 += reg_d0.h[0];
    *(u16 *)reg_a0 = 0xA001;
}

void func_001E8760(void) {
    reg_a0 = reg_a6;
    reg_a0 += reg_d0.h[0];
    *(u16 *)reg_a0 = 0x8000;
}

void func_001E8790(void) {
    ENTITY(reg_a6)[11].offset_y.sh = 1;
}

extern u16 g_enemies_stopped;

void func_001E87A0(void) {
    void func_00203400(void);
#ifdef DEATH_LABEL
    if ((g_enemies_stopped == 0) && (ENTITY(reg_a6)[11].sprite.b[1] != 0) && (*(u16 *)(reg_a5 + 0x1C) == 0)) {
#else
    if ((g_enemies_stopped == 0) && (ENTITY(reg_a6)[11].sprite.b[1] != 0) && (*(u16 *)(reg_a5 + 0x1C) -= 1, *(u16 *)(reg_a5 + 0x1C) == 0)) {
#endif
        func_00203400();
        if (reg_d0.h[0] == 0) {
            *(u16 *)(reg_a5 + 0x1C) = 0x78U;
            return;
        }
        ENTITY(reg_a6)[11].draw.sh = 0;
        func_001E8480();
    }
}
