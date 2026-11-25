#include "common.h"
#include "entity.h"

void func_001D4400(void);
void func_001D4510(void);
void func_001D4540(void);

s32 boss_phase_start();
s32 boss_phase_stop_all();
s32 boss_attack_stop_all();
s32 score_add_no_chain();
s32 func_001D4630();
s32 func_002016D0();
s32 active_players_mask();
extern u8 g_game_mode;
extern s32 g_boss_score;
extern u16 g_damage_blink_counter;
extern u16 D_00299768_as_u16_a[];
extern u16 D_0029976A_as_u16_a[];
extern u16 D_0029976C[];

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define B(o) (*(u8 *)(reg_a6 + (o)))

void func_001D3F00(void) {
    s32 m0;
    s32 m1;
    s32 m2;
    s32 m3;
    s32 m4;

    if (W(0x86) != 0) return;
    reg_d1.b[0] = B(1);
    reg_d1.b[0] |= B(0x21);
    reg_d1.b[0] |= B(0x41);
    reg_d1.b[0] |= B(0xC1);
    reg_d1.b[0] |= B(0xE1);
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_10;
    B(0x67) = 0x10;
    B(0x66) = 0x11;
    B(0x69) = 0x12;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (reg_tmp.w >= 0x8C00) goto block_check;
    if (g_damage_blink_counter != 0) goto block_check;
    reg_d0.w = 0x19;
    B(0x67) = reg_d0.b[0];
    B(0x66) = reg_d0.b[0];
    B(0x69) = reg_d0.b[0];
    goto block_check;
next_10:
    reg_d0.b[0] = 0xA3;
    B(1) &= reg_d0.b[0];
    B(0x21) &= reg_d0.b[0];
    B(0x41) &= reg_d0.b[0];
    B(0xC1) &= reg_d0.b[0];
    B(0xE1) &= reg_d0.b[0];
    W(0x8A) = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = B(0x67);
    reg_d2.b[0] = B(0x66);
    reg_d3.b[0] = B(0x69);
    if (reg_d0.b[0] != 0x19) goto next_20;
    reg_d0.b[0] = 0x10;
    reg_d2.b[0] = 0x11;
    reg_d3.b[0] = 0x12;
next_20:
    reg_d0.b[0] ^= 0xF;
    B(0x67) = reg_d0.b[0];
    reg_d2.b[0] ^= 0xE;
    B(0x66) = reg_d2.b[0];
    reg_d3.b[0] ^= 0xD;
    B(0x69) = reg_d3.b[0];
    if (g_game_mode == 2) {
        m0 = W(0x18);
        m1 = W(0x38);
        m2 = W(0x58);
        m3 = W(0xD8);
        m4 = W(0xF8);
        if (m0 <= m1) m0 = m1;
        if (m2 <= m3) m2 = m3;
        if (m2 <= m4) m2 = m4;
        if (m0 <= m2) m0 = m2;
    }
    reg_d4.h[0] = W(0x18);
    if ((s16) W(0x38) < (s16) reg_d4.h[0]) reg_d4.h[0] = W(0x38);
    if ((s16) W(0x58) < (s16) reg_d4.h[0]) reg_d4.h[0] = W(0x58);
    if ((s16) W(0xD8) < (s16) reg_d4.h[0]) reg_d4.h[0] = W(0xD8);
    if ((s16) W(0xF8) < (s16) reg_d4.h[0]) reg_d4.h[0] = W(0xF8);
    reg_d5.w = 0x7FFF;
    W(0x18) = reg_d5.h[0];
    W(0x38) = reg_d5.h[0];
    W(0x58) = reg_d5.h[0];
    W(0xD8) = reg_d5.h[0];
    W(0xF8) = reg_d5.h[0];
    reg_d5.h[0] -= reg_d4.h[0];
    if (W(0x88) != 0) goto block_check;
    reg_tmp5.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp5.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (g_game_mode == 2) {
        if (m0 > 0x7FFF) {
            reg_tmp5.w += m0 - 0x7FFF;
            if (reg_tmp5.w >= 0x40C00) reg_tmp5.w = 0x40C00;
        } else {
            reg_tmp5.w -= reg_d5.w;
        }
    } else {
        reg_tmp5.w -= reg_d5.w;
    }
    *(u16 *)(reg_a5 + 0x16) = reg_tmp5.h[1];
    *(u16 *)(reg_a5 + 0x18) = reg_tmp5.h[0];
    if ((s32) reg_tmp5.w >= 0) goto block_check;
    active_players_mask();
    if (reg_d0.h[0] != 0) goto next_30;
    reg_tmp.w = 0x200;
    *(u16 *)(reg_a5 + 0x16) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x18) = reg_tmp.h[0];
    goto block_check;
next_30:
    reg_d1.h[0] = W(0x8A);
    g_boss_score = 0x50000;
    func_001D4400();
    return;
block_check:
    if (B(0x8D) != 0) goto block_tail;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_d0.w += 0xFFFEE800;
    if ((s32) reg_d0.w >= 0) goto block_tail;
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_d0.w = 9;
    boss_phase_start();
    func_001D4540();
    func_001D4510();
    B(0x8D) = 1;
    D_00299768_as_u16_a[0] = 1;
    D_0029976A_as_u16_a[0] = 1;
    D_0029976C[0] = 1;
    func_002016D0();
block_tail:
    func_001D4630();
}

s32 boss_animation_stop();
s32 func_0013F3C0();
s32 func_001D4620();
s32 func_00203460();
s32 slowdown_turn_off();
extern u8 g_boss_present_b1;

void func_001D4400() {
    g_boss_present_b1 |= 0x40;
    g_boss_present_b1 |= 0x80;
    slowdown_turn_off();
    func_0013F3C0();
    func_00203460();
    func_001D4620();
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_d0.w = 2;
    boss_animation_stop();
    reg_d0.w = 3;
    boss_animation_stop();
    ENTITY(reg_a6)[5].hit_x_minus.h = 1;
    ENTITY(reg_a6)[5].hp.h = 1;
    reg_tmp.w = -1U;
    *(u16 *)(reg_a5 + 0x16) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x18) = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->misc.sb.draw_layer = 1;
    ENTITY(reg_a6)->flags.h = 0x8000;
    ENTITY(reg_a6)[1].flags.h = 0x8000;
    ENTITY(reg_a6)[2].flags.h = 0x8000;
    ENTITY(reg_a6)[6].flags.h = 0x8000;
    ENTITY(reg_a6)[7].flags.h = 0x8000;
    ENTITY(reg_a6)[3].offset_y.sb[1] = 0x10;
    ENTITY(reg_a6)[3].offset_y.sb[0] = 0x11;
    ENTITY(reg_a6)[3].offset_x.sb[1] = 0x12;
    reg_d0.w = 1;
    boss_phase_start();
}

void func_001D4510(void) {
    u8 *p = reg_a6 + 0xAF; if (*p == 0) { *p = 1; return; }
}

struct UnkDataD28E450 {
    u8 pad_00[0x88];
    s16 unk88;
};

extern struct UnkDataD28E450 *reg_a6_as_UnkDataD28E450_p;

void func_001D4540(void) {
    reg_a6_as_UnkDataD28E450_p->unk88 = 1;
}

void func_001D4550(void) {
    ENTITY(reg_a6)[4].offset_x.sh = 0;
}

void func_001D4560(void) {
    reg_d0.h[0] = 0xA001;
    ENTITY(reg_a6)->flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[1].flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[2].flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[6].flags.h |= reg_d0.h[0];
    ENTITY(reg_a6)[7].flags.h |= reg_d0.h[0];
}

void func_001D45D0(void) {
    reg_d0.h[0] = 0x8000;
    ENTITY(reg_a6)->flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[1].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[2].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[6].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[7].flags.h = (u16) reg_d0.h[0];
}
