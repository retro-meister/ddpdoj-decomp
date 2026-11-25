#include "common.h"
#include "entity.h"

void func_001468F0(void);
void func_00146920(void);
void func_00146940(void);
void func_001469E0(void);
void func_00146A50(void);
void func_00146A90();
void func_00146DB0();
void func_00147050();
void func_001471E0(void);
void func_00147230(void);
void func_00147250(void);
void func_001473E0(void);
void func_00147440(void);
void func_00147470();
void func_00147780(void);
void func_00147830(void);
void func_00147CA0(void);
void func_00147F30(void);
void func_00147F90(void);
void func_001480C0(void);
void func_00148110(void);

s32 debug_print_hex8_stub();
s32 debug_print_hex_short_stub();

void func_00145D40(void) {
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
extern u8 g_player1_as_u8_a[];

void func_00145E70(u8 *arg0) {
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
    if (g_player1_as_u8_a == arg0) {
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
extern u8 D_00260A70[];
extern u8 D_00260AB0[];
extern u8 D_00260AF0[];
extern u8 D_00260B30[];
extern u8 D_00260B70[];
extern u8 D_00260BB0[];
extern u8 D_00260BF0[];
extern u8 D_00260C30[];
extern u8 D_00260C70[];
extern u16 g_input_p2_previous;
extern u16 g_input_p2_pressed;
extern u16 g_input_p1_previous;
extern u16 g_input_p1_pressed;

void func_001460A0(void) {
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
    reg_a0 = (u8 *)D_00260C70;
    reg_d0.w = 0x18;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260C30;
    reg_d0.w = 0x19;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260BF0;
    reg_d0.w = 0x1B;
    sprite_palette_load();
    reg_a0 = (u8 *)D_002609F0;
    reg_d0.w = 0x1A;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260A30;
    reg_d0.w = 0x1C;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260A70;
    reg_d0.w = 0x1D;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260AB0;
    reg_d0.w = 0x1E;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260AF0;
    reg_d0.w = 0xC;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260B30;
    reg_d0.w = 0xD;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260B70;
    reg_d0.w = 0xE;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00260BB0;
    reg_d0.w = 0xF;
    sprite_palette_load();
    ENTITY(reg_a6)->flags.sb[0] = 1;
    g_input_p1_previous = 0xFFFF;
    g_input_p2_previous = 0xFFFF;
    g_input_p1_pressed = 0;
    g_input_p2_pressed = 0;
}

s32 text_layer_print();
s32 func_001A33C0();
extern u16 D_00251AD0[];
extern u16 D_0028C118[];

void func_00146350(void) {
    u16 temp_a0;
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 2);
    reg_a0 = (u8 *)(D_0028C118);
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
    func_001A33C0();
    temp_a0 = *(u16 *)(reg_a4 + 0xA);
    reg_d1.h[0] = temp_a0;
    reg_d0.h[0] = 8;
    reg_a0 = (u8 *)(D_00251AD0);
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
s32 func_00203850();
s32 func_002039B0();
s32 func_002046F0();
s32 func_00204A20();
s32 func_002053F0();
s32 func_00205D20();
s32 func_00206080();
extern s32 D_0028E998;
extern s32 D_0028E99C;
extern u8 *reg_call_target_as_u8_p;

void func_00146470(void) {
    u8 *temp_s0;
    u8 temp_v1;
    u8 temp_v1_2;

    reg_a4 = (u8 *)D_00251AC0;
    if (reg_d7.h[0] != 0) {
        reg_a4 = (u8 *)D_00251AB0;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
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
        func_00203850();
        func_002039B0();
    }
    temp_v1_2 = *(u8 *)(reg_a5 + 2);
    if (temp_v1_2 & 2) {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1_2 | 2);
    } else {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1_2 | 2);
        func_002046F0();
    }
    func_00204A20();
    func_002053F0();
    func_00205D20();
    func_00206080();
    reg_a4 = temp_s0;
}

s32 entity_draw_with_player_lasers();
extern u16 g_frame_mod2;
extern u16 g_two_player_game;

void func_00146690(arg0)
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

void func_001466E0(void) {
    if ((g_two_player_game != 0) || (g_frame_mod2 == 0)) {
        entity_draw_with_player_lasers();
    }
}

void func_00146720(void) {
    if ((g_two_player_game != 0) || (g_frame_mod2 != 0)) {
        entity_draw_with_player_lasers();
    }
}

extern u8 D_00257760[];
extern u8 D_002577B0[];
extern u16 g_player_laser_count;
extern u16 g_hyper_hit_scratch;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u16 D_0029D790_as_u16_a[];
extern u16 D_0029DD90_as_u16_a[];
extern s16 g_player2[];
extern s16 g_player1[];

void func_00146760(void) {
    s32 temp_s0;
    temp_s0 = (s32)reg_a5;
    g_hyper_hit_scratch = 0;
    g_player_laser_count = 0;
    if (g_player1[0] < 0) {
        reg_a6 = (u8 *)(D_0029DD90_as_u16_a);
        reg_d7.w = 0x1F;
        g_hyper_hit_scratch = g_p1_hyper_active;
        do {
            reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
            if (reg_d0.h[0] != 0) {
                reg_d1.w = 0x1F;
                g_player_laser_count += 1;
                reg_d1.h[0] &= reg_d0.h[0];
                ((Fn)*(u32 *)((u8 *)D_00257760 + (reg_d1.h[0] * 4)))();
            }
            reg_a6 += 0x30;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    if (g_player2[0] < 0) {
        reg_a6 = (u8 *)(D_0029D790_as_u16_a);
        reg_d7.w = 0x1F;
        g_hyper_hit_scratch = g_p2_hyper_active;
        do {
            reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
            if (reg_d0.h[0] != 0) {
                reg_d1.w = 0x1F;
                g_player_laser_count += 1;
                reg_d1.h[0] &= reg_d0.h[0];
                ((Fn)*(u32 *)((u8 *)D_002577B0 + (reg_d1.h[0] * 4)))();
            }
            reg_a6 += 0x30;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    reg_a5 = (u8 *)temp_s0;
}


void func_001468E0(void) {
    func_001468F0();
}

extern u16 D_0029F290[];
extern u16 D_0029F264[];


void func_001468F0(void) {
    reg_d0.h[0] = D_0029F290[0];
    reg_d1.h[0] = D_0029F264[0];
    func_00146940();
}


void func_00146910(void) {
    func_00146920();
}

extern u16 D_0029F1F4[];
extern u16 D_0029F220[];

void func_00146920(void) {
    reg_d0.h[0] = D_0029F220[0];
    reg_d1.h[0] = D_0029F1F4[0];
    func_00146940();
}


void func_00146940() {
    u8 *temp_a0;

    reg_d0.h[0] += 0x800;
    temp_a0 = reg_a6 + 2;
    reg_d0.h[0] += ENTITY(reg_a6)->y.h;
    if ((s32) reg_d0.h[0] >= 0x7800) {
        func_00147F30();
        return;
    }
    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
    func_00147F90();
}


void func_001469B0(void) {
    func_001469E0();
}


void func_001469C0(void) {
    func_001469E0();
}

void func_001469D0(void) {
    func_001469E0();
}

extern u8 D_0029D730[];
extern u8 D_0029D770[];
void func_001469E0(void)
{
  u16 value = D_0029F290[0];
  int new_var;
  reg_a0 = D_0029D770;
  if ((!new_var) && (!new_var))
  {
  }
  reg_d2.h[0] = (new_var = D_0029F264[0]);
  reg_a1 = D_0029D730;
  reg_d1.h[0] = value;
  func_00146A90(value);
}


void func_00146A20(void) {
    func_00146A50();
}

void func_00146A30(void) {
    func_00146A50();
}

void func_00146A40(void) {
    func_00146A50();
}

extern u8 D_0029D710[];
extern u8 D_0029D750[];
inline int inline_fn(u16 arg0, u16 arg1, u16 arg2)
{
  return (arg0 && arg1) && arg2;
}

void func_00146A50(void)
{
  u16 sourceValue = D_0029F220[0];
  u16 new_var;
  u16 new_var3;
  int new_var2;
  reg_a0 = D_0029D750;
  new_var = sourceValue;
  new_var2 = 0;
  new_var3 = D_0029F1F4[0];
  reg_a1 = D_0029D710;
  if (!new_var)
  {
  }
  if (inline_fn(new_var, new_var, new_var))
  {
  }
  reg_d1.h[new_var2] = new_var;
  reg_d2.h[new_var2] = new_var3;
  func_00146A90(new_var);
}

void func_0020A040(void);
extern u16 g_p2_laser_bomb_active;
extern u16 g_p1_laser_bomb_active;

void func_00146A90() {
    reg_d1.h[0] += 0x800;
    ENTITY(reg_a6)->y.h += reg_d1.h[0];
    ENTITY(reg_a6)->x.h = reg_d2.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a2 = (u8 *)reg_tmp.w;
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
                    func_0020A040();
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
    func_00147F30();
    return;
block_5:
    if (g_p2_laser_bomb_active != 0) return;
block_6:
    func_00146690();
}

extern u16 D_0029F180_as_u16_a[];
extern u16 D_0029F182[];
extern u16 D_0029F184[];
void func_00146CB0(void)
{
    extern void sfx_p1_laser_a_start(void);
  unsigned int highWord = D_0029F182[0];
  reg_a4 = (u8 *)((u32) D_0029F180_as_u16_a);
  reg_d0.h[0] = D_0029F184[0];
  reg_a3 = (u8 *)((u32) (&sfx_p1_laser_a_start));
  reg_d0.h[1] = highWord;
  func_00146DB0(highWord);
}

void func_00146CF0(void) {
    extern void sfx_p1_laser_b_start(void);
    unsigned int highWord = D_0029F182[0];
    reg_a4 = (u8 *)((u32)D_0029F180_as_u16_a);
    reg_d0.h[0] = D_0029F184[0];
    reg_a3 = (u8 *)((u32)(&sfx_p1_laser_b_start));
    reg_d0.h[1] = highWord;
    func_00146DB0(highWord);
}

extern u16 D_0029F110_as_u16_a[];
extern u16 D_0029F112[];
extern u16 D_0029F114[];
void func_00146D30(void)
{
    extern void sfx_p2_laser_a_start(void);
  u16 highWord = D_0029F112[0];
  reg_d0.h[1] = highWord;
  reg_a4 = (u8 *)((u32) D_0029F110_as_u16_a);
  reg_d0.h[0] = D_0029F114[0];
  reg_a3 = (u8 *)((u32) sfx_p2_laser_a_start);
  reg_d0.h[0] = D_0029F114[0];
  func_00146DB0(highWord);
}

void func_00146D70(void) {
    extern void sfx_p2_laser_b_start(void);
    unsigned int highWord = D_0029F112[0];
    reg_a4 = (u8 *)((u32)D_0029F110_as_u16_a);
    reg_d0.h[0] = D_0029F114[0];
    reg_a3 = (u8 *)((u32)(&sfx_p2_laser_b_start));
    reg_d0.h[1] = highWord;
    func_00146DB0(highWord);
}


void func_00146DB0() {
    s64 temp_v1;
    u16 temp_a0;

    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *)(reg_tmp.w);
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
        func_00147CA0();
        goto block_9;
    }
block_9:
    ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.w = (u32)reg_a0;
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    func_00146690();
}

extern u8 D_0029F180[];
extern u16 D_0029F2B8[];

void func_00146F10(void) {
    extern void func_00147050(u16);
    extern void sfx_p1_laser_a_start();
    extern void sfx_p1_laser_b_start();
    reg_a4 = D_0029F180;
    reg_a3 = (void *)sfx_p1_laser_a_start;
    reg_d0.h[1] = D_0029F182[0];
    reg_d0.h[0] = D_0029F184[0];
    if (D_0029F2B8[0] == 0) {
        func_00147050(D_0029F182[0]);
        return;
    }
    reg_a3 = (void *)sfx_p1_laser_b_start;
    func_00147050(D_0029F182[0]);
}

extern void sfx_p1_laser_hyper_start(void);

void func_00146F80(void) {
    unsigned int highWord = D_0029F182[0];
    reg_a4 = (u8 *)((u32)D_0029F180_as_u16_a);
    reg_d0.h[0] = D_0029F184[0];
    reg_a3 = (u8 *)((u32)(&sfx_p1_laser_hyper_start));
    reg_d0.h[1] = highWord;
    func_00147050(highWord);
}

extern u8 D_0029F110[];
extern u16 D_0029F248[];

void func_00146FC0(void) {
    extern void func_00147050(u16);
    extern void sfx_p2_laser_a_start();
    extern void sfx_p2_laser_b_start();
    reg_a4 = D_0029F110;
    reg_a3 = (void *)sfx_p2_laser_a_start;
    reg_d0.h[1] = D_0029F112[0];
    reg_d0.h[0] = D_0029F114[0];
    if (D_0029F248[0] != 0) {
        reg_a3 = (void *)sfx_p2_laser_b_start;
    }
    func_00147050(D_0029F112[0]);
}

extern void sfx_p2_laser_hyper_start(void);

void func_00147010(void) {
    unsigned int highWord = D_0029F112[0];
    reg_a4 = (u8 *)((u32)D_0029F110_as_u16_a);
    reg_d0.h[0] = D_0029F114[0];
    reg_a3 = (u8 *)((u32)(&sfx_p2_laser_hyper_start));
    reg_d0.h[1] = highWord;
    func_00147050(highWord);
}

void func_00147050() {
    s64 temp_v1;
    u16 temp_a0;

    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *)(reg_tmp.w);
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
        func_00147CA0();
        goto block_9;
    }
block_9:
    ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.w = (u32)reg_a0;
    ENTITY(reg_a6)->misc.h = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x26);
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    func_00146690();
}


void func_001471B0(void) {
    func_001471E0();
}


void func_001471C0(void) {
    func_001471E0();
}

void func_001471D0(void) {
    func_001471E0();
}

extern u16 D_0029F262[];


void func_001471E0(void) {
    reg_d0.h[1] = D_0029F262[0];
    *(u16 *)&reg_d0 = D_0029F264[0];
    func_00147250();
}


void func_00147200(void) {
    func_00147230();
}


void func_00147210(void) {
    func_00147230();
}

void func_00147220(void) {
    func_00147230();
}

extern u16 D_0029F1F2[];


void func_00147230(void) {
    reg_d0.h[1] = D_0029F1F2[0];
    *(u16 *)&reg_d0 = D_0029F1F4[0];
    func_00147250();
}

void func_00147250(void) {
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
        reg_a0 = (u8 *)(reg_tmp.w);
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


void func_001473B0(void) {
    func_001473E0();
}


void func_001473C0(void) {
    func_001473E0();
}

void func_001473D0(void) {
    func_001473E0();
}

extern u16 D_0029F282[];
void func_001473E0(void) {
    reg_d0.h[1] = D_0029F182[0];
    reg_d0.h[0] = D_0029F184[0];
    reg_d1.h[0] = D_0029F282[0];
    func_00147470();
}


void func_00147410(void) {
    func_00147440();
}

void func_00147420(void) {
    func_00147440();
}

void func_00147430(void) {
    func_00147440();
}


extern u16 D_0029F212[];

void func_00147440(void) {
    u16 reg_value = D_0029F112[0];

    reg_d0.h[1] = reg_value;
    reg_d0.h[0] = D_0029F114[0];
    reg_d1.h[0] = D_0029F212[0];
    func_00147470(reg_value);
}

void func_00147470() {
    *(u16 *) (reg_a6 + 2) = reg_d0.h[1];
    *(u16 *) (reg_a6 + 4) = reg_d0.h[0];
    if (*(u16 *) (reg_a6 + 0x28) == reg_d1.h[0]) goto next_1;
    *(u16 *) (reg_a6 + 0x28) = reg_d1.h[0];
    reg_d1.h[0] *= 2;
    reg_tmp.h[1] = *(u16 *) (reg_a6 + 0x1E);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = (reg_d1.h[0]) ? *(u16 *) (reg_a0 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = ((u16) reg_d1.h[0] + 2) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d1.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
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
    reg_a0 = (u8 *) reg_tmp.w;
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
    func_00146690();
}


void func_00147740(void) {
    reg_d0.h[0] = D_0029F290[0];
    reg_d1.h[0] = D_0029F264[0];
    func_00147780();
}

void func_00147760(void) {
    reg_d0.h[0] = D_0029F220[0];
    reg_d1.h[0] = D_0029F1F4[0];
    func_00147780();
}

void func_00147780() {
    reg_d0.h[0] += 0x800;
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s32) reg_d0.h[0] >= 0x7800) {
        func_00147F30();
        return;
    }
    ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
    func_00147F90();
}

extern Reg32 reg_d0;
extern Reg32 reg_d1;

void func_001477F0(void) {
    reg_d0.h[0] = D_0029F290[0];
    reg_d1.h[0] = D_0029F264[0];
    func_00147830();
}

void func_00147810(void) {
    reg_d0.h[0] = D_0029F220[0];
    reg_d1.h[0] = D_0029F1F4[0];
    func_00147830();
}

void func_00147830() {
    reg_d0.h[0] += 0x800;
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    if ((s32) reg_d0.h[0] >= 0x7800) {
        func_00147F30();
        return;
    }
    ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
    func_00147F90();
}

void func_001478A0(void) {
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a1 = (u8 *)(reg_tmp.w);
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

extern u8 D_00256130[];
extern u8 g_p2_laser_stop_y_as_u8;
extern u8 g_p1_laser_stop_y_as_u8;
extern u8 D_0029DD30[];
extern u8 D_0029E330[];
extern u8 g_player2_as_u8_a[];

void func_00147CA0(void) {
    u8 *temp_a3;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 var_a0;
    temp_a3 = (u8 *)(reg_a4);
    (*(u8 *)((u8 *)(temp_a3) + (1))) |= 0x20;
    reg_a2 = (u8 *)D_0029D770;
    reg_a3 = (u8 *)D_0029E330;
    reg_a4 = &g_p1_laser_stop_y_as_u8;
    reg_a5 = (u8 *)g_player1_as_u8_a;
    if (ENTITY(reg_a6)->move.h == 0) {
        reg_a2 = (u8 *)D_0029D750;
        reg_a3 = (u8 *)D_0029DD30;
        reg_a4 = &g_p2_laser_stop_y_as_u8;
        reg_a5 = (u8 *)g_player2_as_u8_a;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2C);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2E);
    reg_a1 = (u8 *)(reg_tmp.w);
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
    reg_a1 = (u8 *)((u32) D_00256130);
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
    *(u16 *)(reg_a2 + 0xE) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a2 + 0x18) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a2 + 0x1A) = (u16) reg_d3.h[0];
    *(u16 *)(reg_a2 + 0x1C) = (u16) reg_d0.h[0];
    func_001478A0();
}

void func_00147F30(void) {
    reg_a0 = D_0029D770;
    if (ENTITY(reg_a6)->move.h == 0) {
        reg_a0 = D_0029D750;
    }
    if (*(u16 *)(reg_a0 + 0xC) == 0) {
        *(u8 *)reg_a0 |= 1;
        *(u16 *)(reg_a0 + 0xC) = 1U;
    }
    ENTITY(reg_a6)->flags.sh = 0;
}

extern u16 g_p2_laser_stop_y;
extern u16 g_p1_laser_stop_y;

void func_00147F90(void) {
    reg_d1.h[0] = g_p1_laser_stop_y;
    reg_a0 = (u8 *)D_0029D730;
    reg_a2 = (u8 *)D_0029D770;
    reg_a5 = (u8 *)g_player1_as_u8_a;
    if (ENTITY(reg_a6)->move.h != 0) goto block_1;
    reg_d1.h[0] = g_p2_laser_stop_y;
    reg_a0 = (u8 *)D_0029D710;
    reg_a2 = (u8 *)D_0029D750;
    reg_a5 = (u8 *)g_player2_as_u8_a;
block_1:
    switch (*(u8 *)(reg_a2 + 1) & 0x10) {
    case 0:
        goto block_4;
    }
    *(u16 *)(reg_a0 + 0x16) = 9;
block_2:
    if ((s32)reg_d1.h[0] <= (s32)reg_d0.h[0]) goto block_3;
    if ((s32)reg_d0.h[0] >= (s32)*(u16 *)(reg_a0 + 2)) goto next_1;
    func_001480C0();
    return;
next_1:
    reg_d1.h[0] = reg_d0.h[0];
    func_00148110();
    func_001480C0();
    return;
block_3:
    ENTITY(reg_a6)->flags.h = 0;
    if (*(s16 *)reg_a0 < 0) return;
    func_00148110();
    return;
block_4:
    if (*(u16 *)(reg_a0 + 0x16) != 0) goto block_2;
    *(u16 *)reg_a0 = 0;
    func_001480C0();
}


void func_001480C0(void) {
    if (ENTITY(reg_a6)->move.h != 0) {
        if (g_p1_laser_bomb_active != 0) {
            return;
        }
        goto block_4;
    }
    if (g_p2_laser_bomb_active == 0) {
block_4:
        func_00146690();
    }
}

extern u16 D_002576C0[];

void func_00148110(void) {
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

s32 func_0020A120();
s32 func_0020A1C0();

void func_001482C0(void) {
    u16 temp_a2;
    u16 temp_a2_2;
    u32 temp_a1;
    u32 temp_a1_2;

    reg_a6 = (u8 *)D_0029D730;
    if (ENTITY(reg_a6)->flags.sh < 0) {
        if ((g_frame_mod2 != 0) && (g_two_player_game != 0) && (g_p1_laser_bomb_active == 0)) {
            func_0020A120();
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
        reg_a0 = (u8 *)(reg_tmp.w);
        temp_a2 = ENTITY(reg_a6)->hit_y_plus.h;
        reg_a0 += temp_a2;
        *(u16 *)reg_a1 = reg_d0.h[0];
        reg_a1 += 2;
        *(u16 *)reg_a1 = D_0029F264[0];
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
        temp_a1 = (unsigned int)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a1);
        reg_a1 += 2;
        reg_tmp.h[0] = ENTITY(reg_a6)->hit_y_plus.h;
        ENTITY(reg_a6)->hit_y_plus.h -= 0xA;
        if ((s32) reg_tmp.h[0] < 0xA) {
            ENTITY(reg_a6)->hit_y_plus.h = (u16) ENTITY(reg_a6)->hp.h;
        }
        if (g_p1_laser_bomb_active == 0) {
            func_001466E0();
        }
    }
    reg_a6 = (u8 *)D_0029D710;
    if (ENTITY(reg_a6)->flags.sh < 0) {
        if ((g_frame_mod2 == 0) && (g_two_player_game != 0) && (g_p2_laser_bomb_active == 0)) {
            func_0020A1C0();
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
        reg_a0 = (u8 *)(reg_tmp.w);
        temp_a2_2 = ENTITY(reg_a6)->hit_y_plus.h;
        reg_a0 += temp_a2_2;
        *(u16 *)reg_a1 = reg_d0.h[0];
        reg_a1 += 2;
        *(u16 *)reg_a1 = D_0029F1F4[0];
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
        temp_a1_2 = (unsigned int)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a1_2);
        reg_a1 += 2;
        reg_tmp.h[0] = ENTITY(reg_a6)->hit_y_plus.h;
        ENTITY(reg_a6)->hit_y_plus.h -= 0xA;
        if ((s32) reg_tmp.h[0] < 0xA) {
            ENTITY(reg_a6)->hit_y_plus.h = (u16) ENTITY(reg_a6)->hp.h;
        }
        if (g_p2_laser_bomb_active == 0) {
            func_00146720();
        }
    }
}
