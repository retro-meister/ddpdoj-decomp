#include "common.h"
#include "entity.h"

void bullets_update_loop(void);
void bullet_frame_from_dir(void);
void velocity_octant_swap(void);
void velocity_octant_keep(void);
void velocity_octant_negate_y(void);
void velocity_octant_negate_both(void);
void velocity_octant_negate_x(void);
void bullet_velocity_from_dir256(void);
void bullet_sprite_emit(void);
void bullet_sprite_emit_end(void);
void bullet_turn_into_star(void);
void bullet_look_set_small_by_dir(void);


s32 bullets_cancel_update();
extern s16 D_0024F330[];
extern u8 *bullets_update_state;
extern u16 g_sprite_bullets2_used;
extern u16 g_sprite_bullets_used;
extern u8 g_slowdown_timer;
extern u8 g_slowdown_setting;
extern u8 g_boss_present_b1;
extern u16 g_loop;
extern u16 g_stage;
extern u16 g_bullets_alive[];
extern u8 g_bullets[];
#ifdef DEATH_LABEL
extern s16 bullets_update_table[];
extern s16 bullets_update_table_2[];
#endif
extern u8 g_sprite_bullets2_buf[];
extern u8 g_sprite_bullets_buf[];

void bullets_update(void) {
    bullets_cancel_update();
    ((s16 *)g_bullets_alive)[0] = 0;
    reg_a4 = (u8 *)g_sprite_bullets2_buf;
    reg_a0 = (u8 *)g_sprite_bullets_buf;
    bullets_update_state = (u8 *)(reg_a4);
    reg_a0 += g_sprite_bullets_used;
    *(u8 **)(g_bullets + MAIN_OR_DEATH_LABEL(0x3490, 0x10690)) = reg_a0;
    bullets_update_loop();
    reg_d1.w = (u32) g_sprite_bullets_buf;
    reg_d0.w = (u32) *(u8 **)(g_bullets + MAIN_OR_DEATH_LABEL(0x3490, 0x10690));
    reg_d0.w -= reg_d1.w;
    reg_a4 = (u8 *)((u32)reg_a4 - (u32)bullets_update_state);
    reg_tmp.w = (u32) reg_a4;
    g_sprite_bullets_used = reg_d0.h[0];
    g_sprite_bullets2_used = reg_tmp.h[0];
#ifdef DEATH_LABEL
    if (g_slowdown_setting != 0) {
        s16 *limit;

        if (g_loop == 0) {
            limit = &bullets_update_table[g_stage];
        } else {
            limit = &bullets_update_table_2[g_stage];
        }
        reg_tmp.h[0] = (s16) g_sprite_bullets2_used + (s16) g_sprite_bullets_used;
        reg_tmp.h[0] /= 0xC;
        if ((g_boss_present_b1 & 2) && (reg_tmp.h[0] >= *limit)) {
            g_slowdown_setting |= 0x80;
            g_slowdown_timer = 1;
        }
    }
#else
    if (g_slowdown_setting != 0) {
        reg_tmp.h[0] = (s16) g_sprite_bullets2_used + (s16) g_sprite_bullets_used;
        reg_tmp.h[0] /= 0xC;
        if ((g_boss_present_b1 & 2) && (g_loop != 0) && (reg_tmp.h[0] > D_0024F330[g_stage])) {
            g_slowdown_timer = 2;
        }
    }
#endif
}

extern u8 bullet_move_routines[];
extern u8 D_0024EE90[];
void pickup_spawn_here();
#ifdef DEATH_LABEL
void bullet_cancel_to_pickup();
#endif
void bullet_slot_reset();
void bullet_fire256_direct();
void bullet_spawn256();
void spawn_request_add();
void direction256_to_entity();
void bullet_target_player_get();
extern u16 bullet_type_records[456];
extern u8 D_0024F0F0[];
extern u8 D_00262570[];
extern u32 D_0028DEA4;
extern u16 g_frame_mod2;
extern u16 g_boss_present_as_u16;
extern u16 g_enemy_signal_2;
#ifdef DEATH_LABEL
extern u8 g_twin_boss_bullet_speed_limit;
extern u8 g_death_boss_form;
#endif
extern u16 g_bullets_alive[];
extern u16 D_00299762[];
extern s16 g_bullet_limit_raised_1[];
extern s16 g_bullet_limit_raised_2[];
extern u16 g_bullet_limit_raised_3[];
extern u16 D_0029976E[];
extern u8 *D_00299770[];
extern u16 g_side_scroll_step[];
extern u16 g_bomb_entities[24];

#define SLOT_PHASE MAIN_OR_DEATH_LABEL(D_00299762[0], *(u16 *)(g_bullets + 0x10682))
#define SLOT_CURSOR MAIN_OR_DEATH_LABEL(D_00299770[0], *(u8 **)(g_bullets + 0x10690))

void bullets_update_loop(void) {
    u8 *var_a0;
    u8 *var_a0_4;
    u8 *var_a1;
    u8 *var_a2;
    s32 temp_a0_16;
    s32 temp_a1_5;
    s32 temp_a1_6;
    s32 temp_a2_3;
    s32 temp_a2_4;
    s32 temp_a2_5;
    s64 temp_a1;
    s64 temp_v1_57;
    s8 var_v0;
    s8 var_v0_2;
    s8 var_v0_3;
    u16 temp_a0_11;
    u16 temp_a0_13;
    u16 temp_a0_14;
    u16 temp_a0_15;
    u16 temp_a0_18;
    u16 temp_a0_2;
    u16 temp_a1_4;
    u16 temp_a1_8;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 temp_a3;
    u16 temp_v0;
    u16 temp_v1;
    u16 temp_v1_10;
    u16 temp_v1_11;
    u16 temp_v1_13;
    u16 temp_v1_14;
    u16 temp_v1_15;
    u16 temp_v1_16;
    u16 temp_v1_17;
    u16 temp_v1_18;
    u16 temp_v1_19;
    u16 temp_v1_20;
    u16 temp_v1_21;
    u16 temp_v1_22;
    u16 temp_v1_23;
    u16 temp_v1_24;
    u16 temp_v1_25;
    u16 temp_v1_26;
    u16 temp_v1_27;
    u16 temp_v1_28;
    u16 temp_v1_29;
    u16 temp_v1_2;
    u16 temp_v1_30;
    u16 temp_v1_31;
    u16 temp_v1_32;
    u16 temp_v1_33;
    u16 temp_v1_35;
    u16 temp_v1_36;
    u16 temp_v1_38;
    u16 temp_v1_39;
    u16 temp_v1_3;
    u16 temp_v1_40;
    u16 temp_v1_41;
    u16 temp_v1_44;
    u16 temp_v1_45;
    u16 temp_v1_47;
    u16 temp_v1_48;
    u16 temp_v1_49;
    u16 temp_v1_4;
    u16 temp_v1_50;
    u16 temp_v1_51;
    u16 temp_v1_52;
    u16 temp_v1_54;
    u16 temp_v1_55;
    u16 temp_v1_56;
    u16 temp_v1_58;
    u16 temp_v1_59;
    u16 temp_v1_5;
    u16 temp_v1_60;
    u16 temp_v1_61;
    u16 temp_v1_62;
    u16 temp_v1_6;
    u16 temp_v1_7;
    u16 temp_v1_8;
    u16 temp_v1_9;
    u16 var_a0_3;
    u32 temp_a0;
    u32 temp_a1_2;
    u32 temp_a1_3;
    u8 temp_a0_10;
    u8 temp_a0_12;
    u8 temp_a0_17;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a0_5;
    u8 temp_a0_6;
    u8 temp_a0_7;
    u8 temp_a0_8;
    u8 temp_a0_9;
    u8 temp_a1_7;
    u8 temp_a1_9;
    u8 temp_v1_12;
    u8 temp_v1_34;
    u8 temp_v1_37;
    u8 temp_v1_42;
    u8 temp_v1_43;
    u8 temp_v1_46;
    u8 temp_v1_53;
    u8 var_a0_2;
    u8 *temp_a3_2;
    u8 *var_a1_2;


    reg_a6 = g_bullets;
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x45, 0x15D);
    reg_d6.h[0] = g_side_scroll_step[0];
    if (((u16 *)g_bullet_limit_raised_1)[0] != 0) {
        reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x6D, 0x225);
        if (((u16 *)g_bullet_limit_raised_2)[0] != 0) {
            reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x9F, 0x31F);
            if (g_bullet_limit_raised_3[0] != 0) {
                reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xBD, 0x3B5);
                if (D_0029976E[0] != 0) {
                    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
                }
            }
        }
    }
    goto loop_10;

L_bom_bui:
    reg_d1.h[0] = *(u16 *)((u8 *)g_bomb_entities);
    if ((reg_d1.h[0] != 0) && (reg_d1.w & 1) && (0 <= (s64)(s16)g_boss_present_as_u16)) {
        goto block_12;
    }
    reg_d0.w = 0;
    D_0028DEA4 = reg_d7.w;
    MAIN_OR_DEATH_LABEL(pickup_spawn_here, bullet_cancel_to_pickup)();
    reg_d7.w = D_0028DEA4;
    bullet_slot_reset();

block_9:
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

loop_10:
    reg_d2.h[0] = ENTITY(reg_a6)->flags.h;
    if ((s16)reg_d2.h[0] >= 0) {
        goto block_9;
    }
    g_bullets_alive[0] += 1;
    reg_d1.h[0] = *(u16 *)((u8 *)g_bomb_entities);
    if ((s16)(reg_d1.h[0] |= (s16)g_boss_present_as_u16) < 0) {
        goto L_bom_bui;
    }

block_12:
    reg_d0.h[0] = 0x5180;
    reg_d0.h[0] &= reg_d2.h[0];
    if (reg_d0.h[0] != 0) {
        goto L_not_plain;
    }
    reg_d0.h[1] = ENTITY(reg_a6)->misc.h;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d0.h[0] -= reg_d6.h[0];
    ENTITY(reg_a6)->x.h += reg_d0.h[0];
    ENTITY(reg_a6)->y.h += reg_d0.h[1];
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xC800;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0xC800;
    if (reg_tmp.h[1] != 0) {
        goto block_16;
    }
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x9000;
    reg_tmp.w = reg_d0.w;
    temp_v0 = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_d0.h[1] = temp_v0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9000;
    if (reg_tmp.h[1] != 0) {
        goto block_16;
    }
    reg_a1 = (u8 *)((u32)reg_a6 + 2);
    reg_d0.h[1] = *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_d0.w = (u32)((s32)reg_d0.w >> 6);
    temp_a1_2 = reg_d0.w;
    reg_d0.w = temp_a1_2 & 0x07FF03FF;
    temp_a0 = reg_d0.w;
    reg_d0.w = temp_a0 | 0x80008000;
    *(*(u16 **)&reg_a4) = reg_d0.h[1];
    (*(u16 **)&reg_a4) += 1;
    *(*(u16 **)&reg_a4) = reg_d0.h[0];
    (*(u16 **)&reg_a4) += 1;
    *(*(u16 **)&reg_a4) = *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    (*(u16 **)&reg_a4) += 1;
    *(*(u16 **)&reg_a4) = *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    (*(u16 **)&reg_a4) += 1;
    *(*(u16 **)&reg_a4) = *(u16 *)(reg_a1 + 0);
    (*(u16 **)&reg_a4) += 1;
    *(*(u16 **)&reg_a4) = ENTITY(reg_a6)->attr.h;
    (*(u16 **)&reg_a4) += 1;
    bullet_sprite_emit_end();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x22);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    goto block_44;

block_16:
    bullet_slot_reset();
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

L_not_plain:
    if (reg_d2.w & 0x1000) {
        goto block_16;
    }
    ENTITY(reg_a6)->x.h -= reg_d6.h[0];
    if (0 > (s64)(s16)reg_d2.b[0]) {
        goto L_0012A4B0;
    }
    if (!(reg_d2.w & 0x100)) {
        goto L_0012A68C;
    }
    temp_a0 = reg_d6.h[0]; ENTITY(reg_a6)->x.h += temp_a0;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    bullet_velocity_from_dir256();
    ENTITY(reg_a6)->misc.h = reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
    reg_d0.w = 0x3F;
    reg_d0.h[0] &= ENTITY(reg_a6)->flags.h;
    reg_a0 = bullet_move_routines;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target = (void (*)())reg_a0;
    reg_call_target();
    SLOT_PHASE += 1;
    if (SLOT_PHASE == 3) {
        SLOT_PHASE = 0;
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

L_0012A4B0:
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xC800;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0xC800;
    if (reg_tmp.h[1] != 0) {
        goto block_16;
    }
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x9000;
    reg_tmp.w = reg_d0.w;
    temp_v0 = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_d0.h[1] = temp_v0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9000;
    if (reg_tmp.h[1] != 0) {
        goto block_16;
    }
    if (reg_d2.w & 0x100) {
        goto L_0012A5DC;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    bullet_velocity_from_dir256();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
    bullet_sprite_emit();
    if ((ENTITY(reg_a6)->flags.b[1]) & 0x40) {
        goto block_33;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x22);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    goto block_44;

L_0012A5DC:
    reg_d0.w = 0x3F;
    reg_d0.h[0] &= ENTITY(reg_a6)->flags.h;
    reg_a0 = bullet_move_routines;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target = (void (*)())reg_a0;
    reg_call_target();
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

L_0012A68C:
    reg_d0.h[1] = ENTITY(reg_a6)->misc.h;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    ENTITY(reg_a6)->x.h += reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    bullet_sprite_emit();

block_33:
    temp_a0_17 = ENTITY(reg_a6)->flags.b[1];
    var_a1_2 = reg_a6 + 1;
    if (temp_a0_17 & 0x20) {
        ENTITY(reg_a6)->flags.b[1] = (u8)(temp_a0_17 | 0x20);
    } else {
        ENTITY(reg_a6)->flags.b[1] = (u8)(temp_a0_17 | 0x20);
        reg_tmp.w = 0x24F;
        ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
        ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
        reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a1 = ((u8 *)bullet_type_records);
        reg_d0.h[0] &= 0x3F;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_a1 += reg_d0.h[0];
        reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a1 - 2) == 1) {
            reg_tmp.w = 0x23F;
            ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
            ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
        }
        ENTITY(reg_a6)->look.sh = 0x410;
        reg_tmp.w = 0xFC00FE00;
        ENTITY(reg_a6)->offset_y.h = reg_tmp.h[1];
        var_a1_2 = (void *)reg_tmp.h[0];
        ENTITY(reg_a6)->offset_x.h = (u16)var_a1_2;
        ENTITY(reg_a6)->hit_x_minus.h = 0x10U;
        ENTITY(reg_a6)->misc.h = (u16)((s16)ENTITY(reg_a6)->misc.h >> 1);
        *(u16 *)(reg_a6 + 0x20) = (u16)((s16)*(u16 *)(reg_a6 + 0x20) >> 1);
    }
    reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_tmp.w += 1;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    ENTITY(reg_a6)->hit_x_minus.h -= 1;
    if (ENTITY(reg_a6)->hit_x_minus.h == 0) {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x3C);
        if ((s16)reg_d0.h[0] >= 0) {
            D_0028DEA4 = reg_d7.w;
            MAIN_OR_DEATH_LABEL(pickup_spawn_here, bullet_cancel_to_pickup)();
            reg_d7.w = D_0028DEA4;
        }
        bullet_slot_reset();
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

block_44:
    switch (reg_tmp.w) {
    default:
        return;
                            case 0:                 /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                reg_tmp.w += 1;
                                ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                if (reg_tmp.w == 0x146) {
                                    reg_tmp.w = 0x140;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 1:                 /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                reg_tmp.w += 1;
                                ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                if (reg_tmp.w == 0x146) {
                                    reg_tmp.w = 0x146;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 3:                 /* switch 1 */
                                temp_a0_3 = ENTITY(reg_a6)->flags.b[1];
                                if (temp_a0_3 & 8) {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_3 & 0xF7;
                                } else {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_3 | 8;
                                    reg_tmp.w = 1;
                                    reg_a1 -= 4;
                                    reg_tmp1.h[1] = *(u16 *)reg_a1;
                                    reg_tmp1.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w += reg_tmp.w;
                                    *(u16 *)reg_a1 = (u16) reg_tmp1.h[1];
                                    *(u16 *)(reg_a1 + 2) = reg_tmp1.h[0];
                                    reg_tmp.h[1] = *(u16 *)reg_a1;
                                    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w = 0x1A2;
                                    if (reg_tmp1.w == reg_tmp.w) {
                                        reg_tmp.w = 0x19E;
                                        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 4:                 /* switch 1 */
                                temp_a0_4 = ENTITY(reg_a6)->flags.b[1];
                                if (temp_a0_4 & 8) {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_4 & 0xF7;
                                } else {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_4 | 8;
                                    reg_tmp.w = 1;
                                    reg_a1 -= 4;
                                    reg_tmp1.h[1] = *(u16 *)reg_a1;
                                    reg_tmp1.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w += reg_tmp.w;
                                    *(u16 *)reg_a1 = (u16) reg_tmp1.h[1];
                                    *(u16 *)(reg_a1 + 2) = reg_tmp1.h[0];
                                    reg_tmp.h[1] = *(u16 *)reg_a1;
                                    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w = 0x1A6;
                                    if (reg_tmp1.w == reg_tmp.w) {
                                        reg_tmp.w = 0x1A2;
                                        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 5:                 /* switch 1 */
                                temp_a0_5 = ENTITY(reg_a6)->flags.b[1];
                                if (temp_a0_5 & 8) {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_5 & 0xF7;
                                } else {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_5 | 8;
                                    reg_tmp.w = 1;
                                    reg_a1 -= 4;
                                    reg_tmp1.h[1] = *(u16 *)reg_a1;
                                    reg_tmp1.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w += reg_tmp.w;
                                    *(u16 *)reg_a1 = (u16) reg_tmp1.h[1];
                                    *(u16 *)(reg_a1 + 2) = reg_tmp1.h[0];
                                    reg_tmp.h[1] = *(u16 *)reg_a1;
                                    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w = 0x1AA;
                                    if (reg_tmp1.w == reg_tmp.w) {
                                        reg_tmp.w = 0x1A6;
                                        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 6:                 /* switch 1 */
                                temp_a0_6 = ENTITY(reg_a6)->flags.b[1];
                                if (temp_a0_6 & 8) {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_6 & 0xF7;
                                } else {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_6 | 8;
                                    reg_tmp.w = 1;
                                    reg_a1 -= 4;
                                    reg_tmp1.h[1] = *(u16 *)reg_a1;
                                    reg_tmp1.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w += reg_tmp.w;
                                    *(u16 *)reg_a1 = (u16) reg_tmp1.h[1];
                                    *(u16 *)(reg_a1 + 2) = reg_tmp1.h[0];
                                    reg_tmp.h[1] = *(u16 *)reg_a1;
                                    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w = 0x1AE;
                                    if (reg_tmp1.w == reg_tmp.w) {
                                        reg_tmp.w = 0x1AA;
                                        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 7:                 /* switch 1 */
                                temp_v1_12 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_12 == 0) {
                                    reg_a6 += 0xA;
                                    reg_d0.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_a0 = reg_a6 + 6;
                                    reg_d0.w += 1;
                                    temp_a1_4 = *(u16 *)reg_a0;
                                    reg_a0 += 2;
                                    reg_tmp.h[1] = temp_a1_4;
                                    reg_tmp.h[0] = *(u16 *)reg_a0;
                                    reg_a0 += 2;
                                    if (reg_tmp.w == reg_d0.w) {
                                        reg_tmp.h[1] = *(u16 *)reg_a0;
                                        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
                                        reg_d0.w -= reg_tmp.w;
                                    }
                                    reg_a0 += 4;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_d0.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[0];
                                    *(u8 *)(reg_a0 + 0) = *(u8 *)(reg_a0 + 1);
                                    reg_a0 += 2;
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_12 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 8:                 /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                reg_tmp.w += 1;
                                ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                if (reg_tmp.w == 0x1EA) {
                                    reg_tmp.w = 0x1E6;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 9:                 /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                reg_tmp.w += 1;
                                ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                if (reg_tmp.w == 0x1BD) {
                                    reg_tmp.w = 0x1B9;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 10:                /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                reg_tmp.w += 1;
                                ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                if (reg_tmp.w == 0x1C3) {
                                    reg_tmp.w = 0x1BF;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 11:                /* switch 1 */
                                reg_a1 -= 4;
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                reg_tmp.w += 1;
                                *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                if (reg_tmp.w == 0x224) {
                                    reg_tmp.w = 0x220;
                                    *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                    *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 12:                /* switch 1 */
                                reg_a1 -= 4;
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                reg_tmp.w += 1;
                                *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                if (reg_tmp.w == 0x212) {
                                    reg_tmp.w = 0x20E;
                                    *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                    *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 13:                /* switch 1 */
                                reg_a1 -= 4;
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                reg_tmp.w += 1;
                                *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                if (reg_tmp.w == 0x218) {
                                    reg_tmp.w = 0x214;
                                    *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                    *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 16:                /* switch 1 */
                                reg_tmp.w = 0x1A6;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                reg_tmp.w = 0xFC00FE00;
                                ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
                                ENTITY(reg_a6)->look.sh = 0x410;
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 17:                /* switch 1 */
                                reg_tmp.w = 0x1A6;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                reg_tmp.w = 0xFC00FE00;
                                ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
                                ENTITY(reg_a6)->look.sh = 0x410;
                                reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2B);
                                *(u8 *)(reg_a6 + 0x2B) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a6 + 0x2B) = (u8) *(u8 *)(reg_a6 + 0x2A);
                                    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x35);
                                    ENTITY(reg_a6)->move.b.dir += reg_d0.b[0];
                                }
                                reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                *(u8 *)(reg_a6 + 0x2D) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                    ENTITY(reg_a6)->move.b.speed += 1;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 18:                /* switch 1 */
                                reg_tmp.w = 0x1A6;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                reg_tmp.w = 0xFC00FE00;
                                ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
                                ENTITY(reg_a6)->look.sh = 0x410;
                                *(u16 *)(reg_a6 + 0x34) -= 1;
                                if (0 > (s64)*(s16 *)(reg_a6 + 0x34)) {
                                    reg_d0.w = 0x35;
                                    spawn_request_add();
                                    *(u16 *)(reg_a0 + 0x16) = (u16) ENTITY(reg_a6)->y.h;
                                    *(u16 *)(reg_a0 + 0x18) = (u16) ENTITY(reg_a6)->x.h;
                                    goto block_16;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 19:                /* switch 1 */
                                reg_d0.w = 3;
                                temp_a0_3 = *(u8 *)(reg_a6 + 0x35);
                                temp_a2_3 = 1 << reg_d0.b[0];
                                if (temp_a2_3 & temp_a0_3) {
                                    temp_a0_7 = ENTITY(reg_a6)->flags.b[1];
                                    if (temp_a0_7 & temp_a2_3) {
                                        ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_7 & (~temp_a2_3 & 0xFF));
                                        goto block_144;
                                    }
                                    ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_7 | (temp_a2_3 & 0xFF));
                                    reg_a6 += 0xA;
                                    reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp.w += 1;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    reg_tmp.w = 0x297;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->y.h;
                                    if (reg_tmp.w == reg_tmp1.w) {
                                        reg_tmp.w = 0x287;
                                        ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_d1.h[1] = *(u16 *)(reg_a6 + 0x2C);
                                reg_d1.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                if (reg_d1.w != 0) {
                                    reg_a0 = (u8 *) reg_d1.w;
                                    if ((0 > (s64)*(s16 *)(reg_a0 + 0)) && (0 <= (s64)*(s8 *)(reg_a0 + 0))) {
                                        reg_d1.h[1] = *(u16 *)(reg_a0 + 2);
                                        reg_d1.h[0] = *(u16 *)(reg_a0 + 4);
                                        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
                                        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
                                        reg_d1.w += reg_tmp.w;
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
                                        temp_a0_8 = ENTITY(reg_a6)->flags.b[1];
                                        temp_a1_5 = 1 << reg_d0.b[0];
                                        if (temp_a0_8 & temp_a1_5) {
                                            ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_8 & (~temp_a1_5 & 0xFF));
                                        } else {
                                            ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_8 | (temp_a1_5 & 0xFF));
                                            reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
                                            reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
                                            reg_tmp.w += 1;
                                            ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                            ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                            reg_tmp.w = 0x288;
                                            reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                            reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                            if (reg_tmp.w != reg_tmp1.w) {
                                                goto block_144;
                                            }
                                            goto block_143;
                                        }
                                        goto block_144;
                                    }
                                    goto L_clr_block_143;
                                }
block_143:
                                *(u8 *)(reg_a6 + 0x35) |= 8;
                                ENTITY(reg_a6)->misc.h = (u16) *(u16 *)(reg_a6 + 0x30);
                                *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
block_144:
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
L_clr_block_143:
                                bullet_slot_reset();
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 20:                /* switch 1 */
                                reg_a6 += 0xA;
                                if (g_frame_mod2 != 0) {
                                    reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp.w += 1;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                    if (reg_tmp.w == 0x1B4) {
                                        reg_tmp.w = 0x1AE;
                                        ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    }
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 22:                /* switch 1 */
                                reg_d0.w = 3;
                                temp_a0_4 = *(u8 *)(reg_a6 + 0x35);
                                temp_a2_4 = 1 << reg_d0.b[0];
                                if (temp_a2_4 & temp_a0_4) {
                                    temp_a0_9 = ENTITY(reg_a6)->flags.b[1];
                                    if (temp_a0_9 & temp_a2_4) {
                                        ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_9 & (~temp_a2_4 & 0xFF));
                                        goto block_167;
                                    }
                                    ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_9 | (temp_a2_4 & 0xFF));
                                    reg_a6 += 0xA;
                                    reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp.w += 1;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    reg_tmp.w = 0x2AB;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->y.h;
                                    if (reg_tmp.w == reg_tmp1.w) {
                                        reg_tmp.w = 0x29B;
                                        ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_d1.h[1] = *(u16 *)(reg_a6 + 0x2C);
                                reg_d1.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                if (reg_d1.w != 0) {
                                    reg_a0 = (u8 *) reg_d1.w;
                                    if ((0 > (s64)*(s16 *)(reg_a0 + 0)) && (0 <= (s64)*(s8 *)(reg_a0 + 0))) {
                                        reg_d1.h[1] = *(u16 *)(reg_a0 + 2);
                                        reg_d1.h[0] = *(u16 *)(reg_a0 + 4);
                                        reg_tmp1.h[1] = *(u16 *)(reg_a6 + 0x28);
                                        reg_tmp1.h[0] = *(u16 *)(reg_a6 + 0x2A);
                                        reg_d1.w = (u32) (reg_d1.w + reg_tmp1.w);
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
                                        temp_a0_10 = ENTITY(reg_a6)->flags.b[1];
                                        temp_a1_6 = 1 << reg_d0.b[0];
                                        if (temp_a0_10 & temp_a1_6) {
                                            ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_10 & (~temp_a1_6 & 0xFF));
                                        } else {
                                            ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_10 | (temp_a1_6 & 0xFF));
                                            reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
                                            reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
                                            reg_tmp.w += 1;
                                            ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                            ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                            reg_tmp.w = 0x29C;
                                            reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                            reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                            if (reg_tmp.w != reg_tmp1.w) {
                                                goto block_167;
                                            }
                                            goto block_166;
                                        }
                                        goto block_167;
                                    }
                                    goto L_clr_block_166;
                                }
block_166:
                                *(u8 *)(reg_a6 + 0x35) |= 8;
                                ENTITY(reg_a6)->misc.h = (u16) *(u16 *)(reg_a6 + 0x30);
                                *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
block_167:
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
L_clr_block_166:
                                bullet_slot_reset();
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 23:                /* switch 1 */
                                reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
                                reg_tmp.w += 1;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
                                if (reg_tmp.w == 0x224) {
                                    reg_tmp.w = 0x220;
                                    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                }
                                temp_a0_11 = *(u16 *)(reg_a6 + 0x36);
                                if (temp_a0_11 != 0) {
                                    if (0 <= (s64)(s16)temp_a0_11) {
                                        *(u16 *)(reg_a6 + 0x36) = (u16) (temp_a0_11 - 1);
                                    }
                                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                    *(u8 *)(reg_a6 + 0x2D) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                        ENTITY(reg_a6)->misc.h -= reg_d0.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 24:                /* switch 1 */
                                reg_d0.w = 3;
                                temp_a1_7 = *(u8 *)(reg_a6 + 0x35);
                                temp_a2_5 = 1 << reg_d0.b[0];
                                if (temp_a2_5 & temp_a1_7) {
                                    temp_a0_12 = ENTITY(reg_a6)->flags.b[1];
                                    if (temp_a0_12 & temp_a2_5) {
                                        ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_12 & (~temp_a2_5 & 0xFF));
                                    } else {
                                        ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_12 | (temp_a2_5 & 0xFF));
                                        reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
                                        reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
                                        reg_tmp.w += 1;
                                        ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                        reg_tmp.w = 0x2AB;
                                        reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                        reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                        if (reg_tmp.w == reg_tmp1.w) {
                                            reg_tmp.w = 0x29B;
                                            ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                            ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                        }
                                    }
                                    temp_a0_13 = *(u16 *)(reg_a6 + 0x36);
                                    if (temp_a0_13 != 0) {
                                        if (0 <= (s64)(s16)temp_a0_13) {
                                            *(u16 *)(reg_a6 + 0x36) = (u16) (temp_a0_13 - 1);
                                        }
                                        reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                        *(u8 *)(reg_a6 + 0x2D) -= 1;
                                        if ((s32) reg_tmp.b[0] <= 0) {
                                            *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                            ENTITY(reg_a6)->misc.h -= reg_d0.h[0];
                                        }
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                *(u8 *)(reg_a6 + 0x35) = (u8) (temp_a1_7 | 8);
                                ENTITY(reg_a6)->misc.h = (u16) *(u16 *)(reg_a6 + 0x30);
                                *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 25:                /* switch 1 */
                                if (*(u16 *)(reg_a6 + 0x2C) != 0) {
                                    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                                    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                                    if ((s32) reg_d0.h[0] < 0x200) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] *= -1;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        ENTITY(reg_a6)->attr.b.flip ^= 0x40;
                                        goto block_202;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x3600) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] *= -1;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        ENTITY(reg_a6)->attr.b.flip ^= 0x40;
                                        goto block_202;
                                    }
                                    reg_tmp.w = reg_d0.w;
                                    reg_d0.h[1] = reg_tmp.h[0];
                                    reg_d0.h[0] = reg_tmp.h[1];
                                    if (((s32) reg_d0.h[0] >= 0x600) && ((s32) reg_d0.h[0] > 0x6E00)) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] *= -1;
                                        reg_d1.b[0] += 0x80;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        ENTITY(reg_a6)->attr.b.flip ^= 0x20;
block_202:
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                        bullet_velocity_from_dir256();
                                        ENTITY(reg_a6)->misc.h = (u16) reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = (u16) reg_d3.h[0];
                                        reg_tmp.w = 0x14;
                                        reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                        reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                        reg_tmp.w = (u32) (reg_tmp.w + reg_tmp1.w);
                                        ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                        *(u16 *)(reg_a6 + 0x2C) -= 1;
                                    }
                                }
                                temp_v1_34 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_34 == 0) {
                                    reg_tmp.w = 0x297;
                                    reg_d0.h[1] = reg_tmp.h[1];
                                    reg_d0.h[0] = reg_tmp.h[0];
                                    reg_tmp.w = 0x287;
                                    reg_d1.h[1] = reg_tmp.h[1];
                                    reg_d1.h[0] = reg_tmp.h[0];
                                    if (*(u16 *)(reg_a6 + 0x2C) == 0) {
                                        reg_tmp.w = 0x2AB;
                                        reg_d0.h[1] = reg_tmp.h[1];
                                        reg_d0.h[0] = reg_tmp.h[0];
                                        reg_tmp.w = 0x29B;
                                        reg_d1.h[1] = reg_tmp.h[1];
                                        reg_d1.h[0] = reg_tmp.h[0];
                                    }
                                    reg_tmp.w = 1;
                                    reg_a6 += 0xA;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp1.w += reg_tmp.w;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp1.h[1];
                                    ENTITY(reg_a6)->y.h = reg_tmp1.h[0];
                                    if (reg_tmp1.w == reg_d0.w) {
                                        ENTITY(reg_a6)->flags.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_34 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 26:                /* switch 1 */
                                temp_v1_37 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_37 == 0) {
                                    reg_a6 += 0xA;
                                    reg_d0.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_a0 = reg_a6 + 6;
                                    reg_d0.w += 1;
                                    temp_a1_8 = *(u16 *)reg_a0;
                                    reg_a0 += 2;
                                    reg_tmp.h[1] = temp_a1_8;
                                    reg_tmp.h[0] = *(u16 *)reg_a0;
                                    reg_a0 += 2;
                                    if (reg_d0.w == reg_tmp.w) {
                                        reg_tmp.h[1] = *(u16 *)reg_a0;
                                        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
                                        reg_d0.w -= reg_tmp.w;
                                    }
                                    reg_a0 += 4;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_d0.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[0];
                                    *(u8 *)(reg_a0 + 0) = *(u8 *)(reg_a0 + 1);
                                    reg_a0 += 2;
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_37 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 27:                /* switch 1 */
                                (*(u16 **)&reg_a4) -= 6;
                                reg_a0 = SLOT_CURSOR;
                                reg_a2 = (u8 *)((u16 *)reg_a4);
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                reg_a1 -= 4;
                                SLOT_CURSOR = reg_a0;
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                reg_tmp.w += 1;
                                *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                reg_tmp.w = 0x1A2;
                                reg_tmp1.h[1] = *(u16 *)reg_a1;
                                reg_tmp1.h[0] = *(u16 *)(reg_a1 + 2);
                                if (reg_tmp.w == reg_tmp1.w) {
                                    reg_tmp.w = 0x19E;
                                    *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                    *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                }
                                temp_v1_40 = *(u16 *)(reg_a6 + 0x30);
                                if (temp_v1_40 != 0) {
                                    *(u16 *)(reg_a6 + 0x30) = (u16) (temp_v1_40 - 1);
                                    reg_d0.w = (u32) *(u16 *)(reg_a6 + 0x28);
                                    reg_d1.w = *(u16 *)(reg_a6 + 0x2A);
                                    ENTITY(reg_a6)->y.h += reg_d0.h[0];
                                    ENTITY(reg_a6)->x.h += reg_d1.h[0];
                                    reg_d1.w = 0;
                                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                    *(u8 *)(reg_a6 + 0x2D) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                        ENTITY(reg_a6)->move.b.dir += reg_d0.b[0];
                                        reg_d1.w = 1;
                                    }
                                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x37);
                                    *(u8 *)(reg_a6 + 0x37) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a6 + 0x37) = (u8) *(u16 *)(reg_a6 + 0x36);
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x38);
                                        ENTITY(reg_a6)->move.b.speed += reg_d0.b[0];
#ifdef DEATH_LABEL
                                        if ((g_death_boss_form == 2) && (ENTITY(reg_a6)->move.b.speed > g_twin_boss_bullet_speed_limit)) {
                                            ENTITY(reg_a6)->move.b.speed = g_twin_boss_bullet_speed_limit;
                                        }
#endif
                                        reg_d1.w = 1;
                                    }
                                    if (reg_d1.h[0] != 0) {
                                        reg_d0.w = 0;
                                        reg_d1.w = 0;
                                        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d3.h[0] = *(u16 *)(D_0024F0F0 + (reg_d1.h[0] * 2));
                                        temp_a3_2 = D_00262570 + (reg_d3.h[0] * 2);
                                        reg_d2.w = reg_d0.h[0] * (*(u16 *)(temp_a3_2 + 0));
                                        reg_d3.w = reg_d0.h[0] * (*(u16 *)(temp_a3_2 + 2));
                                        reg_d2.w = (u32) ((s32) reg_d2.w >> 4);
                                        reg_d3.w = (u32) ((s32) reg_d3.w >> 4);
                                        reg_d1.h[0] &= 0xC0;
                                        switch (reg_d1.h[0]) { /* switch 2; irregular */
                                        case 0x0:   /* switch 2 */
                                            break;
                                        case 0x40:  /* switch 2 */
                                            reg_d2.h[0] *= 0xFFFF;
                                            break;
                                        case 0x80:  /* switch 2 */
                                            reg_d2.h[0] *= -1;
                                            reg_d3.h[0] *= 0xFFFF;
                                            break;
                                        case 0xC0:  /* switch 2 */
                                            reg_d3.h[0] *= 0xFFFF;
                                            break;
                                        }
                                        ENTITY(reg_a6)->misc.h = (u16) reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = (u16) reg_d3.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 28:                /* switch 1 */
                                temp_v1_42 = *(u8 *)(reg_a6 + 0x29);
                                if (temp_v1_42 != 0) {
                                    *(u8 *)(reg_a6 + 0x29) = (u8) (temp_v1_42 - 1);
                                    if (*(u8 *)(reg_a6 + 0x29) == 0) {
                                        bullet_target_player_get();
                                        if (cond_flag == 0) {
                                            direction256_to_entity();
                                            if (g_enemy_signal_2 == 0) {
                                                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                                reg_d1.b[0] += 0xB0;
                                            }
                                            reg_d0.h[1] = *(u16 *)(reg_a6 + 0x2C);
                                            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                            reg_d3.w = 0;
                                            reg_d4.w = 0;
                                            MAIN_OR_DEATH_LABEL(bullet_fire256_direct, bullet_spawn256)();
                                        }
                                    }
                                }
                                temp_v1_43 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_43 == 0) {
                                    reg_d0.w = 0x297;
                                    reg_d1.w = 0x287;
                                    reg_a6 += 0xA;
                                    reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp.w += 1;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    if (reg_tmp.w == reg_d0.w) {
                                        ENTITY(reg_a6)->flags.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_43 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 29:                /* switch 1 */
                                if (*(u16 *)(reg_a6 + 0x2C) != 0) {
                                    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                                    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                                    if ((s32) reg_d0.h[0] < 0x200) {
                                        reg_d1.h[0] = 0x40;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        ENTITY(reg_a6)->attr.b.flip ^= 0x40;
                                        goto block_261;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x3600) {
                                        reg_d1.h[0] = 0xC0;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        ENTITY(reg_a6)->attr.b.flip ^= 0x40;
                                        goto block_261;
                                    }
                                    reg_tmp.w = reg_d0.w;
                                    reg_d0.h[1] = reg_tmp.h[0];
                                    reg_d0.h[0] = reg_tmp.h[1];
                                    if ((s32) reg_d0.h[0] < 0x600) {
                                        reg_d1.h[0] = 0;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        ENTITY(reg_a6)->attr.b.flip ^= 0x20;
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                        bullet_velocity_from_dir256();
                                        reg_d2.w = (u32) ((s32) reg_d2.w >> 1);
                                        reg_d3.w = (u32) ((s32) reg_d3.w >> 1);
                                        ENTITY(reg_a6)->misc.h = reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
                                        goto block_262;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x6E00) {
                                        reg_d1.h[0] = 0x80;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        ENTITY(reg_a6)->attr.b.flip ^= 0x20;
block_261:
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                        bullet_velocity_from_dir256();
                                        reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 1);
                                        reg_d3.h[0] = (u16) ((s16) reg_d3.h[0] >> 1);
                                        ENTITY(reg_a6)->misc.h = reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
block_262:
                                        reg_tmp.w = 0x14;
                                        reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                        reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                        reg_tmp.w = (u32) (reg_tmp.w + reg_tmp1.w);
                                        ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                        *(u16 *)(reg_a6 + 0x2C) -= 1;
                                    }
                                }
                                temp_v1_46 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_46 == 0) {
                                    reg_tmp.w = 0x297;
                                    reg_d0.h[1] = reg_tmp.h[1];
                                    reg_d0.h[0] = reg_tmp.h[0];
                                    reg_tmp.w = 0x287;
                                    reg_d1.h[1] = reg_tmp.h[1];
                                    reg_d1.h[0] = reg_tmp.h[0];
                                    if (*(u16 *)(reg_a6 + 0x2C) == 0) {
                                        reg_tmp.w = 0x2AB;
                                        reg_d0.h[1] = reg_tmp.h[1];
                                        reg_d0.h[0] = reg_tmp.h[0];
                                        reg_tmp.w = 0x29B;
                                        reg_d1.h[1] = reg_tmp.h[1];
                                        reg_d1.h[0] = reg_tmp.h[0];
                                    }
                                    reg_tmp.w = 1;
                                    reg_a6 += 0xA;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp1.w += reg_tmp.w;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp1.h[1];
                                    ENTITY(reg_a6)->y.h = reg_tmp1.h[0];
                                    if (reg_tmp1.w == reg_d0.w) {
                                        ENTITY(reg_a6)->flags.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_46 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 30:                /* switch 1 */
                                reg_tmp.w = 1;
                                reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                reg_tmp1.w += reg_tmp.w;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp1.h[1];
                                ENTITY(reg_a6)->sprite.h = reg_tmp1.h[0];
                                reg_tmp.w = 0x224;
                                reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                if (reg_tmp.w == reg_tmp1.w) {
                                    reg_tmp.w = 0x220;
                                    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                }
                                temp_a0_14 = *(u16 *)(reg_a6 + 0x34);
                                if (temp_a0_14 != 0) {
                                    if (0 <= (s64)(s16)temp_a0_14) {
                                        *(u16 *)(reg_a6 + 0x34) = (u16) (temp_a0_14 - 1);
                                    }
                                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                    *(u8 *)(reg_a6 + 0x2D) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x30);
                                        ENTITY(reg_a6)->misc.h += reg_d0.h[0];
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x32);
                                        *(u16 *)(reg_a6 + 0x20) += reg_d0.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 31:                /* switch 1 */
                                reg_tmp.w = 1;
                                reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                reg_tmp1.w += reg_tmp.w;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp1.h[1];
                                ENTITY(reg_a6)->sprite.h = reg_tmp1.h[0];
                                reg_tmp.w = 0x224;
                                reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                if (reg_tmp.w == reg_tmp1.w) {
                                    reg_tmp.w = 0x220;
                                    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                }
                                temp_a0_15 = *(u16 *)(reg_a6 + 0x34);
                                if (temp_a0_15 != 0) {
                                    if (0 <= (s64)(s16)temp_a0_15) {
                                        *(u16 *)(reg_a6 + 0x34) = (u16) (temp_a0_15 - 1);
                                    }
                                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                    *(u8 *)(reg_a6 + 0x2D) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x30);
                                        ENTITY(reg_a6)->misc.h += reg_d0.h[0];
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x32);
                                        *(u16 *)(reg_a6 + 0x20) += reg_d0.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 32:                /* switch 1 */
                                reg_tmp.w = 1;
                                reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                reg_tmp1.w += reg_tmp.w;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp1.h[1];
                                ENTITY(reg_a6)->sprite.h = reg_tmp1.h[0];
                                reg_tmp.w = 0x1EA;
                                reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                var_a2 = reg_a6 + 0xA;
                                if (reg_tmp.w == reg_tmp1.w) {
                                    reg_tmp.w = 0x1E6;
                                    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                }
                                reg_d0.w = (u32) *(u16 *)(reg_a6 + 0x28);
                                reg_d1.w = *(u16 *)(reg_a6 + 0x2A);
                                ENTITY(reg_a6)->y.h += reg_d0.h[0];
                                var_a1 = reg_a6;
                                (*(u16 *)((u8 *)(var_a1) + (4))) += reg_d1.h[0];
                                reg_d1.w = 0;
                                reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                *(u8 *)(reg_a6 + 0x2D) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                    var_a2 = reg_a6;
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(var_a2) + (0x2E)));
                                    var_a1 = (u8 *) (*(u8 *)((u8 *)(var_a2) + (0x1A)));
                                    (*(u8 *)((u8 *)(var_a2) + (0x1A))) = (u8) (var_a1 + reg_d0.b[0]);
                                    reg_d1.w = 1;
                                }
                                var_a0_4 = reg_a6;
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0_4) + (0x37)));
                                (*(u8 *)((u8 *)(var_a0_4) + (0x37))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a6 + 0x37) = (u8) *(u16 *)(reg_a6 + 0x36);
                                    var_a2 = reg_a6;
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(var_a2) + (0x38)));
                                    var_a1 = (u8 *) (*(u8 *)((u8 *)(var_a2) + (0x1B)));
                                    var_a0_4 = var_a1 + reg_d0.b[0];
                                    (*(u8 *)((u8 *)(var_a2) + (0x1B))) = (u8) var_a0_4;
                                    reg_d1.w = 1;
                                }
                                if (reg_d1.h[0] != 0) {
                                    reg_d0.w = 0;
                                    reg_d1.w = 0;
                                    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                    bullet_velocity_from_dir256();
                                    ENTITY(reg_a6)->misc.h = (u16) reg_d2.h[0];
                                    *(u16 *)(reg_a6 + 0x20) = (u16) reg_d3.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 33:                /* switch 1 */
                                reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2F);
                                *(u8 *)(reg_a6 + 0x2F) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a6 + 0x2F) = (u8) *(u16 *)(reg_a6 + 0x2E);
                                    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2C);
                                    reg_a0 = D_0024EE90;
                                    reg_a0 += reg_d0.h[0];
                                    ENTITY(reg_a6)->draw.h = *(u16 *)(reg_a0 + 0);
                                    ENTITY(reg_a6)->sprite.h = *(u16 *)(reg_a0 + 2);
                                    *(u16 *)(reg_a6 + 0x2C) -= 4;
                                    if (0 > (s64)*(s16 *)(reg_a6 + 0x2C)) {
                                        *(u16 *)(reg_a6 + 0x2C) = 0xC;
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 34:                /* switch 1 */
                                if (*(u16 *)(reg_a6 + 0x2C) != 0) {
                                    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                                    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                                    if ((s32) reg_d0.h[0] < 0x200) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] += 0x80;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        ENTITY(reg_a6)->attr.b.flip ^= 0x40;
                                        goto block_314;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x3600) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] += 0x80;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        ENTITY(reg_a6)->attr.b.flip ^= 0x40;
                                        goto block_314;
                                    }
                                    reg_tmp.w = reg_d0.w;
                                    reg_d0.h[1] = reg_tmp.h[0];
                                    reg_d0.h[0] = reg_tmp.h[1];
                                    if ((s32) reg_d0.h[0] < 0x600) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] += 0x80;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        ENTITY(reg_a6)->attr.b.flip ^= 0x20;
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                        bullet_velocity_from_dir256();
                                        ENTITY(reg_a6)->misc.h = reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
                                        goto block_315;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x6E00) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] += 0x80;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        ENTITY(reg_a6)->attr.b.flip ^= 0x20;
block_314:
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                        bullet_velocity_from_dir256();
                                        ENTITY(reg_a6)->misc.h = reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
block_315:
                                        reg_tmp.w = 0x14;
                                        reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                        reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                        reg_tmp.w = (u32) (reg_tmp.w + reg_tmp1.w);
                                        ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                        *(u16 *)(reg_a6 + 0x2C) -= 1;
                                    }
                                }
                                temp_v1_53 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_53 == 0) {
                                    reg_tmp.w = 0x297;
                                    reg_d0.h[1] = reg_tmp.h[1];
                                    reg_d0.h[0] = reg_tmp.h[0];
                                    reg_tmp.w = 0x287;
                                    reg_d1.h[1] = reg_tmp.h[1];
                                    reg_d1.h[0] = reg_tmp.h[0];
                                    if (*(u16 *)(reg_a6 + 0x2C) == 0) {
                                        reg_tmp.w = 0x2AB;
                                        reg_d0.h[1] = reg_tmp.h[1];
                                        reg_d0.h[0] = reg_tmp.h[0];
                                        reg_tmp.w = 0x29B;
                                        reg_d1.h[1] = reg_tmp.h[1];
                                        reg_d1.h[0] = reg_tmp.h[0];
                                    }
                                    reg_tmp.w = 1;
                                    reg_a6 += 0xA;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp1.w += reg_tmp.w;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp1.h[1];
                                    ENTITY(reg_a6)->y.h = reg_tmp1.h[0];
                                    if (reg_tmp1.w == reg_d0.w) {
                                        ENTITY(reg_a6)->flags.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_53 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 35:                /* switch 1 */
                                reg_d0.w = 3;
                                temp_a1_9 = ENTITY(reg_a6)->flags.b[1];
                                temp_a0_16 = 1 << reg_d0.b[0];
                                if (temp_a1_9 & temp_a0_16) {
                                    ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a1_9 & (~temp_a0_16 & 0xFF));
                                } else {
                                    ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a1_9 | (temp_a0_16 & 0xFF));
                                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x29);
                                    *(u8 *)(reg_a6 + 0x29) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a6 + 0x29) = (u8) *(u16 *)(reg_a6 + 0x28);
                                        ENTITY(reg_a6)->move.b.speed += 1;
                                    }
                                    reg_tmp.w = 1;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                    reg_tmp1.w += reg_tmp.w;
                                    ENTITY(reg_a6)->draw.h = (u16) reg_tmp1.h[1];
                                    ENTITY(reg_a6)->sprite.h = reg_tmp1.h[0];
                                    reg_tmp.w = 0x1AA;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                    if (reg_tmp.w == reg_tmp1.w) {
                                        reg_tmp.w = 0x1A6;
                                        ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
#ifdef DEATH_LABEL
                            case 36:                /* switch 1 */
                                temp_v1_42 = *(u8 *)(reg_a6 + 0x29);
                                if (temp_v1_42 != 0) {
                                    *(u8 *)(reg_a6 + 0x29) = (u8) (temp_v1_42 - 1);
                                    if (*(u8 *)(reg_a6 + 0x29) == 0) {
                                        bullet_target_player_get();
                                        if (cond_flag == 0) {
                                            direction256_to_entity();
                                            if (g_enemy_signal_2 == 0) {
                                                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                                reg_d1.b[0] += 0xB0;
                                            }
                                            reg_d0.h[1] = *(u16 *)(reg_a6 + 0x2C);
                                            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                            reg_d3.w = 0;
                                            reg_d4.w = 0;
                                            bullet_fire256_direct();
                                        }
                                    }
                                }
                                temp_v1_43 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_43 == 0) {
                                    reg_d0.w = 0x297;
                                    reg_d1.w = 0x287;
                                    reg_a6 += 0xA;
                                    reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    if (reg_tmp.w == reg_d0.w) {
                                        ENTITY(reg_a6)->flags.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_43 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
#endif
                            case 2:                 /* switch 1 */
                            case 21:                /* switch 1 */
                                if (g_frame_mod2 != 0) {
                                    reg_a0 = reg_a6 + 0x12;
                                    reg_tmp.h[1] = *(u16 *)reg_a0;
                                    reg_a0 += 2;
                                    reg_tmp.h[0] = *(u16 *)reg_a0;
                                    reg_a0 += 2;
                                    reg_a1 = (u8 *) reg_tmp.w;
                                    reg_d0.h[0] = *(u16 *)reg_a0;
                                    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                                    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)(reg_a0 + 0);
                                    reg_d0.h[0] -= 4;
                                    reg_d0.h[0] &= 0xC;
                                    *(u16 *)reg_a0 = (u16) reg_d0.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
    }
}


void bullet_look_set_tall(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    bullet_frame_from_dir();
}

extern u16 D_0024EEB0[];

void bullet_frame_from_dir(void) {
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_a1 = (u8 *)(D_0024EEB0);
    reg_d1.h[0] = (u16) reg_d1.b[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] >>= 2;
    reg_d1.h[0] &= 0x3E;
    reg_a1 += reg_d1.h[0];
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a0 += reg_d1.h[0];
    reg_d0.h[1] = *(u16 *)reg_a0;
    reg_d0.h[0] = *(u16 *)(reg_a0 + 2);
    ENTITY(reg_a6)->draw.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_d0.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_x_plus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_d0.w += reg_tmp.w;
    ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_d0.h[0];
}

void bullet_look_set_small(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0xFE00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x210;
    bullet_frame_from_dir();
}


void velocity_octant_negate_y_swap(void) {
    u16 value = reg_d2.h[0];
    s32 diff = (value << 16) - value;
    reg_d2.h[0] = diff;
    velocity_octant_swap();
}



void velocity_octant_swap(void) {
    u32 tmp;

    tmp = reg_d2.sw;
    reg_tmp1.sw = tmp;
    reg_d2.sw = reg_d3.sw;
    reg_d3.sw = reg_tmp1.sw;
    velocity_octant_keep();
}

void velocity_octant_keep(void) {
}


void velocity_octant_swap_negate_y(void) {
    reg_tmp1.sw = reg_d2.sw;
    reg_d2.sw = reg_d3.sw;
    reg_d3.sw = reg_tmp1.sw;
    velocity_octant_negate_y();
}

void velocity_octant_negate_y(void) {
    reg_d2.h[0] *= 0xFFFF;
}


void velocity_octant_swap_negate_both(void) {
    reg_tmp1.sw = reg_d2.sw;
    reg_d2.sw = reg_d3.sw;
    reg_d3.sw = reg_tmp1.sw;
    velocity_octant_negate_both();
}


void velocity_octant_negate_both(void) {
    reg_d2.h[0] = (u16)((reg_d2.h[0] << 16) - reg_d2.h[0]);
    velocity_octant_negate_x();
}

void velocity_octant_negate_x(void) {
    reg_d3.h[0] *= 0xFFFF;
}

extern u8 D_00262572[];

void bullet_velocity_from_dir256(void) {
    s32 off;

    reg_d3.h[0] = *(u16 *)(D_0024F0F0 + reg_d1.h[0] * 2);
    off = reg_d3.h[0] * 2;
    reg_d2.w = reg_d0.h[0] * *(u16 *)(D_00262570 + off);
    reg_d3.w = reg_d0.h[0] * *(u16 *)(D_00262572 + off);
    reg_d2.w = (s32)reg_d2.w >> 4;
    reg_d1.h[0] &= 0xC0;
    reg_d3.w = (s32)reg_d3.w >> 4;
    switch (reg_d1.h[0]) {
        case 0x0:
            break;
        case 0x40:
            reg_d2.h[0] *= 0xFFFF;
            break;
        case 0x80:
            reg_d2.h[0] *= 0xFFFF;
            reg_d3.h[0] *= 0xFFFF;
            break;
        case 0xC0:
            reg_d3.h[0] *= 0xFFFF;
            break;
    }
}


void bullet_sprite_emit(void) {
    reg_a1 = (u8 *)(reg_a6 + 2);
    reg_d0.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.w = (u32) ((s32) reg_d0.w >> 6);
    reg_d0.w &= 0x07FF03FF;
    reg_d0.w |= 0x80008000;
    *(u16 *)reg_a4 = reg_d0.h[1];
    reg_a4 += 2;
    *(u16 *)reg_a4 = reg_d0.h[0];
    reg_a4 += 2;
    *(u16 *)reg_a4 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a4 += 2;
    *(u16 *)reg_a4 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a4 += 2;
    *(u16 *)reg_a4 = *(u16 *)reg_a1;
    reg_a4 += 2;
    *(u16 *)reg_a4 = ENTITY(reg_a6)->attr.h;
    reg_a4 += 2;
    bullet_sprite_emit_end();
}

void bullet_sprite_emit_end(void) {
}


void bullet_move_and_emit(void) {
    u32 temp_a1;

    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d0.b[0] += 4;
    reg_d0.h[0] &= 0xF8;
    temp_a1 = reg_d0.h[0];
    reg_d2.h[0] = temp_a1;
    reg_d2.h[0] >>= 1;
    reg_d0.h[0] = temp_a1 + reg_d2.h[0];
    reg_a1 += reg_d0.h[0];
    reg_a0 = reg_a6 + 6;
    reg_d0.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    *(u16 *)reg_a0 += reg_d0.h[0];
    reg_a0 += 2;
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    *(u16 *)reg_a0 += reg_d0.h[0];
    reg_a0 += 2;
    ENTITY(reg_a6)->x.h += reg_d0.h[0];
    *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    reg_tmp.w += reg_d1.w;
    *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    ENTITY(reg_a6)->attr.h |= reg_d0.h[0];
    bullet_sprite_emit();
}

extern u8 D_0024EF30[];

void bullet_move_type_00(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    bullet_move_and_emit();
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x140;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    reg_tmp.w = 0xFE00FF00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x208;
    reg_tmp.w = 0;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_01(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    bullet_move_and_emit();
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x146;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    reg_tmp.w = 0xFE00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x210;
    reg_tmp.w = 1;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

extern u8 D_0024EBC0[];

void bullet_move_type_02(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    bullet_move_and_emit();
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    reg_a0 = D_0024EBC0;
    reg_tmp.w = 0xC000C;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hp.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x26) = 0x101;
    reg_tmp.w = 2;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    bullet_look_set_small_by_dir();
}


void bullet_move_type_03(void) {
    bullet_turn_into_star();
    ENTITY(reg_a6)->misc.h = (u16) *(u16 *)(reg_a6 + 0x30);
    *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
    reg_tmp.w = 0x19E;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 3;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_04(void) {
    bullet_turn_into_star();
    ENTITY(reg_a6)->misc.h = (u16) *(u16 *)(reg_a6 + 0x30);
    *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
    reg_tmp.w = 0x1A2;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 4;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_05(void) {
    bullet_turn_into_star();
    ENTITY(reg_a6)->misc.h = (u16) *(u16 *)(reg_a6 + 0x30);
    *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
    reg_tmp.w = 0x1A6;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 5;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_06(void) {
    bullet_turn_into_star();
    ENTITY(reg_a6)->misc.h = (u16) *(u16 *)(reg_a6 + 0x30);
    *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
    reg_tmp.w = 0x1AA;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 6;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

extern u8 D_0024ED80[];

void bullet_move_type_07(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    bullet_move_and_emit();
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    reg_tmp.w = 3;
    ENTITY(reg_a6)->hit_x_plus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->hp.sh = 0x101;
    reg_tmp.w = 7;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    reg_a0 = D_0024ED80;
    bullet_look_set_tall();
}

void bullet_move_and_emit_small(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    bullet_move_and_emit();
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    reg_tmp.w = 0xFE00FE00;
    ENTITY(reg_a6)->offset_y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x210;
}

void bullet_turn_into_star(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x1B4;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    *(u16 *)(reg_a6 + 0x30) = (u16) ENTITY(reg_a6)->misc.h;
    *(u16 *)(reg_a6 + 0x32) = (u16) *(u16 *)(reg_a6 + 0x20);
    ENTITY(reg_a6)->misc.h = 0U;
    *(u16 *)(reg_a6 + 0x20) = 0U;
}


void bullet_move_type_08(void) {
    bullet_move_and_emit_small();
    reg_tmp.w = 0x1E6;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    reg_tmp.w = 8;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_09(void) {
    bullet_move_and_emit_small();
    reg_tmp.w = 0x1B9;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 9;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_10(void) {
    bullet_move_and_emit_small();
    reg_tmp.w = 0x1BF;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xA;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_11(void) {
    bullet_move_and_emit_small();
    reg_tmp.w = 0x220;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    reg_tmp.w = 0xB;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_12(void) {
    bullet_move_and_emit_small();
    reg_tmp.w = 0x20E;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xC;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_13(void) {
    bullet_move_and_emit_small();
    reg_tmp.w = 0x20E;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xD;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_16(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    bullet_move_and_emit();
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    reg_a0 = D_0024EBC0;
    reg_tmp.w = 0xC000C;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hp.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x26) = 0x101;
    reg_tmp.w = 0x10;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0x29) = 0;
    *(s16 *)(reg_a6 + 0x2A) = 1;
    bullet_look_set_small_by_dir();
}

void bullet_move_type_17(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    bullet_move_and_emit();
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    reg_a0 = D_0024EBC0;
    reg_tmp.w = 0xC000C;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hp.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x26) = 0x101;
    reg_tmp.w = 0x11;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0x29) = 0;
    *(s16 *)(reg_a6 + 0x2A) = 1;
    *(s16 *)(reg_a6 + 0x2C) = 4;
    bullet_look_set_small_by_dir();
}

void bullet_move_type_18(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    bullet_move_and_emit();
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    reg_a0 = D_0024EBC0;
    reg_tmp.w = 0xC000C;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hp.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x26) = 0x101;
    reg_tmp.w = 0x12;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0x29) = 0;
    *(s16 *)(reg_a6 + 0x2A) = 1;
    *(s16 *)(reg_a6 + 0x2C) = 4;
    bullet_look_set_small_by_dir();
}

void bullet_move_type_19(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x283;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    *(u16 *)(reg_a6 + 0x30) = (u16) ENTITY(reg_a6)->misc.h;
    *(u16 *)(reg_a6 + 0x32) = (u16) *(u16 *)(reg_a6 + 0x20);
    ENTITY(reg_a6)->misc.h = 0U;
    *(u16 *)(reg_a6 + 0x20) = 0U;
    reg_tmp.w = 0x13;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_20(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    bullet_move_and_emit();
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x1AE;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    reg_tmp.w = 0xFE00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x210;
    reg_tmp.w = 0x14;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

extern u8 D_0024EDB0[];

void bullet_move_type_21(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    bullet_move_and_emit();
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    reg_a0 = D_0024EDB0;
    reg_tmp.w = 0xC000C;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hp.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x26) = 0x101;
    reg_tmp.w = 0x15;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    bullet_look_set_small_by_dir();
}

void bullet_move_type_22(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x297;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    *(u16 *)(reg_a6 + 0x30) = (u16) ENTITY(reg_a6)->misc.h;
    *(u16 *)(reg_a6 + 0x32) = (u16) *(u16 *)(reg_a6 + 0x20);
    ENTITY(reg_a6)->misc.h = 0U;
    *(u16 *)(reg_a6 + 0x20) = 0U;
    reg_tmp.w = 0x16;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_23(void) {
    bullet_move_and_emit_small();
    reg_tmp.w = 0x220;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    reg_tmp.w = 0x17;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_24(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x297;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    *(u16 *)(reg_a6 + 0x30) = (u16) ENTITY(reg_a6)->misc.h;
    *(u16 *)(reg_a6 + 0x32) = (u16) *(u16 *)(reg_a6 + 0x20);
    ENTITY(reg_a6)->misc.h = 0U;
    *(u16 *)(reg_a6 + 0x20) = 0U;
    reg_tmp.w = 0x18;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_25(void) {
    *(s16 *)(reg_a6 + 0x2C) = 1;
    reg_tmp.w = 0x19;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x283;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
}

extern u8 D_0024EE60[];

void bullet_move_type_26(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    bullet_move_and_emit();
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    reg_tmp.w = 3;
    ENTITY(reg_a6)->hit_x_plus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->hp.sh = 0x101;
    reg_tmp.w = 0x1A;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    reg_a0 = D_0024EE60;
    bullet_look_set_small();
}

extern u16 g_game_frame;

void bullet_move_type_27(void) {
    bullet_turn_into_star();
    reg_tmp.w = 0x19D;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] >>= 2;
    reg_d0.h[0] &= 3;
    do {
        reg_tmp.w = 1;
        reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
        reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
        reg_tmp1.w = (s32) ((s32) reg_tmp1.w + reg_tmp.w);
        ENTITY(reg_a6)->draw.h = (u16) reg_tmp1.h[1];
        ENTITY(reg_a6)->sprite.h = reg_tmp1.h[0];
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_tmp.w = 0x1B;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x30) = 0x20;
}

void bullet_move_type_28(void) {
    *(s16 *)(reg_a6 + 0x28) = 0x1410;
    reg_tmp.w = 0x1C;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x283;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
}

void bullet_move_type_29(void) {
    *(s16 *)(reg_a6 + 0x2C) = 1;
    reg_tmp.w = 0x1D;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x283;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
}


void bullet_move_type_30() {
    bullet_move_and_emit_small();
    reg_tmp.w = 0x220;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    reg_tmp.w = 0x1E;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] -= *(u8 *)(reg_a6 + 0x36);
    bullet_velocity_from_dir256();
    reg_d2.w = (u32) ((s32) reg_d2.w >> 3);
    reg_d3.w = (u32) ((s32) reg_d3.w >> 3);
    *(u16 *)(reg_a6 + 0x30) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x32) = (u16) reg_d3.h[0];
}

void bullet_move_type_31() {
    bullet_move_and_emit_small();
    reg_tmp.w = 0x220;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    reg_tmp.w = 0x1F;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] -= *(u8 *)(reg_a6 + 0x36);
    bullet_velocity_from_dir256();
    reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 3);
    reg_d3.h[0] = (u16) ((s16) reg_d3.h[0] >> 3);
    *(u16 *)(reg_a6 + 0x30) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x32) = (u16) reg_d3.h[0];
}


void bullet_move_type_32(void) {
    bullet_move_and_emit_small();
    reg_tmp.w = 0x1E6;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    reg_tmp.w = 0x20;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_33(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x1B4;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
    *(s16 *)(reg_a6 + 0x2C) = 0x14;
    *(s16 *)(reg_a6 + 0x2E) = 0x101;
    reg_tmp.w = 0x21;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void bullet_move_type_34(void) {
    *(s16 *)(reg_a6 + 0x2C) = 1;
    reg_tmp.w = 0x22;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x283;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    ENTITY(reg_a6)->attr.sb.palette = 0x1A;
}


void bullet_move_type_35(void) {
    bullet_turn_into_star();
    reg_tmp.w = 0x23;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0x1A6;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x28) = 0x404;
    ENTITY(reg_a6)->move.sb.speed = 0;
}

extern u16 D_0024EC80[];

void bullet_look_set_small_by_dir(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0xFE00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x210;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_a1 = (u8 *)(D_0024EC80);
    reg_d0.b[0] += 4;
    reg_d0.h[0] &= 0xF8;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d1.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d1.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.w = (u32) reg_a0;
    ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hit_x_plus.h = (u16) reg_tmp.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    ENTITY(reg_a6)->draw.h = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->hit_x_minus.h -= 4;
}

#ifdef DEATH_LABEL
void bullet_type_24_setup(void) {
    *(u16 *)(reg_a6 + 0x28) = 0x1410;
    reg_tmp.w = 0x24;
    *(u16 *)(reg_a6 + 0x22) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = reg_tmp.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x283;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = reg_tmp.h[0];
    ENTITY(reg_a6)->look.h = 0;
    ENTITY(reg_a6)->attr.b.palette = 0x1A;
}
#endif

s32 fade_in();
s32 settings_notice_layers_setup();
extern u8 D_00269800[];
extern u32 D_0028E964;
extern u16 D_0028E968;
extern u16 D_0028E96C;

void logo_screen_begin(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;

    D_0028E968 = 0xF0;
    save_d0 = reg_d0.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a0 = (u8 *)D_00269800;
    save_d1 = reg_d1.w;
    D_0028E964 = 0;
    D_0028E96C = 0;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    fade_in();
    D_0028E964 = reg_d0.w;
    settings_notice_layers_setup();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

void logo_sprite_draw(void);
void fade_to_black(void);
void fade_release(void);
void fade_is_running(void);
void voice_logo(void);
extern u8 logo_screen_update_table[];
extern u16 D_0028E968;
extern u16 D_0028E96C;

void logo_screen_update(void) {
    u32 sd0, sd1, sd2, sd3, sd4, sd5, sd6, sd7;
    u8 *sa0, *sa1, *sa2, *sa3, *sa4, *sa5, *sa6;

    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    sd2 = reg_d2.w;
    sd3 = reg_d3.w;
    sd4 = reg_d4.w;
    sd5 = reg_d5.w;
    sd6 = reg_d6.w;
    sd7 = reg_d7.w;
    sa0 = reg_a0;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa3 = reg_a3;
    sa4 = reg_a4;
    sa5 = reg_a5;
    sa6 = reg_a6;
    if (D_0028E96C == 0) {
        reg_d0.w = D_0028E964;
        fade_is_running();
        if (cond_flag == 0) {
            fade_release();
            D_0028E96C = 1;
            voice_logo();
        }
    }
    if (D_0028E96C == 1) {
        D_0028E968 -= 1;
        if (D_0028E968 == 0) {
            reg_a0 = (u8 *)logo_screen_update_table;
            fade_to_black();
            D_0028E964 = reg_d0.w;
            D_0028E96C = 2;
        }
    }
    if (D_0028E96C == 2) {
        reg_d0.w = D_0028E964;
        fade_is_running();
        if (cond_flag == 0) {
            fade_release();
            goto block_1;
        }
    }
    logo_sprite_draw();
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    cond_flag = 1;
    return;
block_1:
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    cond_flag = 0;
}

u8 D_00269800[32] = {
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x05, 0x00, 0x1F, 0x00, 0x03, 0x00,
    0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x0C, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x00, 0x00,
};

u8 logo_screen_update_table[32] = {
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x08, 0x00, 0x00, 0x00, 0x1F, 0x00,
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

/* .bss (the compiler lays these out in reverse) */
u8 *D_00299770[4];
#ifdef DEATH_LABEL
u8 g_bullets[67216];
#else
u8 g_bullets[13456];
#endif

/* .sbss (the compiler lays these out in reverse) */
u16 D_0028E96C __attribute__((aligned(4)));
u16 D_0028E968;
u32 D_0028E964;
