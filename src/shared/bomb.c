#include "common.h"
#include "player.h"
#include "entity.h"

void spread_bomb_update(void);
void laser_bomb_update();
void laser_bomb_beam_draw(void);
void laser_bomb_beam_draw_fading(void);
void laser_bomb_tip_update(void);
void laser_bomb_muzzle_update(void);
void laser_bomb_impact_update(void);
void laser_bomb_beam_rebuild(void);
void laser_bomb_end(void);
void bomb_afterglow_end(void);
void bombs_clear(void);

extern u16 g_bomb_afterglow_timer;
extern u16 g_bomb_entities[];
extern u8 g_p2_options[];
extern u8 g_p1_options[];
extern u8 g_player2_as_u8_a[];
extern u8 g_player1_as_u8_a[];

void bombs_update(void) {
    u8 *sa5;

    reg_a6 = (u8 *)(g_bomb_entities);
    reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
    if ((s16) reg_d0.h[0] >= 0) {
        if (g_bomb_afterglow_timer != 0) {
            g_bomb_afterglow_timer -= 1;
            if (g_bomb_afterglow_timer == 0) {
                bomb_afterglow_end();
            }
        }
    } else {
        sa5 = (u8 *)(reg_a5);
        reg_a4 = (u8 *)g_p1_options;
        reg_a5 = (u8 *)g_player1_as_u8_a;
        if (ENTITY(reg_a6)->flags.sb[0] < 0) {
            reg_a4 = (u8 *)g_p2_options;
            reg_a5 = (u8 *)g_player2_as_u8_a;
        }
        reg_d0.h[0] &= 7;
        switch (reg_d0.h[0]) {
        case 3:
            goto block_1;
        }
        switch (reg_d0.h[0]) {
        case 0:
        case 2:
            spread_bomb_update();
            break;
        case 1:
        block_1:
            laser_bomb_update();
            break;
        }
        reg_a5 = sa5;
    }
}

typedef void (*Fn)();

extern u8 spread_bomb_phase1_template[];
extern u8 spread_bomb_phase2_template[];
extern u8 spread_bomb_phase3_template[];
s32 sfx_spread_bomb_a();
s32 sfx_spread_bomb_b();
s32 entity_draw_with_bombs();
s32 entity_draw_with_bombs_keep();
s32 sprite_draw_with_bombs_keep();
s32 rng_next_bit();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u8 spread_bomb_b_phase1_frames[];
extern u8 spread_bomb_b_phase2_frames[];
extern u8 spread_bomb_b_phase3_frames[];
extern u16 g_frame_mod2;
extern u16 g_side_scroll_step[];
extern u8 g_bomb_entities_as_u8_a[];

void spread_bomb_update(void) {
    u8 temp;

    reg_d1.h[0] = g_side_scroll_step[0];
    ENTITY(reg_a6)->x.h -= reg_d1.h[0];
    temp = ENTITY(reg_a6)->flags.b[1];
    if (temp & 1) goto block_a;
    ENTITY(reg_a6)->flags.b[1] = (u8) (temp | 1);
    reg_a0 = (u8 *)spread_bomb_phase1_template;
    reg_a1 = (u8 *)(reg_a6 + 2);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 0xC;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 = (u8 *)sfx_spread_bomb_a;
    reg_a1 += 2;
    switch (ENTITY(reg_a6)->flags.b[0] & 2) { case 0: goto next_1; }
    reg_tmp.w = (u32) spread_bomb_b_phase1_frames;
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)sfx_spread_bomb_b;
next_1:
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
    if (reg_a5 != g_player1_as_u8_a) goto next_2;
    vibration_start_pad1(0xC8, 0x64);
    goto block_a;
next_2:
    vibration_start_pad2(0xC8, 0x64);
block_a:
    if (*(u16 *)(reg_a6 + 0x28) != 0) goto block_c;
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] += *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d4.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    sprite_draw_with_bombs_keep();
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x23);
    *(u8 *)(reg_a6 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts_2;
    *(u8 *)(reg_a6 + 0x23) = (u8) *(u8 *)(reg_a6 + 0x22);
    if (*(u16 *)reg_a0 == 0xFFFF) goto block_b;
    reg_tmp.w = (u32) reg_a0;
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
block_rts_2:
    return;
block_b:
    reg_a0 = (u8 *)spread_bomb_phase2_template;
    reg_a1 = (u8 *)(reg_a6 + 6);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    if (!(ENTITY(reg_a6)->flags.b[0] & 2)) goto block_c;
    reg_tmp.w = (u32) spread_bomb_b_phase2_frames;
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
block_c:
    if (*(u16 *)(reg_a6 + 0x28) != 1) goto block_e;
    reg_d1.w = 0x40;
    rng_next_bit();
    if (reg_d0.b[0] != 0) goto next_3;
    reg_d1.h[0] *= 0xFFFF;
next_3:
    ENTITY(reg_a6)->x.h += reg_d1.h[0];
    if (g_frame_mod2 != 0) goto block_rts;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!((s32) reg_tmp.h[0] < 4)) goto next_4;
    *(u16 *)(reg_a6 + 0x2A) -= 1;
    if (*(u16 *)(reg_a6 + 0x2A) == 0) goto block_d;
    *(u16 *)(reg_a6 + 0x24) = 0x1C;
next_4:
    entity_draw_with_bombs();
    return;
block_d:
    reg_a0 = (u8 *)spread_bomb_phase3_template;
    reg_a1 = (u8 *)(reg_a6 + 6);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    if (!(ENTITY(reg_a6)->flags.b[0] & 2)) goto block_e;
    reg_tmp.w = (u32) spread_bomb_b_phase3_frames;
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
block_e:
    temp = ENTITY(reg_a6)->flags.b[1];
    if (!(temp & 2)) goto next_5;
    ENTITY(reg_a6)->flags.b[1] = (u8) (temp & 0xFD);
    goto block_f;
next_5:
    ENTITY(reg_a6)->flags.b[1] = (u8) (temp | 2);
    return;
block_f:
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    entity_draw_with_bombs_keep();
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    if (reg_tmp.w == -1U) goto block_g;
    reg_tmp.w = (u32) reg_a0;
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
    return;
block_g:
    reg_a0 = (u8 *)g_player1_as_u8_a;
    reg_d1.w = 0;
    reg_a6 = (u8 *)g_bomb_entities_as_u8_a;
    if (ENTITY(reg_a6)->flags.sb[0] >= 0) goto next_6;
    reg_a0 = (u8 *)g_player2_as_u8_a;
    reg_d1.w = 2;
next_6:
    reg_d0.b[0] = *(u8 *)(reg_a0 + 0x38);
    if ((s32) *(u8 *)(reg_a0 + 0x1B) <= (s32) reg_d0.b[0]) goto next_7;
    *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
next_7:
    g_bomb_afterglow_timer = 0x28;
    bombs_clear();
block_rts:
    return;
}

extern u8 laser_bomb_template[];
s32 sfx_laser_bomb_a();
s32 sfx_laser_bomb_b();
s32 func_0020A270();
extern u8 laser_bomb_b_base_frames[];
extern u8 laser_bomb_b_muzzle_frames[];
extern u8 laser_bomb_b_tip_frames[];
extern u8 laser_bomb_b_impact_frames[];
extern u8 laser_bomb_b_beam_frames[];
extern u8 laser_bomb_b_beam_table[];
extern s16 g_bomb_afterglow_timer_as_s16;
extern u16 g_laser_bomb_sizzle;

void laser_bomb_update(arg3)
    u16 arg3;
{
    u8 *temp_a1;
    u8 *var_a2;
    s64 temp_v0;
    s64 temp_v0_2;
    s64 temp_v0_3;
    s64 temp_v0_4;
    u16 *var_a1;
    u16 var_a0;
    u16 var_a3;
    var_a3 = arg3;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 1;
    if (!(reg_tmp.b[0] & 1)) {
        reg_a0 = laser_bomb_template;
        reg_a1 = (u8 *)(reg_a6 + 6);
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 0x7B0;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        var_a2 = (u8 *)(reg_a0 + 2);
        var_a1 = (u16 *)(reg_a1 + 2);
        reg_a0 = var_a2;
        reg_a1 = (u8 *)(var_a1);
        reg_d0.h[0] = *(u16 *)(reg_a5 + 2);
        reg_d0.h[0] += 0x7FFF + 0x7E01;
        *(u16 *)(reg_a6 + 0x7E2) = reg_d0.h[0];
        reg_a0 = (u8 *)sfx_laser_bomb_a;
        reg_d0.w = 0;
        g_laser_bomb_sizzle = reg_d0.h[0];
        if (ENTITY(reg_a6)->flags.b[0] & 2) {
            reg_tmp.w = (u32) laser_bomb_b_base_frames;
            ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
            reg_tmp.w = (u32) laser_bomb_b_beam_table;
            *(u16 *)(reg_a6 + 0x28) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x2A) = (u16) reg_tmp.h[0];
            reg_tmp.w = (u32) laser_bomb_b_beam_frames;
            *(u16 *)(reg_a6 + 0x2C) = (u16) reg_tmp.h[1];
            var_a3 = reg_tmp.h[0];
            *(u16 *)(reg_a6 + 0x2E) = var_a3;
            reg_tmp.w = (u32) laser_bomb_b_tip_frames;
            *(u16 *)(reg_a6 + 0x7FE) = (u16) reg_tmp.h[1];
            var_a2 = (u8 *) reg_tmp.h[0];
            *(u16 *)(reg_a6 + 0x800) = (u16) var_a2;
            reg_tmp.w = (u32) laser_bomb_b_muzzle_frames;
            *(u16 *)(reg_a6 + 0x82E) = (u16) reg_tmp.h[1];
            var_a1 = (u16 *) reg_tmp.h[0];
            *(u16 *)(reg_a6 + 0x830) = (u16) var_a1;
            reg_tmp.w = (u32) laser_bomb_b_impact_frames;
            *(u16 *)(reg_a6 + 0x85E) = (u16) reg_tmp.h[1];
            var_a0 = reg_tmp.h[0];
            *(u16 *)(reg_a6 + 0x860) = var_a0;
            reg_a0 = (u8 *)sfx_laser_bomb_b;
        }
        reg_call_target = (Fn)(reg_a0);
        reg_call_target();
        if (reg_a5 == g_player1_as_u8_a) {
            vibration_start_pad1(0xC8, 0x78);
        } else {
            vibration_start_pad2(0xC8, 0x78);
        }
    }
    reg_d0.h[1] = *(u16 *)(reg_a5 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x7E4) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x812) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x814) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x844) = (u16) reg_d0.h[0];
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        *(u16 *)(reg_a6 + 0x24) = (u16) *(u16 *)(reg_a6 + 0x26);
    }
    if (ENTITY(reg_a6)->hp.h == 0) {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
        reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
        reg_a0 = (u8 *) reg_tmp.w;
        ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x7FE);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x800);
        reg_a0 = (u8 *) reg_tmp.w;
        *(u16 *)(reg_a6 + 0x7EA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x7EC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x82E);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x830);
        reg_a0 = (u8 *) reg_tmp.w;
        *(u16 *)(reg_a6 + 0x81A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x81C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x85E);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x860);
        reg_a0 = (u8 *) reg_tmp.w;
        *(u16 *)(reg_a6 + 0x84A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x84C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->move.h -= 1;
        if (ENTITY(reg_a6)->move.h == 0) {
            ENTITY(reg_a6)->hp.h = 1U;
            goto block_40;
        }
block_36:
        laser_bomb_beam_draw();
        laser_bomb_tip_update();
        laser_bomb_muzzle_update();
        laser_bomb_impact_update();
        entity_draw_with_bombs();
        reg_a6 += 0x7E0;
        if (!(ENTITY(reg_a6)->flags.b[1] & 2)) {
            entity_draw_with_bombs();
        }
        reg_a6 += 0x30;
        entity_draw_with_bombs();
        reg_a6 += 0x30;
        if (!(ENTITY(reg_a6)->flags.b[1] & 2)) {
            entity_draw_with_bombs();
            reg_d0.w = 2;
            func_0020A270();
        }
        return;
    }
block_40:
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    if (reg_tmp.w != -1U) {
        ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x7EA) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x7EC) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x81A) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x81C) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x84A) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x84C) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x2C) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x2E) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_tmp.w = (u32) reg_a0;
        *(u16 *)(reg_a6 + 0x28) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a6 + 0x2A) = (u16) reg_tmp.h[0];
        laser_bomb_beam_rebuild();
        goto block_36;
    } else {
        g_bomb_afterglow_timer_as_s16 = 0x28;
        laser_bomb_end();
        bombs_clear();
    }
}

extern u16 laser_bomb_segment_template[];
extern s32 g_laser_bomb_hit_entity;
extern u16 g_laser_bomb_hit_position;
extern u16 g_bomb_entities_1[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void laser_bomb_beam_draw(void) {
    reg_tmp.h[0] = W(0x80A);
    W(0x80A) -= 4;
    if ((s32) reg_tmp.h[0] >= 4) goto next_20;
    W(0x80A) = 0x1C;
next_20:
    reg_a3 = reg_a6;
    if (W(0x18) != 0) {
        laser_bomb_beam_draw_fading();
        return;
    }
    reg_d0.h[0] = W(0x80A);
    reg_tmp.h[1] = W(0x2C);
    reg_tmp.h[0] = W(0x2E);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d5.w = (u32) reg_a0;
    reg_d4.h[0] = W(0x24);
    reg_a0 += reg_d4.h[0];
    reg_d7.w = 0x28;
    reg_d6.w = 0;
    reg_a6 = (u8 *) g_bomb_entities_1;
    reg_a2 = (u8 *) laser_bomb_segment_template;
loop_40:
    if ((s16) W(0) < 0) goto next_100;
    if (reg_d6.h[0] != 0) goto next_190;
    reg_a1 = reg_a6;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    reg_d0.w += 0x06000000;
    *(u16 *)reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a0 + 0);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a0 + 2);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d5.h[1];
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d5.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_d6.w = 1;
    goto next_180;
next_100:
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
    reg_a1 = (u8 *) reg_tmp.w;
    W(0xA) = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a1;
    W(0xC) = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d0.h[0] = W(2);
    reg_d0.h[0] += 0x200;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x30);
    if (g_laser_bomb_hit_entity == 0) goto next_120;
    if (g_laser_bomb_hit_position < reg_d0.h[0]) goto next_140;
next_120:
    if ((s32) reg_d0.h[0] < 0x7800) goto next_160;
next_140:
    W(0) = 0;
    goto next_190;
next_160:
    reg_d0.h[0] += 0x200;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    W(2) = reg_d0.h[1];
    W(4) = reg_d0.h[0];
next_180:
    entity_draw_with_bombs_keep();
next_190:
    reg_a6 += 0x30;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_40;
    reg_a6 = reg_a3;
}

void laser_bomb_beam_draw_fading(void) {
    u32 base;

    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2C);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2E);
    reg_a0 = (u8 *)reg_tmp.w;
    base = (u32)(reg_a0 + *(u16 *)(reg_a6 + 0x80A));
    reg_d7.w = 0x28;
    reg_a6 = (u8 *)g_bomb_entities_1;
    reg_a0 = (u8 *)base;
    reg_a2 = (u8 *)laser_bomb_segment_template;
    reg_d6.w = 0;
loop_0:
    if ((s16)ENTITY(reg_a6)->flags.h < 0) goto next_0;
    if (reg_d6.h[0] != 0) goto next_6;
    reg_a1 = reg_a6;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    reg_d0.w += 0x06000000;
    *(u16 *)reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a0 + 2);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_d6.w = 1;
    reg_a2 += 2;
    reg_a1 += 2;
    goto next_5;
next_0:
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] += 0x200;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x30);
    if (g_laser_bomb_hit_entity != 0) goto next_1;
    if (*(u16 *)(reg_a3 + 0x868) == 0) goto next_2;
    if (*(u8 *)(reg_a3 + 1) & 0x40) goto next_2;
    if ((s32)*(u16 *)(reg_a3 + 0x842) < (s32)reg_d0.h[0]) goto next_3;
    goto next_2;
next_1:
    if ((s32)g_laser_bomb_hit_position < (s32)reg_d0.h[0]) goto next_3;
next_2:
    if ((s32)reg_d0.h[0] < 0x7800) goto next_4;
next_3:
    ENTITY(reg_a6)->flags.h = 0;
    goto next_6;
next_4:
    reg_d0.h[0] += 0x200;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    ENTITY(reg_a6)->y.h = reg_d0.h[1];
    ENTITY(reg_a6)->x.h = reg_d0.h[0];
next_5:
    entity_draw_with_bombs_keep();
next_6:
    reg_a6 += 0x30;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    reg_a6 = reg_a3;
}

void laser_bomb_tip_update(void) {
    reg_a0 = reg_a6;
    reg_a6 += 0x7E0;
    if (*(u16 *)(reg_a6 + 0x28) == 0) {
        if ((g_laser_bomb_hit_entity == 0) && ((*(u16 *)(reg_a0 + 0x868) == 0) || (*(u8 *)(reg_a0 + 1) & 0x40))) {
            ENTITY(reg_a6)->flags.b[1] &= 0xFD;
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] += 0x400;
            reg_d0.h[0] += *(u16 *)(reg_a5 + 0x30);
            ENTITY(reg_a6)->y.h = (u16) reg_d0.h[0];
            if ((s32) reg_d0.h[0] >= 0x7E00) {
                *(u16 *)(reg_a6 + 0x28) = 1U;
                goto block_6;
            }
        } else {
block_6:
            ENTITY(reg_a6)->flags.b[1] |= 2;
        }
    }
    reg_a6 -= 0x7E0;
}

void laser_bomb_muzzle_update(void) {
}

void laser_bomb_impact_update(void) {
    reg_a0 = reg_a6;
    reg_a6 += 0x840;
    reg_d1.h[0] = g_laser_bomb_hit_position;
    if (g_laser_bomb_hit_entity != 0) goto block_1;
    if (*(u16 *)(reg_a6 + 0x28) == 0) goto block_3;
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.b[0] = *(u8 *)(reg_a0 + 1);
    *(u8 *)(reg_a0 + 1) |= 0x20;
    if (reg_tmp.b[0] & 0x20) goto block_3;
    goto block_2;
block_1:
    *(u8 *)(reg_a0 + 1) &= 0xDF;
block_2:
    *(u8 *)(reg_a0 + 1) &= 0xBF;
    ENTITY(reg_a6)->flags.b[1] &= 0xFD;
    ENTITY(reg_a6)->y.h = reg_d1.h[0];
    *(u16 *)(reg_a6 + 0x28) = 1;
    goto block_4;
block_3:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 2;
    if (reg_tmp.b[0] & 2) goto block_4;
    *(u8 *)(reg_a0 + 0x7E1) &= 0xFD;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] += 0x400;
    if (*(u16 *)(reg_a0 + 0x18) == 0) goto skip_1;
    reg_d0.h[0] -= 0x800;
skip_1:
    *(u16 *)(reg_a0 + 0x7E2) = reg_d0.h[0];
    *(s16 *)(reg_a0 + 0x808) = 0;
    *(u8 *)(reg_a0 + 1) |= 0x40;
block_4:
    reg_a6 -= 0x840;
}


void laser_bomb_beam_rebuild(void) {
    reg_d7.w = 0x28;
    reg_a1 = (u8 *) g_bomb_entities_1;
    reg_d6.h[1] = *(u16 *) (reg_a5 + 2);
    reg_d6.h[0] = *(u16 *) (reg_a5 + 4);
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    reg_d6.h[0] += 0x600;
    reg_d6.h[0] -= *(u16 *) (reg_a5 + 0x30);
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    reg_d5.w = 0;
loop_20:
    if (reg_d5.h[0] == 0) goto next_40;
    *(u16 *) reg_a1 = 0;
    reg_a1 += 0x30;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_20;
    goto next_160;
next_40:
    reg_tmp.h[1] = *(u16 *) (reg_a6 + 0x2C);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x2E);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_a0 += *(u16 *) (reg_a6 + 0x80A);
    reg_a2 = (u8 *) laser_bomb_segment_template;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d6.h[1];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d6.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    reg_d6.h[0] += 0x400;
    if (g_laser_bomb_hit_entity != 0) goto next_80;
    if (*(u8 *) (reg_a6 + 0x841) & 2) goto next_60;
    if ((s32) *(u16 *) (reg_a6 + 0x842) > (s32) reg_d6.h[0]) goto next_120;
    *(u16 *) (reg_a6 + 0x842) = reg_d6.h[0];
    goto next_100;
next_60:
    if (*(u8 *) (reg_a6 + 0x7E1) & 2) goto next_80;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x7E2);
    reg_d0.h[0] += 0x800;
    if ((s32) reg_d0.h[0] > (s32) reg_d6.h[0]) goto next_120;
    goto next_100;
next_80:
    if (reg_d6.h[0] < 0x7800) goto next_120;
next_100:
    reg_d5.w = 1;
next_120:
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    *(u16 *) reg_a1 = *(u16 *) (reg_a0 + 0);
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) (reg_a0 + 2);
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_a1 -= 0x1E;
    *(u16 *) (reg_a6 + 0x80A) += 4;
    if (*(u16 *) (reg_a6 + 0x80A) != 0x20) goto next_140;
    *(u16 *) (reg_a6 + 0x80A) = 0;
next_140:
    reg_a1 += 0x30;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_20;
next_160:
    *(u16 *) (reg_a6 + 0x80A) = 0x1C;
}

s32 func_0013C980();                            /* extern */
s32 func_0013CA90();                            /* extern */
extern s16 g_p2_laser_bomb_active_as_s16;
extern s16 g_p1_laser_bomb_active_as_s16;
extern s8 g_bomb_entities_as_s8_a[];

void laser_bomb_end(void) {
    reg_a6 = (u8 *)g_bomb_entities_as_s8_a;
    if (*(s8 *)reg_a6 >= 0) {
        reg_a0 = g_player1_as_u8_a;
        func_0013C980();
        g_p1_laser_bomb_active_as_s16 = 0;
        g_player1_as_u8_a[0] &= 0xBF;
    } else {
        reg_a0 = g_player2_as_u8_a;
        func_0013CA90();
        g_p2_laser_bomb_active_as_s16 = 0;
        g_player2_as_u8_a[0] &= 0xBF;
    }
    *reg_a0 &= 0x7F;
    reg_d0.w = 0;
    g_laser_bomb_hit_entity = 0;
}

void bomb_afterglow_end(void) {
    reg_d0.w = 0;
    PLAYER(g_player1_as_u8_a)->state.b.invincible = reg_d0.b[0];
    PLAYER(g_player2_as_u8_a)->state.b.invincible = reg_d0.b[0];
}

s32 p1_chain_reset();
s32 p2_chain_reset();
extern u16 g_p2_combo_at_bomb;
extern u16 g_p1_combo_at_bomb;

void bombs_clear(void) {
    reg_d0.w = 0;
    if (g_p1_combo_at_bomb != 0) {
        p1_chain_reset();
    }
    if (g_p2_combo_at_bomb != 0) {
        p2_chain_reset();
    }
    reg_d7.w = 0x2C;
    g_p1_laser_bomb_active_as_s16 = 0;
    g_p2_laser_bomb_active_as_s16 = 0;
    reg_a0 = (u8 *)(g_bomb_entities);
    reg_d0.w = 0;
    g_player1_as_u8_a[0] &= 0xBF;
    g_player2_as_u8_a[0] &= 0xBF;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
