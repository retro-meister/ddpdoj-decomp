#include "common.h"
#include "player.h"
#include "entity.h"

extern void (*p1_laser_clear_table[2])();
extern void (*D_0028C5E0[2])();

u16 hyper_bullet_speed_table[] = {
    0x0001, 0x0001, 0x0002, 0x0002, 0x0003, 0x0003, 0x0004, 0x0004,
    0x0005, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000A, 0x000A,
    0x000A, 0x000A, 0x000A, 0x000A, 0x000A, 0x000A, 0x000A, 0x000A,
    0x000A,
};

u16 bomb_capacity_glyphs[] = {
    0x000A, 0x02DE, 0x000A, 0x0302, 0x000A, 0x0326, 0x000A, 0x034A,
    0x000A, 0x034A, 0x000A, 0x034A,
};

u16 maximum_mark_attrs[] = {
    0x0000, 0x0019, 0x0000, 0x0019, 0x0000, 0x001A,
};

u16 p1_maximum_level_texts[] = {
    0x0000, 0x0001, 0x0007, 0x0006, 0x0004, 0x0005, 0x0007, 0x0006,
    0x0008, 0x0009, 0x0007, 0x0002,
};

u16 p2_maximum_level_texts[] = {
    0x0000, 0x0001, 0x0008, 0x0002, 0x0004, 0x0005, 0x0008, 0x0002,
    0x0008, 0x0009, 0x0008, 0x0002,
};

void p1_laser_clear(void);
void p2_laser_clear(void);
void laser_entities_clear(void);
void p2_hyper_stock_draw();
void p1_hyper_stock_draw();
void hyper_stock_draw_trail(void);
void position_trail_fill();
void power_up_refused(void);
void power_max_refused(void);
void p1_maximum_level_show();
void p2_maximum_level_show();
void bomb_stock_draw(void);
void p1_bomb_slot_fill(void);
void p2_bomb_slot_fill(void);
void bomb_slot_fill(void);
void p1_bomb_capacity_draw(void);
void p2_bomb_capacity_draw(void);
void bomb_capacity_draw(void);
void p2_afterimage_draw(void);
void p1_afterimage_draw(void);
void ship_afterimage_draw(void);
void afterimage_fill(void);

extern u8 g_p1_options[];

void p1_laser_stop(void) {
    ((u16 *)g_p1_options)[0] &= 0xDFFB;
    p1_laser_clear();
}

typedef void (*Fn)(void);

extern u32 reg_save_d7;
extern u32 reg_save_d6;
extern u32 reg_save_d5;
extern u32 reg_save_d0;
extern u8 *reg_save_a6;
extern u8 *reg_save_a2;
extern u8 *reg_save_a1;
extern s32 reg_save_a0;
extern u16 g_p1_hyper_active;
extern u8 D_0029D730[];
extern u8 D_0029D770[];
extern u8 g_p1_laser_entities[];
extern u8 g_p1_options[];
extern u16 D_0029F2B8[];

void sfx_p1_laser_hyper_stop(void);

void p1_laser_clear(void) {
    reg_save_d0 = reg_d0.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    (*(u8 **)&reg_save_a0) = reg_a0;
    reg_save_a1 = reg_a1;
    reg_save_a2 = reg_a2;
    reg_save_a6 = reg_a6;
    reg_d0.h[0] = D_0029F2B8[0];
    reg_d0.h[0] <<= 1;
    reg_a0 = *(u8 **)(((u8 *)p1_laser_clear_table) + (reg_d0.h[0] & ~3));
    if (g_p1_hyper_active != 0) {
        reg_a0 = (u8 *)sfx_p1_laser_hyper_stop;
    }
    reg_call_target = (Fn)reg_a0;
    reg_call_target();
    reg_a6 = (u8 *)g_p1_laser_entities;
    reg_a0 = (u8 *)D_0029D770;
    reg_a1 = (u8 *)D_0029D730;
    reg_a2 = (u8 *)g_p1_options;
    laser_entities_clear();
}

extern u8 g_p2_options[];


void p2_laser_stop(void) {
    ((u16 *)g_p2_options)[0] &= 0xDFFB;
    p2_laser_clear();
}

extern u16 g_p2_hyper_active;
extern u8 D_0029D710[];
extern u8 D_0029D750[];
extern u8 g_p2_laser_entities[];
extern u8 g_p2_options[];
extern u16 D_0029F248[];

void sfx_p2_laser_hyper_stop(void);

void p2_laser_clear(void) {
    reg_save_d0 = reg_d0.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    (*(u8 **)&reg_save_a0) = reg_a0;
    reg_save_a1 = reg_a1;
    reg_save_a2 = reg_a2;
    reg_save_a6 = reg_a6;
    reg_d0.h[0] = D_0029F248[0];
    reg_d0.h[0] <<= 1;
    reg_a0 = *(u8 **)(((u8 *)D_0028C5E0) + (reg_d0.h[0] & ~3));
    if (g_p2_hyper_active != 0) {
        reg_a0 = (u8 *)sfx_p2_laser_hyper_stop;
    }
    reg_call_target = (Fn)reg_a0;
    reg_call_target();
    reg_a6 = (u8 *)g_p2_laser_entities;
    reg_a0 = (u8 *)D_0029D750;
    reg_a1 = (u8 *)D_0029D710;
    reg_a2 = (u8 *)g_p2_options;
    laser_entities_clear();
}

extern s32 reg_save_a0;

void laser_entities_clear(void) {
    *reg_a2 &= 0x7F;
    reg_d0.w = 0;
    *(*(u16 **)&reg_a0) = reg_d0.h[0];
    (*(u16 *)(reg_a1 + 0)) = reg_d0.h[0];
    (*(u16 *)(reg_a1 + 0x16)) = reg_d0.h[0];
    reg_d7.h[0] = 0x1F;
    do {
        ENTITY(reg_a6)->flags.h = reg_d0.h[0];
        reg_a6 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = reg_save_d0;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    (*(u16 **)&reg_a0) = (*(u16 **)&reg_save_a0);
    reg_a1 = reg_save_a1;
    reg_a2 = reg_save_a2;
    reg_a6 = reg_save_a6;
}

extern u16 g_p2_hyper_items;
extern u16 g_p1_hyper_items;
extern s16 g_player2[];
extern s16 g_player1[];

void hyper_stock_draw(void) {
    if (g_player1[0] < 0) {
        reg_d0.h[0] = g_p1_hyper_items;
        reg_a1 = (u8 *)g_player1;
        if (reg_d0.h[0] != 0) {
            p1_hyper_stock_draw(g_player1);
        }
    }
    if (g_player2[0] < 0) {
        reg_d0.h[0] = g_p2_hyper_items;
        reg_a1 = (u8 *)g_player2;
        if (reg_d0.h[0] != 0) {
            p2_hyper_stock_draw(g_player2);
        }
    }
}

extern s32 g_p2_position_trail[16];

void p2_hyper_stock_draw() {
    reg_a0 = (u8 *)((u8 *)g_p2_position_trail);
    hyper_stock_draw_trail();
}

extern s32 g_p1_position_trail[16];

void p1_hyper_stock_draw() {
    reg_a0 = (u8 *)((u8 *)g_p1_position_trail);
    hyper_stock_draw_trail();
}

void sprite_draw_with_hyper_display_keep(void);
extern u16 g_players_hidden;
extern u16 g_frame_mod2;
extern u16 g_game_frame;
extern u16 g_loop;

void hyper_stock_draw_trail(void) {
    if (reg_d0.h[0] != 5) {
        reg_d4.h[0] = 5;
        reg_d2.w = 0x1E;
        reg_d2.h[0] &= g_game_frame;
        reg_d2.h[0] <<= 1;
    } else {
        reg_d4.h[0] = 5;
        reg_d2.w = 0xF;
        reg_d2.h[0] &= g_game_frame;
    }
    reg_d2.h[0] >>= 1;
    reg_d2.w += 0xB42;
    reg_d3.h[0] = 0x418;
    reg_d6.h[0] = 0xF000;
    reg_d7.w = 5;
    reg_a0 += 0x40;
    goto loop_2;
loop_1:
    if (reg_d7.h[0] == 0) {
        *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
        *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
        reg_a0 -= 4;
        reg_d0.h[0] = *(u16 *)(reg_a1 + 2);
        reg_d1.h[0] = *(u16 *)(reg_a1 + 4);
        reg_d2.h[0] = 0xF700;
        if (*(u16 *)(reg_a1 + 0x58) != 0) {
            reg_d2.h[0] = 0xF800;
        }
        reg_d0.h[0] += reg_d2.h[0];
        *(u16 *)(reg_a0 - 4) = reg_d0.h[0];
        *(u16 *)(reg_a0 - 2) = reg_d1.h[0];
        return;
    }
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
loop_2:
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
    if ((g_players_hidden == 0) && (reg_d7.h[0] == reg_d0.h[0])) {
        reg_d0.h[0] -= 1;
        reg_d1.h[1] = *(u16 *)(reg_a0 + 0);
        reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] += reg_d6.h[0];
        if (((s16) reg_d1.h[0] >= -0x500) && ((g_loop == 0) || (*(u8 *)(reg_a1 + 0x3E) == 0) || (g_frame_mod2 == 0))) {
            reg_tmp1.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = reg_tmp1.h[0];
            reg_d1.h[0] += 0xFCC0;
            sprite_draw_with_hyper_display_keep();
        }
    }
    reg_d2.w += 1;
    if ((u32) reg_d2.w >= 0xB52U) {
        if (reg_d2.w == 0xB52) {
            reg_d2.w = 0xB42;
        } else {
            reg_d2.w = 0xB43;
        }
    }
    reg_d6.h[0] -= 0xFD00;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
}
extern s32 g_p2_position_trail[16];

void p2_position_trail_fill(void) {
    u16 src = PLAYER(g_player2)->y.h;
    reg_d1.h[1] = src;
    reg_d1.h[0] = PLAYER(g_player2)->x.h;
    reg_a0 = (u8 *)((u8 *)g_p2_position_trail);
    position_trail_fill(src);
}

void p1_position_trail_fill(void) {
    u16 src = PLAYER(g_player1)->y.h;
    reg_d1.h[1] = src;
    reg_d1.h[0] = PLAYER(g_player1)->x.h;
    reg_a0 = (u8 *)((u8 *)g_p1_position_trail);
    position_trail_fill(src);
}

void position_trail_fill() {
    reg_d0.h[0] = 0xF;
    do {
        *(*(u16 **)&reg_a0) = reg_d1.h[1];
        (*(u16 **)&reg_a0) += 1;
        *(*(u16 **)&reg_a0) = reg_d1.h[0];
        (*(u16 **)&reg_a0) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

s32 sprite_draw_with_maximum();
extern u16 g_p2_maximum_anim_delay_reset;
extern u16 g_p2_maximum_anim_delay;
extern u16 g_p1_maximum_anim_delay_reset;
extern u16 g_p1_maximum_anim_delay;
extern u16 g_p2_maximum_level;
extern u16 g_p1_maximum_level;
extern u16 g_select_screen_active;
extern u8 g_boss_present_b1;
extern u16 g_true_last_boss;
extern u16 g_p2_maximum_value[];
extern u16 g_p1_maximum_value[];

void maximum_marks_draw(void) {
    if (g_select_screen_active == 0) {
        reg_d0.h[0] = ((u16 *)g_player1)[0];
        if (((s16)(reg_d0.h[0]) < 0) && !(reg_d0.h[0] & 0xFFFF & 0x4000) && (g_p1_maximum_value[0] != 0)) {
            reg_a1 = (u8 *)(&PLAYER(g_player1)->max_text_sprite_hi.b[0]);
            reg_d0.h[0] = g_p1_maximum_level;
            reg_d4.h[0] = 7;
            reg_tmp.h[0] = g_p1_maximum_anim_delay;
            g_p1_maximum_anim_delay -= 1;
            if ((s32) reg_tmp.h[0] <= 0) {
                g_p1_maximum_anim_delay = g_p1_maximum_anim_delay_reset;
            }
            switch (g_frame_mod2) { case 0: break; default:
                reg_a0 = (u8 *)(maximum_mark_attrs);
                reg_d4.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d4.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            }
            if (((g_true_last_boss == 0) && !(g_boss_present_b1 & 1)) || (reg_tmp.h[1] = *(u16 *)reg_a1, reg_tmp.h[0] = *(u16 *)(reg_a1 + 2), (reg_tmp.w != 0xC41))) {
                reg_tmp.h[1] = *(u16 *)reg_a1;
                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                reg_tmp.w += 1;
                *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                if (reg_tmp.w == 0xCA1) {
                    reg_tmp.w = 0xC41;
                    *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                    *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                }
            }
            reg_d1.w = 0xFF010200;
            reg_d2.h[1] = *(u16 *)reg_a1;
            reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d3.h[0] = 0x460;
            sprite_draw_with_maximum();
        }
        reg_d0.h[0] = ((u16 *)g_player2)[0];
        if (((s16)(reg_d0.h[0]) < 0) && !(reg_d0.h[0] & 0xFFFF & 0x4000) && (g_p2_maximum_value[0] != 0)) {
            reg_a1 = (u8 *)(&PLAYER(g_player2)->max_text_sprite_hi.b[0]);
            reg_d0.h[0] = g_p2_maximum_level;
            reg_d4.h[0] = 8;
            reg_tmp.h[0] = g_p2_maximum_anim_delay;
            g_p2_maximum_anim_delay -= 1;
            if ((s32) reg_tmp.h[0] <= 0) {
                g_p2_maximum_anim_delay = g_p2_maximum_anim_delay_reset;
            }
            if (g_frame_mod2 != 0) {
                reg_a0 = (u8 *)(maximum_mark_attrs);
                reg_d4.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d4.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            }
            if (((g_true_last_boss == 0) && !(g_boss_present_b1 & 1)) || (reg_tmp.h[1] = *(u16 *)reg_a1, reg_tmp.h[0] = *(u16 *)(reg_a1 + 2), (reg_tmp.w != 0xC41))) {
                reg_tmp.h[1] = *(u16 *)reg_a1;
                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                reg_tmp.w += 1;
                *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                if (reg_tmp.w == 0xCA1) {
                    reg_tmp.w = 0xC41;
                    *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                    *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                }
            }
            reg_d1.w = 0xFF011E00;
            reg_d2.h[1] = *(u16 *)reg_a1;
            reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d3.h[0] = 0x460;
            sprite_draw_with_maximum();
        }
    }
}

s32 sprite_draw_with_hyper_ready();

void hyper_ready_mark_draw() {
    u16 temp_a0;

    reg_tmp.b[0] = *(u8 *)(reg_a0 + 1);
    *(u8 *)(reg_a0 + 1) -= 1;
    if (((s32) reg_tmp.b[0] <= 0) && (*(u8 *)(reg_a0 + 1) = (u8) *(u8 *)reg_a0, reg_tmp.h[1] = *(u16 *)reg_a1, reg_tmp.h[0] = *(u16 *)(reg_a1 + 2), reg_tmp.w += 1, *(u16 *)reg_a1 = (u16) reg_tmp.h[1], *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0], (reg_tmp.w == 0xC3A))) {
        *(u8 *)(reg_a0 + 1) = 0x10U;
    } else {
        reg_tmp.h[1] = *(u16 *)reg_a1;
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        if (reg_tmp.w == 0xC41) {
            reg_tmp.w = 0xC36;
            *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
        }
    }
    reg_d2.h[1] = *(u16 *)reg_a1;
    temp_a0 = *(u16 *)(reg_a1 + 2);
    reg_d2.h[0] = temp_a0;
    reg_d3.h[0] = 0x270;
    reg_d4.h[0] = 9;
    sprite_draw_with_hyper_ready();
}

extern u16 g_p2_hyper_ready_anim_delay;
extern u16 g_p1_hyper_ready_anim_delay;
extern s32 g_p2_hyper_ready_sprite;
extern s32 g_p1_hyper_ready_sprite;
extern u16 g_frame_mod4;

void hyper_ready_marks_draw(void) {
    extern void hyper_ready_mark_draw(u16);
    if (g_select_screen_active == 0) {
        reg_d0.h[0] = ((u16 *)g_player1)[0];
        if ((((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) < 0) && (g_p1_hyper_items != 0) && ((reg_d0.h[0] & 0xFFFF & 0x4000) || (g_p1_maximum_value[0] == 0) || (g_frame_mod4 != 0))) {
            reg_a0 = (u8 *)(&(*(s32 *)&g_p1_hyper_ready_anim_delay));
            reg_a1 = (u8 *)(&g_p1_hyper_ready_sprite);
            reg_d1.w = 0x810000;
            hyper_ready_mark_draw(reg_d0.h[0]);
        }
        reg_d0.h[0] = ((u16 *)g_player2)[0];
        if ((((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) < 0) && (g_p2_hyper_items != 0) && ((reg_d0.h[0] & 0xFFFF & 0x4000) || (g_p2_maximum_value[0] == 0) || (g_game_frame & 2))) {
            reg_a0 = (u8 *)(&(*(s32 *)&g_p2_hyper_ready_anim_delay));
            reg_a1 = (u8 *)(&g_p2_hyper_ready_sprite);
            reg_d1.w = 0x811C00;
            hyper_ready_mark_draw(reg_d0.h[0]);
        }
    }
}

extern u16 g_hyper_bullet_speed;
extern u16 g_p2_hyper_total;
extern u16 g_p1_hyper_total;
extern u16 g_stage;

void hyper_bullet_speed_update(void) {
    reg_d0.h[0] = g_p1_hyper_total;
    if ((s32) g_p2_hyper_total > (s32) reg_d0.h[0]) {
        reg_d0.h[0] = g_p2_hyper_total;
    }
    if (reg_d0.h[0] == 0) goto next_1;
    reg_d2.h[0] = g_p1_hyper_active;
    reg_d2.h[0] |= g_p2_hyper_active;
    if (reg_d2.h[0] != 0) goto next_2;
    reg_d0.h[0] >>= 2;
    if (reg_d0.h[0] == 0) goto next_1;
next_2:
    reg_d2.h[0] = reg_d0.h[0];
    reg_a0 = (u8 *) ((u16 *)hyper_bullet_speed_table);
    reg_d2.h[0] -= 1;
    reg_d2.h[0] *= 2;
    reg_d0.h[0] = (reg_d2.h[0] != 0) ? *(u16 *) ((u8 *) reg_a0 + ((s16) reg_d2.h[0] & ~1)) : *(u16 *) reg_a0;
    if (g_boss_present_b1 & 4) {
        reg_d0.h[0] += 2;
    }
next_1:
    if (g_loop != 0) {
        reg_d0.h[0] += 1;
        if ((g_stage == 4) && (g_true_last_boss != 0)) {
            reg_d0.h[0] += 4;
        }
    }
    if ((s32) reg_d0.h[0] > 0xA) {
        reg_d0.h[0] = 0xA;
    }
    g_hyper_bullet_speed = MAIN_OR_DEATH_LABEL(reg_d0.h[0], 0xA);
}

extern u8 player_weapon_tables[];
extern u8 g_p1_weapon_level_data[];
extern u8 g_p1_option_level_data_as_u8_a[];
extern s16 D_0029F1D0[];

void p1_power_up(void) {
    reg_d0.h[0] = PLAYER(g_player1)->shot_power.h;
    reg_d0.h[0] += PLAYER(g_player1)->laser_power.h;
    if (reg_d0.h[0] == 0x10) {
        power_up_refused();
        return;
    }
    if (PLAYER(g_player1)->laser_power.h != 8) {
        PLAYER(g_player1)->laser_power.h += 2;
        p1_laser_stop();
        D_0029F1D0[0] = 0;
    }
    if (PLAYER(g_player1)->shot_power.h != 8) {
        PLAYER(g_player1)->shot_power.h += 2;
        reg_a0 = (u8 *)player_weapon_tables;
        reg_d0.h[0] = PLAYER(g_player1)->power_style.h;
        reg_d0.h[0] -= 2;
        reg_d0.h[0] <<= 1;
        reg_d0.h[0] += D_0029F2B8[0];
        reg_d0.h[0] <<= 2;
        reg_tmp.h[1] = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a0;
        reg_a1 = (u8 *)reg_tmp.w;
        reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
        reg_tmp.h[1] = (reg_d0.h[0]) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)reg_tmp.w;
        reg_d0.h[0] = *(u16 *)(reg_a0 + 8);
        reg_a1 = (u8 *)g_p1_weapon_level_data;
        reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a0 + 0) != reg_d0.h[0]) {
            reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
            reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
            reg_tmp.w += 2;
            *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
            *(u16 *)(reg_a1 + 2) = reg_tmp.h[0];
        }
        reg_a2 = (u8 *)g_p1_option_level_data_as_u8_a;
        reg_tmp.h[1] = *(u16 *)(reg_a2 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a0 + 0) != reg_d1.h[0]) {
            reg_tmp.h[1] = *(u16 *)(reg_a1 + 4);
            reg_tmp.h[0] = *(u16 *)(reg_a1 + 6);
            reg_tmp.w += 2;
            *(u16 *)(reg_a1 + 4) = reg_tmp.h[1];
            *(u16 *)(reg_a1 + 6) = reg_tmp.h[0];
        }
    }
    cond_flag = 0;
}


void power_up_refused(void) {
    (*(u8 *)&cond_flag) = 1;
}

extern u8 g_p2_weapon_level_data[];
extern u8 g_p2_option_level_data_as_u8_a[];
extern s16 D_0029F160[];

void p2_power_up(void) {
    reg_d0.h[0] = PLAYER(g_player2)->shot_power.h;
    reg_d0.h[0] += PLAYER(g_player2)->laser_power.h;
    if (reg_d0.h[0] == 0x10) {
        power_up_refused();
        return;
    }
    if (PLAYER(g_player2)->laser_power.h != 8) {
        PLAYER(g_player2)->laser_power.h += 2;
        p2_laser_stop();
        D_0029F160[0] = 0;
    }
    if (PLAYER(g_player2)->shot_power.h != 8) {
        PLAYER(g_player2)->shot_power.h += 2;
        reg_a0 = (u8 *)player_weapon_tables;
        reg_d0.h[0] = PLAYER(g_player2)->power_style.h;
        reg_d0.h[0] -= 2;
        reg_d0.h[0] <<= 1;
        reg_d0.h[0] += D_0029F248[0];
        reg_d0.h[0] <<= 2;
        reg_tmp.h[1] = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a0;
        reg_a1 = (u8 *)reg_tmp.w;
        reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
        reg_tmp.h[1] = (reg_d0.h[0]) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)reg_tmp.w;
        reg_d0.h[0] = *(u16 *)(reg_a0 + 8);
        reg_a1 = (u8 *)g_p2_weapon_level_data;
        reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a0 + 0) != reg_d0.h[0]) {
            reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
            reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
            reg_tmp.w += 2;
            *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
            *(u16 *)(reg_a1 + 2) = reg_tmp.h[0];
        }
        reg_a2 = (u8 *)g_p2_option_level_data_as_u8_a;
        reg_tmp.h[1] = *(u16 *)(reg_a2 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a0 + 0) != reg_d1.h[0]) {
            reg_tmp.h[1] = *(u16 *)(reg_a1 + 4);
            reg_tmp.h[0] = *(u16 *)(reg_a1 + 6);
            reg_tmp.w += 2;
            *(u16 *)(reg_a1 + 4) = reg_tmp.h[1];
            *(u16 *)(reg_a1 + 6) = reg_tmp.h[0];
        }
    }
    cond_flag = 0;
}


void p1_power_max(void) {
    reg_d0.h[0] = PLAYER(g_player1)->shot_power.h;
    reg_d0.h[0] += PLAYER(g_player1)->laser_power.h;
    if (reg_d0.h[0] == 0x10) {
        power_max_refused();
        return;
    }
    if (PLAYER(g_player1)->laser_power.h != 8) {
        PLAYER(g_player1)->laser_power.h = 8;
        p1_laser_stop();
        D_0029F1D0[0] = 0;
        if (PLAYER(g_player1)->shot_power.h == 8) goto block_end;
    }
    PLAYER(g_player1)->shot_power.h = 8;
    reg_a0 = (u8 *)player_weapon_tables;
    reg_a1 = (u8 *)g_p1_weapon_level_data;
    reg_d0.h[0] = PLAYER(g_player1)->power_style.h;
    reg_d0.h[0] -= 2;
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += D_0029F2B8[0];
    reg_d0.h[0] <<= 2;
    *(u16 *)(reg_a1 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 2) = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 4) = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 6) = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
    reg_tmp.w += 8;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 2) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 6);
    reg_tmp.w += 8;
    *(u16 *)(reg_a1 + 4) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 6) = reg_tmp.h[0];
block_end:
    cond_flag = 0;
}

void power_max_refused(void) {
    (*(u8 *)&cond_flag) = 1;
}

void p2_power_max(void) {
    reg_d0.h[0] = PLAYER(g_player2)->shot_power.h;
    reg_d0.h[0] += PLAYER(g_player2)->laser_power.h;
    if (reg_d0.h[0] == 0x10) {
        power_max_refused();
        return;
    }
    if (PLAYER(g_player2)->laser_power.h != 8) {
        PLAYER(g_player2)->laser_power.h = 8;
        p2_laser_stop();
        D_0029F160[0] = 0;
        if (PLAYER(g_player2)->shot_power.h == 8) goto block_end;
    }
    PLAYER(g_player2)->shot_power.h = 8;
    reg_a0 = (u8 *)player_weapon_tables;
    reg_a1 = (u8 *)g_p2_weapon_level_data;
    reg_d0.h[0] = PLAYER(g_player2)->power_style.h;
    reg_d0.h[0] -= 2;
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += D_0029F248[0];
    reg_d0.h[0] <<= 2;
    *(u16 *)(reg_a1 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 2) = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 4) = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 6) = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
    reg_tmp.w += 8;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 2) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 6);
    reg_tmp.w += 8;
    *(u16 *)(reg_a1 + 4) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 6) = reg_tmp.h[0];
block_end:
    cond_flag = 0;
}

extern void binary_to_bcd(void);
extern s32 g_p1_maximum_value_digits[];
extern u32 g_p1_maximum_half_digits[];
extern u16 g_p1_maximum_count[];
extern u16 g_p1_maximum_count_digits[];

void p1_maximum_digits_update(void)
{
    reg_d0.h[0] = g_p1_maximum_value[0];
    reg_d5.h[0] = reg_d0.h[0];
    binary_to_bcd();

    ((u32 *)g_p1_maximum_value_digits)[0] = reg_d2.w;
    reg_d5.h[0] >>= 1;
    reg_d0.h[0] = reg_d5.h[0];
    binary_to_bcd();

    g_p1_maximum_half_digits[0] = reg_d2.w;
    reg_d0.h[0] = g_p1_maximum_count[0];
    binary_to_bcd();

    g_p1_maximum_count_digits[0] = reg_d2.h[0];
}

extern s32 g_p2_maximum_value_digits[];
extern u32 g_p2_maximum_half_digits[];
extern u16 g_p2_maximum_count[];
extern u16 g_p2_maximum_count_digits[];


void p2_maximum_digits_update(void) {
    reg_d0.h[0] = g_p2_maximum_value[0];
    reg_d5.h[0] = reg_d0.h[0];
    binary_to_bcd();

    ((u32 *)g_p2_maximum_value_digits)[0] = reg_d2.w;
    reg_d5.h[0] >>= 1;
    reg_d0.h[0] = reg_d5.h[0];
    binary_to_bcd();

    g_p2_maximum_half_digits[0] = reg_d2.w;
    reg_d0.h[0] = g_p2_maximum_count[0];
    binary_to_bcd();

    g_p2_maximum_count_digits[0] = reg_d2.h[0];
}


void p1_bomb_item_take(void) {
    reg_d6.b[0] = *(u8 *)(u32)(&PLAYER(((u8 *)g_player1))->bombs.b.count);
    if (*(u8 *)(u32)(&PLAYER(((u8 *)g_player1))->bombs.b.capacity) == reg_d6.b[0]) goto block_50;
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.b[0] += 1;
    *(u8 *)(u32)(&PLAYER(((u8 *)g_player1))->bombs.b.count) = reg_d5.b[0];
    if (*(u8 *)(u32)(&PLAYER(((u8 *)g_player1))->bombs.b.capacity) != reg_d5.b[0]) goto block_51;
    PLAYER(((u8 *)g_player1))->flags.b[1] &= 0xBF;
    ((u8 *)g_player1)[0] |= 2;
    if (g_p1_maximum_count[0] == 0x63) goto block_end;
    g_p1_maximum_value[0] += 0x16;
    g_p1_maximum_count[0] += 1;
    p1_maximum_digits_update();
    p1_bomb_capacity_draw();
    goto block_end;
block_51:
    if (g_p1_hyper_items != 0) goto block_end;
    p1_bomb_slot_fill();
block_end:
    cond_flag = 0;
    return;
block_50:
    if (g_p1_maximum_count[0] == 0x63) goto block_end;
    g_p1_maximum_value[0] += 0x16;
    g_p1_maximum_count[0] += 1;
    reg_tmp.b[0] = *(u8 *)(u32)(&PLAYER(((u8 *)g_player1))->flags.b[1]);
    *(u8 *)(u32)(&PLAYER(((u8 *)g_player1))->flags.b[1]) &= 0xBF;
    if (reg_tmp.b[0] & 0x40) goto block_52;
    reg_tmp.b[0] = ((u8 *)g_player1)[0];
    ((u8 *)g_player1)[0] |= 2;
    if (reg_tmp.b[0] & 2) goto block_52;
    g_p1_maximum_value[0] += 0x16;
    g_p1_maximum_count[0] += 1;
block_52:
    p1_maximum_digits_update();
    p1_bomb_capacity_draw();
    goto block_end;
}


void p2_bomb_item_take(void) {
    reg_d6.b[0] = *(u8 *)(u32)(&PLAYER(((u8 *)g_player2))->bombs.b.count);
    if (*(u8 *)(u32)(&PLAYER(((u8 *)g_player2))->bombs.b.capacity) == reg_d6.b[0]) goto block_50;
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.b[0] += 1;
    *(u8 *)(u32)(&PLAYER(((u8 *)g_player2))->bombs.b.count) = reg_d5.b[0];
    if (*(u8 *)(u32)(&PLAYER(((u8 *)g_player2))->bombs.b.capacity) != reg_d5.b[0]) goto block_51;
    PLAYER(((u8 *)g_player2))->flags.b[1] &= 0xBF;
    ((u8 *)g_player2)[0] |= 2;
    if (g_p2_maximum_count[0] == 0x63) goto block_end;
    g_p2_maximum_value[0] += 0x16;
    g_p2_maximum_count[0] += 1;
    p2_maximum_digits_update();
    p2_bomb_capacity_draw();
    goto block_end;
block_51:
    if (g_p2_hyper_items != 0) goto block_end;
    p2_bomb_slot_fill();
block_end:
    cond_flag = 0;
    return;
block_50:
    if (g_p2_maximum_count[0] == 0x63) goto block_end;
    g_p2_maximum_value[0] += 0x16;
    g_p2_maximum_count[0] += 1;
    reg_tmp.b[0] = *(u8 *)(u32)(&PLAYER(((u8 *)g_player2))->flags.b[1]);
    *(u8 *)(u32)(&PLAYER(((u8 *)g_player2))->flags.b[1]) &= 0xBF;
    if (reg_tmp.b[0] & 0x40) goto block_52;
    reg_tmp.b[0] = ((u8 *)g_player2)[0];
    ((u8 *)g_player2)[0] |= 2;
    if (reg_tmp.b[0] & 2) goto block_52;
    g_p2_maximum_value[0] += 0x16;
    g_p2_maximum_count[0] += 1;
block_52:
    p2_maximum_digits_update();
    p2_bomb_capacity_draw();
    goto block_end;
}

s32 hud_p1_hyper_count_put();                            /* extern */
extern u8 g_p1_stage_start_timer;
extern u16 g_p1_hyper_time;

void p1_hyper_item_take(void) {
    if (g_p1_hyper_items == 0) {
        p1_position_trail_fill();
    }
    g_p1_hyper_items += 1;
    g_p1_hyper_time = 0x95F;
    p1_bomb_capacity_draw();
    hud_p1_hyper_count_put();
    g_p1_stage_start_timer = 0;
}

s32 hud_p2_hyper_count_put();                            /* extern */
extern u8 g_p2_stage_start_timer;
extern u16 g_p2_hyper_time;

void p2_hyper_item_take(void) {
    if (g_p2_hyper_items == 0) {
        p2_position_trail_fill();
    }
    g_p2_hyper_items += 1;
    g_p2_hyper_time = 0x95F;
    p2_bomb_capacity_draw();
    hud_p2_hyper_count_put();
    g_p2_stage_start_timer = 0;
}

s32 hud_p1_lives_put(u16);
extern u16 g_p1_lives;

void p1_life_add(void) {
    u16 temp_a0;

    temp_a0 = (s16)g_p1_lives;
    if (temp_a0 != 0x14) {
        g_p1_lives = temp_a0 + 1;
        hud_p1_lives_put(temp_a0);
    }
}

s32 hud_p2_lives_put(u16);
extern u16 g_p2_lives;

void p2_life_add(void) {
    u16 temp_a0;

    temp_a0 = (s16)g_p2_lives;
    if (temp_a0 != 0x14) {
        g_p2_lives = temp_a0 + 1;
        hud_p2_lives_put(temp_a0);
    }
}

s32 p1_stage_clear_reward();
extern u16 g_p1_stage_bomb_used;
extern u16 g_p1_stage_misses;
extern s32 g_p1_maximum_value_digits[];
void p1_next_stage_setup(void) {
    u16 temp_a0;

    if (g_player1[0] < 0) {
        p1_stage_clear_reward();
        g_p1_stage_misses = 0;
        g_p1_stage_bomb_used = 0;
        if (!(PLAYER(((u8 *)g_player1))->flags.b[1] & 0x40) && (g_p1_maximum_value_digits[0] != 0)) {
            temp_a0 = g_p1_maximum_level;
            if (temp_a0 != 8) {
                g_p1_maximum_level = temp_a0 + 4;
                p1_maximum_level_show(temp_a0);
                g_p1_maximum_anim_delay_reset -= 1;
                g_p1_maximum_anim_delay = g_p1_maximum_anim_delay_reset;
            }
        }
    }
}

s32 p2_stage_clear_reward();
extern u16 g_p2_stage_bomb_used;
extern u16 g_p2_stage_misses;
extern s32 g_p2_maximum_value_digits[];
void p2_next_stage_setup(void) {
    u16 temp_a0;

    if (g_player2[0] < 0) {
        p2_stage_clear_reward();
        g_p2_stage_misses = 0;
        g_p2_stage_bomb_used = 0;
        if (!(PLAYER(((u8 *)g_player2))->flags.b[1] & 0x40) && (g_p2_maximum_value_digits[0] != 0)) {
            temp_a0 = g_p2_maximum_level;
            if (temp_a0 != 8) {
                g_p2_maximum_level = temp_a0 + 4;
                p2_maximum_level_show(temp_a0);
                g_p2_maximum_anim_delay_reset -= 1;
                g_p2_maximum_anim_delay = g_p2_maximum_anim_delay_reset;
            }
        }
    }
}

s32 palette_bank_load_for_maximum();

void p1_maximum_level_show() {
    reg_a1 = ((u8 *)p1_maximum_level_texts);
    reg_d0.h[0] = g_p1_maximum_level;
    reg_d0.h[0] *= 2;
    reg_a1 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    palette_bank_load_for_maximum();
}

void p2_maximum_level_show() {
    reg_a1 = ((u8 *)p2_maximum_level_texts);
    reg_d0.h[0] = g_p2_maximum_level;
    reg_d0.h[0] *= 2;
    reg_a1 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    palette_bank_load_for_maximum();
}

void p1_invincible_start(void) {
    reg_d0.b[0] = 0x50;
    if (g_boss_present_b1 & 4) {
        reg_d0.b[0] = 0x78;
    }
    PLAYER(((u8 *)g_player1))->state.b.invincible = reg_d0.b[0];
}

void p2_invincible_start(void)
{
    u32 destinationAddress;

    reg_d0.b[0] = 0x50;
    if (g_boss_present_b1 & 4) {
        reg_d0.b[0] = 0x78;
    }

    destinationAddress = (u32)(&PLAYER(((u8 *)g_player2))->state.b.invincible);
    *(u8 *)destinationAddress = reg_d0.b[0];
    *(u8 *)destinationAddress = 0x50;
}

void p1_laser_release(void) {
    ((u8 *)g_player1)[0] &= 0xFE;
    p1_laser_stop();
}


void p2_laser_release(void) {
    ((u8 *)g_player2)[0] &= 0xFE;
    p2_laser_stop();
}

void bomb_stock_origin_p1() {
    reg_d4.sw = 0x02D8000A;
    reg_d1.h[0] = 0;
    reg_d7.sh[0] = 0x100;
}

void bomb_stock_origin_p2() {
    reg_d1.h[0] = 0x1B00;
    reg_d4.sw = 0x02D8008A;
    reg_d7.h[0] = 0xFE00;
}

extern u32 reg_save_d4;
extern u32 reg_save_d3;
extern u32 reg_save_d2;
extern u32 reg_save_d1;

void p1_bomb_stock_draw(void) {
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d0 = reg_d0.w;
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    (*(s32 **)&reg_save_a6) = (s32 *)reg_a6;
    bomb_stock_origin_p1(reg_d6.w, reg_d2.w, reg_d1.w, reg_d0.w);
    reg_a6 = (u8 *)((s32 *)g_player1);
    bomb_stock_draw();
}


void p2_bomb_stock_draw(void) {
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d0 = reg_d0.w;
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    (*(s32 **)&reg_save_a6) = (s32 *)reg_a6;
    bomb_stock_origin_p2(reg_d6.w, reg_d2.w, reg_d1.w, reg_d0.w);
    reg_a6 = (u8 *)((s32 *)g_player2);
    bomb_stock_draw();
}


void bomb_stock_draw_for_task(void) {
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d0 = reg_d0.w;
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    (*(s32 *)&reg_save_a6) = (s32)reg_a6;
    bomb_stock_origin_p1(reg_d6.w, reg_d2.w, reg_d1.w, reg_d0.w);
    if (*(u8 *)(reg_a5 + 6) != 0) {
        bomb_stock_origin_p2();
    }
    bomb_stock_draw();
}

s32 deferred_text_put();
s32 deferred_text_put_sheet();

void bomb_stock_draw(void) {
    u32 tmp;

    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d3.w = 0;
    reg_d5.h[0] = 2;
    deferred_text_put_sheet();
    reg_d1.h[0] += reg_d7.h[0];
    if ((s16) reg_d7.h[0] < 0) goto next_1;
    reg_d7.h[0] *= 2;
next_1:
    reg_d3.w = 1;
    reg_d6.w = 5;
    reg_d5.w = 0;
    reg_d5.b[0] = *(u8 *) (reg_a6 + 0x24);
    reg_d6.b[0] -= reg_d5.b[0];
    reg_tmp5.h[0] = reg_d5.h[0];
    reg_d5.h[0] = reg_d5.h[1];
    reg_d5.h[1] = reg_tmp5.h[0];
    reg_d5.b[0] = *(u8 *) (reg_a6 + 0x25);
    if (reg_d5.b[0] == 0) goto next_2;
    reg_d4.w = 0x02CC000A;
loop_1:
    deferred_text_put();
    reg_d1.h[0] += reg_d7.h[0];
    reg_d5.w -= 0x10001;
    if (reg_d5.h[0] != 0) goto loop_1;
next_2:
    reg_tmp5.h[0] = reg_d5.h[0];
    reg_d5.h[0] = reg_d5.h[1];
    reg_d5.h[1] = reg_tmp5.h[0];
    reg_tmp5.h[0] = reg_d5.h[0];
    reg_d5.h[0] -= 1;
    if (reg_tmp5.h[0] == 0) goto next_3;
    reg_d4.w = 0x02C0000A;
loop_2:
    deferred_text_put();
    reg_d1.h[0] += reg_d7.h[0];
    tmp = reg_d5.h[0] - 1;
    reg_d5.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
next_3:
    if ((s8) reg_d6.b[0] < 0) goto next_4;
    reg_d4.w = 0x02C6000A;
loop_3:
    deferred_text_put();
    reg_d1.h[0] += reg_d7.h[0];
    tmp = reg_d6.h[0] - 1;
    reg_d6.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_3;
next_4:
    reg_d4.w = 0x02D2000A;
    deferred_text_put();
    reg_d0.w = reg_save_d0;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    reg_a6 = (u8 *)((void *)reg_save_a6);
}

extern Reg32 reg_d1;

void p1_bomb_slot_fill(void) {
    reg_d1.h[0] = 0x100;
    reg_d4.sw = 0x2CC000A;
    bomb_slot_fill();
}


void p2_bomb_slot_fill(void) {
    u16 saved = reg_d6.h[0];
    reg_d1.h[0] = 0x1900;
    reg_d4.sw = 0x02CC000A;
    reg_d6.h[0] = (saved << 16) - saved;
    bomb_slot_fill();
}

void bomb_slot_fill(void) {
    s16 temp_a0;

    temp_a0 = (s16) reg_d6.h[0];
    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d3.w = 1;
    reg_d6.h[0] = temp_a0 << 9;
    reg_d1.h[0] += reg_d6.h[0];
    deferred_text_put(temp_a0);
}

void p1_bomb_stock_draw_empty(void) {
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
    bomb_stock_origin_p1();
    reg_d3.w = 0;
    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d5.h[0] = 2;
    deferred_text_put_sheet();
    reg_d3.w = 1;
    reg_d1.h[0] += 0x100;
    reg_d4.w = 0x02C6000A;
    reg_d7.w = 5;
    do {
        deferred_text_put();
        reg_d1.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d4.w = 0x02D2000A;
    deferred_text_put();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}

void p2_bomb_stock_draw_empty(void) {
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
    bomb_stock_origin_p2();
    reg_d3.w = 0;
    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d5.h[0] = 2;
    deferred_text_put_sheet();
    reg_d3.w = 1;
    reg_d1.h[0] -= 0x200;
    reg_d4.w = 0x02C6000A;
    reg_d7.w = 5;
    do {
        deferred_text_put();
        reg_d1.h[0] -= 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d4.w = 0x02D2000A;
    deferred_text_put();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}

extern s32 reg_save_a0;

void p1_bomb_capacity_draw(void)
{
    reg_save_d0 = reg_d0.w;
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a0 = (s32)reg_a0;

    reg_d1.h[0] = 0x100;
    reg_d4.w = 0;
    *(u8 *)&reg_d4.w = PLAYER(((u8 *)g_player1))->bombs.b.capacity;
    bomb_capacity_draw();
}

void p2_bomb_capacity_draw(void)
{
    reg_save_d0 = reg_d0.w;
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a0 = (s32)reg_a0;

    reg_d1.h[0] = 0xF00;
    reg_d4.w = 0;
    *(u8 *)&reg_d4.w = PLAYER(((u8 *)g_player2))->bombs.b.capacity;
    bomb_capacity_draw();
}

void bomb_capacity_draw(void) {
    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d3.w = 0xB;
    reg_d4.h[0] -= 1;
    reg_d4.w = *(u32 *)(((u8 *)bomb_capacity_glyphs) + (reg_d4.h[0] * 4));
    deferred_text_put();
    reg_d0.w = reg_save_d0;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    reg_a0 = (u8 *)reg_save_a0;
}

extern s8 g_bomb_panel_seen;

void p1_bomb_panel_draw(void) {
    g_bomb_panel_seen = 1;
    if ((g_p1_hyper_items != 0) || (!(PLAYER(((u8 *)g_player1))->flags.b[1] & 0x40) && (g_p1_maximum_value[0] != 0))) {
        p1_bomb_stock_draw();
        p1_bomb_capacity_draw();
        return;
    }
    p1_bomb_stock_draw();
}


void p2_bomb_panel_draw(void) {
    g_bomb_panel_seen = 1;
    if ((g_p2_hyper_items != 0) || (!(PLAYER(((u8 *)g_player2))->flags.b[1] & 0x40) && (g_p2_maximum_value[0] != 0))) {
        p2_bomb_stock_draw();
        p2_bomb_capacity_draw();
        return;
    }
    p2_bomb_stock_draw();
}

extern u8 g_bullets[];

void bullets_hold_timer_tick(void) {
    if (*(u16 *)(g_bullets + MAIN_OR_DEATH_LABEL(0x3484, 0x10684)) != 0) {
        *(u16 *)(g_bullets + MAIN_OR_DEATH_LABEL(0x3484, 0x10684)) -= 1;
        if (*(u16 *)(g_bullets + MAIN_OR_DEATH_LABEL(0x3484, 0x10684)) == 0) {
            *(u16 *)(g_bullets + MAIN_OR_DEATH_LABEL(0x3486, 0x10686)) = 0;
        }
    }
}

extern u16 D_0029CEBA[];

void boss_kill_counter_clamp(void) {
    u16 *counter = (u16 *) &D_0029CEBA[0];

    if (*counter >= 0x14) {
        *counter = 0x14;
    }
}

void player_draw_unused(void) {
}


void ship_afterimage_update(void) {
    u8 *sv_a0;
    u8 *sv_a1;
    u8 *sv_a2;
    u8 *sv_a3;
    u8 *sv_a4;
    u8 *sv_a5;
    u8 *sv_a6;
    u32 sv_d0;
    u32 sv_d1;
    u32 sv_d2;
    u32 sv_d3;
    u32 sv_d4;
    u32 sv_d5;
    u32 sv_d6;
    u32 sv_d7;

    sv_d0 = reg_d0.w;
    sv_d1 = reg_d1.w;
    sv_d2 = reg_d2.w;
    sv_d3 = reg_d3.w;
    sv_d4 = reg_d4.w;
    sv_d5 = reg_d5.w;
    sv_d6 = reg_d6.w;
    sv_d7 = reg_d7.w;
    sv_a0 = reg_a0;
    sv_a1 = reg_a1;
    sv_a2 = reg_a2;
    sv_a3 = reg_a3;
    sv_a4 = reg_a4;
    sv_a5 = reg_a5;
    sv_a6 = reg_a6;
    if (*(u8 *) (reg_a6 + 0x3E) == 0) goto next_1;
    if (*(u8 *) (reg_a6 + 0x56) != 0) goto next_2;
    p1_afterimage_draw();
    reg_d0.w = sv_d0;
    reg_d1.w = sv_d1;
    reg_d2.w = sv_d2;
    reg_d3.w = sv_d3;
    reg_d4.w = sv_d4;
    reg_d5.w = sv_d5;
    reg_d6.w = sv_d6;
    reg_d7.w = sv_d7;
    reg_a0 = sv_a0;
    reg_a1 = sv_a1;
    reg_a2 = sv_a2;
    reg_a3 = sv_a3;
    reg_a4 = sv_a4;
    reg_a5 = sv_a5;
    reg_a6 = sv_a6;
    return;
next_2:
    p2_afterimage_draw();
next_1:
    reg_d0.w = sv_d0;
    reg_d1.w = sv_d1;
    reg_d2.w = sv_d2;
    reg_d3.w = sv_d3;
    reg_d4.w = sv_d4;
    reg_d5.w = sv_d5;
    reg_d6.w = sv_d6;
    reg_d7.w = sv_d7;
    reg_a0 = sv_a0;
    reg_a1 = sv_a1;
    reg_a2 = sv_a2;
    reg_a3 = sv_a3;
    reg_a4 = sv_a4;
    reg_a5 = sv_a5;
    reg_a6 = sv_a6;
}

extern u8 g_p2_afterimage_positions[];
extern u8 g_p2_afterimage_sprites[];


void p2_afterimage_draw(void) {
    reg_a0 = g_p2_afterimage_positions;
    reg_a1 = g_p2_afterimage_sprites;
    ship_afterimage_draw();
}

extern s32 g_p1_afterimage_sprites[];
extern s32 g_p1_afterimage_positions[];


void p1_afterimage_draw(void) {
    reg_a0 = (u8 *)((s32)&g_p1_afterimage_positions[0]);
    reg_a1 = (u8 *)((s32)&g_p1_afterimage_sprites[0]);
    ship_afterimage_draw();
}

void sprite_draw_with_laser_trail_keep(void);

void ship_afterimage_draw(void) {
    u32 tmp;

    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = 0x1F;
    reg_a2 = reg_a0;
    reg_a3 = reg_a1;
    reg_d6.h[1] = ENTITY(reg_a6)->y.h;
    reg_d6.h[0] = ENTITY(reg_a6)->x.h;
    reg_d6.w &= 0xFF80FF80;
    reg_a1 += 0x40;
    reg_a0 += 0x40;
    reg_d7.w = 5;
    goto loop_2;
loop_1:
    *(u16 *)(reg_a1 - 4) = *(u16 *)(reg_a1 - 8);
    *(u16 *)(reg_a1 - 2) = *(u16 *)(reg_a1 - 6);
    reg_a1 -= 4;
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
    *(u16 *)(reg_a1 - 4) = *(u16 *)(reg_a1 - 8);
    *(u16 *)(reg_a1 - 2) = *(u16 *)(reg_a1 - 6);
    reg_a1 -= 4;
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
loop_2:
    *(u16 *)(reg_a1 - 4) = *(u16 *)(reg_a1 - 8);
    *(u16 *)(reg_a1 - 2) = *(u16 *)(reg_a1 - 6);
    reg_a1 -= 4;
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
    if (reg_d7.h[0] == 0) {
        *(u16 *)(reg_a3 + 0) = ENTITY(reg_a6)->draw.h;
        *(u16 *)(reg_a3 + 2) = ENTITY(reg_a6)->sprite.h;
        *(u16 *)(reg_a2 + 0) = ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a2 + 2) = ENTITY(reg_a6)->x.h;
        return;
    }
    if (g_frame_mod2 == 0) {
        goto next_1;
    }
    reg_d1.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d5.w = reg_d1.w;
    reg_d5.w &= 0xFF80FF80;
    if (reg_d6.w == reg_d5.w) {
        goto next_1;
    }
    reg_d1.w += 0xFA00FC00;
    reg_d2.h[1] = *(u16 *)(reg_a1 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
    sprite_draw_with_laser_trail_keep();
next_1:
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}


void p1_afterimage_reset(void) {
    u8 *temp_a1;
    u8 *temp_a2;
    u8 *temp_a3;

    temp_a3 = reg_a0;
    temp_a2 = reg_a1;
    temp_a1 = reg_a2;
    reg_save_d0 = reg_d0.w;
    reg_save_a0 = (s32)temp_a3;
    reg_save_a1 = temp_a2;
    reg_save_a2 = temp_a1;
    reg_a0 = ((u8 *)g_p1_afterimage_positions);
    reg_a1 = ((u8 *)g_p1_afterimage_sprites);
    reg_a2 = ((u8 *)g_player1);
    afterimage_fill();
}

void p2_afterimage_reset(void) {
    u8 *temp_a1;
    u8 *temp_a2;
    u8 *temp_a3;

    temp_a3 = reg_a0;
    temp_a2 = reg_a1;
    temp_a1 = reg_a2;
    reg_save_d0 = reg_d0.w;
    reg_save_a0 = (s32)temp_a3;
    reg_save_a1 = temp_a2;
    reg_save_a2 = temp_a1;
    reg_a0 = g_p2_afterimage_positions;
    reg_a1 = g_p2_afterimage_sprites;
    reg_a2 = ((u8 *)g_player2);
    afterimage_fill();
}


void afterimage_fill(void) {
    reg_d0.w = 0xF;
    do {
        *(*(u16 **)&reg_a0) = *(u16 *)(reg_a2 + 2);
        (*(u16 **)&reg_a0) += 1;
        *(*(u16 **)&reg_a0) = *(u16 *)(reg_a2 + 4);
        (*(u16 **)&reg_a0) += 1;
        *(*(u16 **)&reg_a1) = *(u16 *)(reg_a2 + 0xA);
        (*(u16 **)&reg_a1) += 1;
        *(*(u16 **)&reg_a1) = *(u16 *)(reg_a2 + 0xC);
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.w = reg_save_d0;
    (*(u16 **)&reg_a0) = (*(u16 **)&reg_save_a0);
    (*(u16 **)&reg_a1) = ((u16 *)reg_save_a1);
    reg_a2 = ((void *)reg_save_a2);
}

void player_zoom_in_step(void) {
    u16 *speed_field = (u16 *)(reg_a4 + 0x60);
    u16 speed = *speed_field;

    if (speed != 0x80) {
        *speed_field = speed + 4;
    }
}

void sfx_p1_laser_a_stop();
void sfx_p1_laser_b_stop();
void sfx_p2_laser_a_stop();
void sfx_p2_laser_b_stop();

void (*p1_laser_clear_table[2])() = {
    sfx_p1_laser_a_stop,
    sfx_p1_laser_b_stop,
};

void (*D_0028C5E0[2])() = {
    sfx_p2_laser_a_stop,
    sfx_p2_laser_b_stop,
};

u16 D_0028C5E8[4] = {
    0x0000, 0x0001, 0x0007, 0x0002,
};

u16 D_0028C5F0[4] = {
    0x0000, 0x0001, 0x0008, 0x0002,
};
