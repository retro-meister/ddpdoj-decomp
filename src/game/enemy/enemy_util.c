#include "common.h"
#ifdef DDPDOJ_PC
#include "pc_gameplay_abi.h"
#endif
#include "entity.h"

void ground_step_unused(void) {
}

typedef void (*Fn)(void);
extern u8 *reg_call_target_as_u8_p;
extern u16 entity_draw_by_layer_routines[];

void enemy_variant_offset_a_get(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_a0 = (u8 *)entity_draw_by_layer_routines;
    reg_d0.h[0] <<= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
}

extern u16 D_0025AE50[];

void enemy_variant_offset_b_get(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_a0 = (u8 *)D_0025AE50;
    reg_d0.h[0] <<= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
}

extern u16 sprite_draw_by_layer_routines[];

void enemy_variant_offset_c_get(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_a0 = (u8 *)sprite_draw_by_layer_routines;
    reg_d0.h[0] <<= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
}

extern u16 D_0025AEA8[];

void enemy_variant_word_get(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_a0 = (u8 *)D_0025AEA8;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a0) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
}

extern u16 D_0025AEB8[];

void enemy_variant_timer_a_set(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_a1 = (u8 *)D_0025AEB8;
    reg_d0.h[0] += reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1E) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a1) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
}

extern u16 D_0025AEC8[];

void enemy_variant_timer_b_set(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_a1 = (u8 *)D_0025AEC8;
    reg_d0.h[0] += reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1E) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a1) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
}

void enemy_variant_get(void) {
    reg_d2.h[0] = ENTITY(reg_a6)->misc.h;
}

s32 p1_hyper_gauge_check_full();
s32 binary_to_bcd();
s32 bcd_to_binary();
extern u16 g_p1_stage_misses;
extern u16 g_p1_hyper_gauge;
extern u16 g_p1_hyper_active;
extern u16 g_boss_hits;
extern u16 g_boss_hit_decay_timer;
extern u16 g_p1_hits;
extern u16 g_p1_combo_timer;
extern u8 g_boss_present_b1;

void p1_bee_value_update(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    s64 t;

    reg_d3.h[0] = g_p1_stage_misses;
    reg_d4.h[0] = g_p1_combo_timer;
    reg_d5.h[0] = g_p1_hits;
    if (g_boss_present_b1 & 2) {
        reg_d0.h[0] = g_boss_hits;
        if ((s16) reg_d0.h[0] >= 0) {
            binary_to_bcd();
            reg_d5.w = reg_d2.w;
            reg_d4.h[0] = g_boss_hit_decay_timer;
        } else {
            reg_d4.w = 0;
        }
    }
    if (((s16)g_p1_hyper_active == 0) && ((s16) reg_d4.h[0] != 0)) {
        t = (s64) ((s64) reg_d5.h[0] << 0x30) >> 0x30;
        if ((t != 0) && (t >= 0)) {
            save_d0 = reg_d0.w;
            save_d1 = reg_d1.w;
            save_d2 = reg_d2.w;
            save_d3 = reg_d3.w;
            save_d4 = reg_d4.w;
            save_d5 = reg_d5.w;
            if ((s32) (reg_d5.h[0] & 0xFFFF) > 0x200) {
                reg_d5.h[0] = 0x200;
            }
            reg_d0.h[0] = reg_d5.h[0];
            bcd_to_binary();
            reg_d0.w = 0;
loop_11:
            reg_tmp2.w = 0;
            reg_tmp.w = 0;
            reg_tmp.h[0] = 0x14;
            reg_tmp2.h[0] = reg_d2.h[0];
            reg_tmp2.w -= reg_tmp.w;
            reg_d2.h[0] -= 0x14;
            if (reg_tmp2.h[1] == 0) {
                reg_d0.h[0] += 0x48;
                goto loop_11;
            }
            g_p1_hyper_gauge += reg_d0.h[0];
            p1_hyper_gauge_check_full();
            reg_d0.w = save_d0;
            reg_d1.w = save_d1;
            reg_d2.w = save_d2;
            reg_d3.w = save_d3;
            reg_d4.w = save_d4;
            reg_d5.w = save_d5;
        }
    }
}

s32 p2_hyper_gauge_check_full();
extern u16 g_p2_stage_misses;
extern u16 g_p2_hyper_gauge;
extern u16 g_p2_hyper_active;
extern u16 g_p2_hits;
extern u16 g_p2_combo_timer;

void p2_bee_value_update(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    s64 t;

    reg_d3.h[0] = g_p2_stage_misses;
    reg_d4.h[0] = g_p2_combo_timer;
    reg_d5.h[0] = g_p2_hits;
    if (g_boss_present_b1 & 2) {
        reg_d0.h[0] = g_boss_hits;
        if ((s16) reg_d0.h[0] >= 0) {
            binary_to_bcd();
            reg_d5.w = reg_d2.w;
            reg_d4.h[0] = g_boss_hit_decay_timer;
        } else {
            reg_d4.w = 0;
        }
    }
    if (((s16)g_p2_hyper_active == 0) && ((s16) reg_d4.h[0] != 0)) {
        t = (s64) ((s64) reg_d5.h[0] << 0x30) >> 0x30;
        if ((t != 0) && (t >= 0)) {
            save_d0 = reg_d0.w;
            save_d1 = reg_d1.w;
            save_d2 = reg_d2.w;
            save_d3 = reg_d3.w;
            save_d4 = reg_d4.w;
            save_d5 = reg_d5.w;
            if ((s32) (reg_d5.h[0] & 0xFFFF) > 0x200) {
                reg_d5.h[0] = 0x200;
            }
            reg_d0.h[0] = reg_d5.h[0];
            bcd_to_binary();
            reg_d0.w = 0;
loop_11:
            reg_tmp2.w = 0;
            reg_tmp2.h[0] = reg_d2.h[0];
            reg_tmp2.w -= 0x14;
            reg_d2.h[0] -= 0x14;
            if (reg_tmp2.h[1] == 0) {
                reg_d0.h[0] += 0x48;
                goto loop_11;
            }
            g_p2_hyper_gauge += reg_d0.h[0];
            p2_hyper_gauge_check_full();
            reg_d0.w = save_d0;
            reg_d1.w = save_d1;
            reg_d2.w = save_d2;
            reg_d3.w = save_d3;
            reg_d4.w = save_d4;
            reg_d5.w = save_d5;
        }
    }
}

s32 score_add_masked();
extern u16 bee_collected_table[];
extern u16 bee_collected_table_2[];
extern u16 g_bee_value_step;
extern u16 g_stage_bees_collected;

void bee_collected(void) {
    u32 t;
    s32 t2;

    reg_d1.h[0] = g_bee_value_step;
    g_stage_bees_collected += 1;
    if (g_stage_bees_collected != 0xA) goto next_1;
    if ((s16) reg_d3.h[0] != 0) goto next_1;
    ENTITY(reg_a6)->flags.b[1] |= 0x20;
    g_bee_value_step += 4;
next_1:
    reg_a0 = (u8 *)bee_collected_table;
    reg_d0.w = *(u32 *)((u8 *)bee_collected_table + (reg_d1.h[0] & ~3));
    if (!(ENTITY(reg_a6)->flags.b[1] & 0x20)) goto next_2;
    reg_d0.w += reg_d0.w;
next_2:
    reg_a0 = (u8 *)bee_collected_table_2;
    ENTITY(reg_a6)->hit_y_plus.h = (reg_d1.h[0]) ? *(u16 *)(reg_a0 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->hit_y_minus.h = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    if ((s16) reg_d4.h[0] == 0) goto next_5;
    if ((s16) reg_d5.h[0] == 0) goto next_5;
    if ((s16) reg_d5.h[0] < 0) goto next_5;
    ENTITY(reg_a6)->misc.h = reg_d5.h[0];
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d4.w = 3;
loop_3:
    reg_tmp3.w = 0;
    reg_d3.w = 0xF;
    reg_d3.h[0] &= reg_d5.h[0];
    reg_tmp3.h[0] = reg_d3.h[0];
    reg_d3.h[0] -= 1;
    reg_tmp3.w -= 1;
    if (reg_tmp3.h[1] != 0) goto next_4;
loop_4:
    score_add_masked();
    t2 = reg_d3.h[0] - 1;
    reg_d3.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto loop_4;
next_4:
    reg_d5.h[0] >>= 4;
    reg_d0.w <<= 4;
    t = reg_d4.h[0] - 1;
    reg_d4.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_3;
    return;
next_5:
    ENTITY(reg_a6)->misc.h = 1;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    score_add_masked();
}

#pragma push
#pragma opt_propagation off
extern u8 g_ground_no_draw;
extern void (*reg_call_target_as_fn)(void);

void scenery_draw(void (*callback)(void))
{
    if (g_ground_no_draw == 0) {
        const u16 *state = (const u16 *)((void *)reg_a6);

        reg_d1.h[1] = state[1];
        reg_d1.h[0] = state[2];
        reg_d3.h[0] = state[10];
        reg_d2.h[1] = state[8];
        reg_d2.h[0] = state[9];
        reg_d4.w = 0;
        reg_d4.h[0] = state[6];
        reg_call_target_as_fn = callback;
        reg_call_target_as_fn();
    }
}
#pragma pop

void entity_release(void) {
    ENTITY(reg_a6)->flags.b[1] = 0;
}

void boss_level_get_from_58(void) {
#ifndef DDPDOJ_PC
    void boss_level_get(void);
#endif
    *(u16 *)&reg_d0 = 0x58;
    boss_level_get();
}

void boss_level_get_from_78(void) {
#ifndef DDPDOJ_PC
    s32 boss_level_get();
#endif
    reg_d0.h[0] = 0x78;
    boss_level_get();
    reg_d0.w = 4;
}


void enemy_set_entity_count(u16 val) {
    *(u16 *)(reg_a5 + 4) = val;
}


void enemy_switch_target_player(void) {
    u8 *flags_ptr;
    u8 flags;

    flags_ptr = reg_a5 + 2;
    flags = flags_ptr[0];
    if (flags & 1) {
        flags_ptr[0] = flags & 0xFE;
        return;
    }
    flags_ptr[0] = flags | 1;
}

#ifndef DDPDOJ_PC
s32 enemy_remove();                           /* extern */
#endif
s32 entity_check_bounds();                            /* extern */

void heli_bounds_check(void) {
    entity_check_bounds();
    if (cond_flag != 0) {
        if (*(u8 *)(reg_a5 + 0x17) != 0) {
            enemy_remove();
            cond_flag = 1;
            return;
        }
        goto block_4;
    }
    *(u8 *)(reg_a5 + 0x17) = 1U;
block_4:
    cond_flag = 0;
}
