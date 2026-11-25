#include "common.h"
#include "entity.h"

extern void enemy_set_entity_count(s32);

void func_0015C470(void) {
    enemy_set_entity_count(1);
}


s32 aim_at_player();
extern u16 D_002592F0[];
extern s8 D_0025A070[];
extern s8 D_0025A080[];
extern s8 D_0025A0B0[];
extern u16 g_rank_2_16;
extern u16 g_loop;
extern u16 g_stage_x2;
extern u16 g_stage;
extern s8 enemy_move_end_requested;
extern s8 *reg_a0_as_s8_p;

void func_0015C480(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0_as_s8_p = D_0025A0B0;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0_as_s8_p;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0_as_s8_p = D_0025A080;
    reg_d0.w = 0x10;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_loop != 0) {
            reg_d0.h[0] = 0x1200;
            ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
            *(u16 *)(reg_a6 + 0x38) = (u16) reg_d0.h[0];
        }
        reg_a2 = (u8 *)(D_002592F0);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x680;
        reg_d1.h[0] += 0x500;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        *(u8 *)(reg_a5 + 0x2C) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x28) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a5 + 0x2A) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x680;
        reg_d1.h[0] += 0x7FFF + 0x7B01;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        *(u8 *)(reg_a5 + 0x32) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x2E) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a5 + 0x30) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.b[0] = 0x10;
        reg_d1.b[0] = 4;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 4;
        }
        *(u8 *)(reg_a5 + 0x35) = (u8) reg_d0.b[0];
        *(u8 *)(reg_a5 + 0x34) = (u8) reg_d1.b[0];
        if (g_stage == 4) {
            reg_d0.h[0] = 5;
            *(u8 *)(reg_a5 + 0x21) = (u8) reg_d0.b[0];
            *(u8 *)(reg_a5 + 0x20) = (u8) reg_d0.b[0];
            reg_d0.h[0] = 8;
            *(u8 *)(reg_a5 + 0x25) = (u8) reg_d0.b[0];
            *(u8 *)(reg_a5 + 0x24) = (u8) reg_d0.b[0];
            *(u8 *)(reg_a5 + 0x35) = 0xCU;
            reg_d0.h[0] = 0x7FFF;
            ENTITY(reg_a6)->hp.h = (u16) reg_d0.h[0];
            *(u16 *)(reg_a6 + 0x38) = (u16) reg_d0.h[0];
            *(s16 *)(reg_a5 + 0x36) = 0x30;
        }
        reg_d0.h[0] = g_rank_2_16;
        *(u8 *)(reg_a5 + 0x1F) -= reg_d0.b[0];
        reg_d0.h[0] = g_rank_2_16;
        reg_d0.b[0] -= 8;
        *(u8 *)(reg_a5 + 0x23) -= reg_d0.b[0];
        reg_a0_as_s8_p = D_0025A070;
        reg_d0.h[0] = g_stage_x2;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *reg_a0_as_s8_p;
        *(s8 *)(reg_a5 + 0x1D) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        *(s8 *)(reg_a5 + 0x1C) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
    }
}

s32 bullet_fire_3way();
s32 bullet_fire256_3way();
s32 bullet_fire256();
s32 func_001368E0();
s32 explosion_spawn();
s32 enemy_hitbox_debug_draw();
s32 enemy_remove();
s32 enemy_path_step();
s32 func_0018D580();
s32 entity_draw_layer5();
s32 sprite_draw_layer4();
s32 sprite_draw_layer5();
s32 score_add_no_chain();
s32 score_add();
s32 direction_between();
s32 direction_turn_toward();
s32 direction256_between();
extern u16 D_002596F0[];
extern u16 D_00259870[];
extern u16 D_00259970[];
extern u16 D_0028E3EC;
extern u16 g_bullets_blocked;
extern u16 g_enemies_stopped;
extern u16 D_0028E8B8;
extern u16 g_rank_3_16;
extern u16 D_0029C068[];
extern u16 D_0029CEA0[];
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];

void func_0015C870(void) {
    u32 cnt;
    u8 bits;
    u8 *ptr;

    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x1800;
    reg_d0.h[0] += D_0029C068[0];
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x9800;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9800;
    if (reg_tmp.h[1] != 0) goto next_20;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] += 0x1400;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7400;
    if (reg_tmp.h[1] == 0) goto next_30;
next_20:
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_40;
    enemy_remove();
    return;
next_30:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_40:
    *(u16 *)(reg_a6 + 0x22) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a6 + 0x24) = ENTITY(reg_a6)->x.h;
    if (*(s16 *)(reg_a5 + 0x36) < 0) goto next_45;
    reg_d0.h[0] = 0x7FFF;
    ENTITY(reg_a6)->hp.h = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x38) = reg_d0.h[0];
    reg_d0.h[0] = 1;
    if (D_0029CEA0[0] == 0) goto next_42;
    reg_d0.h[0] = 2;
next_42:
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x36);
    *(u16 *)(reg_a5 + 0x36) -= reg_d0.h[0];
    if (!((s32) reg_tmp.h[0] < (s32) reg_d0.h[0])) goto next_45;
    reg_d0.h[0] = 0x1400;
    ENTITY(reg_a6)->hp.h = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x38) = reg_d0.h[0];
next_45:
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= *(u8 *)(reg_a6 + 0x21);
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
    if (!((s32) ENTITY(reg_a6)->hp.h < 0x255)) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    reg_d0.h[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x21) &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
next_60:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
    if (!((s16) *(u16 *)(reg_a6 + 0x38) < (s16) reg_d4.h[0])) goto next_80;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x38);
next_80:
    ENTITY(reg_a6)->hp.h = reg_d4.h[0];
    *(u16 *)(reg_a6 + 0x38) = reg_d4.h[0];
    if ((s16) ENTITY(reg_a6)->hp.h < 0) goto next_700;
next_90:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    func_001368E0();
    if (g_enemies_stopped != 0) goto next_500;
    if (g_bullets_blocked != 0) goto next_500;
    if (*(u16 *)(reg_a5 + 0x18) != 0) goto next_300;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto next_300;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_300;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x35);
    reg_a0 = (u8 *) D_0029F260_as_u16_a;
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_240;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_240:
    if (*(s16 *)reg_a0 < 0) goto next_260;
    if (*(s16 *)reg_a1 >= 0) goto next_290;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_260:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xFE00;
    direction256_between();
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d5.w = 0xFE000000;
    reg_d4.w = 0;
    if (g_stage != 4) goto next_262;
    if (*(u8 *)(reg_a5 + 0x21) != 5) goto next_261;
    reg_d0.w = 4;
    goto next_264;
next_261:
    if (*(u8 *)(reg_a5 + 0x21) == 4) goto next_263;
    goto next_270;
next_262:
    if (*(u8 *)(reg_a5 + 0x21) != 1) goto next_270;
next_263:
    reg_d0.w = 4;
    if (g_stage != 4) goto next_264;
    reg_d0.w = 0xFFFF0004;
next_264:
    reg_d1.b[0] -= 0x1C;
    reg_d6.w = 8;
    reg_d7.w = 7;
    reg_a0 = (u8 *) D_00259870;
loop_265:
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d5.w;
    bullet_fire256();
    reg_d1.h[0] += reg_d6.h[0];
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_265;
    goto next_290;
next_270:
    reg_d0.w = 0xFFFF0005;
    if (g_stage != 4) goto next_274;
    reg_d0.w = 0xFFFE0004;
next_274:
    reg_d1.b[0] -= 0x24;
    reg_d6.w = 0xC;
    reg_d7.w = 6;
    reg_a0 = (u8 *) D_00259970;
loop_280:
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d5.w;
    bullet_fire256_3way();
    reg_d1.h[0] += reg_d6.h[0];
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_280;
next_290:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
    *(u8 *)(reg_a5 + 0x21) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_300;
    *(u8 *)(reg_a5 + 0x21) = *(u8 *)(reg_a5 + 0x20);
    reg_d0.h[0] = 0x50;
    reg_d0.h[0] -= g_rank_3_16;
    *(u8 *)(reg_a5 + 0x1F) = reg_d0.b[0];
    *(u16 *)(reg_a5 + 0x18) = 1;
next_300:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x27);
    *(u8 *)(reg_a5 + 0x27) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_500;
    *(u8 *)(reg_a5 + 0x27) = *(u8 *)(reg_a5 + 0x26);
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x25);
    if (*(u8 *)(reg_a5 + 0x24) != reg_d0.b[0]) goto next_500;
    reg_a0 = (u8 *) D_0029F260_as_u16_a;
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_320;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_320:
    if (*(s16 *)reg_a0 < 0) goto next_340;
    if (*(s16 *)reg_a1 >= 0) goto next_500;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_340:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_a3 = (u8 *) D_002592F0;
    bits = ENTITY(reg_a6)->flags.b[0];
    if (bits & 0x40) {
        ENTITY(reg_a6)->flags.b[0] = bits & 0xBF;
        goto next_380;
    }
    ENTITY(reg_a6)->flags.b[0] = bits | 0x40;
    reg_d0.h[0] += 0x680;
    reg_d1.h[0] += 0x500;
    direction_between();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
    direction_turn_toward();
    *(u16 *)(reg_a5 + 0x2C) = reg_d1.h[0];
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    *(u16 *)(reg_a5 + 0x28) = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    *(u16 *)(reg_a5 + 0x2A) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    goto next_500;
next_380:
    reg_d0.h[0] += 0x680;
    reg_d1.h[0] += 0xFB00;
    direction_between();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x32);
    direction_turn_toward();
    *(u16 *)(reg_a5 + 0x32) = reg_d1.h[0];
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    *(u16 *)(reg_a5 + 0x2E) = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    *(u16 *)(reg_a5 + 0x30) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
next_500:
    entity_draw_layer5();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += 0x80;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x28);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x2A);
    reg_d3.h[0] = 0x628;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer5();
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF600;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x2E);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x30);
    sprite_draw_layer5();
    if (g_loop != 0) goto next_520;
    if (D_0028E3EC == 0) goto next_520;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += 0xD600;
    reg_d2.w = 0x186C;
    reg_d3.h[0] = 0xA40;
    reg_d4.h[0] = 0x18;
    sprite_draw_layer4();
next_520:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    if (*(u16 *)(reg_a5 + 0x18) == 0) goto block_rts;
    if (g_enemies_stopped != 0) goto block_rts;
    if (g_bullets_blocked != 0) goto block_rts;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto block_rts;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
    *(u8 *)(reg_a5 + 0x23) -= 1;
    if (reg_tmp.b[0] == 0) goto next_600;
block_rts:
    return;
next_600:
    *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x34);
    reg_a4 = (u8 *) D_002596F0;
    reg_d0.w = 0x20013;
    if (g_stage != 4) goto next_620;
    reg_d0.w = 0x70013;
next_620:
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x2C);
    reg_d5.h[0] = reg_d1.h[0];
    reg_d5.h[0] &= 0x3E;
    reg_d5.h[0] += reg_d5.h[0];
    reg_d3.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d5.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16) reg_d5.h[0] + 2) != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0x500;
    reg_d3.h[1] += 0x680;
    reg_d4.w = 0;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    bullet_fire_3way();
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x32);
    reg_d5.h[0] = reg_d1.h[0];
    reg_d5.h[0] &= 0x3E;
    reg_d5.h[0] += reg_d5.h[0];
    reg_d3.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d5.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16) reg_d5.h[0] + 2) != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0xFB00;
    reg_d3.h[1] += 0x680;
    bullet_fire_3way();
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
    *(u8 *)(reg_a5 + 0x25) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_650;
    *(u8 *)(reg_a5 + 0x25) = *(u8 *)(reg_a5 + 0x24);
    reg_d0.h[0] = 0x30;
    reg_d0.h[0] -= g_rank_3_16;
    *(u8 *)(reg_a5 + 0x23) = reg_d0.b[0];
    *(u16 *)(reg_a5 + 0x18) = 0;
next_650:
    return;
next_700:
    reg_d0.w = 0x83;
    score_add();
    func_0018D580();
    reg_d0.w = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF800;
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    reg_d0.h[0] = 0x84;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF600;
    *(s16 *)(reg_a0 + 0x28) = 0x600;
    *(s16 *)(reg_a0 + 0x1A) = 0x754;
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    reg_d0.h[0] = 0x84;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF600;
    *(u16 *)(reg_a0 + 0x28) = 0xFA00;
    *(s16 *)(reg_a0 + 0x1A) = 0x7AC;
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s8 *)(reg_a0 + 0x1D) = 0x40;
    reg_d0.w = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF200;
    *(u16 *)(reg_a0 + 0x28) = 0xFE00;
    *(s16 *)(reg_a0 + 0x1A) = 0x798;
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x18) = 2;
    reg_d0.w = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF200;
    *(s16 *)(reg_a0 + 0x28) = 0x100;
    *(s16 *)(reg_a0 + 0x1A) = 0x768;
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x18) = 4;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF600;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x1A) = 0xC80;
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x18) = 4;
    enemy_remove();
}

void func_0015D8E0(void) {
    enemy_set_entity_count(1);
}

extern u16 D_00259170[];
extern s8 D_0025A128[];
extern s8 D_0025A140[];
extern s8 D_0025A160[];
extern u16 g_rank_7_16;
extern s16 D_00299768[];
extern s16 D_0029976A[];

void func_0015D8F0(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0_as_s8_p = D_0025A160;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0_as_s8_p;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0_as_s8_p = D_0025A140;
    reg_d0.w = 0xA;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_a2 = (u8 *)(D_00259170);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x5C0;
        reg_d1.h[0] += 0xA40;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        *(u8 *)(reg_a6 + 0x2A) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a6 + 0x26) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a6 + 0x28) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x5C0;
        reg_d1.h[0] += 0x7FFF + 0x7601;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        *(u8 *)(reg_a6 + 0x30) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a6 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a6 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.b[0] = 0x10;
        reg_d1.b[0] = 8;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 8;
        }
        *(u8 *)(reg_a5 + 0x29) = (u8) reg_d0.b[0];
        *(u8 *)(reg_a5 + 0x28) = (u8) reg_d1.b[0];
        reg_d0.h[0] = g_rank_7_16;
        *(u8 *)(reg_a5 + 0x1F) -= reg_d0.b[0];
        reg_a0_as_s8_p = D_0025A128;
        reg_d0.h[0] = g_stage_x2;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *reg_a0_as_s8_p;
        *(s8 *)(reg_a5 + 0x1D) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        *(s8 *)(reg_a5 + 0x1C) = (s8) *reg_a0_as_s8_p;
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        reg_a0_as_s8_p += 1;
    }
}

s32 bullet_fire256_fixed();
s32 bullet_fire256_2way();
extern u16 D_00259570[];
extern u16 D_00259770[];
extern u16 D_0025A1E0[];
extern u16 g_rank_4_16;
extern u16 g_rank_6_16;
extern s16 D_0029CEA0_as_s16_a[];

void func_0015DC20(void) {
    s16 *temp_a0;
    s16 *temp_v1;
    s16 *temp_v1_2;
    u32 temp_a0_3;
    u32 temp_a0_4;
    u32 temp_a1;
    u32 temp_a3;
    u32 temp_a3_2;
    u32 temp_a3_3;
    u16 var_a0_2;
    u8 temp_v1_3;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7A00;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0xE00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x7A00;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_5:
        if (*(s16 *)(reg_a5 + 0x2A) >= 0) {
            ENTITY(reg_a6)->hp.h = 0x7FFFU;
            reg_d0.w = 1;
            if (D_0029CEA0_as_s16_a[0] < 0) {
                reg_d0.w = 2;
            }
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x2A);
            *(u16 *)(reg_a5 + 0x2A) -= reg_d0.h[0];
            if ((s32) reg_tmp.h[0] < (s32) reg_d0.h[0]) {
                ENTITY(reg_a6)->hp.h = 0x2600U;
            }
        }
        temp_a0 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(temp_a0) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
            if (((s32) (*(u16 *)((u8 *)(temp_a0) + (0x18))) < 0x980) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_17;
        }
        (*(u8 *)((u8 *)(temp_a0) + (1))) &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
        }
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_17:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            func_001368E0();
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                if ((s16) ENTITY(reg_a6)->y.h >= 0x1000) {
                    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x38);
                    if (reg_d0.h[0] == 0) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                        *(u8 *)(reg_a5 + 0x1F) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x29);
                            *(u16 *)(reg_a6 + 0x38) = 1U;
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 1) {
                        reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x3B);
                        *(u8 *)(reg_a6 + 0x3B) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a6 + 0x3B) = (u8) *(u8 *)(reg_a6 + 0x3A);
                            *(u16 *)(reg_a6 + 0x36) += 4;
                            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x36);
                            reg_a0 = (u8 *)(D_0025A1E0);
                            *(u16 *)(reg_a6 + 0x32) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                            *(u16 *)(reg_a6 + 0x34) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            if (reg_d0.h[0] == 0x14) {
                                *(u16 *)(reg_a6 + 0x38) = 2U;
                            }
                        }
                    } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                        reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x3B);
                        *(u8 *)(reg_a6 + 0x3B) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a6 + 0x3B) = (u8) *(u8 *)(reg_a6 + 0x3A);
                            *(u16 *)(reg_a6 + 0x36) += 4;
                            if (*(u16 *)(reg_a6 + 0x36) == 0x18) {
                                *(u16 *)(reg_a6 + 0x36) = 0x10U;
                            }
                            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x36);
                            reg_a0 = (u8 *)(D_0025A1E0);
                            *(u16 *)(reg_a6 + 0x32) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                            *(u16 *)(reg_a6 + 0x34) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        }
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                        *(u8 *)(reg_a5 + 0x1F) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x29);
                            reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                            reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                            if (*(u8 *)(reg_a5 + 2) != 0) {
                                reg_atmp = (u8 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(reg_atmp);
                            }
                            temp_v1 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                                if (*(s16 *)reg_a1 < 0) {
                                    reg_a0 = (u8 *)(reg_a1);
                                    reg_atmp = (u8 *)(temp_v1);
                                    reg_a1 = (u8 *)(temp_v1);
                                    goto block_51;
                                }
                            } else {
block_51:
                                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d0.h[0] += 0xF780;
                                direction256_between();
                                reg_d6.h[0] = reg_d1.h[0];
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                temp_a1 = ENTITY(reg_a6)->x.h;
                                reg_d2.h[0] = temp_a1;
                                reg_d3.w = 0xF7800380;
                                reg_d0.w = 0xFFFD0005;
                                reg_d1.h[0] += 0xA;
                                reg_d4.w = 0;
                                bullet_fire256_2way();
                                reg_d1.h[0] -= 0x14;
                                bullet_fire256_2way();
                                reg_d3.w = 0xF780FC80;
                                reg_d1.h[0] = reg_d6.h[0];
                                reg_d1.h[0] += 0xA;
                                bullet_fire256_2way();
                                reg_d1.h[0] -= 0x14;
                                bullet_fire256_2way();
                            }
                            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
                            *(u8 *)(reg_a5 + 0x21) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
                                reg_d0.h[0] = 0x40;
                                reg_d0.h[0] -= g_rank_4_16;
                                *(u8 *)(reg_a5 + 0x1F) = (u8) reg_d0.b[0];
                                *(u16 *)(reg_a6 + 0x38) = 3U;
                            }
                        }
                    } else {
                        reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x3B);
                        *(u8 *)(reg_a6 + 0x3B) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a6 + 0x3B) = (u8) *(u8 *)(reg_a6 + 0x3A);
                            reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x36);
                            *(u16 *)(reg_a6 + 0x36) -= 4;
                            if ((s32) reg_tmp.h[0] < 4) {
                                *(u16 *)(reg_a6 + 0x38) = 0U;
                            } else {
                                reg_d0.h[0] = *(u16 *)(reg_a6 + 0x36);
                                reg_a0 = (u8 *)(D_0025A1E0);
                                *(u16 *)(reg_a6 + 0x32) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                                *(u16 *)(reg_a6 + 0x34) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            }
                        }
                    }
                }
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x27);
                *(u8 *)(reg_a5 + 0x27) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x27) = (u8) *(u8 *)(reg_a5 + 0x26);
                    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x25);
                    if (*(u8 *)(reg_a5 + 0x24) == reg_d0.b[0]) {
                        reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                        reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                        switch (*(u8 *)(reg_a5 + 2)) { case 0: break; default:
                            reg_atmp = (u8 *)(reg_a0);
                            reg_a0 = (u8 *)(reg_a1);
                            reg_a1 = (u8 *)(reg_atmp);
                        }
                        temp_v1_2 = (s16 *)(reg_a0);
                        if ((*(s16 *)((u8 *)(temp_v1_2) + (0))) >= 0) {
                            if (*(s16 *)reg_a1 < 0) {
                                reg_a0 = (u8 *)(reg_a1);
                                reg_atmp = (u8 *)(temp_v1_2);
                                reg_a1 = (u8 *)(temp_v1_2);
                                goto block_71;
                            }
                        } else {
block_71:
                            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_a3 = (u8 *)(D_00259170);
                            temp_v1_3 = ENTITY(reg_a6)->flags.b[0];
                            if (temp_v1_3 & 0x40) {
                                ENTITY(reg_a6)->flags.b[0] = (u8) (temp_v1_3 & 0xBF);
                                goto block_set;
                            }
                            ENTITY(reg_a6)->flags.b[0] = (u8) (temp_v1_3 | 0x40);
                            reg_d0.h[0] += 0x5C0;
                            reg_d1.h[0] += 0xA40;
                            direction_between();
                            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2A);
                            direction_turn_toward();
                            *(u16 *)(reg_a6 + 0x2A) = (u16) reg_d1.h[0];
                            reg_d1.h[0] &= 0x3E;
                            reg_d1.h[0] += reg_d1.h[0];
                            *(u16 *)(reg_a6 + 0x26) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                            *(u16 *)(reg_a6 + 0x28) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                            goto block_join;
block_set:
                            reg_d0.h[0] += 0x5C0;
                            reg_d1.h[0] += 0xF600;
                            direction_between();
                            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x30);
                            direction_turn_toward();
                            *(u16 *)(reg_a6 + 0x30) = (u16) reg_d1.h[0];
                            reg_d1.h[0] &= 0x3E;
                            reg_d1.h[0] += reg_d1.h[0];
                            *(u16 *)(reg_a6 + 0x2C) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                            *(u16 *)(reg_a6 + 0x2E) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                        }
                    }
                }
            }
block_join:
            entity_draw_layer5();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0_3 = reg_d1.h[0];
            reg_d1.h[1] += 0xF400;
            reg_d1.h[0] = (u32)temp_a0_3 + 0xFB00;
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x32);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x34);
            reg_d3.h[0] = 0x428;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer5();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0_4 = reg_d1.h[0];
            reg_d1.h[1] += 0xFFC0;
            reg_d1.h[0] = (u32)temp_a0_4 + 0x640;
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x26);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x28);
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer5();
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += 0xF200;
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x2C);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x2E);
            sprite_draw_layer5();
            if ((g_loop == 0) && (D_0028E3EC != 0)) {
                reg_d1.h[1] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.h[1] += 0xD400;
                reg_d1.h[0] += 0x100;
                reg_d2.w = 0x1874;
                reg_d3.h[0] = 0x848;
                reg_d4.h[0] = 0x18;
                sprite_draw_layer4();
            }
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                *(u8 *)(reg_a5 + 0x23) -= 1;
                switch (reg_tmp.b[0]) {
                case 0:
                    *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x28);
                    reg_a4 = (u8 *)(D_00259570);
                    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x2A);
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] &= 0x3E;
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_d5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a4;
                    reg_d5.h[0] = ((reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)(reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
                    reg_d0.w = 0x40007;
                    reg_d4.w = 0;
                    reg_d5.h[0] += 0xA40;
                    reg_d5.h[1] += 0x5C0;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d1.b[0] *= 4;
                    reg_d7.h[0] = 6;
                    reg_a0 = (u8 *)(D_00259770);
                    reg_d1.h[0] -= 0x2D;
                    do {
                        reg_d3.h[0] = reg_d1.h[0];
                        reg_d3.h[0] += 2;
                        reg_d3.h[0] &= 0xFC;
                        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d3.w += reg_d5.w;
                        bullet_fire256_fixed();
                        reg_d1.h[0] += 0xF;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x30);
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] &= 0x3E;
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_d5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a4;
                    reg_d5.h[0] = ((reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)(reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
                    reg_d7.h[0] = 6;
                    reg_a0 = (u8 *)(D_00259770);
                    reg_d5.h[0] += 0xF600;
                    reg_d5.h[1] += 0x5C0;
                    reg_d1.b[0] *= 4;
                    reg_d1.h[0] -= 0x2D;
                    do {
                        reg_d3.h[0] = reg_d1.h[0];
                        reg_d3.h[0] += 2;
                        reg_d3.h[0] &= 0xFC;
                        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d3.w += reg_d5.w;
                        bullet_fire256_fixed();
                        var_a0_2 = (u32)reg_d1.h[0] + 0xF;
                        reg_d1.h[0] = var_a0_2;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
                    *(u8 *)(reg_a5 + 0x25) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
                        reg_d0.h[0] = 0x80;
                        reg_d0.h[0] -= g_rank_6_16;
                        *(u8 *)(reg_a5 + 0x23) = (u8) reg_d0.b[0];
                    }
                    return;
                }
            }
        } else {
            reg_d0.w = 0x271;
            score_add();
            func_0018D580();
            reg_d0.w = 0xD;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x26) = 0x600;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            reg_d0.w = 5;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a3 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a3;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(u16 *)(reg_a0 + 0x26) = 0xFC00;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            reg_d0.w = 4;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x26) = 0x200;
            *(s16 *)(reg_a0 + 0x28) = 0x800;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            reg_d0.w = 4;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x26) = 0x200;
            *(u16 *)(reg_a0 + 0x28) = 0xF600;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            reg_d0.w = 8;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(u16 *)(reg_a0 + 0x26) = 0xF800;
            *(s16 *)(reg_a0 + 0x28) = 0x600;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            reg_d0.w = 8;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a3_2 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a3_2;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(u16 *)(reg_a0 + 0x26) = 0xF800;
            *(u16 *)(reg_a0 + 0x28) = 0xF800;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            reg_d0.w = 4;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(u16 *)(reg_a0 + 0x26) = 0xFC00;
            *(s16 *)(reg_a0 + 0x28) = 0xE00;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            reg_d0.w = 4;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a3_3 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a3_3;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(u16 *)(reg_a0 + 0x26) = 0xFC00;
            *(u16 *)(reg_a0 + 0x28) = 0xF000;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            enemy_remove();
        }
    }
}

void func_0015EF00(void)
{
    extern void bullet_fire256_fast(void);
  int new_var;
  u32 savedPosition;
  u32 nextPosition;
  u32 command;
  savedPosition = reg_d1.h[0];
  reg_d0.w = 0xFFFF000D;
  nextPosition = savedPosition + 2;
  reg_d6.h[0] = savedPosition;
  reg_d1.h[0] = nextPosition;
  bullet_fire256_fast();
  nextPosition = reg_d1.h[0] + 5U;
  command = (new_var = reg_d0.w) + 0xFFFE0000;
  reg_d1.h[0] = nextPosition;
  reg_d0.w = command;
  bullet_fire256_fast();
  reg_d1.h[0] = reg_d6.h[0];
}

void func_0015EF60(void)
{
    extern void bullet_fire256_fast(void);
  u32 saved_d0;
  reg_d6.h[0] = reg_d1.h[0];
  reg_d0.w = 0xFFFF000D;
  reg_d1.h[0] -= 2;
  bullet_fire256_fast();
  saved_d0 = reg_d0.w;
  reg_d0.w = saved_d0 + 0xFFFE0000;
  reg_d1.h[0] -= 5;
  bullet_fire256_fast();
  reg_d1.h[0] = reg_d6.h[0];
}

void enemy_set_entity_count(s32);

void func_0015EFC0(void) {
    enemy_set_entity_count(1);
}

extern u8 D_00259170_as_u8_a[];
extern s8 D_0025A1F8[];
extern s8 D_0025A210[];
extern s8 D_0025A230[];
extern u16 g_enemy_signal_3;
extern u16 g_enemy_signal_2;
extern u16 g_enemy_signal_1;
extern u16 g_enemy_signal_0;
extern u16 g_rank_5_16;

void func_0015EFD0(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    s8 *temp_a1;

    if ((g_stage == 0) && (g_enemy_signal_0 != 0)) {
        enemy_remove();
        return;
    }
    reg_a0_as_s8_p = D_0025A230;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0_as_s8_p;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0_as_s8_p = D_0025A210;
    reg_d0.w = 0xD;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_a2 = D_00259170_as_u8_a;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x240;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        *(u8 *)(reg_a5 + 0x2C) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        reg_a2 += reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x28) = (u16) *(u16 *)reg_a2;
        *(u16 *)(reg_a5 + 0x2A) = (u16) *(u16 *)(reg_a2 + 2);
        reg_d0.b[0] = 4;
        reg_d1.b[0] = 5;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 4;
            reg_d1.b[0] = 5;
        }
        *(u8 *)(reg_a5 + 0x2F) = (u8) reg_d0.b[0];
        *(u8 *)(reg_a5 + 0x2E) = (u8) reg_d1.b[0];
        reg_d0.h[0] = g_rank_3_16;
        *(u8 *)(reg_a5 + 0x1F) -= reg_d0.b[0];
        reg_d0.h[0] = g_rank_5_16;
        *(u8 *)(reg_a5 + 0x1E) -= reg_d0.b[0];
        reg_d0.h[0] = g_rank_3_16;
        *(u8 *)(reg_a5 + 0x23) -= reg_d0.b[0];
        if (g_loop != 0) {
            *(u8 *)(reg_a5 + 0x23) -= 0x10;
        }
        reg_d0.h[0] = g_rank_6_16;
        *(u8 *)(reg_a5 + 0x22) -= reg_d0.b[0];
        reg_a0_as_s8_p = D_0025A1F8;
        reg_d0.h[0] = g_stage_x2;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *reg_a0_as_s8_p;
        *(s8 *)(reg_a5 + 0x1D) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        *(s8 *)(reg_a5 + 0x1C) = (s8) *reg_a0_as_s8_p;
        temp_a1 = (s8 *)(reg_a0_as_s8_p + 1);
        reg_a0_as_s8_p = temp_a1;
        if (g_stage == 4) {
            if (g_enemy_signal_1 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_2 != 0) {
                enemy_remove();
                return;
            }
            if (g_enemy_signal_3 != 0) {
                enemy_remove();
            }
        }
    }
}

s32 func_0018D500();
s32 entity_draw_layer5_zoom();
s32 entity_check_bounds();

void func_0015F290(void) {
    s16 *temp_v1;
    s16 *temp_v1_2;
    s16 *var_a0;
    s16 *var_a1;
    u32 temp_a1;
    u32 temp_a0_2;
    u32 temp_s0;
    u32 temp_s1;
    u8 temp_a0;
    u8 temp_a1_2;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        entity_check_bounds();
        if (cond_flag != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_5:
        *(u16 *)(reg_a6 + 0x22) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a6 + 0x24) = (u16) ENTITY(reg_a6)->x.h;
        var_a0 = (s16 *)(reg_a6);
        reg_d1.b[0] = (*(u8 *)((u8 *)(var_a0) + (1)));
        reg_d1.b[0] |= (*(u8 *)((u8 *)(var_a0) + (0x21)));
        reg_d1.h[0] &= 0x5C;
        var_a1 = (s16 *)(var_a0 + 1);
        if (reg_d1.h[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
            if (((s32) (*(u16 *)((u8 *)(var_a0) + (0x18))) < 0x80) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_14;
        }
        reg_d0.h[0] = 0xA3;
        (*(u8 *)((u8 *)(var_a0) + (1))) &= reg_d0.b[0];
        *(u8 *)(reg_a6 + 0x21) &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
        }
        var_a1 = (s16 *)(reg_a6 + 0x18);
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
        reg_d0.b[0] ^= reg_d2.b[0];
        reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
        var_a0 = (s16 *) *(u16 *)(reg_a6 + 0x38);
        if ((s16)(var_a0) < (s16) reg_d4.h[0]) {
            reg_d4.h[0] = (u16) var_a0;
        }
        ENTITY(reg_a6)->hp.h = (u16) reg_d4.h[0];
        *(u16 *)(reg_a6 + 0x38) = (u16) reg_d4.h[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_14:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            func_001368E0();
            if (g_enemies_stopped == 0) {
                if (g_bullets_blocked == 0) {
                    if ((s16) ENTITY(reg_a6)->y.h >= 0x1000) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                        *(u8 *)(reg_a5 + 0x1F) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x2F);
                            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x21);
                            if (*(u8 *)(reg_a5 + 0x20) == reg_d0.b[0]) {
                                reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                                reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                                if (*(u8 *)(reg_a5 + 2) != 0) {
                                    reg_atmp = (u8 *)(reg_a0);
                                    reg_a0 = (u8 *)(reg_a1);
                                    reg_a1 = (u8 *)(reg_atmp);
                                }
                                temp_v1 = (s16 *)(reg_a0);
                                if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                                    if (*(s16 *)reg_a1 < 0) {
                                        reg_a0 = (u8 *)(reg_a1);
                                        reg_atmp = (u8 *)(temp_v1);
                                        reg_a1 = (u8 *)(temp_v1);
                                        goto block_24;
                                    }
                                } else {
block_24:
                                    temp_a1 = 0xF7C0 & 0xFFFF;
                                    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                    temp_s0 = reg_d2.w;
                                    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                    temp_s1 = reg_d3.w;
                                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                    reg_d0.h[0] += temp_a1;
                                    reg_d1.h[0] += 0x7FFF + 0x7AC1;
                                    direction256_between();
                                    *(u8 *)(reg_a5 + 0x31) = (u8) reg_d1.b[0];
                                    reg_d2.w = temp_s0;
                                    reg_d3.w = temp_s1;
                                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                    reg_d0.h[0] += 0x7FFF + 0x77C1;
                                    reg_d1.h[0] += 0x500;
                                    direction256_between();
                                    *(u8 *)(reg_a5 + 0x30) = (u8) reg_d1.b[0];
                                    goto block_25;
                                }
                            } else {
block_25:
                                reg_d0.w = 0x5000C;
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d4.w = 0;
                                temp_a0 = *(u8 *)(reg_a5 + 0x31);
                                reg_d1.b[0] = temp_a0;
                                reg_d3.w = 0xF7C0FAC0;
                                reg_d0.w = 0x5000C;
                                if (((s32) g_stage >= 3) && (reg_d0.w = 0x5000C, reg_d5.b[0] = *(u8 *)(reg_a5 + 0x21), (*(u8 *)(reg_a5 + 0x20) == reg_d5.b[0]))) {
                                    func_0015EF00();
                                } else {
                                    bullet_fire256_2way();
                                }
                                temp_a1_2 = *(u8 *)(reg_a5 + 0x30);
                                reg_d1.b[0] = temp_a1_2;
                                reg_d3.h[0] = 0x500;
                                reg_d0.w = 0x5000C;
                                if (((s32) g_stage >= 3) && (reg_d0.w = 0x5000C, reg_d5.b[0] = *(u8 *)(reg_a5 + 0x21), (*(u8 *)(reg_a5 + 0x20) == reg_d5.b[0]))) {
                                    func_0015EF60();
                                } else {
                                    bullet_fire256_2way();
                                }
                                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
                                *(u8 *)(reg_a5 + 0x21) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
                                    reg_d0.h[0] = 0x70;
                                    reg_d0.h[0] -= g_rank_6_16;
                                    reg_d0.h[0] -= 4;
                                    *(u8 *)(reg_a5 + 0x1F) = (u8) reg_d0.b[0];
                                }
                            }
                        }
                    }
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x27);
                    *(u8 *)(reg_a5 + 0x27) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x27) = (u8) *(u8 *)(reg_a5 + 0x26);
                        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x25);
                        if (*(u8 *)(reg_a5 + 0x24) == reg_d0.b[0]) {
                            reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                            reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                            switch (*(u8 *)(reg_a5 + 2)) { case 0: break; default:
                                reg_atmp = (u8 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(reg_atmp);
                            }
                            temp_v1_2 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1_2) + (0))) >= 0) {
                                if (*(s16 *)reg_a1 < 0) {
                                    reg_a0 = (u8 *)(reg_a1);
                                    reg_atmp = (u8 *)(temp_v1_2);
                                    reg_a1 = (u8 *)(temp_v1_2);
                                    goto block_42;
                                }
                            } else {
block_42:
                                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d0.h[0] += 0x240;
                                direction_between();
                                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
                                direction_turn_toward();
                                *(u16 *)(reg_a5 + 0x2C) = (u16) reg_d1.h[0];
                                reg_a3 = (u8 *)(D_00259170);
                                reg_d1.h[0] &= 0x3E;
                                reg_d1.h[0] += reg_d1.h[0];
                                *(u16 *)(reg_a5 + 0x28) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                                *(u16 *)(reg_a5 + 0x2A) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                            }
                        }
                    }
                }
            }
            reg_d6.w = 0x60005000;
            entity_draw_layer5_zoom();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0_2 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x7C41;
            reg_d1.h[0] = (u32)temp_a0_2 + 0x7FFF + 0x7C01;
            reg_d2.h[1] = *(u16 *)(reg_a5 + 0x28);
            reg_d2.h[0] = *(u16 *)(reg_a5 + 0x2A);
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer5();
            if ((g_loop == 0) && (D_0028E3EC != 0)) {
                reg_d1.h[1] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.h[1] += 0xE200;
                reg_d1.h[0] += 0x300;
                reg_d2.w = 0x1876;
                reg_d3.h[0] = 0x628;
                reg_d4.h[0] = 0x18;
                sprite_draw_layer4();
            }
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            reg_a0 = (u8 *)(reg_a6 + 0x20);
            enemy_hitbox_debug_draw();
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                *(u8 *)(reg_a5 + 0x23) -= 1;
                switch (reg_tmp.b[0]) {
                case 0:
                    *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x2E);
                    reg_a4 = (u8 *)(D_00259570);
                    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x2C);
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d0.h[0] &= 0x3E;
                    reg_d0.h[0] += reg_d0.h[0];
                    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                    reg_d3.h[1] += 0x240;
                    reg_d0.w = 0x40007;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d4.w = (u32) reg_a6;
                    bullet_fire_3way();
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x25);
                    *(u8 *)(reg_a5 + 0x25) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x25) = (u8) *(u8 *)(reg_a5 + 0x24);
                        reg_d0.h[0] = 0x60;
                        reg_d0.h[0] -= g_rank_5_16;
                        reg_d0.h[0] += 4;
                        *(u8 *)(reg_a5 + 0x23) = (u8) reg_d0.b[0];
                    }
                    return;
                }
            }
        } else {
            reg_d0.w = 0x42;
            score_add();
            func_0018D500();
            reg_d0.w = 0xD;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(u16 *)(reg_a0 + 0x26) = 0xF600;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            reg_d0.h[0] = 8;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(u16 *)(reg_a0 + 0x26) = 0xF600;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x1A) = 0x680;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(s8 *)(reg_a0 + 0x1D) = 0x40;
            enemy_remove();
        }
    }
}

void func_0015FC70(void) {
    enemy_set_entity_count(1);
}

extern s8 D_0025A288[];
extern s8 D_0025A2A0[];
extern s8 D_0025A2C0[];
extern u16 g_scroll_line;

void func_0015FC80(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0_as_s8_p = D_0025A2C0;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0_as_s8_p;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0_as_s8_p = D_0025A2A0;
    reg_d0.w = 0xE;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_loop == 0) {
            reg_d0.b[0] = 0x18;
            reg_d1.b[0] = 0x10;
            if ((s32) g_stage > 0x3) {
                goto block_4;
            }
        } else {
block_4:
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 0x10;
        }
        *(u8 *)(reg_a5 + 0x31) = (u8) reg_d0.b[0];
        *(u8 *)(reg_a5 + 0x30) = (u8) reg_d1.b[0];
        reg_a0_as_s8_p = D_0025A288;
        reg_d0.h[0] = g_stage_x2;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *reg_a0_as_s8_p;
        *(s8 *)(reg_a5 + 0x1D) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        *(s8 *)(reg_a5 + 0x1C) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        if (g_stage == 4) {
            ENTITY(reg_a6)->hp.sh = 0x1000;
            if ((s32) g_scroll_line > 0x2E0) {
                ENTITY(reg_a6)->hp.sh = 0xE80;
            }
        }
    }
}

s32 func_002012B0();
s32 func_00202C50();
extern u16 D_0025A330[];

void func_0015FDE0(void) {
    u32 cnt;
    u8 *ptr;

    enemy_path_step();
    if (enemy_move_end_requested != 0) return;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x1600;
    reg_d0.h[0] += D_0029C068[0];
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x9C00;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9C00;
    if (reg_tmp.h[1] != 0) goto next_20;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7600;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] += 0x1200;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7600;
    if (reg_tmp.h[1] == 0) goto next_30;
next_20:
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_40;
    enemy_remove();
    return;
next_30:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_40:
    *(u16 *)(reg_a6 + 0x22) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a6 + 0x24) = ENTITY(reg_a6)->x.h;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d1.b[0] |= *(u8 *)(reg_a6 + 0x21);
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_50;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
    if (!((s32) ENTITY(reg_a6)->hp.h < 0x5C0)) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    reg_d0.h[0] = 0xA3;
    ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x21) &= reg_d0.b[0];
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
next_60:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
    reg_d0.b[0] ^= reg_d2.b[0];
    reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
    if (!((s16) *(u16 *)(reg_a6 + 0x38) < (s16) reg_d4.h[0])) goto next_80;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x38);
next_80:
    ENTITY(reg_a6)->hp.h = reg_d4.h[0];
    *(u16 *)(reg_a6 + 0x38) = reg_d4.h[0];
    if ((s16) ENTITY(reg_a6)->hp.h < 0) goto next_700;
next_90:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    func_001368E0();
    if (g_enemies_stopped != 0) goto next_500;
    if (g_bullets_blocked != 0) goto next_500;
    if (g_enemies_stopped != 0) goto next_500;
    if (g_bullets_blocked != 0) goto next_500;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto next_500;
    *(u8 *)(reg_a5 + 0x16) = 0;
    if (g_stage == 4) goto next_200;
    func_00202C50();
    reg_d1.h[0] = 0xC00;
    if (g_stage != 4) goto next_150;
    reg_d1.h[0] = 0x1800;
next_150:
    if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) goto next_500;
    *(u8 *)(reg_a5 + 0x16) = 1;
next_200:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_500;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x31);
    reg_a0 = (u8 *) D_0029F260_as_u16_a;
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_240;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_240:
    if (*(s16 *)reg_a0 < 0) goto next_260;
    if (*(s16 *)reg_a1 >= 0) goto next_500;
    ptr = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_260:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xFE00;
    direction256_between();
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d5.w = 0xFE000000;
    reg_d4.w = 0;
    reg_a0 = (u8 *) D_00259870;
    if (g_stage == 4) goto next_265;
    reg_d1.h[0] -= 0x14;
    reg_d7.w = 4;
    reg_d0.w = 0xFFFD000B;
    goto loop_270;
next_265:
    reg_d1.h[0] -= 0x14;
    reg_d7.w = 4;
    reg_d0.w = 0xFFFD000C;
loop_270:
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d5.w;
    bullet_fire256();
    reg_d1.h[0] += 0xA;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (u16) cnt << 0x30) >> 0x30) >= 0) goto loop_270;
    if (g_stage != 4) goto next_500;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
    *(u8 *)(reg_a5 + 0x21) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_500;
    *(u8 *)(reg_a5 + 0x21) = *(u8 *)(reg_a5 + 0x20);
    *(u8 *)(reg_a5 + 0x1F) = 0x40;
next_500:
    entity_draw_layer5();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF400;
    reg_d1.h[1] += 0xF200;
    reg_d1.h[1] += *(u16 *)(reg_a5 + 0x2E);
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x28);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x2A);
    reg_d3.h[0] = 0xE60;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    sprite_draw_layer5();
    if (g_loop != 0) goto next_520;
    if (g_stage == 2) goto next_520;
    if (D_0028E3EC == 0) goto next_520;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x900;
    reg_d1.h[1] += 0xD600;
    reg_d2.w = 0x1879;
    reg_d3.h[0] = 0xA38;
    reg_d4.h[0] = 0x18;
    sprite_draw_layer4();
next_520:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    reg_a0 = reg_a6 + 0x20;
    enemy_hitbox_debug_draw();
    if (g_enemies_stopped != 0) goto block_rts;
    if (g_bullets_blocked != 0) goto block_rts;
    if ((s16) ENTITY(reg_a6)->y.h < 0x1000) goto block_rts;
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x32);
    if (reg_d0.h[0] != 0) goto next_600;
    if (*(u8 *)(reg_a5 + 0x16) == 0) goto next_599;
    *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x22);
    return;
next_599:
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
    *(u8 *)(reg_a5 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x30);
    *(u16 *)(reg_a5 + 0x32) = 1;
block_rts:
    return;
next_600:
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
    reg_a0 = (u8 *) D_0025A330;
    reg_d7.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    if ((s16) reg_d7.h[0] != -1) goto next_660;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
    *(u8 *)(reg_a5 + 0x23) -= 1;
    if (reg_tmp.b[0] == 0) goto next_610;
    return;
next_610:
    *(u16 *)(reg_a5 + 0x2C) -= 2;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d6.h[0] = reg_d7.h[0];
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    reg_d6.h[0] = 0x540;
    reg_d4.w = 0;
    reg_a0 = (u8 *) D_00259770;
    reg_d0.w = 0xFFFA0004;
    reg_d7.w = 5;
    reg_d5.w = 0x40000;
    if (g_stage != 4) goto loop_620;
    reg_d5.w = 0x30000;
loop_620:
    func_002012B0();
    reg_d1.b[0] += 0x7E;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d6.w;
    bullet_fire256_fixed();
    if (reg_d7.h[0] > 4) goto next_6205;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d6.w;
    reg_d1.b[0] += 0xF0;
    bullet_fire256_2way();
    if (reg_d7.h[0] > 3) goto next_6205;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d6.w;
    reg_d1.b[0] += 0xF0;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0x20;
next_6205:
    reg_d0.w += reg_d5.w;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (u16) cnt << 0x30) >> 0x30) >= 0) goto loop_620;
    reg_d0.w = 0xFFFA0004;
    reg_d6.h[0] = 0xFAC0;
    reg_d7.w = 5;
loop_640:
    func_002012B0();
    reg_d1.b[0] += 0x7F;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d6.w;
    bullet_fire256_fixed();
    if (reg_d7.h[0] > 4) goto next_6405;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d6.w;
    reg_d1.b[0] += 0x10;
    bullet_fire256_2way();
    if (reg_d7.h[0] > 3) goto next_6405;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w += reg_d6.w;
    reg_d1.b[0] += 0x10;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xE0;
next_6405:
    reg_d0.w += reg_d5.w;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (u16) cnt << 0x30) >> 0x30) >= 0) goto loop_640;
next_660:
    *(u16 *)(reg_a5 + 0x2E) = reg_d7.h[0];
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x2C);
    *(u16 *)(reg_a5 + 0x2C) -= 2;
    if (!((s32) reg_tmp.h[0] < 2)) goto next_680;
    *(u16 *)(reg_a5 + 0x2C) = 0x48;
    *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x22);
    *(u16 *)(reg_a5 + 0x32) = 0;
next_680:
    return;
next_700:
    reg_d0.w = 0x320;
    score_add();
    func_0018D580();
    reg_d0.w = 5;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF600;
    *(u16 *)(reg_a0 + 0x28) = 0xFA00;
    *(s8 *)(reg_a0 + 0x1D) = 0x40;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x1A) = 0x4A0;
    reg_d0.w = 5;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xF600;
    *(s16 *)(reg_a0 + 0x28) = 0x500;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x1A) = 0x460;
    reg_d0.h[0] = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    cnt = ENTITY(reg_a6)->x.h;
    *(u16 *)(reg_a0 + 4) = cnt;
    *(s16 *)(reg_a0 + 0x1E) = 0x10;
    *(u16 *)(reg_a0 + 0x26) = 0xFA00;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    enemy_remove();
}

void func_00160D10(void) {
    enemy_set_entity_count(1);
}

extern u16 D_0025A380[];
extern u16 D_0025A390[];
extern u16 D_0025A3B0[];
extern u16 D_0025A430[];
extern u16 g_rank_8_16;
extern u16 g_rank_11_16;

void func_00160D20(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_0025A3B0);
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(D_0025A390);
    reg_d0.w = 0xD;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d0.b[0] = 6;
        reg_d1.b[0] = 5;
        if ((s32) g_stage > 1) {
            reg_d1.b[0] = 5;
            reg_d0.b[0] = 2;
        }
        *(u8 *)(reg_a5 + 0x2B) = (u8) reg_d0.b[0];
        *(u8 *)(reg_a5 + 0x2A) = (u8) reg_d1.b[0];
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x28);
        reg_a0 = (u8 *)(D_0025A430);
        *(u16 *)(reg_a6 + 0x2A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x2C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = g_rank_11_16;
        *(u8 *)(reg_a5 + 0x2F) -= reg_d0.b[0];
        reg_d0.h[0] = g_rank_8_16;
        *(u8 *)(reg_a5 + 0x1F) -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025A380);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        *(s8 *)(reg_a5 + 0x1D) = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(s8 *)(reg_a5 + 0x1C) = *(s8 *)reg_a0;
        reg_a0 += 1;
        if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) {
            *(s16 *)(reg_a6 + 0x30) = 1;
            reg_d0.w = 0;
            reg_d0.b[0] = ENTITY(reg_a6)->misc.b.user;
            reg_d0.b[0] -= 1;
            *(u16 *)(reg_a6 + 0x32) = (u16) reg_d0.h[0];
            if (reg_d0.h[0] == 0) {
                reg_a0 = (u8 *)reg_a6 + 0x12;
            } else {
                reg_a0 = (u8 *)reg_a6 + 0x10;
            }
            *(u16 *)reg_a0 = 0xF000;
            ENTITY(reg_a6)->misc.b.user = 0U;
        }
        if (g_stage == 4) {
            ENTITY(reg_a6)->hp.sh = 0x1400;
        }
    }
}

s32 func_00125EF0();
s32 entity_draw_layer1();
s32 sprite_draw_layer1();
s32 rng_next();
s32 func_00201200();
s32 func_00211550();
extern u16 D_0025A440[];
extern u16 D_0025A460[];
extern u16 D_0028C9E0;
extern u16 g_rank_1_16;

void func_00160FA0(void) {
    s16 *temp_a0;
    s16 *temp_v1_3;
    u16 temp_v1_2;
    s64 temp_v0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_5;
    u16 temp_a0_6;
    u16 temp_a0_7;
    u16 temp_a1_3;
    u16 temp_a1_4;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 temp_a3;
    u16 temp_v1;
    u8 temp_a1;
    u8 temp_a1_2;
    u8 temp_v1_4;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        if ((*(u16 *)(reg_a6 + 0x30) != 0) && (ENTITY(reg_a6)->flags.b[1] & 0x20)) {
            reg_a0 = (u8 *)(reg_a6 + 0x12);
            if (*(u16 *)(reg_a6 + 0x32) != 0) {
                reg_a0 = (u8 *)(reg_a6 + 0x10);
                reg_d2.h[0] *= 0xFFFF;
            }
            temp_v1 = *(u16 *)reg_a0;
            if ((s16)temp_v1 < 0x1000) {
                *(u16 *)reg_a0 += reg_d2.h[0];
                if ((s32) *(u16 *)reg_a0 < 0x800) {
                    ENTITY(reg_a6)->hp.h = 0x2D00U;
                }
            }
        }
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7200;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1600;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0x7200;
        reg_tmp.w += reg_tmp1.h[0];
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto block_12;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_12:
        temp_a0 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(temp_a0) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
            if (((s32) (*(u16 *)((u8 *)(temp_a0) + (0x18))) < 0xB40) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_19;
        }
        (*(u8 *)((u8 *)(temp_a0) + (1))) &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
        }
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_19:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            func_001368E0();
            if (g_enemies_stopped == 0) {
                ENTITY(reg_a6)->offset_y.h = 0xF000;
                if ((s32) ENTITY(reg_a6)->move.b.dir < 0x40) {
                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x27);
                    *(u8 *)(reg_a6 + 0x27) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a6 + 0x27) = (u8) *(u8 *)(reg_a6 + 0x26);
                        ENTITY(reg_a6)->offset_y.h = 0xF040;
                        if (ENTITY(reg_a6)->move.b.dir == 0) {
                            reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x28);
                            *(u16 *)(reg_a6 + 0x28) -= 4;
                            if ((s32) reg_tmp.h[0] < 4) {
                                *(u16 *)(reg_a6 + 0x28) = 0xCU;
                            }
                        } else {
                            *(u16 *)(reg_a6 + 0x28) += 4;
                            if (*(u16 *)(reg_a6 + 0x28) == 0x10) {
                                *(u16 *)(reg_a6 + 0x28) = 0U;
                            }
                        }
                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x28);
                        reg_a0 = (u8 *)(D_0025A430);
                        *(u16 *)(reg_a6 + 0x2A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        *(u16 *)(reg_a6 + 0x2C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    }
                }
            }
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && (g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
                temp_v1_2 = reg_d0.h[0] & 0xFFFF;
                if (reg_d0.h[0] == 0) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                    *(u8 *)(reg_a5 + 0x1F) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x1F) = 8U;
                        *(u16 *)(reg_a5 + 0x18) = 1U;
                    }
                } else if (temp_v1_2 == 1) {
                    *(u16 *)(reg_a5 + 0x22) += 2;
                    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x22);
                    reg_a0 = (u8 *)(D_0025A440);
                    *(u16 *)(reg_a5 + 0x24) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                    if (reg_d0.h[0] == 0x14) {
                        *(u16 *)(reg_a5 + 0x18) = 2U;
                        *(u16 *)(reg_a5 + 0x22) = 0x10U;
                    }
                } else if (temp_v1_2 == 2) {
                    *(u16 *)(reg_a5 + 0x26) = 0x2C0U;
                    *(u16 *)(reg_a5 + 0x28) = 0xF940U;
                    *(u16 *)(reg_a6 + 0x2E) = 0xF000U;
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                    *(u8 *)(reg_a5 + 0x1F) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        reg_d0.h[0] = 5;
                        reg_d1.h[0] = g_rank_1_16;
                        reg_d1.h[0] >>= 3;
                        reg_d0.h[0] -= reg_d1.h[0];
                        *(u8 *)(reg_a5 + 0x1F) = (u8) reg_d0.b[0];
                        reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                        reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                        if (*(u8 *)(reg_a5 + 2) != 0) {
                            reg_atmp = (u8 *)(reg_a0);
                            reg_a0 = (u8 *)(reg_a1);
                            reg_a1 = (u8 *)(reg_atmp);
                        }
                        temp_v1_3 = (s16 *)(reg_a0);
                        if ((*(s16 *)((u8 *)(temp_v1_3) + (0))) >= 0) {
                            if (*(s16 *)reg_a1 < 0) {
                                reg_a0 = (u8 *)(reg_a1);
                                reg_atmp = (u8 *)(temp_v1_3);
                                reg_a1 = (u8 *)(temp_v1_3);
                                goto block_55;
                            }
                        } else {
block_55:
                            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0xE00;
                            if (!(ENTITY(reg_a6)->flags.b[0] & 0x40)) {
                                reg_d1.h[0] += 0x400;
                                direction256_between();
                                reg_d7.h[0] = reg_d1.h[0];
                                rng_next();
                                reg_d1.b[0] += reg_d0.b[0];
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
                                reg_a0 = (u8 *)(&D_0028C9E0);
                                reg_d3.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                                reg_tmp3.h[0] = reg_d3.h[0];
                                reg_d3.h[0] = 0x400;
                                reg_d3.h[1] = reg_tmp3.h[0];
                                reg_d4.w = 0;
                                reg_d0.w = 0x30013;
                                bullet_fire256_2way();
                                reg_d1.h[0] -= 0x10;
                                func_00201200();
                                if (reg_d5.h[0] != 0) {
                                    reg_d1.h[0] += 0x20;
                                }
                                bullet_fire256();
                            } else {
                                reg_d1.h[0] += 0xFC00 & 0xFFFF;
                                direction256_between();
                                reg_d7.h[0] = reg_d1.h[0];
                                rng_next();
                                reg_d1.b[0] += reg_d0.b[0];
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2C);
                                reg_a0 = (u8 *)(&D_0028C9E0);
                                reg_d3.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                                reg_tmp3.h[0] = reg_d3.h[0];
                                reg_d3.h[0] = 0xFC00;
                                reg_d3.h[1] = reg_tmp3.h[0];
                                reg_d4.w = 0;
                                reg_d0.w = 0x30013;
                                bullet_fire256_2way();
                                reg_d1.h[0] -= 0x10;
                                func_00201200();
                                if (reg_d5.h[0] != 0) {
                                    reg_d1.h[0] += 0x20;
                                }
                                bullet_fire256();
                            }
                        }
                        *(u16 *)(reg_a5 + 0x26) = 0x280U;
                        *(u16 *)(reg_a5 + 0x28) = 0xF980U;
                        *(u16 *)(reg_a6 + 0x2E) = 0xEFC0U;
                        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x2C);
                        *(u16 *)(reg_a5 + 0x2C) -= 2;
                        if ((s32) reg_tmp.h[0] < 2) {
                            *(u16 *)(reg_a5 + 0x2C) = 4U;
                        }
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
                        *(u8 *)(reg_a5 + 0x21) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
                            temp_v1_4 = ENTITY(reg_a6)->flags.b[0];
                            if (!(temp_v1_4 & 0x40)) {
                                ENTITY(reg_a6)->flags.b[0] = (u8) (temp_v1_4 | 0x40);
                            } else {
                                ENTITY(reg_a6)->flags.b[0] = (u8) (temp_v1_4 & 0xBF);
                                reg_d0.h[0] = 0x40;
                                reg_d0.h[0] -= g_rank_4_16;
                                *(u8 *)(reg_a5 + 0x1F) = (u8) reg_d0.b[0];
                                *(u16 *)(reg_a5 + 0x18) = 3U;
                            }
                        }
                    }
                } else {
                    *(u16 *)(reg_a5 + 0x22) -= 2;
                    if (*(u16 *)(reg_a5 + 0x22) == 0) {
                        *(u16 *)(reg_a5 + 0x18) = 0U;
                    }
                    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x22);
                    reg_a0 = (u8 *)(D_0025A440);
                    *(u16 *)(reg_a5 + 0x24) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                }
            }
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0_4 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x6E01;
            reg_d1.h[0] = (u32)temp_a0_4 + 0x7FFF + 0x7801;
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x2A);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x2C);
            reg_d3.h[0] = 0x440;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer1();
            entity_draw_layer1();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += 0x7FFF + 0x7901;
            reg_d1.h[1] += *(u16 *)(reg_a6 + 0x2E);
            reg_d2.w = 0x18E4;
            reg_d3.h[0] = 0x1438;
            sprite_draw_layer1();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += *(u16 *)(reg_a5 + 0x26);
            reg_d1.h[0] += *(u16 *)(reg_a5 + 0x24);
            reg_d1.h[1] += 0x600;
            reg_d2.w = 0x18E6;
            reg_d3.h[0] = 0x810;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer1();
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += *(u16 *)(reg_a5 + 0x28);
            reg_d1.h[0] -= *(u16 *)(reg_a5 + 0x24);
            reg_d2.w = 0x18E5;
            sprite_draw_layer1();
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            return;
        }
        reg_d0.w = 0x162;
        score_add();
        func_0018D580();
        reg_d1.h[0] = 0;
        reg_d2.w = 0xF8000000;
        reg_d0.w = 0xC;
        func_00211550();
        reg_d2.w = 0x08000000;
        func_00211550();
        reg_d0.w = 8;
        reg_a4 = (u8 *)(D_0025A460);
        reg_d6.w = 6;
        do {
            reg_d1.h[1] = *(u16 *)reg_a4;
            reg_a4 += 2;
            reg_d1.h[0] = *(u16 *)reg_a4;
            reg_a4 += 2;
            func_00125EF0();
        } while ((s16)(--reg_d6.h[0]) >= 0);
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        temp_a3 = ENTITY(reg_a6)->x.h;
        *(u16 *)(reg_a0 + 4) = temp_a3;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 1;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(s16 *)(reg_a0 + 0x26) = 0x400;
        *(s16 *)(reg_a0 + 0x28) = 0;
        *(s16 *)(reg_a0 + 0x10) = 1;
        reg_d0.w = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 1;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(u16 *)(reg_a0 + 0x26) = 0xFA00;
        *(u16 *)(reg_a0 + 0x28) = 0xFE00;
        *(s16 *)(reg_a0 + 0x1A) = 0x3A0;
        *(s16 *)(reg_a0 + 0x10) = 1;
        reg_d0.w = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 1;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(u16 *)(reg_a0 + 0x26) = 0xFA00;
        *(s16 *)(reg_a0 + 0x28) = 0x200;
        *(s16 *)(reg_a0 + 0x1A) = 0x360;
        *(s16 *)(reg_a0 + 0x10) = 1;
        reg_d0.w = 0xC;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 1;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(u16 *)(reg_a0 + 0x26) = 0xFA00;
        *(u16 *)(reg_a0 + 0x28) = 0xFE00;
        *(s16 *)(reg_a0 + 0x10) = 1;
        reg_d0.h[0] = 0x85;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 1;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(u16 *)(reg_a0 + 0x26) = 0xF600;
        *(s16 *)(reg_a0 + 0x28) = 0;
        *(s16 *)(reg_a0 + 0x1A) = 0x780;
        *(s16 *)(reg_a0 + 0x10) = 1;
        enemy_remove();
    }
}

extern u8 D_0025A490[];
extern u8 D_0025A4B0[];

void func_00161CC0(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = D_0025A4B0;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0 = D_0025A490;
    reg_d0.w = 0xA;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_a2 = (u8 *)(D_00259170);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x7FFF + 0x7901;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        *(u8 *)(reg_a5 + 0x28) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x24) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a5 + 0x26) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.h[0] = g_rank_4_16;
        *(u8 *)(reg_a5 + 0x1F) -= reg_d0.b[0];
    }
}

void func_00161E40(void) {
    enemy_set_entity_count(1);
}

extern s8 D_0025A480[];

void func_00161E50(void) {
    func_00161CC0();
    reg_a0_as_s8_p = D_0025A480;
    reg_d0.h[0] = g_stage_x2;
    reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
    ENTITY(reg_a6)->attr.sb.palette = (s8) *reg_a0_as_s8_p;
    *(s8 *)(reg_a5 + 0x1D) = (s8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    *(s8 *)(reg_a5 + 0x1C) = (s8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
}

s32 bullet_fire_fixed();
s32 func_0016A9B0();
s32 func_00203120();
extern u16 g_two_player_game;

void func_00161EE0(void) {
    s16 *temp_v1;
    s16 *var_a0;
    s16 *var_a1;
    u32 temp_a0;
    u32 temp_a2_2;
    u32 temp_a2_3;
    u32 temp_a3;
    u32 temp_a0_3;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        func_00203120();
        if (cond_flag != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_5:
        *(u16 *)(reg_a6 + 0x22) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a6 + 0x24) = (u16) ENTITY(reg_a6)->x.h;
        var_a0 = (s16 *)(reg_a6);
        reg_d1.b[0] = (*(u8 *)((u8 *)(var_a0) + (1)));
        reg_d1.b[0] |= (*(u8 *)((u8 *)(var_a0) + (0x21)));
        reg_d1.h[0] &= 0x5C;
        var_a1 = (s16 *)(var_a0 + 1);
        if (reg_d1.h[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
            if (((s32) (*(u16 *)((u8 *)(var_a0) + (0x18))) < 0x1C0) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_14;
        }
        reg_d0.h[0] = 0xA3;
        (*(u8 *)((u8 *)(var_a0) + (1))) &= reg_d0.b[0];
        *(u8 *)(reg_a6 + 0x21) &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
        }
        var_a1 = (s16 *)(reg_a6 + 0x18);
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
        reg_d0.b[0] ^= reg_d2.b[0];
        reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
        var_a0 = (s16 *) *(u16 *)(reg_a6 + 0x38);
        if ((s16)(var_a0) < (s16) reg_d4.h[0]) {
            reg_d4.h[0] = (u16) var_a0;
        }
        ENTITY(reg_a6)->hp.h = (u16) reg_d4.h[0];
        *(u16 *)(reg_a6 + 0x38) = (u16) reg_d4.h[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_14:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            func_001368E0();
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                *(u8 *)(reg_a5 + 0x23) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x21);
                    if (*(u8 *)(reg_a5 + 0x20) == reg_d0.b[0]) {
                        reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                        reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                        switch (*(u8 *)(reg_a5 + 2)) { case 0: break; default:
                            reg_atmp = (u8 *)(reg_a0);
                            reg_a0 = (u8 *)(reg_a1);
                            reg_a1 = (u8 *)(reg_atmp);
                        }
                        temp_v1 = (s16 *)(reg_a0);
                        if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                            if (*(s16 *)reg_a1 < 0) {
                                reg_a0 = (u8 *)(reg_a1);
                                reg_atmp = (u8 *)(temp_v1);
                                reg_a1 = (u8 *)(temp_v1);
                                goto block_23;
                            }
                        } else {
block_23:
                            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d0.h[0] += 0x7FFF + 0x7901;
                            direction_between();
                            reg_d0.h[0] = *(u16 *)(reg_a5 + 0x28);
                            direction_turn_toward();
                            *(u16 *)(reg_a5 + 0x28) = (u16) reg_d1.h[0];
                            reg_a3 = (u8 *)(D_00259170);
                            reg_d1.h[0] &= 0x3E;
                            reg_d1.h[0] += reg_d1.h[0];
                            *(u16 *)(reg_a5 + 0x24) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                            *(u16 *)(reg_a5 + 0x26) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                        }
                    }
                }
            }
            entity_draw_layer5();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x7301;
            reg_d1.h[0] = (u32)temp_a0 + 0x7FFF + 0x7C01;
            reg_d2.h[1] = *(u16 *)(reg_a5 + 0x24);
            reg_d2.h[0] = *(u16 *)(reg_a5 + 0x26);
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer5();
            if ((g_loop == 0) && (D_0028E3EC != 0) && (g_stage != 2)) {
                reg_d1.h[1] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.h[1] += 0xE400;
                reg_d1.h[0] += 0x400;
                reg_d2.w = 0x1936;
                reg_d3.h[0] = 0x820;
                reg_d4.h[0] = 0x18;
                sprite_draw_layer4();
            }
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            reg_a0 = (u8 *)(reg_a6 + 0x20);
            enemy_hitbox_debug_draw();
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                *(u8 *)(reg_a5 + 0x1F) -= 1;
                switch (reg_tmp.b[0]) {
                case 0:
                    reg_d0.h[0] = 6;
                    *(u8 *)(reg_a5 + 0x1F) = (u8) reg_d0.b[0];
                    reg_a4 = (u8 *)(D_00259570);
                    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x28);
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d0.h[0] &= 0x3E;
                    reg_d0.h[0] += reg_d0.h[0];
                    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                    temp_a0_3 = reg_d3.w;
                    reg_d3.w = temp_a0_3 + 0xF9000000;
                    reg_d0.w = 0xFFFF000D;
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    bullet_fire_fixed();
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
                    *(u8 *)(reg_a5 + 0x21) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
                        reg_d0.h[0] = 0x50;
                        reg_d0.h[0] -= g_rank_2_16;
                        *(u8 *)(reg_a5 + 0x1F) = (u8) reg_d0.b[0];
                    }
                    return;
                }
            }
        } else {
            reg_d0.w = 0x25;
            score_add();
            reg_d0.w = 0;
            if (*(u8 *)(reg_a5 + 0xD) == 0x86) {
                reg_d0.w = 8;
            }
            func_0016A9B0();
            if (g_two_player_game == 0) {
                if (reg_d0.h[0] != 8) {
                    func_0016A9B0();
                }
            }
            reg_d0.w = 5;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a3 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a3;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(s16 *)(reg_a0 + 0x26) = 0x200;
            *(s16 *)(reg_a0 + 0x28) = 0x200;
            reg_d0.w = 0xC;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a2_2 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a2_2;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u16 *)(reg_a0 + 0x26) = 0xF600;
            reg_d0.h[0] = 0x84;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a2_3 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a2_3;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u16 *)(reg_a0 + 0x26) = 0xEE00;
            *(u16 *)(reg_a0 + 0x28) = 0xFE00;
            func_0018D500();
            enemy_remove();
        }
    }
}

void func_00162690(void) {
    enemy_set_entity_count(1);
}

extern s8 D_0025A518[];

void func_001626A0(void) {
    func_00161CC0();
    reg_a0_as_s8_p = D_0025A518;
    reg_d0.h[0] = g_stage_x2;
    reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
    ENTITY(reg_a6)->attr.sb.palette = (s8) *reg_a0_as_s8_p;
    *(s8 *)(reg_a5 + 0x1D) = (s8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    *(s8 *)(reg_a5 + 0x1C) = (s8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
}

void func_00162730(void) {
    enemy_set_entity_count(0);
}

extern u8 D_0025A530[];
extern u8 D_0025A550[];
extern u8 D_002623B0[];

extern void sprite_palette_load(void);

void func_00162740(void)
{
    extern void enemy_set_task_work(void);
    extern void enemy_init_entities(void);
    reg_a0 = D_0025A550;
    enemy_init_entities();

    reg_a0 = D_0025A530;
    reg_d0.w = 8;
    enemy_set_task_work();

    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = reg_tmp.h[0];

    reg_a0 = D_002623B0;
    reg_d0.h[0] = 0x16;
    sprite_palette_load();
}

s32 bullet_fire();
s32 func_00137C10();
s32 func_00145D40();
s32 entity_draw_layer2();
s32 func_00201D10();
s32 func_00202180();
s32 aim256_at_player();
s32 func_00202D50();
s32 func_00203670();
extern u16 D_0028E3F0;

void func_001627C0(void) {
    u8 *ptr;
    u32 save_d0, save_d1, save_d2, save_d3, save_d4, save_d5, save_d6, save_d7;
    u8 *save_a0, *save_a1, *save_a2, *save_a3, *save_a4, *save_a5, *save_a6;

    func_00202D50();
    if (cond_flag == 0) {
        reg_d0.w = 0x7F;
        reg_d0.h[0] &= D_0028E3F0;
        if (reg_d0.h[0] == 0) {
            reg_d0.w = 7;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            func_00202180();
            reg_d0.w = 0;
            func_00137C10();
            if ((s32) reg_d0.b[0] < 0x1B) {
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d4.w = (u32) reg_a6;
                reg_d3.w = 0;
                reg_d5.w = 0;
                bullet_fire();
                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.h[0] += 0x800;
                aim256_at_player();
                reg_d0.w = 0;
                func_00137C10();
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0x800;
                reg_d4.w = (u32) reg_a6;
                reg_d5.w = 0;
            }
        }
    }
    func_00203670();
    reg_d1.w = 0x5C;
    ptr = (u8 *)(reg_a6 + 1);
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) {
        reg_d0.b[0] = 0;
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x18);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1A);
        if (((u32) reg_tmp.w < 0x1FFFFU) && (D_0028E8B8 == 0)) {
            reg_d0.w = 0x19;
        }
    } else {
        ENTITY(reg_a6)->flags.b[1] &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = 0;
        }
        reg_d0.b[0] ^= 0x1F;
        reg_d5.h[0] = ENTITY(reg_a6)->hp.h;
        reg_d6.w = 0x7FFF;
        ENTITY(reg_a6)->hp.h = (u16) reg_d6.h[0];
        ptr = (u8 *)(reg_a5);
        reg_d6.h[0] -= reg_d5.h[0];
        reg_tmp.h[1] = (*(u16 *)((u8 *)(ptr) + (0x18)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(ptr) + (0x1A)));
        reg_tmp.w -= reg_d6.w;
        (*(u16 *)((u8 *)(ptr) + (0x18))) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0x1A) = (u16) reg_tmp.h[0];
    }
    ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
    entity_draw_layer2();
    reg_d0.w = 0x20;
    reg_d1.h[0] = D_0028E3F0;
    reg_d1.h[0] &= 0x7E;
    reg_d1.h[0] >>= 1;
    reg_d7.h[0] = reg_d1.h[0];
    func_00201D10();
    save_d0 = reg_d0.w; save_d1 = reg_d1.w; save_d2 = reg_d2.w; save_d3 = reg_d3.w;
    save_d4 = reg_d4.w; save_d5 = reg_d5.w; save_d6 = reg_d6.w; save_d7 = reg_d7.w;
    save_a0 = reg_a0; save_a1 = reg_a1; save_a2 = reg_a2; save_a3 = reg_a3;
    save_a4 = reg_a4; save_a5 = reg_a5; save_a6 = reg_a6;
    reg_d3.h[0] = reg_d7.h[0];
    reg_d1.h[0] = 0x12;
    reg_d0.h[0] = 0xE;
    reg_d5.h[0] = 0;
    func_00145D40();
    reg_d0.w = save_d0; reg_d1.w = save_d1; reg_d2.w = save_d2; reg_d3.w = save_d3;
    reg_d4.w = save_d4; reg_d5.w = save_d5; reg_d6.w = save_d6; reg_d7.w = save_d7;
    reg_a0 = save_a0; reg_a1 = save_a1; reg_a2 = save_a2; reg_a3 = save_a3;
    reg_a4 = save_a4; reg_a5 = save_a5; reg_a6 = save_a6;
    save_d0 = reg_d0.w; save_d1 = reg_d1.w; save_d2 = reg_d2.w; save_d3 = reg_d3.w;
    save_d4 = reg_d4.w; save_d5 = reg_d5.w; save_d6 = reg_d6.w; save_d7 = reg_d7.w;
    save_a0 = reg_a0; save_a1 = reg_a1; save_a2 = reg_a2; save_a3 = reg_a3;
    save_a4 = reg_a4; save_a5 = reg_a5; save_a6 = reg_a6;
    reg_d3.h[0] = reg_d2.h[0];
    reg_d1.h[0] = 0x11;
    reg_d0.h[0] = 0xE;
    reg_d5.h[0] = 0;
    func_00145D40();
    reg_d0.w = save_d0; reg_d1.w = save_d1; reg_d2.w = save_d2; reg_d3.w = save_d3;
    reg_d4.w = save_d4; reg_d5.w = save_d5; reg_d6.w = save_d6; reg_d7.w = save_d7;
    reg_a0 = save_a0; reg_a1 = save_a1; reg_a2 = save_a2; reg_a3 = save_a3;
    reg_a4 = save_a4; reg_a5 = save_a5; reg_a6 = save_a6;
    save_d0 = reg_d0.w; save_d1 = reg_d1.w; save_d2 = reg_d2.w; save_d3 = reg_d3.w;
    save_d4 = reg_d4.w; save_d5 = reg_d5.w; save_d6 = reg_d6.w; save_d7 = reg_d7.w;
    save_a0 = reg_a0; save_a1 = reg_a1; save_a2 = reg_a2; save_a3 = reg_a3;
    save_a4 = reg_a4; save_a5 = reg_a5; save_a6 = reg_a6;
    reg_d1.h[0] = 0x10;
    reg_d0.h[0] = 0xE;
    reg_d5.h[0] = 0;
    func_00145D40();
    reg_d0.w = save_d0; reg_d1.w = save_d1; reg_d2.w = save_d2; reg_d3.w = save_d3;
    reg_d4.w = save_d4; reg_d5.w = save_d5; reg_d6.w = save_d6; reg_d7.w = save_d7;
    reg_a0 = save_a0; reg_a1 = save_a1; reg_a2 = save_a2; reg_a3 = save_a3;
    reg_a4 = save_a4; reg_a5 = save_a5; reg_a6 = save_a6;
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
}

void func_00162C70(void) {
    enemy_set_entity_count(1);
}

extern u16 D_002590F0[];
extern u16 D_0025A570[];
extern u16 D_0025A580[];
extern u16 D_0025A5A0[];
extern u16 D_0025A610[];

void func_00162C80(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_0025A5A0);
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(D_0025A580);
    reg_d0.w = 0xF;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_a2 = (u8 *)(D_002590F0);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x300;
        reg_d1.h[0] += 0x5C0;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        *(u8 *)(reg_a5 + 0x28) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x24) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a5 + 0x26) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x300;
        reg_d1.h[0] += 0x7FFF + 0x79C1;
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        *(u8 *)(reg_a5 + 0x2E) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x2A) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a5 + 0x2C) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d1.b[0] = 4;
        if ((s32) g_stage > 1) {
            reg_d1.b[0] = 4;
        }
        *(u8 *)(reg_a5 + 0x30) = (u8) reg_d1.b[0];
        if (g_loop != 0) {
            *(u8 *)(reg_a5 + 0x21) += 1;
            *(u8 *)(reg_a5 + 0x20) += 1;
        }
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x28);
        reg_a0 = (u8 *)(D_0025A610);
        *(u16 *)(reg_a6 + 0x2A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x2C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = g_rank_8_16;
        *(u8 *)(reg_a5 + 0x1F) -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025A570);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        *(s8 *)(reg_a5 + 0x1D) = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(s8 *)(reg_a5 + 0x1C) = *(s8 *)reg_a0;
        reg_a0 += 1;
        if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) {
            *(s16 *)(reg_a6 + 0x2E) = 1;
            *(u8 *)(reg_a6 + 0x30) = (u8) ENTITY(reg_a6)->misc.b.user;
            if (*(u8 *)(reg_a6 + 0x30) == 0) {
                reg_a0 = reg_a6 + 0x16;
            } else {
                reg_a0 = reg_a6 + 0x14;
            }
            *(u16 *)reg_a0 = 0xF400;
            ENTITY(reg_a6)->misc.b.user = 0U;
        }
    }
}

s32 bullet_fire_2way();
s32 func_00170A60();
s32 func_00170D00();
extern u16 D_002594F0[];
extern u16 D_0025A620[];

void func_001630A0(void) {
    s32 func_00170BE0();
    u8 bits;
    u8 *ptr;
    u32 saved;

    enemy_path_step();
    if (enemy_move_end_requested != 0) {
        return;
    }
    if (*(u16 *)(reg_a6 + 0x2E) == 0) goto next_90;
    if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) goto next_90;
    reg_a0 = reg_a6 + 0x16;
    if (*(u16 *)(reg_a6 + 0x30) == 0) goto next_20;
    reg_a0 = reg_a6 + 0x14;
    reg_d3.h[0] *= 0xFFFF;
next_20:
    if (!((s16) *(u16 *)reg_a0 < 0xC00)) goto next_90;
    *(u16 *)reg_a0 += reg_d3.h[0];
next_90:
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1400;
    reg_d0.h[0] += D_0029C068[0];
    reg_tmp1.h[0] = 0xA000;
    reg_tmp.h[0] = reg_d0.h[0];
    saved = reg_tmp.w;
    reg_tmp.w = saved + reg_tmp1.w;
    reg_d0.h[0] += 0xA000;
    if (reg_tmp.h[1] != 0) goto next_120;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x7800;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    saved = reg_tmp.h[0];
    reg_d0.h[0] += 0xC00;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7800;
    reg_d0.h[1] = saved;
    if (reg_tmp.h[1] == 0) goto next_130;
next_120:
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_140;
    enemy_remove();
    return;
next_130:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_140:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) goto next_150;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
    if (!((s32) ENTITY(reg_a6)->hp.h < 0x4A0)) goto next_190;
    if (D_0028E8B8 != 0) goto next_190;
    reg_d0.w = 0x19;
    goto next_190;
next_150:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] != 0x19) goto next_160;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
next_160:
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
    reg_d0.b[0] ^= reg_d2.b[0];
    if (ENTITY(reg_a6)->hp.sh < 0) goto block_d;
next_190:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    func_001368E0();
    if (g_enemies_stopped != 0) goto next_280;
    ENTITY(reg_a6)->offset_y.h = 0xF400;
    if (!((s32) ENTITY(reg_a6)->move.b.dir < 0x40)) goto next_280;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x27);
    *(u8 *)(reg_a6 + 0x27) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_280;
    *(u8 *)(reg_a6 + 0x27) = *(u8 *)(reg_a6 + 0x26);
    ENTITY(reg_a6)->offset_y.h = 0xF3C0;
    if (ENTITY(reg_a6)->move.b.dir != 0x10) goto next_250;
    *(u16 *)(reg_a6 + 0x28) += 4;
    if (*(u16 *)(reg_a6 + 0x28) != 0x10) goto next_260;
    *(u16 *)(reg_a6 + 0x28) = 0;
    goto next_260;
next_250:
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x28);
    *(u16 *)(reg_a6 + 0x28) -= 4;
    if (!((s32) reg_tmp.h[0] < 4)) goto next_260;
    *(u16 *)(reg_a6 + 0x28) = 0xC;
next_260:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_a0 = (u8 *) D_0025A610;
    *(u16 *)(reg_a6 + 0x2A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x2C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_280:
    if (g_enemies_stopped != 0) goto block_b;
    if (g_bullets_blocked != 0) goto block_b;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
    *(u8 *)(reg_a5 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_b;
    *(u8 *)(reg_a5 + 0x23) = *(u8 *)(reg_a5 + 0x22);
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x21);
    if (*(u8 *)(reg_a5 + 0x20) != reg_d0.b[0]) goto block_b;
    reg_a0 = (u8 *) D_0029F260_as_u16_a;
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    if (*(u8 *)(reg_a5 + 2) == 0) goto next_320;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_320:
    ptr = reg_a0;
    if ((*(s16 *)ptr) < 0) goto next_340;
    if ((*(s16 *)reg_a1) >= 0) goto block_b;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_340:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_a3 = (u8 *) D_002590F0;
    bits = ENTITY(reg_a6)->flags.b[0];
    if (!(bits & 0x40)) goto next_350;
    ENTITY(reg_a6)->flags.b[0] = bits & 0xBF;
    goto next_380;
next_350:
    ENTITY(reg_a6)->flags.b[0] = bits | 0x40;
    reg_d0.h[0] += 0x300;
    reg_d1.h[0] += 0x5C0;
    direction_between();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x28);
    direction_turn_toward();
    *(u16 *)(reg_a5 + 0x28) = reg_d1.h[0];
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    *(u16 *)(reg_a5 + 0x24) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    *(u16 *)(reg_a5 + 0x26) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
    goto block_b;
next_380:
    reg_d0.h[0] += 0x300;
    reg_d1.h[0] += 0xF9C0;
    direction_between();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2E);
    direction_turn_toward();
    *(u16 *)(reg_a5 + 0x2E) = reg_d1.h[0];
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    *(u16 *)(reg_a5 + 0x2A) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    *(u16 *)(reg_a5 + 0x2C) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
block_b:
    func_00170A60();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF500;
    reg_d1.h[1] += 0xF200;
    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x2A);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_d3.h[0] = 0x458;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    func_00170BE0();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2C0;
    reg_d1.h[1] += 0xFF00;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x24);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x26);
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    func_00170BE0();
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0xF6C0;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x2A);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x2C);
    func_00170BE0();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if (g_enemies_stopped != 0) goto block_rts;
    if (g_bullets_blocked != 0) goto block_rts;
    if (ENTITY(reg_a6)->y.sh < 0x1000) goto block_rts;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    switch (reg_tmp.b[0]) {
    case 0:
        goto block_c;
    }
block_rts:
    return;
block_c:
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x30);
    reg_a4 = (u8 *) D_002594F0;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x28);
    reg_d0.h[0] = reg_d1.h[0];
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0x5C0;
    reg_d3.h[1] += 0x300;
    reg_d4.w = 0;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w = 0x30004;
    bits = *(u8 *)(reg_a5 + 0x33);
    if (bits != 0) goto next_610;
    reg_d1.h[0] += 3;
    goto next_620;
next_610:
    if ((bits & 0xFF) != 1) goto next_620;
    reg_d1.h[0] += 5;
next_620:
    bullet_fire_2way();
    reg_d1.h[0] -= 5;
    bullet_fire_fixed();
    reg_d1.h[0] -= 5;
    bullet_fire_2way();
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x2E);
    reg_d4.h[0] = reg_d1.h[0];
    reg_d4.h[0] &= 0x3E;
    reg_d4.h[0] += reg_d4.h[0];
    reg_d3.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16)reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((u16)reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] += 0xF9C0;
    reg_d3.h[1] += 0x300;
    reg_d4.w = 0;
    reg_d0.w = 0x30004;
    bits = *(u8 *)(reg_a5 + 0x33);
    if (bits != 0) goto next_640;
    reg_d1.h[0] -= 3;
    goto next_650;
next_640:
    if ((bits & 0xFF) != 1) goto next_650;
    reg_d1.h[0] -= 5;
next_650:
    bullet_fire_2way();
    reg_d1.h[0] += 5;
    bullet_fire_fixed();
    reg_d1.h[0] += 5;
    bullet_fire_2way();
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
    *(u8 *)(reg_a5 + 0x21) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_690;
    *(u8 *)(reg_a5 + 0x21) = *(u8 *)(reg_a5 + 0x20);
    reg_d0.h[0] = 0xA;
    reg_d1.h[0] = g_rank_1_16;
    reg_d1.h[0] >>= 2;
    reg_d0.h[0] -= reg_d1.h[0];
    *(u8 *)(reg_a5 + 0x1F) = reg_d0.b[0];
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x33);
    *(u8 *)(reg_a5 + 0x33) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_690;
    *(u8 *)(reg_a5 + 0x33) = *(u8 *)(reg_a5 + 0x32);
    reg_d0.h[0] = 0x60;
    reg_d0.h[0] -= g_rank_5_16;
    *(u8 *)(reg_a5 + 0x1F) = reg_d0.b[0];
next_690:
    return;
block_d:
    reg_d0.w = 0x115;
    score_add();
    func_0018D580();
    reg_d1.h[0] = 0;
    reg_d2.w = -0x600U;
    reg_d0.w = 0xC;
    func_00211550();
    reg_d2.w = 0x600;
    func_00211550();
    reg_d0.w = 8;
    reg_a4 = (u8 *)(D_0025A620);
    reg_d6.w = 6;
    do {
        reg_d1.h[1] = *(u16 *)reg_a4;
        reg_a4 += 2;
        reg_d1.h[0] = *(u16 *)reg_a4;
        reg_a4 += 2;
        func_00125EF0();
    } while ((s16)(--reg_d6.h[0]) >= 0);
    reg_d0.w = 0xD;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(s16 *)(reg_a0 + 0x26) = 0x200;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x10) = 1;
    reg_d0.w = 0xC;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(u16 *)(reg_a0 + 0x28) = 0xFA00;
    *(s16 *)(reg_a0 + 0x1A) = 0x5C0;
    *(s16 *)(reg_a0 + 0x10) = 1;
    reg_d0.w = 0xC;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0x400;
    *(u16 *)(reg_a0 + 0x26) = 0xFC00;
    *(s16 *)(reg_a0 + 0x28) = 0x200;
    *(s16 *)(reg_a0 + 0x1A) = 0x440;
    *(s16 *)(reg_a0 + 0x10) = 1;
    reg_d0.h[0] = 0x85;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x1A) = 0x380;
    *(s16 *)(reg_a0 + 0x10) = 1;
    enemy_remove();
}

void func_00163E40(void) {
    enemy_set_entity_count(0);
}

extern u16 D_0025A640[];
extern u16 D_0025A650[];
extern u16 D_0025A660[];

void func_00163E50(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_0025A660);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_0025A650);
    reg_d0.w = 5;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if ((g_stage == 0) && ((s32) g_scroll_line >= 0x156)) {
            ENTITY(reg_a6)->hp.sh = 0x500;
        }
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        func_00202180();
        reg_a0 = (u8 *)(D_002590F0);
        *(u8 *)(reg_a5 + 0x20) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.b[0] = 4;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 4;
        }
        *(u8 *)(reg_a5 + 0x16) = (u8) reg_d0.b[0];
        reg_d0.h[0] = g_rank_5_16;
        *(u8 *)(reg_a5 + 0x1B) -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025A640);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        *(s8 *)(reg_a5 + 0x19) = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(s8 *)(reg_a5 + 0x18) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

s32 func_00125EB0();
s32 func_0016D290();
s32 func_00170B20();
s32 func_00170CA0();
s32 func_00170DE0();
s32 func_0018D4E0();
s32 func_002114C0();
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];

void func_00164040(void) {
    s16 *temp_v1;
    s16 *var_a0;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        entity_check_bounds();
        if (cond_flag != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_5:
        var_a0 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(var_a0) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
            if (((s32) (*(u16 *)((u8 *)(var_a0) + (0x18))) < 0x140) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_12;
        }
        (*(u8 *)((u8 *)(var_a0) + (1))) &= 0xA3;
        score_add_no_chain();
        var_a0 = (s16 *)(reg_a6);
        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1C)));
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
        }
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) (*(u16 *)((u8 *)(var_a0) + (0x18))) >= 0) {
block_12:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if (g_enemies_stopped == 0) {
                if (g_bullets_blocked == 0) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                    *(u8 *)(reg_a5 + 0x1F) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                        var_a0 = (s16 *)(reg_a5);
                        reg_d0.b[0] = (*(u8 *)((u8 *)(var_a0) + (0x1D)));
                        if ((*(u8 *)((u8 *)(var_a0) + (0x1C))) == reg_d0.b[0]) {
                            reg_a0 = (u8 *)(D_0029F260);
                            reg_a1 = (u8 *)(D_0029F1F0);
                            if ((*(u8 *)((u8 *)(var_a0) + (2))) != 0) {
                                reg_atmp = (u8 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(reg_atmp);
                            }
                            temp_v1 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                                var_a0 = (s16 *)(reg_a1);
                                if (*var_a0 < 0) {
                                    reg_a0 = (u8 *)(var_a0);
                                    reg_atmp = (u8 *)(temp_v1);
                                    reg_a1 = (u8 *)(temp_v1);
                                    goto block_21;
                                }
                            } else {
block_21:
                                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                direction_between();
                                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
                                direction_turn_toward();
                                var_a0 = (s16 *) reg_d1.h[0];
                                *(u16 *)(reg_a5 + 0x20) = (u16) var_a0;
                                reg_a3 = (u8 *)(D_002590F0);
                                reg_d1.h[0] &= 0x3E;
                                reg_d1.h[0] += reg_d1.h[0];
                                ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                                ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                            }
                        }
                    }
                    if ((s16) ENTITY(reg_a6)->y.h >= 0x1000) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
                        *(u8 *)(reg_a5 + 0x1B) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x16);
                            func_0016D290();
                            if (cond_flag == 0) {
                                reg_a4 = (u8 *)(D_00259570);
                                reg_d1.h[0] = *(u16 *)(reg_a5 + 0x20);
                                reg_d0.h[0] = reg_d1.h[0];
                                reg_d0.h[0] &= 0x3E;
                                reg_d0.h[0] += reg_d0.h[0];
                                reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                                reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                                reg_d3.w = 0x80000 + reg_d3.w;
                                reg_d0.w = 0x20006;
                                reg_d4.w = 0;
                                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                bullet_fire_fixed();
                                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
                                *(u8 *)(reg_a5 + 0x1D) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
                                    reg_d0.h[0] = 0x40;
                                    reg_d0.h[0] -= g_rank_2_16;
                                    reg_d0.h[0] += 4;
                                    *(u8 *)(reg_a5 + 0x1B) = (u8) reg_d0.b[0];
                                }
                            }
                        }
                    }
                }
            }
            reg_d6.w = 0xF800F800;
            func_00170B20();
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            return;
        }
        reg_d0.w = 0x20;
        score_add();
        func_0018D4E0();
        func_00170CA0();
        reg_d0.w = 8;
        func_002114C0();
        reg_d0.w = 8;
        func_00170DE0();
        func_00125EB0();
        reg_d0.w = 0xC;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        func_00170D00();
        *(s16 *)(reg_a0 + 0x12) = 1;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(s16 *)(reg_a0 + 0x26) = 0;
        *(s16 *)(reg_a0 + 0x28) = 0;
        *(s16 *)(reg_a0 + 0x10) = 1;
        enemy_remove();
    }
}

void func_00164580(void) {
    enemy_set_entity_count(0);
}

s32 enemy_set_task_work();                            /* extern */
s32 enemy_init_entities();                            /* extern */
s32 enemy_path_start();                            /* extern */
extern s32 D_0025A680[];
extern s32 D_0028C9E8;
extern s32 *reg_a0_as_s32_p;

void func_00164590(void) {
    reg_a0_as_s32_p = D_0025A680;
    enemy_init_entities();
    reg_a0_as_s32_p = &D_0028C9E8;
    reg_d0.w = 2;
    enemy_set_task_work();
    enemy_path_start();
    if ((enemy_move_end_requested == 0) && (ENTITY(reg_a6)->misc.b.user != 0)) {
        ENTITY(reg_a6)->misc.b.user = 0U;
        *(s16 *)(reg_a5 + 0x1A) = 0x40;
    }
}

s32 entity_follow_scroll();
s32 func_00203380();
extern s8 D_0028E855_as_s8;
extern u16 D_0029F1F4[];
extern u16 D_0029F264[];

void func_00164600(void) {
    u32 saved;
    u8 t;

    if (D_0028E855_as_s8 < 0) goto block_1;
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    entity_follow_scroll();
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xC00;
    reg_d0.h[0] += D_0029C068[0];
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    saved = reg_tmp.w;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xB000;
    reg_tmp.w = saved + reg_tmp1.w;
    reg_d0.h[0] += 0xB000;
    if (reg_tmp.h[1] != 0) goto next_1;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x8C00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    saved = reg_tmp.h[0];
    reg_d0.h[0] += 0x400;
    reg_tmp.w = 0;
    reg_d0.h[1] = saved;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x8C00;
    if (reg_tmp.h[1] == 0) goto next_2;
next_1:
    switch (*(u8 *)(reg_a5 + 0x17)) {
    case 0:
        goto next_3;
    }
block_1:
    enemy_remove();
    return;
next_2:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_3:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_4;
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    if (ENTITY(reg_a6)->hp.sh < 0) goto block_3;
next_4:
    if (D_0029CEA0[0] != 0) goto next_9;
    func_00203380();
    if (reg_d0.h[0] == 0) goto block_rts;
    if (!(reg_d0.h[0] & 1)) goto next_6;
    reg_d2.h[0] = D_0029F264[0];
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] -= reg_d2.h[0];
    if ((s16) reg_d1.h[0] >= 0) goto next_5;
    reg_d1.h[0] *= 0xFFFF;
next_5:
    if ((s32) reg_d1.h[0] < 0x240) goto next_8;
    if (!(reg_d0.h[0] & 2)) goto block_rts;
next_6:
    reg_d2.h[0] = D_0029F1F4[0];
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] -= reg_d2.h[0];
    if ((s16) reg_d1.h[0] >= 0) goto next_7;
    reg_d1.h[0] *= 0xFFFF;
next_7:
    if ((s32) reg_d1.h[0] > 0x23F) goto block_rts;
next_8:
    *(u16 *)(reg_a5 + 0x18) = 0xF;
next_9:
    *(u16 *)(reg_a5 + 0x18) -= 1;
    t = ENTITY(reg_a6)->flags.b[0];
    if (!(t & 0x40)) goto next_10;
    ENTITY(reg_a6)->flags.b[0] = t & 0xBF;
    goto block_2;
next_10:
    ENTITY(reg_a6)->flags.b[0] = t | 0x40;
    reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_tmp.w ^= 3;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    func_00170A60();
block_2:
    return;
block_3:
    reg_d0.w = 1;
    score_add();
    func_0018D4E0();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    reg_d2.b[0] = ENTITY(reg_a6)->misc.b.draw_layer;
    func_00125EB0();
    reg_d0.w = 0xC;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    func_00170D00();
    reg_d0.h[0] = 1;
    *(u16 *)(reg_a0 + 0x10) = reg_d0.h[0];
    enemy_remove();
block_rts:
    return;
}

void func_00164970(void) {
    enemy_set_entity_count(0);
}

extern u32 D_0025A6A0[];
extern u32 D_0028C9F0;
extern s16 g_scroll_line_as_s16;

void func_00164980(void)
{
    extern void enemy_set_task_work(void);
    extern void enemy_init_entities(void);
    extern void enemy_path_start(void);
    reg_a0 = (u8 *)D_0025A6A0;
    enemy_init_entities();

    reg_a0 = (u8 *)&D_0028C9F0;
    reg_d0.w = 1;
    enemy_set_task_work();
    enemy_path_start();

    if (enemy_move_end_requested == 0 && g_stage == 1 && g_scroll_line_as_s16 < 4) {
        ENTITY(reg_a6)->flags.h = 0x8000;
    }
}

void func_00164A00(void) {
    u32 saved;

    if (D_0028E855_as_s8 < 0) goto block_1;
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    entity_follow_scroll();
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp1.h[0] = 0x8C00;
    saved = reg_tmp.w;
    reg_tmp.w = saved + reg_tmp1.w;
    reg_d0.h[0] += 0x8C00;
    if (reg_tmp.h[1] != 0) goto next_1;
    reg_d0.h[0] = D_0029C068[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] + 0x800;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x400;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_tmp1.h[0] = 0xC000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d1.h[0] += reg_d0.h[0];
    reg_d1.h[0] += 0xC000;
    if (reg_tmp.h[1] == 0) goto next_2;
next_1:
    if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_3;
block_1:
    enemy_remove();
    return;
next_2:
    *(u8 *)(reg_a5 + 0x17) = 1;
next_3:
    if (g_stage != 1) goto next_4;
    if ((s16) g_scroll_line < 4) goto next_4;
    ENTITY(reg_a6)->flags.b[1] |= 0x20;
next_4:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_5;
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    if (ENTITY(reg_a6)->hp.sh < 0) goto block_2;
next_5:
    return;
block_2:
    reg_d0.w = 1;
    score_add();
    func_0018D4E0();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_d2.b[0] = ENTITY(reg_a6)->misc.b.draw_layer;
    func_00125EB0();
    reg_d0.w = 1;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    func_00170D00();
    reg_d0.h[0] = 1;
    *(u16 *)(reg_a0 + 0x10) = reg_d0.h[0];
    enemy_remove();
}

extern u16 *reg_a5_as_u16_p;
extern u16 *reg_a6_as_u16_p;

void func_00164C30(void) {
    extern void func_00170BE0(void);
    reg_d1.h[1] = reg_a6_as_u16_p[1];
    reg_d1.h[0] = reg_a6_as_u16_p[2];
    reg_d1.h[0] += 0xFB00;
    reg_d1.h[1] += 0xFC00;
    reg_d1.h[1] += reg_a5_as_u16_p[0x16];
    reg_d2.h[1] = reg_a5_as_u16_p[0x10];
    reg_d2.h[0] = reg_a5_as_u16_p[0x11];
    reg_d3.h[0] = 0x428;
    reg_d4.h[0] = 0xD;
    func_00170BE0();
}

void func_00164CA0(void) {
    enemy_set_entity_count(0);
}

s32 rng_next_masked();
s32 rng_next_unsigned();
extern u16 D_0025A6C0[];
extern u16 D_0025A6D0[];
extern u16 D_0025A6F0[];
extern u16 D_0025A710[];

void func_00164CB0(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_0025A6F0);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_0025A6D0);
    reg_d0.w = 0xB;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        func_00202180();
        *(u8 *)(reg_a5 + 0x24) = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(D_0025A710);
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        rng_next_unsigned();
        *(u8 *)(reg_a5 + 0x2A) = (u8) reg_d0.b[0];
        reg_d0.h[0] = g_rank_4_16;
        reg_d0.b[0] -= 4;
        *(u8 *)(reg_a5 + 0x1B) -= reg_d0.b[0];
        rng_next_masked();
        reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
        *(u8 *)(reg_a5 + 0x1B) += reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025A6C0);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        *(s8 *)(reg_a5 + 0x19) = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(s8 *)(reg_a5 + 0x18) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

s32 bullet_fire_double();
extern u16 D_0025A790[];
extern u16 D_0025A7B0[];
extern u16 D_0025A830[];
extern u16 D_0025AEE0[];

void func_00164E90(void) {
    s32 func_00170BE0();
    u8 *ptr;

    enemy_path_step();
    if (enemy_move_end_requested != 0) {
        return;
    }
    entity_check_bounds();
    if (cond_flag == 0) goto next_30;
    if (reg_a5[0x17] == 0) goto next_40;
    enemy_remove();
    return;
next_30:
    reg_a5[0x17] = 1;
next_40:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) goto next_50;
    reg_d0.b[0] = reg_a5[0x19];
    if (!((s32) ENTITY(reg_a6)->hp.h < 0x50)) goto next_90;
    if (D_0028E8B8 != 0) goto next_90;
    reg_d0.w = 0x19;
    goto next_90;
next_50:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] != 0x19) goto next_60;
    reg_d0.b[0] = reg_a5[0x19];
next_60:
    reg_d2.b[0] = reg_a5[0x18];
    reg_d0.b[0] ^= reg_d2.b[0];
    if (ENTITY(reg_a6)->hp.sh < 0) goto block_dead;
next_90:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    reg_tmp.b[0] = reg_a5[0x27];
    reg_a5[0x27] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_120;
    reg_a5[0x27] = reg_a5[0x26];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x28);
    reg_a0 = (u8 *) D_0025A790;
    *(u16 *)(reg_a5 + 0x20) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x22) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x28);
    *(u16 *)(reg_a5 + 0x28) -= 4;
    if (!((s32) reg_tmp.h[0] < 4)) goto next_120;
    *(u16 *)(reg_a5 + 0x28) = 0x14;
next_120:
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x2A);
    reg_a0 = (u8 *) D_0025A830;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x2C) = reg_d0.h[0];
    reg_d0.h[0] += 0xF800;
    ENTITY(reg_a6)->offset_y.h = reg_d0.h[0];
    reg_a5[0x2A] += 3;
    if ((s8) ENTITY(reg_a6)->flags.b[0] >= 0) goto next_200;
block_base:
    func_00170A60();
    func_00164C30();
    if (D_0028E3EC == 0) goto next_150;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[1] += 0x100;
    reg_d1.h[0] += 0xFE00;
    reg_d1.h[1] += *(u16 *)(reg_a5 + 0x2C);
    reg_a0 = (u8 *) D_0025AEE0;
    reg_d2.w = 6;
    reg_d2.h[0] &= D_0028E3F0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x1E;
    func_00170BE0();
next_150:
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    return;
next_200:
    if (g_enemies_stopped != 0) goto block_objset;
    if (g_bullets_blocked != 0) goto block_objset;
    reg_tmp.b[0] = reg_a5[0x1F];
    reg_a5[0x1F] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_objset;
    reg_a5[0x1F] = reg_a5[0x1E];
    reg_d0.b[0] = reg_a5[0x1D];
    if (reg_a5[0x1C] != reg_d0.b[0]) goto block_objset;
    reg_a0 = (u8 *) D_0029F260_as_u16_a;
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    if (reg_a5[2] == 0) goto next_220;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_220:
    ptr = reg_a0;
    if ((*(s16 *)ptr) < 0) goto next_240;
    if ((*(s16 *)reg_a1) >= 0) goto block_objset;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) ptr;
    reg_a1 = ptr;
next_240:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x24);
    direction_turn_toward();
    *(u16 *)(reg_a5 + 0x24) = reg_d1.h[0];
    reg_a0 = (u8 *) D_0025A710;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
block_objset:
    func_00170A60();
    func_00164C30();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if (g_enemies_stopped != 0) goto block_rts;
    if (g_bullets_blocked != 0) goto block_rts;
    if ((ENTITY(reg_a6)->y.sh) < 0x1000) goto block_rts;
    reg_tmp.b[0] = reg_a5[0x1B];
    reg_a5[0x1B] -= 1;
    switch (reg_tmp.b[0]) {
    case 0:
        goto block_fire;
    }
block_rts:
    return;
block_fire:
    reg_d0.h[0] = 8;
    reg_d1.h[0] = g_rank_1_16;
    reg_d1.h[0] >>= 2;
    reg_d0.h[0] -= reg_d1.h[0];
    reg_a5[0x1B] = reg_d0.b[0];
    func_0016D290();
    if (cond_flag != 0) goto block_rts;
    reg_a4 = (u8 *) D_0025A7B0;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x24);
    reg_d0.h[0] = reg_d1.h[0];
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d4.w = (u32) reg_a6;
    reg_d0.w = 0xC;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    if (reg_a5[0x1D] != 2) goto next_620;
    bullet_fire_double();
    goto next_630;
next_620:
    bullet_fire_fixed();
next_630:
    reg_tmp.b[0] = reg_a5[0x1D];
    reg_a5[0x1D] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_650;
    reg_a5[0x1D] = reg_a5[0x1C];
    reg_d0.h[0] = 0x50;
    reg_d0.h[0] -= g_rank_5_16;
    reg_d0.h[0] += 4;
    reg_a5[0x1B] = reg_d0.b[0];
next_650:
    return;
block_dead:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x80;
    if (reg_tmp.b[0] & 0x80) goto block_dead2;
    reg_d0.w = 0x11;
    score_add();
    reg_d0.w = 0xB;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(s16 *)(reg_a0 + 0x26) = 0;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x10) = 2;
    ENTITY(reg_a6)->flags.b[1] &= 0xFD;
    reg_tmp.w = 0x1957;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    ENTITY(reg_a6)->hp.h = 0x140;
    goto block_base;
block_dead2:
    func_0018D4E0();
    reg_d0.w = 8;
    score_add();
    reg_d0.h[0] = 0xC;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xFC00;
    *(s16 *)(reg_a0 + 0x28) = 0;
    *(s16 *)(reg_a0 + 0x10) = 1;
    enemy_remove();
}

void func_001657C0(void) {
    enemy_set_entity_count(0);
}

extern u16 D_002591F0[];
extern u16 D_0025AC38[];
extern u16 D_0025AC48[];
extern u16 D_0025AC60[];

void func_001657D0(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_0025AC60);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_0025AC48);
    reg_d0.w = 5;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if ((g_stage == 0) && ((s32) g_scroll_line >= 0x156)) {
            ENTITY(reg_a6)->hp.sh = 0x280;
        }
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        func_00202180();
        reg_a0 = (u8 *)(D_002591F0);
        *(u8 *)(reg_a5 + 0x20) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.b[0] = 4;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 4;
        }
        *(u8 *)(reg_a5 + 0x16) = (u8) reg_d0.b[0];
        reg_d0.h[0] = g_rank_5_16;
        *(u8 *)(reg_a5 + 0x1B) -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025AC38);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        *(s8 *)(reg_a5 + 0x19) = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(s8 *)(reg_a5 + 0x18) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

extern u16 D_002595F0[];

void func_001659C0(void) {
    s16 *temp_a0;
    s16 *temp_v1;
    u16 temp_a0_2;
    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        entity_check_bounds();
        if (cond_flag != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_5:
        temp_a0 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(temp_a0) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
            if (((s32) (*(u16 *)((u8 *)(temp_a0) + (0x18))) < 0x120) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_12;
        }
        (*(u8 *)((u8 *)(temp_a0) + (1))) &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x19);
        }
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x18);
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_12:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                *(u8 *)(reg_a5 + 0x1F) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                    func_0016D290();
                    if (cond_flag == 0) {
                        reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
                        if (*(u8 *)(reg_a5 + 0x1C) == reg_d0.b[0]) {
                            reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                            reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                            if (*(u8 *)(reg_a5 + 2) != 0) {
                                reg_atmp = (u8 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(reg_atmp);
                            }
                            temp_v1 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1) + (0))) >= 0) {
                                if (*(s16 *)reg_a1 < 0) {
                                    reg_a0 = (u8 *)(reg_a1);
                                    reg_atmp = (u8 *)(temp_v1);
                                    reg_a1 = (u8 *)(temp_v1);
                                    goto block_22;
                                }
                            } else {
block_22:
                                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                direction_between();
                                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
                                direction_turn_toward();
                                *(u16 *)(reg_a5 + 0x20) = (u16) reg_d1.h[0];
                                reg_a3 = (u8 *)(D_002591F0);
                                reg_d1.h[0] &= 0x3E;
                                reg_d1.h[0] += reg_d1.h[0];
                                ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                                ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                            }
                        }
                    }
                }
                if ((s16) ENTITY(reg_a6)->y.h >= 0x1000) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
                    *(u8 *)(reg_a5 + 0x1B) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x16);
                        func_0016D290();
                        if (cond_flag == 0) {
                            reg_a4 = (u8 *)(D_002595F0);
                            reg_d1.h[0] = *(u16 *)(reg_a5 + 0x20);
                            reg_d0.h[0] = reg_d1.h[0];
                            reg_d0.h[0] &= 0x3E;
                            reg_d0.h[0] *= 4;
                            reg_a4 += reg_d0.h[0];
                            reg_d3.h[1] = *(u16 *)reg_a4;
                            reg_a4 += 2;
                            temp_a0_2 = *(u16 *)reg_a4;
                            reg_d3.h[0] = temp_a0_2;
                            reg_a4 += 2;
                            reg_d0.w = 6;
                            reg_d4.w = 0;
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            bullet_fire_fixed();
                            reg_d3.h[1] = *(u16 *)reg_a4;
                            reg_a4 += 2;
                            reg_d3.h[0] = *(u16 *)reg_a4;
                            reg_a4 += 2;
                            bullet_fire_fixed();
                            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
                            *(u8 *)(reg_a5 + 0x1D) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x1C);
                                reg_d0.h[0] = 0x40;
                                reg_d0.h[0] -= g_rank_4_16;
                                reg_d0.h[0] += 8;
                                *(u8 *)(reg_a5 + 0x1B) = (u8) reg_d0.b[0];
                            }
                        }
                    }
                }
            }
            func_00170A60();
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            return;
        }
        reg_d0.w = 0x34;
        score_add();
        func_0018D4E0();
        func_00170CA0();
        reg_d0.w = 8;
        func_002114C0();
        reg_d0.w = 8;
        func_00170DE0();
        func_00125EB0();
        reg_d0.w = 0xC;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
        func_00170D00();
        *(s16 *)(reg_a0 + 0x12) = 1;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(u16 *)(reg_a0 + 0x26) = 0xFE00;
        *(s16 *)(reg_a0 + 0x28) = 0;
        *(s16 *)(reg_a0 + 0x10) = 1;
        enemy_remove();
    }
}

void func_00165EE0(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00259270[];
extern u16 D_0025AC80[];
extern u16 D_0025AC90[];
extern u16 D_0025ACA0[];

void func_00165EF0(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    reg_a0 = (u8 *)(D_0025ACA0);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_0025AC90);
    reg_d0.w = 5;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        func_00202180();
        reg_a0 = (u8 *)(D_00259270);
        *(u8 *)(reg_a5 + 0x20) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.b[0] = 4;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 4;
        }
        *(u8 *)(reg_a5 + 0x16) = (u8) reg_d0.b[0];
        reg_d0.h[0] = g_rank_4_16;
        reg_d0.h[0] -= 4;
        *(u8 *)(reg_a5 + 0x1B) -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025AC80);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        *(s8 *)(reg_a5 + 0x19) = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(s8 *)(reg_a5 + 0x18) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

s32 func_00170D70();

void func_001660C0(void) {
    u8 *swp;

    enemy_path_step();
    if (enemy_move_end_requested != 0) goto block_rts;
    entity_check_bounds();
    switch (cond_flag) {
    case 0:
        goto next_1;
    }
    if (reg_a5[0x17] == 0) goto next_2;
    enemy_remove();
    return;
next_1:
    reg_a5[0x17] = 1;
next_2:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] != 0) goto next_3;
    reg_d0.b[0] = reg_a5[0x19];
    if ((s32) ENTITY(reg_a6)->hp.h >= 0xC0) goto next_5;
    if (D_0028E8B8 != 0) goto next_5;
    reg_d0.w = 0x19;
    goto next_5;
next_3:
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    score_add_no_chain();
    reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
    if (reg_d0.b[0] != 0x19) goto next_4;
    reg_d0.b[0] = reg_a5[0x19];
next_4:
    reg_d2.b[0] = reg_a5[0x18];
    reg_d0.b[0] ^= reg_d2.b[0];
    if (ENTITY(reg_a6)->hp.sh < 0) goto next_20;
next_5:
    ENTITY(reg_a6)->attr.b.palette = reg_d0.b[0];
    if (ENTITY(reg_a6)->flags.sb[0] >= 0) goto next_6;
    func_00170A60();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    return;
next_6:
    if (g_enemies_stopped != 0) goto next_21;
    if (g_bullets_blocked != 0) goto next_21;
    reg_tmp.b[0] = reg_a5[0x1F];
    reg_a5[0x1F] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_21;
    reg_a5[0x1F] = reg_a5[0x1E];
    reg_a0 = (u8 *) D_0029F260_as_u16_a;
    reg_a1 = (u8 *) D_0029F1F0_as_u16_a;
    if (reg_a5[2] == 0) goto next_7;
    reg_atmp = (u8 *) reg_a0;
    reg_a0 = reg_a1;
    reg_a1 = (u8 *) reg_atmp;
next_7:
    if (*(s16 *)reg_a0 < 0) goto next_8;
    if (*(s16 *)reg_a1 >= 0) goto next_21;
    swp = reg_a0;
    reg_a0 = reg_a1;
    reg_atmp = (u8 *) swp;
    reg_a1 = swp;
next_8:
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
    direction_turn_toward();
    *(u16 *)(reg_a5 + 0x20) = reg_d1.h[0];
    reg_a3 = (u8 *) D_00259270;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a3 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a3 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
next_21:
    func_00170A60();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if (g_enemies_stopped != 0) goto block_rts;
    if (g_bullets_blocked != 0) goto block_rts;
    if (ENTITY(reg_a6)->y.sh < 0x1000) goto block_rts;
    reg_tmp.b[0] = reg_a5[0x1B];
    reg_a5[0x1B] -= 1;
    switch (reg_tmp.b[0]) {
    case 0:
        goto next_9;
    }
    goto block_rts;
next_9:
    reg_a5[0x1B] = reg_a5[0x16];
    func_0016D290();
    if (cond_flag != 0) goto block_rts;
    if (g_stage != 3) goto next_10;
    if (g_scroll_line < 0x2E) goto block_rts;
next_10:
    reg_a4 = (u8 *) D_00259570;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x20);
    reg_d0.h[0] = reg_d1.h[0];
    reg_d0.h[0] &= 0x3E;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a4 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
    reg_d3.h[0] = ((u16) reg_d0.h[0] + 2 != 0) ? *(u16 *)(reg_a4 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a4;
    reg_d1.h[0] += 2;
    reg_d1.h[0] &= 0x3C;
    reg_d4.w = (u32) reg_a6;
    reg_d0.w = 0xD;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    bullet_fire_fixed();
    reg_tmp.b[0] = reg_a5[0x1D];
    reg_a5[0x1D] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_12;
    reg_a5[0x1D] = reg_a5[0x1C];
    reg_d0.h[0] = 0x40;
    reg_d0.h[0] -= g_rank_4_16;
    reg_d0.h[0] += 4;
    reg_a5[0x1B] = reg_d0.b[0];
next_12:
    return;
next_20:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x80;
    if (reg_tmp.b[0] & 0x80) goto next_11;
    reg_d0.w = 8;
    score_add();
    reg_d0.h[0] = 0x84;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    func_00170D70();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(u16 *)(reg_a0 + 0x28) = 0xFE00;
    *(s16 *)(reg_a0 + 0x10) = 1;
    ENTITY(reg_a6)->flags.b[1] &= 0xFD;
    reg_tmp.w = 0x1626;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    ENTITY(reg_a6)->hp.h = 0x300;
    goto next_21;
next_11:
    func_0018D4E0();
    reg_d0.w = 8;
    score_add();
    func_00170CA0();
    reg_d0.w = 8;
    func_002114C0();
    reg_d0.w = 8;
    func_00170DE0();
    func_00125EB0();
    reg_d0.w = 0xC;
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = ENTITY(reg_a6)->x.h;
    func_00170D00();
    *(s16 *)(reg_a0 + 0x12) = 1;
    *(s16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a0 + 0x26) = 0xFC00;
    *(u16 *)(reg_a0 + 0x28) = 0xFE00;
    *(s16 *)(reg_a0 + 0x10) = 1;
    enemy_remove();
block_rts:
    return;
}

void func_00166740(void) {
    s32 bullet_fire256_fast();
    u16 temp_a1;

    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    temp_a1 = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = temp_a1;
    reg_d3.w = reg_d7.w;
    reg_d0.w = 0x3000C;
    reg_d0.h[0] = 0xB;
    reg_d4.w = 0;
    bullet_fire256();
    reg_d0.h[1] += 3;
    reg_d5.b[0] = *(u8 *)(reg_a5 + 0x1F);
    reg_d5.b[0] *= 2;
    reg_d1.b[0] += reg_d5.b[0];
    bullet_fire256_fast();
}

void func_001667D0(void) {
    enemy_set_entity_count(1);
}

extern s8 D_0025ACC0[];
extern s8 D_0025ACD0[];
extern s8 D_0025ACF0[];
extern u16 g_enemy_signal_7;
extern u16 g_enemy_signal_6;
extern u16 g_enemy_signal_5;
extern u16 g_enemy_signal_4;

void func_001667E0(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    s8 *temp_a1_2;

    reg_a0_as_s8_p = (s8 *)D_0025ACF0;
    enemy_init_entities();
    reg_a0_as_s8_p = (s8 *)D_0025ACD0;
    reg_d0.w = 0xC;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_d0.b[0] = 5;
        if ((s32) g_stage > 1) {
            reg_d0.b[0] = 2;
        }
        *(u8 *)(reg_a5 + 0x2E) = (u8) reg_d0.b[0];
        reg_d0.h[0] = g_rank_2_16;
        *(u8 *)(reg_a5 + 0x2A) -= reg_d0.b[0];
        if (g_stage == 1) {
            if (((s32) g_scroll_line >= 0x100) && ((s32) g_scroll_line < 0x16C)) {
                if (g_enemy_signal_0 != 0) {
                    enemy_remove();
                    return;
                }
                goto block_10;
            }
            if ((s32) g_scroll_line >= 0x80) {
                ENTITY(reg_a6)->hp.sh = 0x680;
            }
            goto block_10;
        }
block_10:
        reg_a0_as_s8_p = (s8 *)D_0025ACC0;
        reg_d0.h[0] = g_stage_x2;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *reg_a0_as_s8_p;
        *(s8 *)(reg_a5 + 0x1B) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        *(s8 *)(reg_a5 + 0x1A) = (s8) *reg_a0_as_s8_p;
        temp_a1_2 = (s8 *)(reg_a0_as_s8_p + 1);
        reg_a0_as_s8_p = temp_a1_2;
        if (g_stage == 4) {
            ENTITY(reg_a6)->hp.sh = 0x880;
            if ((s32) g_scroll_line < 0x230) {
                if (g_enemy_signal_4 != 0) {
                    enemy_remove();
                }
            } else if ((s32) g_scroll_line < 0x250) {
                if (g_enemy_signal_5 != 0) {
                    enemy_remove();
                }
            } else if ((s32) g_scroll_line < 0x290) {
                if (g_enemy_signal_6 != 0) {
                    enemy_remove();
                }
            } else if ((g_enemy_signal_7 != 0) && ((s32) g_scroll_line > 0x240)) {
                enemy_remove();
            }
        }
    }
}

extern u16 D_0025AD30[];
extern u16 D_0028C9F8;

void func_001669F0(void) {
    s16 *temp_v1_2;
    s16 *var_a1;
    u16 temp_a0_2;
    s32 temp_a0_4;
    s64 temp_v0_2;
    u16 temp_a0;
    u16 temp_a0_3;
    u16 temp_a0_5;
    u16 temp_a1;
    u16 temp_a1_2;
    u16 temp_a2;
    u16 var_a2;
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;
    u8 temp_v0;
    u8 temp_v1;
    u8 var_v0;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7000;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1000;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0x7000;
        reg_tmp.w += reg_tmp1.sw;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto block_5;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
block_5:
        *(u16 *)(reg_a6 + 0x22) = (u16) ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a6 + 0x24) = (u16) ENTITY(reg_a6)->x.h;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        reg_d1.b[0] |= *(u8 *)(reg_a6 + 0x21);
        reg_d1.h[0] &= 0x5C;
        var_a1 = (s16 *)(reg_a6 + 1);
        if (reg_d1.h[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
            if (((s32) ENTITY(reg_a6)->hp.h < 0x260) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto block_14;
        }
        reg_d0.h[0] = 0xA3;
        ENTITY(reg_a6)->flags.b[1] &= reg_d0.b[0];
        *(u8 *)(reg_a6 + 0x21) &= reg_d0.b[0];
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1B);
        }
        var_a1 = (s16 *)(reg_a6 + 0x18);
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1A);
        reg_d0.b[0] ^= reg_d2.b[0];
        reg_d4.h[0] = ENTITY(reg_a6)->hp.h;
        temp_a0 = *(u16 *)(reg_a6 + 0x38);
        if ((s16)(temp_a0) < (s16) reg_d4.h[0]) {
            reg_d4.h[0] = temp_a0;
        }
        ENTITY(reg_a6)->hp.h = (u16) reg_d4.h[0];
        *(u16 *)(reg_a6 + 0x38) = (u16) reg_d4.h[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
block_14:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                if (((g_loop != 0) || ((s32) g_stage >= 3)) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x2B);
                    *(u8 *)(reg_a5 + 0x2B) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x2B) = (u8) *(u8 *)(reg_a5 + 0x2F);
                        reg_d1.w = 0x20;
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d4.w = 0;
                        if (!(ENTITY(reg_a6)->flags.b[0] & 0x40)) {
                            reg_d0.w = 0x20007;
                            reg_d3.w = 0xF200F940;
                            bullet_fire_fixed();
                            reg_d3.w = 0xF2000700;
                            bullet_fire_fixed();
                        } else {
                            reg_d0.w = 0x20007;
                            reg_d3.w = 0xF400FE00;
                            bullet_fire_fixed();
                            reg_d3.w = 0xF4000240;
                            bullet_fire_fixed();
                        }
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x2D);
                        *(u8 *)(reg_a5 + 0x2D) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x2D) = (u8) *(u8 *)(reg_a5 + 0x2C);
                            temp_v1 = ENTITY(reg_a6)->flags.b[0];
                            if (temp_v1 & 0x40) {
                                ENTITY(reg_a6)->flags.b[0] = temp_v1 & 0xBF;
                            } else {
                                ENTITY(reg_a6)->flags.b[0] = temp_v1 | 0x40;
                            }
                            reg_d0.h[0] = 0x20;
                            reg_d0.h[0] -= g_rank_2_16;
                            *(u8 *)(reg_a5 + 0x2B) = (u8) reg_d0.b[0];
                            *(u8 *)(reg_a5 + 0x2A) = (u8) reg_d0.b[0];
                        }
                    }
                }
                if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000) && (*(u8 *)(reg_a5 + 0x17) != 0)) {
                    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
                    temp_a0_2 = reg_d0.h[0] & 0xFFFF;
                    if (reg_d0.h[0] == 0) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
                        *(u8 *)(reg_a5 + 0x1D) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            reg_d0.h[0] = 0x10;
                            reg_d0.h[0] -= g_rank_1_16;
                            *(u8 *)(reg_a5 + 0x1D) = (u8) reg_d0.b[0];
                            *(u16 *)(reg_a5 + 0x18) = 1U;
                        }
                    } else if (temp_a0_2 == 1) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                        *(u8 *)(reg_a5 + 0x23) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                            *(u16 *)(reg_a5 + 0x20) += 4;
                            if (*(u16 *)(reg_a5 + 0x20) == 0x1C) {
                                *(u16 *)(reg_a5 + 0x18) = 2U;
                            }
                            goto block_58;
                        }
                    } else if (temp_a0_2 == 2) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
                        *(u8 *)(reg_a5 + 0x1D) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x1D) = (u8) *(u8 *)(reg_a5 + 0x2E);
                            reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                            reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                            if (*(u8 *)(reg_a5 + 2) != 0) {
                                reg_atmp = (u8 *)(reg_a0);
                                reg_a0 = (u8 *)(reg_a1);
                                reg_a1 = (u8 *)(reg_atmp);
                            }
                            temp_v1_2 = (s16 *)(reg_a0);
                            if ((*(s16 *)((u8 *)(temp_v1_2) + (0))) >= 0) {
                                if (*(s16 *)reg_a1 < 0) {
                                    reg_a0 = (u8 *)(reg_a1);
                                    reg_atmp = (u8 *)(temp_v1_2);
                                    reg_a1 = (u8 *)(temp_v1_2);
                                    goto block_45;
                                }
                            } else {
block_45:
                                reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                                reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                                reg_d4.w = 0;
                                reg_d4.b[0] = *(u8 *)(reg_a5 + 0x1F);
                                reg_a0 = (u8 *)(&D_0028C9F8);
                                reg_d4.h[0] += reg_d4.h[0];
                                reg_d7.h[0] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
                                temp_a1 = reg_d7.h[0];
                                temp_s1 = reg_d1.w;
                                temp_s2 = reg_d2.w;
                                temp_s3 = reg_d3.w;
                                reg_d0.h[0] += temp_a1;
                                *(u16 *)&reg_tmp7.h[0] = temp_a1;
                                reg_d7.h[1] = *(u16 *)&reg_tmp7.h[0];
                                reg_d7.h[0] = 0x700;
                                reg_d1.h[0] += reg_d7.h[0];
                                temp_s0 = reg_d0.w;
                                direction256_between();
                                func_00166740();
                                reg_d1.w = temp_s1;
                                reg_d7.h[0] = 0xF900;
                                reg_d0.w = temp_s0;
                                reg_d2.w = temp_s2;
                                reg_d3.w = temp_s3;
                                reg_d1.h[0] += reg_d7.h[0];
                                direction256_between();
                                func_00166740();
                            }
                            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                            *(u8 *)(reg_a5 + 0x1F) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                                reg_d0.h[0] = 0x10;
                                reg_d0.h[0] -= g_rank_1_16;
                                *(u8 *)(reg_a5 + 0x1D) = (u8) reg_d0.b[0];
                                *(u16 *)(reg_a5 + 0x18) = 3U;
                            }
                        }
                    } else {
                        temp_v0 = *(u8 *)(reg_a5 + 0x1D);
                        if (temp_v0 != 0) {
                            *(u8 *)(reg_a5 + 0x1D) = (u8) (temp_v0 - 1);
                        } else {
                            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                            *(u8 *)(reg_a5 + 0x23) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                                *(u16 *)(reg_a5 + 0x20) -= 4;
                                if (*(u16 *)(reg_a5 + 0x20) == 0) {
                                    reg_d0.h[0] = 0x30;
                                    if (g_stage == 4) {
                                        reg_d0.h[0] += 0x10;
                                    }
                                    reg_d0.h[0] -= g_rank_3_16;
                                    *(u8 *)(reg_a5 + 0x1D) = (u8) reg_d0.b[0];
                                    *(u16 *)(reg_a5 + 0x18) = 0U;
                                }
block_58:
                                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x20);
                                reg_a0 = (u8 *)(D_0025AD30);
                                *(u16 *)(reg_a5 + 0x24) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                                *(u16 *)(reg_a5 + 0x26) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            }
                        }
                    }
                }
            }
            entity_draw_layer5();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            temp_a0_3 = reg_d1.h[0];
            reg_d1.h[1] += 0x7FFF + 0x7D01;
            reg_d1.h[0] = (u32)temp_a0_3 + 0x7FFF + 0x7701;
            reg_d2.h[1] = *(u16 *)(reg_a5 + 0x24);
            reg_d2.h[0] = *(u16 *)(reg_a5 + 0x26);
            reg_d3.h[0] = 0x648;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer5();
            if ((g_loop == 0) && (D_0028E3EC != 0) && ((g_stage != 1) || ((s32) g_scroll_line < 0x16C))) {
                reg_d1.h[1] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d1.h[1] += 0x7FFF + 0x5801;
                reg_d2.w = 0x1887;
                reg_d3.h[0] = 0x830;
                reg_d4.h[0] = 0x18;
                reg_d1.h[0] += 0x200;
                sprite_draw_layer4();
            }
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            reg_a0 = (u8 *)(reg_a6 + 0x20);
            enemy_hitbox_debug_draw();
            return;
        }
        reg_d0.w = 0x55;
        score_add();
        func_0018D580();
        reg_d0.w = 0xD;
        explosion_spawn();
        *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
        var_a2 = ENTITY(reg_a6)->x.h;
        *(u16 *)(reg_a0 + 4) = var_a2;
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 1;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(u16 *)(reg_a0 + 0x26) = 0xF600;
        *(s16 *)(reg_a0 + 0x28) = 0;
        if ((g_stage != 1) || ((s32) g_scroll_line < 0x150)) {
            reg_d0.h[0] = ENTITY(reg_a6)->move.h;
            reg_d0.b[0] *= 4;
            temp_a0_5 = reg_d0.h[0];
            *(u16 *)(reg_a0 + 0x1A) = temp_a0_5;
            reg_d0.h[0] = 0x84;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            var_a2 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = var_a2;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(s16 *)(reg_a0 + 0x26) = 0x400;
            *(s16 *)(reg_a0 + 0x28) = 0;
            reg_d0.h[0] = ENTITY(reg_a6)->move.h;
            reg_d0.h[0] += 0x800;
            reg_d0.b[0] *= 4;
            *(u16 *)(reg_a0 + 0x1A) = (u16) reg_d0.h[0];
        }
        enemy_remove();
    }
}

void func_00167420(void) {
    enemy_set_entity_count(0);
}

extern u16 D_00258FF0[];
extern s8 D_0025AD50[];
extern s8 D_0025AD60[];
extern s8 D_0025AD90[];

void func_00167430(void) {
    s32 enemy_set_task_work();
    s32 enemy_init_entities();
    s32 enemy_path_start();
    u16 temp_a0;
    reg_a0_as_s8_p = (s8 *)D_0025AD90;
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0_as_s8_p;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0_as_s8_p = (s8 *)D_0025AD60;
    reg_d0.w = 0x10;
    enemy_set_task_work();
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (ENTITY(reg_a6)->misc.b.user != 0) {
            ENTITY(reg_a6)->attr.b.flip |= 0x40;
            *(u16 *)(reg_a5 + 0x2E) = 0x280U;
        }
        reg_a2 = (u8 *)(D_00258FF0);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        temp_a0 = (u32)reg_d0.h[0] + 0x440;
        reg_d0.h[0] = temp_a0;
        reg_d1.h[0] += *(u16 *)(reg_a5 + 0x2E);
        aim_at_player();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        *(u8 *)(reg_a5 + 0x28) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x24) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a5 + 0x26) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d1.b[0] = 3;
        if ((s32) g_stage > 1) {
            reg_d1.b[0] = 3;
        }
        *(u8 *)(reg_a5 + 0x2B) = (u8) reg_d1.b[0];
        reg_d0.h[0] = g_rank_8_16;
        *(u8 *)(reg_a5 + 0x1F) -= reg_d0.b[0];
        reg_a0_as_s8_p = (s8 *)D_0025AD50;
        reg_d0.h[0] = g_stage_x2;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        ENTITY(reg_a6)->attr.sb.palette = (s8) *reg_a0_as_s8_p;
        *(s8 *)(reg_a5 + 0x1D) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        *(s8 *)(reg_a5 + 0x1C) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) {
            *(s16 *)(reg_a5 + 0x30) = 1;
            reg_d0.w = 0;
            *(u8 *)(reg_a5 + 0x32) = (u8) ENTITY(reg_a6)->misc.b.user;
            if (*(u8 *)(reg_a5 + 0x32) == 0) {
                reg_a0_as_s8_p = (s8 *)(reg_a6 + 0x16);
            } else {
                reg_a0_as_s8_p = (s8 *)(reg_a6 + 0x14);
            }
            *(u16 *)reg_a0_as_s8_p = 0xF800;
        }
        ENTITY(reg_a6)->misc.b.user = 0U;
    }
}

s32 func_0018D520();
extern u16 D_00259370[];
extern u16 D_0025ADE0[];
extern u16 D_0025ADF0[];

void func_001676F0(void) {
    s32 func_00170BE0();
    s16 *t1;
    s16 *t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u16 v1;
    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        if ((*(u16 *)(reg_a5 + 0x30) != 0) && (ENTITY(reg_a6)->flags.b[1] & 0x20)) {
            reg_a0 = (u8 *)(reg_a6 + 0x16);
            if (*(u16 *)(reg_a5 + 0x32) != 0) {
                reg_a0 = (u8 *)(reg_a6 + 0x14);
                reg_d3.h[0] *= 0xFFFF;
            }
            t6 = *(u16 *)reg_a0;
            if ((s16)(t6) < 0x800) {
                *(s16 *)reg_a0 = t6 + reg_d3.h[0];
            }
        }
        v1 = D_0029C068[0];
        reg_d0.h[1] = ENTITY(reg_a6)->y.h;
        reg_d0.h[0] = ENTITY(reg_a6)->x.h;
        reg_tmp.w = 0;
        reg_tmp.h[0] = 0xA800;
        reg_tmp1.w = 0;
        t5 = (u32)reg_d0.h[0] + 0x1000;
        reg_d0.h[0] = t5;
        reg_d0.h[0] += v1;
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x7FFF + 0x2801;
        if (reg_tmp.h[1] != 0) {
            goto next_20;
        }
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7800;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] = reg_d0.h[1];
        reg_d0.h[1] = reg_tmp.h[0];
        reg_d0.h[0] += 0xC00;
        reg_tmp.w = 0;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0x7800;
        reg_tmp.w += reg_tmp1.sw;
        if (reg_tmp.h[1] != 0) {
next_20:
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                enemy_remove();
                return;
            }
            goto next_1;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
next_1:
        t1 = (s16 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(t1) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
            if (((s32) (*(u16 *)((u8 *)(t1) + (0x18))) < 0x2C0) && (D_0028E8B8 == 0)) {
                reg_d0.w = 0x19;
            }
            goto next_2;
        }
        (*(u8 *)((u8 *)(t1) + (1))) &= 0xA3;
        score_add_no_chain();
        reg_d0.b[0] = ENTITY(reg_a6)->attr.b.palette;
        if (reg_d0.b[0] == 0x19) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
        }
        reg_d2.b[0] = *(u8 *)(reg_a5 + 0x1C);
        reg_d0.b[0] ^= reg_d2.b[0];
        if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
next_2:
            ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
            func_001368E0();
            if ((g_enemies_stopped == 0) && ((s32) ENTITY(reg_a6)->move.b.dir < 0x40)) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x35);
                *(u8 *)(reg_a5 + 0x35) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x35) = (u8) *(u8 *)(reg_a6 + 0x34);
                    if (ENTITY(reg_a6)->move.b.dir == 0x10) {
                        *(u16 *)(reg_a5 + 0x36) += 4;
                        if (*(u16 *)(reg_a5 + 0x36) == 0x10) {
                            *(u16 *)(reg_a5 + 0x36) = 0U;
                        }
                    } else {
                        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x36);
                        *(u16 *)(reg_a5 + 0x36) -= 4;
                        if ((s32) reg_tmp.b[0] < 4) {
                            *(u16 *)(reg_a5 + 0x36) = 0xCU;
                        }
                    }
                    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x36);
                    reg_a0 = (u8 *)(D_0025ADE0);
                    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                }
            }
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                *(u8 *)(reg_a5 + 0x23) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                    reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                    reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                    if (*(u8 *)(reg_a5 + 2) != 0) {
                        reg_atmp = (u8 *)(reg_a0);
                        reg_a0 = (u8 *)(reg_a1);
                        reg_a1 = (u8 *)(reg_atmp);
                    }
                    t2 = (s16 *)(reg_a0);
                    if ((*(s16 *)((u8 *)(t2) + (0))) >= 0) {
                        if (*(s16 *)reg_a1 < 0) {
                            reg_a0 = (u8 *)(reg_a1);
                            reg_atmp = (u8 *)(t2);
                            reg_a1 = (u8 *)(t2);
                            goto next_3;
                        }
                    } else {
next_3:
                        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
                        reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
                        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                        t3 = ENTITY(reg_a6)->x.h;
                        reg_d1.h[0] = t3;
                        reg_a3 = (u8 *)(D_00258FF0);
                        reg_d0.h[0] += 0x440;
                        reg_d1.h[0] += *(u16 *)(reg_a5 + 0x2E);
                        direction_between();
                        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x28);
                        direction_turn_toward();
                        *(u16 *)(reg_a5 + 0x28) = (u16) reg_d1.h[0];
                        reg_d1.h[0] &= 0x3E;
                        reg_d1.h[0] += reg_d1.h[0];
                        *(u16 *)(reg_a5 + 0x24) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                        *(u16 *)(reg_a5 + 0x26) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                    }
                }
            }
            func_00170A60();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += *(u16 *)(reg_a5 + 0x2E);
            reg_d1.h[1] += 0x7FFF + 0x7E41;
            reg_d1.h[0] += 0x7FFF + 0x7C01;
            reg_d2.h[1] = *(u16 *)(reg_a5 + 0x24);
            reg_d2.h[0] = *(u16 *)(reg_a5 + 0x26);
            reg_d3.h[0] = 0x620;
            reg_d4.w = 0;
            reg_d4.b[0] = ENTITY(reg_a6)->attr.b.palette;
            func_00170BE0();
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            if (g_enemies_stopped != 0) {
                goto block_rts;
            }
            if (g_bullets_blocked != 0) {
                goto block_rts;
            }
            if ((s16) ENTITY(reg_a6)->y.h < 0x1000) {
                goto block_rts;
            }
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
            *(u8 *)(reg_a5 + 0x1F) -= 1;
            switch (reg_tmp.b[0]) {
            case 0:
                break;
            default:
                return;
            }
            reg_d0.h[0] = 3;
            reg_d1.h[0] = g_rank_1_16;
            reg_d1.h[0] >>= 3;
            reg_d0.h[0] -= reg_d1.h[0];
            *(u8 *)(reg_a5 + 0x1F) = (u8) reg_d0.b[0];
            reg_a4 = (u8 *)(D_00259370);
            reg_d1.h[0] = *(u16 *)(reg_a5 + 0x28);
            reg_d0.h[0] = reg_d1.h[0];
            reg_d0.h[0] &= 0x3E;
            reg_d0.h[0] += reg_d0.h[0];
            reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
            reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
            reg_d3.h[0] += *(u16 *)(reg_a5 + 0x2E);
            reg_d3.h[1] += 0x440;
            reg_d4.w = (u32) reg_a6;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            t4 = ENTITY(reg_a6)->x.h;
            reg_d2.h[0] = t4;
            reg_d0.w = 0x2000C;
            if (*(u8 *)(reg_a5 + 0x21) & 1) {
                reg_d1.h[0] -= 2;
                bullet_fire_double();
                reg_d1.h[0] += 4;
                bullet_fire_double();
            } else {
                bullet_fire_double();
            }
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
            *(u8 *)(reg_a5 + 0x21) -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                goto block_rts;
            }
            *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
            reg_d0.h[0] = 0xA;
            reg_d0.h[0] -= g_rank_1_16;
            reg_d0.h[0] += 8;
            *(u8 *)(reg_a5 + 0x1F) = (u8) reg_d0.b[0];
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x2D);
            *(u8 *)(reg_a5 + 0x2D) -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                goto block_rts;
            }
            *(u8 *)(reg_a5 + 0x2D) = (u8) *(u8 *)(reg_a5 + 0x2C);
            reg_d0.h[0] = 0x70;
            reg_d0.h[0] -= g_rank_4_16;
            *(u8 *)(reg_a5 + 0x1F) = (u8) reg_d0.b[0];
block_rts:
            return;
        } else {
            func_0018D520();
            reg_d0.w = 0x88;
            score_add();
            func_00170CA0();
            reg_d2.w = 0xFE000000;
            reg_d0.w = 0xC;
            func_00211550();
            reg_d0.w = 8;
            reg_a4 = (u8 *)(D_0025ADF0);
            reg_d6.w = 4;
            do {
                reg_d1.h[1] = *(u16 *)reg_a4;
                reg_a4 += 2;
                reg_d1.h[0] = *(u16 *)reg_a4;
                reg_a4 += 2;
                func_00125EF0();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_d0.w = 0xD;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            func_00170D00();
            if (g_stage == 1) {
                *(s16 *)(reg_a0 + 0x1E) = 8;
            }
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(u16 *)(reg_a0 + 0x26) = 0xFC00;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x10) = 1;
            reg_d0.w = 8;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            func_00170D00();
            if (g_stage == 1) {
                *(s16 *)(reg_a0 + 0x1E) = 8;
            }
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u16 *)(reg_a0 + 0x26) = 0xF600;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x10) = 1;
            enemy_remove();
        }
    }
}
