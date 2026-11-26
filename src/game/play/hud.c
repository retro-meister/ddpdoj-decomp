#include "common.h"
#include "score_tables.h"

extern u16 hud_digit_offsets[];
extern u32 *hud_hit_digit_sets[];
extern u32 hud_hit_digits_a[];
extern u32 hud_hit_digits_b[];
extern u32 hud_hit_digits_c[];
extern u32 hud_hit_digits_d[];
extern u32 hud_hit_label_frames[];
extern u32 *hud_boss_hit_digit_sets[];
extern u32 hud_boss_hit_digits_a[];
extern u32 hud_boss_hit_digits_b[];
extern u32 hud_boss_hit_digits_c[];
extern u32 hud_boss_hit_label_frames[];
extern u32 hud_boss_hit_digits_d[];
extern u32 hud_boss_hit_digits_steady[];
extern u16 hud_boss_hit_flicker[];
extern s16 g_player1[];
#include "player.h"
extern s16 g_player2[];

void hud_update_playing(void);
void hud_p1_panel(void);
void hud_p2_panel(void);
void hud_boss_bar_enter(void);
void hud_boss_hits_update(void);
void hud_boss_bar_leave(void);
void hud_intro(void);
void hud_p1_gauge_plate_draw(void);
void hud_p2_gauge_plate_draw(void);
void hud_lives_draw_boss_entering(void);
void hud_lives_draw_boss_leaving(void);
void hud_boss_hit_bonus(void);
void boss_hits_take_on_button(void);
void hud_hits_draw(void);
void hud_hits_label_draw(void);
void hud_boss_hits_draw(void);
void hud_boss_hit_bonus_draw(void);
void hud_combo_gauge_draw(void);
void hud_p1_hyper_update(void);
void p1_hyper_end(void);
void hud_p2_hyper_update(void);
void p2_hyper_end(void);
void hud_p1_hyper_gauge_draw(void);
void hud_p1_hyper_gauge_draw_at(void);
void hud_p2_hyper_gauge_draw(void);
void hud_p2_hyper_gauge_draw_at(void);
void hyper_text_animate(void);
void maximum_text_animate(void);
void hud_text_sprite_draw(void);
void hud_multiplier_text_put(void);
void hud_max_hits_text_put(void);

void hud_setup_nothing(void) {
}


void hud_setup(void) {
    hud_setup_nothing();
}

void sprite_draw_with_score(void);

void sprite_draw_with_score_entry() {
    sprite_draw_with_score();
}

void sprite_draw_with_score_entry_2(void) {
    sprite_draw_with_score();
}

void sprite_draw_with_score_keep(void);

void sprite_draw_with_score_keep_entry(void) {
    sprite_draw_with_score_keep();
}

void hud_p1_multiplier_frame_restore(void) {
    extern void deferred_text_put(void);
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x200;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x54F000A;
    deferred_text_put();
}

void hud_p2_multiplier_frame_restore(void) {
    extern void deferred_text_put(void);
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1400;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x54F000A;
    deferred_text_put();
}

void hud_p1_item_count_frame_restore(void) {
    extern void deferred_text_put(void);
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x200;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x414000A;
    deferred_text_put();
}

void hud_p2_item_count_frame_restore(void) {
    void deferred_text_put(void);
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x1400;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x414000A;
    deferred_text_put();
}

extern u16 g_p1_hyper_items;
extern u16 g_p1_hyper_active;

void hud_p1_ship_and_hyper_count_draw(void) {
    u32 save_d1;

    save_d1 = reg_d1.w;
    if ((s16)reg_d0.h[0] < 0) goto next_0;
    reg_d5.w = reg_d1.w;
    reg_d1.h[0] += 0xFF00;
    reg_d1.h[1] += 0xFE00;
    reg_d2.h[0] = PLAYER(((u8 *)g_player1))->ship_type.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)lives_sprites_p1;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d4.h[0] = 0;
loop_0:
    sprite_draw_with_score_keep_entry();
    reg_d1.h[0] += 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
    reg_d1.w = reg_d5.w;
next_0:
    if (g_p1_hyper_active != 0) goto next_1;
    reg_d1.h[0] += 0xFF00;
    reg_d1.h[1] += 0x100;
    reg_d3.h[0] = 0x430;
    reg_d4.h[0] = 9;
    reg_d2.h[0] = g_p1_hyper_items;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)hyper_item_count_sprites;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    sprite_draw_with_score_entry();
next_1:
    reg_d1.w = save_d1;
}

extern u16 g_p2_hyper_items;
extern u16 g_p2_hyper_active;

void hud_p2_ship_and_hyper_count_draw(void) {
    if ((s16)reg_d0.h[0] < 0) goto next_0;
    reg_d5.w = reg_d1.w;
    reg_d1.h[0] += 0xFF00;
    reg_d1.h[1] += 0xFE00;
    reg_d2.h[0] = PLAYER(((u8 *)g_player2))->ship_type.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)lives_sprites_p2;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d4.h[0] = 1;
loop_0:
    sprite_draw_with_score_keep_entry();
    reg_d1.h[0] -= 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
    reg_d1.w = reg_d5.w;
next_0:
    if (g_p2_hyper_active != 0) goto next_1;
    reg_d1.h[0] += 0xF500;
    reg_d1.h[1] += 0x100;
    reg_d3.h[0] = 0x430;
    reg_d4.h[0] = 9;
    reg_d2.h[0] = g_p2_hyper_items;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)hyper_item_count_sprites;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    sprite_draw_with_score_entry();
next_1:
    return;
}


void hud_p1_lives_row_draw(arg0)
    u16 arg0;
{
    s32 deferred_text_put();
    u16 var_a0;
    var_a0 = arg0;
    if ((s16) reg_d7.h[0] >= 0) {
        reg_d2.h[0] = 1;
        reg_a0 = (u8 *)(lives_text_p1);
        reg_d4.h[0] = PLAYER(((u8 *)g_player1))->ship_type.h;
        reg_d4.h[0] += reg_d4.h[0];
        reg_d3.h[0] = 0;
        reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d5.h[0] = reg_d1.h[0];
        do {
            deferred_text_put();
            var_a0 = (u32)reg_d1.h[0] + 0x100;
            reg_d1.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d1.h[0] = reg_d5.h[0];
    }
}


void hud_p2_lives_row_draw(void) {
    extern void deferred_text_put(void);
    if ((s16)reg_d7.h[0] >= 0) {
        reg_d2.h[0] = 1;
        reg_a0 = (u8 *)lives_text_p2;
        reg_d4.h[0] = PLAYER(((u8 *)g_player2))->ship_type.h;
        reg_d4.h[0] += reg_d4.h[0];
        reg_d3.h[0] = 0;
        reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d5.h[0] = reg_d1.h[0];
        do {
            deferred_text_put();
            reg_d1.h[0] -= 0x100;
        } while ((s16)--reg_d7.h[0] >= 0);
        reg_d1.h[0] = reg_d5.h[0];
    }
}

extern u16 g_p1_lives;

void hud_p1_hyper_gauge_draw_boss(void) {
    if ((*(s16 *)&g_p1_lives) >= 0) {
        reg_d6.w = 0x12;
        reg_d6.h[0] -= 0x32;
        reg_d6.h[0] <<= 7;
        hud_p1_hyper_gauge_draw_at();
    }
}

extern u16 g_p2_lives;

void hud_p2_hyper_gauge_draw_boss(void) {
    if ((*(s16 *)&g_p2_lives) >= 0) {
        reg_d6.w = 0x12;
        reg_d6.h[0] -= 0x32;
        reg_d6.h[0] <<= 7;
        hud_p2_hyper_gauge_draw_at();
    }
}

extern u16 g_boss_hits;
extern u16 g_boss_hit_carry;

void boss_hits_take_carry(void) {
    if (g_boss_hit_carry != 0) {
        g_boss_hit_carry -= 1;
        g_boss_hits += 1;
        if (g_boss_hit_carry != 0) {
            g_boss_hit_carry -= 1;
            g_boss_hits += 1;
            if (g_boss_hit_carry != 0) {
                g_boss_hit_carry -= 1;
                g_boss_hits += 1;
                if (g_boss_hit_carry != 0) {
                    g_boss_hits += 1;
                    g_boss_hit_carry -= 1;
                }
            }
        }
    }
}

extern u16 g_score_panel_intro;

void hud_update(void) {
    maximum_text_animate();
    hyper_text_animate();
    if (g_score_panel_intro != 0) {
        hud_intro();
        return;
    }
    hud_update_playing();
}

extern u8 g_boss_present;
extern u8 D_0028E961;

void hud_update_playing(void) {
    hud_p1_hyper_update();
    hud_p2_hyper_update();
    boss_hits_take_carry();
    if (g_boss_present & 1) {
        hud_boss_bar_enter();
        return;
    }
    if (D_0028E961 & 8) {
        hud_boss_bar_enter();
        return;
    }
    hud_p1_panel();
}

extern u16 g_p1_maximum_level;
extern u16 g_game_frame;
extern u16 g_p1_hyper_combo_decay;
extern u8 D_0028E5DD;
extern u16 g_p1_max_hits;
extern s8 g_boss_hp_bar_flags;
extern u16 g_p1_hits_shown;
extern s32 g_p1_chain_points;
extern u16 g_p1_hit10_anim_count;
extern u16 g_p1_hit10_color_timer;
extern s16 g_p1_hit10_display_timer;
extern u16 g_p1_combo_timer;
extern s32 g_p1_chain_first_score;
extern s32 g_maximum_text_anim_sprite;
extern s32 g_hyper_text_anim_sprite;
extern u8 g_p1_score_panel_flags;
extern u16 g_p1_maximum_count_digits[];
extern u8 D_0029F261[];
void hud_p1_panel(void) {
    if ((*(s16 *)&g_p1_lives) < 0) {
        hud_p2_panel();
        return;
    }
    hud_p1_hyper_gauge_draw();
    if (!(g_boss_present & 1) || (g_boss_hp_bar_flags < 0)) {
        if (g_p1_hyper_active != 0) {
            if (!(g_p1_score_panel_flags & 1)) {
                g_p1_score_panel_flags |= 1;
                hud_p1_multiplier_frame_restore();
                hud_p1_item_count_frame_restore();
            }
            reg_d1.w = 0x64C00400;
            reg_d2.w = (*(u32 *)&g_hyper_text_anim_sprite);
            hud_text_sprite_draw();
        } else {
            g_p1_score_panel_flags &= 0xFE;
            if (g_game_frame & 0x40) {
                if (!(D_0029F261[0] & 0x40) && (reg_d6.h[0] = g_p1_maximum_count_digits[0], (g_p1_maximum_count_digits[0] != 0))) {
                    reg_d0.w = 0x3F;
                    reg_d0.h[0] &= g_game_frame;
                    if ((s32) reg_d0.h[0] < 0x14) {
                        hud_p1_multiplier_frame_restore();
                        reg_d1.w = 0x64C00400;
                        reg_d2.w = (*(u32 *)&g_maximum_text_anim_sprite);
                        hud_text_sprite_draw();
                    } else {
                        reg_d0.h[0] = 0xD4;
                        reg_d1.h[0] = 0x200;
                        reg_d5.h[0] = g_p1_maximum_level;
                        hud_multiplier_text_put();
                    }
                } else {
                    goto block_15;
                }
            } else {
block_15:
                reg_d0.h[0] = 0xD4;
                reg_d1.h[0] = 0x200;
                reg_d6.h[0] = g_p1_max_hits;
                hud_max_hits_text_put();
            }
        }
    }
    if ((*(u16 *)&g_p1_hit10_display_timer) != 0) {
        (*(u16 *)&g_p1_hit10_display_timer) -= 1;
        reg_d1.h[0] = 0x40;
        reg_d6.w = 0;
        reg_d0.h[0] = g_p1_hits_shown;
        reg_d6.h[0] = g_p1_hit10_anim_count;
        g_p1_hit10_anim_count += 1;
        reg_d3.h[0] = (*(u16 *)&g_p1_hit10_display_timer);
        if ((s32) reg_d3.h[0] < 0x2A) {
            reg_d3.h[0] -= 0x2A;
            reg_d3.h[0] <<= 7;
            reg_d1.h[0] += reg_d3.h[0];
        }
        reg_d2.h[0] = g_p1_hit10_color_timer;
        if (g_p1_hit10_color_timer != 0) {
            g_p1_hit10_color_timer -= 1;
        }
        reg_d4.h[0] = 7;
        hud_hits_draw();
    }
    reg_d6.h[0] = g_p1_combo_timer;
    if (g_p1_combo_timer != 0) {
        if (g_p1_hyper_active != 0) {
            D_0028E5DD -= 1;
            if ((s8) D_0028E5DD < 0) {
                D_0028E5DD = (*(u8 *)&g_p1_hyper_combo_decay);
                goto block_26;
            }
            goto block_29;
        }
block_26:
        g_p1_combo_timer -= 1;
        if (g_p1_combo_timer == 0) {
            reg_d0.w = 0;
            g_p1_chain_first_score = reg_d0.w;
            g_p1_chain_points = reg_d0.w;
        } else {
block_29:
            reg_d1.w = 0x5BC00000;
            reg_d4.h[0] = 9;
            hud_combo_gauge_draw();
        }
    }
    hud_p2_panel();
}

extern u16 g_p2_maximum_level;
extern u16 g_p2_hyper_combo_decay;
extern u8 D_0028E5D9;
extern u16 g_p2_max_hits;
extern u16 g_p2_hits_shown;
extern s32 g_p2_chain_points;
extern u16 g_p2_hit10_anim_count;
extern u16 g_p2_hit10_color_timer;
extern s16 g_p2_hit10_display_timer;
extern u16 g_p2_combo_timer;
extern s32 g_p2_chain_first_score;
extern u8 g_p2_score_panel_flags;
extern u16 g_p2_maximum_count_digits[];
extern u8 D_0029F1F1[];
void hud_p2_panel(void) {
    if ((*(s16 *)&g_p2_lives) < 0) {
        hud_boss_hits_update();
        return;
    }
    hud_p2_hyper_gauge_draw();
    if (!(g_boss_present & 1) || (g_boss_hp_bar_flags < 0)) {
        if (g_p2_hyper_active != 0) {
            if (!(g_p2_score_panel_flags & 1)) {
                g_p2_score_panel_flags |= 1;
                hud_p2_multiplier_frame_restore();
                hud_p2_item_count_frame_restore();
            }
            reg_d1.w = 0x64C02800;
            reg_d2.w = (*(u32 *)&g_hyper_text_anim_sprite);
            hud_text_sprite_draw();
        } else {
            g_p2_score_panel_flags &= 0xFE;
            if (g_game_frame & 0x40) {
                if (!(D_0029F1F1[0] & 0x40) && (reg_d6.h[0] = g_p2_maximum_count_digits[0], (g_p2_maximum_count_digits[0] != 0))) {
                    reg_d0.w = 0x3F;
                    reg_d0.h[0] &= g_game_frame;
                    if ((s32) reg_d0.h[0] < 0x2C) {
                        hud_p2_multiplier_frame_restore();
                        reg_d1.w = 0x64C02800;
                        reg_d2.w = (*(u32 *)&g_maximum_text_anim_sprite);
                        hud_text_sprite_draw();
                    } else {
                        reg_d0.h[0] = 0xD4;
                        reg_d1.h[0] = 0x1400;
                        reg_d5.h[0] = g_p2_maximum_level;
                        hud_multiplier_text_put();
                    }
                } else {
                    goto block_15;
                }
            } else {
block_15:
                reg_d0.h[0] = 0xD4;
                reg_d1.h[0] = 0x1400;
                reg_d6.h[0] = g_p2_max_hits;
                hud_max_hits_text_put();
            }
        }
    }
    if ((*(u16 *)&g_p2_hit10_display_timer) != 0) {
        (*(u16 *)&g_p2_hit10_display_timer) -= 1;
        reg_d1.h[0] = 0x1FC0;
        reg_d6.w = 0;
        reg_d0.h[0] = g_p2_hits_shown;
        reg_d6.h[0] = g_p2_hit10_anim_count;
        g_p2_hit10_anim_count += 1;
        reg_d3.h[0] = (*(u16 *)&g_p2_hit10_display_timer);
        if ((s32) reg_d3.h[0] < 0x2A) {
            reg_d3.h[0] -= 0x2A;
            reg_d3.h[0] <<= 7;
            reg_d1.h[0] -= reg_d3.h[0];
        }
        reg_d2.h[0] = g_p2_hit10_color_timer;
        if (g_p2_hit10_color_timer != 0) {
            g_p2_hit10_color_timer -= 1;
        }
        reg_d4.h[0] = 8;
        hud_hits_draw();
    }
    reg_d6.h[0] = g_p2_combo_timer;
    if (g_p2_combo_timer != 0) {
        if (g_p2_hyper_active != 0) {
            D_0028E5D9 -= 1;
            if ((s8) D_0028E5D9 < 0) {
                D_0028E5D9 = (*(u8 *)&g_p2_hyper_combo_decay);
                goto block_26;
            }
            goto block_29;
        }
block_26:
        g_p2_combo_timer -= 1;
        if (g_p2_combo_timer == 0) {
            reg_d0.w = 0;
            g_p2_chain_first_score = reg_d0.w;
            g_p2_chain_points = reg_d0.w;
        } else {
block_29:
            reg_d1.w = 0x5BC03400;
            reg_d4.h[0] = 0x4009;
            hud_combo_gauge_draw();
        }
    }
    hud_boss_hits_update();
}

s32 voice_hyper();
s32 sprite_palette_load();
s32 hud_p1_caption_clear();
s32 hud_p2_caption_clear();
extern u8 D_00261C30[];
extern u8 hud_boss_bar_enter_table[];
extern u8 D_0028E61D;
extern u8 *g_boss_hp;
extern s32 g_boss_hp_unit;
extern u16 g_lives_display_move_x;
extern u16 g_lives_display_move_y;
extern u16 g_boss_hp_bar_move_count;
extern u8 g_boss_bar_flags;
extern u8 g_boss_present_b1;
extern u16 g_loop;
extern u16 g_stage;
extern u16 g_bomb_entities[];

void hud_boss_bar_enter(void) {
    s32 deferred_text_put();
    s32 flag;
    s32 bits;

    if (g_boss_present_b1 & 8) {
        hud_boss_bar_leave();
        return;
    }
    flag = g_boss_bar_flags;
    if ((s8) flag < 0) goto next_160;
    bits = flag & 0xFF;
    if (bits & 0x10) goto next_120;
    if (bits & 8) goto next_80;
    if (bits & 1) goto next_40;
    g_boss_bar_flags = flag | 1;
    g_boss_hp_bar_move_count = 0x32;
    g_lives_display_move_x = 8;
    g_lives_display_move_y = 8;
    if (!(g_boss_bar_flags & 2)) {
        g_boss_bar_flags |= 2;
        goto next_20;
    }
    if (!(g_boss_bar_flags & 4)) {
        g_boss_bar_flags |= 4;
        goto next_20;
    }
    hud_p1_caption_clear();
    hud_p2_caption_clear();
    reg_a0 = (u8 *)D_00261C30;
    reg_d0.h[0] = 7;
    sprite_palette_load();
    reg_a0 = (u8 *)hud_boss_bar_enter_table;
    reg_d0.h[0] = 8;
    sprite_palette_load();
    goto next_40;
next_20:
    g_boss_bar_flags &= 0xFE;
next_40:
    reg_d1.h[0] = 0x5BC0;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_d3.h[0] = 0x840;
    reg_d4.h[0] = 9;
    reg_d6.h[0] = g_boss_hp_bar_move_count;
    reg_d6.h[0] -= 0x32;
    reg_d6.h[0] <<= 7;
    hud_p1_gauge_plate_draw();
    hud_p2_gauge_plate_draw();
    hud_lives_draw_boss_entering();
    g_boss_hp_bar_move_count -= 1;
    if (g_boss_hp_bar_move_count != 0x11) {
        hud_boss_hits_update();
        return;
    }
    g_boss_bar_flags |= 8;
    g_boss_hp_bar_move_count = 0x38;
    hud_boss_hits_update();
    return;
next_80:
    reg_d1.h[0] = 0x67C0;
    reg_d2.w = 0xCA2;
    reg_d3.h[0] = 0x2E0;
    reg_d4.h[0] = 9;
    reg_tmp.h[0] = g_boss_hp_bar_move_count;
    g_boss_hp_bar_move_count -= 1;
    if (reg_tmp.h[0] == 0) goto next_100;
    reg_d6.h[0] = g_boss_hp_bar_move_count;
    reg_d6.h[0] <<= 6;
    reg_d1.h[0] += reg_d6.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0;
    sprite_draw_with_score_entry();
    reg_d7.h[0] = 0xE00;
    reg_d7.h[0] -= reg_d6.h[0];
    hud_p1_hyper_gauge_draw_boss();
    hud_p2_hyper_gauge_draw_boss();
    hud_lives_draw_boss_entering();
    hud_boss_hits_update();
    return;
next_100:
    g_boss_bar_flags = flag | 0x10;
    hud_lives_draw_boss_entering();
    g_boss_hp_bar_move_count = 0xFFE2;
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0;
    reg_d2.w = 1;
    reg_d3.w = 0x1B;
    reg_d4.w = 0x03B6000A;
    deferred_text_put();
    reg_d7.h[0] = 0xE00;
    hud_p1_hyper_gauge_draw_boss();
    hud_p2_hyper_gauge_draw_boss();
    hud_boss_hits_update();
    return;
next_120:
    reg_d7.h[0] = 0xE00;
    hud_p1_hyper_gauge_draw_boss();
    hud_p2_hyper_gauge_draw_boss();
    g_boss_hp_bar_move_count += 1;
    if ((s16) g_boss_hp_bar_move_count < 0) {
        hud_boss_hits_update();
        return;
    }
    reg_d1.w = 0x67C00000;
    reg_d2.w = 0xCA1;
    reg_d3.h[0] = 0x200;
    reg_d4.h[0] = 9;
    reg_d6.h[0] = g_boss_hp_bar_move_count;
loop_140:
    reg_d3.h[0] += 2;
    if ((s16) --reg_d6.h[0] >= 0) goto loop_140;
    if (g_boss_hp_bar_move_count != 0x6F) goto next_280;
    g_boss_bar_flags |= 0x80;
    goto next_180;
next_160:
    reg_d7.h[0] = 0xE00;
    hud_p1_hyper_gauge_draw_boss();
    hud_p2_hyper_gauge_draw_boss();
next_180:
    reg_a0 = (u8 *)g_boss_hp;
    reg_d7.h[1] = *(u16 *) (reg_a0 + 0);
    reg_d7.h[0] = *(u16 *) (reg_a0 + 2);
    if ((s32) reg_d7.w < 0) {
        hud_boss_hits_update();
        return;
    }
    reg_d4.h[0] = 9;
    if ((u32) reg_d7.w > 0x6FB8U) goto next_240;
    if (g_loop == 0) goto next_200;
    if (g_stage == 4) goto next_240;
next_200:
    reg_d4.h[0] = 0x19;
    reg_d2.h[0] = g_bomb_entities[0];
    if ((s16) reg_d2.h[0] >= 0) goto next_220;
    if (reg_d2.w & 1) goto next_240;
next_220:
    if (D_0028E61D & 1) goto next_240;
    D_0028E61D |= 1;
    voice_hyper();
next_240:
    reg_d1.w = 0x67C001C0;
    reg_d2.w = 0xCA1;
    reg_d3.h[0] = 0x200;
    reg_d0.w = (*(u32 *)&g_boss_hp_unit);
loop_260:
    reg_tmp7.w = reg_d7.w;
    reg_d7.w -= reg_d0.w;
    if ((u32) reg_d0.w <= (u32) reg_tmp7.w) {
        reg_d3.h[0] += 1;
        goto loop_260;
    }
next_280:
    if (reg_d3.h[0] == 0x200) {
        hud_boss_hits_update();
        return;
    }
    sprite_draw_with_score_entry();
    hud_boss_hits_update();
}

s32 boss_hits_display_reset();
extern s16 g_boss_hit_palette;
extern u16 g_boss_hit_anim_count;
extern u16 g_boss_hit_decay_timer;
extern u16 g_two_player_state;
extern u16 g_two_player_game;

void hud_boss_hits_update(void) {
    u32 flags;
    u32 hit;

    flags = g_boss_present_b1;
    if (!(flags & 4)) goto next_7;
    hit = g_boss_hits;
    if ((s16)hit >= 0) goto next_0;
    g_boss_hit_anim_count -= 1;
    goto next_1;
next_0:
    g_boss_hit_anim_count += 1;
next_1:
    if (flags & 0x40) goto next_4;
    if ((*(s16 *)&g_two_player_state) < 0) goto next_6;
    if (g_boss_hit_decay_timer == 0) goto next_7;
    g_boss_hit_decay_timer -= 1;
    if (g_boss_hit_decay_timer != 0) goto next_5;
    g_boss_hit_palette = 8;
    g_boss_hit_decay_timer = 0xA;
    if (g_two_player_game != 0) goto next_3;
    g_boss_hit_decay_timer = 0x12;
next_3:
    g_boss_hits -= 1;
    if ((s16)g_boss_hits < 0) goto next_6;
    if (g_boss_hits != 0) goto next_5;
    boss_hits_display_reset();
    goto next_7;
next_4:
    switch (hit & 0xFFFF) {
    case 0:
        goto next_7;
    }
    if ((s16)g_boss_hit_anim_count < 0) goto next_7;
    g_boss_hit_palette = 7;
    g_boss_hit_decay_timer = 0;
next_5:
    hud_boss_hits_draw();
    goto next_7;
next_6:
    g_boss_hits = 0;
    g_boss_hit_decay_timer = 0;
next_7:
    if (g_boss_present_b1 & 8) {
        hud_boss_hit_bonus();
    }
}

s32 deferred_text_clear();
s32 hud_p1_caption_put();
s32 hud_p2_caption_put();
extern s16 g_p2_chain_points_display_timer;
extern s16 g_p1_hit10_display_timer;
extern s16 g_p1_chain_points_display_timer;

void hud_boss_bar_leave(void) {
    u8 flags;

    flags = (*(u8 *)&g_boss_hp_bar_flags);
    if ((s8)flags >= 0) goto next_0;
    hud_p1_panel();
    return;
next_0:
    if (flags & 8) goto next_5;
    if (flags & 1) goto next_2;
    (*(u8 *)&g_boss_hp_bar_flags) |= 1;
    g_boss_hp_bar_move_count = 0x38;
    g_lives_display_move_x = 0x10;
    g_lives_display_move_y = 8;
    if (!((*(u8 *)&g_boss_hp_bar_flags) & 2)) {
        (*(u8 *)&g_boss_hp_bar_flags) |= 2;
        goto next_1;
    }
    if (!((*(u8 *)&g_boss_hp_bar_flags) & 4)) {
        (*(u8 *)&g_boss_hp_bar_flags) |= 4;
        goto next_1;
    }
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0;
    reg_d2.w = 6;
    reg_d3.w = 0x1B;
    deferred_text_clear();
    goto next_2;
next_1:
    (*(u8 *)&g_boss_hp_bar_flags) &= 0xFE;
next_2:
    hud_lives_draw_boss_leaving();
    reg_d1.h[0] = 0x75C0;
    reg_d2.w = 0xCA2;
    reg_d3.h[0] = 0x2E0;
    reg_d4.h[0] = 9;
    reg_d6.h[0] = g_boss_hp_bar_move_count;
    reg_d6.h[0] <<= 6;
    reg_d1.h[0] -= reg_d6.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0;
    sprite_draw_with_score_entry();
    reg_d7.h[0] = reg_d6.h[0];
    hud_p1_hyper_gauge_draw_boss();
    hud_p2_hyper_gauge_draw_boss();
    g_boss_hp_bar_move_count -= 1;
    if (g_boss_hp_bar_move_count != 0) {
        hud_boss_hits_update();
        return;
    }
    (*(u8 *)&g_boss_hp_bar_flags) |= 8;
    g_boss_hp_bar_move_count = 0x41;
    hud_boss_hits_update();
    return;
next_5:
    if (g_boss_hits == 0) goto next_7;
    reg_d6.h[0] = g_boss_hp_bar_move_count;
    if (g_boss_hp_bar_move_count == 0) goto next_6;
    g_boss_hp_bar_move_count -= 1;
    reg_d6.h[0] = g_boss_hp_bar_move_count;
    reg_d6.h[0] <<= 6;
    reg_d6.h[0] *= 0xFFFF;
next_6:
    hud_p1_gauge_plate_draw();
    hud_p2_gauge_plate_draw();
    hud_lives_draw_boss_leaving();
    hud_boss_hits_update();
    return;
next_7:
    (*(u8 *)&g_boss_hp_bar_flags) |= 0x80;
    g_p1_chain_points_display_timer = 0;
    g_p2_chain_points_display_timer = 0;
    g_p1_hit10_display_timer = 0;
    hud_lives_draw_boss_leaving();
    if ((*(s16 *)&g_p1_lives) < 0) goto next_8;
    hud_p1_caption_put();
    hud_p1_multiplier_frame_restore();
next_8:
    if ((*(s16 *)&g_p2_lives) < 0) {
        hud_boss_hits_update();
        return;
    }
    hud_p2_caption_put();
    hud_p2_multiplier_frame_restore();
    hud_boss_hits_update();
}

s32 hud_p1_hyper_count_put();
s32 hud_p2_hyper_count_put();
s32 hud_p1_lives_put();
s32 hud_p2_lives_put();
extern u16 g_p2_lives;
extern u16 g_p1_lives;

void hud_intro(void) {
    if (!(g_boss_present & 1)) goto next_2;
    if ((s16)g_p1_lives < 0) goto next_0;
    hud_p1_hyper_count_put();
    hud_p1_lives_put();
next_0:
    if ((s16)g_p2_lives < 0) goto next_1;
    hud_p2_hyper_count_put();
    hud_p2_lives_put();
next_1:
    g_score_panel_intro = 0;
    hud_update_playing();
    return;
next_2:
    if (g_boss_hp_bar_move_count == 0) goto next_7;
    g_boss_hp_bar_move_count -= 1;
    reg_d6.h[0] = g_boss_hp_bar_move_count;
    reg_d6.h[0] <<= 6;
    reg_d6.h[0] *= 0xFFFF;
    reg_d0.h[0] = g_p1_lives;
    if ((s16)g_p1_lives < 0) goto next_4;
    reg_tmp.w = reg_d0.h[0];
    reg_tmp.w -= 1;
    reg_d0.h[0] = reg_tmp.h[0];
    if (reg_tmp.h[1] != 0) goto next_3;
    if (reg_d0.h[0] <= 5) goto next_3;
    reg_d0.w = 5;
next_3:
    reg_d1.w = 0x5DC00500;
    reg_d1.h[0] += reg_d6.h[0];
    reg_d3.h[0] = 0x208;
    hud_p1_ship_and_hyper_count_draw();
    hud_p1_gauge_plate_draw();
next_4:
    reg_d0.h[0] = g_p2_lives;
    if ((s16)g_p2_lives < 0) goto next_6;
    reg_tmp.w = reg_d0.h[0];
    reg_tmp.w -= 1;
    reg_d0.h[0] = reg_tmp.h[0];
    if (reg_tmp.h[1] != 0) goto next_5;
    if (reg_d0.h[0] <= 5) goto next_5;
    reg_d0.w = 5;
next_5:
    reg_d1.w = 0x5DC03300;
    reg_d1.h[0] -= reg_d6.h[0];
    reg_d3.h[0] = 0x208;
    hud_p2_ship_and_hyper_count_draw();
    hud_p2_gauge_plate_draw();
next_6:
    return;
next_7:
    reg_d7.h[0] = g_p1_lives;
    if ((s16)g_p1_lives < 0) goto next_10;
    reg_tmp7.w = reg_d7.h[0];
    reg_tmp7.w -= 1;
    reg_d7.h[0] = reg_tmp7.h[0];
    if (reg_tmp7.h[1] != 0) goto next_9;
    if (reg_d7.h[0] <= 5) goto next_8;
    reg_d7.w = 5;
next_8:
    reg_d0.h[0] = 0xBC;
    reg_d1.h[0] = 0x200;
    hud_p1_lives_row_draw();
next_9:
    hud_p1_hyper_count_put();
    hud_p1_caption_put();
    hud_p1_multiplier_frame_restore();
next_10:
    reg_d7.h[0] = g_p2_lives;
    if ((s16)g_p2_lives < 0) goto next_13;
    reg_tmp7.w = reg_d7.h[0];
    reg_tmp7.w -= 1;
    reg_d7.h[0] = reg_tmp7.h[0];
    if (reg_tmp7.h[1] != 0) goto next_12;
    if (reg_d7.h[0] <= 5) goto next_11;
    reg_d7.w = 5;
next_11:
    reg_d0.h[0] = 0xBC;
    reg_d1.h[0] = 0x1900;
    hud_p2_lives_row_draw();
next_12:
    hud_p2_hyper_count_put();
    hud_p2_caption_put();
    hud_p2_multiplier_frame_restore();
next_13:
    g_score_panel_intro = 0;
}

#pragma push
#pragma opt_propagation off


void hud_p1_gauge_plate_draw(void)
{
    if ((*(s16 *)&g_p1_lives) >= 0) {
        u16 offset = reg_d6.h[0];
        u32 savedRegister;

        reg_d1.h[0] = 0x5BC0;
        reg_d2.w = 0xE65;
        reg_d3.h[0] = 0x840;
        reg_d4.h[0] = 9;
        savedRegister = reg_d1.w;
        reg_tmp1.w = savedRegister;
        reg_d1.h[1] = reg_d1.h[0];
        reg_d1.h[0] = 0;
        reg_d1.h[0] += offset;
        sprite_draw_with_score_entry(savedRegister);
        reg_d7.w = 0;
        hud_p1_hyper_gauge_draw_at();
    }
}
#pragma pop


void hud_p2_gauge_plate_draw(void) {
    if ((*(s16 *)&g_p2_lives) >= 0) {
        u32 savedRegister;
        u16 savedLow;

        reg_d1.h[0] = 0x5BC0;
        savedRegister = reg_d1.w;
        savedLow = reg_d1.h[0];
        reg_d1.h[0] = 0x2800;
        reg_d2.w = 0xE63;
        reg_d3.h[0] = 0x840;
        reg_d4.h[0] = 9;
        reg_tmp1.w = savedRegister;
        reg_d1.h[1] = savedLow;
        reg_d1.h[0] -= reg_d6.h[0];
        sprite_draw_with_score_entry();
        reg_d7.w = 0;
        hud_p2_hyper_gauge_draw_at();
    }
}

void hud_lives_draw_boss_entering(void) {
    reg_d1.h[0] = 0x5F80;
    reg_d6.h[0] = g_lives_display_move_x;
    reg_d6.h[0] <<= 7;
    if ((g_boss_bar_flags & 8) && ((s32) g_boss_hp_bar_move_count < 0xD)) {
        g_lives_display_move_y -= 1;
        if ((s16) g_lives_display_move_y < 0) {
            g_lives_display_move_y = 0;
        }
    }
    reg_d0.h[0] = g_lives_display_move_y;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_d0.h[0] = g_p1_lives;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    if ((s16)(g_p1_lives) >= 0) {
        reg_tmp.w = (u32) reg_d0.h[0];
        reg_tmp.w -= 1;
        reg_d0.h[0] = reg_tmp.h[0];
        if (reg_tmp.h[1] == 0) {
            if ((s32) reg_d0.h[0] > 5) {
                reg_d0.w = 5;
            }
        }
        reg_d1.h[0] = 0x100;
        reg_d7.h[0] = reg_d0.h[0];
        reg_d3.h[0] = 0x208;
        reg_d1.h[0] += reg_d6.h[0];
        hud_p1_ship_and_hyper_count_draw();
        if (g_boss_bar_flags & 0x10) {
            reg_d1.h[0] = 0;
            reg_d0.h[0] = 0xC0;
            hud_p1_lives_row_draw();
            hud_p1_hyper_count_put();
        }
    }
    reg_d0.h[0] = g_p2_lives;
    if ((s16)(g_p2_lives) >= 0) {
        reg_tmp.w = (u32) reg_d0.h[0];
        reg_tmp.w -= 1;
        reg_d0.h[0] = reg_tmp.h[0];
        if (reg_tmp.h[1] == 0) {
            if ((s32) reg_d0.h[0] > 5) {
                reg_d0.w = 5;
            }
        }
        reg_d1.h[0] = 0x3700;
        reg_d7.h[0] = reg_d0.h[0];
        reg_d3.h[0] = 0x208;
        reg_d1.h[0] -= reg_d6.h[0];
        hud_p2_ship_and_hyper_count_draw();
        if (g_boss_bar_flags & 0x10) {
            reg_d0.h[0] = 0xC0;
            reg_d1.h[0] = 0x1B00;
            hud_p2_lives_row_draw();
            hud_p2_hyper_count_put();
        }
    }
    g_lives_display_move_x -= 1;
    if ((s16) g_lives_display_move_x < 0) {
        g_lives_display_move_x = 0;
    }
}

void hud_lives_draw_boss_leaving(void) {
    reg_d1.h[0] = 0x5DC0;
    reg_d0.h[0] = g_lives_display_move_y;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] += reg_d0.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    if (((*(u8 *)&g_boss_hp_bar_flags) & 8) && ((s32) g_boss_hp_bar_move_count < 0x11)) {
        g_lives_display_move_x -= 1;
        if ((s16) g_lives_display_move_x < 0) {
            g_lives_display_move_x = 0;
        }
    }
    reg_d6.h[0] = g_lives_display_move_x;
    reg_d0.h[0] = g_p1_lives;
    reg_d6.h[0] <<= 6;
    if ((s16)(g_p1_lives) >= 0) {
        reg_tmp.w = (u32) reg_d0.h[0];
        reg_tmp.w -= 1;
        reg_d0.h[0] = reg_tmp.h[0];
        if (reg_tmp.h[1] == 0) {
            if ((s32) reg_d0.h[0] > 5) {
                reg_d0.w = 5;
            }
        }
        reg_d1.h[0] = 0x500;
        reg_d7.h[0] = reg_d0.h[0];
        reg_d3.h[0] = 0x208;
        reg_d1.h[0] -= reg_d6.h[0];
        hud_p1_ship_and_hyper_count_draw();
        if ((s8) (*(u8 *)&g_boss_hp_bar_flags) < 0) {
            reg_d0.h[0] = 0xBC;
            reg_d1.h[0] = 0x200;
            hud_p1_lives_row_draw();
            hud_p1_hyper_count_put();
        }
    }
    reg_d0.h[0] = g_p2_lives;
    if ((s16)(g_p2_lives) >= 0) {
        reg_tmp.w = (u32) reg_d0.h[0];
        reg_tmp.w -= 1;
        reg_d0.h[0] = reg_tmp.h[0];
        if (reg_tmp.h[1] == 0) {
            if ((s32) reg_d0.h[0] > 5) {
                reg_d0.w = 5;
            }
        }
        reg_d1.h[0] = 0x3300;
        reg_d7.h[0] = reg_d0.h[0];
        reg_d3.h[0] = 0x208;
        reg_d1.h[0] += reg_d6.h[0];
        hud_p2_ship_and_hyper_count_draw();
        if ((s8) (*(u8 *)&g_boss_hp_bar_flags) < 0) {
            reg_d0.h[0] = 0xBC;
            reg_d1.h[0] = 0x1900;
            hud_p2_lives_row_draw();
            hud_p2_hyper_count_put();
        }
    }
    g_lives_display_move_y -= 1;
    if ((s16) g_lives_display_move_y < 0) {
        g_lives_display_move_y = 0;
    }
}

s32 sfx_bonus_count();
s32 music_fade_out();
s32 score_add_p1();
s32 score_add_p2();
s32 score_value_add();
extern u8 g_replay_save_asked;
extern u8 g_stage_clear_wait_timer;
extern s32 g_boss_score;
extern s32 g_boss_hit_bonus;
extern u16 g_boss_hit_bonus_timer;
extern u8 g_simulation_active;
extern s16 g_player2[];
extern s16 g_player1[];

void hud_boss_hit_bonus(void) {
    u8 flags;
    u8 *p;

    flags = g_boss_present;
    switch (flags & 8) {
    case 0:
        return;
    }
    if (flags & 0x10) goto next_0;
    g_boss_present = flags | 0x10;
    g_boss_hit_bonus_timer = 7;
    reg_a0 = (u8 *)&g_boss_hit_bonus_timer;
    reg_d0.w = (*(u32 *)&g_boss_score);
    reg_d0.w <<= 4;
    score_value_add();
next_0:
    if (!(g_boss_present & 4)) {
        hud_boss_hit_bonus_draw();
        return;
    }
    if (g_boss_present & 2) {
        hud_boss_hit_bonus_draw();
        return;
    }
    boss_hits_take_on_button();
    if (cond_flag != 0) goto next_6;
    g_boss_hit_bonus_timer -= 1;
    if ((s16)g_boss_hit_bonus_timer >= 0) goto next_9;
    if ((*(u32 *)&g_boss_hit_bonus) == 0) goto next_1;
    sfx_bonus_count();
next_1:
    reg_d0.w = 0x10;
    reg_d0.h[0] -= g_boss_hits;
    if ((s16)reg_d0.h[0] < 0) goto next_2;
    reg_d0.h[0] >>= 2;
    reg_d0.h[0] += 1;
    goto next_3;
next_2:
    reg_d0.w = 0;
next_3:
    g_boss_hit_bonus_timer = reg_d0.h[0];
    reg_d7.w = 0;
    if (g_boss_hits < 0x32) goto next_4;
    g_boss_hits -= 1;
    reg_d7.w = 1;
next_4:
    if (g_boss_hits < 0x64) goto next_5;
    g_boss_hits -= 1;
    reg_d7.w = 2;
next_5:
    if (g_boss_hits < 0x96) goto next_7;
    g_boss_hits -= 1;
    reg_d7.w = 3;
next_7:
    reg_tmp.w = 0;
    reg_tmp.h[0] = g_boss_hits;
    g_boss_hits -= 1;
    reg_tmp.w -= 1;
    if (g_boss_hits == 0) goto next_6;
    if ((s16)g_boss_hits >= 0) goto next_8;
    if (reg_tmp.h[1] != 0) goto next_10;
    g_replay_save_asked = 0;
    g_stage_clear_wait_timer = 0;
    g_boss_present |= 2;
    if (g_simulation_active == 0) goto next_11;
    g_stage_clear_wait_timer = 0x78;
    music_fade_out();
    goto next_12;
next_11:
    if (g_stage == 4) goto next_12;
    g_stage_clear_wait_timer = 0x78;
    music_fade_out();
next_12:
    reg_d0.w = 0;
    g_boss_hits = reg_d0.h[0];
    g_boss_hit_bonus_timer = reg_d0.h[0];
    g_boss_hit_bonus = reg_d0.w;
    hud_boss_hit_bonus_draw();
    return;
next_10:
    g_boss_hit_bonus_timer = 8;
    g_boss_hit_anim_count = 0xFFFF;
    goto next_9;
next_6:
    g_boss_hits = 0xFFFF;
    g_boss_hit_anim_count = 0x17;
    g_boss_hit_bonus_timer = 0x12;
next_8:
    reg_d0.w = (*(u32 *)&g_boss_score);
    reg_d0.w >>= 8;
loop_0:
    p = (u8 *)&g_boss_hit_bonus_timer;
    reg_a0 = p;
    score_value_add();
    reg_a0 = p;
    score_value_add();
    reg_a0 = p;
    score_value_add();
    reg_a0 = p;
    score_value_add();
    reg_a0 = p;
    score_value_add();
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
next_9:
    if (g_boss_hits == 0) goto next_13;
    if ((s16)g_boss_hits < 0) goto next_13;
    hud_boss_hit_bonus_draw();
    return;
next_13:
    if (g_boss_hit_bonus_timer == 8) goto next_14;
    hud_boss_hit_bonus_draw();
next_14:
    reg_d1.w = (*(u32 *)&g_boss_hit_bonus);
    if (reg_d1.w == 0) goto next_15;
    sfx_bonus_count();
    reg_d0.w = reg_d1.w;
    reg_d0.w >>= 4;
    if (g_player1[0] >= 0) goto next_16;
    score_add_p1();
next_16:
    if (g_player2[0] >= 0) goto next_17;
    score_add_p2();
next_17:
    reg_d0.w = 0;
    g_boss_hit_bonus = reg_d0.w;
next_15:
    hud_boss_hit_bonus_draw();
}

s32 input_get_p1_held();
s32 input_get_p2_held();
extern s8 g_menu_pad;
extern u8 g_replay_mode;
void boss_hits_take_on_button(void) {
    u32 temp_s0;
    u32 temp_v1;

    reg_d0.h[0] = g_boss_hits;
    reg_d0.h[0] -= 1;
    if ((s16) reg_d0.h[0] < 0) {
        cond_flag = 0;
        return;
    }
    reg_d0.w = 0;
    if (g_player1[0] < 0) {
        input_get_p1_held();
        if ((g_replay_mode == 2) && (g_menu_pad == 1)) {
            input_get_p2_held();
        }
    }
    if (g_player2[0] < 0) {
        temp_s0 = reg_d0.h[0];
        input_get_p2_held();
        if ((g_replay_mode == 2) && (g_menu_pad == 0)) {
            input_get_p1_held();
        }
        reg_d0.h[0] |= temp_s0 & 0xFFFF;
    }
    temp_v1 = reg_d0.b[0] & 0x70;
    reg_d0.b[0] = temp_v1;
    if (!(temp_v1 & 0xFF)) {
        cond_flag = 0;
        return;
    }
    reg_d7.h[0] = g_boss_hits;
    cond_flag = 1;
    g_boss_hits = 0;
    reg_d7.w -= 1;
}

s32 palette_bank_b_load_half();
extern u8 hud_hits_draw_table[];
extern u8 hud_hits_draw_table_2[];
extern u8 hud_hits_draw_table_3[];
extern u16 g_frame_mod2;

void hud_hits_draw(void) {
    u32 save_d0;
    u32 save_d6;

    reg_d1.h[1] = 0x4FC0;
    reg_d3.h[0] = 0x610;
    reg_d5.w = 0xCCB;
    if (g_frame_mod2 != 0) goto next_0;
    reg_d5.w = 0xCD5;
next_0:
    if (reg_d2.h[0] == 0) goto next_1;
    save_d0 = reg_d0.h[0];
    reg_a0 = (u8 *)hud_hits_draw_table;
    reg_d0.h[0] = reg_d4.h[0];
    palette_bank_b_load_half();
    reg_d0.h[0] = save_d0;
    goto next_2;
next_1:
    save_d0 = reg_d0.h[0];
    reg_a0 = (u8 *)hud_hits_draw_table_2;
    reg_d0.h[0] = reg_d4.h[0];
    palette_bank_b_load_half();
    reg_d0.h[0] = save_d0;
    if (reg_d0.h[0] < 0x100) goto next_2;
    save_d0 = reg_d0.h[0];
    reg_a0 = (u8 *)hud_hits_draw_table_3;
    reg_d0.h[0] = reg_d4.h[0];
    palette_bank_b_load_half();
    reg_d0.h[0] = save_d0;
next_2:
    reg_d7.w = 3;
loop_0:
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] <<= 4;
    reg_d0.h[0] |= (u16)((s32)reg_tmp.h[0] >> 12);
    reg_d2.w = 0xF;
    if ((reg_d2.h[0] &= reg_d0.h[0]) != 0) goto next_3;
    if ((s32)reg_d6.w < 0) goto next_3;
    if ((s16)reg_d1.h[0] > 0x1C00) goto next_7;
    goto next_8;
next_3:
    reg_d6.w |= 0x80000000;
    if (reg_d6.h[0] >= 0xC) goto next_5;
    reg_d5.w = 0;
    save_d6 = reg_d6.w;
loop_1:
    reg_tmp6.w = reg_d6.h[0];
    reg_tmp6.w -= 3;
    reg_d6.h[0] = reg_tmp6.h[0];
    if (reg_tmp6.h[1] != 0) goto next_4;
    reg_d5.h[0] += 4;
    goto loop_1;
next_4:
    reg_d6.w = save_d6;
    reg_a0 = (u8 *)hud_hit_digit_sets;
    reg_a0 = *(u8 **)(reg_a0 + reg_d5.h[0]);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_tmp2.w = reg_d2.w;
    reg_d2.w = *(u32 *)(reg_a0 + reg_tmp2.h[0]);
    goto next_6;
next_5:
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = *(u16 *)(((u8 *)hud_digit_offsets) + (reg_d2.h[0] & ~1));
    reg_d2.w += reg_d5.w;
next_6:
    sprite_draw_with_score_keep_entry();
next_7:
    reg_d1.h[0] += 0x480;
next_8:
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    hud_hits_label_draw();
}


void hud_hits_label_draw(void) {
    reg_d1.h[0] += 0xFE00;
    reg_d1.h[1] = 0x4EC0;
    reg_d6.h[0] -= 0x17;
    if ((s16) reg_d6.h[0] >= 0) goto next_1;
    reg_d6.h[0] *= 0xFFFF;
    reg_a0 = (u8 *)hud_hit_label_frames;
    reg_d6.h[0] &= 0xFFFE;
    reg_d6.h[0] += reg_d6.h[0];
    reg_d2.w = *(u32 *) (reg_a0 + reg_d6.h[0]);
    goto next_2;
next_1:
    reg_d2.w = 0xD78;
    if (g_frame_mod2 != 0) goto next_2;
    reg_d2.w = 0xD78;
next_2:
    reg_d3.h[0] = 0x420;
    sprite_draw_with_score_entry_2();
}

s32 binary_to_bcd();

void hud_boss_hits_draw(void) {
    u32 save_d6;

    reg_d0.h[0] = g_boss_hits;
    if ((s16)reg_d0.h[0] >= 0) goto next_0;
    reg_d0.w = 0;
next_0:
    binary_to_bcd();
    reg_d0.w = reg_d2.w;
    reg_d1.w = 0x5BBFFE00;
    reg_d1.h[0] += 0x440;
    reg_d4.h[0] = (*(u16 *)&g_boss_hit_palette);
    reg_d6.w = 0;
    reg_d6.h[0] = g_boss_hit_anim_count;
    reg_d7.w = 7;
loop_0:
    reg_tmp.w = reg_d0.w;
    reg_d0.w <<= 4;
    reg_d0.w |= reg_tmp.w >> 28;
    reg_d2.w = 0xF;
    reg_d2.h[0] &= reg_d0.h[0];
    if (reg_d2.h[0] != 0) goto next_1;
    if ((s32)reg_d6.w >= 0) goto next_5;
next_1:
    reg_d6.w |= 0x80000000;
    if (reg_d6.h[0] >= 0xC) goto next_3;
    reg_d5.w = 0;
    save_d6 = reg_d6.w;
loop_1:
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] -= 3;
    if ((s32)reg_tmp6.h[0] < 3) goto next_2;
    reg_d5.h[0] += 4;
    goto loop_1;
next_2:
    reg_d6.w = save_d6;
    reg_a0 = (u8 *)hud_boss_hit_digit_sets;
    reg_a0 = *(u8 **)(((u8 *)hud_boss_hit_digit_sets) + (reg_d5.h[0] & ~3));
    reg_d2.h[0] *= 4;
    reg_a0 += reg_d2.h[0];
    reg_d2.w = *(u32 *)reg_a0;
    goto next_4;
next_3:
    reg_d5.h[0] = reg_d2.h[0];
    reg_d2.w = 6;
    reg_d2.h[0] &= g_game_frame;
    reg_a0 = (u8 *)hud_boss_hit_flicker;
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)hud_boss_hit_digits_steady;
    reg_d5.h[0] += reg_d5.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_a0 += reg_d5.h[0];
    reg_d2.w += *(u32 *)reg_a0;
next_4:
    reg_d3.h[0] = 0x610;
    sprite_draw_with_score_keep_entry();
next_5:
    reg_d1.h[0] += 0x440;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    reg_d1.h[0] += 0xFE00;
    reg_d1.w -= 0x2000000;
    reg_d2.w = 0xE37;
    reg_d6.h[0] -= 0x1B;
    if ((s16)reg_d6.h[0] >= 0) goto next_6;
    reg_d6.h[0] *= 0xFFFF;
    reg_d6.h[0] &= 0xFFFE;
    reg_d6.h[0] += reg_d6.h[0];
    reg_d2.w = *(u32 *)(((u8 *)hud_boss_hit_label_frames) + (reg_d6.h[0] & ~3));
next_6:
    reg_d3.h[0] = 0x420;
    sprite_draw_with_score_entry_2();
}

s32 sprite_draw_layer2_keep();

void hud_boss_hit_bonus_draw(void) {
    reg_d0.w = (*(u32 *)&g_boss_hit_bonus);
    reg_d1.w = 0x0E000C00;
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x10;
    reg_a0 = (u8 *)boss_hit_bonus_digits;
    reg_d6.w = 0;
    reg_d7.w = 7;
loop_0:
    reg_tmp.w = reg_d0.w;
    reg_d0.w <<= 4;
    reg_d0.w |= reg_tmp.w >> 28;
    reg_d2.w = 0xF;
    reg_d2.h[0] &= reg_d0.h[0];
    if (reg_d2.h[0] != 0) goto next_0;
    if (reg_d7.h[0] == 0) goto next_0;
    if (reg_d6.h[0] == 0) goto next_1;
next_0:
    reg_d6.w = 1;
    reg_a0 = (u8 *)boss_hit_bonus_digits;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 += reg_d2.h[0];
    reg_d2.w = *(u32 *)reg_a0;
    sprite_draw_layer2_keep();
next_1:
    reg_d1.h[0] += 0x400;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
}


void hud_combo_gauge_draw(void) {
    reg_d2.h[0] = g_loop;
    reg_a0 = (u8 *) combo_gauge_levels_by_loop;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = *(u8 **) (reg_a0 + reg_d2.h[0]);
    reg_d6.h[0] += reg_d6.h[0];
    reg_d2.w = 0;
    reg_d2.h[0] = (reg_d6.h[0]) ? *(u16 *) (reg_a0 + ((s16) reg_d6.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_d3.h[0] = 0x810;
    reg_d2.w += 0xD7D;
    sprite_draw_with_score_entry_2();
}

s32 p1_invincible_start();
s32 p1_hyper_effect_start();
s32 p1_hyper_effect_draw_first();
s32 p1_hyper_effect_draw();
extern u8 g_p1_stage_start_timer;
extern u8 g_game_frame_ran;
extern u16 g_select_screen_active;
extern u16 g_p1_hyper_in_effect;
extern u16 g_p1_hyper_level;
extern u16 g_p1_hyper_total;
extern u16 g_p1_hyper_time;
extern u16 g_p1_hits;
extern u16 g_max_combo_time;
extern u8 g_replay_save_prompt_active;
void hud_p1_hyper_update(void) {
    u32 temp_a0;
    u32 temp_v1;

    if (g_p1_hyper_active == 0) {
        if (g_p1_hyper_in_effect == 0) {
            p1_hyper_effect_draw();
            return;
        }
        reg_d0.w = 0x11;
        temp_a0 = reg_d0.b[0];
        temp_v1 = temp_a0 & D_0029F261[0];
        reg_d0.b[0] = temp_v1;
        if (!(temp_v1 & 0xFF)) {
            g_p1_hyper_active = 1;
            p1_hyper_effect_start();
            hud_p1_hyper_count_put();
            if (g_p1_combo_timer != 0) {
                g_p1_combo_timer = g_max_combo_time;
            }
            reg_d0.h[0] = g_p1_hyper_items;
            g_p1_hyper_total += reg_d0.h[0];
            g_p1_hyper_level = reg_d0.h[0];
            if (g_p1_hyper_total > 0xF) {
                g_p1_hyper_total = 0xF;
            }
            D_0028E5DD = 0;
            (*(s8 *)&g_p1_hyper_combo_decay) = 0;
            g_p1_hyper_items = 0;
            p1_invincible_start();
            goto block_9;
        }
    } else {
block_9:
        p1_hyper_effect_draw_first();
        if (D_0029F261[0] & 1) {
            p1_hyper_end();
            return;
        }
        if (((s32) g_p1_hits >= 0x10) && (g_p1_combo_timer != 0)) {
            g_p1_hit10_color_timer = g_p1_combo_timer;
            g_p1_hit10_display_timer = 0x78;
            g_p1_chain_points_display_timer = 0x78;
        }
        if (!(g_boss_present_b1 & 0x40) && (g_select_screen_active == 0) && (g_replay_save_prompt_active == 0) && (g_game_frame_ran != 0)) {
            g_p1_hyper_time -= 2;
            if ((s16) g_p1_hyper_time < 0) {
                p1_hyper_end();
                if (g_p1_stage_start_timer == 0x78) {
                    g_p1_stage_start_timer = 0xA;
                }
            }
        }
    }
}

s32 p1_laser_release();                            /* extern */
s32 hud_p1_hyper_count_put();                            /* extern */
s32 p1_hyper_items_update();                            /* extern */
extern u16 g_p1_hyper_effect_frame;

void p1_hyper_end(void) {
    if (g_p1_hyper_active != 0) {
        g_p1_hyper_effect_frame = 0x48;
    }
    p1_laser_release();
    reg_d0.w = 0;
    g_p1_hyper_active = reg_d0.h[0];
    g_p1_hyper_time = reg_d0.h[0];
    g_p1_hyper_level = reg_d0.h[0];
    g_p1_hyper_in_effect = reg_d0.h[0];
    hud_p1_hyper_count_put();
    p1_hyper_items_update();
}

s32 p2_invincible_start();
s32 p2_hyper_effect_start();
s32 p2_hyper_effect_draw_first();
s32 p2_hyper_effect_draw();
extern u8 g_p2_stage_start_timer;
extern u16 g_p2_hyper_in_effect;
extern u16 g_p2_hyper_level;
extern u16 g_p2_hyper_total;
extern u16 g_p2_hyper_time;
extern u16 g_p2_hits;
extern s16 g_p2_hit10_display_timer;
void hud_p2_hyper_update(void) {
    u32 temp_a0;
    u32 temp_v1;

    if (g_p2_hyper_active == 0) {
        if (g_p2_hyper_in_effect == 0) {
            p2_hyper_effect_draw();
            return;
        }
        reg_d0.w = 0x11;
        temp_a0 = reg_d0.b[0];
        temp_v1 = temp_a0 & D_0029F1F1[0];
        reg_d0.b[0] = temp_v1;
        if (!(temp_v1 & 0xFF)) {
            g_p2_hyper_active = 1;
            p2_hyper_effect_start();
            hud_p2_hyper_count_put();
            if (g_p2_combo_timer != 0) {
                g_p2_combo_timer = g_max_combo_time;
            }
            reg_d0.h[0] = g_p2_hyper_items;
            g_p2_hyper_total += reg_d0.h[0];
            g_p2_hyper_level = reg_d0.h[0];
            if (g_p2_hyper_total > 0xF) {
                g_p2_hyper_total = 0xF;
            }
            D_0028E5D9 = 0;
            (*(s8 *)&g_p2_hyper_combo_decay) = 0;
            g_p2_hyper_items = 0;
            p2_invincible_start();
            goto block_9;
        }
    } else {
block_9:
        p2_hyper_effect_draw_first();
        if (D_0029F1F1[0] & 1) {
            p2_hyper_end();
            return;
        }
        if (((s32) g_p2_hits >= 0x10) && (g_p2_combo_timer != 0)) {
            g_p2_hit10_color_timer = g_p2_combo_timer;
            g_p2_hit10_display_timer = 0x78;
            g_p2_chain_points_display_timer = 0x78;
        }
        if (!(g_boss_present_b1 & 0x40) && (g_select_screen_active == 0) && (g_replay_save_prompt_active == 0) && (g_game_frame_ran != 0)) {
            g_p2_hyper_time -= 2;
            if ((s16) g_p2_hyper_time < 0) {
                p2_hyper_end();
                if (g_p2_stage_start_timer == 0x78) {
                    g_p2_stage_start_timer = 0xA;
                }
            }
        }
    }
}

s32 p2_laser_release();                            /* extern */
s32 hud_p2_hyper_count_put();                            /* extern */
s32 p2_hyper_items_update();                            /* extern */
extern u16 g_p2_hyper_effect_frame;

void p2_hyper_end(void) {
    if (g_p2_hyper_active != 0) {
        g_p2_hyper_effect_frame = 0x48;
    }
    p2_laser_release();
    reg_d0.w = 0;
    g_p2_hyper_active = reg_d0.h[0];
    g_p2_hyper_time = reg_d0.h[0];
    g_p2_hyper_level = reg_d0.h[0];
    g_p2_hyper_in_effect = reg_d0.h[0];
    hud_p2_hyper_count_put();
    p2_hyper_items_update();
}


void hud_p1_hyper_gauge_draw(void) {
    reg_d6.sw = 0;
    reg_d7.sw = 0;
    hud_p1_hyper_gauge_draw_at();
}

extern u16 g_boss_hyper_wait;
extern u16 g_p1_hyper_items_pending;
extern u16 g_p1_hyper_gauge;

void hud_p1_hyper_gauge_draw_at(void) {
    u32 t1;

    switch (g_p1_hyper_active) {
    case 0:
        goto next_0;
    }
    reg_d2.w = 0;
    reg_d2.h[0] = g_p1_hyper_time;
    reg_d2.h[0] *= 0x16;
    reg_d2.h[1] = 0;
    reg_d2.h[0] /= 0x4B0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)hyper_gauge_frames;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d1.h[0] = 0x5EC0;
    reg_tmp1.w = reg_d1.w;
    t1 = reg_d1.h[0];
    reg_d1.h[1] = t1;
    reg_d1.h[0] = 0x400;
    if (!(g_boss_present & 1)) goto next_1;
    if (g_boss_hp_bar_flags < 0) goto next_1;
    if (g_boss_bar_flags & 0x10) goto next_2;
    reg_d1.h[0] = 0x60C0;
    reg_d0.h[0] = g_lives_display_move_y;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0;
    reg_d0.h[0] = g_lives_display_move_x;
    reg_d0.h[0] <<= 7;
    reg_d1.h[0] += reg_d0.h[0];
    goto next_1;
next_2:
    if (g_boss_present_b1 & 8) goto next_3;
    reg_d1.h[0] = 0x60C0;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0;
    goto next_1;
next_3:
    reg_d0.h[0] = g_lives_display_move_y;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] = t1 + reg_d0.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x400;
    reg_d0.h[0] = g_lives_display_move_x;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] -= reg_d0.h[0];
next_1:
    reg_d3.h[0] = 0x430;
    reg_d4.h[0] = 9;
    sprite_draw_with_score_entry();
    reg_d1.h[0] = 0x5FC0;
    reg_d1.h[0] -= reg_d7.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x1000;
    reg_d1.h[0] += reg_d6.h[0];
    reg_d2.w = 0xCFF;
    reg_d3.h[0] = 0x608;
    reg_d4.h[0] = 9;
    reg_d0.h[0] = g_p1_hyper_items_pending;
    if (g_p1_hyper_items_pending == 0) goto next_4;
    reg_d0.h[0] -= 1;
loop_0:
    sprite_draw_with_score_keep_entry();
    reg_d1.h[0] += 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
next_4:
    reg_d2.w = 0;
    reg_d2.h[0] = g_p1_hyper_gauge;
    if (g_p1_hyper_gauge == 0) return;
    reg_d2.h[0] <<= 4;
    reg_d2.h[0] /= 0x4B0;
    reg_a0 = (u8 *)hyper_stock_frames_p1;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    sprite_draw_with_score_entry_2();
    return;
next_0:
    reg_d1.h[0] = 0x5FC0;
    reg_d1.h[0] -= reg_d7.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x1000;
    reg_d1.h[0] += reg_d6.h[0];
    reg_d3.h[0] = 0x608;
    reg_d4.h[0] = 9;
    if (g_boss_hyper_wait == 0) goto next_5;
    reg_d0.h[0] = g_p1_hyper_items_pending;
    if (g_p1_hyper_items_pending == 0) goto next_5;
    reg_d0.h[0] -= 1;
    reg_d2.w = 0xCFF;
loop_1:
    sprite_draw_with_score_keep_entry();
    reg_d1.h[0] += 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_1;
next_5:
    reg_d2.w = 0;
    reg_d2.h[0] = g_p1_hyper_gauge;
    if (g_p1_hyper_gauge == 0) return;
    reg_d2.h[0] <<= 4;
    reg_d2.h[0] /= 0x4B0;
    reg_a0 = (u8 *)hyper_stock_frames_p1;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    sprite_draw_with_score_entry_2();
}


void hud_p2_hyper_gauge_draw(void) {
    reg_d6.sw = 0;
    reg_d7.sw = 0;
    hud_p2_hyper_gauge_draw_at();
}

extern u16 g_p2_hyper_items_pending;
extern u16 g_p2_hyper_gauge;

void hud_p2_hyper_gauge_draw_at(void) {
    u32 t1;

    switch (g_p2_hyper_active) {
    case 0:
        goto next_0;
    }
    reg_d2.w = 0;
    reg_d2.h[0] = g_p2_hyper_time;
    reg_d2.h[0] *= 0x16;
    reg_d2.h[1] = 0;
    reg_d2.h[0] /= 0x4B0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)hyper_gauge_frames;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d1.h[0] = 0x5EC0;
    reg_tmp1.w = reg_d1.w;
    t1 = reg_d1.h[0];
    reg_d1.h[1] = t1;
    reg_d1.h[0] = 0x2800;
    if (!(g_boss_present & 1)) goto next_1;
    if (g_boss_hp_bar_flags < 0) goto next_1;
    if (g_boss_bar_flags & 0x10) goto next_2;
    reg_d1.h[0] = 0x60C0;
    reg_d0.h[0] = g_lives_display_move_y;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x2C00;
    reg_d0.h[0] = g_lives_display_move_x;
    reg_d0.h[0] <<= 7;
    reg_d1.h[0] -= reg_d0.h[0];
    goto next_1;
next_2:
    if (g_boss_present_b1 & 8) goto next_3;
    reg_d1.h[0] = 0x60C0;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x2C00;
    goto next_1;
next_3:
    reg_d0.h[0] = g_lives_display_move_y;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] = t1 + reg_d0.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x2800;
    reg_d0.h[0] = g_lives_display_move_x;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] += reg_d0.h[0];
next_1:
    reg_d3.h[0] = 0x430;
    reg_d4.h[0] = 9;
    sprite_draw_with_score_entry();
    reg_d1.h[0] = 0x5FC0;
    reg_d1.h[0] -= reg_d7.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x2600;
    reg_d1.h[0] -= reg_d6.h[0];
    reg_d2.w = 0xE3A;
    reg_d3.h[0] = 0x608;
    reg_d4.h[0] = 9;
    reg_d0.h[0] = g_p2_hyper_items_pending;
    if (g_p2_hyper_items_pending == 0) goto next_4;
    reg_d0.h[0] -= 1;
loop_0:
    sprite_draw_with_score_keep_entry();
    reg_d1.h[0] -= 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
next_4:
    reg_d2.w = 0;
    reg_d2.h[0] = g_p2_hyper_gauge;
    if (g_p2_hyper_gauge == 0) return;
    reg_d2.h[0] <<= 4;
    reg_d2.h[0] /= 0x4B0;
    reg_a0 = (u8 *)hyper_stock_frames_p2;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    sprite_draw_with_score_entry_2();
    return;
next_0:
    reg_d1.h[0] = 0x5FC0;
    reg_d1.h[0] -= reg_d7.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x2600;
    reg_d1.h[0] -= reg_d6.h[0];
    reg_d3.h[0] = 0x608;
    reg_d4.h[0] = 9;
    if (g_boss_hyper_wait == 0) goto next_5;
    reg_d0.h[0] = g_p2_hyper_items_pending;
    if (g_p2_hyper_items_pending == 0) goto next_5;
    reg_d0.h[0] -= 1;
    reg_d2.w = 0xE3A;
loop_1:
    sprite_draw_with_score_keep_entry();
    reg_d1.h[0] -= 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_1;
next_5:
    reg_d2.w = 0;
    reg_d2.h[0] = g_p2_hyper_gauge;
    if (g_p2_hyper_gauge == 0) return;
    reg_d2.h[0] <<= 4;
    reg_d2.h[0] /= 0x4B0;
    reg_a0 = (u8 *)hyper_stock_frames_p2;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    sprite_draw_with_score_entry_2();
}

extern s32 g_hyper_text_anim_sprite;
extern u16 g_hyper_text_anim_frame;
extern u16 g_hyper_text_anim_delay;
extern u8 D_0028E705;

void hyper_text_animate(void)
{
    s32 tableEntry;

    D_0028E705 -= 1;
    if ((s8)D_0028E705 < 0) {
        reg_a0 = (u8 *)hyper_text_frames;
        D_0028E705 = (*(u8 *)&g_hyper_text_anim_delay);
        reg_d0.h[0] = g_hyper_text_anim_frame;
        tableEntry = *(s32 *)(reg_a0 + reg_d0.h[0]);
        g_hyper_text_anim_frame -= 4;
        g_hyper_text_anim_sprite = tableEntry;
        if ((s16)g_hyper_text_anim_frame < 0) {
            g_hyper_text_anim_frame = 0x38;
        }
    }
}

extern s32 g_maximum_text_anim_sprite;

void maximum_text_animate(void) {
    reg_d0.w = 0x3F;
    reg_a0 = (u8 *)maximum_text_frames;
    reg_d0.h[0] &= g_game_frame;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    g_maximum_text_anim_sprite = *(s32 *)(reg_a0 + reg_d0.h[0]);
}


void hud_text_sprite_draw(void) {
    reg_d3.sh[0] = 0x430;
    reg_d4.sh[0] = 0x9;
    sprite_draw_with_score_entry_2();
}

s32 deferred_text_put_sheet();

void hud_multiplier_text_put(void) {
    s32 deferred_text_put();
    u32 save_d5;

    if (reg_d6.h[0] >= 0x10) goto next_1;
    reg_d6.h[0] += reg_d6.h[0];
    reg_d6.h[0] += reg_d6.h[0];
    reg_a0 = (u8 *)multiplier_units_text;
    reg_d4.h[1] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((reg_d6.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d6.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 2;
    deferred_text_put();
    reg_d1.h[0] += 0x300;
next_0:
    reg_d4.h[0] = reg_d5.h[0];
    reg_a0 = (u8 *)max_level_text;
    reg_tmp4.w = reg_d4.w;
    reg_d4.h[1] = (reg_tmp4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_tmp4.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((reg_tmp4.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_tmp4.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 2;
    reg_d5.w = 9;
    deferred_text_put_sheet();
    return;
next_1:
    save_d5 = reg_d5.h[0];
    reg_d5.w = 0xC;
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] <<= reg_d5.h[0];
    reg_d6.h[0] |= (u16)((s32)reg_tmp6.h[0] >> (0x10 - reg_d5.h[0]));
    reg_d5.w = 0xF;
    reg_d5.h[0] &= reg_d6.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_a0 = (u8 *)multiplier_tens_text;
    reg_d4.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((u16)reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 1;
    deferred_text_put();
    reg_d1.h[0] += 0x200;
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] <<= 4;
    reg_d6.h[0] |= (u16)((s32)reg_tmp6.h[0] >> 12);
    reg_d5.w = 0xF;
    reg_d5.h[0] &= reg_d6.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_d5.h[0] += reg_d5.h[0];
    reg_a0 = (u8 *)multiplier_ones_text;
    reg_d4.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 0;
    reg_d5.w = 3;
    deferred_text_put_sheet();
    reg_d1.h[0] += 0x100;
    reg_d5.h[0] = save_d5;
    goto next_0;
}


void hud_max_hits_text_put(void) {
    s32 deferred_text_put();
    u32 temp_a1;
    u32 temp_v1_2;
    u16 var_v0_2;
    u32 temp_s0;
    u32 temp_s1;

    reg_d2.w = 2;
    reg_d3.w = 5;
    reg_d4.w = 0x053D000A;
    deferred_text_put();
    reg_d5.w = 0;
    reg_a1 = (u8 *)(hit_count_digit_text);
    reg_d7.w = 3;
    reg_d1.h[0] += 0x200;
    do {
        reg_tmp6.h[0] = reg_d6.h[0];
        reg_d2.w = 0xF;
        reg_d6.h[0] *= 0x10;
        temp_a1 = ((s32) reg_tmp6.h[0] >> 0xC) & 0xFFFF;
        reg_d6.h[0] |= temp_a1;
        temp_v1_2 = reg_d2.h[0] & reg_d6.h[0];
        reg_d2.h[0] = temp_v1_2;
        if ((temp_v1_2 & 0xFFFF) || (reg_d5.h[0] != 0)) {
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[0] += reg_d2.h[0];
            reg_d4.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a1;
            var_v0_2 = (((u16)reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
            temp_s0 = reg_d2.w;
            temp_s1 = reg_d3.w;
            reg_d4.h[0] = var_v0_2;
            reg_d2.w = 2;
            reg_d5.w = 0xA;
            reg_d3.w = 0;
            deferred_text_put_sheet();
            reg_d2.w = temp_s0;
            reg_d3.w = temp_s1;
            reg_d5.w = 1;
        }
        reg_d1.h[0] += 0x100;
        reg_a1 += 0x28;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

u16 hud_digit_offsets[16] = {
    0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007,
    0x0008, 0x0009, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u32 *hud_hit_digit_sets[4] = {
    hud_hit_digits_a,
    hud_hit_digits_b,
    hud_hit_digits_c,
    hud_hit_digits_d,
};

u32 hud_hit_digits_a[12] = {
    0x0CA3, 0x0CA4, 0x0CA5, 0x0CA6, 0x0CA7, 0x0CA8, 0x0CA9, 0x0CAA,
    0x0CAB, 0x0CAC, 0x0000, 0x0000,
};

u32 hud_hit_digits_b[12] = {
    0x0CAD, 0x0CAE, 0x0CAF, 0x0CB0, 0x0CB1, 0x0CB2, 0x0CB3, 0x0CB4,
    0x0CB5, 0x0CB6, 0x0000, 0x0000,
};

u32 hud_hit_digits_c[12] = {
    0x0CB7, 0x0CB8, 0x0CB9, 0x0CBA, 0x0CBB, 0x0CBC, 0x0CBD, 0x0CBE,
    0x0CBF, 0x0CC0, 0x0000, 0x0000,
};

u32 hud_hit_digits_d[12] = {
    0x0CC1, 0x0CC2, 0x0CC3, 0x0CC4, 0x0CC5, 0x0CC6, 0x0CC7, 0x0CC8,
    0x0CC9, 0x0CCA, 0x0000, 0x0000,
};

u32 hud_hit_label_frames[12] = {
    0x0D78, 0x0D77, 0x0D76, 0x0D75, 0x0D74, 0x0D73, 0x0D72, 0x0D71,
    0x0D70, 0x0D6F, 0x0D6E, 0x0D6D,
};

u32 *hud_boss_hit_digit_sets[4] = {
    hud_boss_hit_digits_a,
    hud_boss_hit_digits_b,
    hud_boss_hit_digits_c,
    hud_boss_hit_digits_d,
};

u32 hud_boss_hit_digits_a[12] = {
    0x0D9E, 0x0D9F, 0x0DA0, 0x0DA1, 0x0DA2, 0x0DA3, 0x0DA4, 0x0DA5,
    0x0DA6, 0x0DA7, 0x0000, 0x0000,
};

u32 hud_boss_hit_digits_b[12] = {
    0x0DA8, 0x0DA9, 0x0DAA, 0x0DAB, 0x0DAC, 0x0DAD, 0x0DAE, 0x0DAF,
    0x0DB0, 0x0DB1, 0x0000, 0x0000,
};

u32 hud_boss_hit_digits_c[12] = {
    0x0DB2, 0x0DB3, 0x0DB4, 0x0DB5, 0x0DB6, 0x0DB7, 0x0DB8, 0x0DB9,
    0x0DBA, 0x0DBB, 0x0000, 0x0000,
};

u32 hud_boss_hit_label_frames[16] = {
    0x0E37, 0x0E36, 0x0E35, 0x0E34, 0x0E33, 0x0E32, 0x0E31, 0x0E30,
    0x0E2F, 0x0E2E, 0x0E2D, 0x0E2C, 0x0E2B, 0x0E2A, 0x0000, 0x0000,
};

u32 hud_boss_hit_digits_d[12] = {
    0x0DBC, 0x0DBD, 0x0DBE, 0x0DBF, 0x0DC0, 0x0DC1, 0x0DC2, 0x0DC3,
    0x0DC4, 0x0DC5, 0x0000, 0x0000,
};

u32 hud_boss_hit_digits_steady[10] = {
    0x0DEE, 0x0DEF, 0x0DF0, 0x0DF1, 0x0DF2, 0x0DF3, 0x0DF4, 0x0DF5,
    0x0DF6, 0x0DF7,
};

u16 hud_boss_hit_flicker[4] = {
    0x0000, 0x0014, 0x000A, 0x0014,
};
