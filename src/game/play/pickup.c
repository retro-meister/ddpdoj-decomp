#include "common.h"
#include "black_label.h"
#ifdef DDPDOJ_PC
#include "arcade_gameplay.h"
#else
void bullet_fire256_direct(void);
s32 entity_draw_with_special_items();
s32 rng_next_bit();
s32 sprite_draw_with_special_items();
s32 velocity_from_direction();
#endif
#include "layers.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

extern void (*pickups_update_loop_table[20])();
extern void (*pickup_spawn_init_table[20])();
extern void *pickup_init_routines[20];

void pickup_spawn_variant(void);
void pickup_spawn_plain(void);
void pickup_spawn(void);
void pickups_update_loop(void);
void pickup_spawn_init(void);
void pickup_init_jitter_small(void);
void pickup_init_jitter(void);
void pickup_init_to_player1(void);
void pickup_init_to_target(void);
void pickup_collected_begin(void);
void pickup_collected_update(void);
void pickup_collected_update_blinking(void);
void pickup_draw_value_large(void);
void pickup_draw_value(void);
void bullet_fire_loop2_double();
void bullet_fire_loop2_3way();
void bullet_fire_direct(void);
void bullet_spawn(void);
void bullet_position_offset_add(void);
void bullet_fire256_loop2_double();
void bullet_fire256_loop2_3way();
void bullet_spawn256(void);
void bullet_type_setup_32(void);
void bullet_type_setup_31(void);

extern u16 g_frame_mod2;
extern u16 g_bullet_count;

#ifdef DDPDOJ_PC
void pickup_draw_alternating(void) {
    u16 arg0;
#else
void pickup_draw_alternating(u16 arg0) {
    extern void entity_draw_with_special_items(u16);
#endif
    if (g_bullet_count >= 0x34) {
        reg_d0.w = 1;
        reg_d0.h[0] &= reg_d7.h[0];
        arg0 = g_frame_mod2;
        if (arg0 == reg_d0.h[0]) {
            return;
        }
    }
    ARCADE_REGISTER_CALL(entity_draw_with_special_items, arg0);
}


void pickup_draw_when_crowded(void) {
    u16 t;

    if (g_bullet_count < 35) goto call;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x24);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x26);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d2.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] -= reg_d2.h[0];
    t = reg_d0.h[0];
    if (((s64) ((s64) t << 0x30) >> 0x30) < 0) {
        reg_d0.h[0] = (t << 16) - t;
    }
    if (reg_d0.h[0] < 0x600) goto call;
    reg_d0.w = 1;
    reg_d0.h[0] &= reg_d7.h[0];
    if (g_frame_mod2 != reg_d0.h[0]) {
call:
        entity_draw_with_special_items();
        return;
    }
}

extern u16 g_side_scroll_x[];

void pickup_bounds_check(void) {
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += g_side_scroll_x[0];
    reg_tmp1.h[0] = 0x9000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7FFF + 0x1001;
    if (reg_tmp.h[1] == 0) {
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7800;
        reg_tmp.w = reg_d0.w;
        reg_d0.h[1] = reg_d0.h[0];
        reg_d0.h[0] = reg_tmp.h[1];
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x800;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.sw;
        reg_d0.h[0] += 0x7800;
    }
    cond_flag = 0;
    switch (reg_tmp.h[1]) {
    case 0:
        break;
    default:
        cond_flag = 1;
    }
}

extern u16 g_enemies_stopped;
void pickup_follow_layer_b(void) {
    if (g_enemies_stopped == 0) {
        reg_d0.h[0] = g_layer_b_shift[0];
        *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    }
}

void bullet_release(void) {
    reg_d0.w = 0;
    *(u16 *)reg_a6 = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 2) = (u16) reg_d0.h[0];
    g_bullet_count -= 1;
}

extern u16 g_p2_stage_stars_small;
extern u16 g_p1_stage_stars_small;

void stage_stars_small_add(void) {
    (*(u16 **)&reg_a0) = &g_p1_stage_stars_small;
    if (!(reg_d1.w & 0x1000)) {
        (*(u16 **)&reg_a0) = &g_p2_stage_stars_small;
    }
    *(*(u16 **)&reg_a0) += reg_d0.h[0];
    if ((s32) *((u16 *)reg_a0) >= 0x3E8) {
        *(*(u16 **)&reg_a0) = 0x3E7;
    }
}

extern u16 g_p2_stage_stars_large;
extern u16 g_p1_stage_stars_large;

void stage_stars_large_add(void) {
    (*(u16 **)&reg_a0) = &g_p1_stage_stars_large;
    if (!(reg_d1.w & 0x1000)) {
        (*(u16 **)&reg_a0) = &g_p2_stage_stars_large;
    }
    *(*(u16 **)&reg_a0) += reg_d0.h[0];
    if ((s32) *((u16 *)reg_a0) >= 0x3E8) {
        *(*(u16 **)&reg_a0) = 0x3E7;
    }
}

void p1_stage_stars_small_add(void) {
    (*(u16 **)&reg_a0) = &g_p1_stage_stars_small;
    *(*(u16 **)&reg_a0) += reg_d0.h[0];
    if ((s32) *((u16 *)reg_a0) >= 0x3E8) {
        *(*(u16 **)&reg_a0) = 0x3E7;
    }
}

void p2_stage_stars_small_add(void) {
    (*(u16 **)&reg_a0) = &g_p2_stage_stars_small;
    *(*(u16 **)&reg_a0) += reg_d0.h[0];
    if ((s32) *((u16 *)reg_a0) >= 0x3E8) {
        *(*(u16 **)&reg_a0) = 0x3E7;
    }
}

extern u16 g_frame_mod8;

void pickup_accelerate(void) {
    if (g_frame_mod8 == 0) {
        if (g_enemies_stopped == 0) {
            ENTITY(reg_a6)->move.b.speed += 1;
        }
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d1.w = 0x3F;
        reg_d1.b[0] &= ENTITY(reg_a6)->move.b.dir;
        velocity_from_direction();
        *(u16 *)(reg_a6 + 0x20) = reg_d2.h[0];
        *(u16 *)(reg_a6 + 0x22) = reg_d3.h[0];
    }
    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x20);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x22);
    ENTITY(reg_a6)->x.h += reg_d2.h[0];
    reg_tmp2.w = reg_d2.w;
    reg_d2.h[1] = reg_d2.h[0];
    reg_d2.h[0] = reg_tmp2.h[1];
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
}

void pickup_spin_frames_0(void) {
    ENTITY(reg_a6)->hp.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)->hp.b[1] < 0) {
        ENTITY(reg_a6)->hp.b[1] = (u8) ENTITY(reg_a6)->hp.b[0];
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBCF) {
            reg_tmp.w = 0xBBF;
            *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        }
    }
}

void pickup_spin_frames_1(void) {
    ENTITY(reg_a6)->hp.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)->hp.b[1] < 0) {
        ENTITY(reg_a6)->hp.b[1] = (u8) ENTITY(reg_a6)->hp.b[0];
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBDF) {
            reg_tmp.w = 0xBCF;
            *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        }
    }
}

void pickup_spin_frames_2(void) {
    ENTITY(reg_a6)->hp.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)->hp.b[1] < 0) {
        ENTITY(reg_a6)->hp.b[1] = (u8) ENTITY(reg_a6)->hp.b[0];
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBEF) {
            reg_tmp.w = 0xBDF;
            *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        }
    }
}

void pickup_spin_frames_3(void) {
    ENTITY(reg_a6)->hp.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)->hp.b[1] < 0) {
        ENTITY(reg_a6)->hp.b[1] = (u8) ENTITY(reg_a6)->hp.b[0];
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBFF) {
            reg_tmp.w = 0xBEF;
            *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        }
    }
}

void velocity_from_dir256(void);
void direction256_to_entity(void);

void pickup_home_on_target(void) {
    if (ENTITY(reg_a6)->misc.b.user == 0) {
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x26);
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        direction256_to_entity();
        ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
        reg_d0.w = 0x40;
        velocity_from_dir256();
        *(u16 *)(reg_a6 + 0x20) = reg_d2.h[0];
        *(u16 *)(reg_a6 + 0x22) = reg_d3.h[0];
        ENTITY(reg_a6)->misc.b.user = 1;
    }
    reg_d0.h[0] = g_frame_mod8;
    if ((reg_d0.b[0] &= ENTITY(reg_a6)->move.b.speed) == 0) {
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x26);
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        if (*(s16 *)reg_a0 >= 0) {
            bullet_release();
            return;
        }
        direction256_to_entity();
        if (ENTITY(reg_a6)->move.b.dir != reg_d1.b[0]) {
            ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
            reg_d0.w = 0x40;
            velocity_from_dir256();
            *(u16 *)(reg_a6 + 0x20) = reg_d2.h[0];
            *(u16 *)(reg_a6 + 0x22) = reg_d3.h[0];
        }
    }
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d3.h[0] = *(u16 *)(reg_a6 + 0x22);
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
}

extern u16 g_bee_value_step;
extern u16 g_stage_bees_collected;
extern u8 g_pickups[];
void pickups_clear(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    do {
        temp_a2 = g_pickups + var_a1;
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0xC08);
    g_p2_stage_stars_small = 0;
    g_p2_stage_stars_large = 0;
    g_p1_stage_stars_small = 0;
    g_p1_stage_stars_large = 0;
    g_bee_value_step = 0;
    g_stage_bees_collected = 0;
    g_bullet_count = 0;
}

extern u16 g_stage_bees_collected;

void p1_stage_counts_reset(void) {
    reg_d0.w = 0;
    g_stage_bees_collected = reg_d0.h[0];
    g_p1_stage_stars_large = reg_d0.h[0];
    g_p1_stage_stars_small = reg_d0.h[0];
}

void p2_stage_counts_reset(void) {
    reg_d0.w = 0;
    g_stage_bees_collected = reg_d0.h[0];
    g_p2_stage_stars_large = reg_d0.h[0];
    g_p2_stage_stars_small = reg_d0.h[0];
}

void stage_counts_reset(void) {
    reg_d0.w = 0;
    g_stage_bees_collected = reg_d0.h[0];
    g_p1_stage_stars_large = reg_d0.h[0];
    g_p1_stage_stars_small = reg_d0.h[0];
    g_p2_stage_stars_large = reg_d0.h[0];
    g_p2_stage_stars_small = reg_d0.h[0];
}


void bee_counts_reset(void) {
    g_bee_value_step = 0;
    stage_counts_reset();
}


void pickup_spawn_variant_here(void) {
    reg_d1.w = 0;
    pickup_spawn_variant();
}

void pickup_spawn_variant(void) {
    reg_d2.h[0] = (u8)reg_d2.h[0];
    reg_d2.h[0] <<= 2;
    pickup_spawn();
}


void pickup_spawn_here(void) {
    reg_d1.w = 0;
    pickup_spawn_plain();
}


void pickup_spawn_plain(void) {
    reg_d2.sw = 0;
    pickup_spawn();
}

extern u8 *D_0028DE8C;
extern u32 D_0028DE90;

void pickup_spawn(void) {
    u32 tmp;

    D_0028DE90 = reg_d7.w;
    D_0028DE8C = reg_a0;
    reg_a0 = (u8 *) ((u16 *)g_pickups);
    reg_d7.h[0] = 0x45;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    pickup_spawn_init();
    cond_flag = 0;
    return;
next_1:
    reg_a0 += 0x2C;
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    cond_flag = 1;
    reg_d7.w = D_0028DE90;
    reg_a0 = D_0028DE8C;
}

extern u16 g_side_scroll_step[];

void pickups_update(void) {
    reg_d7.h[0] = g_bullet_count;
    if (reg_d7.h[0] != 0) {
        reg_a6 = (u8 *)((s32 *)g_pickups);
        reg_d7.w -= 1;
        reg_d6.h[0] = g_side_scroll_step[0];
        pickups_update_loop();
    }
}

typedef void (*Fn)();


void pickups_update_loop(void) {
    u32 t1;

loop_1:
    reg_d1.h[0] = ENTITY(reg_a6)->flags.h;
    if (reg_d1.h[0] == 0) {
        reg_a6 += 0x2C;
        goto loop_1;
    }
    ENTITY(reg_a6)->x.h -= reg_d6.h[0];
    reg_d0.w = 0x7C;
    reg_d0.h[0] &= reg_d1.h[0];
    if ((s8) reg_d1.b[0] < 0) {
        pickup_collected_update();
        return;
    }
#ifdef DDPDOJ_PC
    pickups_update_loop_table[reg_d0.h[0] / 4]();
#else
    ((Fn)*(u32 *)((u8 *)((u8 *)pickups_update_loop_table) + (reg_d0.h[0] & ~3)))();
#endif
    reg_a6 += 0x2C;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64) ((s64) (t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}

s32 sfx_score_item_pickup();
s32 score_add_masked();

void pickup_collect_score_item() {
    reg_d0.w = 1;
    stage_stars_small_add();
    reg_tmp.w = 0x50000;
    ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
    reg_d0.w = 0x50;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    score_add_masked();
    sfx_score_item_pickup();
    ENTITY(reg_a6)->flags.b[0] = 0x84;
    pickup_collected_begin();
}


void score_pickup_kind0(void) {
    void pickup_draw_alternating(void);
    void bullet_release(void);
    void pickup_accelerate(void);
    void pickup_spin_frames_0(void);
    if ((u16)(reg_d1.h[0] &= 0x1800) != 0) {
        pickup_collect_score_item();
        return;
    }
    pickup_spin_frames_0();
    pickup_accelerate();
    if (0 <= (s64)ENTITY(reg_a6)->y.sh) {
        pickup_draw_alternating();
    } else {
        bullet_release();
    }
}



s32 p1_bee_value_update();
s32 p2_bee_value_update();
s32 bee_collected();
s32 sfx_bee_pickup();
extern u8 D_00269490[];
extern u8 *reg_call_target_as_u8_p;

void score_pickup_bee(void) {
#ifndef DDPDOJ_PC
    s32 bullet_release();
#endif
    u32 t;

    if (reg_d1.w & 1) {
        pickup_collected_update_blinking();
        return;
    }
    reg_d0.w = 0;
    if (reg_d1.w & 0x1000) goto next_1;
    if (!(reg_d1.w & 0x800)) goto next_3;
    p2_bee_value_update();
    goto next_2;
next_1:
    p1_bee_value_update();
next_2:
    bee_collected();
    sfx_bee_pickup();
    ENTITY(reg_a6)->flags.b[0] |= 1;
    pickup_collected_begin();
    return;
block_1:
    bullet_release();
    return;
next_3:
    reg_tmp.w = 0xBBD;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    ENTITY(reg_a6)->hp.h -= 1;
    if ((s16) ENTITY(reg_a6)->hp.h >= 0) goto next_4;
    ENTITY(reg_a6)->hp.h = 2;
    reg_tmp.w = 0xBBE;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
next_4:
    pickup_bounds_check();
    if (cond_flag != 0) goto block_1;
    reg_d0.w = 4;
    reg_d1.h[0] &= reg_d0.h[0];
    t = reg_d1.h[0] ^ reg_d0.h[0];
    reg_d1.h[0] = t;
    if (t & 0xFFFF) goto next_5;
    pickup_follow_layer_b();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    return;
next_5:
    ENTITY(reg_a6)->y.h -= 0x60;
    ENTITY(reg_a6)->misc.b.draw_layer -= 1;
    if (ENTITY(reg_a6)->misc.b.draw_layer != 0) goto next_6;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->misc.b.user;
    reg_a0 = (u8 *)(D_00269490);
    reg_a0 += reg_d0.h[0];
    ENTITY(reg_a6)->misc.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
next_6:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x22);
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    ENTITY(reg_a6)->x.h += reg_d1.h[0];
    entity_draw_with_special_items();
}

extern u8 g_boss_present_b1;

void score_pickup_ground_star_small(void) {
#ifndef DDPDOJ_PC
    s32 bullet_release();
#endif
    u32 t;

    if ((s16)(g_boss_present_b1) < 0) goto next_2;
    t = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t;
    if (!(t & 0xFFFF)) goto next_1;
    reg_d0.w = 1;
    stage_stars_large_add();
    reg_tmp.w = 0x50000;
    ENTITY(reg_a6)->hit_y_plus.h = reg_tmp.h[1];
    ENTITY(reg_a6)->hit_y_minus.h = reg_tmp.h[0];
    reg_d0.w = 0x50;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    score_add_masked();
    sfx_score_item_pickup();
    ENTITY(reg_a6)->flags.b[0] = 0x84;
    pickup_collected_begin();
    return;
next_2:
    bullet_release();
    return;
next_1:
    pickup_follow_layer_b();
    pickup_bounds_check();
    if (cond_flag != 0) goto next_2;
    ENTITY(reg_a6)->hp.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)->hp.b[1] < 0) {
        ENTITY(reg_a6)->hp.b[1] = ENTITY(reg_a6)->hp.b[0];
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
        if (reg_tmp.w == 0xC0F) {
            reg_tmp.w = 0xBFF;
            *(u16 *)reg_a0 = reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
            ENTITY(reg_a6)->hp.b[1] = 1;
        }
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
}

s32 sfx_score_item_pickup_2();

void score_pickup_ground_star_large(void) {
#ifndef DDPDOJ_PC
    s32 bullet_release();
#endif
    u32 t;

    if ((s16)(g_boss_present_b1) < 0) goto next_2;
    t = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t;
    if (!(t & 0xFFFF)) goto next_1;
    reg_d0.w = 2;
    stage_stars_large_add();
    reg_tmp.w = 0x10008;
    ENTITY(reg_a6)->hit_y_plus.h = reg_tmp.h[1];
    ENTITY(reg_a6)->hit_y_minus.h = reg_tmp.h[0];
    reg_d0.w = 0x1000;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    score_add_masked();
    sfx_score_item_pickup_2();
    ENTITY(reg_a6)->flags.b[0] = 0x84;
    pickup_collected_begin();
    return;
next_2:
    bullet_release();
    return;
next_1:
    pickup_follow_layer_b();
    pickup_bounds_check();
    if (cond_flag != 0) goto next_2;
    ENTITY(reg_a6)->hp.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)->hp.b[1] < 0) {
        ENTITY(reg_a6)->hp.b[1] = ENTITY(reg_a6)->hp.b[0];
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
        if (reg_tmp.w == 0xC2F) {
            reg_tmp.w = 0xC1F;
            *(u16 *)reg_a0 = reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
            ENTITY(reg_a6)->hp.b[1] = 2;
        }
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
}


void score_pickup_air_star_medium(void) {
#ifndef DDPDOJ_PC
    s32 pickup_draw_alternating();
    s32 bullet_release();
    s32 pickup_accelerate();
#endif
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 2;
        stage_stars_small_add();
        reg_tmp.w = 0x10004;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x100;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        score_add_masked();
        sfx_score_item_pickup();
        ENTITY(reg_a6)->flags.b[0] = 0x84;
        pickup_collected_begin();
        return;
    }
    pickup_spin_frames_1();
    pickup_accelerate();
    if (ENTITY(reg_a6)->y.sh >= -0x200) {
        pickup_draw_alternating();
        return;
    }
    bullet_release();
}


void score_pickup_air_star_large(void) {
#ifndef DDPDOJ_PC
    s32 pickup_draw_alternating();
    s32 bullet_release();
    s32 pickup_accelerate();
#endif
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 4;
        stage_stars_small_add();
        reg_tmp.w = 0x50004;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        score_add_masked();
        sfx_score_item_pickup();
        ENTITY(reg_a6)->flags.b[0] = 0x84;
        pickup_collected_begin();
        return;
    }
    pickup_spin_frames_2();
    pickup_accelerate();
    if (ENTITY(reg_a6)->y.sh >= -0x400) {
        pickup_draw_alternating();
        return;
    }
    bullet_release();
}


void score_pickup_air_star_huge(void) {
#ifndef DDPDOJ_PC
    s32 pickup_draw_alternating();
    s32 bullet_release();
    s32 pickup_accelerate();
#endif
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 8;
        stage_stars_small_add();
        reg_tmp.w = 0x10008;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        score_add_masked();
        sfx_score_item_pickup_2();
        ENTITY(reg_a6)->flags.b[0] = 0x84;
        pickup_collected_begin();
        return;
    }
    pickup_spin_frames_3();
    pickup_accelerate();
    if (ENTITY(reg_a6)->y.sh >= -0x600) {
        pickup_draw_alternating();
        return;
    }
    bullet_release();
}


void score_pickup_p1_homing_star_small() {
#ifndef DDPDOJ_PC
    s32 bullet_release();
    s32 pickup_spin_frames_0();
#endif
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 1;
        p1_stage_stars_small_add();
        reg_tmp.w = 0x50000;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x50;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        score_add_masked();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    pickup_home_on_target();
    pickup_spin_frames_0();
    pickup_draw_when_crowded();
}

void score_pickup_p1_homing_star_medium() {
#ifndef DDPDOJ_PC
    s32 bullet_release();
#endif
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 2;
        p1_stage_stars_small_add();
        reg_tmp.w = 0x10004;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x100;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        score_add_masked();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    pickup_home_on_target();
    pickup_spin_frames_1();
    pickup_draw_when_crowded();
}

void score_pickup_p1_homing_star_large() {
#ifndef DDPDOJ_PC
    s32 bullet_release();
#endif
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 4;
        p1_stage_stars_small_add();
        reg_tmp.w = 0x50004;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        score_add_masked();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    pickup_home_on_target();
    pickup_spin_frames_2();
    pickup_draw_when_crowded();
}

void score_pickup_p1_homing_star_huge() {
#ifndef DDPDOJ_PC
    s32 bullet_release();
#endif
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 8;
        p1_stage_stars_small_add();
        reg_tmp.w = 0x10008;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        score_add_masked();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    pickup_home_on_target();
    pickup_spin_frames_3();
    pickup_draw_when_crowded();
}


void score_pickup_p2_homing_star_small() {
#ifndef DDPDOJ_PC
    s32 bullet_release();
    s32 pickup_spin_frames_0();
#endif
    if (reg_d1.w & 0x800) {
        reg_d0.w = 1;
        p2_stage_stars_small_add();
        reg_tmp.w = 0x50000;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x50;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        score_add_masked();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    pickup_home_on_target();
    pickup_spin_frames_0();
    pickup_draw_when_crowded();
}

void score_pickup_p2_homing_star_medium() {
#ifndef DDPDOJ_PC
    s32 bullet_release();
#endif
    if (reg_d1.w & 0x800) {
        reg_d0.w = 2;
        p2_stage_stars_small_add();
        reg_tmp.w = 0x10004;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x100;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        score_add_masked();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    pickup_home_on_target();
    pickup_spin_frames_1();
    pickup_draw_when_crowded();
}

void score_pickup_p2_homing_star_large() {
#ifndef DDPDOJ_PC
    s32 bullet_release();
#endif
    if (reg_d1.w & 0x800) {
        reg_d0.w = 4;
        p2_stage_stars_small_add();
        reg_tmp.w = 0x50004;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        score_add_masked();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    pickup_home_on_target();
    pickup_spin_frames_2();
    pickup_draw_when_crowded();
}

void score_pickup_p2_homing_star_huge() {
#ifndef DDPDOJ_PC
    s32 bullet_release();
#endif
    if (reg_d1.w & 0x800) {
        reg_d0.w = 8;
        p2_stage_stars_small_add();
        reg_tmp.w = 0x10008;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        score_add_masked();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    pickup_home_on_target();
    pickup_spin_frames_3();
    pickup_draw_when_crowded();
}

extern u32 D_0028DE94;

void pickup_spawn_cancel(void) {
    reg_d1.w = D_0028DE94;
    g_bullet_count -= 1;
    (*(s16 *)((u8 *)(reg_a0) + (-6))) = 0;
    cond_flag = 0;
    reg_d7.w = D_0028DE90;
    reg_a0 = ((void *)D_0028DE8C);
}

#ifdef DDPDOJ_PC
extern void (*entity_draw_layer_routines[8])(void);
#else
extern u8 entity_draw_layer_routines_as_u8_a[];
#endif

void pickup_spawn_init(void) {
    u8 *save_a1;

#ifdef DDPDOJ_PC
    g_bullet_count += 1;
    reg_a3 = pickup_init_routines[reg_d0.h[0] / 4];
#else
    reg_a3 = (u8 *)((u8 *)pickup_init_routines);
    g_bullet_count += 1;
    reg_a3 = *(u8 **) (((u8 *)pickup_init_routines) + (reg_d0.h[0] & ~3));
#endif
    *(u16 *) reg_a0 = reg_d0.h[0];
    *(u16 *) reg_a0 |= 0x8000;
    reg_a0 += 2;
    D_0028DE94 = reg_d1.w;
    reg_tmp1.h[1] = *(u16 *) (reg_a6 + 2);
    reg_tmp1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.w += reg_tmp1.w;
    reg_d1.h[0] += (s32) g_side_scroll_step[0];
    *(u16 *) reg_a0 = reg_d1.h[1];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0xAC00;
    reg_d1.h[0] += 0xE00;
    reg_d1.h[0] += (s32) g_side_scroll_x[0];
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_tmp1.w += reg_tmp.w;
    reg_d1.h[0] += 0xAC00;
    if (reg_tmp1.h[1] != 0) {
        pickup_spawn_cancel();
        return;
    }
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x6000;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp1.w = 0;
    reg_d1.h[0] += 0x800;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] += 0x6000;
    reg_tmp1.w += (s32) reg_tmp.w;
    if (reg_tmp1.h[1] != 0) {
        pickup_spawn_cancel();
        return;
    }
    reg_d1.w = D_0028DE94;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a0 += 2;
    reg_a0 -= 0x1E;
    save_a1 = reg_a1;
#ifdef DDPDOJ_PC
    Fn *layer = &entity_draw_layer_routines[reg_d2.h[0] / 4];
    reg_a1 = (u8 *)layer;
    STORE_ARCADE_ADDRESS_DIRECT((u16 *)(reg_a0 + 0x28), *layer);
    pickup_spawn_init_table[reg_d0.h[0] / 4]();
#else
    reg_a1 = (u8 *)entity_draw_layer_routines_as_u8_a;
    reg_a1 += reg_d2.h[0];
    *(u16 *) (reg_a0 + 0x28) = *(u16 *) (reg_a1 + 2);
    *(u16 *) (reg_a0 + 0x2A) = *(u16 *) (reg_a1 + 0);
    ((Fn) *(u32 *) (((u8 *)pickup_spawn_init_table) + (reg_d0.h[0] & ~3)))();
#endif
    reg_a1 = save_a1;
    reg_d7.w = D_0028DE90;
    reg_a0 = D_0028DE8C;
}

s32 rng_next_unsigned();
extern u16 pickup_start_offsets_3[];

void pickup_init_scatter_3(void) {
    u8 *sa1;

    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x1A) = 0x420;
    rng_next_unsigned();
    reg_d0.h[0] &= 0xE;
    sa1 = reg_a1;
    reg_d1.w = 0;
    reg_a1 = (u8 *)pickup_start_offsets_3;
    reg_a1 += reg_d0.h[0];
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 = sa1;
    reg_tmp1.h[1] = *(u16 *)(reg_a0 + 0xA);
    reg_tmp1.h[0] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp1.w += reg_d1.w;
    *(u16 *)(reg_a0 + 0xA) = reg_tmp1.h[1];
    *(u16 *)(reg_a0 + 0xC) = reg_tmp1.h[0];
    pickup_init_jitter_small();
}

s32 rng_next_0_to_3();
void pickup_init_jitter_small(void) {
    rng_next_0_to_3();
    reg_d0.h[0] >>= 1;
    pickup_init_jitter();
}


void pickup_init_jitter(void) {
    u32 save_d0;
    u32 save_d2;
    u32 save_d3;
    u8 *temp_a1;

    *(u8 *)(reg_a0 + 0x1B) += reg_d0.b[0];
    save_d0 = reg_d0.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    rng_next_bit();
    reg_d0.h[0] += 1;
    reg_d1.h[0] = reg_d0.h[0];
    rng_next_0_to_3();
    reg_d0.b[0] -= reg_d1.b[0];
    *(u8 *)(reg_a0 + 0x1A) += reg_d0.b[0];
    temp_a1 = (u8 *)(reg_a0);
    reg_d0.b[0] = (*(u8 *)((u8 *)(temp_a1) + (0x1B)));
    reg_d1.w = 0x3F;
    reg_d0.h[0] = (u16) reg_d0.b[0];
    reg_d1.b[0] &= (*(u8 *)((u8 *)(temp_a1) + (0x1A)));
    reg_a0 = reg_a6;
    reg_atmp = temp_a1;
    reg_a6 = temp_a1;
    velocity_from_direction();
    reg_atmp = (u8 *)reg_a0;
    reg_a0 = reg_a6;
    reg_a6 = (u8 *)reg_atmp;
    *(u16 *)(reg_a0 + 0x20) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a0 + 0x22) = (u16) reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    cond_flag = 0;
    reg_d1.w = reg_d7.w;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
}

extern void rng_next(void);

void pickup_init_spread(void) {
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)((u8 *)((void *)reg_a0) + 0x1A) = 0x420;
    rng_next();
    if ((s8)reg_d0.b[0] < 0) {
        reg_d0.b[0] *= -1;
    }
    reg_d0.h[0] = (s8)reg_d0.b[0];
    reg_d0.h[0] >>= 1;
    pickup_init_jitter();
}

void pickup_init_timer(void) {
    *(u16 *)((u8 *)((void *)reg_a0) + 0x1E) = 0x9601;
    cond_flag = 0;
}

s32 rng_next_masked();

void pickup_init_random_delay_a(void) {
    reg_d7.w = reg_d0.w;
    rng_next_masked();
    reg_d0.h[0] &= 0x1F;
    *(u8 *)(reg_a0 + 0x19) += reg_d0.b[0];
    *(s16 *)(reg_a0 + 0x20) = 0;
    cond_flag = 0;
    reg_d0.w = reg_d7.w;
}

void pickup_init_random_delay_b(void) {
    reg_d7.w = reg_d0.w;
    rng_next_masked();
    reg_d0.h[0] &= 0x1F;
    *(u8 *)(reg_a0 + 0x19) += reg_d0.b[0];
    *(s16 *)(reg_a0 + 0x20) = 0;
    cond_flag = 0;
    reg_d0.w = reg_d7.w;
}


void pickup_init_spread_reset(void) {
    pickup_init_spread();
    *(s8 *)reg_a0 = 0;
    *(u8 *)(reg_a0 + 0x1B) += 5;
    cond_flag = 0;
}

void pickup_init_spread_a(void) {
    pickup_init_spread();
    *(u8 *)(reg_a0 + 0x1B) += 5;
    cond_flag = 0;
}

void pickup_init_spread_b(void) {
    pickup_init_spread();
    *(u8 *)(reg_a0 + 0x1B) += 5;
    cond_flag = 0;
}

void pickup_init_spread_c(void) {
    pickup_init_spread();
    *(u8 *)(reg_a0 + 0x1B) += 5;
    cond_flag = 0;
}

extern s16 g_player2[56];

void pickup_init_to_player2_offsets_3(void) {
    reg_a3 = ((u8 *)pickup_start_offsets_3);
    reg_tmp.w = ARCADE_ADDRESS_ENCODE((u8 *)g_player2);
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[0];
    pickup_init_to_target();
}

extern u16 pickup_start_offsets_0[];

void pickup_init_to_player2_offsets_0(void) {
    reg_a3 = ((u8 *)pickup_start_offsets_0);
    reg_tmp.w = ARCADE_ADDRESS_ENCODE((u8 *)g_player2);
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[0];
    pickup_init_to_target();
}

extern u16 pickup_start_offsets_1[];

void pickup_init_to_player2_offsets_1(void) {
    reg_a3 = ((u8 *)pickup_start_offsets_1);
    reg_tmp.w = ARCADE_ADDRESS_ENCODE((u8 *)g_player2);
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[0];
    pickup_init_to_target();
}

extern u16 pickup_start_offsets_2[];

void pickup_init_to_player2_offsets_2(void) {
    reg_a3 = ((u8 *)pickup_start_offsets_2);
    reg_tmp.w = ARCADE_ADDRESS_ENCODE((u8 *)g_player2);
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[0];
    pickup_init_to_target();
}



void pickup_init_to_player1_offsets_3(void) {
    reg_a3 = (u8 *)pickup_start_offsets_3;
    pickup_init_to_player1();
}

extern u16 pickup_start_offsets_0[];


void pickup_init_to_player1_offsets_0(void) {
    reg_a3 = (u8 *)pickup_start_offsets_0;
    pickup_init_to_player1();
}

extern u16 pickup_start_offsets_1[];


void pickup_init_to_player1_offsets_1(void) {
    reg_a3 = (u8 *)pickup_start_offsets_1;
    pickup_init_to_player1();
}

extern u16 pickup_start_offsets_2[];

void pickup_init_to_player1_offsets_2(void)
{
    reg_a3 = (u8 *)pickup_start_offsets_2;
    pickup_init_to_player1();
}

extern s16 g_player1[56];
void pickup_init_to_player1(void) {
    reg_tmp.w = ARCADE_ADDRESS_ENCODE((u8 *)g_player1);
    *(u16 *)(reg_a0 + 0x24) = reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x26) = reg_tmp.h[0];
    pickup_init_to_target();
}

void pickup_init_to_target(void) {
    reg_d7.h[0] &= 0xF;
    *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d7.b[0];
    *(s8 *)(reg_a0 + 0x1F) = 0;
    reg_d7.w = reg_d0.w;
    rng_next_unsigned();
    reg_d0.w &= 0xE;
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a3) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp.w += reg_d0.w;
    *(u16 *)(reg_a0 + 0xA) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0xC) = (u16) reg_tmp.h[0];
    cond_flag = 0;
    reg_d0.w = reg_d7.w;
}

void pickup_init_scatter_0(void) {
    u16 temp_a1;
    temp_a1 = reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = temp_a1;
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(s16 *)(reg_a0 + 0x1A) = 0x420;
    rng_next_unsigned();
    reg_a3 = (u8 *)(pickup_start_offsets_0);
    reg_d0.h[0] &= 0xE;
    reg_d1.w = 0;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp1.h[1] = *(u16 *)(reg_a0 + 0xA);
    reg_tmp1.h[0] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp1.w = (s32) ((s32) reg_tmp1.w + reg_d1.w);
    *(u16 *)(reg_a0 + 0xA) = (u16) reg_tmp1.h[1];
    *(u16 *)(reg_a0 + 0xC) = reg_tmp1.h[0];
    pickup_init_jitter_small();
    *(u16 *)reg_a0 &= 0xFF83;
    *(u16 *)reg_a0 |= 0x14;
}

void pickup_init_scatter_1(void) {
    u16 temp_a1;
    temp_a1 = reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = temp_a1;
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(s16 *)(reg_a0 + 0x1A) = 0x420;
    rng_next_unsigned();
    reg_a3 = (u8 *)(pickup_start_offsets_1);
    reg_d0.h[0] &= 0xE;
    reg_d1.w = 0;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp1.h[1] = *(u16 *)(reg_a0 + 0xA);
    reg_tmp1.h[0] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp1.w = (s32) ((s32) reg_tmp1.w + reg_d1.w);
    *(u16 *)(reg_a0 + 0xA) = (u16) reg_tmp1.h[1];
    *(u16 *)(reg_a0 + 0xC) = reg_tmp1.h[0];
    pickup_init_jitter_small();
    *(u16 *)reg_a0 &= 0xFF83;
    *(u16 *)reg_a0 |= 0x18;
}

void pickup_init_scatter_2(void) {
    u16 temp_a1;
    temp_a1 = reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = temp_a1;
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(s16 *)(reg_a0 + 0x1A) = 0x420;
    rng_next_unsigned();
    reg_a3 = (u8 *)(pickup_start_offsets_2);
    reg_d0.h[0] &= 0xE;
    reg_d1.w = 0;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp1.h[1] = *(u16 *)(reg_a0 + 0xA);
    reg_tmp1.h[0] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp1.w = (s32) ((s32) reg_tmp1.w + reg_d1.w);
    *(u16 *)(reg_a0 + 0xA) = (u16) reg_tmp1.h[1];
    *(u16 *)(reg_a0 + 0xC) = reg_tmp1.h[0];
    pickup_init_jitter_small();
    *(u16 *)reg_a0 &= 0xFF83;
    *(u16 *)reg_a0 |= 0x1C;
}

void rng_next(void);
struct PickupCollectionTable {
    u16 spawn[12];
    const u16 *variants[3];
    u16 collection[30];
};
extern struct PickupCollectionTable pickup_init_routines_7;
#ifdef DDPDOJ_PC
extern u16 D_00269750[24];
extern u16 D_00269780[24];
extern u16 D_002697B0[24];
static const u16 *const pickup_collection_sprites[] = { D_00269750, D_00269780, D_002697B0 };
#else
extern u8 D_00269708[];
#endif

void pickup_collected_begin(void) {
    void velocity_from_direction(void);
    reg_d0.h[1] = ENTITY(reg_a6)->hit_y_plus.h;
    reg_d0.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
#ifdef DDPDOJ_PC
    unsigned variant = reg_d0.h[0] / 4;
    reg_a0 = (u8 *)pickup_init_routines_7.variants[variant];
#else
    reg_a0 = (u8 *)D_00269708;
    reg_a0 = *(u8 **)(D_00269708 + (reg_d0.h[0] & ~3));
#endif
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
#ifdef DDPDOJ_PC
    reg_a0 += 4;
    reg_a1 = reg_a6;
    reg_a2 = (u8 *)pickup_collection_sprites[variant];
#else
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 = reg_a6;
    reg_a2 = (u8 *)reg_tmp.w;
#endif
    ENTITY(reg_a6)->flags.h &= 0xF8DF;
    reg_a1 += 2;
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
    reg_tmp.w += 0x06000000;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[0];
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    ENTITY(reg_a6)->hit_y_minus.h = 0x10;
    ENTITY(reg_a6)->hit_x_plus.sh = 0x202;
    ENTITY(reg_a6)->hit_x_minus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->hp.sb[1] = 7;
    ENTITY(reg_a6)->hp.sb[0] = 0xF;
    ENTITY(reg_a6)->attr.sh = 0x1D;
    reg_d0.h[0] = g_side_scroll_step[0];
    reg_d0.h[0] = (s16)reg_d0.h[0] + ENTITY(reg_a6)->x.sh;
    reg_d1.w = 0x30;
    if ((s32)reg_d0.h[0] < 0x1C00) {
        reg_d1.w = 0x10;
    }
    rng_next();
    if ((s8)reg_d0.b[0] < 0) {
        reg_d0.b[0] *= -1;
    }
    reg_d0.h[0] &= 6;
    reg_d0.h[0] += 6;
    velocity_from_direction();
    ENTITY(reg_a6)->move.h = reg_d3.h[0];
}

void entity_draw_layer5_zoom(void);

void pickup_collected_update(void) {
    u32 sd6;
    u8 t;
    u32 t1;

    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1A);
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    *(u8 *)(reg_a6 + 0x15) -= 1;
    if (*(u8 *)(reg_a6 + 0x15) != 0) goto block_1;
    *(u8 *)(reg_a6 + 0x15) = *(u8 *)(reg_a6 + 0x14);
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x16);
    *(u8 *)(reg_a6 + 0x18) -= 1;
    switch (*(u8 *)(reg_a6 + 0x18)) {
        case 0:
            goto block_3;
    }
    *(u8 *)(reg_a6 + 0x19) -= 1;
    t = *(u8 *)(reg_a6 + 0x19);
    if ((s8)t < 0) goto block_2;
    if (t == 0) {
        *(u8 *)(reg_a6 + 0x15) = 0x28;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w += reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    goto block_1;
block_2:
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w -= reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
block_1:
    sd6 = reg_d6.w;
    reg_d6.w = 0x40004000;
    entity_draw_layer5_zoom();
    reg_d6.w = sd6;
    goto block_4;
block_3:
    bullet_release();
block_4:
    reg_a6 += 0x2C;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(u16)t1 << 0x30) >> 0x30) >= 0) {
        pickups_update_loop();
    }
}


void pickup_collected_update_blinking(void) {
    u32 sd6;
    u8 t;

    if ((reg_d1.w & 0x2000) && (g_frame_mod2 != 0)) {
        *(u8 *)(reg_a6 + 0x1C) ^= 0x10;
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1A);
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    *(u8 *)(reg_a6 + 0x15) -= 1;
    if (*(u8 *)(reg_a6 + 0x15) != 0) goto block_1;
    *(u8 *)(reg_a6 + 0x15) = *(u8 *)(reg_a6 + 0x14);
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x16);
    *(u8 *)(reg_a6 + 0x18) -= 1;
    if (*(u8 *)(reg_a6 + 0x18) == 0) goto block_3;
    *(u8 *)(reg_a6 + 0x19) -= 1;
    t = *(u8 *)(reg_a6 + 0x19);
    if ((s8)t < 0) goto block_2;
    if (t == 0) {
        *(u8 *)(reg_a6 + 0x15) = 0x28;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w += reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    goto block_1;
block_2:
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w -= reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
block_1:
    sd6 = reg_d6.w;
    reg_d6.w = 0x40004000;
    entity_draw_layer5_zoom();
    reg_d6.w = sd6;
    if ((s32)*(u8 *)(reg_a6 + 0x15) < 3) return;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 8);
    reg_d1.h[1] += *(u16 *)(reg_a6 + 6);
    pickup_draw_value_large();
    if (*(u8 *)(reg_a6 + 1) & 0x20) {
        pickup_draw_value();
    }
    return;
block_3:
    bullet_release();
}

void sprite_draw_with_special_items_keep(void);
extern u16 g_loop;
extern u16 g_stage;

void pickup_draw_value_large(void) {
    void sprite_draw_with_special_items(void);
    u32 sd6;
    u32 sd7;

    reg_d1.h[0] += 0x7FFF + 0x7DC1;
    reg_d1.h[1] += 0x200;
    reg_d2.w = 0x11E0;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 0x1D;
    sprite_draw_with_special_items();
    reg_d3.h[0] = 0x410;
    sd6 = reg_d6.w;
    sd7 = reg_d7.w;
    reg_d1.h[0] += 0x480;
    reg_d1.h[1] += 0x7FFF + 0x7F41;
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_d7.w = 1;
    reg_d6.w = 0;
    do {
        reg_d5.w = 0x1046;
        reg_d2.w = 0xF;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] <<= 4;
        reg_d0.h[0] |= (u16)((s32)reg_tmp.h[0] >> 0xC);
        reg_d2.h[0] &= reg_d0.h[0];
        reg_d4.w = 0;
        if (reg_d2.h[0] == 0 && reg_d6.h[0] == 0) {
            reg_d5.w = 0x103C;
        } else {
            reg_d4.h[0] = reg_d2.h[0] * 0xA;
        }
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] <<= 4;
        reg_d2.w = 0xF;
        reg_d0.h[0] |= (u16)((s32)reg_tmp.h[0] >> 0xC);
        reg_d2.h[0] &= reg_d0.h[0];
        if (reg_d2.h[0] != 0 || reg_d4.h[0] != 0 || reg_d6.h[0] != 0) {
            reg_d6.w = 1;
            reg_d2.w += reg_d4.w;
            if (reg_d5.w == 0x103C) {
                reg_d1.h[0] += 0x7FFF + 0x7E01;
            }
            reg_d2.w += reg_d5.w;
            reg_d4.h[0] = 0x1D;
            sprite_draw_with_special_items_keep();
            reg_d1.h[0] += 0x400;
        }
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d1.h[0] += 0x7FFF + 0x7C01;
    if (g_stage != 0 || g_loop != 0) {
        reg_d6.w = sd6;
        reg_d7.w = sd7;
        return;
    }
    reg_d2.w = 0x11E1;
    reg_d1.h[0] += 0x400;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 0x1D;
    reg_d1.h[1] += 0xC0;
    sprite_draw_with_special_items_keep();
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_d1.w += 0xFF400000;
}

extern u32 pickup_draw_value_table[];

void pickup_draw_value(void) {
    u16 temp_a2;
    u16 temp_a3;
    u32 temp_a0;

    temp_a3 = (u32)reg_d1.h[0] + 0x400;
    reg_d1.h[0] = temp_a3;
    temp_a2 = (u32)reg_d1.h[1] + 0x40;
    reg_d1.h[1] = temp_a2;
    reg_d0.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
    reg_a0 = (u8 *)(pickup_draw_value_table);
    reg_a0 += reg_d0.h[0];
    temp_a0 = *(u32 *)reg_a0;
    reg_d2.w = temp_a0;
    reg_d3.h[0] = 0x420;
    reg_d4.h[0] = 0x1D;
    sprite_draw_with_special_items();
    ENTITY(reg_a6)->hit_y_minus.h -= 4;
    if ((s16) ENTITY(reg_a6)->hit_y_minus.h < 0) {
        ENTITY(reg_a6)->hit_y_minus.h = 0x10U;
    }
}

#ifdef DEATH_LABEL
s32 bullet_is_type_24(void) {
    return (*(u16 *)reg_a6 & 0x3F) == 0x24;
}
#endif

void bullet_slot_reset(void) {
    *(u16 *)reg_a6 = 0;
    *(u16 *)(reg_a6 + 2) = 0xFFFF;
}

extern u8 g_bullets[];

extern u8 *D_00299770[];

void bullets_clear(void) {
#ifdef DDPDOJ_PC
    memset(g_bullets, 0, MAIN_OR_DEATH_LABEL(0x3490, 0x10690));
    D_00299770[0] = NULL;
#else
    memset(g_bullets, 0, MAIN_OR_DEATH_LABEL(0x3494, 0x10694));
#endif
    reg_a0 = g_bullets + 2;
    reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
    do {
        *(u16 *)reg_a0 = 0xFFFF;
        reg_a0 += 0x40;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}


void bullet_fire_loop2_double_from_task(void) {
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    bullet_fire_loop2_double();
}

#ifdef DDPDOJ_PC
typedef uintptr_t BulletSavedAddress;
#else
typedef s32 BulletSavedAddress;
#endif
extern BulletSavedAddress g_bullet_fire_saved_a0;
extern u32 g_bullet_fire_saved_d1;
extern u32 g_bullet_fire_saved_d0;

void bullet_fire_loop2_double() {
    bullet_fire_direct();
    reg_d0.w += 0x60000;
    bullet_fire_direct();
    reg_d0.w = g_bullet_fire_saved_d0;
    reg_d1.w = g_bullet_fire_saved_d1;
    reg_a0 = (u8 *)g_bullet_fire_saved_a0;
}

extern u8 *g_bullet_fire_saved_a0_as_u8_p;

void bullet_fire_loop2(void) {
    g_bullet_fire_saved_d0 = reg_d0.w;
    g_bullet_fire_saved_d1 = reg_d1.w;
    g_bullet_fire_saved_a0 = (BulletSavedAddress)reg_a0;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[0] = 0x81;
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((reg_d1.b[0] &= *(u8 *)(reg_a5 + 0xC)) != 0) {
        bullet_fire_loop2_double_from_task();
        return;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    if (!(*(u8 *)(reg_a0 + 1) & 2)) {
        bullet_fire_loop2_double();
        return;
    }
    bullet_fire_loop2_3way();
}


void bullet_fire_loop2_3way() {
    reg_d1.b[0] += reg_d1.b[0];
    reg_d0.w += 0x20000;
    reg_d1.b[0] += reg_d1.b[0];
    bullet_fire256_direct();
    reg_d0.w -= 0x20000;
    reg_d1.b[0] -= 8;
    bullet_fire256_direct();
    reg_d1.b[0] += 0x10;
    bullet_fire256_direct();
    reg_d0.w = g_bullet_fire_saved_d0;
    reg_d1.w = g_bullet_fire_saved_d1;
    reg_a0 = (u8 *)g_bullet_fire_saved_a0;
}

void bullet_fire_loop2_2way() {
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] -= 8;
    bullet_fire256_direct();
    reg_d1.b[0] += 0x10;
    bullet_fire256_direct();
    reg_d0.w = g_bullet_fire_saved_d0;
    reg_d1.w = g_bullet_fire_saved_d1;
    reg_a0 = (u8 *)g_bullet_fire_saved_a0;
}


void bullet_fire_fixed(void) {
    if (g_loop == 0) {
        bullet_spawn();
        return;
    }
    bullet_fire_direct();
}

void bullet_fire_fast(void) {
    if (g_loop == 0) {
        bullet_spawn();
        return;
    }
    reg_d0.w += 0x40000;
    bullet_fire_direct();
    reg_d0.w += 0xFFFC0000;
}


void bullet_fire_double(void) {
    if (g_loop == 0) {
        bullet_spawn();
        return;
    }
    g_bullet_fire_saved_d0 = reg_d0.w;
    g_bullet_fire_saved_d1 = reg_d1.w;
    g_bullet_fire_saved_a0 = (BulletSavedAddress)reg_a0;
    bullet_fire_loop2_double(reg_d0.w);
}


void bullet_fire_2way(void) {
    if (g_loop == 0) {
        bullet_spawn();
        return;
    }
    g_bullet_fire_saved_d0 = reg_d0.w;
    g_bullet_fire_saved_d1 = reg_d1.w;
    g_bullet_fire_saved_a0 = (BulletSavedAddress)reg_a0;
    bullet_fire_loop2_2way(reg_d0.w);
}


void bullet_fire_3way(void) {
    if (g_loop == 0) {
        bullet_spawn();
        return;
    }
    g_bullet_fire_saved_d0 = reg_d0.w;
    g_bullet_fire_saved_d1 = reg_d1.w;
    g_bullet_fire_saved_a0 = (BulletSavedAddress)reg_a0;
    bullet_fire_loop2_3way(reg_d0.w);
}


void bullet_fire(void) {
    if (g_loop != 0) {
        bullet_fire_loop2();
        return;
    }
    bullet_spawn();
}


void bullet_fire_direct(void) {
    bullet_spawn();
}

extern u16 bullet_type_records[];
extern u32 g_bullet_spawn_saved_d7;
extern u32 g_bullet_spawn_saved_d0;
extern BulletSavedAddress g_bullet_spawn_saved_a1;
extern void *g_bullet_spawn_saved_a0;
extern u16 g_hyper_bullet_speed;
extern u8 g_no_enemy_bullets;
extern u16 g_bullet_speed_bonus;
extern u16 g_bullets_blocked;
extern s16 g_bullet_limit_raised_1[];
extern s16 g_bullet_limit_raised_2[];
extern u16 g_bullet_limit_raised_3[];
extern u16 g_bullets_clear_request[];
extern u16 g_bomb_entities[];
#ifdef DEATH_LABEL
extern u16 g_attract_demo;
extern u8 g_twin_boss_bullet_speed_limit;
extern u8 g_death_boss_form;
#endif

void bullet_spawn(void) {
    s16 hi;

#ifdef DEATH_LABEL
    if ((g_attract_demo == 0) && (g_no_enemy_bullets != 0)) {
        return;
    }
#else
    if (g_no_enemy_bullets != 0) {
        return;
    }
#endif
    g_bullet_spawn_saved_d7 = reg_d7.w;
    (*(u8 **)&g_bullet_spawn_saved_a0) = reg_a0;
    (*(u16 **)&g_bullet_spawn_saved_a1) = (u16 *) reg_a1;
    reg_d7.h[0] = g_bullets_blocked;
    reg_d7.h[0] += g_enemies_stopped;
    reg_d7.h[0] += g_bomb_entities[0];
    if (reg_d7.h[0] != 0) {
        goto next_3;
    }
next_1:
    reg_a0 = (u8 *)g_bullets;
    reg_d7.w = MAIN_OR_DEATH_LABEL(0xD, 0x45);
    if (((u16 *)g_bullet_limit_raised_1)[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x15, 0x6D);
    if (((u16 *)g_bullet_limit_raised_2)[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x1F, 0x9F);
    if (g_bullet_limit_raised_3[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x25, 0xBD);
    if (g_bullets_clear_request[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x29, 0xD1);
loop_2:
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_2;
    }
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = (u8 *)((u8 *)g_bullet_spawn_saved_a0);
    reg_a1 = (u8 *) (*(u16 **)&g_bullet_spawn_saved_a1);
    cond_flag = 1;
    return;
next_3:
    if (0 <= (s64) (s16) g_bomb_entities[0]) {
        goto next_4;
    }
    if (*(u8 *) g_bomb_entities & 1) {
        goto next_1;
    }
next_4:
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = (u8 *)((u8 *)g_bullet_spawn_saved_a0);
    reg_a1 = (u8 *) (*(u16 **)&g_bullet_spawn_saved_a1);
    cond_flag = 0;
    return;
next_5:
    g_bullet_spawn_saved_d0 = reg_d0.w;
    hi = reg_d0.h[1];
    reg_d0.h[0] &= 0x3F;
#ifdef DDPDOJ_BONUS_FEATURES
    if (black_label_ring_frames(reg_d0.h[0])) reg_d0.h[0] = 0x1B;
#endif
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *) bullet_type_records;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a1 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a1 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a1;
    reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
#ifdef DDPDOJ_BONUS_FEATURES
    if (black_label_ring_frames(g_bullet_spawn_saved_d0 & 0x3F))
        *(u16 *)reg_a0 = (*(u16 *)reg_a0 & ~0x3F) | (g_bullet_spawn_saved_d0 & 0x3F);
#endif
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[1];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) (reg_a0 + 0xC) = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] += hi;
    reg_d7.h[0] += g_bullet_speed_bonus;
    reg_d7.h[0] += g_hyper_bullet_speed;
#ifdef DEATH_LABEL
    if ((g_death_boss_form == 2) && (reg_d7.h[0] > g_twin_boss_bullet_speed_limit)) {
        reg_d7.h[0] = g_twin_boss_bullet_speed_limit;
    }
#endif
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    *(u8 *) (reg_a0 + 0xB) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0xA) = reg_d1.b[0];
    *(u8 *) (reg_a0 + 0x2B) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0x2A) = reg_d1.b[0];
    reg_d1.b[0] >>= 2;
    bullet_position_offset_add();
}

extern u8 bullet_type_setup_routines[];

void bullet_position_offset_add(void) {
    if (reg_d3.w == 0) {
        goto next_1;
    }
    *(u16 *) (reg_a0 - 0xC) += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    *(u16 *) (reg_a0 - 0xE) += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
next_1:
    if (*(s16 *) reg_a1 == 0) {
        goto next_2;
    }
    reg_a1 = (u8 *)bullet_type_setup_routines;
    reg_a1 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *) reg_a1;
    reg_tmp.h[0] = *(u16 *) (reg_a1 + 2);
    reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_call_target = (Fn) reg_a1;
    reg_call_target();
    return;
next_2:
    reg_d0.w = g_bullet_spawn_saved_d0;
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = (u8 *)((u8 *)g_bullet_spawn_saved_a0);
    reg_a1 = (u8 *)(*(u8 **)&g_bullet_spawn_saved_a1);
    cond_flag = 0;
}


void bullet_fire256_loop2_double_from_task(void) {
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    bullet_fire256_loop2_double();
}


void bullet_fire256_loop2_double() {
    bullet_fire256_direct();
    reg_d0.w += 0x60000;
    bullet_fire256_direct();
    reg_d0.w = g_bullet_fire_saved_d0;
    reg_d1.w = g_bullet_fire_saved_d1;
    reg_a0 = (u8 *)g_bullet_fire_saved_a0;
}


void bullet_fire256_loop2(void) {
    g_bullet_fire_saved_d0 = reg_d0.w;
    g_bullet_fire_saved_d1 = reg_d1.w;
    g_bullet_fire_saved_a0 = (BulletSavedAddress)reg_a0;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[0] = 0x81;
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((reg_d1.b[0] &= *(u8 *)(reg_a5 + 0xC)) != 0) {
        bullet_fire256_loop2_double_from_task();
        return;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    if (!(*(u8 *)(reg_a0 + 1) & 2)) {
        bullet_fire256_loop2_double();
        return;
    }
    bullet_fire256_loop2_3way();
}

void bullet_fire256_loop2_3way() {
    bullet_fire256_direct();
    reg_d1.b[0] -= 8;
    bullet_fire256_direct();
    reg_d1.b[0] += 0x10;
    bullet_fire256_direct();
    reg_d0.w = g_bullet_fire_saved_d0;
    reg_d1.w = g_bullet_fire_saved_d1;
    reg_a0 = (u8 *)g_bullet_fire_saved_a0;
}

void bullet_fire256_loop2_2way() {
    reg_d1.b[0] -= 8;
    bullet_fire256_direct();
    reg_d1.b[0] += 0x10;
    bullet_fire256_direct();
    reg_d0.w = g_bullet_fire_saved_d0;
    reg_d1.w = g_bullet_fire_saved_d1;
    reg_a0 = (u8 *)g_bullet_fire_saved_a0;
}


void bullet_fire256_fixed(void) {
    if (g_loop == 0) {
        bullet_spawn256();
        return;
    }
    bullet_fire256_direct();
}

void bullet_fire256_fast(void) {
    if (g_loop == 0) {
        bullet_spawn256();
        return;
    }
    reg_d0.w += 0x40000;
    bullet_fire256_direct();
    reg_d0.w += 0xFFFC0000;
}


void bullet_fire256_double(void) {
    if (g_loop == 0) {
        bullet_spawn256();
        return;
    }
    g_bullet_fire_saved_d0 = reg_d0.w;
    g_bullet_fire_saved_d1 = reg_d1.w;
    g_bullet_fire_saved_a0 = (BulletSavedAddress)reg_a0;
    bullet_fire256_loop2_double(reg_d0.w);
}


void bullet_fire256_2way(void) {
    if (g_loop == 0) {
        bullet_spawn256();
        return;
    }
    g_bullet_fire_saved_d0 = reg_d0.w;
    g_bullet_fire_saved_d1 = reg_d1.w;
    g_bullet_fire_saved_a0 = (BulletSavedAddress)reg_a0;
    bullet_fire256_loop2_2way(reg_d0.w);
}


void bullet_fire256_3way(void) {
    if (g_loop == 0) {
        bullet_spawn256();
        return;
    }
    g_bullet_fire_saved_d0 = reg_d0.w;
    g_bullet_fire_saved_d1 = reg_d1.w;
    g_bullet_fire_saved_a0 = (BulletSavedAddress)reg_a0;
    bullet_fire256_loop2_3way(reg_d0.w);
}


void bullet_fire256(void) {
    if (g_loop != 0) {
        bullet_fire256_loop2();
        return;
    }
    bullet_spawn256();
}

#ifdef DEATH_LABEL
extern u8 g_twin_boss_bullets_halved;
extern u8 g_death_boss_form;
extern s32 g_twin_boss_first_bullets;
extern s32 g_twin_boss_second_bullets;
extern u8 g_twin_boss_first_fire_point[];
#endif

void bullet_fire256_direct(void) {
#ifdef DEATH_LABEL
    if (g_death_boss_form == 2) {
        if (g_twin_boss_bullets_halved != 0) {
            if (reg_a6 == g_twin_boss_first_fire_point) {
                g_twin_boss_first_bullets += 1;
                if (g_twin_boss_first_bullets & 1) {
                    return;
                }
            } else {
                g_twin_boss_second_bullets += 1;
                if (!(g_twin_boss_second_bullets & 1)) {
                    return;
                }
            }
        }
    } else {
        g_twin_boss_second_bullets = 0;
        g_twin_boss_first_bullets = 0;
    }
#endif
    bullet_spawn256();
}

#ifdef DEATH_LABEL
extern u16 g_attract_demo;
extern u8 g_twin_boss_bullet_speed_limit;
extern u8 g_death_boss_form;
#endif

void bullet_spawn256(void) {
    s16 hi;

#ifdef DEATH_LABEL
    if ((g_attract_demo == 0) && (g_no_enemy_bullets != 0)) {
        return;
    }
#else
    if (g_no_enemy_bullets != 0) {
        return;
    }
#endif
    g_bullet_spawn_saved_d7 = reg_d7.w;
    (*(u8 **)&g_bullet_spawn_saved_a0) = reg_a0;
    (*(u16 **)&g_bullet_spawn_saved_a1) = (u16 *) reg_a1;
    reg_d7.h[0] = g_bullets_blocked;
    reg_d7.h[0] += g_enemies_stopped;
    reg_d7.h[0] += g_bomb_entities[0];
    if (reg_d7.h[0] != 0) {
        goto next_3;
    }
next_1:
    reg_a0 = (u8 *)g_bullets;
    reg_d7.w = MAIN_OR_DEATH_LABEL(0xD, 0x45);
    if (((u16 *)g_bullet_limit_raised_1)[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x15, 0x6D);
    if (((u16 *)g_bullet_limit_raised_2)[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x1F, 0x9F);
    if (g_bullet_limit_raised_3[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x25, 0xBD);
    if (g_bullets_clear_request[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x29, 0xD1);
loop_2:
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_2;
    }
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = (u8 *)((u8 *)g_bullet_spawn_saved_a0);
    reg_a1 = (u8 *) (*(u16 **)&g_bullet_spawn_saved_a1);
    cond_flag = 1;
    return;
next_3:
    if (0 <= (s64) (s16) g_bomb_entities[0]) {
        goto next_4;
    }
    if (*(u8 *) g_bomb_entities & 1) {
        goto next_1;
    }
next_4:
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = (u8 *)((u8 *)g_bullet_spawn_saved_a0);
    reg_a1 = (u8 *) (*(u16 **)&g_bullet_spawn_saved_a1);
    cond_flag = 0;
    return;
next_5:
    g_bullet_spawn_saved_d0 = reg_d0.w;
    hi = reg_d0.h[1];
    reg_d0.h[0] &= 0x3F;
#ifdef DDPDOJ_BONUS_FEATURES
    if (black_label_ring_frames(reg_d0.h[0])) reg_d0.h[0] = 0x1B;
#endif
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *) bullet_type_records;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a1 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a1 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a1;
    reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d7.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.w |= 0x200;
    *(u16 *) reg_a0 = reg_d7.h[0];
#ifdef DDPDOJ_BONUS_FEATURES
    if (black_label_ring_frames(g_bullet_spawn_saved_d0 & 0x3F))
        *(u16 *)reg_a0 = (*(u16 *)reg_a0 & ~0x3F) | (g_bullet_spawn_saved_d0 & 0x3F);
#endif
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[1];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) (reg_a0 + 0xC) = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] += hi;
    reg_d7.h[0] += g_bullet_speed_bonus;
    reg_d7.h[0] += g_hyper_bullet_speed;
#ifdef DEATH_LABEL
    if ((g_death_boss_form == 2) && (reg_d7.h[0] > g_twin_boss_bullet_speed_limit)) {
        reg_d7.h[0] = g_twin_boss_bullet_speed_limit;
    }
#endif
    *(u8 *) (reg_a0 + 0xB) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0xA) = reg_d1.b[0];
    *(u8 *) (reg_a0 + 0x2B) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0x2A) = reg_d1.b[0];
    bullet_position_offset_add();
}

extern BulletSavedAddress g_bullet_spawn_saved_a1;
extern void *g_bullet_spawn_saved_a0;

void bullet_type_setup_00(void) {
    cond_flag = 0;
    reg_d0.w = g_bullet_spawn_saved_d0;
    reg_d7.sw = (s32)g_bullet_spawn_saved_d7;
    reg_a0 = g_bullet_spawn_saved_a0;
    reg_a1 = (u8 *)g_bullet_spawn_saved_a1;
}

extern void *g_bullet_spawn_saved_a0;

void bullet_type_setup_03(void) {
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d3.h[1];
    *(u16 *)(reg_a0 + 0x1A) = (u16) reg_d3.h[0];
    *(u16 *)(reg_a0 + 0x1C) = (u16) reg_d4.h[1];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d4.h[0];
    *(s8 *)(reg_a0 + 0x25) = 0;
    cond_flag = 0;
    reg_d0.w = g_bullet_spawn_saved_d0;
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = g_bullet_spawn_saved_a0;
    reg_a1 = (u8 *)g_bullet_spawn_saved_a1;
}

void bullet_type_setup_17(void) {
    *(u8 *)(reg_a0 + 0x25) = (u8) reg_d4.b[0];
    cond_flag = 0;
    reg_d0.w = g_bullet_spawn_saved_d0;
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = g_bullet_spawn_saved_a0;
    reg_a1 = (u8 *)g_bullet_spawn_saved_a1;
}

void bullet_type_setup_18(void) {
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_d4.h[0];
    cond_flag = 0;
    reg_d0.w = g_bullet_spawn_saved_d0;
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = g_bullet_spawn_saved_a0;
    reg_a1 = (u8 *)g_bullet_spawn_saved_a1;
}

void bullet_type_setup_19(void) {
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d3.h[1];
    *(u16 *)(reg_a0 + 0x1A) = (u16) reg_d3.h[0];
    *(u16 *)(reg_a0 + 0x1C) = (u16) reg_d4.h[1];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d4.h[0];
    *(s8 *)(reg_a0 + 0x25) = 0;
    cond_flag = 0;
    reg_d0.w = g_bullet_spawn_saved_d0;
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = g_bullet_spawn_saved_a0;
    reg_a1 = (u8 *)g_bullet_spawn_saved_a1;
}

void bullet_type_setup_23(void) {
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d3.h[1];
    *(u16 *)(reg_a0 + 0x1A) = (u16) reg_d3.h[0];
    *(u16 *)(reg_a0 + 0x1C) = (u16) reg_d4.h[1];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d4.h[0];
    *(s8 *)(reg_a0 + 0x25) = 0;
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_d5.h[0];
    cond_flag = 0;
    reg_d0.w = g_bullet_spawn_saved_d0;
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = g_bullet_spawn_saved_a0;
    reg_a1 = (u8 *)g_bullet_spawn_saved_a1;
}


void bullet_type_setup_27(void) {
    bullet_type_setup_32();
}

extern u16 g_enemy_signal_1;
extern u16 g_enemy_signal_0;

void bullet_type_setup_32(void) {
    *(u16 *)(reg_a0 + 0x18) = (u16) g_enemy_signal_0;
    *(u16 *)(reg_a0 + 0x1A) = (u16) g_enemy_signal_1;
    *(u16 *)(reg_a0 + 0x1C) = (u16) reg_d4.h[1];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d4.h[0];
    *(s8 *)(reg_a0 + 0x25) = 0;
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_d5.h[1];
    *(u16 *)(reg_a0 + 0x28) = (u16) reg_d5.h[0];
    cond_flag = 0;
    reg_d0.w = g_bullet_spawn_saved_d0;
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = g_bullet_spawn_saved_a0;
    reg_a1 = (u8 *)g_bullet_spawn_saved_a1;
}

void bullet_init_from_task(void) {
    *(u8 *)(reg_a0 + 0x1B) = (u8) *(u8 *)(reg_a5 + 2);
    *(u16 *)(reg_a0 + 0x1C) = (u16) reg_d4.h[1];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d4.h[0];
    cond_flag = 0;
    reg_d0.w = g_bullet_spawn_saved_d0;
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = g_bullet_spawn_saved_a0;
    reg_a1 = (u8 *)g_bullet_spawn_saved_a1;
}


void bullet_type_setup_30(void) {
    bullet_type_setup_31();
}

void bullet_type_setup_31(void) {
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d3.h[1];
    *(u16 *)(reg_a0 + 0x1A) = (u16) reg_d3.h[0];
    *(u16 *)(reg_a0 + 0x1C) = (u16) reg_d4.h[1];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d4.h[0];
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_d5.h[1];
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_d5.h[0];
    cond_flag = 0;
    reg_d0.w = g_bullet_spawn_saved_d0;
    reg_d7.w = g_bullet_spawn_saved_d7;
    reg_a0 = g_bullet_spawn_saved_a0;
    reg_a1 = (u8 *)g_bullet_spawn_saved_a1;
}

extern u16 g_bullet_cancel[];

#ifdef DEATH_LABEL
s32 bullet_cancel_to_pickup();
#endif

void bullets_cancel_update(void) {
    u32 t;

    if (g_bullet_cancel[0] == 0) {
        return;
    }
    reg_d0.h[0] = *(u16 *)(g_bullets + MAIN_OR_DEATH_LABEL(0x3486, 0x10686));
    if ((s16) reg_d0.h[0] < 0) {
        goto next_3;
    }
    reg_a6 = (u8 *)g_bullets;
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x45, 0x15D);
    if (((u16 *)g_bullet_limit_raised_1)[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x6D, 0x225);
    if (((u16 *)g_bullet_limit_raised_2)[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x9F, 0x31F);
    if (g_bullet_limit_raised_3[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xBD, 0x3B5);
    if (g_bullets_clear_request[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
loop_1:
    if (0 > (s64) *(s8 *) (reg_a6 + 1)) {
        g_bullet_spawn_saved_d7 = reg_d7.w;
        reg_d0.h[0] = *(u16 *)(g_bullets + MAIN_OR_DEATH_LABEL(0x3486, 0x10686));
        MAIN_OR_DEATH_LABEL(pickup_spawn_here, bullet_cancel_to_pickup)();
        reg_d7.w = g_bullet_spawn_saved_d7;
        bullet_slot_reset();
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
    return;
next_3:
    reg_a6 = (u8 *)g_bullets;
    reg_d2.w = 0x40;
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x45, 0x15D);
    if (((u16 *)g_bullet_limit_raised_1)[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x6D, 0x225);
    if (((u16 *)g_bullet_limit_raised_2)[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x9F, 0x31F);
    if (g_bullet_limit_raised_3[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xBD, 0x3B5);
    if (g_bullets_clear_request[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
loop_4:
    t = *(u8 *) (reg_a6 + 1);
    if (0 > (s8) t) {
        *(u8 *) (reg_a6 + 1) = t | reg_d2.b[0];
        *(u16 *) (reg_a6 + 0x3C) = 0xFFFF;
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_4;
    }
}

void entity_draw_layer1();
void entity_draw_layer2();
void entity_draw_layer3();
void entity_draw_layer4();
void entity_draw_layer5();
extern u16 pickup_init_routines_0[16];
extern u16 pickup_init_routines_1[16];
extern u16 pickup_init_routines_2[16];
extern u16 pickup_init_routines_3[16];
extern u16 pickup_init_routines_5[16];
extern u16 pickup_init_routines_6[16];


void (*pickups_update_loop_table[20])() = {
    score_pickup_kind0,
    score_pickup_bee,
    score_pickup_ground_star_small,
    score_pickup_ground_star_large,
    score_pickup_kind0,
    score_pickup_air_star_medium,
    score_pickup_air_star_large,
    score_pickup_air_star_huge,
    score_pickup_p1_homing_star_small,
    score_pickup_p1_homing_star_medium,
    score_pickup_p1_homing_star_large,
    score_pickup_p1_homing_star_huge,
    score_pickup_p2_homing_star_small,
    score_pickup_p2_homing_star_medium,
    score_pickup_p2_homing_star_large,
    score_pickup_p2_homing_star_huge,
    score_pickup_bee,
    score_pickup_air_star_medium,
    score_pickup_air_star_large,
    score_pickup_air_star_huge,
};

u16 bee_collected_table[24] = {
    0x0100, 0x0000, 0x0200, 0x0000, 0x0300, 0x0000, 0x0400, 0x0000,
    0x0500, 0x0000, 0x0600, 0x0000, 0x0700, 0x0000, 0x0800, 0x0000,
    0x0900, 0x0000, 0x1000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 bee_collected_table_2[24] = {
    0x0001, 0x0004, 0x0002, 0x0004, 0x0003, 0x0004, 0x0004, 0x0004,
    0x0005, 0x0004, 0x0006, 0x0004, 0x0007, 0x0004, 0x0008, 0x0004,
    0x0009, 0x0004, 0x0001, 0x0008, 0x0000, 0x0000, 0x0000, 0x0000,
};

u8 D_00269490[160] = {
    0x04, 0x96, 0xF4, 0xFF, 0x1F, 0x00, 0x04, 0x00, 0xE8, 0xFF, 0x1D, 0x00, 0x04, 0x06, 0xDE, 0xFF,
    0x1A, 0x00, 0x04, 0x0C, 0xD6, 0xFF, 0x15, 0x00, 0x06, 0x12, 0xEC, 0xFF, 0x0A, 0x00, 0x0A, 0x18,
    0xF6, 0xFF, 0x05, 0x00, 0x0A, 0x1E, 0x0A, 0x00, 0xFB, 0xFF, 0x06, 0x24, 0x14, 0x00, 0xF6, 0xFF,
    0x04, 0x2A, 0x2A, 0x00, 0xEB, 0xFF, 0x04, 0x30, 0x22, 0x00, 0xE6, 0xFF, 0x04, 0x36, 0x18, 0x00,
    0xE3, 0xFF, 0x04, 0x3C, 0x0C, 0x00, 0xE1, 0xFF, 0x04, 0x42, 0x00, 0x00, 0xE0, 0xFF, 0x04, 0x48,
    0xF4, 0xFF, 0xE1, 0xFF, 0x04, 0x4E, 0xE8, 0xFF, 0xE3, 0xFF, 0x04, 0x54, 0xDE, 0xFF, 0xE6, 0xFF,
    0x04, 0x5A, 0xD6, 0xFF, 0xEB, 0xFF, 0x06, 0x60, 0xEC, 0xFF, 0xF6, 0xFF, 0x0A, 0x66, 0xF6, 0xFF,
    0xFB, 0xFF, 0x0A, 0x6C, 0x0A, 0x00, 0x05, 0x00, 0x06, 0x72, 0x14, 0x00, 0x0A, 0x00, 0x04, 0x78,
    0x2A, 0x00, 0x15, 0x00, 0x04, 0x7E, 0x22, 0x00, 0x1A, 0x00, 0x04, 0x84, 0x18, 0x00, 0x1D, 0x00,
    0x04, 0x8A, 0x0C, 0x00, 0x1F, 0x00, 0x04, 0x90, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
};

void (*entity_draw_layer_routines[8])(void) = {
    entity_draw_layer1,
    entity_draw_layer1,
    entity_draw_layer2,
    entity_draw_layer3,
    entity_draw_layer4,
    entity_draw_layer5,
    0,
    0,
};

void (*pickup_spawn_init_table[20])() = {
    pickup_init_scatter_3,
    pickup_init_timer,
    pickup_init_random_delay_a,
    pickup_init_random_delay_b,
    pickup_init_spread_reset,
    pickup_init_spread_a,
    pickup_init_spread_b,
    pickup_init_spread_c,
    pickup_init_to_player1_offsets_3,
    pickup_init_to_player1_offsets_0,
    pickup_init_to_player1_offsets_1,
    pickup_init_to_player1_offsets_2,
    pickup_init_to_player2_offsets_3,
    pickup_init_to_player2_offsets_0,
    pickup_init_to_player2_offsets_1,
    pickup_init_to_player2_offsets_2,
    pickup_init_timer,
    pickup_init_scatter_0,
    pickup_init_scatter_1,
    pickup_init_scatter_2,
};

u16 pickup_start_offsets_0[8] = {
    0x0000, 0x0002, 0x0004, 0x0006, 0x0008, 0x000A, 0x000C, 0x000E,
};

u16 pickup_start_offsets_1[8] = {
    0x0000, 0x0002, 0x0004, 0x0006, 0x0008, 0x000A, 0x000C, 0x000E,
};

u16 pickup_start_offsets_2[8] = {
    0x0000, 0x0002, 0x0004, 0x0006, 0x0008, 0x000A, 0x000C, 0x000E,
};

u16 pickup_start_offsets_3[8] = {
    0x0000, 0x0002, 0x0004, 0x0006, 0x0008, 0x000A, 0x000C, 0x000E,
};

void *pickup_init_routines[20] = {
    pickup_init_routines_0,
    pickup_init_routines_1,
    pickup_init_routines_2,
    pickup_init_routines_3,
    pickup_init_routines_0,
    pickup_init_routines_5,
    pickup_init_routines_6,
    &pickup_init_routines_7,
    pickup_init_routines_0,
    pickup_init_routines_5,
    pickup_init_routines_6,
    &pickup_init_routines_7,
    pickup_init_routines_0,
    pickup_init_routines_5,
    pickup_init_routines_6,
    &pickup_init_routines_7,
    pickup_init_routines_1,
    pickup_init_routines_5,
    pickup_init_routines_6,
    &pickup_init_routines_7,
};

u16 pickup_init_routines_0[16] = {
    0xFC00, 0xFE00, 0x0000, 0x0BBF, 0x0410, 0x0580, 0x0580, 0x0480,
    0x0480, 0x0101, 0x001C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 pickup_init_routines_1[16] = {
    0xFA00, 0xFD00, 0x0000, 0x0BBD, 0x0618, 0x0980, 0x0980, 0x0780,
    0x0780, 0x0000, 0x001C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 pickup_init_routines_2[16] = {
    0xFC00, 0xFD00, 0x0000, 0x0BFF, 0x0418, 0x0680, 0x0680, 0x0500,
    0x0500, 0x0101, 0x001C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 pickup_init_routines_3[16] = {
    0xF800, 0xFA00, 0x0000, 0x0C1F, 0x0830, 0x0A80, 0x0A80, 0x0880,
    0x0880, 0x0202, 0x001C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 pickup_init_routines_5[16] = {
    0xFC00, 0xFD00, 0x0000, 0x0BCF, 0x0418, 0x0600, 0x0600, 0x0500,
    0x0500, 0x0101, 0x001C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 pickup_init_routines_6[16] = {
    0xFA00, 0xFC00, 0x0000, 0x0BDF, 0x0620, 0x0800, 0x0800, 0x0680,
    0x0680, 0x0101, 0x001C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

struct PickupCollectionTable pickup_init_routines_7 = {
    { 0xF800, 0xFA00, 0x0000, 0x0BEF, 0x0830, 0x0980, 0x0980, 0x0780, 0x0780, 0x0101, 0x001C, 0x0000 },
    { pickup_init_routines_7.collection + 2, pickup_init_routines_7.collection + 10,
      pickup_init_routines_7.collection + 18 },
    { 0x0000, 0x0000, 0x0000, 0x0001, 0xFC00, 0xFC00, 0x0420, 0x0001, 0x0000, 0x0000, 0x0000, 0x0001, 0xFC00, 0xFB00, 0x0428, 0x0001, 0x0000, 0x0000, 0x0000, 0x0001, 0xFC00, 0xFA00, 0x0430, 0x0001, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u16 D_00269750[24] = {
    0x0EFC, 0x0000, 0x0F04, 0x0000, 0x0F0C, 0x0000, 0x0F14, 0x0000,
    0x0F1C, 0x0000, 0x0F24, 0x0000, 0x0F2C, 0x0000, 0x0F34, 0x0000,
    0x0F3C, 0x0000, 0x0F44, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00269780[24] = {
    0x0F4C, 0x0000, 0x0F54, 0x0000, 0x0F5C, 0x0000, 0x0F64, 0x0000,
    0x0F6C, 0x0000, 0x0F74, 0x0000, 0x0F7C, 0x0000, 0x0F84, 0x0000,
    0x0F8C, 0x0000, 0x0F94, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_002697B0[24] = {
    0x0F9C, 0x0000, 0x0FA4, 0x0000, 0x0FAC, 0x0000, 0x0FB4, 0x0000,
    0x0FBC, 0x0000, 0x0FC4, 0x0000, 0x0FCC, 0x0000, 0x0FD4, 0x0000,
    0x0FDC, 0x0000, 0x0FE4, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u32 pickup_draw_value_table[8] = {
    0x000011DF, 0x000011DE, 0x000011DD, 0x000011DC, 0x000011DB, 0x00000000, 0x00000000, 0x00000000,
};

/* .sbss (the compiler lays these out in reverse) */
void *g_bullet_spawn_saved_a0;
BulletSavedAddress g_bullet_spawn_saved_a1;
u8 *bullets_update_state;
u32 g_bullet_spawn_saved_d0;
u32 g_bullet_spawn_saved_d7;
u32 g_bullet_fire_saved_d0;
u32 g_bullet_fire_saved_d1;
BulletSavedAddress g_bullet_fire_saved_a0;
#ifdef DEATH_LABEL
s32 g_twin_boss_second_bullets;
s32 g_twin_boss_first_bullets;
#endif
u32 D_0028DE94;
u32 D_0028DE90;
u8 *D_0028DE8C;
