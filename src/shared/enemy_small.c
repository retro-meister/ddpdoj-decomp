#include "common.h"
#include "entity.h"

void func_0016D290(void);

extern u8 D_0025B100[];

void func_0016CDD0(void) {
    u8 temp_v1;

    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->misc.b.draw_layer;
    reg_a0 = D_0025B100;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d0.h[0] *= 8;
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a5 + 0x2A) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a5 + 0x2C) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a5 + 0x2E) = (u16) *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x30) = (u16) *(u16 *)(reg_a0 + 2);
    temp_v1 = ENTITY(reg_a6)->misc.b.user;
    if (temp_v1 != 0) {
        reg_d1.b[0] = temp_v1;
    }
    reg_d1.h[0] += reg_d1.h[0];
    ENTITY(reg_a6)->misc.b.user = (u8) reg_d1.b[0];
}

s32 explosion_spawn();
extern u16 *reg_a1_as_u16_p;

void func_0016CEA0(void) {
    explosion_spawn();
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->misc.b.user;
    *(u16 *)(reg_a0 + 0x1E) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1_as_u16_p + ((s16)reg_d0.h[0] & ~1)) : *reg_a1_as_u16_p;
    *(s16 *)(reg_a0 + 0x10) = 1;
}

s32 func_002114C0();
extern u16 D_0025B150[];
extern u16 *reg_a0_as_u16_p;

void func_0016CF40(void) {
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)->misc.b.draw_layer;
    reg_a0_as_u16_p = D_0025B150;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0_as_u16_p + ((s16)reg_d1.h[0] & ~1)) : *reg_a0_as_u16_p;
    func_002114C0();
}

typedef void (*Fn)(void);
extern u8 *jtbl_0028E3F4_as_u8_p;

void func_0016CFB0(void) {
    reg_d2.w = 0;
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x1E);
    reg_d2.h[0] += 1;
    if (reg_d2.h[0] == 4) {
        reg_d2.w = 0;
    }
    *(u16 *)(reg_a5 + 0x1E) = reg_d2.h[0];
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x1E;
    reg_d2.w += 0x13D8;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x2E);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x30);
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn)jtbl_0028E3F4_as_u8_p)();
}


extern u8 D_00267030[];
extern u8 D_00267050[];
extern u8 D_00267070[];
extern u8 D_00267090[];
extern u16 g_loop;
extern u16 g_stage_x4;

void func_0016D040(void) {
    cond_flag = 0;
    reg_d0.h[0] = g_stage_x4;
    reg_a0 = (u8 *)D_00267050;
    if (g_loop != 0) {
        reg_a0 = (u8 *)D_00267090;
    }
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)D_00267030;
    if (g_loop != 0) {
        reg_a0 = (u8 *)D_00267070;
    }
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = reg_a6 + 2;
    reg_d1.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d1.h[0] -= reg_d2.h[0];
    reg_tmp2.h[0] = reg_d2.h[0];
    reg_d2.h[0] = reg_d2.h[1];
    reg_d2.h[1] = reg_tmp2.h[0];
    reg_tmp.w = 0;
    reg_tmp1.w = 0;
    reg_tmp.h[0] = reg_d2.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_tmp1.w += reg_tmp.w;
    reg_d1.h[0] += reg_d2.h[0];
    if (reg_tmp1.h[1] == 0) {
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] -= reg_d3.h[0];
        reg_tmp3.h[0] = reg_d3.h[0];
        reg_d3.h[0] = reg_d3.h[1];
        reg_d3.h[1] = reg_tmp3.h[0];
        reg_tmp.w = 0;
        reg_tmp1.w = 0;
        reg_tmp.h[0] = reg_d3.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_tmp1.w += reg_tmp.w;
        reg_d1.h[0] += reg_d3.h[0];
        if (reg_tmp1.h[1] == 0) {
            func_0016D290();
            return;
        }
    }
    cond_flag = 1;
}

extern u16 D_0025B160[];
extern u16 g_stage;
extern s16 D_0029F1F0[];
extern u16 D_0029F1F2[];
extern u16 D_0029F1F4[];
extern s16 D_0029F260[];
extern u16 D_0029F262[];
extern u16 D_0029F264[];


void func_0016D290(void) {
    reg_d0.h[0] = 0x7FFF;
    if (D_0029F260[0] < 0) {
        reg_d2.h[0] = D_0029F262[0];
        reg_d3.h[0] = D_0029F264[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] -= reg_d2.h[0];
        if ((s16)(reg_d0.h[0]) < 0) {
            reg_d0.h[0] *= 0xFFFF;
        }
        reg_d2.h[0] = reg_d0.h[0];
        reg_d2.h[0] >>= 2;
        reg_d1.h[0] -= reg_d3.h[0];
        reg_d0.h[0] -= reg_d2.h[0];
        if ((s16)(reg_d1.h[0]) < 0) {
            reg_d1.h[0] *= 0xFFFF;
        }
        if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
            reg_tmp1.w = reg_d1.w;
            reg_d1.w = reg_d0.w;
            reg_d0.w = reg_tmp1.w;
        }
        reg_d1.h[0] >>= 1;
        reg_d0.h[0] += reg_d1.h[0];
    }
    reg_d4.h[0] = reg_d0.h[0];
    reg_d0.h[0] = 0x7FFF;
    if (D_0029F1F0[0] < 0) {
        reg_d2.h[0] = D_0029F1F2[0];
        reg_d3.h[0] = D_0029F1F4[0];
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] -= reg_d2.h[0];
        if ((s16)(reg_d0.h[0]) < 0) {
            reg_d0.h[0] *= 0xFFFF;
        }
        reg_d2.h[0] = reg_d0.h[0];
        reg_d2.h[0] >>= 2;
        reg_d1.h[0] -= reg_d3.h[0];
        reg_d0.h[0] -= reg_d2.h[0];
        if ((s16)(reg_d1.h[0]) < 0) {
            reg_d1.h[0] *= 0xFFFF;
        }
        if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
            reg_tmp1.w = reg_d1.w;
            reg_d1.w = reg_d0.w;
            reg_d0.w = reg_tmp1.w;
        }
        reg_d1.h[0] >>= 1;
        reg_d0.h[0] += reg_d1.h[0];
    }
    if ((s32) reg_d0.h[0] > (s32) reg_d4.h[0]) {
        reg_d0.h[0] = reg_d4.h[0];
    }
    reg_a0 = (u8 *)(D_0025B160);
    reg_d4.h[0] = g_stage;
    reg_d4.h[0] += reg_d4.h[0];
    reg_a0 += reg_d4.h[0];
    reg_d4.h[0] = *(u16 *)reg_a0;
    if ((s32) reg_d4.h[0] > (s32) reg_d0.h[0]) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

void func_0016D520(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 enemy_set_task_work();
s32 enemy_init_entities();
s32 enemy_path_start();
extern u16 D_0025B170[];
extern u16 D_0025B180[];
extern u16 D_0025B1A0[];
extern u16 D_0025B3C0_as_u16_a[];
extern u16 g_rank_1_16;
extern u16 g_rank_5_16;
extern u16 g_stage_x2;
extern s8 enemy_move_end_requested;

void func_0016D530(void) {
    reg_a0 = (u8 *)(D_0025B1A0);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_0025B180);
    reg_d0.w = 0xF;
    enemy_set_task_work();
    reg_d0.h[0] = g_stage;
    reg_d0.h[0] >>= 1;
    reg_d0.h[0] += 2;
    *(u8 *)(reg_a5 + 0x1D) = (u8) reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x1C) = (u8) reg_d0.b[0];
    reg_d0.h[0] = g_rank_5_16;
    *(u8 *)(reg_a5 + 0x29) -= reg_d0.b[0];
    reg_d0.h[0] = g_rank_1_16;
    reg_d0.h[0] >>= 4;
    *(u8 *)(reg_a5 + 0x18) -= reg_d0.b[0];
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if ((s32) ENTITY(reg_a6)->y.h >= 0x7600) {
            *(s8 *)(reg_a5 + 0x33) = 1;
        }
        if (g_stage == 2) {
            ENTITY(reg_a6)->misc.sb.draw_layer = 2;
        }
        func_0016CDD0();
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
        reg_a6 = (void *) reg_tmp.w;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        *(u8 *)(reg_a5 + 0x32) = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(D_0025B3C0_as_u16_a);
        reg_d1.b[0] += 1;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x22) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x24) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_0025B170);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        *(s8 *)(reg_a5 + 0x35) = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(s8 *)(reg_a5 + 0x34) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

typedef void (*Fn)();

extern u8 D_0025B1C0[];
extern u8 D_0025B2C0[];
extern u8 D_0025B3C0[];

s32 bullet_fire_fast();
s32 enemy_hitbox_debug_draw();
s32 enemy_remove();
s32 enemy_path_step();
s32 func_0018D4E0();
s32 score_add_no_chain();
s32 score_add();
s32 aim_at_player();
s32 direction_turn_toward();
extern u8 D_0025B130_as_u8_a[];
extern u8 D_0025B140_as_u8_a[];
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern u16 g_enemy_signal_0;
extern u16 g_enemies_stopped;
extern u16 g_rank_3_16;
extern u16 D_0029C068[];
extern void (*jtbl_0028E3F4)();

void func_0016D790(void) {
    enemy_path_step();
    if (enemy_move_end_requested != 0) goto block_rts;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_d0.h[0] += 0x1200;
    reg_tmp.w = 0;
    reg_d0.h[0] += D_0029C068[0];
    reg_tmp1.h[0] = 0xA400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0xA400;
    if (reg_tmp.h[1] != 0) goto block_a;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    if (*(u8 *)(reg_a5 + 0x33) == 0) goto next_1;
    if (!((s32) reg_d0.h[0] < 0x7600)) goto next_1;
    *(u8 *)(reg_a5 + 0x33) = 0;
next_1:
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_tmp1.h[0] = 0x7C00;
    reg_d0.h[0] += 0xA00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7C00;
    if (reg_tmp.h[1] == 0) goto next_2;
block_a:
    if (*(u16 *)(reg_a5 + 0x16) == 0) goto next_3;
    enemy_remove();
    return;
next_2:
    *(u16 *)(reg_a5 + 0x16) = 1;
next_3:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    switch (reg_d1.b[0]) { case 0: goto next_4; }
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x34);
    ENTITY(reg_a6)->attr.b.palette ^= reg_d0.b[0];
    score_add_no_chain();
    if (ENTITY(reg_a6)->hp.sh >= 0) goto next_5;
    if (*(s8 *)(reg_a5 + 0x21) < 0) goto block_e;
    ENTITY(reg_a6)->flags.b[1] &= 0xFD;
    ENTITY(reg_a6)->hp.h = *(u16 *)(reg_a5 + 0x26);
    reg_d0.w = 8;
    score_add();
    *(u8 *)(reg_a5 + 0x21) |= 0x80;
    reg_d0.w = 3;
    reg_a1 = (u8 *)D_0025B140_as_u8_a;
    func_0016CEA0();
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0;
    goto next_5;
next_4:
    ENTITY(reg_a6)->attr.b.palette = *(u8 *)(reg_a5 + 0x35);
next_5:
    if (g_enemies_stopped != 0) goto next_7;
    reg_d7.h[0] = ENTITY(reg_a6)->move.h;
    reg_d1.w = 0x3E;
    reg_d1.h[0] &= reg_d7.h[0];
    reg_d1.h[0] *= 4;
    if (reg_d7.h[0] & 0x40) goto next_6;
    if (!(D_0028E3F0 & 4)) goto next_6;
    reg_d1.h[0] += 4;
next_6:
    reg_a0 = (u8 *)D_0025B2C0;
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_7:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x2A);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x2C);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if (*(s8 *)(reg_a5 + 0x21) >= 0) goto block_b;
    if (D_0028E3EC == 0) goto block_rts;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFE00;
    func_0016CFB0();
    goto block_rts;
block_b:
    if (g_enemies_stopped != 0) goto block_c;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x32);
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x19);
    *(u8 *)(reg_a5 + 0x19) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_8;
    *(u8 *)(reg_a5 + 0x19) = *(u8 *)(reg_a5 + 0x18);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x200;
    aim_at_player();
    if (cond_flag != 0) goto block_c;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x32);
    direction_turn_toward();
    *(u8 *)(reg_a5 + 0x32) = reg_d1.b[0];
    reg_a0 = (u8 *)D_0025B3C0;
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    *(u16 *)(reg_a5 + 0x22) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x24) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_8:
    if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) goto block_c;
    *(u8 *)(reg_a5 + 0x29) -= 1;
    if (*(u8 *)(reg_a5 + 0x29) == 0) goto block_d;
block_c:
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFA00FA00;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x22);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x24);
    reg_d3.h[0] = 0x830;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x2E);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x30);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
    goto block_rts;
block_d:
    reg_d0.w = 0x18;
    reg_d0.h[0] -= g_rank_1_16;
    *(u8 *)(reg_a5 + 0x29) = reg_d0.b[0];
    func_0016D040();
    if (cond_flag != 0) goto block_c;
    if (g_stage != 1) goto next_9;
    if (g_enemy_signal_0 != 0) goto block_c;
next_9:
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x200;
    aim_at_player();
    if (cond_flag != 0) goto block_c;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d0.w = 0x3C;
    reg_d2.b[0] += 2;
    reg_d2.h[0] &= reg_d0.h[0];
    reg_d3.b[0] = *(u8 *)(reg_a5 + 0x32);
    reg_d3.b[0] += 2;
    reg_d3.h[0] &= reg_d0.h[0];
    if (reg_d3.b[0] == reg_d2.b[0]) goto next_10;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1C);
    if (*(u8 *)(reg_a5 + 0x1D) == reg_d0.b[0]) goto block_c;
next_10:
    *(u8 *)(reg_a5 + 0x29) = *(u8 *)(reg_a5 + 0x1A);
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1D);
    *(u8 *)(reg_a5 + 0x1D) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_11;
    *(u8 *)(reg_a5 + 0x1D) = *(u8 *)(reg_a5 + 0x1C);
    reg_d0.w = 0x40;
    reg_d0.h[0] -= g_rank_3_16;
    *(u8 *)(reg_a5 + 0x29) = reg_d0.b[0];
next_11:
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0x32);
    reg_a0 = (u8 *)D_0025B1C0;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 1;
    reg_d3.h[0] &= 0x3E;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d2.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.w += reg_tmp.w;
    reg_d1.b[0] += 2;
    reg_d1.h[0] &= 0x3C;
    reg_d0.w = 0xC;
    reg_d3.w = 0x02000000;
    bullet_fire_fast();
    goto block_c;
block_e:
    reg_d0.w = 0x10;
    score_add();
    reg_d0.w = 4;
    reg_a1 = (u8 *)D_0025B130_as_u8_a;
    func_0016CEA0();
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(s16 *)(reg_a0 + 0x12) = 0;
    *(s16 *)(reg_a0 + 0x14) = 0;
    reg_d0.w = 4;
    func_0016CF40();
    func_0018D4E0();
    enemy_remove();
block_rts:
    return;
}

void func_0016E000(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 rng_next_masked();
extern u16 D_0025B440[];
extern u16 D_0025B450[];
extern u16 D_0025B470[];
extern u16 D_0025B610_as_u16_a[];
extern u16 g_scroll_line;
extern u16 g_rank_2_16;
extern u16 g_rank_6_16;

void func_0016E010(void) {
    reg_a0 = (u8 *)(D_0025B470);
    enemy_init_entities();
    reg_a0 = (u8 *)(D_0025B450);
    reg_d0.w = 0xF;
    enemy_set_task_work();
    reg_d0.h[0] = g_rank_6_16;
    *(u8 *)(reg_a5 + 0x29) -= reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x1B) -= reg_d0.b[0];
    rng_next_masked();
    reg_d0.b[0] >>= 1;
    *(u8 *)(reg_a5 + 0x29) += reg_d0.b[0];
    reg_d0.h[0] = g_rank_1_16;
    reg_d0.h[0] >>= 4;
    *(u8 *)(reg_a5 + 0x19) -= reg_d0.b[0];
    if ((g_stage == 1) && ((s32) g_scroll_line >= 0x159)) {
        reg_d0.w = 0x30;
        reg_d0.h[0] -= g_rank_2_16;
        reg_d0.h[0] -= 6;
        *(u8 *)(reg_a5 + 0x29) = (u8) reg_d0.b[0];
    }
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        if (g_stage == 2) {
            ENTITY(reg_a6)->misc.sb.draw_layer = 2;
        }
        func_0016CDD0();
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
        reg_a6 = (void *) reg_tmp.w;
        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        *(u8 *)(reg_a5 + 0x32) = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(D_0025B610_as_u16_a);
        reg_d1.b[0] += 1;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x22) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x24) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_0025B440);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        ENTITY(reg_a6)->attr.sb.palette = *(s8 *)reg_a0;
        *(s8 *)(reg_a5 + 0x35) = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(s8 *)(reg_a5 + 0x34) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

extern u16 D_0025B130[];
extern u16 D_0025B140[];
extern u16 D_0025B490_as_u16_a[];
extern u16 D_0025B510_as_u16_a[];
extern u16 D_0028E7DC_as_u16;
extern u16 D_0028E7E0_as_u16;
extern u16 g_rank_10_16;

void func_0016E2A0(void) {
    u32 swap;

    enemy_path_step();
    if (enemy_move_end_requested != 0) {
        return;
    }
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0xE00;
    reg_d0.h[0] += D_0029C068[0];
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xAC00;
    reg_tmp1.w += reg_tmp.w;
    reg_d0.h[0] += 0xAC00;
    if (reg_tmp1.h[1] != 0) goto next_lim;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x8400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    swap = reg_tmp.h[0];
    reg_d0.h[0] += 0x600;
    reg_tmp.w = 0;
    reg_d0.h[1] = swap;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp1.w += reg_tmp.w;
    reg_d0.h[0] += 0x8400;
next_lim:
    if (reg_tmp1.h[1] == 0) goto next_40;
    if (*(u16 *)(reg_a5 + 0x16) == 0) goto next_50;
    enemy_remove();
    return;
next_40:
    *(u16 *)(reg_a5 + 0x16) = 1;
next_50:
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= ENTITY(reg_a6)->flags.b[1];
    if (reg_d1.b[0] == 0) goto next_100;
    ENTITY(reg_a6)->flags.b[1] &= 0xA3;
    reg_d0.b[0] = reg_a5[0x34];
    ENTITY(reg_a6)->attr.b.palette ^= reg_d0.b[0];
    score_add_no_chain();
    if (ENTITY(reg_a6)->hp.sh >= 0) goto next_110;
    if ((s8) reg_a5[0x21] < 0) goto block_70;
    ENTITY(reg_a6)->hp.h = *(u16 *)(reg_a5 + 0x26);
    reg_d0.w = 8;
    score_add();
    reg_a5[0x21] |= 0x80;
    if (D_0028E7E0_as_u16 != 0) goto next_110;
    D_0028E7E0_as_u16 = 1;
    reg_d0.w = 3;
    reg_a1_as_u16_p = (u16 *)D_0025B140;
    func_0016CEA0();
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    goto next_110;
next_100:
    ENTITY(reg_a6)->attr.b.palette = reg_a5[0x35];
next_110:
    if (g_enemies_stopped != 0) goto next_225;
    reg_d7.h[0] = ENTITY(reg_a6)->move.h;
    reg_d1.w = 0x3E;
    reg_d1.h[0] &= reg_d7.h[0];
    reg_d1.h[0] <<= 2;
    if (reg_d7.h[0] & 0x40) goto next_220;
    if (!(D_0028E3F0 & 4)) goto next_220;
    reg_d1.h[0] += 4;
next_220:
    reg_a0 = (u8 *) D_0025B510_as_u16_a;
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_225:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x2A);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x2C);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn) reg_a0;
    jtbl_0028E3F4();
    reg_a0 = reg_a6;
    enemy_hitbox_debug_draw();
    if ((s8) reg_a5[0x21] >= 0) goto next_300;
    if (D_0028E3EC == 0) goto block_rts;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0x100FE00;
    func_0016CFB0();
    return;
next_300:
    if (g_enemies_stopped != 0) goto block_objset;
    reg_d1.b[0] = reg_a5[0x32];
    reg_tmp.b[0] = reg_a5[0x19];
    reg_a5[0x19] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_500;
    reg_a5[0x19] = reg_a5[0x18];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x200;
    aim_at_player();
    if (cond_flag != 0) goto block_objset;
    reg_d0.b[0] = reg_a5[0x32];
    direction_turn_toward();
    reg_a5[0x32] = reg_d1.b[0];
    reg_a0 = (u8 *) D_0025B610_as_u16_a;
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d1.h[0] += reg_d1.h[0];
    *(u16 *)(reg_a5 + 0x22) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0x24) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
next_500:
    if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) goto block_objset;
    reg_a5[0x29] -= 1;
    if (reg_a5[0x29] == 0) goto block_shot;
block_objset:
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.w += 0xFC00FC00;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0x22);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x24);
    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x2E);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x30);
    reg_a0 = (u8 *) reg_tmp.w;
    jtbl_0028E3F4 = (Fn) reg_a0;
    jtbl_0028E3F4();
block_rts:
    return;
block_shot:
    reg_d0.h[0] = 0xA0;
    reg_d0.h[0] -= g_rank_10_16;
    reg_d0.h[0] += 4;
    if (g_loop != 0) goto next_610;
    if (g_stage != 1) goto next_610;
    if ((s32) g_scroll_line < 0x159) goto next_610;
    reg_d0.w = 0x30;
    reg_d0.h[0] -= g_rank_2_16;
    reg_d0.h[0] -= 6;
next_610:
    reg_a5[0x29] = reg_d0.b[0];
    func_0016D040();
    if (cond_flag != 0) goto block_objset;
    if (g_stage != 1) goto next_620;
    if (g_enemy_signal_0 != 0) goto block_objset;
next_620:
    if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) goto block_objset;
    reg_d1.b[0] = reg_a5[0x32];
    reg_a0 = (u8 *) D_0025B490_as_u16_a;
    reg_d1.b[0] += 2;
    reg_d1.h[0] &= 0x3C;
    reg_d2.h[0] = reg_d1.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = ENTITY(reg_a6)->y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.w += reg_tmp.w;
    reg_d0.w = 0xD;
    if ((s32) g_stage < 3) goto next_630;
    reg_d0.w = 0xFFFC000D;
next_630:
    reg_d3.w = 0x2000000;
    bullet_fire_fast();
    goto block_objset;
block_70:
    reg_d0.w = 0x10;
    score_add();
    reg_d0.w = 7;
    reg_a1_as_u16_p = (u16 *)D_0025B130;
    func_0016CEA0();
    *(u16 *)(reg_a0 + 0x26) = 0xFE00;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    if (D_0028E7E0_as_u16 == 0) goto next_71;
    *(u16 *)(reg_a0 + 0x12) = 0xFFFF;
next_71:
    D_0028E7E0_as_u16 = 1;
    D_0028E7DC_as_u16 += 1;
    if (!(D_0028E7DC_as_u16 & 1)) goto next_72;
    reg_d0.w = 4;
    func_0016CF40();
next_72:
    func_0018D4E0();
    enemy_remove();
}

void func_0016EA90(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(1);
}

s32 direction_between();
extern u16 D_00258FF0[];
extern u16 D_0025B690[];
extern u16 D_0025B6A0[];
extern u16 D_0025B6C0[];
extern u16 D_0025B740[];

void func_0016EAA0(void) {
    reg_a0 = (u8 *)(D_0025B6C0);
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(D_0025B6A0);
    reg_d0.w = 0xE;
    enemy_set_task_work();
    reg_d0.b[0] = 4;
    reg_d2.b[0] = 2;
    reg_d1.b[0] = 4;
    if ((s32) g_stage > 1) {
        reg_d0.b[0] = 3;
        reg_d1.b[0] = 6;
        reg_d2.b[0] = 1;
    }
    *(u8 *)(reg_a5 + 0x2B) = (u8) reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x2A) = (u8) reg_d1.b[0];
    *(u8 *)(reg_a6 + 0x31) = (u8) reg_d2.b[0];
    enemy_path_start();
    if (enemy_move_end_requested == 0) {
        reg_a0 = (u8 *)(D_00258FF0);
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0xB00;
        direction_between();
        if (cond_flag != 0) {
            reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
        }
        *(u8 *)(reg_a5 + 0x28) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        *(u16 *)(reg_a5 + 0x24) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a5 + 0x26) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x28);
        reg_a0 = (u8 *)(D_0025B740);
        *(u16 *)(reg_a6 + 0x2A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x2C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_0025B690);
        reg_d0.h[0] = g_stage_x2;
        reg_a0 += reg_d0.h[0];
        *(s8 *)(reg_a5 + 0x1D) = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(s8 *)(reg_a5 + 0x1C) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}

s32 bullet_fire256_fast();
s32 bullet_fire256_double();
s32 func_001368E0();
s32 func_0018D580();
s32 entity_draw_layer1();
s32 sprite_draw_layer1();
s32 rng_next();
s32 func_00201100();
s32 aim256_at_player();
s32 func_00211550();
extern u16 D_00259370[];
extern u16 D_00259870[];
extern u16 g_bullets_blocked;
extern u16 D_0028E8B8;
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];

void func_0016ED40(void) {
    s16 *t1;
    s16 *t2;
    u16 t3;
    u16 t4;
    u16 t5;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x6E00;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1000;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x6E00;
        if (reg_tmp.h[1] != 0) {
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
            if (((s32) (*(u16 *)((u8 *)(t1) + (0x18))) < 0x7C0) && (D_0028E8B8 == 0)) {
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
            if (g_enemies_stopped == 0) {
                ENTITY(reg_a6)->offset_y.h = 0xF000U;
                if ((s32) ENTITY(reg_a6)->move.b.dir < 0x40) {
                    *(u16 *)(reg_a6 + 0x36) += 0x20;
                    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x36);
                    reg_d0.h[0] &= 0x40;
                    ENTITY(reg_a6)->offset_y.h += reg_d0.h[0];
                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x27);
                    *(u8 *)(reg_a6 + 0x27) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a6 + 0x27) = (u8) *(u8 *)(reg_a6 + 0x26);
                        if (ENTITY(reg_a6)->move.b.dir == 0) {
                            *(u16 *)(reg_a6 + 0x28) += 4;
                            if (*(u16 *)(reg_a6 + 0x28) == 0x10) {
                                *(u16 *)(reg_a6 + 0x28) = 0U;
                            }
                        } else {
                            reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x28);
                            *(u16 *)(reg_a6 + 0x28) -= 4;
                            if ((s32) reg_tmp.h[0] < 4) {
                                *(u16 *)(reg_a6 + 0x28) = 0xCU;
                            }
                        }
                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x28);
                        reg_a0 = (u8 *)(D_0025B740);
                        ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    }
                }
            }
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0)) {
                reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                *(u8 *)(reg_a5 + 0x23) -= 1;
                if (((s32) reg_tmp.b[0] <= 0) && (*(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22), reg_d0.b[0] = *(u8 *)(reg_a5 + 0x21), (*(u8 *)(reg_a5 + 0x20) == reg_d0.b[0]))) {
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
                        reg_d0.h[0] += 0xB00;
                        direction_between();
                        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x28);
                        direction_turn_toward();
                        *(u16 *)(reg_a5 + 0x28) = (u16) reg_d1.h[0];
                        reg_d1.h[0] &= 0x3E;
                        reg_d1.h[0] += reg_d1.h[0];
                        *(u16 *)(reg_a5 + 0x24) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                        *(u16 *)(reg_a5 + 0x26) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
                        goto next_4;
                    }
                } else {
next_4:
                    if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                        *(u8 *)(reg_a5 + 0x1F) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x2A);
                            reg_a4 = (u8 *)(D_00259370);
                            reg_d1.h[0] = *(u16 *)(reg_a5 + 0x28);
                            reg_d0.h[0] = reg_d1.h[0];
                            reg_d1.h[0] *= 4;
                            func_00201100();
                            reg_d1.b[0] += reg_d5.b[0];
                            reg_d0.h[0] &= 0x3E;
                            reg_d0.h[0] += reg_d0.h[0];
                            reg_d5.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a4;
                            reg_d5.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a4 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a4;
                            reg_d0.w = 5;
                            reg_d4.w = 0;
                            reg_tmp5.h[0] = reg_d5.h[0];
                            reg_d5.h[0] = reg_d5.h[1];
                            reg_d5.h[1] = reg_tmp5.h[0];
                            reg_d5.h[0] += 0xB00;
                            reg_tmp5.h[0] = reg_d5.h[0];
                            reg_d5.h[0] = reg_d5.h[1];
                            reg_d5.h[1] = reg_tmp5.h[0];
                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                            reg_d1.h[0] -= 0x24;
                            reg_d7.h[0] = 6;
                            reg_a0 = (u8 *)(D_00259870);
                            do {
                                reg_d3.h[0] = reg_d1.h[0];
                                reg_d3.h[0] += 2;
                                reg_d3.h[0] &= 0xFC;
                                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                                reg_d3.w += reg_d5.w;
                                bullet_fire256_double();
                                reg_d1.h[0] += 0xC;
                            } while ((s16)(--reg_d7.h[0]) >= 0);
                            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
                            *(u8 *)(reg_a5 + 0x21) -= 1;
                            if ((s32) reg_tmp.b[0] <= 0) {
                                *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
                                *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                            }
                        }
                    }
                }
            }
            entity_draw_layer1();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            t4 = reg_d1.h[0];
            reg_d1.h[1] += 0x500;
            reg_d1.h[0] = (u32)t4 + 0x7FFF + 0x7C01;
            reg_d2.h[1] = *(u16 *)(reg_a5 + 0x24);
            reg_d2.h[0] = *(u16 *)(reg_a5 + 0x26);
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer1();
            reg_a0 = (u8 *)(reg_a6);
            enemy_hitbox_debug_draw();
            if (g_enemies_stopped != 0) {
                return;
            }
            switch (g_bullets_blocked) {
            case 0:
                goto next_5;
            }
            return;
next_5:
            if ((s16) (ENTITY(reg_a6)->y.h) >= 0x1000) {
                if (reg_a5[0x31] != 0) {
                    goto next_6;
                }
                reg_tmp.b[0] = reg_a5[0x2F];
                reg_a5[0x2F] -= 1;
                if ((s32) reg_tmp.b[0] > 0) {
                    goto block_rts;
                }
                reg_a5[0x2F] = reg_a5[0x2B];
                reg_a5[0x31] = reg_a5[0x30];
                reg_a5[0x33] = 0x80;
                reg_a5[0x32] = 0x80;
                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0xFA00;
                reg_d1.h[0] += 0x680;
                aim256_at_player();
                if (cond_flag != 0) {
                    goto next_6;
                }
                reg_a5[0x33] = reg_d1.b[0];
                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0x7FFF + 0x7A01;
                reg_d1.h[0] += 0x7FFF + 0x7981;
                aim256_at_player();
                reg_a5[0x32] = reg_d1.b[0];
next_6:
                reg_tmp.b[0] = reg_a5[0x2F];
                reg_a5[0x2F] -= 1;
                if ((s32) reg_tmp.b[0] > 0) {
                    goto block_rts;
                }
                reg_a5[0x2F] = reg_a5[0x2B];
                reg_d1.w = 0;
                reg_d1.b[0] = reg_a5[0x33];
                rng_next();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
                reg_d1.b[0] += reg_d0.b[0];
                reg_d0.w = 0x20016;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0xFA000680;
                reg_d4.w = 0;
                bullet_fire256_fast();
                reg_d1.w = 0;
                reg_d1.b[0] = reg_a5[0x32];
                rng_next();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
                reg_d1.b[0] += reg_d0.b[0];
                reg_d0.w = 0x20016;
                reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                reg_d3.w = 0xF9FFF980;
                reg_d4.w = 0;
                bullet_fire256_fast();
                reg_tmp.b[0] = reg_a5[0x31];
                reg_a5[0x31] -= 1;
                if ((s32) reg_tmp.b[0] > 0) {
                    goto block_rts;
                }
                reg_a5[0x2F] = reg_a5[0x2E];
block_rts:
                return;
            }
        } else {
            reg_d0.w = 0x550;
            score_add();
            func_0018D580();
            reg_d1.h[0] = 0;
            reg_d0.w = 0xC;
            reg_d2.w = 0xF8000000;
            func_00211550();
            if (g_stage == 4) {
                if ((s32) g_scroll_line < 0x2B0) {
                    reg_d2.w = 0x08000000;
                    func_00211550();
                }
            }
            reg_d0.w = 0xD;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            t5 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = t5;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(s16 *)(reg_a0 + 0x26) = 0x400;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x10) = 1;
            reg_d0.w = 5;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(u16 *)(reg_a0 + 0x26) = 0xF800;
            *(s16 *)(reg_a0 + 0x28) = 0x600;
            *(s16 *)(reg_a0 + 0x10) = 1;
            reg_d0.w = 5;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(u16 *)(reg_a0 + 0x26) = 0xF600;
            *(u16 *)(reg_a0 + 0x28) = 0xFA00;
            *(s16 *)(reg_a0 + 0x10) = 1;
            enemy_remove();
        }
    }
}

void func_0016F930(void) {
    void enemy_set_entity_count(s32 mode);
    enemy_set_entity_count(1);
}

extern u16 D_0025B750[];
extern u16 D_0025B760[];
extern u16 D_0025B780[];
extern u16 D_0025B7F0_as_u16_a[];

void func_0016F940(void) {
    reg_a0 = (u8 *)(D_0025B780);
    enemy_init_entities();
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(D_0025B760);
    reg_d0.w = 0xE;
    enemy_set_task_work();
    reg_d0.b[0] = 4;
    reg_d1.b[0] = 4;
    if ((s32) g_stage > 1) {
        reg_d1.b[0] = 0;
        reg_d0.b[0] = 3;
    }
    *(u8 *)(reg_a5 + 0x2E) = (u8) reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x2F) = (u8) reg_d1.b[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x28);
    reg_a0 = (u8 *)(D_0025B7F0_as_u16_a);
    *(u16 *)(reg_a6 + 0x2A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x2C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_0025B750);
    reg_d0.h[0] = g_stage_x2;
    reg_a0 += reg_d0.h[0];
    *(s8 *)(reg_a5 + 0x1D) = *(s8 *)reg_a0;
    reg_a0 += 1;
    *(s8 *)(reg_a5 + 0x1C) = *(s8 *)reg_a0;
    reg_a0 += 1;
    g_enemy_signal_0 += 1;
    enemy_path_start();
    if (enemy_move_end_requested != 0) {
        return;
    }
}

s32 func_00125EC0();
s32 func_0018D520();
s32 entity_draw_layer4();
s32 sprite_draw_layer4();
extern u16 D_0025B7E0[];
extern u8 D_0025B7F0[];
extern u8 D_0025B800[];

void func_0016FAE0(void) {
    u8 *t1;
    u32 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;

    enemy_path_step();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7800;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0xC00;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.w;
        reg_d0.h[0] += 0x7800;
        if (reg_tmp.h[1] != 0) {
            if (*(u8 *)(reg_a5 + 0x17) != 0) {
                g_enemy_signal_0 -= 1;
                enemy_remove();
                return;
            }
            goto next_1;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
next_1:
        t1 = (u8 *)(reg_a6);
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(t1) + (1)));
        if (reg_d1.b[0] == 0) {
            reg_d0.b[0] = *(u8 *)(reg_a5 + 0x1D);
            if (((s32) (*(u16 *)((u8 *)(t1) + (0x18))) < 0x380) && (D_0028E8B8 == 0)) {
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
            if (g_enemies_stopped == 0) {
                ENTITY(reg_a6)->offset_y.h = 0xF400U;
                if ((s32) ENTITY(reg_a6)->move.b.dir < 0x40) {
                    *(u16 *)(reg_a6 + 0x2E) += 0x20;
                    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
                    reg_d0.h[0] &= 0x40;
                    ENTITY(reg_a6)->offset_y.h -= reg_d0.h[0];
                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x27);
                    *(u8 *)(reg_a6 + 0x27) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a6 + 0x27) = (u8) *(u8 *)(reg_a6 + 0x26);
                        if (ENTITY(reg_a6)->move.b.dir == 0) {
                            *(u16 *)(reg_a6 + 0x28) += 4;
                            if (*(u16 *)(reg_a6 + 0x28) == 0x10) {
                                *(u16 *)(reg_a6 + 0x28) = 0U;
                            }
                        } else {
                            reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x28);
                            *(u16 *)(reg_a6 + 0x28) -= 4;
                            if ((s32) reg_tmp.h[0] < 4) {
                                *(u16 *)(reg_a6 + 0x28) = 0xCU;
                            }
                        }
                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x28);
                        reg_a0 = (u8 *)D_0025B7F0;
                        *(u16 *)(reg_a6 + 0x2A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        *(u16 *)(reg_a6 + 0x2C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    }
                }
            }
            if ((g_enemies_stopped == 0) && (g_bullets_blocked == 0) && (g_enemies_stopped == 0) && (g_bullets_blocked == 0) && ((s16) ENTITY(reg_a6)->y.h >= 0x1000)) {
                reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
                if (reg_d0.h[0] == 0) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                    *(u8 *)(reg_a5 + 0x1F) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x1F) = 0x10U;
                        *(u16 *)(reg_a5 + 0x18) = 1U;
                    }
                } else if ((reg_d0.h[0] & 0xFFFF) == 1) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                    *(u8 *)(reg_a5 + 0x23) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                        if ((s16) ENTITY(reg_a6)->y.h < 0x6C00) {
                            *(u16 *)(reg_a5 + 0x24) += 4;
                            reg_d0.h[0] = *(u16 *)(reg_a5 + 0x24);
                            reg_a0 = (u8 *)D_0025B800;
                            *(u16 *)(reg_a5 + 0x26) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                            *(u16 *)(reg_a5 + 0x28) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            if (reg_d0.h[0] == 0x1C) {
                                *(u16 *)(reg_a5 + 0x34) = 0xFFFEU;
                                *(u16 *)(reg_a5 + 0x18) = 2U;
                            }
                        }
                    }
                } else if ((reg_d0.h[0] & 0xFFFF) == 2) {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
                    *(u8 *)(reg_a5 + 0x1F) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x2F);
                        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
                        reg_d0.h[0] += 0xA80;
                        aim256_at_player();
                        reg_d7.h[0] = reg_d1.h[0];
                        rng_next();
                        reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
                        reg_d1.b[0] += reg_d0.b[0];
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        t4 = ENTITY(reg_a6)->x.h;
                        reg_d2.h[0] = t4;
                        reg_d3.w = 0x0A800400;
                        reg_d4.w = 0;
                        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x34);
                        reg_tmp.h[0] = reg_d0.h[0];
                        reg_d0.h[0] = 0x13;
                        reg_d0.h[1] = reg_tmp.h[0];
                        bullet_fire256_fast();
                        reg_d1.h[0] = reg_d7.h[0];
                        rng_next();
                        reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
                        reg_d1.b[0] += reg_d0.b[0];
                        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                        t5 = ENTITY(reg_a6)->x.h;
                        reg_d2.h[0] = t5;
                        reg_d3.w = 0x0A7FFC00;
                        reg_d4.w = 0;
                        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x34);
                        reg_tmp.h[0] = reg_d0.h[0];
                        reg_d0.h[0] = 0x13;
                        reg_d0.h[1] = reg_tmp.h[0];
                        bullet_fire256_fast();
                        *(u16 *)(reg_a5 + 0x34) += 1;
                        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
                        *(u8 *)(reg_a5 + 0x21) -= 1;
                        if ((s32) reg_tmp.b[0] <= 0) {
                            *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
                            if (*(u8 *)(reg_a5 + 0x21) != 0) {
                                *(u8 *)(reg_a5 + 0x1F) = (u8) *(u8 *)(reg_a5 + 0x1E);
                                *(u16 *)(reg_a5 + 0x18) = 3U;
                                *(u8 *)(reg_a5 + 0x23) = 0x10U;
                            }
                        }
                    }
                } else {
                    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x23);
                    *(u8 *)(reg_a5 + 0x23) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a5 + 0x23) = (u8) *(u8 *)(reg_a5 + 0x22);
                        *(u16 *)(reg_a5 + 0x24) -= 4;
                        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x24);
                        reg_a0 = (u8 *)D_0025B800;
                        *(u16 *)(reg_a5 + 0x26) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                        *(u16 *)(reg_a5 + 0x28) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        if (reg_d0.h[0] == 0) {
                            *(u16 *)(reg_a5 + 0x18) = 0U;
                        }
                    }
                }
            }
            t2 = 0xFA00 & 0xFFFF;
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += t2;
            reg_tmp1.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = reg_tmp1.h[0];
            reg_d1.h[0] += 0x7FFF + 0x7201;
            reg_tmp1.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = reg_tmp1.h[0];
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x2A);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x2C);
            reg_d3.h[0] = 0x230;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer4();
            entity_draw_layer4();
            reg_d1.h[1] = ENTITY(reg_a6)->y.h;
            reg_d1.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += 0x7FFF + 0x7A01;
            reg_tmp1.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = reg_tmp1.h[0];
            reg_d1.h[0] += 0x800;
            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
            reg_d0.h[0] &= 0x40;
            reg_d1.h[0] -= reg_d0.h[0];
            reg_tmp1.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = reg_tmp1.h[0];
            reg_d2.h[1] = *(u16 *)(reg_a5 + 0x26);
            reg_d2.h[0] = *(u16 *)(reg_a5 + 0x28);
            reg_d3.h[0] = 0x430;
            reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
            sprite_draw_layer4();
            reg_a0 = reg_a6;
            enemy_hitbox_debug_draw();
            if (g_enemies_stopped != 0) {
                goto block_rts;
            }
            switch (g_bullets_blocked) {
            case 0:
                break;
            default:
                return;
            }
            if ((s16) ENTITY(reg_a6)->y.h < 0x1000) {
                goto block_rts;
            }
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x31);
            *(u8 *)(reg_a5 + 0x31) -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                goto block_rts;
            }
            *(u8 *)(reg_a5 + 0x31) = (u8) *(u8 *)(reg_a5 + 0x2E);
            reg_d0.w = 0xFFFE0004;
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d3.w = 0xFE000000;
            reg_d7.h[0] = 7;
            reg_d1.h[0] = 0x6B;
            reg_d4.w = 0;
            do {
                bullet_fire256_fast();
                reg_d1.h[0] += 7;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x33);
            *(u8 *)(reg_a5 + 0x33) -= 1;
            if ((s32) reg_tmp.b[0] > 0) {
                goto block_rts;
            }
            *(u8 *)(reg_a5 + 0x33) = (u8) *(u8 *)(reg_a5 + 0x32);
            *(u8 *)(reg_a5 + 0x31) = (u8) *(u8 *)(reg_a5 + 0x30);
block_rts:
            return;
        } else {
            reg_d0.w = 0x130;
            score_add();
            func_0018D520();
            reg_d0.w = 0xC;
            reg_d1.h[0] = 8;
            func_00211550();
            reg_d0.w = 0xD;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            t6 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = t6;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0x400;
            *(s16 *)(reg_a0 + 0x26) = 0x400;
            *(s16 *)(reg_a0 + 0x28) = 0;
            *(s16 *)(reg_a0 + 0x10) = 1;
            reg_d0.w = 0xC;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u16 *)(reg_a0 + 0x26) = 0xFA00;
            *(s16 *)(reg_a0 + 0x28) = 0x600;
            *(s16 *)(reg_a0 + 0x10) = 1;
            reg_d0.w = 0x84;
            explosion_spawn();
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 1;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u16 *)(reg_a0 + 0x26) = 0xFA00;
            *(u16 *)(reg_a0 + 0x28) = 0xFA00;
            *(s16 *)(reg_a0 + 0x10) = 1;
            g_enemy_signal_0 -= 1;
            reg_d0.w = 8;
            reg_a4 = (u8 *)(D_0025B7E0);
            reg_d6.w = 3;
            do {
                reg_d1.h[1] = *(u16 *)reg_a4;
                reg_a4 += 2;
                t3 = *(u16 *)reg_a4;
                reg_d1.h[0] = t3;
                reg_a4 += 2;
                reg_d2.w = 3;
                func_00125EC0();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            enemy_remove();
        }
    }
}

extern u8 D_0025B870[];

void func_00170690(void) {
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x1A);
    reg_a0 = D_0025B870;
    reg_a0 += reg_d0.h[0];
    ENTITY(reg_a6)->draw.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->sprite.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a5 + 0x18) = *(u16 *)reg_a0;
    reg_a0 += 2;
}

void func_00170710(void) {
    void enemy_set_entity_count(s32);
    enemy_set_entity_count(0);
}

s32 func_0018DCE0();
s32 sprite_palette_load();
extern u16 D_0025B820[];
extern u16 D_0025B830[];
extern u8 D_0025B840[];
extern u8 D_0025B850[];
extern u8 D_00261C30[];
extern u8 D_00261CF0[];

void func_00170720(void) {
    reg_a0 = D_0025B850;
    enemy_init_entities();
    reg_a0 = D_0025B840;
    reg_d0.w = 5;
    enemy_set_task_work();
    reg_tmp.w = 0x40001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
    func_0018DCE0();
    reg_a0 = D_00261CF0;
    reg_d6.h[0] = g_stage_x2;
    reg_a1 = (u8 *)(D_0025B820);
    reg_d0.h[0] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a1;
    ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
    sprite_palette_load();
    reg_a0 = D_00261C30;
    reg_a1 = (u8 *)(D_0025B830);
    reg_d0.h[0] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a1;
    sprite_palette_load();
}

s32 func_0018D9D0();
s32 func_0019D770();

void func_00170840(void) {
    u16 m;

    if (*(u16 *)(reg_a5 + 0x20) == 0) goto next_20;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_20;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x1E);
    func_0018D9D0();
    *(u16 *)(reg_a5 + 0x20) -= 1;
next_20:
    ENTITY(reg_a6)->x.sh = 0x1C00;
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    *(u16 *)(reg_a5 + 0x18) -= 1;
    if ((s32) reg_tmp.h[0] > 0) goto block_objset;
    m = *(u16 *)(reg_a5 + 0x16);
    if (m != 0) goto next_100;
    func_00170690();
    *(u16 *)(reg_a5 + 0x1A) += 8;
    if (*(u16 *)(reg_a5 + 0x1A) != 0xF0) goto block_objset;
    *(u16 *)(reg_a5 + 0x16) = 1;
    goto block_objset;
next_100:
    if ((m & 0xFFFF) != 1) goto next_200;
    func_00170690();
    *(u16 *)(reg_a5 + 0x1A) += 8;
    if (*(u16 *)(reg_a5 + 0x1A) != 0x128) goto block_objset;
    *(u16 *)(reg_a5 + 0x1A) = 0x100;
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
    *(u16 *)(reg_a5 + 0x1C) -= 1;
    if ((s32) reg_tmp.h[0] > 0) goto block_objset;
    *(u16 *)(reg_a5 + 0x16) = 2;
    goto block_objset;
next_200:
    func_00170690();
    *(u16 *)(reg_a5 + 0x1A) += 8;
    if (*(u16 *)(reg_a5 + 0x1A) != 0x230) goto block_objset;
    enemy_remove();
    return;
block_objset:
    func_0019D770();
    switch (D_0028E3EC) {
    case 0:
        return;
    default:
        break;
    }
    if (D_0028E3F0 & 2) {
        ENTITY(reg_a6)->y.h -= 0x40;
        func_0019D770();
        ENTITY(reg_a6)->y.h += 0x40;
        return;
    }
    ENTITY(reg_a6)->y.h += 0x40;
    func_0019D770();
    ENTITY(reg_a6)->y.h -= 0x40;
}
