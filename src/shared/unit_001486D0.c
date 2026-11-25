#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void func_0014BE20(void);
void func_0014CAE0(void);

s32 entity_draw_with_player_shots();                            /* extern */

void func_001486D0(void) {
    reg_a0 = (u8 *)(((s32)reg_a6));
    func_0014BE20();
    entity_draw_with_player_shots();
}

void func_00148700(void) {
    reg_a0 = (u8 *)(((s32)reg_a6));
    func_0014BE20();
    entity_draw_with_player_shots();
}

s32 entity_draw_with_player_shots_zoom();
extern u16 D_00257800[];

void func_00148730(void) {
    u32 temp_s0;

    temp_s0 = reg_d6.w;
    reg_d6.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *)(D_00257800);
    reg_d6.h[0] *= 2;
    reg_d6.h[1] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d6.h[0] = ((reg_d6.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d6.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    entity_draw_with_player_shots_zoom();
    reg_d6.w = temp_s0;
    reg_a0 = (u8 *)(reg_a6);
    func_0014BE20();
}

s32 func_00201330();                            /* extern */

void func_00148800(void) {
    func_00201330();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] += reg_d1.h[0];
    func_00201330();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d2.h[0] += reg_d1.h[0];
}

s32 func_00201330();

void func_00148860() {
    func_00201330();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 2);
    ENTITY(reg_a6)->y.h += reg_d1.h[0];
    func_00201330();
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 2);
    ENTITY(reg_a6)->x.h += reg_d1.h[0];
}

typedef void (*Fn)();

extern u8 D_00257820[];
extern u16 g_player_shot_count;
extern u8 g_p2_hyper_active_as_u8;
extern u8 g_p1_hyper_active_as_u8;
extern u16 g_side_scroll_step[];
extern u8 D_0029E390[];
extern u8 g_player2_as_u8_a[];
extern u8 g_player1_as_u8_a[];

void func_001488C0(void) {
    u8 *saved_a4;
    u8 *saved_a5;
    u32 t;

    reg_a6 = (u8 *)D_0029E390;
    reg_d6.h[0] = g_side_scroll_step[0];
    g_player_shot_count = 0;
    saved_a4 = reg_a4;
    saved_a5 = reg_a5;
    reg_a4 = (u8 *)g_player1_as_u8_a;
    reg_a5 = &g_p1_hyper_active_as_u8;
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
    ((Fn)*(u32 *)((u8 *)D_00257820 + (reg_d0.h[0] * 4)))();
next_1:
    reg_a6 += 0x30;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (u16) t << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_a4 = (u8 *)g_player2_as_u8_a;
    reg_a5 = &g_p2_hyper_active_as_u8;
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
s32 func_00209F20();
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
    func_001486D0();
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
    reg_a0 = (u8 *)reg_tmp.w;
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
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (*(s16 *)(reg_a6 + 0x24) >= 0) goto skip_1;
    *(u16 *)(reg_a6 + 0x24) = 4;
skip_1:
    func_001486D0();
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
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_001486D0();
    return;
block_touch_first:
    if (g_two_player_game == 0) goto skip_2;
    reg_d0.w = 0x14;
    func_00209F20();
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
    func_00148800();
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
    reg_a0 = (u8 *)reg_tmp.w;
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
    func_001486D0();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_2_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
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
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 4;
next_60:
    func_001486D0();
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
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_00148730();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    func_00209F20();
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
    func_00148800();
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
    reg_a0 = (u8 *) reg_tmp.w;
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
    func_00148700();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_3_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
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
    reg_a0 = (u8 *) reg_tmp.w;
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
    func_00148700();
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
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_00148700();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    func_00209F20();
next_220:
    reg_d0.h[0] = W(0x2C);
    reg_d2.h[0] = W(0x2E);
    func_00148860();
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
    reg_a0 = (u8 *) reg_tmp.w;
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
    func_00148700();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_4_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
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
    reg_a0 = (u8 *) reg_tmp.w;
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
    func_00148700();
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
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_00148700();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    func_00209F20();
next_220:
    reg_d0.h[0] = W(0x2C);
    reg_d2.h[0] = W(0x2E);
    func_00148860();
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
    reg_a0 = (u8 *) reg_tmp.w;
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
    func_001486D0();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_5_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
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
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 4;
next_60:
    func_001486D0();
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
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_001486D0();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    func_00209F20();
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
    reg_a0 = (u8 *) reg_tmp.w;
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
    func_001486D0();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_6_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
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
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 4;
next_60:
    func_001486D0();
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
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_001486D0();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    func_00209F20();
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
    reg_a0 = (u8 *) reg_tmp.w;
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
    func_00148700();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_7_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
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
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 8;
next_60:
    func_00148700();
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
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_00148700();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    func_00209F20();
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
    reg_a0 = (u8 *) reg_tmp.w;
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
    func_00148700();
    return;
next_10:
    W(0) |= 8;
    if (reg_d1.sb[0] < 0) goto block_touch;
    reg_d0.h[0] = W(0x26);
    reg_a0 = (u8 *) player_shot_8_flight_table;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
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
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    W(0x24) -= 4;
    if ((s16) W(0x24) >= 0) goto next_60;
    W(0x24) = 8;
next_60:
    func_00148700();
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
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = W(0x24);
    W(0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    W(0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    func_00148700();
    goto block_rts;
next_200:
    if (g_two_player_game == 0) goto next_220;
    reg_d0.w = 0x14;
    func_00209F20();
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
    reg_a0 = (u8 *) reg_tmp.w;
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

void func_0014BE20(void) {
}

s32 func_001A5A80();
s32 func_001AEA80();
s32 task_stop_self();
extern u8 g_game_frame_ran;
extern s16 g_score_task_active_as_s16;
extern u16 g_stage;
extern u8 g_replay_mode;

void score_task(void) {
    switch (reg_a5[3]) {
    case 0:
        goto block_1;
    }
    if (reg_a5[3] == 2) goto block_2;
    func_001AEA80();
    if (g_replay_mode != 2) goto next_1;
    if (g_stage != 0) goto next_1;
    if (g_game_frame_ran == 0) return;
next_1:
    func_001A5A80();
    return;
block_1:
    reg_a5[3] = 1;
    g_score_task_active_as_s16 = 1;
    return;
block_2:
    g_score_task_active_as_s16 = 0;
    task_stop_self();
}

s32 func_0012FA80();
s32 text_layer_clear();
s32 func_0012FB00();
s32 func_0013B2E0(s32, s32, s32, s32);
s32 stage_map_reset();
extern u8 D_0026A3F0[];
extern u8 D_0028E368;
extern u8 D_0028E378;
extern u8 g_replay_buffer_state;

void func_0014BEC0(void) {
    g_replay_buffer_state = 2;
    D_0028E378 = 0xFF;
    D_0028E368 = 0;
    func_0012FA80();
    text_layer_clear();
    func_0012FB00();
    stage_map_reset();
    *(s8 *)(reg_a5 + 3) = 1;
    *(s16 *)(reg_a5 + 8) = 0x4400;
    *(s16 *)(reg_a5 + 0xA) = 0x1C00;
    *(s16 *)(reg_a5 + 0x14) = 0;
    *(s16 *)(reg_a5 + 0x12) = 0;
    *(s16 *)(reg_a5 + 0x10) = 0;
    *(s8 *)(reg_a5 + 0x17) = 1;
    *(s8 *)(reg_a5 + 0x16) = 0;
    *(s16 *)(reg_a5 + 0x18) = 0;
    *(s16 *)(reg_a5 + 4) = 0x1E0;
    reg_a0 = D_0026A3F0;
    func_0013B2E0(0x1E0, 0x1C00, 0x4400, 1);
    *(s16 *)(reg_a5 + 0x1A) = 0x20;
    *(s16 *)(reg_a5 + 0x1C) = 0x20;
}

s32 func_001353E0();
s32 func_0013B190();
s32 task_start();

void func_0014BF90() {
    *(u16 *)(reg_a5 + 0x1C) -= 1;
    if (*(u16 *)(reg_a5 + 0x1C) == 0) {
        reg_d0.w = 0;
        reg_d1.h[0] = 6;
        func_001353E0();
        func_0013B190();
        reg_d0.h[0] = 0xC;
        task_start();
        task_stop_self();
    }
}

s32 func_00133070();
s32 music_play_bgm12();
s32 sprite_draw_layer1();
s32 rng_next_masked();
s32 func_0022B660();
s32 replay_start_result();
extern u16 D_0026A380[];
extern u16 D_0026A3A0[];
extern u16 D_0026A3C0[];
extern u8 D_0028ED64;
extern u8 g_simulation_active;

void game_over_task(void) {
    u16 t;
    u8 st;

    st = *(u8 *)(reg_a5 + 3);
    if (st == 0) {
        func_0014BEC0();
        return;
    }
    if (st == 2) {
        if ((D_0028ED64 != 0) && (func_00133070(reg_a5) != 0)) {
            if (func_0022B660() == 0) {
                return;
            }
            goto block_1;
        }
        if ((g_replay_mode == 2) || (g_simulation_active != 0)) {
            replay_start_result();
            return;
        }
block_1:
        g_replay_mode = 0;
        func_0014BF90();
        return;
    }
    t = *(u16 *)(reg_a5 + 0x1A);
    if (t == 0) goto next_1;
    *(u16 *)(reg_a5 + 0x1A) = t - 1;
    if (*(u16 *)(reg_a5 + 0x1A) != 0) goto next_1;
    music_play_bgm12();
next_1:
    *(u16 *)(reg_a5 + 4) -= 1;
    if ((s16) *(u16 *)(reg_a5 + 4) >= 0) goto next_2;
    *(u8 *)(reg_a5 + 3) = 2;
next_2:
    if (*(u16 *)(reg_a5 + 0x10) != 0) goto next_6;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x12);
    *(u8 *)(reg_a5 + 0x15) -= 1;
    if ((s8) *(u8 *)(reg_a5 + 0x15) >= 0) goto next_3;
    *(u8 *)(reg_a5 + 0x15) = *(u8 *)(reg_a5 + 0x14);
    *(u16 *)(reg_a5 + 0x12) += 4;
    if (reg_d1.h[0] != 0x1C) goto next_3;
    *(u16 *)(reg_a5 + 0x12) = 0;
    *(u16 *)(reg_a5 + 0x18) += 1;
    if (*(u16 *)(reg_a5 + 0x18) == 0x14) goto next_5;
    rng_next_masked();
    reg_d0.h[0] >>= 3;
    st = reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x17) = st;
    if (st != 0) goto next_3;
    *(u8 *)(reg_a5 + 0x16) += 1;
    if ((s32) *(u8 *)(reg_a5 + 0x16) < 3) goto next_3;
    *(u8 *)(reg_a5 + 0x17) = 1;
next_3:
    reg_a0 = (u8 *)(D_0026A380);
    if (*(u8 *)(reg_a5 + 0x17) != 0) goto next_4;
    reg_a0 = (u8 *)(D_0026A3A0);
next_4:
    *(u16 *)(reg_a5 + 0xC) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0xE) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    goto next_8;
next_5:
    *(u16 *)(reg_a5 + 0x10) = 1;
    *(u16 *)(reg_a5 + 0x14) = 0;
next_6:
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x12);
    *(u8 *)(reg_a5 + 0x15) -= 1;
    if ((s8) *(u8 *)(reg_a5 + 0x15) >= 0) goto next_8;
    *(u8 *)(reg_a5 + 0x15) = *(u8 *)(reg_a5 + 0x14);
    *(u16 *)(reg_a5 + 0x12) += 4;
    if (reg_d0.h[0] != 0x1C) goto next_7;
    *(u16 *)(reg_a5 + 0x12) = 0;
    *(u8 *)(reg_a5 + 3) = 2;
next_7:
    reg_a0 = (u8 *)(D_0026A3C0);
    *(u16 *)(reg_a5 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0xE) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
next_8:
    reg_d1.h[1] = *(u16 *)(reg_a5 + 8);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0xA);
    reg_d1.w += 0xE600E400;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0xC);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0xE);
    reg_d3.h[0] = 0x1AE0;
    reg_d4.h[0] = 2;
    sprite_draw_layer1();
}

extern u16 stage_ground_tables[];
extern u16 g_stage_x4;

void func_0014C3B0(void) {
    reg_a0 = (u8 *)(stage_ground_tables);
    reg_d0.h[0] = g_stage_x4;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
}

extern u8 D_002526B0[];
extern u8 D_0029BF50[];
extern s32 D_0029C050_as_s32_a[];

void func_0014C450(void) {
    memset(D_0029BF50, 0, 0x104);
    reg_a0 = D_002526B0;
    reg_a0 += g_stage_x4;
    D_0029C050_as_s32_a[0] = *(s32 *)reg_a0;
}

extern u8 g_ground_no_draw;
extern u8 *reg_call_target_as_u8_p;

void func_0014C4B0(void) {
    u32 temp_s0;

    if ((g_simulation_active == 0) || (g_ground_no_draw == 0) || (g_stage != 2)) {
        reg_a6 = D_0029BF50;
        reg_d7.w = 7;
        do {
            if (ENTITY(reg_a6)->flags.b[1] != 0) {
                reg_d0.h[0] = g_side_scroll_step[0];
                ENTITY(reg_a6)->x.h -= reg_d0.h[0];
                reg_tmp.h[1] = ENTITY(reg_a6)->offset_x.h;
                reg_tmp.h[0] = ENTITY(reg_a6)->draw.h;
                reg_a1 = (u8 *)reg_tmp.w;
                reg_call_target_as_u8_p = reg_a1;
                temp_s0 = reg_d7.w;
                ((Fn)reg_call_target_as_u8_p)();
                reg_d7.w = temp_s0;
            }
            reg_a6 += 0x20;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}

typedef void (*Fn)(void);

extern u8 *D_0029C050[];
extern Fn reg_call_target_as_Fn;

void func_0014C590(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u32 t1;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a6 = (u8 *)D_0029BF50;
    reg_d7.w = 7;
loop_1:
    if (ENTITY(reg_a6)->flags.b[1] != 0) goto next_1;
    ENTITY(reg_a6)->flags.b[1] = 0x80;
    ENTITY(reg_a6)->y.h = reg_d1.h[1];
    ENTITY(reg_a6)->x.h = reg_d1.h[0];
    reg_a1 = D_0029C050[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 += reg_d0.h[0];
    reg_a1 = *(u8 **)reg_a1;
    reg_call_target_as_Fn = (Fn)reg_a1;
    reg_call_target_as_Fn();
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
    return;
next_1:
    reg_a6 += 0x20;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(u16)t1 << 0x30) >> 0x30) >= 0) goto loop_1;
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

extern u16 g_scroll_line;
extern u8 D_0029C082[];

void func_0014C7B0(void) {
    reg_a0 = (u8 *)D_0029C082;
    reg_a1 = reg_a5 + 0xA;
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 0xE);
    reg_a2 = (u8 *)reg_tmp.w;
    if (reg_a2 == 0) return;
    *(u16 *)(reg_a0 + 0x16) -= 1;
    if (0 >= (s16) *(u16 *)(reg_a0 + 0x16)) {
        reg_d0.h[0] = *(u16 *)(reg_a0 + 0x10);
        if ((s16) reg_d0.h[0] != -1) {
            *(u16 *)(reg_a0 + 0x10) -= 1;
            if (0 >= (s16) *(u16 *)(reg_a0 + 0x10)) {
                *(u16 *)(reg_a0 + 0xC) = 0U;
                *(u16 *)(reg_a0 + 0xE) = 0U;
                *(s16 *)(reg_a5 + 8) = 0;
                g_scroll_line = *(u16 *)(reg_a0 + 0x18);
                return;
            }
        }
        *(u16 *)(reg_a0 + 0x16) = (u16) *(u16 *)(reg_a0 + 0x14);
        reg_tmp.w = (u32)reg_a2;
        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
    }
}

extern s16 D_0029C080_as_s16_a[];
extern s16 D_0029C08E[];
extern s16 D_0029C090[];
extern u8 D_0029C09E[];
extern s16 D_0029C0AA[];
extern s16 D_0029C0AC[];

void func_0014C8A0(void) {
    u8 *var_a0;
    u32 temp_s0;
    u32 temp_s1;

    func_0014C3B0();
    memset(D_0029C080_as_s16_a, 0, 0x40);
    reg_a1 = (u8 *)D_0029C082;
    reg_d1.w = 1;
    var_a0 = (u8 *)(D_0029C09E);
    do {
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_tmp.h[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 = (u8 *)(reg_tmp.w);
        *(u16 *)(reg_a1 + 4) = *(u16 *)reg_a2;
        reg_a2 += 2;
        *(u16 *)(reg_a1 + 6) = *(u16 *)reg_a2;
        reg_a2 += 2;
        *(u16 *)(reg_a1 + 8) = *(u16 *)reg_a2;
        reg_a2 += 2;
        *(u16 *)(reg_a1 + 0xA) = *(u16 *)reg_a2;
        reg_a2 += 2;
        reg_tmp.w = (u32)reg_a2;
        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
        reg_a1 = (u8 *)D_0029C09E;
    } while ((s16)(--reg_d1.h[0]) >= 0);
    if (g_scroll_line != 0) {
        D_0029C080_as_s16_a[0] = 1;
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x10);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x12);
        reg_a3 = (u8 *)reg_tmp.w;
        temp_s0 = (u32)reg_a3;
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0xA);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0xC);
        reg_d7.w = 0;
        reg_a4 = (u8 *)reg_tmp.w;
        temp_s1 = (u32)reg_a4;
        do {
            func_0014CAE0();
            var_a0 = (u8 *) g_scroll_line;
            reg_d7.h[0] += 1;
        } while ((u32)var_a0 != reg_d7.h[0]);
        reg_tmp.w = temp_s0;
        reg_a4 = (u8 *)temp_s1;
        reg_a3 = (u8 *)temp_s0;
        *(u16 *)(reg_a5 + 0x10) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0x12) = (u16) reg_tmp.h[0];
        reg_tmp.w = (u32)reg_a4;
        *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0xC) = (u16) reg_tmp.h[0];
        reg_d0.w = 0;
        *(s16 *)(reg_a5 + 8) = 0;
        D_0029C08E[0] = 0;
        D_0029C090[0] = 0;
        D_0029C0AA[0] = 0;
        D_0029C0AC[0] = 0;
    }
    D_0029C080_as_s16_a[0] = 0;
}


void func_0014CAD0(void) {
    reg_d7.h[0] = g_scroll_line;
    func_0014CAE0();
}

extern u8 ground_event_routines[];
extern u16 D_0029C0BA[];
extern u16 D_0029C0BC[];
extern u16 D_0029C0BE[];

void func_0014CAE0(void) {
    u16 temp_a0;
    reg_a6 = (u8 *)D_0029C082;
    reg_d6.w = 1;
    do {
loop_1:
        reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
        reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
        reg_a1 = (u8 *)(reg_tmp.w);
        reg_d1.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        if (((s16)(reg_d1.h[0]) != -1) && ((reg_d1.h[0] & 0xFFFF) == reg_d7.h[0])) {
            reg_a1 += 2;
            temp_a0 = *(u16 *)reg_a1;
            reg_d2.h[0] = temp_a0;
            reg_a1 += 2;
            reg_a2 = (u8 *)ground_event_routines;
            reg_a2 += reg_d2.h[0];
            reg_tmp.h[1] = *(u16 *)reg_a2;
            reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
            reg_a2 = (u8 *) reg_tmp.w;
            reg_call_target = (Fn)(reg_a2);
            reg_call_target();
            reg_tmp.w = (u32)reg_a1;
            ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
            ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
            goto loop_1;
        }
        reg_a6 = (u8 *)D_0029C09E;
    } while ((s16)(--reg_d6.h[0]) >= 0);
    reg_d0.h[1] = D_0029C0BC[0];
    reg_d0.h[0] = D_0029C0BE[0];
    if (reg_d0.w != 0) {
        D_0029C0BA[0] -= 1;
        if (0 > (s16) D_0029C0BA[0]) {
            reg_a0 = (u8 *)reg_d0.w;
            reg_call_target = (Fn)((u8 *) reg_a0);
            reg_call_target();
            *(u32 *)D_0029C0BC = 0;
        }
    }
}

s32 sprite_palette_load();

void func_0014CC90(void) {
    u16 temp_a1;

    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = ENTITY(reg_a6)->x.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->offset_y.h;
    reg_a2 = (u8 *)(reg_tmp.w);
loop_1:
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a1 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a1;
    reg_a2 += 2;
    reg_a0 = (u8 *)reg_tmp.w;
    if ((u32)reg_a0 != -1U) {
        reg_d0.h[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        sprite_palette_load();
        reg_d2.h[0] -= 1;
        if (reg_d2.h[0] == 0) {
            reg_tmp.w = (u32)reg_a2;
            ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[1];
            ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[0];
        } else {
            goto loop_1;
        }
    }
}

void ground_event_01(void) {
    reg_a2 = reg_a5 + 0x10;
    if (reg_d6.h[0] != 0) {
        reg_a2 = reg_a5 + 0xA;
    }
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
    reg_a3 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d2.h[0] = reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (s16) reg_d1.h[0] << 5;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] += reg_d0.h[0];
    reg_a3 += (s16) reg_d1.h[0];
    reg_tmp.w = (u32)reg_a3;
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->look.h = (u16) reg_tmp.h[0];
    reg_tmp.w = (u32)reg_a3;
    *(u16 *)reg_a2 = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a2 + 2) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    ENTITY(reg_a6)->hit_x_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] += 1;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)->hit_y_plus.h = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
}

extern u16 *reg_a1_as_u16_p;
extern u16 *reg_a2_as_u16_p;
extern s32 reg_a5_as_s32;

void ground_event_02(void) {
    reg_a2_as_u16_p = (u16 *)(reg_a5_as_s32 + 0x22);
    if (reg_d6.h[0] != 0) {
        reg_a2_as_u16_p = (u16 *)(reg_a5_as_s32 + 0x1C);
    }
    *reg_a2_as_u16_p = *reg_a1_as_u16_p;
    reg_a1_as_u16_p += 1;
}


void ground_event_03(void) {
    *(u16 *)(reg_a5 + 8) = 1;
    reg_d0.h[0] = g_scroll_line;
    reg_d0.h[0] += 4;
    *(u16 *)(reg_a6 + 0x18) = (u16) reg_d0.h[0];
}

extern u16 g_side_scroll_x_prev[];
extern u16 D_0029C080[];

void ground_event_04(void) {
    u16 *temp_a0;
    u16 temp_a1;

    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    temp_a1 = *(u16 *)reg_a1;
    temp_a0 = ((u16 *)reg_a1) + 1;
    reg_d1.h[0] = temp_a1;
    reg_a1 = (u8 *)temp_a0;
    if (D_0029C080[0] == 0) {
        reg_d1.h[0] -= 0x800;
        reg_d1.h[0] -= g_side_scroll_x_prev[0];
        func_0014C590();
    }
}

extern u8 ground_event_sound_routines[];

void ground_event_05(void) {
    u32 temp_a1;
    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = ENTITY(reg_a6)->offset_x.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->draw.h;
    reg_a2 = (u8 *)(reg_tmp.w);
loop_1:
    reg_d0.h[0] = *(u16 *)reg_a2;
    temp_a1 = reg_d0.h[0];
    reg_a2 += 2;
    if ((s16)(temp_a1) != -1) {
        reg_a3 = (u8 *)ground_event_sound_routines;
        reg_d0.h[0] = temp_a1 + temp_a1;
        reg_d0.h[0] += reg_d0.h[0];
        reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_a3 = (u8 *) reg_tmp.w;
        reg_call_target = (Fn)(reg_a3);
        reg_call_target();
        reg_d2.h[0] -= 1;
        if (reg_d2.h[0] == 0) {
            reg_tmp.w = (u32)reg_a2;
            ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[1];
            ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[0];
        } else {
            goto loop_1;
        }
    }
}

void func_0014D0F0(void) {
    D_0029C0BA[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    D_0029C0BC[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    D_0029C0BE[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
}

void music_stop(void);

void ground_event_sound_01(void) {
    music_stop();
}

extern void music_fade_out(void);

void ground_event_sound_02(void) {
    reg_d1.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    music_fade_out();
}

extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];
extern s16 D_0029976E_as_s16_a[];

void ground_event_06(void) {
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if (reg_d0.h[0] == 1) {
        D_00299768[0] = 1;
    }
    if (reg_d0.h[0] == 2) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
    }
    if (reg_d0.h[0] == 3) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C_as_s16_a[0] = 1;
    }
    if (reg_d0.h[0] == 4) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C_as_s16_a[0] = 1;
        D_0029976E_as_s16_a[0] = 1;
    }
}
