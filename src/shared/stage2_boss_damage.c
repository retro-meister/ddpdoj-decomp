#include "common.h"
#include "entity.h"

void func_001CB6B0(void);
void func_001CB7E0(void);
void func_001CB890(void);
void func_001CB940(void);
void func_001CBA00();
void func_001CBB10(void);

void func_001CA720(void) {
}

s32 boss_phase_start();
s32 boss_phase_stop_all();
s32 boss_attack_stop_all();
s32 score_add_no_chain();
s32 score_add();
s32 func_001CBCE0();
s32 func_002016D0();
s32 active_players_mask();
extern u8 g_game_mode;
extern s32 g_boss_score;
extern u16 g_damage_blink_counter;

void func_001CA730(void) {
    s32 m;
    u32 cnt;
    s32 h1;
    s32 h2;
    s32 h3;

    if (ENTITY(reg_a6)[10].offset_y.h != 0) return;
    if (ENTITY(reg_a6)[10].sprite.b[1] == 0) goto next_110;
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
    ENTITY(reg_a6)[10].draw.h = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)[9].offset_y.b[0];
    if (reg_d0.b[0] != 0x19) goto next_101;
    ENTITY(reg_a6)[9].offset_y.b[0] = 0x10;
    ENTITY(reg_a6)[9].offset_y.b[1] = 0x12;
    ENTITY(reg_a6)[9].offset_x.b[1] = 0x17;
    ENTITY(reg_a6)[9].look.b.palette = 0x11;
    ENTITY(reg_a6)[9].hit_y_plus.b[1] = 0x13;
    ENTITY(reg_a6)[9].sprite.b[0] = 0x13;
    ENTITY(reg_a6)[9].look.b.size = 0xD;
next_101:
    reg_d0.b[0] = ENTITY(reg_a6)[9].offset_y.b[0];
    reg_d0.b[0] ^= 0xF;
    ENTITY(reg_a6)[9].offset_y.b[0] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].offset_y.b[1];
    reg_d0.b[0] ^= 0xD;
    ENTITY(reg_a6)[9].offset_y.b[1] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].offset_x.b[1];
    reg_d0.b[0] ^= 0x8;
    ENTITY(reg_a6)[9].offset_x.b[1] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].look.b.palette;
    reg_d0.b[0] ^= 0xE;
    ENTITY(reg_a6)[9].look.b.palette = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].hit_y_plus.b[1];
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)[9].hit_y_plus.b[1] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].sprite.b[0];
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)[9].sprite.b[0] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].look.b.size;
    reg_d0.b[0] ^= 0x12;
    ENTITY(reg_a6)[9].look.b.size = reg_d0.b[0];
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
    if (ENTITY(reg_a6)[10].offset_x.h != 0) goto next_108;
    reg_tmp2.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp2.h[0] = *(u16 *)(reg_a5 + 0x18);
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
    *(u16 *)(reg_a5 + 0x16) = reg_tmp2.h[1];
    *(u16 *)(reg_a5 + 0x18) = reg_tmp2.h[0];
next_108:
    reg_d0.h[0] = 0x7FFF;
    ENTITY(reg_a6)->hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[1].hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[6].hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[7].hp.h = reg_d0.h[0];
    goto next_110;
next_100:
    ENTITY(reg_a6)[9].offset_y.b[0] = 0x10;
    ENTITY(reg_a6)[9].offset_y.b[1] = 0x12;
    ENTITY(reg_a6)[9].offset_x.b[1] = 0x17;
    ENTITY(reg_a6)[9].look.b.palette = 0x11;
    ENTITY(reg_a6)[9].hit_y_plus.b[1] = 0x13;
    ENTITY(reg_a6)[9].sprite.b[0] = 0x13;
    ENTITY(reg_a6)[9].look.b.size = 0xD;
    reg_d2.w = 0x7700;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (reg_tmp.w > reg_d2.w) goto next_110;
    if (g_damage_blink_counter != 0) goto next_110;
    ENTITY(reg_a6)[9].offset_y.b[0] = 0x19;
    ENTITY(reg_a6)[9].offset_y.b[1] = 0x19;
    ENTITY(reg_a6)[9].offset_x.b[1] = 0x19;
    ENTITY(reg_a6)[9].look.b.palette = 0x19;
    ENTITY(reg_a6)[9].hit_y_plus.b[1] = 0x19;
    ENTITY(reg_a6)[9].sprite.b[0] = 0x19;
    ENTITY(reg_a6)[9].look.b.size = 0x19;
next_110:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if ((s32) reg_tmp.w >= 0) goto next_130;
    active_players_mask();
    if (reg_d0.h[0] != 0) goto next_120;
    reg_tmp.w = 0x200;
    *(u16 *)(reg_a5 + 0x16) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x18) = reg_tmp.h[0];
    goto next_130;
next_120:
    g_boss_score = 0x40000;
    func_001CB6B0();
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
    ENTITY(reg_a6)[10].draw.h = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)[9].offset_x.b[0];
    if (reg_d0.b[0] != 0x19) goto next_21;
    ENTITY(reg_a6)[9].offset_x.b[0] = 0x11;
next_21:
    reg_d0.b[0] = ENTITY(reg_a6)[9].offset_x.b[0];
    reg_d0.b[0] ^= 0xE;
    ENTITY(reg_a6)[9].offset_x.b[0] = reg_d0.b[0];
    if (ENTITY(reg_a6)[10].offset_x.h == 0) goto next_22;
    ENTITY(reg_a6)[2].hp.h = 0x5000;
next_22:
    if (ENTITY(reg_a6)[2].hp.sh >= 0) goto next_29;
    reg_d1.h[0] = ENTITY(reg_a6)[10].draw.h;
    reg_d0.w = 0x800;
    score_add();
    func_001CB7E0();
    goto next_29;
next_25:
    ENTITY(reg_a6)[9].offset_x.b[0] = 0x11;
    reg_d2.h[0] = 0x1800;
    if ((s32) ENTITY(reg_a6)[2].hp.h > (s32) reg_d2.h[0]) goto next_29;
    if (g_damage_blink_counter != 0) goto next_29;
    ENTITY(reg_a6)[9].offset_x.b[0] = 0x19;
next_29:
    if (ENTITY(reg_a6)[3].flags.h == 0x8000) goto next_39;
    reg_d1.w = 0x5C;
    cnt = reg_d1.b[0];
    cnt &= ENTITY(reg_a6)[3].flags.b[1];
    reg_d1.b[0] = cnt;
    if (!(cnt & 0xFF)) goto next_35;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[3].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[10].draw.h = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)[9].draw.b.priority;
    if (reg_d0.b[0] != 0x19) goto next_31;
    ENTITY(reg_a6)[9].draw.b.priority = 0x11;
next_31:
    reg_d0.b[0] = ENTITY(reg_a6)[9].draw.b.priority;
    reg_d0.b[0] ^= 0xE;
    ENTITY(reg_a6)[9].draw.b.priority = reg_d0.b[0];
    if (ENTITY(reg_a6)[10].offset_x.h == 0) goto next_32;
    ENTITY(reg_a6)[3].hp.h = 0x5000;
next_32:
    if (ENTITY(reg_a6)[3].hp.sh >= 0) goto next_39;
    reg_d1.h[0] = ENTITY(reg_a6)[10].draw.h;
    reg_d0.w = 0x800;
    score_add();
    func_001CB890();
    goto next_39;
next_35:
    ENTITY(reg_a6)[9].draw.b.priority = 0x11;
    reg_d2.h[0] = 0x1800;
    if ((s32) ENTITY(reg_a6)[3].hp.h > (s32) reg_d2.h[0]) goto next_39;
    if (g_damage_blink_counter != 0) goto next_39;
    ENTITY(reg_a6)[9].draw.b.priority = 0x19;
next_39:
    if (ENTITY(reg_a6)[4].flags.h == 0x8000) goto next_49;
    reg_d1.w = 0x5C;
    cnt = reg_d1.b[0];
    cnt &= ENTITY(reg_a6)[4].flags.b[1];
    reg_d1.b[0] = cnt;
    if (!(cnt & 0xFF)) goto next_45;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[4].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[10].draw.h = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)[9].draw.b.flip;
    if (reg_d0.b[0] != 0x19) goto next_41;
    ENTITY(reg_a6)[9].draw.b.flip = 0x12;
next_41:
    reg_d0.b[0] = ENTITY(reg_a6)[9].draw.b.flip;
    reg_d0.b[0] ^= 0xD;
    ENTITY(reg_a6)[9].draw.b.flip = reg_d0.b[0];
    if (ENTITY(reg_a6)[10].offset_x.h == 0) goto next_42;
    ENTITY(reg_a6)[4].hp.h = 0x5000;
next_42:
    if (ENTITY(reg_a6)[4].hp.sh >= 0) goto next_49;
    reg_d1.h[0] = ENTITY(reg_a6)[10].draw.h;
    reg_d0.w = 0x800;
    score_add();
    func_001CB940();
    goto next_49;
next_45:
    ENTITY(reg_a6)[9].draw.b.flip = 0x12;
    reg_d2.h[0] = 0x1800;
    if ((s32) ENTITY(reg_a6)[4].hp.h > (s32) reg_d2.h[0]) goto next_49;
    if (g_damage_blink_counter != 0) goto next_49;
    ENTITY(reg_a6)[9].draw.b.flip = 0x19;
next_49:
    if (ENTITY(reg_a6)[5].flags.h == 0x8000) goto next_59;
    reg_d1.w = 0x5C;
    cnt = reg_d1.b[0];
    cnt &= ENTITY(reg_a6)[5].flags.b[1];
    reg_d1.b[0] = cnt;
    if (!(cnt & 0xFF)) goto next_55;
    reg_d0.b[0] = 0xA3;
    ENTITY(reg_a6)[5].flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[10].draw.h = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)[9].sprite.b[1];
    if (reg_d0.b[0] != 0x19) goto next_51;
    ENTITY(reg_a6)[9].sprite.b[1] = 0x12;
next_51:
    reg_d0.b[0] = ENTITY(reg_a6)[9].sprite.b[1];
    reg_d0.b[0] ^= 0xD;
    ENTITY(reg_a6)[9].sprite.b[1] = reg_d0.b[0];
    if (ENTITY(reg_a6)[10].offset_x.h == 0) goto next_52;
    ENTITY(reg_a6)[5].hp.h = 0x5000;
next_52:
    if (ENTITY(reg_a6)[5].hp.sh >= 0) goto next_59;
    reg_d1.h[0] = ENTITY(reg_a6)[10].draw.h;
    reg_d0.w = 0x800;
    score_add();
    func_001CBB10();
    goto next_59;
next_55:
    ENTITY(reg_a6)[9].sprite.b[1] = 0x12;
    reg_d2.h[0] = 0x1800;
    if ((s32) ENTITY(reg_a6)[5].hp.h > (s32) reg_d2.h[0]) goto next_59;
    if (g_damage_blink_counter != 0) goto next_59;
    ENTITY(reg_a6)[9].sprite.b[1] = 0x19;
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
    ENTITY(reg_a6)[10].draw.h = reg_d1.h[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)[9].look.b.palette;
    if (reg_d0.b[0] != 0x19) goto next_601;
    ENTITY(reg_a6)[9].offset_y.b[0] = 0x10;
    ENTITY(reg_a6)[9].offset_y.b[1] = 0x12;
    ENTITY(reg_a6)[9].offset_x.b[1] = 0x17;
    ENTITY(reg_a6)[9].look.b.palette = 0x11;
    ENTITY(reg_a6)[9].hit_y_plus.b[1] = 0x13;
    ENTITY(reg_a6)[9].sprite.b[0] = 0x13;
    ENTITY(reg_a6)[9].look.b.size = 0xD;
    ENTITY(reg_a6)[9].offset_x.b[0] = 0x11;
    ENTITY(reg_a6)[9].draw.b.priority = 0x11;
    ENTITY(reg_a6)[9].draw.b.flip = 0x12;
    ENTITY(reg_a6)[9].sprite.b[1] = 0x12;
next_601:
    reg_d0.b[0] = ENTITY(reg_a6)[9].offset_y.b[0];
    reg_d0.b[0] ^= 0xF;
    ENTITY(reg_a6)[9].offset_y.b[0] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].offset_y.b[1];
    reg_d0.b[0] ^= 0xD;
    ENTITY(reg_a6)[9].offset_y.b[1] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].offset_x.b[1];
    reg_d0.b[0] ^= 0x8;
    ENTITY(reg_a6)[9].offset_x.b[1] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].look.b.palette;
    reg_d0.b[0] ^= 0xE;
    ENTITY(reg_a6)[9].look.b.palette = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].hit_y_plus.b[1];
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)[9].hit_y_plus.b[1] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].sprite.b[0];
    reg_d0.b[0] ^= 0xC;
    ENTITY(reg_a6)[9].sprite.b[0] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].look.b.size;
    reg_d0.b[0] ^= 0x12;
    ENTITY(reg_a6)[9].look.b.size = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].offset_x.b[0];
    reg_d0.b[0] ^= 0xE;
    ENTITY(reg_a6)[9].offset_x.b[0] = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].draw.b.priority;
    reg_d0.b[0] ^= 0xE;
    ENTITY(reg_a6)[9].draw.b.priority = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].draw.b.flip;
    reg_d0.b[0] ^= 0xD;
    ENTITY(reg_a6)[9].draw.b.flip = reg_d0.b[0];
    reg_d0.b[0] = ENTITY(reg_a6)[9].sprite.b[1];
    reg_d0.b[0] ^= 0xD;
    ENTITY(reg_a6)[9].sprite.b[1] = reg_d0.b[0];
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
    if (ENTITY(reg_a6)[10].offset_x.h != 0) goto next_608;
    reg_tmp2.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp2.h[0] = *(u16 *)(reg_a5 + 0x18);
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
    *(u16 *)(reg_a5 + 0x16) = reg_tmp2.h[1];
    *(u16 *)(reg_a5 + 0x18) = reg_tmp2.h[0];
next_608:
    reg_d0.h[0] = 0x7FFF;
    ENTITY(reg_a6)[8].hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[6].hp.h = reg_d0.h[0];
    ENTITY(reg_a6)[7].hp.h = reg_d0.h[0];
    goto next_610;
next_600:
    ENTITY(reg_a6)[9].offset_y.b[0] = 0x10;
    ENTITY(reg_a6)[9].offset_y.b[1] = 0x12;
    ENTITY(reg_a6)[9].offset_x.b[1] = 0x17;
    ENTITY(reg_a6)[9].look.b.palette = 0x11;
    ENTITY(reg_a6)[9].hit_y_plus.b[1] = 0x13;
    ENTITY(reg_a6)[9].sprite.b[0] = 0x13;
    ENTITY(reg_a6)[9].look.b.size = 0xD;
    ENTITY(reg_a6)[9].offset_x.b[0] = 0x11;
    ENTITY(reg_a6)[9].draw.b.priority = 0x11;
    ENTITY(reg_a6)[9].draw.b.flip = 0x12;
    ENTITY(reg_a6)[9].sprite.b[1] = 0x12;
next_610:
    if (ENTITY(reg_a6)[10].sprite.b[1] != 0) goto next_720;
    reg_d0.b[0] = ENTITY(reg_a6)[2].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[4].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[5].misc.b.draw_layer;
    if (reg_d0.b[0] == 4) goto next_710;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_d0.w -= 0xEFC0;
    if ((s32) reg_d0.w >= 0) goto next_720;
next_710:
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_d0.w = 1;
    boss_phase_start();
    func_001CB7E0();
    func_001CB890();
    func_001CB940();
    func_001CBB10();
    ENTITY(reg_a6)[9].sprite.b[0] = 0x13;
    ENTITY(reg_a6)[9].look.b.size = 0xD;
    ENTITY(reg_a6)[10].sprite.b[1] = 1;
    func_002016D0();
next_720:
    if (ENTITY(reg_a6)[10].sprite.b[0] != 0) goto next_730;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (!((s32) reg_tmp.w < 0x7701)) goto next_730;
    ENTITY(reg_a6)[10].sprite.b[0] = 1;
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_d0.w = 8;
    boss_phase_start();
next_730:
    func_001CBCE0();
}

s32 boss_animation_stop(s32, s32, s32, s32);
s32 func_0013F3C0();
s32 func_001CBCD0();
s32 func_00203460();
s32 slowdown_turn_off();
extern u8 g_boss_present_b1;

void func_001CB6B0(void) {
    g_boss_present_b1 |= 0x40;
    g_boss_present_b1 |= 0x80;
    slowdown_turn_off();
    func_0013F3C0();
    func_00203460();
    func_001CBCD0();
    boss_attack_stop_all();
    boss_phase_stop_all();
    reg_tmp.w = -1U;
    *(u16 *)(reg_a5 + 0x16) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x18) = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->misc.sb.draw_layer = 1;
    ENTITY(reg_a6)->flags.h = 0x8000;
    ENTITY(reg_a6)[1].flags.h = 0x8000;
    ENTITY(reg_a6)[6].flags.h = 0x8000;
    ENTITY(reg_a6)[7].flags.h = 0x8000;
    ENTITY(reg_a6)[9].offset_y.sb[0] = 0x10;
    ENTITY(reg_a6)[9].offset_y.sb[1] = 0x12;
    ENTITY(reg_a6)[9].offset_x.sb[1] = 0x17;
    ENTITY(reg_a6)[9].look.sb.palette = 0x11;
    ENTITY(reg_a6)[9].hit_y_plus.sb[1] = 0x13;
    ENTITY(reg_a6)[9].sprite.sb[0] = 0x13;
    ENTITY(reg_a6)[9].look.sb.size = 0xD;
    ENTITY(reg_a6)[9].offset_x.sb[0] = 0x11;
    ENTITY(reg_a6)[9].draw.sb.priority = 0x11;
    ENTITY(reg_a6)[9].draw.sb.flip = 0x12;
    ENTITY(reg_a6)[9].sprite.sb[1] = 0x12;
    reg_d0.w = 0xD;
    boss_animation_stop(0x13, 0x11, 0x17, 0x12);
    reg_d0.w = 2;
    boss_phase_start();
}

s32 boss_part_hide(s32, s32, s32);
s32 explosion_spawn();

void func_001CB7E0(void) {
    if (ENTITY(reg_a6)[2].misc.b.draw_layer == 0) {
        ENTITY(reg_a6)[2].hp.h = 0xFFFF;
        ENTITY(reg_a6)[2].misc.b.draw_layer = 1U;
        ENTITY(reg_a6)[2].flags.h = 0x8000;
        ENTITY(reg_a6)[9].offset_x.sb[0] = 0x11;
        reg_d0.w = 6;
        boss_part_hide(0x11, 0x8000, 1);
        reg_d0.h[0] = 0x87;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)[2].y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)[2].x.h;
        *(u16 *)(reg_a0 + 0x1E) = 8;
        *(u16 *)(reg_a0 + 0x12) = 0;
        *(u16 *)(reg_a0 + 0x14) = 0x800;
    }
}

void func_001CB890(void) {
    if (ENTITY(reg_a6)[3].misc.b.draw_layer == 0) {
        ENTITY(reg_a6)[3].hp.h = 0xFFFF;
        ENTITY(reg_a6)[3].misc.b.draw_layer = 1U;
        ENTITY(reg_a6)[3].flags.h = 0x8000;
        ENTITY(reg_a6)[9].draw.sb.priority = 0x11;
        reg_d0.w = 7;
        boss_part_hide(0x11, 0x8000, 1);
        reg_d0.h[0] = 0x84;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)[3].y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)[3].x.h;
        *(u16 *)(reg_a0 + 0x1E) = 8;
        *(u16 *)(reg_a0 + 0x12) = 0;
        *(u16 *)(reg_a0 + 0x14) = 0x800;
    }
}

s32 explosion_burst_small(void *);
s32 rng_next_unsigned();
extern u8 D_0026CA80[];

void func_001CB940(void) {
    if (ENTITY(reg_a6)[4].misc.b.draw_layer == 0) {
        ENTITY(reg_a6)[4].hp.h = 0xFFFF;
        ENTITY(reg_a6)[4].misc.b.draw_layer = 1U;
        ENTITY(reg_a6)[4].flags.h = 0x8000;
        ENTITY(reg_a6)[9].draw.sb.flip = 0x12;
        reg_d0.w = 8;
        boss_part_hide(0x12, 0x8000, 1);
        reg_a1 = D_0026CA80;
        reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
        func_001CBA00();
        rng_next_unsigned();
        reg_d1.b[0] = reg_d0.b[0];
        reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
        reg_d3.h[0] = 8;
        reg_d0.h[0] = 0;
        explosion_burst_small(reg_a6);
    }
}

void func_001CBA00(arg2)
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
        *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
        var_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(var_a2);
        *(u16 *)(reg_a0 + 2) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
        *(s16 *)(reg_a0 + 0x1E) = 8;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(u16 *)(reg_a0 + 0x1A) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        goto loop_1;
    }
}

extern u8 D_0026CAB0[];

void func_001CBB10(void) {
    if (ENTITY(reg_a6)[5].misc.b.draw_layer == 0) {
        ENTITY(reg_a6)[5].hp.h = 0xFFFF;
        ENTITY(reg_a6)[5].misc.b.draw_layer = 1U;
        ENTITY(reg_a6)[5].flags.h = 0x8000;
        ENTITY(reg_a6)[9].sprite.sb[1] = 0x12;
        reg_d0.w = 9;
        boss_part_hide(0x12, 0x8000, 1);
        reg_a1 = D_0026CAB0;
        reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
        func_001CBA00();
        rng_next_unsigned();
        reg_d1.b[0] = reg_d0.b[0];
        reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
        reg_d3.h[0] = 8;
        reg_d0.h[0] = 0;
        explosion_burst_small(reg_a6);
    }
}

void func_001CBBD0(void) {
    ENTITY(reg_a6)[10].offset_x.sh = 1;
}

void func_001CBBE0(void) {
    ENTITY(reg_a6)[10].offset_x.sh = 0;
}

void func_001CBBF0(void) {
    reg_d0.h[0] = 0xA000;
    ENTITY(reg_a6)[8].flags.h |= reg_d0.h[0];
}
