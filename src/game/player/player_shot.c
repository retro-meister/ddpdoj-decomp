#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void player_shot_draw_unused(void);
void scroll_events_run_line(void);

s32 entity_draw_with_player_shots();                            /* extern */

void player_shot_draw_a(void) {
#ifdef DDPDOJ_PC
    reg_a0 = reg_a6;
#else
    reg_a0 = (u8 *)(((s32)reg_a6));
#endif
    player_shot_draw_unused();
    entity_draw_with_player_shots();
}

void player_shot_draw_b(void) {
#ifdef DDPDOJ_PC
    reg_a0 = reg_a6;
#else
    reg_a0 = (u8 *)(((s32)reg_a6));
#endif
    player_shot_draw_unused();
    entity_draw_with_player_shots();
}

s32 entity_draw_with_player_shots_zoom();
extern u16 player_shot_2_frame_set_table[];

void player_shot_2_frame_set(void) {
    u32 temp_s0;

    temp_s0 = reg_d6.w;
    reg_d6.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *)(player_shot_2_frame_set_table);
    reg_d6.h[0] *= 2;
    reg_d6.h[1] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d6.h[0] = ((reg_d6.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d6.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    entity_draw_with_player_shots_zoom();
    reg_d6.w = temp_s0;
    reg_a0 = (u8 *)(reg_a6);
    player_shot_draw_unused();
}

s32 rng_next_pair_small_d1();                            /* extern */

void player_shot_jitter_half(void) {
    rng_next_pair_small_d1();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] += reg_d1.h[0];
    rng_next_pair_small_d1();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d2.h[0] += reg_d1.h[0];
}

s32 rng_next_pair_small_d1();

void player_shot_jitter_quarter() {
    rng_next_pair_small_d1();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 2);
    ENTITY(reg_a6)->y.h += reg_d1.h[0];
    rng_next_pair_small_d1();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 2);
    ENTITY(reg_a6)->x.h += reg_d1.h[0];
}

typedef void (*Fn)();

extern Fn player_shot_update_routines[16];
extern u16 g_player_shot_count;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u16 g_side_scroll_step[];
extern u8 D_0029E390[];
extern s16 g_player2[56];
extern s16 g_player1[56];

void player_shots_update(void) {
    u8 *saved_a4;
    u8 *saved_a5;
    u32 t;

    reg_a6 = (u8 *)D_0029E390;
    reg_d6.h[0] = g_side_scroll_step[0];
    g_player_shot_count = 0;
    saved_a4 = reg_a4;
    saved_a5 = reg_a5;
    reg_a4 = (u8 *)((u8 *)g_player1);
    reg_a5 = &(*(u8 *)&g_p1_hyper_active);
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = 1;
    reg_d6.h[1] = reg_tmp6.h[0];
loop_1:
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    reg_d7.w = 0x23;
loop_2:
    reg_d1.h[0] = ENTITY(reg_a6)->flags.h;
    if (reg_d1.h[0] == 0) goto next_1;
    g_player_shot_count += 1;
    ENTITY(reg_a6)->x.h -= reg_d6.h[0];
    reg_d0.w = 0xF;
    reg_d0.h[0] &= reg_d1.h[0];
    player_shot_update_routines[reg_d0.h[0]]();
next_1:
    reg_a6 += 0x30;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (u16) t << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_a4 = (u8 *)((u8 *)g_player2);
    reg_a5 = &(*(u8 *)&g_p2_hyper_active);
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_a4 = saved_a4;
    reg_a5 = saved_a5;
}

s32 sfx_enemy_fire_0();
s32 velocity_from_dir256();
s32 sparks_spawn_for_shot();
extern u16 player_shot_1_flight_table[];
extern u16 player_shot_1_impact_table[];
extern u16 g_two_player_game;

void player_shot_1_update(void) {
    if (reg_d0.h[0] != 0) goto block_main;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x40;
    if (!(reg_tmp.b[0] & 0x40)) goto block_obj;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 1;
    if (reg_tmp.b[0] & 1) goto block_first;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x30);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x32);
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    ENTITY(reg_a6)->x.h += reg_d1.h[0];
block_obj:
    ENTITY(reg_a6)->attr.b.flip ^= 0x40;
    player_shot_draw_a();
    return;
block_first:
    ENTITY(reg_a6)->flags.h |= 8;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_dir256();
    *(u16 *)(reg_a6 + 0x2C) = reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x2E) = reg_d3.h[0];
    if (ENTITY(reg_a6)->flags.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
    reg_a0 = (u8 *)player_shot_1_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    ENTITY(reg_a6)->offset_y.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->offset_x.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->look.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    goto block_anim;
block_clr:
    ENTITY(reg_a6)->flags.h = 0;
    return;
block_anim:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x2E);
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    if ((s32)ENTITY(reg_a6)->y.h >= 0x8000) goto block_clr;
    ENTITY(reg_a6)->x.h += reg_d1.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xC000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xC000;
    if ((s32)reg_tmp.h[0] > 0x4000) goto block_clr;
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (*(s16 *)(reg_a6 + 0x24) >= 0) goto skip_1;
    *(u16 *)(reg_a6 + 0x24) = 4;
skip_1:
    player_shot_draw_a();
    return;
block_main:
    if (reg_d1.sb[0] >= 0) goto block_anim;
block_touch:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 2;
    if (!(reg_tmp.b[0] & 2)) goto block_touch_first;
loop_1:
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if ((s32)reg_tmp.h[0] < 4) goto block_clr;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x2E);
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    ENTITY(reg_a6)->x.h += reg_d1.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    player_shot_draw_a();
    return;
block_touch_first:
    if (g_two_player_game == 0) goto skip_2;
    reg_d0.w = 0x14;
    sparks_spawn_for_shot();
skip_2:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2C);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x2E);
    if (!(ENTITY(reg_a6)->flags.b[1] & 1)) goto skip_4;
    reg_d3.h[0] = 8;
    if (!(*(u8 *)(reg_a6 + 0x28) & 4)) goto skip_3;
    reg_d3.h[0] = 0xA;
    if (*(u16 *)(reg_a6 + 0x2A) != reg_d3.h[0]) goto skip_4;
skip_3:
    ENTITY(reg_a6)->y.h -= 0x200;
skip_4:
    player_shot_jitter_half();
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    ENTITY(reg_a6)->x.h += reg_d2.h[0];
    reg_d0.h[0] = (s16)reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16)reg_d2.h[0] >> 2;
    *(u16 *)(reg_a6 + 0x2C) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x2E) = reg_d2.h[0];
    sfx_enemy_fire_0();
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
    reg_a0 = (u8 *)player_shot_1_impact_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    ENTITY(reg_a6)->offset_y.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->offset_x.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->look.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->misc.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x24) = *(u16 *)reg_a0;
    reg_a0 += 2;
    goto loop_1;
}

extern u16 player_shot_2_flight_table[];
extern u16 player_shot_2_impact_table[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void player_shot_2_update(void) {
    if (reg_d0.h[0] != 1) goto next_100;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x40;
    if (!(reg_tmp.b[0] & 0x40)) goto next_5;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 1;
    if (reg_tmp.b[0] & 1) goto next_10;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x30);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x32);
    W(2) += reg_d0.h[0];
    W(4) += reg_d1.h[0];
next_5:
    ENTITY(reg_a6)->attr.b.flip ^= 0x40;
    player_shot_draw_a();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_2_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(2) += reg_d0.h[0];
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_dir256();
    W(0x2C) = reg_d2.h[0];
    W(0x2E) = reg_d3.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    goto block_anime;
block_clr:
    W(0) = 0;
    goto block_rts;
block_anime:
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    if (!((s32) W(2) < 0x7800)) goto block_clr;
    W(4) += reg_d1.h[0];
    reg_d0.h[0] = W(4);
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xB800;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x800;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xB800;
    if (!((s32) reg_tmp.h[0] < 0x4801)) goto block_clr;
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 4;
next_60:
    player_shot_draw_a();
    goto block_rts;
next_100:
    if (reg_d1.sb[0] >= 0) goto block_anime;
block_touch:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 2;
    if (!(reg_tmp.b[0] & 2)) goto next_200;
loop_110:
    reg_tmp.h[0] = W(0x24);
    W(0x24) -= 4;
    if ((s32) reg_tmp.h[0] < 4) goto block_clr;
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    W(4) += reg_d1.h[0];
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    player_shot_2_frame_set();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    sparks_spawn_for_shot();
next_220:
    reg_d0.h[0] = W(0x2C);
    reg_d2.h[0] = W(0x2E);
    if (!(ENTITY(reg_a6)->flags.b[1] & 1)) goto next_240;
    reg_d3.h[0] = 8;
    if (!(reg_a6[0x28] & 4)) goto next_230;
    reg_d3.h[0] = 0xA;
    if (W(0x2A) != reg_d3.h[0]) goto next_240;
next_230:
    W(2) += 0x300;
next_240:
    player_shot_jitter_half();
    W(2) += reg_d0.h[0];
    W(4) += reg_d2.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] >> 2;
    W(0x2C) = reg_d0.h[0];
    W(0x2E) = reg_d2.h[0];
    sfx_enemy_fire_0();
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_2_impact_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x24) = *(u16 *)reg_a0;
    reg_a0 += 2;
    goto loop_110;
block_rts:
    return;
}

extern u16 player_shot_3_flight_table[];
extern u16 player_shot_3_impact_table[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void player_shot_3_update(void) {
    if (reg_d0.h[0] != 2) goto next_100;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x40;
    if (!(reg_tmp.b[0] & 0x40)) goto next_5;
    ENTITY(reg_a6)->flags.b[1] |= 1;
    goto next_10;
next_5:
    player_shot_draw_b();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_3_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_dir256();
    W(0x2C) = reg_d2.h[0];
    W(0x2E) = reg_d3.h[0];
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(0xA) = *(u16 *)reg_a0;
    W(0xC) = *(u16 *)(reg_a0 + 2);
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    goto block_anime;
block_clr:
    W(0) = 0;
    goto block_rts;
block_anime:
    ENTITY(reg_a6)->flags.b[1] |= 1;
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    if (!((s32) W(2) < 0x7800)) goto block_clr;
    W(4) += reg_d1.h[0];
    reg_d0.h[0] = W(4);
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xC000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x400;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xC000;
    if (!((s32) reg_tmp.h[0] < 0x4001)) goto block_clr;
    player_shot_draw_b();
    goto block_rts;
next_100:
    if (reg_d1.sb[0] >= 0) goto block_anime;
block_touch:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 2;
    if (!(reg_tmp.b[0] & 2)) goto next_200;
loop_110:
    reg_tmp.h[0] = W(0x24);
    W(0x24) -= 4;
    if ((s32) reg_tmp.h[0] < 4) goto block_clr;
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    player_shot_draw_b();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    sparks_spawn_for_shot();
next_220:
    reg_d0.h[0] = W(0x2C);
    reg_d2.h[0] = W(0x2E);
    player_shot_jitter_quarter();
    W(2) += reg_d0.h[0];
    W(4) += reg_d2.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] >> 2;
    W(0x2C) = reg_d0.h[0];
    W(0x2E) = reg_d2.h[0];
    sfx_enemy_fire_0();
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_3_impact_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x24) = *(u16 *)reg_a0;
    reg_a0 += 2;
    goto loop_110;
block_rts:
    return;
}

extern u16 player_shot_4_flight_table[];
extern u16 player_shot_4_impact_table[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void player_shot_4_update(void) {
    if (reg_d0.h[0] != 3) goto next_100;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x40;
    if (!(reg_tmp.b[0] & 0x40)) goto next_5;
    ENTITY(reg_a6)->flags.b[1] |= 1;
    goto next_10;
next_5:
    player_shot_draw_b();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_4_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_dir256();
    W(0x2C) = reg_d2.h[0];
    W(0x2E) = reg_d3.h[0];
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(0xA) = *(u16 *)reg_a0;
    W(0xC) = *(u16 *)(reg_a0 + 2);
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    goto block_anime;
block_clr:
    W(0) = 0;
    goto block_rts;
block_anime:
    ENTITY(reg_a6)->flags.b[1] |= 1;
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    if (!((s32) W(2) < 0x7400)) goto block_clr;
    W(4) += reg_d1.h[0];
    reg_d0.h[0] = W(4);
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xBC00;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x600;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xBC00;
    if (!((s32) reg_tmp.h[0] < 0x4401)) goto block_clr;
    player_shot_draw_b();
    goto block_rts;
next_100:
    if (reg_d1.sb[0] >= 0) goto block_anime;
block_touch:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 2;
    if (!(reg_tmp.b[0] & 2)) goto next_200;
loop_110:
    reg_tmp.h[0] = W(0x24);
    W(0x24) -= 4;
    if ((s32) reg_tmp.h[0] < 4) goto block_clr;
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    player_shot_draw_b();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    sparks_spawn_for_shot();
next_220:
    reg_d0.h[0] = W(0x2C);
    reg_d2.h[0] = W(0x2E);
    player_shot_jitter_quarter();
    W(2) += reg_d0.h[0];
    W(4) += reg_d2.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] >> 2;
    W(0x2C) = reg_d0.h[0];
    W(0x2E) = reg_d2.h[0];
    sfx_enemy_fire_0();
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_4_impact_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x24) = *(u16 *)reg_a0;
    reg_a0 += 2;
    goto loop_110;
block_rts:
    return;
}

extern u16 player_shot_5_flight_table[];
extern u16 player_shot_5_impact_table[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void player_shot_5_update(void) {
    if (reg_d0.h[0] != 4) goto next_100;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x40;
    if (!(reg_tmp.b[0] & 0x40)) goto next_5;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 1;
    if (reg_tmp.b[0] & 1) goto next_10;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x30);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x32);
    W(2) += reg_d0.h[0];
    W(4) += reg_d1.h[0];
next_5:
    ENTITY(reg_a6)->attr.b.flip ^= 0x40;
    player_shot_draw_a();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_5_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(2) += reg_d0.h[0];
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_dir256();
    W(0x2C) = reg_d2.h[0];
    W(0x2E) = reg_d3.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    goto block_anime;
block_clr:
    W(0) = 0;
    goto block_rts;
block_anime:
    ENTITY(reg_a6)->flags.b[1] |= 1;
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    if (!((s32) W(2) < 0x8000)) goto block_clr;
    W(4) += reg_d1.h[0];
    reg_d0.h[0] = W(4);
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xB000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0xC00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xB000;
    if (!((s32) reg_tmp.h[0] < 0x5001)) goto block_clr;
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 4;
next_60:
    player_shot_draw_a();
    goto block_rts;
next_100:
    if (reg_d1.sb[0] >= 0) goto block_anime;
block_touch:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 2;
    if (!(reg_tmp.b[0] & 2)) goto next_200;
loop_110:
    reg_tmp.h[0] = W(0x24);
    W(0x24) -= 4;
    if ((s32) reg_tmp.h[0] < 4) goto block_clr;
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    W(4) += reg_d1.h[0];
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    player_shot_draw_a();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    sparks_spawn_for_shot();
next_220:
    reg_d0.h[0] = W(0x2C);
    reg_d2.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    W(4) += reg_d2.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] >> 2;
    W(0x2C) = reg_d0.h[0];
    W(0x2E) = reg_d2.h[0];
    sfx_enemy_fire_0();
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_5_impact_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x24) = *(u16 *)reg_a0;
    reg_a0 += 2;
    goto loop_110;
block_rts:
    return;
}

extern u16 player_shot_6_flight_table[];
extern u16 player_shot_6_impact_table[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void player_shot_6_update(void) {
    if (reg_d0.h[0] != 5) goto next_100;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x40;
    if (!(reg_tmp.b[0] & 0x40)) goto next_5;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 1;
    if (reg_tmp.b[0] & 1) goto next_10;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x30);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x32);
    W(2) += reg_d0.h[0];
    W(4) += reg_d1.h[0];
next_5:
    ENTITY(reg_a6)->attr.b.flip ^= 0x40;
    player_shot_draw_a();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_6_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(2) += reg_d0.h[0];
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_dir256();
    W(0x2C) = reg_d2.h[0];
    W(0x2E) = reg_d3.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    goto block_anime;
block_clr:
    W(0) = 0;
    goto block_rts;
block_anime:
    ENTITY(reg_a6)->flags.b[1] |= 1;
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    if (!((s32) W(2) < 0x8000)) goto block_clr;
    W(4) += reg_d1.h[0];
    reg_d0.h[0] = W(4);
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xB000;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0xC00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xB000;
    if (!((s32) reg_tmp.h[0] < 0x5001)) goto block_clr;
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 4;
next_60:
    player_shot_draw_a();
    goto block_rts;
next_100:
    if (reg_d1.sb[0] >= 0) goto block_anime;
block_touch:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 2;
    if (!(reg_tmp.b[0] & 2)) goto next_200;
loop_110:
    reg_tmp.h[0] = W(0x24);
    W(0x24) -= 4;
    if ((s32) reg_tmp.h[0] < 4) goto block_clr;
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    W(4) += reg_d1.h[0];
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    player_shot_draw_a();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    sparks_spawn_for_shot();
next_220:
    reg_d0.h[0] = W(0x2C);
    reg_d2.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    W(4) += reg_d2.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] >> 2;
    W(0x2C) = reg_d0.h[0];
    W(0x2E) = reg_d2.h[0];
    sfx_enemy_fire_0();
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_6_impact_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x24) = *(u16 *)reg_a0;
    reg_a0 += 2;
    goto loop_110;
block_rts:
    return;
}

extern u16 player_shot_7_flight_table[];
extern u16 player_shot_7_impact_table[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void player_shot_7_update(void) {
    if (reg_d0.h[0] != 6) goto next_100;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x40;
    if (!(reg_tmp.b[0] & 0x40)) goto next_5;
    ENTITY(reg_a6)->flags.b[1] |= 1;
    goto next_10;
next_5:
    player_shot_draw_b();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_7_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_dir256();
    W(0x2C) = reg_d2.h[0];
    W(0x2E) = reg_d3.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    goto block_anime;
block_clr:
    W(0) = 0;
    goto block_rts;
block_anime:
    ENTITY(reg_a6)->flags.b[1] |= 1;
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    if (!((s32) W(2) < 0x7800)) goto block_clr;
    W(4) += reg_d1.h[0];
    reg_d0.h[0] = W(4);
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xB400;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0xA00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xB400;
    if (!((s32) reg_tmp.h[0] < 0x4C01)) goto block_clr;
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 8;
next_60:
    player_shot_draw_b();
    goto block_rts;
next_100:
    if (reg_d1.sb[0] >= 0) goto block_anime;
block_touch:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 2;
    if (!(reg_tmp.b[0] & 2)) goto next_200;
loop_110:
    reg_tmp.h[0] = W(0x24);
    W(0x24) -= 4;
    if ((s32) reg_tmp.h[0] < 4) goto block_clr;
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    W(4) += reg_d1.h[0];
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    player_shot_draw_b();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    sparks_spawn_for_shot();
next_220:
    reg_d0.h[0] = W(0x2C);
    reg_d2.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    W(4) += reg_d2.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] >> 2;
    W(0x2C) = reg_d0.h[0];
    W(0x2E) = reg_d2.h[0];
    sfx_enemy_fire_0();
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_7_impact_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x24) = *(u16 *)reg_a0;
    reg_a0 += 2;
    goto loop_110;
block_rts:
    return;
}

extern u16 player_shot_8_flight_table[];
extern u16 player_shot_8_impact_table[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void player_shot_8_update(void) {
    if (reg_d0.h[0] != 7) goto next_100;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x40;
    if (!(reg_tmp.b[0] & 0x40)) goto next_5;
    ENTITY(reg_a6)->flags.b[1] |= 1;
    goto next_10;
next_5:
    player_shot_draw_b();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_8_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_dir256();
    W(0x2C) = reg_d2.h[0];
    W(0x2E) = reg_d3.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    goto block_anime;
block_clr:
    W(0) = 0;
    goto block_rts;
block_anime:
    ENTITY(reg_a6)->flags.b[1] |= 1;
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    if (!((s32) W(2) < 0x7800)) goto block_clr;
    W(4) += reg_d1.h[0];
    reg_d0.h[0] = W(4);
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xB400;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0xA00;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0xB400;
    if (!((s32) reg_tmp.h[0] < 0x4C01)) goto block_clr;
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 8;
next_60:
    player_shot_draw_b();
    goto block_rts;
next_100:
    if (reg_d1.sb[0] >= 0) goto block_anime;
block_touch:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 2;
    if (!(reg_tmp.b[0] & 2)) goto next_200;
loop_110:
    reg_tmp.h[0] = W(0x24);
    W(0x24) -= 4;
    if ((s32) reg_tmp.h[0] < 4) goto block_clr;
    reg_d0.h[0] = W(0x2C);
    reg_d1.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    W(4) += reg_d1.h[0];
    reg_tmp.h[1] = W(0x1E);
    reg_tmp.h[0] = W(0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    player_shot_draw_b();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    sparks_spawn_for_shot();
next_220:
    reg_d0.h[0] = W(0x2C);
    reg_d2.h[0] = W(0x2E);
    W(2) += reg_d0.h[0];
    W(4) += reg_d2.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] >> 2;
    W(0x2C) = reg_d0.h[0];
    W(0x2E) = reg_d2.h[0];
    sfx_enemy_fire_0();
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_8_impact_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    W(6) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0xE) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
    W(0x24) = *(u16 *)reg_a0;
    reg_a0 += 2;
    goto loop_110;
block_rts:
    return;
}

void player_shot_draw_unused(void) {
}
