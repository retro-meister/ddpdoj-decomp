#include "common.h"
#include "entity.h"


void func_001CBC10(void) {
    reg_d0.h[0] = 0x8000;
    ENTITY(reg_a6)[2].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[3].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[4].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[5].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[6].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[7].flags.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[8].flags.h = (u16) reg_d0.h[0];
}

extern u32 reg_a6_as_u32;
extern u32 reg_a0_as_u32;

void func_001CBC70(void) {
    reg_a0_as_u32 = reg_a6_as_u32;
    reg_a0_as_u32 += reg_d0.h[0];
    *(u16 *)reg_a0_as_u32 = 0xA000;
}

void func_001CBCA0(void) {
    reg_a0_as_u32 = reg_a6_as_u32;
    reg_a0_as_u32 += reg_d0.h[0];
    *(u16 *)reg_a0_as_u32 = 0x8000;
}

void func_001CBCD0(void) {
    ENTITY(reg_a6)[10].offset_y.sh = 1;
}

s32 func_001CB6B0();
void func_00203400(void);
extern u16 g_enemies_stopped;

void func_001CBCE0(void) {
#ifdef DEATH_LABEL
    if ((g_enemies_stopped == 0) && (*(u16 *)(reg_a5 + 0x1A) == 0)) {
#else
    if ((g_enemies_stopped == 0) && (*(u16 *)(reg_a5 + 0x1A) -= 1, *(u16 *)(reg_a5 + 0x1A) == 0)) {
#endif
        func_00203400();
        if (reg_d0.h[0] == 0) {
            *(u16 *)(reg_a5 + 0x1A) = 0x78U;
            return;
        }
        ENTITY(reg_a6)[10].draw.sh = 0;
        func_001CB6B0();
    }
}

void enemy_set_entity_count(s32);

void func_001CBD50(void) {
    enemy_set_entity_count(2);
}


s32 func_0013B2E0();
s32 enemy_set_task_work();
s32 enemy_init_entities();
s32 enemy_path_start();
s32 sfx_heli_start();
s32 aim256_at_player();
extern u16 D_002590F0[];
extern u8 D_00263000[];
extern u8 D_00263030[];
extern u8 D_002630D0[];
extern s16 g_enemy_signal_0_as_s16;
extern u16 g_loop;
extern u16 g_stage;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s8 enemy_move_end_requested;

void func_001CBD60(void) {
    reg_a0 = D_00263030;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0 = D_00263000;
    reg_d0.w = 0x14;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
        reg_d0.h[0] &= 0xE7FF;
        reg_d2.h[0] = ENTITY(reg_a6)[1].flags.h;
        reg_d2.h[0] &= 0xDFFE;
        reg_d0.h[0] |= reg_d2.h[0];
        ENTITY(reg_a6)[1].flags.h = (u16) reg_d0.h[0];
        reg_a3 = (u8 *)(D_002590F0);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0xAC0;
        reg_d1.h[0] += 0x780;
        aim256_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d1.b[0] *= 4;
        }
        *(u8 *)(reg_a5 + 0x2C) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0xF8;
        reg_d1.h[0] >>= 1;
        *(u16 *)(reg_a5 + 0x28) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
        *(u16 *)(reg_a5 + 0x2A) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0xAC0;
        reg_d1.h[0] += 0x7FFF + 0x7881;
        aim256_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d1.b[0] *= 4;
        }
        *(u8 *)(reg_a5 + 0x32) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0xF8;
        reg_d1.h[0] >>= 1;
        *(u16 *)(reg_a5 + 0x2E) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
        *(u16 *)(reg_a5 + 0x30) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d0.b[0] = 0x10;
        reg_d1.b[0] = 2;
        reg_d2.b[0] = 0x18;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 2;
            reg_d2.b[0] = 0x18;
        }
        *(u8 *)(reg_a5 + 0x35) = (u8) reg_d0.b[0];
        *(u8 *)(reg_a5 + 0x34) = (u8) reg_d1.b[0];
        *(u8 *)(reg_a5 + 0x3D) = (u8) reg_d2.b[0];
        reg_a0 = D_002630D0;
        func_0013B2E0();
        g_enemy_signal_0_as_s16 = 1;
        sfx_heli_start();
        D_00299768[0] = 1;
        if (g_loop != 0) {
            D_0029976A[0] = 1;
        }
    }
}

typedef void (*Fn)();

extern u8 D_002590F0_as_u8_a[];
extern u8 D_002594F0_as_u8_a[];
s32 bullet_fire256_fixed();
s32 bullet_fire256_fast();
s32 bullet_fire256_2way();
s32 bullet_fire256_3way();
s32 bullet_fire256();
s32 func_00136980();
s32 explosion_spawn();
s32 enemy_hitbox_debug_draw();
s32 enemy_remove();
s32 enemy_path_step();
s32 enemy_switch_target_player();
s32 sfx_explosion_extra_1();
s32 sfx_beam_loop_stop();
s32 entity_draw_layer1();
s32 entity_draw_layer5();
s32 sprite_draw_layer1();
s32 sprite_draw_layer4();
s32 sprite_draw_layer5();
s32 score_add_no_chain();
s32 score_add();
s32 func_002010D0();
s32 rng_next_unsigned();
s32 func_00201800();
s32 func_002025E0();
s32 direction256_between();
s32 vibration_start_pad1(s32, s32);
s32 vibration_start_pad2(s32, s32);
extern u16 D_00259970[];
extern u16 D_00262A50_as_u16_a[];
extern u16 D_00263100[];
extern u16 D_00263120[];
extern u16 D_00263180[];
extern u16 D_00263240[];
extern u16 D_00263270[];
extern u16 D_00263280[];
extern u16 D_00263290[];
extern u8 g_slowdown_timer;
extern u16 D_0028E3EC;
extern u16 g_game_frame;
extern u16 g_enemy_signal_0;
extern u16 g_bullets_blocked;
extern u16 g_scroll_line;
extern u16 g_damage_blink_counter;
extern u16 g_rank_1_16;
extern u16 g_rank_5_16;
extern u16 g_side_scroll_x[];
extern u16 g_player2_as_u16_a[];
extern u16 g_player1_as_u16_a[];

void func_001CC0A0(void) {
    u32 cnt;
    u16 val;
    u8 bits;
    u8 *ptr;

    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto skip_1;
    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] &= 0xE7FF;
    reg_d2.h[0] = ENTITY(reg_a6)[1].flags.h;
    reg_d2.h[0] &= 0xDFFE;
    reg_d0.h[0] |= reg_d2.h[0];
    ENTITY(reg_a6)[1].flags.h = reg_d0.h[0];
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x1A00;
    reg_d0.h[0] += g_side_scroll_x[0];
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x9400;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9400;
    if (reg_tmp.h[1] != 0) goto next_20;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7A00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] += 0xE00;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7A00;
    if (reg_tmp.h[1] == 0) goto next_30;
next_20:
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_40;
    g_enemy_signal_0 = 0;
    sfx_beam_loop_stop();
    enemy_remove();
    return;
next_30:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_40:
    if (ENTITY(reg_a6)->misc.b.user != 0) goto next_45;
    reg_tmp.w = 0xB000;
    ENTITY(reg_a6)[1].attr.h = reg_tmp.h[1];
    ENTITY(reg_a6)[1].misc.h = reg_tmp.h[0];
next_45:
    ENTITY(reg_a6)[1].y.h = ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[1].x.h = ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= ENTITY(reg_a6)[1].flags.b[1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
    reg_d3.b[0] = ENTITY(reg_a6)[2].offset_x.b[1];
    reg_d5.b[0] = ENTITY(reg_a6)[2].draw.b.priority;
    if (!((s32) ENTITY(reg_a6)->hp.h < 0x2C00)) goto next_90;
    if (g_damage_blink_counter != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    reg_d0.h[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    ENTITY(reg_a6)[1].flags.b[1] &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    reg_d3.b[0] = ENTITY(reg_a6)[2].offset_y.b[1];
    reg_d5.b[0] = ENTITY(reg_a6)[2].offset_y.b[0];
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
    reg_d3.b[0] = ENTITY(reg_a6)[2].offset_x.b[1];
    reg_d5.b[0] = ENTITY(reg_a6)[2].draw.b.priority;
next_60:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d2.b[0] = ENTITY(reg_a6)[2].offset_x.b[0];
    reg_d3.b[0] ^= reg_d2.b[0];
    reg_d2.b[0] = ENTITY(reg_a6)[2].draw.b.flip;
    reg_d5.b[0] ^= reg_d2.b[0];
    reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
    if (!((s16) ENTITY(reg_a6)[1].hp.h < (s16) reg_d4.h[0])) goto next_80;
    reg_d4.h[0] = ENTITY(reg_a6)[1].hp.h;
next_80:
    reg_d6.w = 0x7FFF;
    ENTITY(reg_a6)->hp.h = reg_d6.h[0];
    ENTITY(reg_a6)[1].hp.h = reg_d6.h[0];
    reg_d6.h[0] -= reg_d4.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)[1].attr.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[1].misc.h;
    reg_tmp.w -= reg_d6.w;
    ENTITY(reg_a6)[1].attr.h = reg_tmp.h[1];
    ENTITY(reg_a6)[1].misc.h = reg_tmp.h[0];
    if ((s32) reg_tmp.w < 0) goto next_700;
next_90:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    ENTITY(reg_a6)[2].offset_y.b[1] = reg_d3.b[0];
    ENTITY(reg_a6)[2].offset_y.b[0] = reg_d5.b[0];
    reg_d0.h[1] = ENTITY(reg_a6)[1].attr.h;
    reg_d0.h[0] = ENTITY(reg_a6)[1].misc.h;
    func_00136980();
    reg_tmp.b[0] = ENTITY(reg_a6)[1].offset_y.b[1];
    ENTITY(reg_a6)[1].offset_y.b[1] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_120;
    ENTITY(reg_a6)[1].offset_y.b[1] = ENTITY(reg_a6)[1].offset_y.b[0];
    reg_d0.h[0] = ENTITY(reg_a6)[1].offset_x.h;
    reg_a0 = (u8 *) D_00263100;
    switch (reg_d0.h[0]) { case 0: goto block_zero; }
    val = *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1));
    goto block_join;
block_zero:
    val = *(u16 *)reg_a0;
block_join:
    ENTITY(reg_a6)[1].draw.h = val;
    ENTITY(reg_a6)[1].sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)[1].offset_x.h -= 4;
    if ((s16) ENTITY(reg_a6)[1].offset_x.h >= 0) goto next_120;
    ENTITY(reg_a6)[1].offset_x.h = 0x1C;
next_120:
    if (g_enemies_stopped != 0) goto next_500;
    if (g_bullets_blocked != 0) goto next_500;
    if (g_enemies_stopped != 0) goto next_500;
    if (g_bullets_blocked != 0) goto next_500;
    if (*(u16 *)(reg_a5 + 0x18) != 0) goto next_400;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto next_400;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    if (reg_d0.h[0] != 0) goto next_200;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x35);
    *(u16 *)(reg_a5 + 0x1A) = 1;
    goto next_400;
next_200:
    if ((reg_d0.h[0] & 0xFFFF) != 1) goto next_220;
    reg_tmp.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    ENTITY(reg_a6)[1].move.b.speed -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    ENTITY(reg_a6)[1].move.b.speed = ENTITY(reg_a6)[1].move.b.dir;
    ENTITY(reg_a6)[1].look.h += 4;
    if (ENTITY(reg_a6)[1].look.h != 0x5C) goto next_400;
    *(u16 *)(reg_a5 + 0x1A) = 2;
    goto next_400;
next_220:
    if ((reg_d0.h[0] & 0xFFFF) != 2) goto next_300;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    reg_d0.h[0] = 0x10;
    reg_d1.h[0] = g_rank_1_16;
    reg_d1.h[0] >>= 2;
    reg_d0.b[0] -= reg_d1.b[0];
    *(u8 *)(reg_a5 + 0x1F) = reg_d0.b[0];
    reg_a0 = (u8 *) g_player1_as_u16_a;
    reg_a1 = (u8 *) g_player2_as_u16_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_240;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_240:
    if (*(s16 *)reg_a0 < 0) goto next_260;
    if (*(s16 *)reg_a1 >= 0) goto next_400;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_260:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xF800;
    direction256_between();
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    reg_a0 = (u8 *) D_00263240;
    reg_a1 = (u8 *) D_00262A50_as_u16_a;
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.w = 0xB;
loop_280:
    func_002010D0();
    reg_d1.b[0] = (s8) reg_d1.b[0] * 8;
    reg_d1.b[0] += reg_d6.b[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x3A);
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = 0x13;
    reg_d5.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d5.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a1 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a1 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d5.w;
    if (!(reg_d7.h[0] & 1)) goto next_285;
    bullet_fire256_2way();
    goto next_290;
next_285:
    bullet_fire256_fixed();
next_290:
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_280;
    enemy_switch_target_player();
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
    *(u8 *)(reg_a5 + 0x21) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    *(u8 *)(reg_a5 + 0x21) = *(u8 *)(reg_a5 + 0x20);
    reg_d0.h[0] = 0x50;
    reg_d0.h[0] -= g_rank_5_16;
    *(u8 *)(reg_a5 + 0x1F) = reg_d0.b[0];
    *(u16 *)(reg_a5 + 0x1A) = 3;
    goto next_400;
next_300:
    reg_tmp.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    ENTITY(reg_a6)[1].move.b.speed -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_400;
    ENTITY(reg_a6)[1].move.b.speed = ENTITY(reg_a6)[1].move.b.dir;
    ENTITY(reg_a6)[1].look.h -= 4;
    if (ENTITY(reg_a6)[1].look.h != 0) goto next_400;
    *(u16 *)(reg_a5 + 0x1A) = 0;
    *(u16 *)(reg_a5 + 0x18) = 1;
next_400:
    reg_d0.h[0] = ENTITY(reg_a6)[1].look.h;
    reg_a0 = (u8 *) D_00263180;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    ENTITY(reg_a6)[1].hit_y_plus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)[1].hit_y_minus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)[1].hit_x_plus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)[1].hit_x_minus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a0 = (u8 *) g_player1_as_u16_a;
    reg_a1 = (u8 *) g_player2_as_u16_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_420;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_420:
    if (*(s16 *)reg_a0 < 0) goto next_440;
    if (*(s16 *)reg_a1 >= 0) goto next_500;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_440:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d5.w = 4;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x25);
    if (*(u8 *)(reg_a5 + 0x24) != reg_d0.b[0]) goto next_460;
    reg_d5.w = 1;
next_460:
    reg_a3 = (u8 *)D_002590F0_as_u8_a;
    bits = ENTITY(reg_a6)->flags.b[0];
    if (bits & 0x40) {
        ENTITY(reg_a6)->flags.b[0] = bits & 0xBF;
        goto next_480;
    }
    ENTITY(reg_a6)->flags.b[0] = bits | 0x40;
    reg_d0.h[0] += 0xAC0;
    reg_d1.h[0] += 0x780;
    direction256_between();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
    func_002025E0();
    *(u16 *)(reg_a5 + 0x2C) = reg_d1.h[0];
    reg_d1.b[0] += 4;
    reg_d1.h[0] &= 0xF8;
    reg_d1.h[0] >>= 1;
    *(u16 *)(reg_a5 + 0x28) = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    *(u16 *)(reg_a5 + 0x2A) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    goto next_500;
next_480:
    reg_d0.h[0] += 0xAC0;
    reg_d1.h[0] += 0xF880;
    direction256_between();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x32);
    func_002025E0();
    *(u16 *)(reg_a5 + 0x32) = reg_d1.h[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] &= 0xF8;
    reg_d1.h[0] >>= 1;
    *(u16 *)(reg_a5 + 0x2E) = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    *(u16 *)(reg_a5 + 0x30) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
next_500:
    reg_a2 = (u8 *) entity_draw_layer5;
    reg_a3 = (u8 *) sprite_draw_layer5;
    reg_a4 = (u8 *) sprite_draw_layer4;
    if (!((s32) g_scroll_line < 0x11E)) goto next_510;
    reg_a2 = (u8 *) entity_draw_layer1;
    reg_a3 = (u8 *) sprite_draw_layer1;
    reg_a4 = (u8 *) sprite_draw_layer1;
next_510:
    reg_call_target = (Fn) reg_a2;
    reg_call_target();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF200;
    reg_d1.h[1] += 0xE400;
    reg_d0.h[0] = ENTITY(reg_a6)[1].look.h;
    reg_a0 = (u8 *) D_00263120;
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x1670;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[2].offset_y.b[0];
    reg_call_target = (Fn) reg_a3;
    reg_call_target();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x480;
    reg_d1.h[1] += 0x6C0;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x28);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x2A);
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_call_target = (Fn) reg_a3;
    reg_call_target();
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF580;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x2E);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x30);
    reg_call_target = (Fn) reg_a3;
    reg_call_target();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xEE00;
    reg_d1.h[1] += 0xF900;
    reg_d2.h[1] = ENTITY(reg_a6)[1].draw.h;
    reg_d2.h[0] = ENTITY(reg_a6)[1].sprite.h;
    reg_d3.h[0] = 0x1290;
    reg_d4.w = 0;
    reg_d4.b[0] = ENTITY(reg_a6)[2].offset_y.b[1];
    reg_call_target = (Fn) reg_a3;
    reg_call_target();
    if (g_loop != 0) goto next_540;
    if (D_0028E3EC == 0) goto next_540;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += 0xD600;
    reg_d2.w = 0x1B9F;
    reg_d3.h[0] = 0xC48;
    reg_d4.h[0] = 0x18;
    if (!(g_game_frame & 2)) goto next_520;
    reg_d4.h[0] |= 0x4000;
next_520:
    reg_call_target = (Fn) reg_a4;
    reg_call_target();
next_540:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    if (g_enemies_stopped != 0) goto block_rts;
    if (g_bullets_blocked != 0) goto block_rts;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto block_rts;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (reg_d0.h[0] == 0) goto block_rts;
    if (reg_d0.h[0] != 1) goto next_800;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
    reg_tmp.h[0] -= 1;
    *(u8 *)(reg_a5 + 0x23) -= 1;
    if (reg_tmp.b[1] != 0) goto next_600;
block_rts:
    return;
next_600:
    *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x34);
    reg_a4 = (u8 *)D_002594F0_as_u8_a;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x2C);
    reg_d0.h[0] = reg_d1.h[0];
    reg_d0.h[0] += 4;
    reg_d0.h[0] &= 0xF8;
    reg_d0.h[0] >>= 1;
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0x780;
    reg_d3.h[1] += 0xAC0;
    reg_d4.w = (u32) reg_a6;
    reg_d0.w = 0x180007;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    bullet_fire256_3way();
    reg_d6.b[0] = *(u8 *)(reg_a5 + 0x25);
    reg_d6.b[0] += reg_d6.b[0];
    reg_d6.b[0] += *(u8 *)(reg_a5 + 0x3C);
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256_fast();
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x32);
    reg_d4.h[0] = reg_d1.h[0];
    reg_d4.h[0] += 4;
    reg_d4.h[0] &= 0xF8;
    reg_d4.h[0] >>= 1;
    reg_d3.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d4.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16) reg_d4.h[0] + 2) != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0xF880;
    reg_d3.h[1] += 0xAC0;
    bullet_fire256_3way();
    reg_d6.b[0] = *(u8 *)(reg_a5 + 0x25);
    reg_d6.b[0] += reg_d6.b[0];
    reg_d6.b[0] += *(u8 *)(reg_a5 + 0x3C);
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256_fast();
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_650;
    *(u8 *)(reg_a5 + 0x24) += 6;
    *(u8 *)(reg_a5 + 0x25) = *(u8 *)(reg_a5 + 0x24);
    *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x22);
    enemy_switch_target_player();
    *(u16 *)(reg_a5 + 0x18) = 2;
    *(u8 *)(reg_a5 + 0x3C) -= 2;
    if ((s32) *(u8 *)(reg_a5 + 0x3C) >= 5) goto next_650;
    *(u8 *)(reg_a5 + 0x3C) = 5;
next_650:
    return;
next_800:
    reg_tmp.w = 0;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x37);
    reg_tmp.h[0] -= 1;
    *(u8 *)(reg_a5 + 0x37) -= 1;
    if (reg_tmp.b[1] != 0) goto next_820;
    return;
next_820:
    *(u8 *)(reg_a5 + 0x37) = *(u8 *)(reg_a5 + 0x3D);
    if (!(*(u8 *)(reg_a5 + 0x38) & 4)) goto next_830;
    rng_next_unsigned();
    reg_d1.h[0] = reg_d0.h[0];
    goto next_870;
next_830:
    reg_a0 = (u8 *) g_player1_as_u16_a;
    reg_a1 = (u8 *) g_player2_as_u16_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_840;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_840:
    if (*(s16 *)reg_a0 < 0) goto next_860;
    if (*(s16 *)reg_a1 >= 0) goto next_900;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_860:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xF940;
    direction256_between();
next_870:
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.h[0] = *(u16 *)(reg_a5 + 0x38);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x3E);
    reg_d0.h[0] = reg_d0.h[0] - reg_d4.h[0];
    reg_d0.h[0] >>= 1;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = 3;
    if (!(*(u8 *)(reg_a5 + 0x38) & 4)) goto next_875;
    reg_d0.h[0] = 3;
next_875:
    reg_a0 = (u8 *) D_00263270;
    reg_d5.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d5.h[0] = (((u16) reg_d4.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) D_00263280;
    reg_d6.h[0] = (reg_d4.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d7.h[0] = (((u16) reg_d4.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d4.w = 0;
    reg_a0 = (u8 *) D_00259970;
loop_880:
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d5.w;
    bullet_fire256();
    if (!(reg_d7.h[0] & 1)) goto next_890;
    reg_d0.w -= 0x60000;
    reg_d0.h[0] += 1;
    bullet_fire256_fixed();
    reg_d0.w += 0x60000;
    reg_d0.h[0] -= 1;
next_890:
    reg_d1.h[0] += reg_d6.h[0];
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_880;
    *(u16 *)(reg_a5 + 0x38) -= 4;
    if ((s16) *(u16 *)(reg_a5 + 0x38) >= 0) goto next_900;
    *(u16 *)(reg_a5 + 0x3E) += 8;
    *(u16 *)(reg_a5 + 0x38) = 0xC;
    *(u8 *)(reg_a5 + 0x37) = *(u8 *)(reg_a5 + 0x36);
    enemy_switch_target_player();
    *(u16 *)(reg_a5 + 0x18) = 0;
next_900:
    return;
next_700:
    sfx_beam_loop_stop();
    sfx_explosion_extra_1();
    ENTITY(reg_a6)[2].look.h = reg_d1.h[0];
    reg_d0.w = 0x457;
    score_add();
    vibration_start_pad1(0xB4, 0x3C);
    vibration_start_pad2(0xB4, 0x3C);
    g_slowdown_timer = 0x3C;
    reg_a0 = (u8 *) D_00263290;
    func_0013B2E0();
    reg_d0.h[0] = 0x8080;
    ENTITY(reg_a6)->flags.sh = (s16) reg_d0.h[0];
    ENTITY(reg_a6)[1].flags.h = (u16) reg_d0.h[0];
    reg_d0.w = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    val = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 4) = val;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(s16 *)(reg_a0 + 0x26) = 0x400;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    reg_d0.h[0] = 0x84;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(s16 *)(reg_a0 + 0x26) = 0x400;
    *(s16 *)(reg_a0 + 0x28) = 0x200;
    *(s16 *)(reg_a0 + 0x1A) = 0x44C;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x18) = 1;
    reg_d0.h[0] = 0x84;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(s16 *)(reg_a0 + 0x26) = 0x400;
    *(u16 *)(reg_a0 + 0x28) = 0xFE00;
    *(s16 *)(reg_a0 + 0x1A) = 0x4B4;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s8 *)(reg_a0 + 0x1D) = 0x40;
    *(s16 *)(reg_a0 + 0x18) = 2;
    reg_d0.w = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xFA00;
    *(u16 *)(reg_a0 + 0x28) = 0xFE00;
    *(s16 *)(reg_a0 + 0x1A) = 0x6A8;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x18) = 2;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xFC00;
    *(s16 *)(reg_a0 + 0x28) = 0x100;
    *(s16 *)(reg_a0 + 0x1A) = 0x858;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x18) = 4;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF400;
    *(u16 *)(reg_a0 + 0x28) = 0xFE00;
    *(s16 *)(reg_a0 + 0x1A) = 0xA88;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x18) = 6;
    reg_d0.w = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF400;
    *(s16 *)(reg_a0 + 0x28) = 0x400;
    *(s16 *)(reg_a0 + 0x1A) = 0xA78;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x18) = 4;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(s16 *)(reg_a0 + 0x26) = 0;
    *(u16 *)(reg_a0 + 0x28) = 0xF200;
    *(s16 *)(reg_a0 + 0x1A) = 0x4A0;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x18) = 8;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(s16 *)(reg_a0 + 0x26) = 0;
    *(s16 *)(reg_a0 + 0x28) = 0xE00;
    *(s16 *)(reg_a0 + 0x1A) = 0x460;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x18) = 8;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xEA00;
    *(u16 *)(reg_a0 + 0x28) = 0xF600;
    *(s16 *)(reg_a0 + 0x1A) = 0xA90;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x18) = 0xA;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xEA00;
    *(s16 *)(reg_a0 + 0x28) = 0xA00;
    *(s16 *)(reg_a0 + 0x1A) = 0xA70;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x18) = 0xA;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xE400;
    *(s16 *)(reg_a0 + 0x28) = 0x200;
    *(s16 *)(reg_a0 + 0x1A) = 0x588;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x18) = 8;
skip_1:
    if (ENTITY(reg_a6)[2].sprite.h == 0x30) {
        g_enemy_signal_0 = 0;
    }
    reg_d1.h[0] = ENTITY(reg_a6)[2].look.h;
    func_00201800();
    ENTITY(reg_a6)[2].sprite.h -= 1;
    if (ENTITY(reg_a6)[2].sprite.h == 0) {
        sfx_beam_loop_stop();
        enemy_remove();
    }
}
