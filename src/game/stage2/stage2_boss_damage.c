#include "common.h"
#include "entity.h"
#include "explosion.h"
#include "stage2_boss.h"

void stage2_boss_defeated(void);
void stage2_boss_part2_blow_off(void);
void stage2_boss_part3_blow_off(void);
void stage2_boss_part4_blow_off(void);
void stage2_boss_explosions_from_table();
void stage2_boss_part5_blow_off(void);

void stage2_boss_damage_none(void) {
}

s32 boss_phase_start();
s32 boss_phase_stop_all();
s32 boss_attack_stop_all();
s32 score_add_no_chain();
s32 score_add();
void stage2_boss_time_limit(void);
s32 bullet_cancel_on_boss_hit();
s32 active_players_mask();
extern u8 g_game_mode;
extern s32 g_boss_score;
extern u16 g_damage_blink_counter;

void stage2_boss_take_damage(void) {
    s32 m;
    u32 cnt;
    s32 h1;
    s32 h2;
    s32 h3;

    if (STAGE2_DAMAGE(reg_a6)->stopped != 0) return;
    if (STAGE2_DAMAGE(reg_a6)->second_form == 0) goto next_110;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[6].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[7].flags.b[1];
    cnt = reg_d1.h[0] & 0x5C;
    reg_d1.h[0] = cnt;
    if (!(cnt & 0xFFFF)) goto next_100;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[6].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[7].flags.b[1] &= reg_d0.b[0];
    STAGE2_DAMAGE(reg_a6)->hit_by = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->torso;
    if (reg_d0.b[0] != 0x19) goto next_101;
    STAGE2_PALETTES(reg_a6)->torso = 0x10;
    STAGE2_PALETTES(reg_a6)->lower = 0x12;
    STAGE2_PALETTES(reg_a6)->shoulder_cannon = 0x17;
    STAGE2_PALETTES(reg_a6)->radome = 0x11;
    STAGE2_PALETTES(reg_a6)->base = 0x13;
    STAGE2_PALETTES(reg_a6)->right_side_gun = 0x13;
    STAGE2_PALETTES(reg_a6)->left_side_gun = 0xD;
next_101:
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->torso;
    reg_d0.b[0] ^= 0xF;
    STAGE2_PALETTES(reg_a6)->torso = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->lower;
    reg_d0.b[0] ^= 0xD;
    STAGE2_PALETTES(reg_a6)->lower = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->shoulder_cannon;
    reg_d0.b[0] ^= 0x8;
    STAGE2_PALETTES(reg_a6)->shoulder_cannon = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->radome;
    reg_d0.b[0] ^= 0xE;
    STAGE2_PALETTES(reg_a6)->radome = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->base;
    reg_d0.b[0] ^= 0xC;
    STAGE2_PALETTES(reg_a6)->base = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->right_side_gun;
    reg_d0.b[0] ^= 0xC;
    STAGE2_PALETTES(reg_a6)->right_side_gun = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->left_side_gun;
    reg_d0.b[0] ^= 0x12;
    STAGE2_PALETTES(reg_a6)->left_side_gun = reg_d0.b[0];
    if (g_game_mode == 2) {
        m = ENTITY(reg_a6)->hp.h;
        h1 = ENTITY(reg_a6)[1].hp.h;
        h2 = ENTITY(reg_a6)[6].hp.h;
        h3 = ENTITY(reg_a6)[7].hp.h;
        if (m > h1) goto skip_m1;
        m = h1;
skip_m1:
        if (h2 > h3) goto skip_m2;
        h2 = h3;
skip_m2:
        if (m > h2) goto skip_m3;
        m = h2;
skip_m3:;
    }
    reg_d2.w = 0x7FFF;
    reg_d2.h[0] -= ENTITY(reg_a6)->hp.h;
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= ENTITY(reg_a6)[1].hp.h;
    if (!((s32) reg_d2.w < (s32) reg_d3.w)) goto skip_d180;
    reg_d2.w = reg_d3.w;
skip_d180:
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= ENTITY(reg_a6)[6].hp.h;
    if (!((s32) reg_d2.w < (s32) reg_d3.w)) goto skip_d181;
    reg_d2.w = reg_d3.w;
skip_d181:
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= ENTITY(reg_a6)[7].hp.h;
    if (!((s32) reg_d2.w < (s32) reg_d3.w)) goto skip_d182;
    reg_d2.w = reg_d3.w;
skip_d182:
    if (STAGE2_DAMAGE(reg_a6)->shielded != 0) goto next_108;
    reg_tmp2.h[1] = STAGE2_BOSS(reg_a5)->hp[0];
    reg_tmp2.h[0] = STAGE2_BOSS(reg_a5)->hp[1];
    if (g_game_mode != 2) goto next_106;
    if (m <= 0x7FFF) goto next_105;
    m -= 0x7FFF;
    reg_tmp2.w += m;
    if ((u32) reg_tmp2.w < 0x2BDC0U) goto next_107;
    reg_tmp2.w = 0x2BDC0;
    goto next_107;
next_105:
    reg_tmp2.w -= reg_d2.w;
    goto next_107;
next_106:
    reg_tmp2.w -= reg_d2.w;
next_107:
    STAGE2_BOSS(reg_a5)->hp[0] = reg_tmp2.h[1];
    STAGE2_BOSS(reg_a5)->hp[1] = reg_tmp2.h[0];
next_108:
    reg_d0.h[0] = 0x7FFF;
    ENTITY(reg_a6)->hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[1].hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[6].hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[7].hp.h = reg_d0.h[0];
    goto next_110;
next_100:
    STAGE2_PALETTES(reg_a6)->torso = 0x10;
    STAGE2_PALETTES(reg_a6)->lower = 0x12;
    STAGE2_PALETTES(reg_a6)->shoulder_cannon = 0x17;
    STAGE2_PALETTES(reg_a6)->radome = 0x11;
    STAGE2_PALETTES(reg_a6)->base = 0x13;
    STAGE2_PALETTES(reg_a6)->right_side_gun = 0x13;
    STAGE2_PALETTES(reg_a6)->left_side_gun = 0xD;
    reg_d2.w = 0x7700;
    reg_tmp.h[1] = STAGE2_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE2_BOSS(reg_a5)->hp[1];
    if (reg_tmp.w > reg_d2.w) goto next_110;
    if (g_damage_blink_counter != 0) goto next_110;
    STAGE2_PALETTES(reg_a6)->torso = 0x19;
    STAGE2_PALETTES(reg_a6)->lower = 0x19;
    STAGE2_PALETTES(reg_a6)->shoulder_cannon = 0x19;
    STAGE2_PALETTES(reg_a6)->radome = 0x19;
    STAGE2_PALETTES(reg_a6)->base = 0x19;
    STAGE2_PALETTES(reg_a6)->right_side_gun = 0x19;
    STAGE2_PALETTES(reg_a6)->left_side_gun = 0x19;
next_110:
    reg_tmp.h[1] = STAGE2_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE2_BOSS(reg_a5)->hp[1];
    if ((s32) reg_tmp.w >= 0) goto next_130;
    active_players_mask();
    if (reg_d0.h[0] != 0) goto next_120;
    reg_tmp.w = 0x200;
    STAGE2_BOSS(reg_a5)->hp[0] = reg_tmp.h[1];
    STAGE2_BOSS(reg_a5)->hp[1] = reg_tmp.h[0];
    goto next_130;
next_120:
    g_boss_score = 0x40000;
    stage2_boss_defeated();
    return;
next_130:
    if (ENTITY(reg_a6)[2].flags.h == 0x8000) goto next_29;
    reg_d1.w = 0x5C;
    cnt = reg_d1.b[0];
    cnt &= ENTITY(reg_a6)[2].flags.b[1];
    reg_d1.b[0] = cnt;
    if (!(cnt & 0xFF)) goto next_25;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[2].flags.b[1] &= reg_d0.b[0];
    STAGE2_DAMAGE(reg_a6)->hit_by = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->right_knee_gun;
    if (reg_d0.b[0] != 0x19) goto next_21;
    STAGE2_PALETTES(reg_a6)->right_knee_gun = 0x11;
next_21:
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->right_knee_gun;
    reg_d0.b[0] ^= 0xE;
    STAGE2_PALETTES(reg_a6)->right_knee_gun = reg_d0.b[0];
    if (STAGE2_DAMAGE(reg_a6)->shielded == 0) goto next_22;
    ENTITY(reg_a6)[2].hp.h = 0x5000;
next_22:
    if (ENTITY(reg_a6)[2].hp.sh >= 0) goto next_29;
    reg_d1.h[0] = STAGE2_DAMAGE(reg_a6)->hit_by;
    reg_d0.w = 0x800;
    score_add();
    stage2_boss_part2_blow_off();
    goto next_29;
next_25:
    STAGE2_PALETTES(reg_a6)->right_knee_gun = 0x11;
    reg_d2.h[0] = 0x1800;
    if ((s32) ENTITY(reg_a6)[2].hp.h > (s32) reg_d2.h[0]) goto next_29;
    if (g_damage_blink_counter != 0) goto next_29;
    STAGE2_PALETTES(reg_a6)->right_knee_gun = 0x19;
next_29:
    if (ENTITY(reg_a6)[3].flags.h == 0x8000) goto next_39;
    reg_d1.w = 0x5C;
    cnt = reg_d1.b[0];
    cnt &= ENTITY(reg_a6)[3].flags.b[1];
    reg_d1.b[0] = cnt;
    if (!(cnt & 0xFF)) goto next_35;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[3].flags.b[1] &= reg_d0.b[0];
    STAGE2_DAMAGE(reg_a6)->hit_by = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->left_knee_gun;
    if (reg_d0.b[0] != 0x19) goto next_31;
    STAGE2_PALETTES(reg_a6)->left_knee_gun = 0x11;
next_31:
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->left_knee_gun;
    reg_d0.b[0] ^= 0xE;
    STAGE2_PALETTES(reg_a6)->left_knee_gun = reg_d0.b[0];
    if (STAGE2_DAMAGE(reg_a6)->shielded == 0) goto next_32;
    ENTITY(reg_a6)[3].hp.h = 0x5000;
next_32:
    if (ENTITY(reg_a6)[3].hp.sh >= 0) goto next_39;
    reg_d1.h[0] = STAGE2_DAMAGE(reg_a6)->hit_by;
    reg_d0.w = 0x800;
    score_add();
    stage2_boss_part3_blow_off();
    goto next_39;
next_35:
    STAGE2_PALETTES(reg_a6)->left_knee_gun = 0x11;
    reg_d2.h[0] = 0x1800;
    if ((s32) ENTITY(reg_a6)[3].hp.h > (s32) reg_d2.h[0]) goto next_39;
    if (g_damage_blink_counter != 0) goto next_39;
    STAGE2_PALETTES(reg_a6)->left_knee_gun = 0x19;
next_39:
    if (ENTITY(reg_a6)[4].flags.h == 0x8000) goto next_49;
    reg_d1.w = 0x5C;
    cnt = reg_d1.b[0];
    cnt &= ENTITY(reg_a6)[4].flags.b[1];
    reg_d1.b[0] = cnt;
    if (!(cnt & 0xFF)) goto next_45;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[4].flags.b[1] &= reg_d0.b[0];
    STAGE2_DAMAGE(reg_a6)->hit_by = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->right_shoulder_gun;
    if (reg_d0.b[0] != 0x19) goto next_41;
    STAGE2_PALETTES(reg_a6)->right_shoulder_gun = 0x12;
next_41:
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->right_shoulder_gun;
    reg_d0.b[0] ^= 0xD;
    STAGE2_PALETTES(reg_a6)->right_shoulder_gun = reg_d0.b[0];
    if (STAGE2_DAMAGE(reg_a6)->shielded == 0) goto next_42;
    ENTITY(reg_a6)[4].hp.h = 0x5000;
next_42:
    if (ENTITY(reg_a6)[4].hp.sh >= 0) goto next_49;
    reg_d1.h[0] = STAGE2_DAMAGE(reg_a6)->hit_by;
    reg_d0.w = 0x800;
    score_add();
    stage2_boss_part4_blow_off();
    goto next_49;
next_45:
    STAGE2_PALETTES(reg_a6)->right_shoulder_gun = 0x12;
    reg_d2.h[0] = 0x1800;
    if ((s32) ENTITY(reg_a6)[4].hp.h > (s32) reg_d2.h[0]) goto next_49;
    if (g_damage_blink_counter != 0) goto next_49;
    STAGE2_PALETTES(reg_a6)->right_shoulder_gun = 0x19;
next_49:
    if (ENTITY(reg_a6)[5].flags.h == 0x8000) goto next_59;
    reg_d1.w = 0x5C;
    cnt = reg_d1.b[0];
    cnt &= ENTITY(reg_a6)[5].flags.b[1];
    reg_d1.b[0] = cnt;
    if (!(cnt & 0xFF)) goto next_55;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[5].flags.b[1] &= reg_d0.b[0];
    STAGE2_DAMAGE(reg_a6)->hit_by = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->left_shoulder_gun;
    if (reg_d0.b[0] != 0x19) goto next_51;
    STAGE2_PALETTES(reg_a6)->left_shoulder_gun = 0x12;
next_51:
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->left_shoulder_gun;
    reg_d0.b[0] ^= 0xD;
    STAGE2_PALETTES(reg_a6)->left_shoulder_gun = reg_d0.b[0];
    if (STAGE2_DAMAGE(reg_a6)->shielded == 0) goto next_52;
    ENTITY(reg_a6)[5].hp.h = 0x5000;
next_52:
    if (ENTITY(reg_a6)[5].hp.sh >= 0) goto next_59;
    reg_d1.h[0] = STAGE2_DAMAGE(reg_a6)->hit_by;
    reg_d0.w = 0x800;
    score_add();
    stage2_boss_part5_blow_off();
    goto next_59;
next_55:
    STAGE2_PALETTES(reg_a6)->left_shoulder_gun = 0x12;
    reg_d2.h[0] = 0x1800;
    if ((s32) ENTITY(reg_a6)[5].hp.h > (s32) reg_d2.h[0]) goto next_59;
    if (g_damage_blink_counter != 0) goto next_59;
    STAGE2_PALETTES(reg_a6)->left_shoulder_gun = 0x19;
next_59:
    if (ENTITY(reg_a6)[8].flags.h == 0x8000) goto next_610;
    reg_d1.b[0] = ENTITY(reg_a6)[8].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[6].flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[7].flags.b[1];
    cnt = reg_d1.h[0] & 0x5C;
    reg_d1.h[0] = cnt;
    if (!(cnt & 0xFFFF)) goto next_600;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[8].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[6].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[7].flags.b[1] &= reg_d0.b[0];
    STAGE2_DAMAGE(reg_a6)->hit_by = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->radome;
    if (reg_d0.b[0] != 0x19) goto next_601;
    STAGE2_PALETTES(reg_a6)->torso = 0x10;
    STAGE2_PALETTES(reg_a6)->lower = 0x12;
    STAGE2_PALETTES(reg_a6)->shoulder_cannon = 0x17;
    STAGE2_PALETTES(reg_a6)->radome = 0x11;
    STAGE2_PALETTES(reg_a6)->base = 0x13;
    STAGE2_PALETTES(reg_a6)->right_side_gun = 0x13;
    STAGE2_PALETTES(reg_a6)->left_side_gun = 0xD;
    STAGE2_PALETTES(reg_a6)->right_knee_gun = 0x11;
    STAGE2_PALETTES(reg_a6)->left_knee_gun = 0x11;
    STAGE2_PALETTES(reg_a6)->right_shoulder_gun = 0x12;
    STAGE2_PALETTES(reg_a6)->left_shoulder_gun = 0x12;
next_601:
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->torso;
    reg_d0.b[0] ^= 0xF;
    STAGE2_PALETTES(reg_a6)->torso = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->lower;
    reg_d0.b[0] ^= 0xD;
    STAGE2_PALETTES(reg_a6)->lower = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->shoulder_cannon;
    reg_d0.b[0] ^= 0x8;
    STAGE2_PALETTES(reg_a6)->shoulder_cannon = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->radome;
    reg_d0.b[0] ^= 0xE;
    STAGE2_PALETTES(reg_a6)->radome = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->base;
    reg_d0.b[0] ^= 0xC;
    STAGE2_PALETTES(reg_a6)->base = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->right_side_gun;
    reg_d0.b[0] ^= 0xC;
    STAGE2_PALETTES(reg_a6)->right_side_gun = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->left_side_gun;
    reg_d0.b[0] ^= 0x12;
    STAGE2_PALETTES(reg_a6)->left_side_gun = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->right_knee_gun;
    reg_d0.b[0] ^= 0xE;
    STAGE2_PALETTES(reg_a6)->right_knee_gun = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->left_knee_gun;
    reg_d0.b[0] ^= 0xE;
    STAGE2_PALETTES(reg_a6)->left_knee_gun = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->right_shoulder_gun;
    reg_d0.b[0] ^= 0xD;
    STAGE2_PALETTES(reg_a6)->right_shoulder_gun = reg_d0.b[0];
    reg_d0.b[0] = STAGE2_PALETTES(reg_a6)->left_shoulder_gun;
    reg_d0.b[0] ^= 0xD;
    STAGE2_PALETTES(reg_a6)->left_shoulder_gun = reg_d0.b[0];
    if (g_game_mode == 2) {
        m = ENTITY(reg_a6)[8].hp.h;
        h1 = ENTITY(reg_a6)[6].hp.h;
        h2 = ENTITY(reg_a6)[7].hp.h;
        if (m > h1) goto skip_m4;
        m = h1;
skip_m4:
        if (m > h2) goto skip_m5;
        m = h2;
skip_m5:;
    }
    reg_d2.w = 0x7FFF;
    reg_d2.h[0] -= ENTITY(reg_a6)[8].hp.h;
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= ENTITY(reg_a6)[6].hp.h;
    if (!((s32) reg_d2.w < (s32) reg_d3.w)) goto skip_d1180;
    reg_d2.w = reg_d3.w;
skip_d1180:
    reg_d3.w = 0x7FFF;
    reg_d3.h[0] -= ENTITY(reg_a6)[7].hp.h;
    if (!((s32) reg_d2.w < (s32) reg_d3.w)) goto skip_d1181;
    reg_d2.w = reg_d3.w;
skip_d1181:
    if (STAGE2_DAMAGE(reg_a6)->shielded != 0) goto next_608;
    reg_tmp2.h[1] = STAGE2_BOSS(reg_a5)->hp[0];
    reg_tmp2.h[0] = STAGE2_BOSS(reg_a5)->hp[1];
    if (g_game_mode != 2) goto next_606;
    if (m <= 0x7FFF) goto next_605;
    m -= 0x7FFF;
    reg_tmp2.w += m;
    if ((u32) reg_tmp2.w < 0x2BDC0U) goto next_607;
    reg_tmp2.w = 0x2BDC0;
    goto next_607;
next_605:
    reg_tmp2.w -= reg_d2.w;
    goto next_607;
next_606:
    reg_tmp2.w -= reg_d2.w;
next_607:
    STAGE2_BOSS(reg_a5)->hp[0] = reg_tmp2.h[1];
    STAGE2_BOSS(reg_a5)->hp[1] = reg_tmp2.h[0];
next_608:
    reg_d0.h[0] = 0x7FFF;
    ENTITY(reg_a6)[8].hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[6].hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[7].hp.h = reg_d0.h[0];
    goto next_610;
next_600:
    STAGE2_PALETTES(reg_a6)->torso = 0x10;
    STAGE2_PALETTES(reg_a6)->lower = 0x12;
    STAGE2_PALETTES(reg_a6)->shoulder_cannon = 0x17;
    STAGE2_PALETTES(reg_a6)->radome = 0x11;
    STAGE2_PALETTES(reg_a6)->base = 0x13;
    STAGE2_PALETTES(reg_a6)->right_side_gun = 0x13;
    STAGE2_PALETTES(reg_a6)->left_side_gun = 0xD;
    STAGE2_PALETTES(reg_a6)->right_knee_gun = 0x11;
    STAGE2_PALETTES(reg_a6)->left_knee_gun = 0x11;
    STAGE2_PALETTES(reg_a6)->right_shoulder_gun = 0x12;
    STAGE2_PALETTES(reg_a6)->left_shoulder_gun = 0x12;
next_610:
    if (STAGE2_DAMAGE(reg_a6)->second_form != 0) goto next_720;
    reg_d0.b[0] = ENTITY(reg_a6)[2].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[4].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[5].misc.b.draw_layer;
    if (reg_d0.b[0] == 4) goto next_710;
    reg_d0.h[1] = STAGE2_BOSS(reg_a5)->hp[0];
    reg_d0.h[0] = STAGE2_BOSS(reg_a5)->hp[1];
    reg_d0.w -= 0xEFC0;
    if ((s32) reg_d0.w >= 0) goto next_720;
next_710:
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_d0.w = 1;
    boss_phase_start();
    stage2_boss_part2_blow_off();
    stage2_boss_part3_blow_off();
    stage2_boss_part4_blow_off();
    stage2_boss_part5_blow_off();
    STAGE2_PALETTES(reg_a6)->right_side_gun = 0x13;
    STAGE2_PALETTES(reg_a6)->left_side_gun = 0xD;
    STAGE2_DAMAGE(reg_a6)->second_form = 1;
    bullet_cancel_on_boss_hit();
next_720:
    if (STAGE2_DAMAGE(reg_a6)->rage != 0) goto next_730;
    reg_tmp.h[1] = STAGE2_BOSS(reg_a5)->hp[0];
    reg_tmp.h[0] = STAGE2_BOSS(reg_a5)->hp[1];
    if (!((s32) reg_tmp.w < 0x7701)) goto next_730;
    STAGE2_DAMAGE(reg_a6)->rage = 1;
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_d0.w = 8;
    boss_phase_start();
next_730:
    stage2_boss_time_limit();
}

s32 boss_animation_stop(s32, s32, s32, s32);
s32 func_0013F3C0();
void stage2_boss_stop_damage(void);
s32 boss_defeat_begin();
s32 slowdown_turn_off();
extern u8 g_boss_present_b1;

void stage2_boss_defeated(void) {
    g_boss_present_b1 |= 0x40;
    g_boss_present_b1 |= 0x80;
    slowdown_turn_off();
    func_0013F3C0();
    boss_defeat_begin();
    stage2_boss_stop_damage();
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_tmp.w = -1U;
    STAGE2_BOSS(reg_a5)->hp[0] = (u16) reg_tmp.h[1];
    STAGE2_BOSS(reg_a5)->hp[1] = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->misc.sb.draw_layer = 1;
    ENTITY(reg_a6)->flags.h = 0x8000;
    ENTITY(reg_a6)[1].flags.h = 0x8000;
    ENTITY(reg_a6)[6].flags.h = 0x8000;
    ENTITY(reg_a6)[7].flags.h = 0x8000;
    STAGE2_PALETTES(reg_a6)->torso = 0x10;
    STAGE2_PALETTES(reg_a6)->lower = 0x12;
    STAGE2_PALETTES(reg_a6)->shoulder_cannon = 0x17;
    STAGE2_PALETTES(reg_a6)->radome = 0x11;
    STAGE2_PALETTES(reg_a6)->base = 0x13;
    STAGE2_PALETTES(reg_a6)->right_side_gun = 0x13;
    STAGE2_PALETTES(reg_a6)->left_side_gun = 0xD;
    STAGE2_PALETTES(reg_a6)->right_knee_gun = 0x11;
    STAGE2_PALETTES(reg_a6)->left_knee_gun = 0x11;
    STAGE2_PALETTES(reg_a6)->right_shoulder_gun = 0x12;
    STAGE2_PALETTES(reg_a6)->left_shoulder_gun = 0x12;
    reg_d0.w = 0xD;
    boss_animation_stop(0x13, 0x11, 0x17, 0x12);
    reg_d0.w = 2;
    boss_phase_start();
}

s32 boss_part_hide(s32, s32, s32);
s32 explosion_spawn();

void stage2_boss_part2_blow_off(void) {
    if (ENTITY(reg_a6)[2].misc.b.draw_layer == 0) {
        ENTITY(reg_a6)[2].hp.h = 0xFFFF;
        ENTITY(reg_a6)[2].misc.b.draw_layer = 1U;
        ENTITY(reg_a6)[2].flags.h = 0x8000;
        STAGE2_PALETTES(reg_a6)->right_knee_gun = 0x11;
        reg_d0.w = 6;
        boss_part_hide(0x11, 0x8000, 1);
        reg_d0.h[0] = 0x87;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[2].y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)[2].x.h;
        EXPLOSION(reg_a0)->draw_layer = 8;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x800;
    }
}

void stage2_boss_part3_blow_off(void) {
    if (ENTITY(reg_a6)[3].misc.b.draw_layer == 0) {
        ENTITY(reg_a6)[3].hp.h = 0xFFFF;
        ENTITY(reg_a6)[3].misc.b.draw_layer = 1U;
        ENTITY(reg_a6)[3].flags.h = 0x8000;
        STAGE2_PALETTES(reg_a6)->left_knee_gun = 0x11;
        reg_d0.w = 7;
        boss_part_hide(0x11, 0x8000, 1);
        reg_d0.h[0] = 0x84;
        explosion_spawn();
        EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[3].y.h;
        EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)[3].x.h;
        EXPLOSION(reg_a0)->draw_layer = 8;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0x800;
    }
}

s32 explosion_burst_small(void *);
s32 rng_next_unsigned();
extern u8 D_0026CA80[];

void stage2_boss_part4_blow_off(void) {
    if (ENTITY(reg_a6)[4].misc.b.draw_layer == 0) {
        ENTITY(reg_a6)[4].hp.h = 0xFFFF;
        ENTITY(reg_a6)[4].misc.b.draw_layer = 1U;
        ENTITY(reg_a6)[4].flags.h = 0x8000;
        STAGE2_PALETTES(reg_a6)->right_shoulder_gun = 0x12;
        reg_d0.w = 8;
        boss_part_hide(0x12, 0x8000, 1);
        reg_a1 = D_0026CA80;
        reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
        stage2_boss_explosions_from_table();
        rng_next_unsigned();
        reg_d1.b[0] = reg_d0.b[0];
        reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
        reg_d3.h[0] = 8;
        reg_d0.h[0] = 0;
        explosion_burst_small(reg_a6);
    }
}

void stage2_boss_explosions_from_table(arg2)
    u16 *arg2;
{
    u16 *var_a2;
    u16 temp_a1;

    var_a2 = (u16 *)(arg2);
loop_1:
    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if (reg_d1.h[0] != 0xFFFF) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        explosion_spawn();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
        EXPLOSION(reg_a0)->delay = (u16) reg_d1.h[0];
        EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
        var_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(var_a2);
        EXPLOSION(reg_a0)->y = (u16) reg_d2.h[1];
        EXPLOSION(reg_a0)->x = (u16) reg_d2.h[0];
        EXPLOSION(reg_a0)->draw_layer = 8;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->move.h = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        goto loop_1;
    }
}

extern u8 D_0026CAB0[];

void stage2_boss_part5_blow_off(void) {
    if (ENTITY(reg_a6)[5].misc.b.draw_layer == 0) {
        ENTITY(reg_a6)[5].hp.h = 0xFFFF;
        ENTITY(reg_a6)[5].misc.b.draw_layer = 1U;
        ENTITY(reg_a6)[5].flags.h = 0x8000;
        STAGE2_PALETTES(reg_a6)->left_shoulder_gun = 0x12;
        reg_d0.w = 9;
        boss_part_hide(0x12, 0x8000, 1);
        reg_a1 = D_0026CAB0;
        reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
        stage2_boss_explosions_from_table();
        rng_next_unsigned();
        reg_d1.b[0] = reg_d0.b[0];
        reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
        reg_d3.h[0] = 8;
        reg_d0.h[0] = 0;
        explosion_burst_small(reg_a6);
    }
}

void stage2_boss_shield_on(void) {
    STAGE2_DAMAGE(reg_a6)->shielded = 1;
}

void stage2_boss_shield_off(void) {
    STAGE2_DAMAGE(reg_a6)->shielded = 0;
}

void stage2_boss_radome_show(void) {
    reg_d0.h[0] = 0xA000;
    ENTITY(reg_a6)[8].flags.h |= reg_d0.h[0];
}

void stage2_boss_parts_stop_hits(void) {
    reg_d0.h[0] = 0x8000;
    ENTITY(reg_a6)[2].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[3].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[4].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[5].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[6].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[7].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[8].flags.h = (u16) reg_d0.h[0];
}


void stage2_boss_part_take_hits(void) {
    (*(u32 *)&reg_a0) = (*(u32 *)&reg_a6);
    (*(u32 *)&reg_a0) += reg_d0.h[0];
    *(u16 *)(*(u32 *)&reg_a0) = 0xA000;
}

void stage2_boss_part_stop_hits(void) {
    (*(u32 *)&reg_a0) = (*(u32 *)&reg_a6);
    (*(u32 *)&reg_a0) += reg_d0.h[0];
    *(u16 *)(*(u32 *)&reg_a0) = 0x8000;
}

void stage2_boss_stop_damage(void) {
    STAGE2_DAMAGE(reg_a6)->stopped = 1;
}

extern u16 g_enemies_stopped;

void stage2_boss_time_limit(void) {
#ifdef DEATH_LABEL
    if ((g_enemies_stopped == 0) && (STAGE2_BOSS(reg_a5)->time_left == 0)) {
#else
    if ((g_enemies_stopped == 0) && (STAGE2_BOSS(reg_a5)->time_left -= 1, STAGE2_BOSS(reg_a5)->time_left == 0)) {
#endif
        active_players_mask();
        if (reg_d0.h[0] == 0) {
            STAGE2_BOSS(reg_a5)->time_left = 0x78U;
            return;
        }
        STAGE2_DAMAGE(reg_a6)->hit_by = 0;
        stage2_boss_defeated();
    }
}

u8 D_0026CA80[96] = {
    0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0xFA, 0x00, 0xFE, 0xA0, 0x04, 0x02, 0x00, 0x87, 0x00,
    0x00, 0x00, 0x00, 0xF8, 0x00, 0x04, 0x50, 0x04, 0x04, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x00, 0xFE,
    0x00, 0x00, 0x00, 0x02, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0xFA, 0x00, 0x02, 0x50, 0x04, 0x02, 0x00, 0x87, 0x00,
    0x00, 0x00, 0x00, 0xF8, 0x00, 0xFC, 0xA0, 0x04, 0x04, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x00, 0xFE,
    0x00, 0x00, 0x00, 0x02, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
