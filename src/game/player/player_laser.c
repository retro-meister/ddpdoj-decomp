#include "black_label.h"
#include "common.h"
#ifdef DDPDOJ_PC
#include "arcade_gameplay.h"
#endif
#include "player.h"
#include "entity.h"

void p1_laser_segment_b(void);
void p2_laser_segment_b(void);
void laser_segment_move(void);
void p1_laser_front_hyper(void);
void p2_laser_front_hyper(void);
void laser_front_update();
void laser_muzzle_update();
void laser_muzzle_update_strong();
void p1_laser_ship_glow_hyper(void);
void p2_laser_ship_glow_hyper(void);
void laser_ship_glow_update(void);
void p1_laser_option_glow_hyper(void);
void p2_laser_option_glow_hyper(void);
void laser_option_glow_update();
void laser_segment_move_strong(void);
void laser_segment_move_hyper(void);
void laser_segment_spawn(void);
void laser_segment_end(void);
void laser_segment_hit_check(void);
void laser_segment_skip_check(void);
void laser_impact_start(void);

s32 debug_print_hex8_stub();
s32 debug_print_hex_short_stub();

void shooter_drone_debug_print(void) {
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

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a6 = reg_a6;
    reg_d2.h[0] = 0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    debug_print_hex8_stub();
    reg_d2.h[0] = 1;
    reg_d0.h[0] -= 2;
    reg_d3.h[0] = reg_d5.h[0];
    debug_print_hex_short_stub();
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

extern u8 player_weapon_tables[];
extern u8 g_p2_weapon_level_data[];
extern u8 g_p1_weapon_level_data[];
extern s16 g_player1[];

void weapon_level_data_set(u8 *arg0) {
    u8 *sa0;
    u8 *sa1;
    u8 *sa2;
    u8 *sa4;
    u32 sd0;
    u32 sd1;
    u32 stmp;

    sa0 = reg_a0;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa4 = reg_a4;
    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    stmp = reg_tmp.w;
    if (((u8 *)g_player1) == arg0) {
        reg_a4 = (u8 *)g_p1_weapon_level_data;
    } else {
        reg_a4 = (u8 *)g_p2_weapon_level_data;
    }
    reg_d1.w = 0;
    reg_d1.h[0] = *(u16 *)(arg0 + 0x20);
    reg_d0.h[0] = *(u16 *)(arg0 + 0x5A);
    reg_d0.h[0] -= 2;
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += *(u16 *)(arg0 + 0x58);
    reg_d0.h[0] <<= 2;
    reg_a2 = (u8 *)player_weapon_tables;
    *(u16 *)(reg_a4 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 2) = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 4) = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a2 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 6) = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a2 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a2;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
    reg_tmp.w += reg_d1.w;
    *(u16 *)(reg_a4 + 0) = reg_tmp.h[1];
    *(u16 *)(reg_a4 + 2) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 6);
    reg_tmp.w += reg_d1.w;
    *(u16 *)(reg_a4 + 4) = reg_tmp.h[1];
    *(u16 *)(reg_a4 + 6) = reg_tmp.h[0];
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a4 = sa4;
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_tmp.w = stmp;
}

s32 sprite_palette_load();
extern u8 D_00251AB0[];
extern u8 D_00251AC0[];
extern u8 D_002609F0[];
extern u8 D_00260A30[];
extern u8 ship_select_ship_begin_table[];
extern u8 ship_select_ship_begin_table_2[];
extern u8 ship_select_ship_begin_table_3[];
extern u8 ship_select_ship_begin_table_4[];
extern u8 ship_select_ship_begin_table_5[];
extern u8 ship_select_ship_begin_table_6[];
extern u8 ship_select_ship_begin_table_7[];
extern u8 ship_select_ship_begin_table_8[];
extern u8 ship_select_ship_begin_table_9[];
extern u16 g_input_p2_previous;
extern u16 g_input_p2_pressed;
extern u16 g_input_p1_previous;
extern u16 g_input_p1_pressed;

void ship_select_ship_begin(void) {
    ENTITY(reg_a6)->y.sh = 0;
    reg_a4 = (u8 *)D_00251AC0;
    if (reg_d7.h[0] != 0) {
        reg_a4 = (u8 *)D_00251AB0;
        ENTITY(reg_a6)->y.sh = 0;
    }
    reg_d0.h[0] = 0x1E40;
    reg_d1.h[0] = 0x5200;
    if (reg_d7.h[0] != 0) {
        reg_d0.h[0] = 0x1A00;
        reg_d1.h[0] = 0xE600;
    }
    ENTITY(reg_a6)->look.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)->hit_x_plus.h = (u16) reg_d1.h[0];
    ENTITY(reg_a6)->move.h = (u16) reg_d1.h[0];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a6 + 0x26) = (u16) reg_d1.h[0];
    ENTITY(reg_a6)->draw.sh = 0x60;
    ENTITY(reg_a6)->sprite.sh = 0xC00;
    ENTITY(reg_a6)->hit_y_plus.sh = 0x60;
    ENTITY(reg_a6)->hit_y_minus.sh = 0xC00;
    *(s16 *)(reg_a6 + 0x2E) = 0x599;
    *(s8 *)(reg_a6 + 0x30) = 2;
    *(s8 *)(reg_a6 + 0x31) = 0;
    *(s8 *)(reg_a6 + 0x35) = 0;
    *(s8 *)(reg_a6 + 0x34) = 0;
    *(s16 *)(reg_a6 + 0x36) = 0;
    *(s16 *)(reg_a6 + 0x38) = 0;
    *(s16 *)(reg_a6 + 0x3A) = 0;
    *(s16 *)(reg_a6 + 0x3C) = 0;
    *(s16 *)(reg_a6 + 0x3E) = 0;
    *(s16 *)(reg_a6 + 0x40) = 0x1AC0;
    *(s16 *)(reg_a6 + 0x42) = 0;
    *(s16 *)(reg_a6 + 0x44) = 0;
    *(s16 *)(reg_a6 + 0x46) = 0;
    *(s16 *)(reg_a6 + 0x48) = 0;
    *(s16 *)(reg_a6 + 0x4A) = 0;
    *(s16 *)(reg_a6 + 0x4C) = 0;
    *(s16 *)(reg_a6 + 0x4E) = 0;
    *(s16 *)(reg_a6 + 0x50) = 0;
    *(s16 *)(reg_a6 + 0x52) = 0;
    *(s16 *)(reg_a6 + 0x54) = 0;
    reg_a0 = (u8 *)ship_select_ship_begin_table_9;
    reg_d0.w = 0x18;
    sprite_palette_load();
    reg_a0 = (u8 *)ship_select_ship_begin_table_8;
    reg_d0.w = 0x19;
    sprite_palette_load();
    reg_a0 = (u8 *)ship_select_ship_begin_table_7;
    reg_d0.w = 0x1B;
    sprite_palette_load();
    reg_a0 = (u8 *)D_002609F0;
    reg_d0.w = 0x1A;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260A30;
    reg_d0.w = 0x1C;
    sprite_palette_load();
    reg_a0 = (u8 *)ship_select_ship_begin_table;
    reg_d0.w = 0x1D;
    sprite_palette_load();
    reg_a0 = (u8 *)ship_select_ship_begin_table_2;
    reg_d0.w = 0x1E;
    sprite_palette_load();
    reg_a0 = (u8 *)ship_select_ship_begin_table_3;
    reg_d0.w = 0xC;
    sprite_palette_load();
    reg_a0 = (u8 *)ship_select_ship_begin_table_4;
    reg_d0.w = 0xD;
    sprite_palette_load();
    reg_a0 = (u8 *)ship_select_ship_begin_table_5;
    reg_d0.w = 0xE;
    sprite_palette_load();
    reg_a0 = (u8 *)ship_select_ship_begin_table_6;
    reg_d0.w = 0xF;
    sprite_palette_load();
    ENTITY(reg_a6)->flags.sb[0] = 1;
    g_input_p1_previous = 0xFFFF;
    g_input_p2_previous = 0xFFFF;
    g_input_p1_pressed = 0;
    g_input_p2_pressed = 0;
}

#ifndef DDPDOJ_PC
s32 text_layer_print();
#endif
s32 ship_palettes_load();
extern u16 ship_select_ship_confirm_table[];
extern u16 ship_select_ship_confirm_table_2[];

void ship_select_ship_confirm(void) {
    u16 temp_a0;
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 2);
    reg_a0 = (u8 *)(ship_select_ship_confirm_table_2);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    if (reg_d7.h[0] != 0) {
        *(u8 *)(reg_a5 + 9) = (u8) reg_d0.b[0];
    } else {
        *(u8 *)(reg_a5 + 8) = (u8) reg_d0.b[0];
    }
    reg_d0.w = 0;
    if (reg_d7.h[0] == 0) {
        reg_d0.w = 1;
    }
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    ship_palettes_load();
    temp_a0 = *(u16 *)(reg_a4 + 0xA);
    reg_d1.h[0] = temp_a0;
    reg_d0.h[0] = 8;
    reg_a0 = (u8 *)(ship_select_ship_confirm_table);
    reg_d2.h[0] = 0;
    reg_d1.h[0] >>= 6;
    reg_d1.h[0] >>= 3;
    reg_d1.h[0] += 8;
    text_layer_print();
    *(s8 *)reg_a6 = 3;
}

typedef void (*Fn)();

s32 sfx_confirm();
s32 sfx_cursor_move();
s32 select_panel_piece_0_draw();
s32 select_panel_piece_1_draw();
s32 select_panel_piece_4_draw();
s32 select_panel_piece_5_draw();
s32 select_panel_piece_6_draw();
s32 select_other_side_piece_draw();
s32 select_panel_piece_9_draw();
extern s32 D_0028E998;
extern s32 D_0028E99C;
extern u8 *reg_call_target_as_u8_p;

void ship_select_ship_update(void) {
    u8 *temp_s0;
    u8 temp_v1;
    u8 temp_v1_2;

    reg_a4 = (u8 *)D_00251AC0;
    if (reg_d7.h[0] != 0) {
        reg_a4 = (u8 *)D_00251AB0;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 8);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    reg_d6.h[0] = ENTITY(reg_a6)->y.h;
    if (reg_d0.w & 4) {
        ENTITY(reg_a6)->y.h -= 1;
        if (0 > (s16) ENTITY(reg_a6)->y.h) {
            ENTITY(reg_a6)->y.h = 0U;
        }
    }
    if (ENTITY(reg_a6)->y.h != reg_d6.h[0]) {
        sfx_cursor_move();
    }
    reg_d6.h[0] = ENTITY(reg_a6)->y.h;
    if (reg_d0.w & 8) {
        ENTITY(reg_a6)->y.h += 1;
        if ((s16) ENTITY(reg_a6)->y.h > 1) {
            ENTITY(reg_a6)->y.h = 1U;
        }
    }
    if (ENTITY(reg_a6)->y.h != reg_d6.h[0]) {
        sfx_cursor_move();
    }
    if ((*(u8 *)(reg_a6 + 0x31) != 0) || (reg_d0.h[0] &= 0x70, (reg_d0.h[0] != 0))) {
        sfx_confirm();
        ENTITY(reg_a6)->flags.sb[0] = 2;
        if (reg_d7.h[0] != 0) {
            D_0028E99C = (s32) ENTITY(reg_a6)->y.h;
        } else {
            D_0028E998 = ENTITY(reg_a6)->y.h + 2;
        }
    }
    temp_v1 = *(u8 *)(reg_a5 + 2);
    temp_s0 = (u8 *)(reg_a4);
    if (temp_v1 & 1) {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1 | 1);
    } else {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1 | 1);
        select_panel_piece_0_draw();
        select_panel_piece_1_draw();
    }
    temp_v1_2 = *(u8 *)(reg_a5 + 2);
    if (temp_v1_2 & 2) {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1_2 | 2);
    } else {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1_2 | 2);
        select_panel_piece_4_draw();
    }
    select_panel_piece_5_draw();
    select_panel_piece_6_draw();
    select_other_side_piece_draw();
    select_panel_piece_9_draw();
    reg_a4 = temp_s0;
}

s32 entity_draw_with_player_lasers();
extern u16 g_frame_mod2;
extern u16 g_two_player_game;

void laser_draw_alternating(arg0)
    u16 arg0;
{
    u16 var_a0;

    var_a0 = arg0;
    if (g_two_player_game == 0) {
        reg_d2.w = 0;
        if (ENTITY(reg_a6)->move.h != 0) {
            reg_d2.w = 1;
        }
        var_a0 = g_frame_mod2;
        if (var_a0 != reg_d2.h[0]) {
            goto block_4;
        }
    } else {
block_4:
        entity_draw_with_player_lasers();
    }
}

s32 entity_draw_with_player_lasers();                            /* extern */

void p1_laser_draw_alternating(void) {
    if ((g_two_player_game != 0) || (g_frame_mod2 == 0)) {
        entity_draw_with_player_lasers();
    }
}

void p2_laser_draw_alternating(void) {
    if ((g_two_player_game != 0) || (g_frame_mod2 != 0)) {
        entity_draw_with_player_lasers();
    }
}

#ifdef DDPDOJ_PC
typedef uintptr_t LaserRegisterAddress;
#else
typedef u32 LaserRegisterAddress;
#endif
extern Fn p1_laser_part_routines[20];
extern Fn p2_laser_part_routines[20];
extern u16 g_player_laser_count;
extern u16 g_hyper_hit_scratch;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u8 g_p2_laser_entities[1296];
extern u8 g_p1_laser_entities[1296];
extern s16 g_player2[];
extern s16 g_player1[];

void player_lasers_update(void) {
    u8 *temp_s0 = reg_a5;
    g_hyper_hit_scratch = 0;
    g_player_laser_count = 0;
    if (g_player1[0] < 0) {
        reg_a6 = (u8 *)(((u16 *)g_p1_laser_entities));
        reg_d7.w = 0x1F;
        g_hyper_hit_scratch = g_p1_hyper_active;
        do {
            reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
            if (reg_d0.h[0] != 0) {
                reg_d1.w = 0x1F;
                g_player_laser_count += 1;
                reg_d1.h[0] &= reg_d0.h[0];
                p1_laser_part_routines[reg_d1.h[0]]();
            }
            reg_a6 += 0x30;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    if (g_player2[0] < 0) {
        reg_a6 = (u8 *)(((u16 *)g_p2_laser_entities));
        reg_d7.w = 0x1F;
        g_hyper_hit_scratch = g_p2_hyper_active;
        do {
            reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
            if (reg_d0.h[0] != 0) {
                reg_d1.w = 0x1F;
                g_player_laser_count += 1;
                reg_d1.h[0] &= reg_d0.h[0];
                p2_laser_part_routines[reg_d1.h[0]]();
            }
            reg_a6 += 0x30;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    reg_a5 = (u8 *)temp_s0;
}


void p1_laser_segment_a(void) {
    p1_laser_segment_b();
}


void p1_laser_segment_b(void) {
    reg_d0.h[0] = PLAYER(((u8 *)g_player1))->moved_y.h;
    reg_d1.h[0] = PLAYER(((u8 *)g_player1))->x.h;
    laser_segment_move();
}


void p2_laser_segment_a(void) {
    p2_laser_segment_b();
}

void p2_laser_segment_b(void) {
    reg_d0.h[0] = PLAYER(g_player2)->moved_y.h;
    reg_d1.h[0] = PLAYER(g_player2)->x.h;
    laser_segment_move();
}


void laser_segment_move() {
    u8 *temp_a0;

    reg_d0.h[0] += 0x800;
    temp_a0 = reg_a6 + 2;
    reg_d0.h[0] += ENTITY(reg_a6)->y.h;
    if ((s32) reg_d0.h[0] >= 0x7800) {
        laser_segment_end();
        return;
    }
    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
    laser_segment_hit_check();
}


void p1_laser_front_a(void) {
    p1_laser_front_hyper();
}


void p1_laser_front_b(void) {
    p1_laser_front_hyper();
}

void p1_laser_front_strong(void) {
    p1_laser_front_hyper();
}

extern u8 D_0029D730[];
extern u8 g_p1_laser_segments[];
void p1_laser_front_hyper(void)
{
  u16 value = PLAYER(((u8 *)g_player1))->moved_y.h;
  int new_var;
  reg_a0 = g_p1_laser_segments;
  if ((!new_var) && (!new_var))
  {
  }
  reg_d2.h[0] = (new_var = PLAYER(((u8 *)g_player1))->x.h);
  reg_a1 = D_0029D730;
  reg_d1.h[0] = value;
  laser_front_update(value);
}


void p2_laser_front_a(void) {
    p2_laser_front_hyper();
}

void p2_laser_front_b(void) {
    p2_laser_front_hyper();
}

void p2_laser_front_strong(void) {
    p2_laser_front_hyper();
}

extern u8 D_0029D710[];
extern u8 g_p2_laser_segments[];
inline int inline_fn(u16 arg0, u16 arg1, u16 arg2)
{
  return (arg0 && arg1) && arg2;
}

void p2_laser_front_hyper(void)
{
  u16 sourceValue = PLAYER(g_player2)->moved_y.h;
  u16 new_var;
  u16 new_var3;
  int new_var2;
  reg_a0 = g_p2_laser_segments;
  new_var = sourceValue;
  new_var2 = 0;
  new_var3 = PLAYER(g_player2)->x.h;
  reg_a1 = D_0029D710;
  if (!new_var)
  {
  }
  if (inline_fn(new_var, new_var, new_var))
  {
  }
  reg_d1.h[new_var2] = new_var;
  reg_d2.h[new_var2] = new_var3;
  laser_front_update(new_var);
}

void sparks_spawn_for_laser(void);
extern u16 g_p2_laser_bomb_active;
extern u16 g_p1_laser_bomb_active;

void laser_front_update() {
    reg_d1.h[0] += 0x800;
    ENTITY(reg_a6)->y.h += reg_d1.h[0];
    ENTITY(reg_a6)->x.h = reg_d2.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a2 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if ((s32)reg_tmp.h[0] < 4) {
        *(u16 *)(reg_a6 + 0x24) = 4;
    }
    if (ENTITY(reg_a6)->flags.b[1] & 1) goto block_1;
    if (ENTITY(reg_a6)->flags.sb[0] >= 0) {
        switch (g_two_player_game) {
            case 0:
                break;
            default:
                reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x27);
                *(u8 *)(reg_a6 + 0x27) -= 1;
                if ((s32)reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a6 + 0x27) = *(u8 *)(reg_a6 + 0x26);
                    sparks_spawn_for_laser();
                }
                break;
        }
    }
    if ((s32)ENTITY(reg_a6)->y.h >= 0x7800) goto block_4;
    if (!(*(u8 *)(reg_a0 + 1) & 0x10)) goto block_2;
block_1:
    if (*(s16 *)reg_a1 < 0) goto block_3;
    ENTITY(reg_a6)->flags.b[1] |= 1;
block_2:
    reg_a0 = (u8 *)&g_p1_laser_bomb_active;
    if (ENTITY(reg_a6)->move.h == 0) goto block_5;
    if (g_p1_laser_bomb_active == 0) goto block_6;
    return;
block_3:
    ENTITY(reg_a6)->flags.h = 0;
    return;
block_4:
    laser_segment_end();
    return;
block_5:
    if (g_p2_laser_bomb_active != 0) return;
block_6:
    laser_draw_alternating();
}

extern u8 g_p1_options[];
extern u16 D_0029F182[];
extern u16 D_0029F184[];
void p1_laser_muzzle_a(void)
{
    extern void sfx_p1_laser_a_start(void);
  unsigned int highWord = D_0029F182[0];
  reg_a4 = (u8 *)((LaserRegisterAddress) ((u16 *)g_p1_options));
  reg_d0.h[0] = D_0029F184[0];
  reg_a3 = (u8 *)((LaserRegisterAddress) (&sfx_p1_laser_a_start));
  reg_d0.h[1] = highWord;
  laser_muzzle_update(highWord);
}

void p1_laser_muzzle_b(void) {
    extern void sfx_p1_laser_b_start(void);
    unsigned int highWord = D_0029F182[0];
    reg_a4 = (u8 *)((LaserRegisterAddress)((u16 *)g_p1_options));
    reg_d0.h[0] = D_0029F184[0];
    reg_a3 = (u8 *)((LaserRegisterAddress)(&sfx_p1_laser_b_start));
    reg_d0.h[1] = highWord;
    laser_muzzle_update(highWord);
}

extern u8 g_p2_options[];
extern u16 D_0029F112[];
extern u16 D_0029F114[];
void p2_laser_muzzle_a(void)
{
    extern void sfx_p2_laser_a_start(void);
  u16 highWord = D_0029F112[0];
  reg_d0.h[1] = highWord;
  reg_a4 = (u8 *)((LaserRegisterAddress) ((u16 *)g_p2_options));
  reg_d0.h[0] = D_0029F114[0];
  reg_a3 = (u8 *)((LaserRegisterAddress) sfx_p2_laser_a_start);
  reg_d0.h[0] = D_0029F114[0];
  laser_muzzle_update(highWord);
}

void p2_laser_muzzle_b(void) {
    extern void sfx_p2_laser_b_start(void);
    unsigned int highWord = D_0029F112[0];
    reg_a4 = (u8 *)((LaserRegisterAddress)((u16 *)g_p2_options));
    reg_d0.h[0] = D_0029F114[0];
    reg_a3 = (u8 *)((LaserRegisterAddress)(&sfx_p2_laser_b_start));
    reg_d0.h[1] = highWord;
    laser_muzzle_update(highWord);
}


void laser_muzzle_update() {
    s64 temp_v1;
    u16 temp_a0;

    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    *(u16 *)(reg_a6 + 0x22) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    temp_v1 = (s64) ((s64) *(u16 *)(reg_a6 + 0x22) << 0x30) >> 0x30;
    if (temp_v1 < 0) {
        *(u16 *)(reg_a6 + 0x22) = (u16) ~temp_v1;
        temp_a0 = *(u16 *)(reg_a6 + 0x22);
        if (temp_a0 == 0x7F) {
            ENTITY(reg_a6)->flags.sh = 0;
            return;
        }
        if (ENTITY(reg_a6)->move.h != 0) {
            if (g_p1_laser_bomb_active == 0) {
                goto block_7;
            }
            goto block_8;
        } else if (g_p2_laser_bomb_active == 0) {
block_7:
            reg_call_target = (Fn)(reg_a3);
            reg_call_target();
        }
block_8:
        laser_segment_spawn();
        goto block_9;
    }
block_9:
    ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    laser_draw_alternating();
}

extern u8 g_p1_options[];

void p1_laser_muzzle_strong(void) {
#ifndef DDPDOJ_PC
    extern void laser_muzzle_update_strong(u16);
#endif
    extern void sfx_p1_laser_a_start();
    extern void sfx_p1_laser_b_start();
    reg_a4 = g_p1_options;
    reg_a3 = (void *)sfx_p1_laser_a_start;
    reg_d0.h[1] = D_0029F182[0];
    reg_d0.h[0] = D_0029F184[0];
    if (PLAYER(((u8 *)g_player1))->ship_type.h == 0) {
        ARCADE_REGISTER_CALL(laser_muzzle_update_strong, D_0029F182[0]);
        return;
    }
    reg_a3 = (void *)sfx_p1_laser_b_start;
    ARCADE_REGISTER_CALL(laser_muzzle_update_strong, D_0029F182[0]);
}

extern void sfx_p1_laser_hyper_start(void);

void p1_laser_muzzle_hyper(void) {
    unsigned int highWord = D_0029F182[0];
    reg_a4 = (u8 *)((LaserRegisterAddress)((u16 *)g_p1_options));
    reg_d0.h[0] = D_0029F184[0];
    reg_a3 = (u8 *)((LaserRegisterAddress)(&sfx_p1_laser_hyper_start));
    reg_d0.h[1] = highWord;
    ARCADE_REGISTER_CALL(laser_muzzle_update_strong, highWord);
}

extern u8 g_p2_options[];

void p2_laser_muzzle_strong(void) {
#ifndef DDPDOJ_PC
    extern void laser_muzzle_update_strong(u16);
#endif
    extern void sfx_p2_laser_a_start();
    extern void sfx_p2_laser_b_start();
    reg_a4 = g_p2_options;
    reg_a3 = (void *)sfx_p2_laser_a_start;
    reg_d0.h[1] = D_0029F112[0];
    reg_d0.h[0] = D_0029F114[0];
    if (PLAYER(g_player2)->ship_type.h != 0) {
        reg_a3 = (void *)sfx_p2_laser_b_start;
    }
    ARCADE_REGISTER_CALL(laser_muzzle_update_strong, D_0029F112[0]);
}

extern void sfx_p2_laser_hyper_start(void);

void p2_laser_muzzle_hyper(void) {
    unsigned int highWord = D_0029F112[0];
    reg_a4 = (u8 *)((LaserRegisterAddress)((u16 *)g_p2_options));
    reg_d0.h[0] = D_0029F114[0];
    reg_a3 = (u8 *)((LaserRegisterAddress)(&sfx_p2_laser_hyper_start));
    reg_d0.h[1] = highWord;
    ARCADE_REGISTER_CALL(laser_muzzle_update_strong, highWord);
}

void laser_muzzle_update_strong() {
    s64 temp_v1;
    u16 temp_a0;

    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    *(u16 *)(reg_a6 + 0x22) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    temp_v1 = (s64) ((s64) *(u16 *)(reg_a6 + 0x22) << 0x30) >> 0x30;
    if (temp_v1 < 0) {
        *(u16 *)(reg_a6 + 0x22) = (u16) ~temp_v1;
        temp_a0 = *(u16 *)(reg_a6 + 0x22);
        if (temp_a0 == 0x7F) {
            ENTITY(reg_a6)->flags.sh = 0;
            return;
        }
        if (ENTITY(reg_a6)->move.h != 0) {
            if (g_p1_laser_bomb_active == 0) {
                goto block_7;
            }
            goto block_8;
        } else if (g_p2_laser_bomb_active == 0) {
block_7:
            reg_call_target = (Fn)(reg_a3);
            reg_call_target();
        }
block_8:
        laser_segment_spawn();
        goto block_9;
    }
block_9:
    ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    laser_draw_alternating();
}


void p1_laser_ship_glow_a(void) {
    p1_laser_ship_glow_hyper();
}


void p1_laser_ship_glow_b(void) {
    p1_laser_ship_glow_hyper();
}

void p1_laser_ship_glow_strong(void) {
    p1_laser_ship_glow_hyper();
}


void p1_laser_ship_glow_hyper(void) {
    reg_d0.h[1] = PLAYER(((u8 *)g_player1))->y.h;
    *(u16 *)&reg_d0 = PLAYER(((u8 *)g_player1))->x.h;
    laser_ship_glow_update();
}


void p2_laser_ship_glow_a(void) {
    p2_laser_ship_glow_hyper();
}


void p2_laser_ship_glow_b(void) {
    p2_laser_ship_glow_hyper();
}

void p2_laser_ship_glow_strong(void) {
    p2_laser_ship_glow_hyper();
}


void p2_laser_ship_glow_hyper(void) {
    reg_d0.h[1] = PLAYER(g_player2)->y.h;
    *(u16 *)&reg_d0 = PLAYER(g_player2)->x.h;
    laser_ship_glow_update();
}

void laser_ship_glow_update(void) {
    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
    reg_d0.w = 0;
    switch (ENTITY(reg_a6)->move.h) { case 0: break; default:
        reg_d0.w = 1;
    }
    if (g_frame_mod2 != reg_d0.h[0]) {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
        reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
        *(u16 *)(reg_a6 + 0x24) -= 4;
        if ((s32) reg_tmp.h[0] < 4) {
            *(u16 *)(reg_a6 + 0x24) = (u16) *(u16 *)(reg_a6 + 0x22);
        }
        if (ENTITY(reg_a6)->move.h != 0) {
            if (g_p1_laser_bomb_active != 0) {
                return;
            }
            goto block_15;
        }
        if (g_p2_laser_bomb_active == 0) {
block_15:
            entity_draw_with_player_lasers();
        }
    }
}


void p1_laser_option_glow_a(void) {
    p1_laser_option_glow_hyper();
}


void p1_laser_option_glow_b(void) {
    p1_laser_option_glow_hyper();
}

void p1_laser_option_glow_strong(void) {
    p1_laser_option_glow_hyper();
}
void p1_laser_option_glow_hyper(void) {
    reg_d0.h[1] = D_0029F182[0];
    reg_d0.h[0] = D_0029F184[0];
    reg_d1.h[0] = PLAYER(((u8 *)g_player1))->laser_power.h;
    laser_option_glow_update();
}


void p2_laser_option_glow_a(void) {
    p2_laser_option_glow_hyper();
}

void p2_laser_option_glow_b(void) {
    p2_laser_option_glow_hyper();
}

void p2_laser_option_glow_strong(void) {
    p2_laser_option_glow_hyper();
}

void p2_laser_option_glow_hyper(void) {
    u16 reg_value = D_0029F112[0];

    reg_d0.h[1] = reg_value;
    reg_d0.h[0] = D_0029F114[0];
    reg_d1.h[0] = PLAYER(g_player2)->laser_power.h;
    laser_option_glow_update(reg_value);
}

void laser_option_glow_update() {
    *(u16 *) (reg_a6 + 2) = reg_d0.h[1];
    *(u16 *) (reg_a6 + 4) = reg_d0.h[0];
    if (*(u16 *) (reg_a6 + 0x28) == reg_d1.h[0]) goto next_1;
    *(u16 *) (reg_a6 + 0x28) = reg_d1.h[0];
    reg_d1.h[0] *= 2;
    reg_tmp.h[1] = *(u16 *) (reg_a6 + 0x1E);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x20);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_tmp.h[1] = (reg_d1.h[0]) ? *(u16 *) (reg_a0 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = ((u16) reg_d1.h[0] + 2) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d1.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    *(u16 *) (reg_a6 + 0x2A) = *(u16 *) reg_a0;
    reg_a0 += 2;
    *(u16 *) (reg_a6 + 0x2C) = *(u16 *) reg_a0;
    reg_a0 += 2;
    *(u16 *) (reg_a6 + 6) = *(u16 *) reg_a0;
    reg_a0 += 2;
    *(u16 *) (reg_a6 + 8) = *(u16 *) reg_a0;
    reg_a0 += 2;
    *(u16 *) (reg_a6 + 0xE) = *(u16 *) reg_a0;
    reg_a0 += 2;
    *(u8 *) (reg_a6 + 0x23) = 0;
    *(u16 *) (reg_a6 + 0x24) = *(u16 *) (reg_a6 + 0x26);
next_1:
    reg_tmp.b[0] = *(u8 *) (reg_a6 + 0x23);
    *(u8 *) (reg_a6 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_2;
    *(u8 *) (reg_a6 + 0x23) = *(u8 *) (reg_a6 + 0x22);
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x24);
    reg_tmp.h[1] = *(u16 *) (reg_a6 + 0x2A);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x2C);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    *(u16 *) (reg_a6 + 0xA) = (reg_d0.h[0]) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    *(u16 *) (reg_a6 + 0xC) = (reg_d0.h[0] + 2) ? *(u16 *) (reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x24);
    *(u16 *) (reg_a6 + 0x24) -= 4;
    if ((s32) reg_tmp.h[0] >= 4) goto next_2;
    *(u16 *) (reg_a6 + 0x24) = *(u16 *) (reg_a6 + 0x26);
next_2:
    switch (*(u16 *) (reg_a6 + 0x1A)) { case 0: goto next_3; }
    if (g_p1_laser_bomb_active == 0) goto next_4;
    return;
next_3:
    if (g_p2_laser_bomb_active != 0) return;
next_4:
    laser_draw_alternating();
}


void p1_laser_segment_strong(void) {
    reg_d0.h[0] = PLAYER(((u8 *)g_player1))->moved_y.h;
    reg_d1.h[0] = PLAYER(((u8 *)g_player1))->x.h;
    laser_segment_move_strong();
}

void p2_laser_segment_strong(void) {
    reg_d0.h[0] = PLAYER(g_player2)->moved_y.h;
    reg_d1.h[0] = PLAYER(g_player2)->x.h;
    laser_segment_move_strong();
}

void laser_segment_move_strong() {
    reg_d0.h[0] += 0x800;
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s32) reg_d0.h[0] >= 0x7800) {
        laser_segment_end();
        return;
    }
    ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
    laser_segment_hit_check();
}

extern Reg32 reg_d0;
extern Reg32 reg_d1;

void p1_laser_segment_hyper(void) {
    reg_d0.h[0] = PLAYER(((u8 *)g_player1))->moved_y.h;
    reg_d1.h[0] = PLAYER(((u8 *)g_player1))->x.h;
    laser_segment_move_hyper();
}

void p2_laser_segment_hyper(void) {
    reg_d0.h[0] = PLAYER(g_player2)->moved_y.h;
    reg_d1.h[0] = PLAYER(g_player2)->x.h;
    laser_segment_move_hyper();
}

void laser_segment_move_hyper() {
    reg_d0.h[0] += 0x800;
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s32) reg_d0.h[0] >= 0x7800) {
        laser_segment_end();
        return;
    }
    ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
    laser_segment_hit_check();
}

void laser_parts_spawn(void) {
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    reg_a3 += 4;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    reg_a3 += 4;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) reg_d0.h[0];
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) ENTITY(reg_a6)->move.h;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    (*(u8 *)((u8 *)(reg_a3) + (-2))) = (u8) ENTITY(reg_a6)->attr.b.palette;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    reg_a3 += 0xA;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 0x1A;
    *(u16 *)reg_a3 = (u16) ENTITY(reg_a6)->move.h;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    (*(u8 *)((u8 *)(reg_a3) + (-2))) = (u8) ENTITY(reg_a6)->attr.b.palette;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
    *(u16 *)reg_a3 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a3 += 2;
}

extern u8 laser_segment_spawn_table[];
extern u16 g_p2_laser_stop_y;
extern u16 g_p1_laser_stop_y;
extern u8 D_0029DD30[];
extern u8 D_0029E330[];

void laser_segment_spawn(void) {
    u8 *temp_a3;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 var_a0;
    temp_a3 = (u8 *)(reg_a4);
    (*(u8 *)((u8 *)(temp_a3) + (1))) |= 0x20;
    reg_a2 = (u8 *)g_p1_laser_segments;
    reg_a3 = (u8 *)D_0029E330;
    reg_a4 = &(*(u8 *)&g_p1_laser_stop_y);
    reg_a5 = (u8 *)((u8 *)g_player1);
    if (ENTITY(reg_a6)->move.h == 0) {
        reg_a2 = (u8 *)g_p2_laser_segments;
        reg_a3 = (u8 *)D_0029DD30;
        reg_a4 = &(*(u8 *)&g_p2_laser_stop_y);
        reg_a5 = (u8 *)((u8 *)g_player2);
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2C);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2E);
    reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    *(u16 *)reg_a2 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[1] = *(u16 *)(reg_a5 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 4);
    temp_a2 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = temp_a2;
    temp_a2_2 = *(u16 *)reg_a1;
    reg_tmp.h[0] = temp_a2_2;
    reg_a1 += 2;
    reg_d1.w += reg_tmp.w;
    *(u16 *)(reg_a2 + 2) = (u16) reg_d1.h[1];
    *(u16 *)(reg_a2 + 4) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a2 + 6) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a2 + 8) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a2 + 0xA) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    var_a0 = *(u16 *)reg_a1;
    *(u16 *)(reg_a2 + 0xC) = var_a0;
    reg_a1 = (u8 *)((LaserRegisterAddress) laser_segment_spawn_table);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x22);
    if (*(u8 *)reg_a5 & 1) {
        reg_d0.h[0] += 0x3C;
        reg_d2.h[0] = *(u16 *)(reg_a5 + 0x58);
        reg_d3.h[0] = *(u16 *)(reg_a5 + 0x5A);
        reg_d3.h[0] -= 2;
    } else {
        reg_d3.h[0] = *(u16 *)(reg_a5 + 0x5A);
        reg_d3.h[0] -= 2;
        reg_d1.h[0] = reg_d3.h[0];
        reg_d1.h[0] *= 5;
        reg_d0.h[0] += reg_d1.h[0];
        reg_d2.h[0] = *(u16 *)(reg_a5 + 0x58);
        if (reg_d2.h[0] != 0) {
            reg_d0.h[0] += 0x1E;
        }
    }
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
#ifdef DDPDOJ_BONUS_FEATURES
    if (g_black_label_active && !(PLAYER(reg_a5)->flags.b[0] & 1)) {
        if (reg_d3.h[0] == 0) reg_d0.h[0] += reg_d2.h[0] == 0 ? 2 : 4;
        if (reg_d3.h[0] == 4 && reg_d2.h[0] == 0) reg_d0.h[0] += 4;
    }
#endif
    *(u16 *)(reg_a2 + 0xE) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a2 + 0x18) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a2 + 0x1A) = (u16) reg_d3.h[0];
    *(u16 *)(reg_a2 + 0x1C) = (u16) reg_d0.h[0];
    laser_parts_spawn();
}

void laser_segment_end(void) {
    reg_a0 = g_p1_laser_segments;
    if (ENTITY(reg_a6)->move.h == 0) {
        reg_a0 = g_p2_laser_segments;
    }
    if (*(u16 *)(reg_a0 + 0xC) == 0) {
        *(u8 *)reg_a0 |= 1;
        *(u16 *)(reg_a0 + 0xC) = 1U;
    }
    ENTITY(reg_a6)->flags.sh = 0;
}

extern u16 g_p2_laser_stop_y;
extern u16 g_p1_laser_stop_y;

void laser_segment_hit_check(void) {
    reg_d1.h[0] = g_p1_laser_stop_y;
    reg_a0 = (u8 *)D_0029D730;
    reg_a2 = (u8 *)g_p1_laser_segments;
    reg_a5 = (u8 *)((u8 *)g_player1);
    if (ENTITY(reg_a6)->move.h != 0) goto block_1;
    reg_d1.h[0] = g_p2_laser_stop_y;
    reg_a0 = (u8 *)D_0029D710;
    reg_a2 = (u8 *)g_p2_laser_segments;
    reg_a5 = (u8 *)((u8 *)g_player2);
block_1:
    switch (*(u8 *)(reg_a2 + 1) & 0x10) {
    case 0:
        goto block_4;
    }
    *(u16 *)(reg_a0 + 0x16) = 9;
block_2:
    if ((s32)reg_d1.h[0] <= (s32)reg_d0.h[0]) goto block_3;
    if ((s32)reg_d0.h[0] >= (s32)*(u16 *)(reg_a0 + 2)) goto next_1;
    laser_segment_skip_check();
    return;
next_1:
    reg_d1.h[0] = reg_d0.h[0];
    laser_impact_start();
    laser_segment_skip_check();
    return;
block_3:
    ENTITY(reg_a6)->flags.h = 0;
    if (*(s16 *)reg_a0 < 0) return;
    laser_impact_start();
    return;
block_4:
    if (*(u16 *)(reg_a0 + 0x16) != 0) goto block_2;
    *(u16 *)reg_a0 = 0;
    laser_segment_skip_check();
}


void laser_segment_skip_check(void) {
    if (ENTITY(reg_a6)->move.h != 0) {
        if (g_p1_laser_bomb_active != 0) {
            return;
        }
        goto block_4;
    }
    if (g_p2_laser_bomb_active == 0) {
block_4:
        laser_draw_alternating();
    }
}

extern u16 D_002576C0[];

void laser_impact_start(void) {
    *(u16 *)reg_a0 = 0x8000U;
    reg_a0 += 2;
    reg_d1.h[0] += 0x200;
    *(u16 *)reg_a0 = (u16) reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) ENTITY(reg_a6)->x.h;
    reg_a0 += 2;
    reg_a0 += 0xA;
    reg_d3.h[0] = *(u16 *)(reg_a5 + 0x22);
    reg_d3.h[0] *= 4;
    if (*(u8 *)reg_a5 & 1) {
        reg_d3.h[0] += 0x78;
    } else if (*(u16 *)(reg_a5 + 0x5A) != 2) {
        reg_d3.h[0] += 0x50;
    } else if (*(u16 *)(reg_a5 + 0x58) != 0) {
        reg_d3.h[0] += 0x28;
    }
    reg_a1 = (u8 *)(D_002576C0);
    reg_a1 += reg_d3.h[0];
    reg_d0.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)reg_a0 = (u16) reg_d0.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d0.h[0];
    *(u8 *)(reg_a0 + 4) = (u8) ENTITY(reg_a6)->attr.b.palette;
}

s32 sparks_spawn_for_laser_first_half();
s32 sparks_spawn_for_laser_second_half();

void laser_impacts_update(void) {
    u16 temp_a2;
    u16 temp_a2_2;
    LaserRegisterAddress temp_a1;
    LaserRegisterAddress temp_a1_2;

    reg_a6 = (u8 *)D_0029D730;
    if (ENTITY(reg_a6)->flags.sh < 0) {
        if ((g_frame_mod2 != 0) && (g_two_player_game != 0) && (g_p1_laser_bomb_active == 0)) {
            sparks_spawn_for_laser_first_half();
        }
        reg_d0.h[0] = g_p1_laser_stop_y;
        reg_d1.h[0] = D_0029F182[0];
        reg_d0.h[0] += 0x180;
        reg_d1.h[0] += 0x400;
        if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
            reg_d0.h[0] = reg_d1.h[0];
        }
        reg_a1 = (u8 *)(reg_a6 + 2);
        reg_tmp.h[1] = ENTITY(reg_a6)->hit_y_minus.h;
        reg_tmp.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        temp_a2 = ENTITY(reg_a6)->hit_y_plus.h;
        reg_a0 += temp_a2;
        *(u16 *)reg_a1 = reg_d0.h[0];
        reg_a1 += 2;
        *(u16 *)reg_a1 = PLAYER(((u8 *)g_player1))->x.h;
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
        temp_a1 = (LaserRegisterAddress)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a1);
        reg_a1 += 2;
        reg_tmp.h[0] = ENTITY(reg_a6)->hit_y_plus.h;
        ENTITY(reg_a6)->hit_y_plus.h -= 0xA;
        if ((s32) reg_tmp.h[0] < 0xA) {
            ENTITY(reg_a6)->hit_y_plus.h = (u16) ENTITY(reg_a6)->hp.h;
        }
        if (g_p1_laser_bomb_active == 0) {
            p1_laser_draw_alternating();
        }
    }
    reg_a6 = (u8 *)D_0029D710;
    if (ENTITY(reg_a6)->flags.sh < 0) {
        if ((g_frame_mod2 == 0) && (g_two_player_game != 0) && (g_p2_laser_bomb_active == 0)) {
            sparks_spawn_for_laser_second_half();
        }
        reg_d0.h[0] = g_p2_laser_stop_y;
        reg_d1.h[0] = D_0029F112[0];
        reg_d1.h[0] += 0x400;
        if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
            reg_d0.h[0] = reg_d1.h[0];
        }
        reg_a1 = (u8 *)(reg_a6 + 2);
        reg_tmp.h[1] = ENTITY(reg_a6)->hit_y_minus.h;
        reg_tmp.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        temp_a2_2 = ENTITY(reg_a6)->hit_y_plus.h;
        reg_a0 += temp_a2_2;
        *(u16 *)reg_a1 = reg_d0.h[0];
        reg_a1 += 2;
        *(u16 *)reg_a1 = PLAYER(g_player2)->x.h;
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
        temp_a1_2 = (LaserRegisterAddress)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a1_2);
        reg_a1 += 2;
        reg_tmp.h[0] = ENTITY(reg_a6)->hit_y_plus.h;
        ENTITY(reg_a6)->hit_y_plus.h -= 0xA;
        if ((s32) reg_tmp.h[0] < 0xA) {
            ENTITY(reg_a6)->hit_y_plus.h = (u16) ENTITY(reg_a6)->hp.h;
        }
        if (g_p2_laser_bomb_active == 0) {
            p2_laser_draw_alternating();
        }
    }
}

u8 D_00251AB0[16] = {
    0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x00, 0x50, 0x00, 0x12, 0x00, 0x00,
};

u8 D_00251AC0[16] = {
    0x00, 0x01, 0x01, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x00, 0x1C, 0x00, 0x12, 0x00, 0x00,
};

u16 ship_select_ship_confirm_table[8] = {
    0x2020, 0x2020, 0x2020, 0x2020, 0x2020, 0x2020, 0x2020, 0x0000,
};

u16 ship_select_ship_confirm_table_2[2] = {
    0x0000, 0x0002,
};

u16 D_0028C11C[2] = {
    0x0000, 0x0002,
};

u16 D_0028C120[4] = {
    0x0002, 0x0004, 0x0006, 0x0000,
};

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(D_00251AB0_as_u16_a, D_00251AB0, 0x0);
PC_DATA_ALIAS(D_00251AB4, D_00251AB0, 0x4);

PC_DATA_ALIAS(D_00251AC0_as_u16_a, D_00251AC0, 0x0);
PC_DATA_ALIAS(D_00251AC4, D_00251AC0, 0x4);
#endif
