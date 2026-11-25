#include "common.h"
extern u8 g_player1_as_u8_a[];
#include "player.h"
extern u8 g_player2_as_u8_a[];

void func_001A5AD0(void);
void func_001A5B50(void);
void func_001A5DD0(void);
void func_001A6050(void);
void func_001A6510(void);
void func_001A6650(void);
void func_001A68B0(void);
void func_001A6B70(void);
void func_001A6BE0(void);
void func_001A6C60(void);
void func_001A6E70(void);
void func_001A7080(void);
void func_001A7410(void);
void func_001A7520(void);
void func_001A77A0(void);
void func_001A7840(void);
void func_001A7B30(void);
void func_001A7C60(void);
void func_001A7D00(void);
void func_001A7E90(void);
void func_001A7EE0(void);
void func_001A8070(void);
void func_001A80C0(void);
void func_001A80D0(void);
void func_001A8510(void);
void func_001A8520(void);
void func_001A8970(void);
void func_001A89E0(void);
void sprite_draw_with_score_entry_2_d3_430_d4_9(void);
void func_001A8A60(void);
void func_001A8E00(void);

void func_001A53B0(void) {
}


void func_001A53C0(void) {
    func_001A53B0();
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

void func_001A5400(void) {
    extern void deferred_text_put(void);
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x200;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x54F000A;
    deferred_text_put();
}

void func_001A5430(void) {
    extern void deferred_text_put(void);
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1400;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x54F000A;
    deferred_text_put();
}

void func_001A5460(void) {
    extern void deferred_text_put(void);
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x200;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x414000A;
    deferred_text_put();
}

void func_001A5490(void) {
    void deferred_text_put(void);
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x1400;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x414000A;
    deferred_text_put();
}

extern u8 D_0026BFD0[];
extern u8 D_0028DAE8[];
extern u16 g_p1_hyper_items;
extern u16 g_p1_hyper_active;

void func_001A54C0(void) {
    u32 save_d1;

    save_d1 = reg_d1.w;
    if ((s16)reg_d0.h[0] < 0) goto next_0;
    reg_d5.w = reg_d1.w;
    reg_d1.h[0] += 0xFF00;
    reg_d1.h[1] += 0xFE00;
    reg_d2.h[0] = PLAYER(g_player1_as_u8_a)->ship_type.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0028DAE8;
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
    reg_a0 = (u8 *)D_0026BFD0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    sprite_draw_with_score_entry();
next_1:
    reg_d1.w = save_d1;
}

extern u8 D_0028DAF0[];
extern u16 g_p2_hyper_items;
extern u16 g_p2_hyper_active;

void func_001A5600(void) {
    if ((s16)reg_d0.h[0] < 0) goto next_0;
    reg_d5.w = reg_d1.w;
    reg_d1.h[0] += 0xFF00;
    reg_d1.h[1] += 0xFE00;
    reg_d2.h[0] = PLAYER(g_player2_as_u8_a)->ship_type.h;
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0028DAF0;
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
    reg_a0 = (u8 *)D_0026BFD0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    sprite_draw_with_score_entry();
next_1:
    return;
}

extern u16 D_0028DAF8[];

void func_001A5740(arg0)
    u16 arg0;
{
    s32 deferred_text_put();
    u16 var_a0;
    var_a0 = arg0;
    if ((s16) reg_d7.h[0] >= 0) {
        reg_d2.h[0] = 1;
        reg_a0 = (u8 *)(D_0028DAF8);
        reg_d4.h[0] = PLAYER(g_player1_as_u8_a)->ship_type.h;
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

extern u16 D_0028DB00[];

void func_001A5850(void) {
    extern void deferred_text_put(void);
    if ((s16)reg_d7.h[0] >= 0) {
        reg_d2.h[0] = 1;
        reg_a0 = (u8 *)D_0028DB00;
        reg_d4.h[0] = PLAYER(g_player2_as_u8_a)->ship_type.h;
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

extern s16 g_p1_lives_as_s16;

void func_001A5960(void) {
    if (g_p1_lives_as_s16 >= 0) {
        reg_d6.w = 0x12;
        reg_d6.h[0] -= 0x32;
        reg_d6.h[0] <<= 7;
        func_001A80D0();
    }
}

extern s16 g_p2_lives_as_s16;

void func_001A59B0(void) {
    if (g_p2_lives_as_s16 >= 0) {
        reg_d6.w = 0x12;
        reg_d6.h[0] -= 0x32;
        reg_d6.h[0] <<= 7;
        func_001A8520();
    }
}

extern u16 g_boss_hits;
extern u16 g_boss_hit_carry;

void func_001A5A00(void) {
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

void func_001A5A80(void) {
    func_001A89E0();
    func_001A8970();
    if (g_score_panel_intro != 0) {
        func_001A68B0();
        return;
    }
    func_001A5AD0();
}

extern u8 g_boss_present;
extern u8 D_0028E961;

void func_001A5AD0(void) {
    func_001A7D00();
    func_001A7EE0();
    func_001A5A00();
    if (g_boss_present & 1) {
        func_001A6050();
        return;
    }
    if (D_0028E961 & 8) {
        func_001A6050();
        return;
    }
    func_001A5B50();
}

extern u16 g_p1_maximum_level;
extern u16 g_game_frame;
extern u8 g_p1_hyper_combo_decay_as_u8;
extern u8 D_0028E5DD;
extern u16 g_p1_max_hits;
extern s8 g_boss_hp_bar_flags;
extern u16 g_p1_hits_shown;
extern u32 g_p1_chain_points_as_u32;
extern u16 g_p1_hit10_anim_count;
extern u16 g_p1_hit10_color_timer;
extern u16 g_p1_hit10_display_timer_as_u16;
extern u16 g_p1_combo_timer;
extern u32 g_p1_chain_first_score_as_u32;
extern u32 g_maximum_text_anim_sprite_as_u32;
extern u32 g_hyper_text_anim_sprite_as_u32;
extern u8 g_p1_score_panel_flags;
extern u16 g_p1_maximum_count_digits[];
extern u8 D_0029F261[];
void func_001A5B50(void) {
    if (g_p1_lives_as_s16 < 0) {
        func_001A5DD0();
        return;
    }
    func_001A80C0();
    if (!(g_boss_present & 1) || (g_boss_hp_bar_flags < 0)) {
        if (g_p1_hyper_active != 0) {
            if (!(g_p1_score_panel_flags & 1)) {
                g_p1_score_panel_flags |= 1;
                func_001A5400();
                func_001A5460();
            }
            reg_d1.w = 0x64C00400;
            reg_d2.w = g_hyper_text_anim_sprite_as_u32;
            sprite_draw_with_score_entry_2_d3_430_d4_9();
        } else {
            g_p1_score_panel_flags &= 0xFE;
            if (g_game_frame & 0x40) {
                if (!(D_0029F261[0] & 0x40) && (reg_d6.h[0] = g_p1_maximum_count_digits[0], (g_p1_maximum_count_digits[0] != 0))) {
                    reg_d0.w = 0x3F;
                    reg_d0.h[0] &= g_game_frame;
                    if ((s32) reg_d0.h[0] < 0x14) {
                        func_001A5400();
                        reg_d1.w = 0x64C00400;
                        reg_d2.w = g_maximum_text_anim_sprite_as_u32;
                        sprite_draw_with_score_entry_2_d3_430_d4_9();
                    } else {
                        reg_d0.h[0] = 0xD4;
                        reg_d1.h[0] = 0x200;
                        reg_d5.h[0] = g_p1_maximum_level;
                        func_001A8A60();
                    }
                } else {
                    goto block_15;
                }
            } else {
block_15:
                reg_d0.h[0] = 0xD4;
                reg_d1.h[0] = 0x200;
                reg_d6.h[0] = g_p1_max_hits;
                func_001A8E00();
            }
        }
    }
    if (g_p1_hit10_display_timer_as_u16 != 0) {
        g_p1_hit10_display_timer_as_u16 -= 1;
        reg_d1.h[0] = 0x40;
        reg_d6.w = 0;
        reg_d0.h[0] = g_p1_hits_shown;
        reg_d6.h[0] = g_p1_hit10_anim_count;
        g_p1_hit10_anim_count += 1;
        reg_d3.h[0] = g_p1_hit10_display_timer_as_u16;
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
        func_001A7520();
    }
    reg_d6.h[0] = g_p1_combo_timer;
    if (g_p1_combo_timer != 0) {
        if (g_p1_hyper_active != 0) {
            D_0028E5DD -= 1;
            if ((s8) D_0028E5DD < 0) {
                D_0028E5DD = g_p1_hyper_combo_decay_as_u8;
                goto block_26;
            }
            goto block_29;
        }
block_26:
        g_p1_combo_timer -= 1;
        if (g_p1_combo_timer == 0) {
            reg_d0.w = 0;
            g_p1_chain_first_score_as_u32 = reg_d0.w;
            g_p1_chain_points_as_u32 = reg_d0.w;
        } else {
block_29:
            reg_d1.w = 0x5BC00000;
            reg_d4.h[0] = 9;
            func_001A7C60();
        }
    }
    func_001A5DD0();
}

extern u16 g_p2_maximum_level;
extern u8 g_p2_hyper_combo_decay_as_u8;
extern u8 D_0028E5D9;
extern u16 g_p2_max_hits;
extern u16 g_p2_hits_shown;
extern u32 g_p2_chain_points_as_u32;
extern u16 g_p2_hit10_anim_count;
extern u16 g_p2_hit10_color_timer;
extern u16 g_p2_hit10_display_timer_as_u16;
extern u16 g_p2_combo_timer;
extern u32 g_p2_chain_first_score_as_u32;
extern u8 g_p2_score_panel_flags;
extern u16 g_p2_maximum_count_digits[];
extern u8 D_0029F1F1[];
void func_001A5DD0(void) {
    if (g_p2_lives_as_s16 < 0) {
        func_001A6510();
        return;
    }
    func_001A8510();
    if (!(g_boss_present & 1) || (g_boss_hp_bar_flags < 0)) {
        if (g_p2_hyper_active != 0) {
            if (!(g_p2_score_panel_flags & 1)) {
                g_p2_score_panel_flags |= 1;
                func_001A5430();
                func_001A5490();
            }
            reg_d1.w = 0x64C02800;
            reg_d2.w = g_hyper_text_anim_sprite_as_u32;
            sprite_draw_with_score_entry_2_d3_430_d4_9();
        } else {
            g_p2_score_panel_flags &= 0xFE;
            if (g_game_frame & 0x40) {
                if (!(D_0029F1F1[0] & 0x40) && (reg_d6.h[0] = g_p2_maximum_count_digits[0], (g_p2_maximum_count_digits[0] != 0))) {
                    reg_d0.w = 0x3F;
                    reg_d0.h[0] &= g_game_frame;
                    if ((s32) reg_d0.h[0] < 0x2C) {
                        func_001A5430();
                        reg_d1.w = 0x64C02800;
                        reg_d2.w = g_maximum_text_anim_sprite_as_u32;
                        sprite_draw_with_score_entry_2_d3_430_d4_9();
                    } else {
                        reg_d0.h[0] = 0xD4;
                        reg_d1.h[0] = 0x1400;
                        reg_d5.h[0] = g_p2_maximum_level;
                        func_001A8A60();
                    }
                } else {
                    goto block_15;
                }
            } else {
block_15:
                reg_d0.h[0] = 0xD4;
                reg_d1.h[0] = 0x1400;
                reg_d6.h[0] = g_p2_max_hits;
                func_001A8E00();
            }
        }
    }
    if (g_p2_hit10_display_timer_as_u16 != 0) {
        g_p2_hit10_display_timer_as_u16 -= 1;
        reg_d1.h[0] = 0x1FC0;
        reg_d6.w = 0;
        reg_d0.h[0] = g_p2_hits_shown;
        reg_d6.h[0] = g_p2_hit10_anim_count;
        g_p2_hit10_anim_count += 1;
        reg_d3.h[0] = g_p2_hit10_display_timer_as_u16;
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
        func_001A7520();
    }
    reg_d6.h[0] = g_p2_combo_timer;
    if (g_p2_combo_timer != 0) {
        if (g_p2_hyper_active != 0) {
            D_0028E5D9 -= 1;
            if ((s8) D_0028E5D9 < 0) {
                D_0028E5D9 = g_p2_hyper_combo_decay_as_u8;
                goto block_26;
            }
            goto block_29;
        }
block_26:
        g_p2_combo_timer -= 1;
        if (g_p2_combo_timer == 0) {
            reg_d0.w = 0;
            g_p2_chain_first_score_as_u32 = reg_d0.w;
            g_p2_chain_points_as_u32 = reg_d0.w;
        } else {
block_29:
            reg_d1.w = 0x5BC03400;
            reg_d4.h[0] = 0x4009;
            func_001A7C60();
        }
    }
    func_001A6510();
}

s32 voice_hyper();
s32 sprite_palette_load();
s32 func_001AC8C0();
s32 func_001AC8E0();
extern u8 D_00261C30[];
extern u8 D_00261C70[];
extern u8 D_0028E61D;
extern u8 *g_boss_hp;
extern u32 g_boss_hp_unit_as_u32;
extern u16 g_lives_display_move_x;
extern u16 g_lives_display_move_y;
extern u16 g_boss_hp_bar_move_count;
extern u8 D_0028E635;
extern u8 g_boss_present_b1;
extern u16 g_loop;
extern u16 g_stage;
extern u16 g_bomb_entities[];

void func_001A6050(void) {
    s32 deferred_text_put();
    s32 flag;
    s32 bits;

    if (g_boss_present_b1 & 8) {
        func_001A6650();
        return;
    }
    flag = D_0028E635;
    if ((s8) flag < 0) goto next_160;
    bits = flag & 0xFF;
    if (bits & 0x10) goto next_120;
    if (bits & 8) goto next_80;
    if (bits & 1) goto next_40;
    D_0028E635 = flag | 1;
    g_boss_hp_bar_move_count = 0x32;
    g_lives_display_move_x = 8;
    g_lives_display_move_y = 8;
    if (!(D_0028E635 & 2)) {
        D_0028E635 |= 2;
        goto next_20;
    }
    if (!(D_0028E635 & 4)) {
        D_0028E635 |= 4;
        goto next_20;
    }
    func_001AC8C0();
    func_001AC8E0();
    reg_a0 = (u8 *)D_00261C30;
    reg_d0.h[0] = 7;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00261C70;
    reg_d0.h[0] = 8;
    sprite_palette_load();
    goto next_40;
next_20:
    D_0028E635 &= 0xFE;
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
    func_001A6B70();
    func_001A6BE0();
    func_001A6C60();
    g_boss_hp_bar_move_count -= 1;
    if (g_boss_hp_bar_move_count != 0x11) {
        func_001A6510();
        return;
    }
    D_0028E635 |= 8;
    g_boss_hp_bar_move_count = 0x38;
    func_001A6510();
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
    func_001A5960();
    func_001A59B0();
    func_001A6C60();
    func_001A6510();
    return;
next_100:
    D_0028E635 = flag | 0x10;
    func_001A6C60();
    g_boss_hp_bar_move_count = 0xFFE2;
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0;
    reg_d2.w = 1;
    reg_d3.w = 0x1B;
    reg_d4.w = 0x03B6000A;
    deferred_text_put();
    reg_d7.h[0] = 0xE00;
    func_001A5960();
    func_001A59B0();
    func_001A6510();
    return;
next_120:
    reg_d7.h[0] = 0xE00;
    func_001A5960();
    func_001A59B0();
    g_boss_hp_bar_move_count += 1;
    if ((s16) g_boss_hp_bar_move_count < 0) {
        func_001A6510();
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
    D_0028E635 |= 0x80;
    goto next_180;
next_160:
    reg_d7.h[0] = 0xE00;
    func_001A5960();
    func_001A59B0();
next_180:
    reg_a0 = (u8 *)g_boss_hp;
    reg_d7.h[1] = *(u16 *) (reg_a0 + 0);
    reg_d7.h[0] = *(u16 *) (reg_a0 + 2);
    if ((s32) reg_d7.w < 0) {
        func_001A6510();
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
    reg_d0.w = g_boss_hp_unit_as_u32;
loop_260:
    reg_tmp7.w = reg_d7.w;
    reg_d7.w -= reg_d0.w;
    if ((u32) reg_d0.w <= (u32) reg_tmp7.w) {
        reg_d3.h[0] += 1;
        goto loop_260;
    }
next_280:
    if (reg_d3.h[0] == 0x200) {
        func_001A6510();
        return;
    }
    sprite_draw_with_score_entry();
    func_001A6510();
}

s32 func_001AC320();
extern s16 g_boss_hit_palette;
extern u16 g_boss_hit_anim_count;
extern u16 g_boss_hit_decay_timer;
extern s16 g_two_player_state_as_s16;
extern u16 g_two_player_game;

void func_001A6510(void) {
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
    if (g_two_player_state_as_s16 < 0) goto next_6;
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
    func_001AC320();
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
    func_001A7840();
    goto next_7;
next_6:
    g_boss_hits = 0;
    g_boss_hit_decay_timer = 0;
next_7:
    if (g_boss_present_b1 & 8) {
        func_001A7080();
    }
}

s32 deferred_text_clear();
s32 func_001AC950();
s32 func_001AC9D0();
extern s16 g_lives_display_move_x_as_s16;
extern s16 g_lives_display_move_y_as_s16;
extern u8 g_boss_hp_bar_flags_as_u8;
extern s16 g_p2_chain_points_display_timer;
extern s16 g_p1_hit10_display_timer;
extern s16 g_p1_chain_points_display_timer;

void func_001A6650(void) {
    u8 flags;

    flags = g_boss_hp_bar_flags_as_u8;
    if ((s8)flags >= 0) goto next_0;
    func_001A5B50();
    return;
next_0:
    if (flags & 8) goto next_5;
    if (flags & 1) goto next_2;
    g_boss_hp_bar_flags_as_u8 |= 1;
    g_boss_hp_bar_move_count = 0x38;
    g_lives_display_move_x_as_s16 = 0x10;
    g_lives_display_move_y_as_s16 = 8;
    if (!(g_boss_hp_bar_flags_as_u8 & 2)) {
        g_boss_hp_bar_flags_as_u8 |= 2;
        goto next_1;
    }
    if (!(g_boss_hp_bar_flags_as_u8 & 4)) {
        g_boss_hp_bar_flags_as_u8 |= 4;
        goto next_1;
    }
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0;
    reg_d2.w = 6;
    reg_d3.w = 0x1B;
    deferred_text_clear();
    goto next_2;
next_1:
    g_boss_hp_bar_flags_as_u8 &= 0xFE;
next_2:
    func_001A6E70();
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
    func_001A5960();
    func_001A59B0();
    g_boss_hp_bar_move_count -= 1;
    if (g_boss_hp_bar_move_count != 0) {
        func_001A6510();
        return;
    }
    g_boss_hp_bar_flags_as_u8 |= 8;
    g_boss_hp_bar_move_count = 0x41;
    func_001A6510();
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
    func_001A6B70();
    func_001A6BE0();
    func_001A6E70();
    func_001A6510();
    return;
next_7:
    g_boss_hp_bar_flags_as_u8 |= 0x80;
    g_p1_chain_points_display_timer = 0;
    g_p2_chain_points_display_timer = 0;
    g_p1_hit10_display_timer = 0;
    func_001A6E70();
    if (g_p1_lives_as_s16 < 0) goto next_8;
    func_001AC950();
    func_001A5400();
next_8:
    if (g_p2_lives_as_s16 < 0) {
        func_001A6510();
        return;
    }
    func_001AC9D0();
    func_001A5430();
    func_001A6510();
}

s32 func_001AA8F0();
s32 func_001AAA20();
s32 func_001AC3A0();
s32 func_001AC5F0();
extern s16 g_score_panel_intro_as_s16;
extern u16 g_p2_lives;
extern u16 g_p1_lives;

void func_001A68B0(void) {
    if (!(g_boss_present & 1)) goto next_2;
    if ((s16)g_p1_lives < 0) goto next_0;
    func_001AA8F0();
    func_001AC3A0();
next_0:
    if ((s16)g_p2_lives < 0) goto next_1;
    func_001AAA20();
    func_001AC5F0();
next_1:
    g_score_panel_intro_as_s16 = 0;
    func_001A5AD0();
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
    func_001A54C0();
    func_001A6B70();
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
    func_001A5600();
    func_001A6BE0();
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
    func_001A5740();
next_9:
    func_001AA8F0();
    func_001AC950();
    func_001A5400();
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
    func_001A5850();
next_12:
    func_001AAA20();
    func_001AC9D0();
    func_001A5430();
next_13:
    g_score_panel_intro_as_s16 = 0;
}

#pragma push
#pragma opt_propagation off


void func_001A6B70(void)
{
    if (g_p1_lives_as_s16 >= 0) {
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
        func_001A80D0();
    }
}
#pragma pop


void func_001A6BE0(void) {
    if (g_p2_lives_as_s16 >= 0) {
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
        func_001A8520();
    }
}

void func_001A6C60(void) {
    reg_d1.h[0] = 0x5F80;
    reg_d6.h[0] = g_lives_display_move_x;
    reg_d6.h[0] <<= 7;
    if ((D_0028E635 & 8) && ((s32) g_boss_hp_bar_move_count < 0xD)) {
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
        func_001A54C0();
        if (D_0028E635 & 0x10) {
            reg_d1.h[0] = 0;
            reg_d0.h[0] = 0xC0;
            func_001A5740();
            func_001AA8F0();
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
        func_001A5600();
        if (D_0028E635 & 0x10) {
            reg_d0.h[0] = 0xC0;
            reg_d1.h[0] = 0x1B00;
            func_001A5850();
            func_001AAA20();
        }
    }
    g_lives_display_move_x -= 1;
    if ((s16) g_lives_display_move_x < 0) {
        g_lives_display_move_x = 0;
    }
}

void func_001A6E70(void) {
    reg_d1.h[0] = 0x5DC0;
    reg_d0.h[0] = g_lives_display_move_y;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] += reg_d0.h[0];
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    if ((g_boss_hp_bar_flags_as_u8 & 8) && ((s32) g_boss_hp_bar_move_count < 0x11)) {
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
        func_001A54C0();
        if ((s8) g_boss_hp_bar_flags_as_u8 < 0) {
            reg_d0.h[0] = 0xBC;
            reg_d1.h[0] = 0x200;
            func_001A5740();
            func_001AA8F0();
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
        func_001A5600();
        if ((s8) g_boss_hp_bar_flags_as_u8 < 0) {
            reg_d0.h[0] = 0xBC;
            reg_d1.h[0] = 0x1900;
            func_001A5850();
            func_001AAA20();
        }
    }
    g_lives_display_move_y -= 1;
    if ((s16) g_lives_display_move_y < 0) {
        g_lives_display_move_y = 0;
    }
}

s32 sfx_bonus_count();
s32 music_fade_out();
s32 func_001A9180();
s32 func_001A9190();
s32 score_value_add();
extern s8 D_0028E2A0_as_s8;
extern s8 D_0028E2A4_as_s8;
extern u32 g_boss_score_as_u32;
extern u32 g_boss_hit_bonus_as_u32;
extern u16 g_boss_hit_bonus_timer;
extern u8 g_simulation_active;
extern s16 g_player2[];
extern s16 g_player1[];

void func_001A7080(void) {
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
    reg_d0.w = g_boss_score_as_u32;
    reg_d0.w <<= 4;
    score_value_add();
next_0:
    if (!(g_boss_present & 4)) {
        func_001A7B30();
        return;
    }
    if (g_boss_present & 2) {
        func_001A7B30();
        return;
    }
    func_001A7410();
    if (cond_flag != 0) goto next_6;
    g_boss_hit_bonus_timer -= 1;
    if ((s16)g_boss_hit_bonus_timer >= 0) goto next_9;
    if (g_boss_hit_bonus_as_u32 == 0) goto next_1;
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
    D_0028E2A0_as_s8 = 0;
    D_0028E2A4_as_s8 = 0;
    g_boss_present |= 2;
    if (g_simulation_active == 0) goto next_11;
    D_0028E2A4_as_s8 = 0x78;
    music_fade_out();
    goto next_12;
next_11:
    if (g_stage == 4) goto next_12;
    D_0028E2A4_as_s8 = 0x78;
    music_fade_out();
next_12:
    reg_d0.w = 0;
    g_boss_hits = reg_d0.h[0];
    g_boss_hit_bonus_timer = reg_d0.h[0];
    g_boss_hit_bonus_as_u32 = reg_d0.w;
    func_001A7B30();
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
    reg_d0.w = g_boss_score_as_u32;
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
    func_001A7B30();
    return;
next_13:
    if (g_boss_hit_bonus_timer == 8) goto next_14;
    func_001A7B30();
next_14:
    reg_d1.w = g_boss_hit_bonus_as_u32;
    if (reg_d1.w == 0) goto next_15;
    sfx_bonus_count();
    reg_d0.w = reg_d1.w;
    reg_d0.w >>= 4;
    if (g_player1[0] >= 0) goto next_16;
    func_001A9180();
next_16:
    if (g_player2[0] >= 0) goto next_17;
    func_001A9190();
next_17:
    reg_d0.w = 0;
    g_boss_hit_bonus_as_u32 = reg_d0.w;
next_15:
    func_001A7B30();
}

s32 input_get_p1_held();
s32 input_get_p2_held();
extern s8 D_0028EC24;
extern u8 g_replay_mode;
void func_001A7410(void) {
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
        if ((g_replay_mode == 2) && (D_0028EC24 == 1)) {
            input_get_p2_held();
        }
    }
    if (g_player2[0] < 0) {
        temp_s0 = reg_d0.h[0];
        input_get_p2_held();
        if ((g_replay_mode == 2) && (D_0028EC24 == 0)) {
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

s32 func_001A30A0();
extern u8 D_00261C50[];
extern u8 D_00261C90[];
extern u8 D_00261CD0[];
extern u8 D_0026B640[];
extern u8 D_0026B660[];
extern u16 g_frame_mod2;

void func_001A7520(void) {
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
    reg_a0 = (u8 *)D_00261C50;
    reg_d0.h[0] = reg_d4.h[0];
    func_001A30A0();
    reg_d0.h[0] = save_d0;
    goto next_2;
next_1:
    save_d0 = reg_d0.h[0];
    reg_a0 = (u8 *)D_00261C90;
    reg_d0.h[0] = reg_d4.h[0];
    func_001A30A0();
    reg_d0.h[0] = save_d0;
    if (reg_d0.h[0] < 0x100) goto next_2;
    save_d0 = reg_d0.h[0];
    reg_a0 = (u8 *)D_00261CD0;
    reg_d0.h[0] = reg_d4.h[0];
    func_001A30A0();
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
    reg_a0 = (u8 *)D_0026B660;
    reg_a0 = *(u8 **)(reg_a0 + reg_d5.h[0]);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_tmp2.w = reg_d2.w;
    reg_d2.w = *(u32 *)(reg_a0 + reg_tmp2.h[0]);
    goto next_6;
next_5:
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = *(u16 *)(D_0026B640 + (reg_d2.h[0] & ~1));
    reg_d2.w += reg_d5.w;
next_6:
    sprite_draw_with_score_keep_entry();
next_7:
    reg_d1.h[0] += 0x480;
next_8:
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    func_001A77A0();
}

extern u8 D_0026B730[];

void func_001A77A0(void) {
    reg_d1.h[0] += 0xFE00;
    reg_d1.h[1] = 0x4EC0;
    reg_d6.h[0] -= 0x17;
    if ((s16) reg_d6.h[0] >= 0) goto next_1;
    reg_d6.h[0] *= 0xFFFF;
    reg_a0 = (u8 *)D_0026B730;
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

s32 func_00200EE0();
extern u8 D_0026B760[];
extern u8 D_0026B800[];
extern u8 D_0026B870[];
extern u8 D_0028DAD0[];
extern u16 g_boss_hit_palette_as_u16;

void func_001A7840(void) {
    u32 save_d6;

    reg_d0.h[0] = g_boss_hits;
    if ((s16)reg_d0.h[0] >= 0) goto next_0;
    reg_d0.w = 0;
next_0:
    func_00200EE0();
    reg_d0.w = reg_d2.w;
    reg_d1.w = 0x5BBFFE00;
    reg_d1.h[0] += 0x440;
    reg_d4.h[0] = g_boss_hit_palette_as_u16;
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
    reg_a0 = (u8 *)D_0026B760;
    reg_a0 = *(u8 **)(D_0026B760 + (reg_d5.h[0] & ~3));
    reg_d2.h[0] *= 4;
    reg_a0 += reg_d2.h[0];
    reg_d2.w = *(u32 *)reg_a0;
    goto next_4;
next_3:
    reg_d5.h[0] = reg_d2.h[0];
    reg_d2.w = 6;
    reg_d2.h[0] &= g_game_frame;
    reg_a0 = (u8 *)D_0028DAD0;
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)D_0026B870;
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
    reg_d2.w = *(u32 *)(D_0026B800 + (reg_d6.h[0] & ~3));
next_6:
    reg_d3.h[0] = 0x420;
    sprite_draw_with_score_entry_2();
}

s32 sprite_draw_layer2_keep();
extern u8 D_0026BFA0[];

void func_001A7B30(void) {
    reg_d0.w = g_boss_hit_bonus_as_u32;
    reg_d1.w = 0x0E000C00;
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 0x10;
    reg_a0 = (u8 *)D_0026BFA0;
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
    reg_a0 = (u8 *)D_0026BFA0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 += reg_d2.h[0];
    reg_d2.w = *(u32 *)reg_a0;
    sprite_draw_layer2_keep();
next_1:
    reg_d1.h[0] += 0x400;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
}

extern u16 D_0028DAE0[];

void func_001A7C60(void) {
    reg_d2.h[0] = g_loop;
    reg_a0 = (u8 *) D_0028DAE0;
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
s32 func_001AB920();
s32 func_001AB940();
s32 func_001AB9D0();
extern u8 D_0028E288;
extern u8 g_game_frame_ran;
extern u16 g_select_screen_active;
extern u16 g_p1_hyper_in_effect;
extern u16 g_p1_hyper_level;
extern s8 g_p1_hyper_combo_decay_as_s8;
extern s8 D_0028E5DD_as_s8;
extern u16 g_p1_hyper_total;
extern u16 g_p1_hyper_time;
extern u16 g_p1_hits;
extern u16 g_max_combo_time;
extern u8 D_0028EC4C;
void func_001A7D00(void) {
    u32 temp_a0;
    u32 temp_v1;

    if (g_p1_hyper_active == 0) {
        if (g_p1_hyper_in_effect == 0) {
            func_001AB9D0();
            return;
        }
        reg_d0.w = 0x11;
        temp_a0 = reg_d0.b[0];
        temp_v1 = temp_a0 & D_0029F261[0];
        reg_d0.b[0] = temp_v1;
        if (!(temp_v1 & 0xFF)) {
            g_p1_hyper_active = 1;
            func_001AB920();
            func_001AA8F0();
            if (g_p1_combo_timer != 0) {
                g_p1_combo_timer = g_max_combo_time;
            }
            reg_d0.h[0] = g_p1_hyper_items;
            g_p1_hyper_total += reg_d0.h[0];
            g_p1_hyper_level = reg_d0.h[0];
            if (g_p1_hyper_total > 0xF) {
                g_p1_hyper_total = 0xF;
            }
            D_0028E5DD_as_s8 = 0;
            g_p1_hyper_combo_decay_as_s8 = 0;
            g_p1_hyper_items = 0;
            p1_invincible_start();
            goto block_9;
        }
    } else {
block_9:
        func_001AB940();
        if (D_0029F261[0] & 1) {
            func_001A7E90();
            return;
        }
        if (((s32) g_p1_hits >= 0x10) && (g_p1_combo_timer != 0)) {
            g_p1_hit10_color_timer = g_p1_combo_timer;
            g_p1_hit10_display_timer = 0x78;
            g_p1_chain_points_display_timer = 0x78;
        }
        if (!(g_boss_present_b1 & 0x40) && (g_select_screen_active == 0) && (D_0028EC4C == 0) && (g_game_frame_ran != 0)) {
            g_p1_hyper_time -= 2;
            if ((s16) g_p1_hyper_time < 0) {
                func_001A7E90();
                if (D_0028E288 == 0x78) {
                    D_0028E288 = 0xA;
                }
            }
        }
    }
}

s32 p1_laser_release();                            /* extern */
s32 func_001AA8F0();                            /* extern */
s32 func_001ABB80();                            /* extern */
extern s16 g_p1_hyper_effect_frame_as_s16;

void func_001A7E90(void) {
    if (g_p1_hyper_active != 0) {
        g_p1_hyper_effect_frame_as_s16 = 0x48;
    }
    p1_laser_release();
    reg_d0.w = 0;
    g_p1_hyper_active = reg_d0.h[0];
    g_p1_hyper_time = reg_d0.h[0];
    g_p1_hyper_level = reg_d0.h[0];
    g_p1_hyper_in_effect = reg_d0.h[0];
    func_001AA8F0();
    func_001ABB80();
}

s32 p2_invincible_start();
s32 func_001ABA50();
s32 func_001ABA70();
s32 func_001ABB00();
extern u8 D_0028E284;
extern u16 g_p2_hyper_in_effect;
extern u16 g_p2_hyper_level;
extern s8 g_p2_hyper_combo_decay_as_s8;
extern s8 D_0028E5D9_as_s8;
extern u16 g_p2_hyper_total;
extern u16 g_p2_hyper_time;
extern u16 g_p2_hits;
extern s16 g_p2_hit10_display_timer;
void func_001A7EE0(void) {
    u32 temp_a0;
    u32 temp_v1;

    if (g_p2_hyper_active == 0) {
        if (g_p2_hyper_in_effect == 0) {
            func_001ABB00();
            return;
        }
        reg_d0.w = 0x11;
        temp_a0 = reg_d0.b[0];
        temp_v1 = temp_a0 & D_0029F1F1[0];
        reg_d0.b[0] = temp_v1;
        if (!(temp_v1 & 0xFF)) {
            g_p2_hyper_active = 1;
            func_001ABA50();
            func_001AAA20();
            if (g_p2_combo_timer != 0) {
                g_p2_combo_timer = g_max_combo_time;
            }
            reg_d0.h[0] = g_p2_hyper_items;
            g_p2_hyper_total += reg_d0.h[0];
            g_p2_hyper_level = reg_d0.h[0];
            if (g_p2_hyper_total > 0xF) {
                g_p2_hyper_total = 0xF;
            }
            D_0028E5D9_as_s8 = 0;
            g_p2_hyper_combo_decay_as_s8 = 0;
            g_p2_hyper_items = 0;
            p2_invincible_start();
            goto block_9;
        }
    } else {
block_9:
        func_001ABA70();
        if (D_0029F1F1[0] & 1) {
            func_001A8070();
            return;
        }
        if (((s32) g_p2_hits >= 0x10) && (g_p2_combo_timer != 0)) {
            g_p2_hit10_color_timer = g_p2_combo_timer;
            g_p2_hit10_display_timer = 0x78;
            g_p2_chain_points_display_timer = 0x78;
        }
        if (!(g_boss_present_b1 & 0x40) && (g_select_screen_active == 0) && (D_0028EC4C == 0) && (g_game_frame_ran != 0)) {
            g_p2_hyper_time -= 2;
            if ((s16) g_p2_hyper_time < 0) {
                func_001A8070();
                if (D_0028E284 == 0x78) {
                    D_0028E284 = 0xA;
                }
            }
        }
    }
}

s32 p2_laser_release();                            /* extern */
s32 func_001AAA20();                            /* extern */
s32 func_001ABD80();                            /* extern */
extern s16 g_p2_hyper_effect_frame_as_s16;

void func_001A8070(void) {
    if (g_p2_hyper_active != 0) {
        g_p2_hyper_effect_frame_as_s16 = 0x48;
    }
    p2_laser_release();
    reg_d0.w = 0;
    g_p2_hyper_active = reg_d0.h[0];
    g_p2_hyper_time = reg_d0.h[0];
    g_p2_hyper_level = reg_d0.h[0];
    g_p2_hyper_in_effect = reg_d0.h[0];
    func_001AAA20();
    func_001ABD80();
}


void func_001A80C0(void) {
    reg_d6.sw = 0;
    reg_d7.sw = 0;
    func_001A80D0();
}

extern u8 D_0026BDE0[];
extern u8 D_0026BEA0[];
extern u16 g_boss_hyper_wait;
extern u16 g_p1_hyper_items_pending;
extern u16 g_p1_hyper_gauge;

void func_001A80D0(void) {
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
    reg_a0 = (u8 *)D_0026BDE0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d1.h[0] = 0x5EC0;
    reg_tmp1.w = reg_d1.w;
    t1 = reg_d1.h[0];
    reg_d1.h[1] = t1;
    reg_d1.h[0] = 0x400;
    if (!(g_boss_present & 1)) goto next_1;
    if (g_boss_hp_bar_flags < 0) goto next_1;
    if (D_0028E635 & 0x10) goto next_2;
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
    reg_a0 = (u8 *)D_0026BEA0;
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
    reg_a0 = (u8 *)D_0026BEA0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    sprite_draw_with_score_entry_2();
}


void func_001A8510(void) {
    reg_d6.sw = 0;
    reg_d7.sw = 0;
    func_001A8520();
}

extern u8 D_0026BF20[];
extern u16 g_p2_hyper_items_pending;
extern u16 g_p2_hyper_gauge;

void func_001A8520(void) {
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
    reg_a0 = (u8 *)D_0026BDE0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d1.h[0] = 0x5EC0;
    reg_tmp1.w = reg_d1.w;
    t1 = reg_d1.h[0];
    reg_d1.h[1] = t1;
    reg_d1.h[0] = 0x2800;
    if (!(g_boss_present & 1)) goto next_1;
    if (g_boss_hp_bar_flags < 0) goto next_1;
    if (D_0028E635 & 0x10) goto next_2;
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
    reg_a0 = (u8 *)D_0026BF20;
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
    reg_a0 = (u8 *)D_0026BF20;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    sprite_draw_with_score_entry_2();
}

extern s32 D_0026BA70[];
extern s32 g_hyper_text_anim_sprite;
extern u16 g_hyper_text_anim_frame;
extern u8 g_hyper_text_anim_delay_as_u8;
extern u8 D_0028E705;

void func_001A8970(void)
{
    s32 tableEntry;

    D_0028E705 -= 1;
    if ((s8)D_0028E705 < 0) {
        reg_a0 = (u8 *)D_0026BA70;
        D_0028E705 = g_hyper_text_anim_delay_as_u8;
        reg_d0.h[0] = g_hyper_text_anim_frame;
        tableEntry = *(s32 *)(reg_a0 + reg_d0.h[0]);
        g_hyper_text_anim_frame -= 4;
        g_hyper_text_anim_sprite = tableEntry;
        if ((s16)g_hyper_text_anim_frame < 0) {
            g_hyper_text_anim_frame = 0x38;
        }
    }
}

extern s32 D_0026BAB0[];
extern s32 g_maximum_text_anim_sprite;

void func_001A89E0(void) {
    reg_d0.w = 0x3F;
    reg_a0 = (u8 *)D_0026BAB0;
    reg_d0.h[0] &= g_game_frame;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    g_maximum_text_anim_sprite = *(s32 *)(reg_a0 + reg_d0.h[0]);
}


void sprite_draw_with_score_entry_2_d3_430_d4_9(void) {
    reg_d3.sh[0] = 0x430;
    reg_d4.sh[0] = 0x9;
    sprite_draw_with_score_entry_2();
}

s32 deferred_text_put_sheet();
extern u8 D_0026BB60[];
extern u8 D_0026BB70[];
extern u8 D_0026BBA0[];
extern u8 D_0026BBD0[];

void func_001A8A60(void) {
    s32 deferred_text_put();
    u32 save_d5;

    if (reg_d6.h[0] >= 0x10) goto next_1;
    reg_d6.h[0] += reg_d6.h[0];
    reg_d6.h[0] += reg_d6.h[0];
    reg_a0 = (u8 *)D_0026BB70;
    reg_d4.h[1] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d4.h[0] = (((reg_d6.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d6.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 2;
    reg_d3.w = 2;
    deferred_text_put();
    reg_d1.h[0] += 0x300;
next_0:
    reg_d4.h[0] = reg_d5.h[0];
    reg_a0 = (u8 *)D_0026BB60;
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
    reg_a0 = (u8 *)D_0026BBA0;
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
    reg_a0 = (u8 *)D_0026BBD0;
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

extern u16 D_0026BC00[];

void func_001A8E00(void) {
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
    reg_a1 = (u8 *)(D_0026BC00);
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
