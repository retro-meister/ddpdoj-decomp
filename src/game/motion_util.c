#include "common.h"
#ifdef DDPDOJ_PC
#include "pc_gameplay_abi.h"
#endif
#include "player.h"
#include "layers.h"
#include "entity.h"

extern void (*direction_octant_combines[8])();

void bullet_cancel_credit_alive(void);
void bullets_cancel_sweep(void);
void bullet_cancel_skip(void);
void velocity_from_dir(void);
#ifndef DDPDOJ_PC
void velocity_from_direction(void);
#endif
void entity_advance256_apply();
void entity_advance_scaled_apply(void);
void velocity_from_dir_scaled(void);
void direction_to_entity(void);
#ifndef DDPDOJ_PC
void direction_to_point(void);
#endif
void direction_between(void);
void entity_turn_toward(void);
void entity_dir_turned_toward(void);
void direction_turn_toward(void);
void direction256_to_entity(void);
void direction256_to_point(void);
void direction256_between(void);
void player_distance_or_max(void);
void entity_distance_to_entity(void);
void entity_distance_to(void);
#ifndef DDPDOJ_PC
void distance_between(void);
#endif
void cond_flag_clear(void);
void entity_x_distance(void);
void target_player_get(void);
void player_pair_pick_alive(void);
void stage_clear_task_start(void);
void enemies_remove_all_entry(void);
void heli_x_limit_apply(void);
void heli_x_limit_far(void);


s32 bullet_cancel_hyper_active();
extern u32 reg_save_d7;
extern u32 reg_save_d6;
extern u32 reg_save_d5;
extern u32 reg_save_d4;
extern u32 reg_save_d3;
extern u32 reg_save_d2;
extern u32 reg_save_d1;
extern u32 reg_save_d0;
extern u8 *reg_save_a6;
extern u8 *reg_save_a5;
extern s32 reg_save_a4;
extern s32 reg_save_a3;
extern u8 *reg_save_a2;
extern u8 *reg_save_a1;
extern s32 reg_save_a0;
extern u8 g_boss_present_b1;
extern u16 g_bullet_cancel[];
extern u16 g_bullet_cancel_kind[];

void bullet_cancel_with_flags(void) {
    bullet_cancel_hyper_active();
    if (cond_flag == 0) {
        g_bullet_cancel[0] = 1;
        g_bullet_cancel_kind[0] = 0xFFFF;
        if (g_boss_present_b1 & 2) {
            bullet_cancel_skip();
            return;
        }
        reg_save_d0 = reg_d0.w;
        reg_save_d1 = reg_d1.w;
        reg_save_d2 = reg_d2.w;
        reg_save_d3 = reg_d3.w;
        reg_save_d4 = reg_d4.w;
        reg_save_d5 = reg_d5.w;
        reg_save_d6 = reg_d6.w;
        reg_save_d7 = reg_d7.w;
        (*(u8 **)&reg_save_a0) = reg_a0;
        reg_save_a1 = reg_a1;
        reg_save_a2 = reg_a2;
        (*(u8 **)&reg_save_a3) = reg_a3;
        (*(u8 **)&reg_save_a4) = reg_a4;
        reg_save_a5 = reg_a5;
        reg_save_a6 = reg_a6;
        reg_d1.h[0] |= 0x8000;
        bullets_cancel_sweep();
    }
}


void bullet_cancel_with_flags_plain(void) {
    bullet_cancel_hyper_active();
    if (cond_flag == 0) {
        ((s16 *)g_bullet_cancel_kind)[0] = 0;
        ((s16 *)g_bullet_cancel)[0] = 1;
        if (g_boss_present_b1 & 2) {
            bullet_cancel_skip();
            return;
        }
        reg_save_d0 = reg_d0.w;
        reg_save_d1 = reg_d1.w;
        reg_save_d2 = reg_d2.w;
        reg_save_d3 = reg_d3.w;
        reg_save_d4 = reg_d4.w;
        reg_save_d5 = reg_d5.w;
        reg_save_d6 = reg_d6.w;
        reg_save_d7 = reg_d7.w;
        (*(u8 **)&reg_save_a0) = reg_a0;
        reg_save_a1 = reg_a1;
        reg_save_a2 = reg_a2;
        (*(u8 **)&reg_save_a3) = reg_a3;
        (*(u8 **)&reg_save_a4) = reg_a4;
        reg_save_a5 = reg_a5;
        reg_save_a6 = reg_a6;
        reg_d1.h[0] |= 0x8000;
        bullets_cancel_sweep();
    }
}


void bullet_cancel_credit_players(void) {
    if (!(g_boss_present_b1 & 2)) {
        bullet_cancel_credit_alive();
        return;
    }
    bullet_cancel_skip();
}

extern s16 g_player2[];
extern s16 g_player1[];

void bullet_cancel_credit_alive(void) {
    reg_save_d0 = reg_d0.w;
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    (*(u8 **)&reg_save_a0) = reg_a0;
    reg_save_a1 = reg_a1;
    reg_save_a2 = reg_a2;
    (*(u8 **)&reg_save_a3) = reg_a3;
    (*(u8 **)&reg_save_a4) = reg_a4;
    reg_save_a5 = reg_a5;
    reg_save_a6 = reg_a6;
    reg_d1.h[0] = 0x8000;
    if ((g_player1[0] < 0) && !(PLAYER(g_player1)->flags.b[1] & 1)) {
        reg_d1.h[0] |= 0x10;
    }
    if ((g_player2[0] < 0) && !(PLAYER(g_player2)->flags.b[1] & 1)) {
        reg_d1.h[0] |= 8;
    }
    bullets_cancel_sweep();
}

s32 score_add_p1();
s32 score_add_p2();
extern s32 reg_save_a4;
extern s32 reg_save_a3;
extern s32 reg_save_a0;
extern u8 g_bullets[67216];

void bullets_cancel_sweep(void) {
    u16 *var_a0;
    var_a0 = (u16 *)(((u16 *)g_bullets));
    reg_d2.w = 0;
    reg_a2 = (u8 *)(((u16 *)g_bullets));
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
    do {
        reg_d0.h[0] = *(u16 *)reg_a2;
        if ((s16) reg_d0.h[0] < 0) {
            if (reg_d1.h[0] & 0x10) {
                reg_d0.w = 0x23;
                score_add_p1();
            }
            if (reg_d1.h[0] & 8) {
                reg_d0.w = 0x23;
                score_add_p2();
            }
        }
        var_a0 = (u16 *)(reg_a2 + 0x40);
        reg_a2 = (u8 *)(var_a0);
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = reg_save_d0;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    reg_a0 = (u8 *)reg_save_a0;
    reg_a1 = (u8 *)(*(s32 *)&reg_save_a1);
    reg_a2 = (u8 *)(((u16 *)reg_save_a2));
    reg_a3 = (u8 *)reg_save_a3;
    reg_a4 = (u8 *)reg_save_a4;
    reg_a5 = (u8 *)(*(s32 *)&reg_save_a5);
    reg_a6 = (u8 *)(*(s32 *)&reg_save_a6);
}

#pragma push
#pragma opt_propagation off

extern Reg32 reg_d0;
extern Reg32 reg_d1;
extern Reg32 reg_d2;
extern Reg32 reg_d3;
extern Reg32 reg_d4;
extern Reg32 reg_d5;
extern Reg32 reg_d6;
extern Reg32 reg_d7;

void bullet_cancel_skip(void) {
    u32 d5, d4, d3, d2, d1, d0, d7, d6;

    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    reg_d4.w = d4;
    reg_d5.w = d5;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d6.w = d6;
    reg_d7.w = d7;
}
#pragma pop

extern u16 g_enemies_stopped;

void entity_follow_scroll(void) {
    if (g_enemies_stopped == 0) {
        reg_d0.h[1] = g_layer_b_shift[0];
        reg_d0.h[0] = g_layer_b_shift[1];
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] = reg_d0.h[1];
        reg_d0.h[1] = reg_tmp.h[0];
        ENTITY(reg_a6)->y.h += reg_d0.h[0];
    }
}

void layer_b_shift_get(void) {
    if (g_enemies_stopped == 0) {
        reg_d2.h[0] = g_layer_b_shift[0];
        reg_d3.h[0] = g_layer_b_shift[1];
        return;
    }
    reg_d2.w = 0;
    reg_d3.w = 0;
}


void velocity_from_dir_unless_stopped(void) {
    if (g_enemies_stopped == 0) {
        velocity_from_dir();
        return;
    }
    reg_d2.w = 0;
    reg_d3.w = 0;
}


void entity_velocity(void)
{
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.w = 0x3F;
    reg_d1.b[0] &= ENTITY(reg_a6)->move.b.dir;

    if (g_enemies_stopped != 0) {
        reg_d2.w = 0;
        reg_d3.w = 0;
    } else {
        velocity_from_dir();
    }
}


void velocity_from_dir(void) {
    velocity_from_direction();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
}

extern u8 D_00262570[];
extern u8 D_00262572[];
extern u8 dir_vector_index_fine[];

void velocity_from_direction(void) {
    s32 t;

    reg_d1.h[0] *= 4;
    reg_d3.h[0] = *(s16 *)(dir_vector_index_fine + reg_d1.h[0] * 2);
    t = reg_d3.h[0] * 2;
    reg_d2.w = reg_d0.h[0] * *(u16 *)(D_00262570 + t);
    reg_d3.w = reg_d0.h[0] * *(u16 *)(D_00262572 + t);
    reg_d2.w = (s32) reg_d2.w >> 4;
    reg_d3.w = (s32) reg_d3.w >> 4;
    reg_d1.h[0] &= 0xC0;
    switch (reg_d1.h[0]) {
    case 0x0:
        break;
    case 0x40:
        reg_d2.h[0] *= 0xFFFF;
        break;
    case 0x80:
        reg_d2.h[0] *= -1;
        reg_d3.h[0] *= 0xFFFF;
        break;
    case 0xC0:
        reg_d3.h[0] *= 0xFFFF;
        break;
    }
}

extern u8 dir_vector_index[];

void velocity_from_dir256(void) {
    s32 t;

    reg_d3.h[0] = *(s16 *)(dir_vector_index + reg_d1.h[0] * 2);
    t = reg_d3.h[0] * 2;
    reg_d2.w = reg_d0.h[0] * *(u16 *)(D_00262570 + t);
    reg_d3.w = reg_d0.h[0] * *(u16 *)(D_00262572 + t);
    reg_d2.w = (s32) reg_d2.w >> 4;
    reg_d3.w = (s32) reg_d3.w >> 4;
    reg_d1.h[0] &= 0xC0;
    switch (reg_d1.h[0]) {
    case 0x0:
        break;
    case 0x40:
        reg_d2.h[0] *= 0xFFFF;
        break;
    case 0x80:
        reg_d2.h[0] *= -1;
        reg_d3.h[0] *= 0xFFFF;
        break;
    case 0xC0:
        reg_d3.h[0] *= 0xFFFF;
        break;
    }
}


void entity_advance256(void) {
#ifndef DDPDOJ_PC
    extern void entity_advance256_apply(u8, void *);
#endif
    u8 temp_a0;

    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.w = 0;
    temp_a0 = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] = temp_a0;
    if (g_enemies_stopped != 0) {
        reg_d3.w = 0;
        reg_d2.w = 0;
        return;
    }
    ARCADE_REGISTER_CALL(entity_advance256_apply, temp_a0, reg_a6);
}


void entity_advance256_apply() {
    velocity_from_dir256();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
}



void entity_advance_scaled(void) {
    u8 *base = (u8 *)((void *)reg_a6);

    reg_d0.w = 0;
    reg_d0.b[0] = base[0x1B];
    reg_d1.w = 0;
    reg_d1.b[0] = base[0x1A];
    entity_advance_scaled_apply();
}


void entity_advance_scaled_apply(void) {
    if (g_enemies_stopped == 0) {
        velocity_from_dir_scaled();
        ENTITY(reg_a6)->y.h += reg_d2.h[0];
        ENTITY(reg_a6)->x.h += reg_d3.h[0];
        return;
    }
    reg_d2.w = 0;
    reg_d3.w = 0;
}

void velocity_from_dir_scaled(void) {
    s32 t;

    reg_d3.h[0] = *(s16 *)(dir_vector_index + reg_d1.h[0] * 2);
    t = reg_d3.h[0] * 2;
    reg_d2.w = reg_d0.h[0] * *(u16 *)(D_00262570 + t);
    reg_d3.w = reg_d0.h[0] * *(u16 *)(D_00262572 + t);
    reg_d2.w = (s32) reg_d2.w >> reg_d4.w;
    reg_d3.w = (s32) reg_d3.w >> reg_d4.w;
    reg_d1.h[0] &= 0xC0;
    switch (reg_d1.h[0]) {
    case 0x0:
        break;
    case 0x40:
        reg_d2.h[0] *= 0xFFFF;
        break;
    case 0x80:
        reg_d2.h[0] *= -1;
        reg_d3.h[0] *= 0xFFFF;
        break;
    case 0xC0:
        reg_d3.h[0] *= 0xFFFF;
        break;
    }
}


void aim_at_player(void) {
    target_player_get();
    if (cond_flag == 0) {
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
        direction_between();
    }
}


void direction_to_target_player(void) {
    target_player_get();
    if (cond_flag == 0) {
        direction_to_entity();
    }
}



void direction_to_entity(void) {
    u8 *base = (u8 *)((void *)reg_a0);
    reg_d2.h[0] = *(u16 *)(base + 0x2);
    reg_d3.h[0] = *(u16 *)(base + 0x4);
    direction_to_point();
}


void direction_to_point(void) {
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    direction_between();
}

#pragma push
#pragma divbyzerocheck on
typedef void (*Fn)();

extern u8 direction_octant_bases[];
extern u8 direction_ratio_angles[];

void direction_between(void) {
    reg_d4.h[0] = 0x1800;
    reg_d0.h[0] += reg_d4.h[0];
    reg_d1.h[0] += reg_d4.h[0];
    reg_d2.h[0] += reg_d4.h[0];
    reg_d3.h[0] += reg_d4.h[0];
    reg_d4.w = 8;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] -= reg_d3.h[0];
    if ((s32) reg_tmp1.h[0] < (s32) reg_d3.h[0]) {
        reg_d4.w = 0;
        reg_d1.h[0] *= 0xFFFF;
    }
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s32) reg_tmp.h[0] < (s32) reg_d2.h[0]) {
        reg_d0.h[0] *= 0xFFFF;
        reg_d4.h[0] += 4;
    }
    reg_d2.h[0] = reg_d1.h[0];
    reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 1);
    reg_d1.h[0] += reg_d2.h[0];
    if (!((s32) reg_d0.h[0] > (s32) reg_d1.h[0])) goto next_1;
    reg_d4.h[0] += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.w = reg_d1.w;
    reg_d1.w = reg_tmp.w;
next_1:
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = 0;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    if (reg_d1.h[0] == 0) goto block_rts;
    reg_d0.w <<= 6;
    reg_d2.h[0] = reg_d0.w % reg_d1.h[0];
    reg_d0.w = reg_d0.w / (u32) (u16) reg_d1.h[0];
    reg_d2.h[0] *= 2;
    reg_d0.h[0] *= 2;
    if (!((s32) reg_d1.h[0] < (s32) reg_d2.h[0])) goto next_2;
    reg_d0.h[0] += 1;
next_2:
    reg_d0.b[0] = *(s8 *)(direction_ratio_angles + reg_d0.h[0]);
    reg_d1.h[0] = *(s16 *)(direction_octant_bases + (reg_d4.h[0] & ~1));
    ((Fn)*(u32 *)((u8 *)((u8 *)direction_octant_combines) + (((s32) reg_d4.h[0] >> 1) * 4)))();
block_rts:
    return;
}
#pragma pop

void direction_octant_subtract(void) {
    reg_d1.h[0] -= reg_d0.h[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] >>= 3;
    reg_d1.h[0] &= 0x3F;
}

void direction_octant_add(void) {
    reg_d1.h[0] += reg_d0.h[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] >>= 3;
    reg_d1.h[0] &= 0x3F;
}


void entity_turn_to_target_player(void) {
    direction_to_target_player();
    if (cond_flag == 0) {
        entity_turn_toward();
    }
}


void entity_turn_toward(void) {
    entity_dir_turned_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
}


void entity_dir_turned_toward(void) {
    *(u8 *)&reg_d0 = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
}

void direction_turn_toward(void) {
    reg_d2.w = 0x3F;
    reg_d0.h[0] &= reg_d2.h[0];
    reg_d1.h[0] &= reg_d2.h[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] += 1;
        reg_d1.h[0] &= reg_d2.h[0];
        if ((s32) reg_d1.h[0] >= 0x20) {
            reg_d0.b[0] -= 2;
        }
        reg_d0.h[0] &= reg_d2.h[0];
    }
    reg_d1.h[0] = reg_d0.h[0];
}

void direction_step_toward(void) {
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] += 1;
        if ((s32) reg_d1.b[0] >= 0x80) {
            reg_d0.b[0] -= 2;
        }
    }
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) reg_d1.b[0];
}

void direction_steps_toward(void) {
    u32 tmp;

    reg_d0.h[0] = reg_d0.b[0];
    reg_d1.h[0] = reg_d1.b[0];
    reg_d2.h[0] = reg_d1.h[0];
    reg_d5.h[0] -= 1;
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] == 0) goto block_5;
    if (reg_d1.b[0] < 0x80) goto next_2;
    goto next_4;
loop_1:
    reg_d1.h[0] = reg_d2.h[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] == 0) goto block_5;
next_2:
    reg_d0.b[0] += 1;
    tmp = reg_d5.h[0] - 1;
    reg_d5.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d1.h[0] = reg_d0.h[0];
    return;
loop_3:
    reg_d1.h[0] = reg_d2.h[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] == 0) goto block_5;
next_4:
    reg_d0.b[0] -= 1;
    tmp = reg_d5.h[0] - 1;
    reg_d5.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_3;
block_5:
    reg_d1.h[0] = reg_d0.h[0];
}


void aim256_at_player(void) {
    target_player_get();
    if (cond_flag == 0) {
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
        direction256_between();
    }
}


void direction256_to_target_player(void) {
    target_player_get();
    if (cond_flag == 0) {
        direction256_to_entity();
    }
}



void direction256_to_entity(void) {
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    direction256_to_point();
}


void direction256_to_point(void) {
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    direction256_between();
}

#pragma push
#pragma divbyzerocheck on
extern u8 direction256_octant_bases[];
extern u8 direction256_ratio_angles[];

void direction256_between(void) {
    reg_d4.h[0] = 0x1800;
    reg_d0.h[0] += reg_d4.h[0];
    reg_d1.h[0] += reg_d4.h[0];
    reg_d2.h[0] += reg_d4.h[0];
    reg_d3.h[0] += reg_d4.h[0];
    reg_d4.w = 8;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] -= reg_d3.h[0];
    if ((s32) reg_tmp1.h[0] < (s32) reg_d3.h[0]) {
        reg_d4.w = 0;
        reg_d1.h[0] *= 0xFFFF;
    }
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s32) reg_tmp.h[0] < (s32) reg_d2.h[0]) {
        reg_d0.h[0] *= 0xFFFF;
        reg_d4.h[0] += 4;
    }
    reg_d2.h[0] = reg_d1.h[0];
    reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 1);
    reg_d1.h[0] += reg_d2.h[0];
    if (!((s32) reg_d0.h[0] > (s32) reg_d1.h[0])) goto next_1;
    reg_d4.h[0] += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.w = reg_d1.w;
    reg_d1.w = reg_tmp.w;
next_1:
    reg_d0.h[1] = 0;
    if (reg_d1.h[0] == 0) goto block_rts;
    reg_d0.w <<= 5;
    reg_d2.h[0] = reg_d0.w % reg_d1.h[0];
    reg_d0.w = reg_d0.w / (u32) (u16) reg_d1.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] *= 2;
    if (!((s32) reg_d2.h[0] > (s32) reg_d1.h[0])) goto next_2;
    reg_d0.h[0] += 1;
next_2:
    reg_d0.b[0] = *(s8 *)(direction256_ratio_angles + reg_d0.h[0]);
    reg_d1.h[0] = *(s16 *)(direction256_octant_bases + (reg_d4.h[0] & ~1));
    switch ((s32) reg_d4.h[0] >> 1) {
    case 0:
        reg_d1.h[0] += reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 1:
        reg_d1.h[0] -= reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 2:
        reg_d1.h[0] -= reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 3:
        reg_d1.h[0] += reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 4:
        reg_d1.h[0] -= reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 5:
        reg_d1.h[0] += reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 6:
        reg_d1.h[0] += reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 7:
        reg_d1.h[0] -= reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    }
block_rts:
    return;
}
#pragma pop



void nearest_player_distance(void)
{
    s16 firstResult;

    reg_a0 = ((u8 *)g_player1);
    player_distance_or_max();
    firstResult = (s16)reg_d0.h[0];

    reg_a0 = ((u8 *)g_player2);
    player_distance_or_max();
    reg_d1.h[0] = (u16)firstResult;

    if (reg_d0.h[0] > reg_d1.h[0]) {
        reg_d0.h[0] = reg_d1.h[0];
    }
}


void player_distance_or_max(void) {
    reg_d0.h[0] = 0x7FFF;
    if (*(s16 *)reg_a0 >= 0) {
        cond_flag_clear();
        return;
    }
    entity_distance_to_entity();
}


void entity_distance_to_entity(void) {
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
    entity_distance_to();
}


void entity_distance_to(void) {
    reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    distance_between();
}

void distance_between(void) {
    u32 temp_a0;
    u32 temp_a1;

    reg_d0.h[0] -= reg_d2.h[0];
    if ((s16)(reg_d0.h[0]) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    temp_a1 = reg_d0.h[0];
    reg_d4.h[0] = temp_a1;
    reg_d4.h[0] >>= 2;
    reg_d1.h[0] -= reg_d3.h[0];
    temp_a0 = temp_a1 - reg_d4.h[0];
    reg_d0.h[0] = temp_a0;
    if ((s16)(reg_d1.h[0]) < 0) {
        reg_d1.h[0] *= 0xFFFF;
    }
    if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
        reg_tmp.w = reg_d0.w;
        reg_d0.w = reg_d1.w;
        reg_d1.w = reg_tmp.w;
    }
    reg_d1.h[0] >>= 1;
    reg_d0.h[0] += reg_d1.h[0];
    cond_flag_clear();
}


void cond_flag_clear(void) {
    (*(u8 *)&cond_flag) = 0;
}


void nearest_player_by_x(void) {
    s16 *temp_s0;

    reg_d0.h[0] = 0x7FFF;
    reg_a0 = (u8 *)(g_player1);
    reg_d1.h[0] = reg_d0.h[0];
    if (*(s16 *)reg_a0 < 0) {
        entity_x_distance();
    }
    temp_s0 = (s16 *)(reg_a0);
    reg_a0 = (u8 *)(g_player2);
    if (*(s16 *)reg_a0 < 0) {
        reg_d1.h[0] = reg_d0.h[0];
        entity_x_distance();
        reg_a1 = (u8 *)(reg_a0);
    }
    reg_a0 = (u8 *)(temp_s0);
    if ((s32) reg_d0.h[0] > (s32) reg_d1.h[0]) {
        reg_d0.h[0] = reg_d1.h[0];
        reg_a0 = (u8 *)(reg_a1);
    }
}

void entity_x_distance(void) {
    reg_d2.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] -= reg_d2.h[0];
    if (((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    cond_flag = 0;
}

extern u8 shot_limits_y[];
extern u8 shot_limits_x[];
extern u8 shot_limits_y_second_loop[];
extern u8 shot_limits_x_second_loop[];
extern u16 g_loop;
extern u16 g_stage_x4;


void entity_in_shot_limits(void) {
    u8 *save_a0;
    u32 save_d0;
    u32 save_d1;

    save_d1 = reg_d1.w;
    save_d0 = reg_d0.w;
    save_a0 = reg_a0;
    reg_d0.h[0] = g_stage_x4;
    reg_a0 = (u8 *)shot_limits_y;
    if (g_loop == 0) goto next_1;
    reg_a0 = (u8 *)shot_limits_y_second_loop;
next_1:
    reg_d0.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d0.h[0] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.w = 0;
    reg_tmp1.w = 0;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp.h[0] = reg_d0.h[1];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_tmp1.w += reg_tmp.w;
    reg_d1.h[0] += reg_d0.h[1];
    if (reg_tmp1.h[1] != 0) goto next_3;
    reg_d0.h[0] = g_stage_x4;
    reg_a0 = (u8 *)shot_limits_x;
    if (g_loop == 0) goto next_2;
    reg_a0 = (u8 *)shot_limits_x_second_loop;
next_2:
    reg_d0.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d0.h[0] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp.w = 0;
    reg_tmp1.w = 0;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp.h[0] = reg_d0.h[1];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_tmp1.w += reg_tmp.w;
    reg_d1.h[0] += reg_d0.h[1];
next_3:
    cond_flag = 0;
    if (reg_tmp1.h[1] != 0) {
        cond_flag = 1;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_a0 = save_a0;
}

void entity_in_shot_limits_y(void) {
    u8 *save_a0;
    u32 save_d0;
    u32 save_d1;

    save_d1 = reg_d1.w;
    save_d0 = reg_d0.w;
    save_a0 = reg_a0;
    reg_d0.h[0] = g_stage_x4;
    reg_a0 = (u8 *)shot_limits_y;
    reg_d0.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d0.h[0] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.w = 0;
    reg_tmp1.w = 0;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp.h[0] = reg_d0.h[1];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_tmp1.w += reg_tmp.w;
    reg_d1.h[0] += reg_d0.h[1];
    cond_flag = 0;
    if (reg_tmp1.h[1] != 0) {
        cond_flag = 1;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_a0 = save_a0;
}

extern u16 g_side_scroll_x[];


void entity_check_bounds(void) {
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x9000;
    reg_tmp1.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += (s16) g_side_scroll_x[0];
    reg_tmp1.h[0] = reg_d0.h[0];
    reg_tmp1.w += reg_tmp.w;
    if (reg_tmp1.h[1] == 0) {
        reg_tmp.w = 0;
        reg_tmp.h[0] = 0x8000;
        reg_tmp1.w = 0;
        reg_d0.h[1] += 0x800;
        reg_tmp1.h[0] = reg_d0.h[1];
        reg_tmp1.w += reg_tmp.w;
    }
    cond_flag = 0;
    if (reg_tmp1.h[1] != 0) {
        cond_flag = 1;
    }
}

void entity_bounds_check_wide(void) {
    reg_d0.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d0.h[0] = *(u16 *) (reg_a6 + 4);
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x9000;
    reg_tmp1.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += (s16) g_side_scroll_x[0];
    reg_tmp1.h[0] = reg_d0.h[0];
    reg_tmp1.w += reg_tmp.w;
    if (reg_tmp1.h[1] != 0) goto next_1;
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x7000;
    reg_tmp1.w = 0;
    reg_d0.h[1] += 0x1000;
    reg_tmp1.h[0] = reg_d0.h[1];
    reg_tmp1.w += reg_tmp.w;
next_1:
    cond_flag = 0;
    if (reg_tmp1.h[1] == 0) return;
    cond_flag = 1;
}

void entity_bounds_check_narrow(void) {
    reg_d0.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d0.h[0] = *(u16 *) (reg_a6 + 4);
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0xB000;
    reg_tmp1.w = 0;
    reg_d0.h[0] += 0xC00;
    reg_d0.h[0] += (s16) g_side_scroll_x[0];
    reg_tmp1.h[0] = reg_d0.h[0];
    reg_tmp1.w += reg_tmp.w;
    if (reg_tmp1.h[1] != 0) goto next_1;
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x8400;
    reg_tmp1.w = 0;
    reg_d0.h[1] += 0x600;
    reg_tmp1.h[0] = reg_d0.h[1];
    reg_tmp1.w += reg_tmp.w;
next_1:
    cond_flag = 0;
    if (reg_tmp1.h[1] == 0) return;
    cond_flag = 1;
}


extern s16 *reg_save_atmp;

void target_player_get(void)
{
    reg_a0 = (u8 *)((u32)((u8 *)g_player1));
    cond_flag = 0;
    reg_a1 = (u8 *)((u32)((u8 *)g_player2));

    if (((u8 *)((u32)reg_a5))[2] != 0) {
        (*(u32 *)&reg_save_atmp) = (u32)reg_a1;
        reg_a1 = (u8 *)(((u32)reg_a0));
        reg_a0 = (u8 *)(*(u32 *)&reg_save_atmp);
    }

    player_pair_pick_alive();
}


void player_pair_pick_alive(void) {
    s16 *temp_a0;

    temp_a0 = (s16 *)reg_a0;
    if (*temp_a0 >= 0) {
        if (*(s16 *)reg_a1 >= 0) {
            cond_flag = 1;
            return;
        }
        reg_a0 = (u8 *)(((s16 *)reg_a1));
        reg_atmp = (u8 *)temp_a0;
        reg_a1 = (u8 *)temp_a0;
        goto block_4;
    }
block_4:
    cond_flag = 0;
}


void bullet_target_player_get(void) {
    reg_a0 = (u8 *)((s32 *)g_player1);
    reg_a1 = (u8 *)((s32 *)g_player2);
    if (*(u8 *)(reg_a6 + 0x2B) != 0) {
        (*(s32 **)&reg_save_atmp) = (s32 *)reg_a1;
        reg_a1 = (u8 *)(((s32 *)reg_a0));
        reg_a0 = (u8 *)((s32 *)reg_save_atmp);
    }
    player_pair_pick_alive();
}

void players_alive_mask(void) {
    reg_d1.b[0] = PLAYER(g_player1)->flags.b[1];
    reg_d0.w = 0;
    if (((s8) reg_d1.b[0] < 0) && !(reg_d1.h[0] & (1 << reg_d0.h[0]))) {
        reg_d0.w = 1;
    }
    reg_d1.b[0] = PLAYER(g_player2)->flags.b[1];
    if (((s8) reg_d1.b[0] < 0) && !(reg_d1.h[0] & 1)) {
        reg_d0.h[0] += 2;
    }
}

void active_players_mask(void) {
    reg_d0.w = 0;
    if ((g_player1[0] < 0) && !(PLAYER(g_player1)->flags.b[1] & 1)) {
        reg_d0.w = 0x10;
    }
    if ((g_player2[0] < 0) && !(PLAYER(g_player2)->flags.b[1] & 1)) {
        reg_d0.h[0] += 8;
    }
}

s32 music_stop();
extern u16 g_player_shots_disabled;
void boss_defeat_begin(void) {
    music_stop();
    g_player_shots_disabled = 1;
    if (g_player1[0] < 0) {
        PLAYER(((u8 *)g_player1))->state.b.invincible = 0xFF;
    }
    if (g_player2[0] < 0) {
        PLAYER(((u8 *)g_player2))->state.b.invincible = 0xFF;
    }
}

s32 music_play_bgm10();
s32 slowdown_reset();
extern u16 g_players_stage_clear;
void stage_clear_begin(void) {
    slowdown_reset();
    music_play_bgm10();
    g_players_stage_clear = 1;
    g_boss_present_b1 |= 8;
    g_boss_present_b1 &= 0xEF;
    if (*(s16 *)g_player1 < 0) goto block_1;
    if (!(PLAYER(g_player1)->flags.b[1] & 1)) goto next_1;
    if (*(u8 *)g_player1 & 0x80) goto next_1;
block_1:
    PLAYER(g_player1)->flags.b[1] |= 0x20;
next_1:
    if (*(s16 *)g_player2 < 0) goto block_2;
    if (!(PLAYER(g_player2)->flags.b[1] & 1)) goto next_2;
    if (*(u8 *)g_player2 & 0x80) goto next_2;
block_2:
    PLAYER(g_player2)->flags.b[1] |= 0x20;
next_2:
    return;
}

extern u16 g_stage;

void stage_clear_to_next_stage(void) {
    stage_clear_begin();
    reg_d7.h[0] = g_stage;
    reg_d7.h[0] += 1;
    if ((s32) reg_d7.h[0] >= 5) {
        reg_d7.w = 0;
    }
    stage_clear_task_start();
}

s32 pickups_clear();                            /* extern */

void stage_clear_from_menu(void) {
    enemies_remove_all_entry();
    pickups_clear();
    stage_clear_begin();
    stage_clear_task_start();
}

s32 task_start();                            /* extern */

void stage_clear_task_start(void) {
    reg_d0.h[0] = 6;
    task_start();
    *(u16 *)(reg_a0 + 4) = (u16) reg_d7.h[0];
}

void enemies_remove_all(void);

void enemies_remove_all_entry(void) {
    enemies_remove_all();
}

s32 input_get_p2_held();
extern s8 g_stick_directions[];

void entity_move_by_p2_stick(void) {
    input_get_p2_held();
    reg_d0.h[0] &= 0xF;
    ENTITY(reg_a6)->move.sb.dir = g_stick_directions[reg_d0.h[0]];
    if (ENTITY(reg_a6)->move.sb.dir >= 0) {
        entity_velocity();
        return;
    }
    ENTITY(reg_a6)->move.sb.dir = 0x40;
    reg_d2.w = 0;
    reg_d3.h[0] = reg_d2.h[0];
}


void heli_x_limit_check(void) {
    u16 temp_a0;

    cond_flag = 0;
    reg_a0 = ((u8 *)g_player1);
    if (*(u8 *)(reg_a5 + 2) & 1) {
        reg_a0 = ((u8 *)g_player2);
    }
    reg_d0.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d6.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= 0x1C00;
    temp_a0 = (u32)reg_d6.h[0] + 0x800;
    reg_d6.h[0] = temp_a0;
    if ((s32) reg_tmp.h[0] >= 0x1C00) {
        heli_x_limit_far();
        return;
    }
    reg_tmp.h[0] = reg_d6.h[0];
    reg_d6.h[0] -= 0x2400;
    if ((s32) reg_tmp.h[0] < 0x2400) {
        heli_x_limit_apply();
    }
}

void heli_x_limit_apply(void) {
    u32 scaled = (u32)reg_d6.h[0] << 16;
    reg_d6.h[0] = (u16)(scaled - reg_d6.h[0]);
    reg_d6.h[0] += 0x1C00;
    *(u16 *)((u8 *)((void *)reg_a6) + 4) = reg_d6.h[0];
}


void heli_x_limit_far(void) {
    Reg32 *temporaryRegister = &reg_tmp;
    Reg32 *dataRegister6 = &reg_d6;
    u32 originalD6;
    u32 adjustment;

    temporaryRegister->w = 0;
    temporaryRegister->h[0] = 0x2400;
    reg_tmp1.w = 0;
    originalD6 = dataRegister6->h[0];
    adjustment = temporaryRegister->w;
    reg_tmp1.h[0] = originalD6;
    reg_tmp1.w -= adjustment;
    dataRegister6->h[0] = originalD6 - 0x2400;

    if (reg_tmp1.h[1] != 0) {
        cond_flag = 1;
        return;
    }

    heli_x_limit_apply();
    reg_d0.w = -1;
    cond_flag = 1;
}

s8 g_stick_directions[16] = {
    0xFF, 0x00, 0x20, 0xFF, 0x30, 0x38, 0x28, 0xFF, 0x10, 0x08, 0x18, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

u8 direction256_octant_bases[16] = {
    0x40, 0x00, 0x80, 0x00, 0x40, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x80, 0x00, 0xC0, 0x00, 0x00, 0x00,
};

u8 direction256_ratio_angles[80] = {
    0x00, 0x01, 0x02, 0x02, 0x03, 0x04, 0x04, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08, 0x09, 0x09, 0x0A,
    0x0A, 0x0B, 0x0B, 0x0C, 0x0D, 0x0D, 0x0E, 0x0E, 0x0F, 0x10, 0x10, 0x11, 0x11, 0x12, 0x12, 0x13,
    0x13, 0x14, 0x14, 0x15, 0x16, 0x16, 0x16, 0x17, 0x17, 0x17, 0x18, 0x18, 0x19, 0x19, 0x1A, 0x1A,
    0x1B, 0x1B, 0x1B, 0x1C, 0x1C, 0x1C, 0x1D, 0x1D, 0x1E, 0x1E, 0x1E, 0x1E, 0x1F, 0x1F, 0x1F, 0x20,
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

void (*direction_octant_combines[8])() = {
    direction_octant_add,
    direction_octant_subtract,
    direction_octant_subtract,
    direction_octant_add,
    direction_octant_subtract,
    direction_octant_add,
    direction_octant_add,
    direction_octant_subtract,
};

u8 direction_octant_bases[16] = {
    0x80, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x01, 0x80, 0x01, 0x00, 0x00,
};

u8 direction_ratio_angles[144] = {
    0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x08, 0x09, 0x09, 0x0A, 0x0A,
    0x0B, 0x0B, 0x0C, 0x0C, 0x0D, 0x0D, 0x0E, 0x0E, 0x0F, 0x10, 0x10, 0x11, 0x12, 0x12, 0x13, 0x14,
    0x14, 0x15, 0x15, 0x16, 0x16, 0x17, 0x17, 0x18, 0x19, 0x1A, 0x1A, 0x1B, 0x1B, 0x1C, 0x1C, 0x1D,
    0x1E, 0x1F, 0x1F, 0x20, 0x20, 0x21, 0x21, 0x22, 0x22, 0x23, 0x23, 0x24, 0x24, 0x25, 0x25, 0x26,
    0x26, 0x27, 0x27, 0x28, 0x28, 0x29, 0x2A, 0x2A, 0x2B, 0x2B, 0x2C, 0x2C, 0x2C, 0x2D, 0x2D, 0x2D,
    0x2E, 0x2E, 0x2E, 0x2F, 0x2F, 0x30, 0x30, 0x31, 0x31, 0x32, 0x32, 0x33, 0x33, 0x34, 0x34, 0x35,
    0x35, 0x36, 0x36, 0x36, 0x37, 0x37, 0x37, 0x38, 0x38, 0x38, 0x39, 0x39, 0x39, 0x3A, 0x3A, 0x3A,
    0x3B, 0x3B, 0x3B, 0x3C, 0x3C, 0x3C, 0x3D, 0x3D, 0x3D, 0x3E, 0x3E, 0x3E, 0x3F, 0x3F, 0x3F, 0x40,
    0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 dir_vector_index_fine[1152] = {
    0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x06, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x0C, 0x00, 0x0E, 0x00,
    0x10, 0x00, 0x12, 0x00, 0x14, 0x00, 0x16, 0x00, 0x18, 0x00, 0x1A, 0x00, 0x1C, 0x00, 0x1E, 0x00,
    0x20, 0x00, 0x22, 0x00, 0x24, 0x00, 0x26, 0x00, 0x28, 0x00, 0x2A, 0x00, 0x2C, 0x00, 0x2E, 0x00,
    0x30, 0x00, 0x32, 0x00, 0x34, 0x00, 0x36, 0x00, 0x38, 0x00, 0x3A, 0x00, 0x3C, 0x00, 0x3E, 0x00,
    0x40, 0x00, 0x42, 0x00, 0x44, 0x00, 0x46, 0x00, 0x48, 0x00, 0x4A, 0x00, 0x4C, 0x00, 0x4E, 0x00,
    0x50, 0x00, 0x52, 0x00, 0x54, 0x00, 0x56, 0x00, 0x58, 0x00, 0x5A, 0x00, 0x5C, 0x00, 0x5E, 0x00,
    0x60, 0x00, 0x62, 0x00, 0x64, 0x00, 0x66, 0x00, 0x68, 0x00, 0x6A, 0x00, 0x6C, 0x00, 0x6E, 0x00,
    0x70, 0x00, 0x72, 0x00, 0x74, 0x00, 0x76, 0x00, 0x78, 0x00, 0x7A, 0x00, 0x7C, 0x00, 0x7E, 0x00,
    0x80, 0x00, 0x7E, 0x00, 0x7C, 0x00, 0x7A, 0x00, 0x78, 0x00, 0x76, 0x00, 0x74, 0x00, 0x72, 0x00,
    0x70, 0x00, 0x6E, 0x00, 0x6C, 0x00, 0x6A, 0x00, 0x68, 0x00, 0x66, 0x00, 0x64, 0x00, 0x62, 0x00,
    0x60, 0x00, 0x5E, 0x00, 0x5C, 0x00, 0x5A, 0x00, 0x58, 0x00, 0x56, 0x00, 0x54, 0x00, 0x52, 0x00,
    0x50, 0x00, 0x4E, 0x00, 0x4C, 0x00, 0x4A, 0x00, 0x48, 0x00, 0x46, 0x00, 0x44, 0x00, 0x42, 0x00,
    0x40, 0x00, 0x3E, 0x00, 0x3C, 0x00, 0x3A, 0x00, 0x38, 0x00, 0x36, 0x00, 0x34, 0x00, 0x32, 0x00,
    0x30, 0x00, 0x2E, 0x00, 0x2C, 0x00, 0x2A, 0x00, 0x28, 0x00, 0x26, 0x00, 0x24, 0x00, 0x22, 0x00,
    0x20, 0x00, 0x1E, 0x00, 0x1C, 0x00, 0x1A, 0x00, 0x18, 0x00, 0x16, 0x00, 0x14, 0x00, 0x12, 0x00,
    0x10, 0x00, 0x0E, 0x00, 0x0C, 0x00, 0x0A, 0x00, 0x08, 0x00, 0x06, 0x00, 0x04, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x06, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x0C, 0x00, 0x0E, 0x00,
    0x10, 0x00, 0x12, 0x00, 0x14, 0x00, 0x16, 0x00, 0x18, 0x00, 0x1A, 0x00, 0x1C, 0x00, 0x1E, 0x00,
    0x20, 0x00, 0x22, 0x00, 0x24, 0x00, 0x26, 0x00, 0x28, 0x00, 0x2A, 0x00, 0x2C, 0x00, 0x2E, 0x00,
    0x30, 0x00, 0x32, 0x00, 0x34, 0x00, 0x36, 0x00, 0x38, 0x00, 0x3A, 0x00, 0x3C, 0x00, 0x3E, 0x00,
    0x40, 0x00, 0x42, 0x00, 0x44, 0x00, 0x46, 0x00, 0x48, 0x00, 0x4A, 0x00, 0x4C, 0x00, 0x4E, 0x00,
    0x50, 0x00, 0x52, 0x00, 0x54, 0x00, 0x56, 0x00, 0x58, 0x00, 0x5A, 0x00, 0x5C, 0x00, 0x5E, 0x00,
    0x60, 0x00, 0x62, 0x00, 0x64, 0x00, 0x66, 0x00, 0x68, 0x00, 0x6A, 0x00, 0x6C, 0x00, 0x6E, 0x00,
    0x70, 0x00, 0x72, 0x00, 0x74, 0x00, 0x76, 0x00, 0x78, 0x00, 0x7A, 0x00, 0x7C, 0x00, 0x7E, 0x00,
    0x80, 0x00, 0x7E, 0x00, 0x7C, 0x00, 0x7A, 0x00, 0x78, 0x00, 0x76, 0x00, 0x74, 0x00, 0x72, 0x00,
    0x70, 0x00, 0x6E, 0x00, 0x6C, 0x00, 0x6A, 0x00, 0x68, 0x00, 0x66, 0x00, 0x64, 0x00, 0x62, 0x00,
    0x60, 0x00, 0x5E, 0x00, 0x5C, 0x00, 0x5A, 0x00, 0x58, 0x00, 0x56, 0x00, 0x54, 0x00, 0x52, 0x00,
    0x50, 0x00, 0x4E, 0x00, 0x4C, 0x00, 0x4A, 0x00, 0x48, 0x00, 0x46, 0x00, 0x44, 0x00, 0x42, 0x00,
    0x40, 0x00, 0x3E, 0x00, 0x3C, 0x00, 0x3A, 0x00, 0x38, 0x00, 0x36, 0x00, 0x34, 0x00, 0x32, 0x00,
    0x30, 0x00, 0x2E, 0x00, 0x2C, 0x00, 0x2A, 0x00, 0x28, 0x00, 0x26, 0x00, 0x24, 0x00, 0x22, 0x00,
    0x20, 0x00, 0x1E, 0x00, 0x1C, 0x00, 0x1A, 0x00, 0x18, 0x00, 0x16, 0x00, 0x14, 0x00, 0x12, 0x00,
    0x10, 0x00, 0x0E, 0x00, 0x0C, 0x00, 0x0A, 0x00, 0x08, 0x00, 0x06, 0x00, 0x04, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x06, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x0C, 0x00, 0x0E, 0x00,
    0x10, 0x00, 0x12, 0x00, 0x14, 0x00, 0x16, 0x00, 0x18, 0x00, 0x1A, 0x00, 0x1C, 0x00, 0x1E, 0x00,
    0x20, 0x00, 0x22, 0x00, 0x24, 0x00, 0x26, 0x00, 0x28, 0x00, 0x2A, 0x00, 0x2C, 0x00, 0x2E, 0x00,
    0x30, 0x00, 0x32, 0x00, 0x34, 0x00, 0x36, 0x00, 0x38, 0x00, 0x3A, 0x00, 0x3C, 0x00, 0x3E, 0x00,
    0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x06, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x0C, 0x00, 0x0E, 0x00,
    0x10, 0x00, 0x12, 0x00, 0x14, 0x00, 0x16, 0x00, 0x18, 0x00, 0x1A, 0x00, 0x1C, 0x00, 0x1E, 0x00,
    0x20, 0x00, 0x22, 0x00, 0x24, 0x00, 0x26, 0x00, 0x28, 0x00, 0x2A, 0x00, 0x2C, 0x00, 0x2E, 0x00,
    0x30, 0x00, 0x32, 0x00, 0x34, 0x00, 0x36, 0x00, 0x38, 0x00, 0x3A, 0x00, 0x3C, 0x00, 0x3E, 0x00,
    0x40, 0x00, 0x42, 0x00, 0x44, 0x00, 0x46, 0x00, 0x48, 0x00, 0x4A, 0x00, 0x4C, 0x00, 0x4E, 0x00,
    0x50, 0x00, 0x52, 0x00, 0x54, 0x00, 0x56, 0x00, 0x58, 0x00, 0x5A, 0x00, 0x5C, 0x00, 0x5E, 0x00,
    0x60, 0x00, 0x62, 0x00, 0x64, 0x00, 0x66, 0x00, 0x68, 0x00, 0x6A, 0x00, 0x6C, 0x00, 0x6E, 0x00,
    0x70, 0x00, 0x72, 0x00, 0x74, 0x00, 0x76, 0x00, 0x78, 0x00, 0x7A, 0x00, 0x7C, 0x00, 0x7E, 0x00,
    0x80, 0x00, 0x7E, 0x00, 0x7C, 0x00, 0x7A, 0x00, 0x78, 0x00, 0x76, 0x00, 0x74, 0x00, 0x72, 0x00,
    0x70, 0x00, 0x6E, 0x00, 0x6C, 0x00, 0x6A, 0x00, 0x68, 0x00, 0x66, 0x00, 0x64, 0x00, 0x62, 0x00,
    0x60, 0x00, 0x5E, 0x00, 0x5C, 0x00, 0x5A, 0x00, 0x58, 0x00, 0x56, 0x00, 0x54, 0x00, 0x52, 0x00,
    0x50, 0x00, 0x4E, 0x00, 0x4C, 0x00, 0x4A, 0x00, 0x48, 0x00, 0x46, 0x00, 0x44, 0x00, 0x42, 0x00,
    0x40, 0x00, 0x3E, 0x00, 0x3C, 0x00, 0x3A, 0x00, 0x38, 0x00, 0x36, 0x00, 0x34, 0x00, 0x32, 0x00,
    0x30, 0x00, 0x2E, 0x00, 0x2C, 0x00, 0x2A, 0x00, 0x28, 0x00, 0x26, 0x00, 0x24, 0x00, 0x22, 0x00,
    0x20, 0x00, 0x1E, 0x00, 0x1C, 0x00, 0x1A, 0x00, 0x18, 0x00, 0x16, 0x00, 0x14, 0x00, 0x12, 0x00,
    0x10, 0x00, 0x0E, 0x00, 0x0C, 0x00, 0x0A, 0x00, 0x08, 0x00, 0x06, 0x00, 0x04, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x06, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x0C, 0x00, 0x0E, 0x00,
    0x10, 0x00, 0x12, 0x00, 0x14, 0x00, 0x16, 0x00, 0x18, 0x00, 0x1A, 0x00, 0x1C, 0x00, 0x1E, 0x00,
    0x20, 0x00, 0x22, 0x00, 0x24, 0x00, 0x26, 0x00, 0x28, 0x00, 0x2A, 0x00, 0x2C, 0x00, 0x2E, 0x00,
    0x30, 0x00, 0x32, 0x00, 0x34, 0x00, 0x36, 0x00, 0x38, 0x00, 0x3A, 0x00, 0x3C, 0x00, 0x3E, 0x00,
    0x40, 0x00, 0x42, 0x00, 0x44, 0x00, 0x46, 0x00, 0x48, 0x00, 0x4A, 0x00, 0x4C, 0x00, 0x4E, 0x00,
    0x50, 0x00, 0x52, 0x00, 0x54, 0x00, 0x56, 0x00, 0x58, 0x00, 0x5A, 0x00, 0x5C, 0x00, 0x5E, 0x00,
    0x60, 0x00, 0x62, 0x00, 0x64, 0x00, 0x66, 0x00, 0x68, 0x00, 0x6A, 0x00, 0x6C, 0x00, 0x6E, 0x00,
    0x70, 0x00, 0x72, 0x00, 0x74, 0x00, 0x76, 0x00, 0x78, 0x00, 0x7A, 0x00, 0x7C, 0x00, 0x7E, 0x00,
    0x80, 0x00, 0x7E, 0x00, 0x7C, 0x00, 0x7A, 0x00, 0x78, 0x00, 0x76, 0x00, 0x74, 0x00, 0x72, 0x00,
    0x70, 0x00, 0x6E, 0x00, 0x6C, 0x00, 0x6A, 0x00, 0x68, 0x00, 0x66, 0x00, 0x64, 0x00, 0x62, 0x00,
    0x60, 0x00, 0x5E, 0x00, 0x5C, 0x00, 0x5A, 0x00, 0x58, 0x00, 0x56, 0x00, 0x54, 0x00, 0x52, 0x00,
    0x50, 0x00, 0x4E, 0x00, 0x4C, 0x00, 0x4A, 0x00, 0x48, 0x00, 0x46, 0x00, 0x44, 0x00, 0x42, 0x00,
    0x40, 0x00, 0x3E, 0x00, 0x3C, 0x00, 0x3A, 0x00, 0x38, 0x00, 0x36, 0x00, 0x34, 0x00, 0x32, 0x00,
    0x30, 0x00, 0x2E, 0x00, 0x2C, 0x00, 0x2A, 0x00, 0x28, 0x00, 0x26, 0x00, 0x24, 0x00, 0x22, 0x00,
    0x20, 0x00, 0x1E, 0x00, 0x1C, 0x00, 0x1A, 0x00, 0x18, 0x00, 0x16, 0x00, 0x14, 0x00, 0x12, 0x00,
    0x10, 0x00, 0x0E, 0x00, 0x0C, 0x00, 0x0A, 0x00, 0x08, 0x00, 0x06, 0x00, 0x04, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x06, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x0C, 0x00, 0x0E, 0x00,
    0x10, 0x00, 0x12, 0x00, 0x14, 0x00, 0x16, 0x00, 0x18, 0x00, 0x1A, 0x00, 0x1C, 0x00, 0x1E, 0x00,
    0x20, 0x00, 0x22, 0x00, 0x24, 0x00, 0x26, 0x00, 0x28, 0x00, 0x2A, 0x00, 0x2C, 0x00, 0x2E, 0x00,
    0x30, 0x00, 0x32, 0x00, 0x34, 0x00, 0x36, 0x00, 0x38, 0x00, 0x3A, 0x00, 0x3C, 0x00, 0x3E, 0x00,
};

u8 dir_vector_index[576] = {
    0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x06, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x0C, 0x00, 0x0E, 0x00,
    0x10, 0x00, 0x12, 0x00, 0x14, 0x00, 0x16, 0x00, 0x18, 0x00, 0x1A, 0x00, 0x1C, 0x00, 0x1E, 0x00,
    0x20, 0x00, 0x22, 0x00, 0x24, 0x00, 0x26, 0x00, 0x28, 0x00, 0x2A, 0x00, 0x2C, 0x00, 0x2E, 0x00,
    0x30, 0x00, 0x32, 0x00, 0x34, 0x00, 0x36, 0x00, 0x38, 0x00, 0x3A, 0x00, 0x3C, 0x00, 0x3E, 0x00,
    0x40, 0x00, 0x42, 0x00, 0x44, 0x00, 0x46, 0x00, 0x48, 0x00, 0x4A, 0x00, 0x4C, 0x00, 0x4E, 0x00,
    0x50, 0x00, 0x52, 0x00, 0x54, 0x00, 0x56, 0x00, 0x58, 0x00, 0x5A, 0x00, 0x5C, 0x00, 0x5E, 0x00,
    0x60, 0x00, 0x62, 0x00, 0x64, 0x00, 0x66, 0x00, 0x68, 0x00, 0x6A, 0x00, 0x6C, 0x00, 0x6E, 0x00,
    0x70, 0x00, 0x72, 0x00, 0x74, 0x00, 0x76, 0x00, 0x78, 0x00, 0x7A, 0x00, 0x7C, 0x00, 0x7E, 0x00,
    0x80, 0x00, 0x7E, 0x00, 0x7C, 0x00, 0x7A, 0x00, 0x78, 0x00, 0x76, 0x00, 0x74, 0x00, 0x72, 0x00,
    0x70, 0x00, 0x6E, 0x00, 0x6C, 0x00, 0x6A, 0x00, 0x68, 0x00, 0x66, 0x00, 0x64, 0x00, 0x62, 0x00,
    0x60, 0x00, 0x5E, 0x00, 0x5C, 0x00, 0x5A, 0x00, 0x58, 0x00, 0x56, 0x00, 0x54, 0x00, 0x52, 0x00,
    0x50, 0x00, 0x4E, 0x00, 0x4C, 0x00, 0x4A, 0x00, 0x48, 0x00, 0x46, 0x00, 0x44, 0x00, 0x42, 0x00,
    0x40, 0x00, 0x3E, 0x00, 0x3C, 0x00, 0x3A, 0x00, 0x38, 0x00, 0x36, 0x00, 0x34, 0x00, 0x32, 0x00,
    0x30, 0x00, 0x2E, 0x00, 0x2C, 0x00, 0x2A, 0x00, 0x28, 0x00, 0x26, 0x00, 0x24, 0x00, 0x22, 0x00,
    0x20, 0x00, 0x1E, 0x00, 0x1C, 0x00, 0x1A, 0x00, 0x18, 0x00, 0x16, 0x00, 0x14, 0x00, 0x12, 0x00,
    0x10, 0x00, 0x0E, 0x00, 0x0C, 0x00, 0x0A, 0x00, 0x08, 0x00, 0x06, 0x00, 0x04, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x06, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x0C, 0x00, 0x0E, 0x00,
    0x10, 0x00, 0x12, 0x00, 0x14, 0x00, 0x16, 0x00, 0x18, 0x00, 0x1A, 0x00, 0x1C, 0x00, 0x1E, 0x00,
    0x20, 0x00, 0x22, 0x00, 0x24, 0x00, 0x26, 0x00, 0x28, 0x00, 0x2A, 0x00, 0x2C, 0x00, 0x2E, 0x00,
    0x30, 0x00, 0x32, 0x00, 0x34, 0x00, 0x36, 0x00, 0x38, 0x00, 0x3A, 0x00, 0x3C, 0x00, 0x3E, 0x00,
    0x40, 0x00, 0x42, 0x00, 0x44, 0x00, 0x46, 0x00, 0x48, 0x00, 0x4A, 0x00, 0x4C, 0x00, 0x4E, 0x00,
    0x50, 0x00, 0x52, 0x00, 0x54, 0x00, 0x56, 0x00, 0x58, 0x00, 0x5A, 0x00, 0x5C, 0x00, 0x5E, 0x00,
    0x60, 0x00, 0x62, 0x00, 0x64, 0x00, 0x66, 0x00, 0x68, 0x00, 0x6A, 0x00, 0x6C, 0x00, 0x6E, 0x00,
    0x70, 0x00, 0x72, 0x00, 0x74, 0x00, 0x76, 0x00, 0x78, 0x00, 0x7A, 0x00, 0x7C, 0x00, 0x7E, 0x00,
    0x80, 0x00, 0x7E, 0x00, 0x7C, 0x00, 0x7A, 0x00, 0x78, 0x00, 0x76, 0x00, 0x74, 0x00, 0x72, 0x00,
    0x70, 0x00, 0x6E, 0x00, 0x6C, 0x00, 0x6A, 0x00, 0x68, 0x00, 0x66, 0x00, 0x64, 0x00, 0x62, 0x00,
    0x60, 0x00, 0x5E, 0x00, 0x5C, 0x00, 0x5A, 0x00, 0x58, 0x00, 0x56, 0x00, 0x54, 0x00, 0x52, 0x00,
    0x50, 0x00, 0x4E, 0x00, 0x4C, 0x00, 0x4A, 0x00, 0x48, 0x00, 0x46, 0x00, 0x44, 0x00, 0x42, 0x00,
    0x40, 0x00, 0x3E, 0x00, 0x3C, 0x00, 0x3A, 0x00, 0x38, 0x00, 0x36, 0x00, 0x34, 0x00, 0x32, 0x00,
    0x30, 0x00, 0x2E, 0x00, 0x2C, 0x00, 0x2A, 0x00, 0x28, 0x00, 0x26, 0x00, 0x24, 0x00, 0x22, 0x00,
    0x20, 0x00, 0x1E, 0x00, 0x1C, 0x00, 0x1A, 0x00, 0x18, 0x00, 0x16, 0x00, 0x14, 0x00, 0x12, 0x00,
    0x10, 0x00, 0x0E, 0x00, 0x0C, 0x00, 0x0A, 0x00, 0x08, 0x00, 0x06, 0x00, 0x04, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x06, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x0C, 0x00, 0x0E, 0x00,
    0x10, 0x00, 0x12, 0x00, 0x14, 0x00, 0x16, 0x00, 0x18, 0x00, 0x1A, 0x00, 0x1C, 0x00, 0x1E, 0x00,
    0x20, 0x00, 0x22, 0x00, 0x24, 0x00, 0x26, 0x00, 0x28, 0x00, 0x2A, 0x00, 0x2C, 0x00, 0x2E, 0x00,
    0x30, 0x00, 0x32, 0x00, 0x34, 0x00, 0x36, 0x00, 0x38, 0x00, 0x3A, 0x00, 0x3C, 0x00, 0x3E, 0x00,
};
