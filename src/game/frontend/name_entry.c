#include "common.h"
#include "task.h"
#include "entity.h"
#include "sdk/ps2sdk.h"
#include "cd.h"
#include "replay.h"
s32 password_conditions_check(void);
void password_make(void);
void name_entry_p1_update();
void name_entry_p2_update();
void name_entry_side_begin(void);
void name_entry_side_update(void);
void name_entry_side_done(void);
void name_entry_rank_find_p1(void);
void name_entry_rank_find_p2(void);
void name_entry_rank_find(void);
void name_entry_side_setup(void);
void name_entry_name_copy_to_own_ranks(void);
void name_entry_name_draw(void);
void name_entry_cursor_draw(void);
void name_entry_score_draw(void);
void name_entry_player_and_rank_draw(void);
void name_entry_letter_board_draw(void);
void name_entry_cover_draw_p1(void);
void name_entry_cover_draw_p2(void);
void name_entry_lever_input(void);
void name_entry_cursor_move(void);
extern u16 name_entry_letter_table[];

s32 text_layer_clear();
s32 music_play_bgm13();
s32 sprite_palette_load();
s32 p1_rank_entry_insert();
s32 p2_rank_entry_insert();
s32 stage_map_reset();
extern u8 name_entry_task_begin_table[];
extern u16 D_00261F30[];
extern u8 name_entry_task_begin_table_2[];
extern u8 name_entry_task_begin_table_3[];
extern u16 D_0028E4B0;
extern u8 g_name_entry_player;
extern u16 g_two_player_seen;
extern s16 g_player2[];
extern s16 g_player1[];
extern u8 D_002BAE00[];

void name_entry_task_begin() {
    stage_map_reset();
#ifndef DEATH_LABEL
    D_0028E4B0 = g_two_player_seen;
#endif
    text_layer_clear();
    *(s8 *)(reg_a5 + 3) = 1;
    memset(D_002BAE00, 0, 0x84);
    reg_a0 = (u8 *)((u8 *)D_00261F30);
    reg_d0.h[0] = 2;
    sprite_palette_load();
    reg_a0 = (u8 *)name_entry_task_begin_table_2;
    reg_d0.h[0] = 3;
    sprite_palette_load();
    reg_a0 = (u8 *)name_entry_task_begin_table_3;
    reg_d0.h[0] = 4;
    sprite_palette_load();
    reg_a0 = (u8 *)name_entry_task_begin_table;
    reg_d0.h[0] = 5;
    sprite_palette_load();
    if (0 > g_player1[0]) {
        p1_rank_entry_insert();
        if (cond_flag == 0) {
            g_name_entry_player |= 1;
        }
    }
    if (0 > g_player2[0]) {
        p2_rank_entry_insert();
        if (cond_flag == 0) {
            g_name_entry_player |= 2;
        }
    }
    *(u8 *)(reg_a5 + 4) = (u8) g_name_entry_player;
    if (*(u8 *)(reg_a5 + 4) != 0) {
        music_play_bgm13();
    }
}

s32 text_layer_clear();                            /* extern */
s32 game_state_clear();                            /* extern */
s32 ending_state_clear();                            /* extern */
s32 players_clear();                            /* extern */
s32 sound_stop_effects();                            /* extern */
s32 text_palette_load();                            /* extern */
extern u16 text_palette_0[16];
extern u8 D_0028E258;
extern u8 D_0028E25C;
extern u8 g_game_mode;
extern s32 D_0028EAFC;

void name_entry_task_finish() {
    players_clear();
    ending_state_clear();
    game_state_clear();
    task_stop_self();
    sound_stop_effects();
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)((s32 *)text_palette_0);
    text_palette_load();
    if ((s32) D_0028E258 < (s32) D_0028E25C) {
        D_0028E258 = D_0028E25C;
    }
    if (g_game_mode == 2) {
        password_make();
    } else if (password_conditions_check() != 0) {
        password_make();
    } else {
        D_0028EAFC = 0xFF;
    }
    reg_d0.h[0] = TASK_ATTRACT;
    task_start();
    (*(s16 *)((u8 *)((s32 *)reg_a0) + (4))) = 0x12;
}

u8 password_value_bits_put(s32 a, s32 b) {
    s8 i;
    s8 val = (s8)a;
    for (i = 0; i < (s8)b; i++) {
        s8 bit = (s8)(val & 1);
        val >>= 1;
        val &= 0x7F;
        if (bit) {
            val |= -0x80;
        }
    }
    return (u8)val;
}

extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u8 g_setting_difficulty;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;

s32 password_conditions_check(void) {
    if ((g_setting_difficulty == 1) && (g_setting_extend == 0) && (g_setting_ship_stock == 0) && (g_game_mode == 0) && (g_p1_score_digits == 0) && (g_p2_score_digits == 0) && (MAIN_OR_DEATH_LABEL(D_0028E4B0, g_two_player_seen) != 3)) {
#ifdef DEATH_LABEL
        printf("-----pass word ok!!------\n");
#else
        printf("-----pass word ok!!---[%d]---\n", D_0028E4B0);
#endif
        return 1;
    }
    return 0;
}

s32 rand(void);
extern s8 password_bits_unpack_table[];
extern s32 password_bits_unpack_state;
extern u8 password_bits_unpack_buffer[];
extern u8 D_002BAD63[];
extern u8 password_bits_unpack_buffer_2[];
extern u8 D_002BADD0[];
extern u8 D_002BADF0[];

s32 password_bits_unpack(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 val;
    u8 ch;

    memset(password_bits_unpack_buffer_2, 0, 0x60);
    k = 0;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 8; j++) {
            if (D_002BADF0[i] & (1 << j)) {
                password_bits_unpack_buffer_2[k] = 1;
            }
            k++;
        }
    }
    memset(password_bits_unpack_buffer, 0, 20);
    k = 0;
    for (i = 0; i < 20; i++) {
        val = 0;
        for (j = 0; j < 5; j++) {
            if (password_bits_unpack_buffer_2[k] != 0) {
                val |= 1 << j;
            }
            k++;
        }
        password_bits_unpack_buffer[i] = val;
    }
    for (i = 0; i < 4; i++) {
        if ((rand() % 2) != 0) {
            D_002BAD63[0] |= 1 << (i + 1);
        }
    }
    password_bits_unpack_state = 0;
    for (i = 0; password_bits_unpack_table[i] != -1; i++) {
        password_bits_unpack_state++;
    }
    memset(((s8 *)D_002BADD0), 0, 30);
    for (i = 0; i < 20; i++) {
        ch = password_bits_unpack_buffer[i];
        if ((((s32) ch < 0) || ((s32) ch >= password_bits_unpack_state)) ? 1 : 0) {
            printf((const char *)SJIS("error:変換された文字テーブル参照値が不正です。"));
            return 0;
        }
        ((s8 *)D_002BADD0)[i] = password_bits_unpack_table[ch];
    }
    return 1;
}

s64 atoi();
s32 sprintf();
extern u8 D_0028E2BC;
extern u8 D_002BADD0[];
extern u8 g_stored_ranking_texts[160];
extern u8 g_death_label_ranking_texts[272];
extern u16 g_ranking_score_tops[5];
extern u16 g_ranking_continues[5];
extern u16 g_ranking_hits[5];
extern u16 g_ranking_power_styles[5];
extern u16 g_ranking_ship_types[5];
extern u16 g_ranking_stages[5];
extern u16 g_ranking_loops[5];
extern s32 g_ranking_names[16];
extern s32 g_ranking_scores[8];
void password_make(void) {
    u32 save_d0;
    char str[0x28];
    u8 rec[14];
    u8 code[12];
    u32 score;
    u8 name[3];
    u16 val_fc;
    u16 val_fe;
    s32 i;
    u8 *p;
    s32 j;
    s32 i2;
    s32 k;
    s32 bits;
    s32 i1;
    s32 sum;
    u32 v0;
    u8 shift;
    u32 v3;
    u32 v4;
    u8 flags;
    u32 v1;
    u32 v2;
    u8 packed;
    u8 sw;
    u8 x;

    if (D_0028EAFC == 0xFF) return;
    save_d0 = reg_d0.w;
    for (j = 0; j < 14; j++) {
        rec[j] = 0;
    }
    flags = 0;
    score = ((u32 *)((u8 *)g_ranking_scores))[D_0028EAFC];
    for (i = 0; i < 3; i++) {
        name[i] = ((u32 *)((u8 *)g_ranking_names))[D_0028EAFC * 3 + i];
    }
    v0 = ((u16 *)((u8 *)g_ranking_stages))[D_0028EAFC];
    v1 = ((u16 *)((u8 *)g_ranking_ship_types))[D_0028EAFC];
    v2 = ((u16 *)((u8 *)g_ranking_power_styles))[D_0028EAFC];
    val_fc = ((u16 *)((u8 *)g_ranking_score_tops))[D_0028EAFC];
    v3 = ((u16 *)((u8 *)g_ranking_loops))[D_0028EAFC];
    val_fe = ((u16 *)((u8 *)g_ranking_hits))[D_0028EAFC];
    v4 = ((u16 *)((u8 *)g_ranking_continues))[D_0028EAFC];
    shift = (u32)D_0028E2BC & 3;
    if (shift == 0) {
        shift = (u8)(shift + 1);
    }
    printf("--no[%x]\n", D_0028EAFC);
    printf("--byou[%x]\n", (u8)shift);
    printf("--okuhi[%x]\n", val_fc);
    printf("--scohi[%x]\n", score);
    printf("--aerahi[%x]\n", (u16)v0);
    v1 = (u16)(v1 >> 1);
    printf("--typehi[%x]\n", v1);
    v2 = (u16)(v2 >> 1);
    printf("--kyokhi[%x]\n", v2);
    printf("--roundhi[%x]\n", (u16)v3);
    printf("--gphi[%x]\n", val_fe);
    printf("--cnthi[%x]\n", (u16)v4);
    printf("--name[%x][%x][%x]\n", name[0], name[1], name[2]);
    packed = (s8)(v1 & 3) << 6;
    packed |= (s8)(v2 & 3) << 4;
    packed |= v0 & 7;
    if (g_game_mode == 2) {
        flags |= 0x80;
    } else {
        flags = 0;
    }
    flags |= (v3 & 1) << 6;
    flags |= (v4 & 0xF) << 2;
    p = (u8 *)&score;
    rec[0] = p[0];
    rec[1] = p[1];
    rec[2] = p[2];
    rec[3] = p[3];
    rec[4] = packed;
    p = (u8 *)&val_fc;
    rec[5] = p[0];
    rec[6] = p[1];
    rec[8] = name[0];
    rec[9] = name[1];
    rec[10] = name[2];
    rec[7] = 0;
    rec[11] = 0;
    p = (u8 *)&val_fe;
    rec[12] = p[0];
    rec[13] = p[1];
    memset(code, 0, 12);
    memcpy(code, rec, 12);
    sum = 0;
    sprintf(str, (const char *)"%02x%02x%02x%02x0", code[3], code[2], code[1], code[0]);
    sum += atoi(str);
    sprintf(str, (const char *)"%02x%02x000000000", code[6], code[5]);
    sum += atoi(str);
    j = 2;
    bits = 0;
    for (i1 = 0; i1 < 4; i1++, j++) {
        if (code[11] & (1 << j)) {
            bits |= 1 << i1;
        }
    }
    code[0] = 0;
    code[1] = 0;
    code[2] = 0;
    code[3] = 0;
    sum += bits;
    k = 0;
    for (i2 = 0; i2 < 4; i2++) {
        for (j = 0; j < 8; j++, k++) {
            if (sum & (1 << k)) {
                code[i2] |= 1 << j;
            }
        }
    }
    code[5] = rec[12];
    code[6] = rec[13];
    sw = code[0];
    code[0] = code[8];
    code[8] = sw;
    sw = code[5];
    code[5] = code[10];
    code[10] = sw;
    for (i = 0; i < 12; i++) {
        code[i] = password_value_bits_put(code[i], (s8)shift);
    }
    flags |= shift;
    code[11] = flags;
    x = 0;
    for (i = 0; i < 12; i++) {
        x ^= code[i];
    }
    code[7] = x;
    memset(D_002BADF0, 0, 12);
    memcpy(D_002BADF0, code, 12);
    password_bits_unpack();
    if (g_game_mode == 2) {
        memcpy(((u8 *)g_stored_ranking_texts) + D_0028EAFC * 0x1E, D_002BADD0, 0x1E);
    } else {
        memcpy(((u8 *)g_death_label_ranking_texts) + D_0028EAFC * 0x1E, D_002BADD0, 0x1E);
    }
    reg_d0.w = save_d0;
}


void name_entry_task(void) {
    u8 temp_a0;

    temp_a0 = *(u8 *)(reg_a5 + 3);
    if (temp_a0 == 0) {
        name_entry_task_begin(temp_a0, reg_a5);
        return;
    }
    if (temp_a0 == 2) {
        name_entry_task_finish(temp_a0, reg_a5);
        return;
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 4);
    if (reg_d0.b[0] == 0) {
        name_entry_task_finish(reg_d0.b[0], reg_a5);
        return;
    }
    if (reg_d0.b[0] == 3) {
        name_entry_p1_update(reg_d0.b[0], reg_a5);
        reg_d0.w = 3;
        name_entry_p2_update();
        return;
    }
    if (reg_d0.w & 1) {
        name_entry_p1_update(reg_d0.w, reg_a5);
        return;
    }
    if (reg_d0.w & 2) {
        name_entry_p2_update(reg_d0.w, reg_a5);
    }
}

extern u16 D_002BAE80[];

void name_entry_p1_update() {
    s32 input_get_p1_held();
    s32 input_get_p1_pressed();
    s32 temp_s6;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;

    reg_a4 = (u8 *)D_002BAE00;
    input_get_p1_held();
    *(u16 *)(reg_a4 + 0x34) = (u16) reg_d0.h[0];
    input_get_p1_pressed();
    *(u16 *)(reg_a4 + 0x36) = (u16) reg_d0.h[0];
    reg_d7.h[0] = *(u16 *)(reg_a4 + 2);
    if (reg_d7.h[0] != 0) {
        name_entry_side_update();
        return;
    }
    *(s16 *)(reg_a4 + 0x12) = 1;
    *(s16 *)(reg_a4 + 0x2C) = 0;
    *(s16 *)(reg_a4 + 0x2E) = 0;
    temp_s6 = (s32)reg_a0;
    temp_s0 = (s32)reg_a1;
    temp_s1 = (s32)reg_a2;
    temp_s2 = (s32)reg_a3;
    temp_s3 = (s32)reg_a4;
    temp_s4 = (s32)reg_a5;
    temp_s5 = (s32)reg_a6;
    name_entry_rank_find_p1();
    if (cond_flag != 0) {
        reg_a0 = (u8 *)temp_s6;
        reg_a1 = (u8 *)temp_s0;
        reg_a2 = (u8 *)temp_s1;
        reg_a3 = (u8 *)temp_s2;
        reg_a4 = (u8 *)temp_s3;
        reg_a5 = (u8 *)temp_s4;
        reg_a6 = (u8 *)temp_s5;
        name_entry_side_done();
        return;
    }
    name_entry_side_setup();
    reg_a0 = (u8 *)temp_s6;
    reg_a1 = (u8 *)temp_s0;
    reg_a2 = (u8 *)temp_s1;
    reg_a3 = (u8 *)temp_s2;
    reg_a4 = (u8 *)temp_s3;
    reg_a5 = (u8 *)temp_s4;
    reg_a6 = (u8 *)temp_s5;
    if (D_002BAE80[0] != 0) {
        name_entry_side_update();
        return;
    }
    name_entry_side_begin();
}

extern u8 name_entry_p2_update_buffer[];

void name_entry_p2_update() {
    s32 input_get_p2_held();
    s32 input_get_p2_pressed();
    s32 temp_s6;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;

    reg_a4 = (u8 *)name_entry_p2_update_buffer;
    input_get_p2_held();
    *(u16 *)(reg_a4 + 0x34) = (u16) reg_d0.h[0];
    input_get_p2_pressed();
    *(u16 *)(reg_a4 + 0x36) = (u16) reg_d0.h[0];
    reg_d7.h[0] = *(u16 *)(reg_a4 + 2);
    if (reg_d7.h[0] != 0) {
        name_entry_side_update();
        return;
    }
    *(s16 *)(reg_a4 + 0x12) = 2;
    *(s16 *)(reg_a4 + 0x2C) = 1;
    *(s16 *)(reg_a4 + 0x2E) = 0;
    temp_s6 = (s32)reg_a0;
    temp_s0 = (s32)reg_a1;
    temp_s1 = (s32)reg_a2;
    temp_s2 = (s32)reg_a3;
    temp_s3 = (s32)reg_a4;
    temp_s4 = (s32)reg_a5;
    temp_s5 = (s32)reg_a6;
    name_entry_rank_find_p2();
    if (cond_flag != 0) {
        reg_a0 = (u8 *)temp_s6;
        reg_a1 = (u8 *)temp_s0;
        reg_a2 = (u8 *)temp_s1;
        reg_a3 = (u8 *)temp_s2;
        reg_a4 = (u8 *)temp_s3;
        reg_a5 = (u8 *)temp_s4;
        reg_a6 = (u8 *)temp_s5;
        name_entry_side_done();
        return;
    }
    name_entry_side_setup();
    reg_a0 = (u8 *)temp_s6;
    reg_a1 = (u8 *)temp_s0;
    reg_a2 = (u8 *)temp_s1;
    reg_a3 = (u8 *)temp_s2;
    reg_a4 = (u8 *)temp_s3;
    reg_a5 = (u8 *)temp_s4;
    reg_a6 = (u8 *)temp_s5;
    if (D_002BAE80[0] != 0) {
        name_entry_side_update();
        return;
    }
    name_entry_side_begin();
}

s32 fade_in_and_release();
extern u8 name_entry_side_begin_table[];

void name_entry_side_begin() {
    *(s16 *)(reg_a4 + 0x2E) = 1;
    ((s16 *)D_002BAE80)[0] = 1;
    reg_a0 = name_entry_side_begin_table;
    fade_in_and_release();
    name_entry_side_update();
}

s32 fade_to_black_and_release();
s32 sfx_confirm();
extern u8 name_entry_side_update_table[];
extern u8 name_entry_side_update_table_2[];
extern u8 D_002BAE82[];

#define W(o) (*(u16 *)(reg_a4 + (o)))
#define L(p, o) (*(u32 *)((p) + (o)))

void name_entry_side_update(void) {
    u8 *ptr;

    if (W(0x2E) == 0) goto next_1;
    name_entry_letter_board_draw();
next_1:
    reg_d0.b[0] = reg_a5[4];
    if (reg_d0.b[0] != 3) {
        if (reg_d0.w & 1) {
            name_entry_cover_draw_p2();
        } else if (reg_d0.w & 2) {
            name_entry_cover_draw_p1();
        }
    }
    name_entry_score_draw();
    name_entry_player_and_rank_draw();
    if (W(0x1E) == 0) goto block_count;
    name_entry_name_draw();
    if (((u16 *)D_002BAE82)[0] != 0) return;
    if (W(0x2E) == 0) return;
    if (W(0x1E) != 0x30) goto next_4;
    W(0x1E) -= 1;
    reg_a0 = (u8 *)name_entry_side_update_table_2;
    fade_to_black_and_release();
    return;
next_4:
    W(0x1E) -= 1;
    if (W(0x1E) != 0) goto next_5;
    reg_a5[3] = 2;
    return;
next_5:
    if (W(0x1E) == 0x30) {
        reg_d2.w = 0x20;
    }
    return;
block_count:
    W(2) += 1;
    reg_d7.h[0] = W(2);
    if (reg_d7.h[0] >= 0x30) goto next_6;
    name_entry_name_draw();
    return;
next_6:
    if (reg_d7.h[0] >= 0x738) goto block_fill;
    reg_d0.w = 0xF;
    reg_d0.h[0] &= W(0x36);
    if (reg_d0.h[0] != 0) goto next_7;
    if (reg_a4[0x21] == 0) goto next_8;
    reg_a4[0x20] -= 1;
    if (reg_a4[0x20] != 0) goto next_8;
    name_entry_cursor_move();
    goto next_8;
next_7:
    W(0x14) = 0;
    name_entry_lever_input();
next_8:
    name_entry_cursor_draw();
    name_entry_name_draw();
    reg_d0.h[0] = W(0x36);
    if (!(reg_d0.w & 0x8000)) goto next_9;
    sfx_confirm();
    if (W(0x16) != 0) goto block_fill;
block_default:
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_a1 = reg_a0;
    ptr = reg_a1;
    L(ptr, 0) = 0xC;
    L(ptr, 4) = 0xC;
    L(ptr, 8) = 0x3C;
    reg_a1 = ptr + 0xC;
    W(0x16) = 3;
    goto block_copy;
next_9:
    reg_d0.h[0] = W(0x36);
    reg_d3.w = 0x20;
    reg_d3.h[0] &= reg_d0.h[0];
    if (reg_d3.h[0] != 0) goto next_12;
    reg_d0.h[0] &= 0x50;
    if (reg_d0.h[0] == 0) return;
    sfx_confirm();
    reg_d0.h[0] = W(0x18);
    if (reg_d0.h[0] < 27) goto next_13;
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
loop_10:
    reg_d0.w = 0x70;
loop_11:
    reg_d1.h[0] = W(0x16);
    L(reg_a0, reg_d1.h[0] * 4) = reg_d0.w;
    W(0x16) += 1;
    if (W(0x16) != 3) goto loop_11;
    goto block_check;
block_fill:
    reg_d0.h[0] = W(0x18);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = W(0x16);
    if (W(0x18) < 27) goto next_14;
    reg_d0.w = 0;
    goto block_default;
next_14:
    L(reg_a0, reg_d1.h[0] * 4) = reg_d0.w;
    W(0x16) += 1;
    if (W(0x16) != 3) goto loop_10;
    goto block_check;
next_12:
    reg_d1.w = 0;
    reg_d1.h[0] = W(0x16);
    if (reg_d1.h[0] == 0) return;
    W(0x16) -= 1;
    reg_d1.h[0] = W(0x16);
    reg_d0.w = 0;
    goto block_store;
next_13:
    reg_d1.h[0] = W(0x16);
    W(0x16) += 1;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
block_store:
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    L(reg_a0, reg_d1.h[0] * 4) = reg_d0.w;
    if (W(0x16) < 3) return;
block_check:
    reg_a1 = (u8 *)name_entry_side_update_table;
loop_15:
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[1] = *(u16 *)(reg_a1 + 0);
    reg_d0.h[0] = *(u16 *)(reg_a1 + 2);
    if (reg_d0.w == 0xFFFFFFFF) goto block_copy;
    reg_tmp.w = L(reg_a0, 0);
    if (reg_tmp.w != reg_d0.w) goto next_16;
    reg_d0.h[1] = *(u16 *)(reg_a1 + 4);
    reg_d0.h[0] = *(u16 *)(reg_a1 + 6);
    reg_tmp.w = L(reg_a0, 4);
    if (reg_tmp.w != reg_d0.w) goto next_16;
    reg_d0.h[1] = *(u16 *)(reg_a1 + 8);
    reg_d0.h[0] = *(u16 *)(reg_a1 + 0xA);
    reg_tmp.w = L(reg_a0, 8);
    if (reg_tmp.w == reg_d0.w) goto block_default;
next_16:
    reg_a1 += 0xC;
    goto loop_15;
block_copy:
    name_entry_name_copy_to_own_ranks();
    reg_d1.h[0] = W(0x12);
    *(u8 *)((u16 *)D_002BAE82) &= ~(1 << reg_d1.sb[0]);
    W(0x1E) = 0x70;
    reg_d0.w = 0;
    W(0x1A) = reg_d0.h[1];
    W(0x1C) = reg_d0.h[0];
    name_entry_name_draw();
}

void name_entry_side_done(void) {
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x2C);
    *(u8 *)(reg_a5 + 4) &= (~(1 << (s8) reg_d0.b[0]) & 0xFF);
    if (*(u8 *)(reg_a5 + 4) == 0) {
        *(s8 *)(reg_a5 + 3) = 2;
    }
}


void name_entry_rank_find_p1(void) {
    reg_d0.w = 0xFF;
    name_entry_rank_find();
}

void name_entry_rank_find_p2(void) {
    reg_d0.w = 0xFE;
    name_entry_rank_find();
}



void name_entry_rank_find(void) {
    u32 tmp;

    cond_flag = 0;
    reg_d4.w = 4;
    reg_d1.w = 0;
    reg_a0 = (u8 *)((s32 *)g_ranking_names);
loop_1:
    if (*(u32 *)reg_a0 != reg_d0.w) {
        reg_a0 += 0xC;
        reg_d1.h[0] += 1;
        tmp = reg_d4.h[0] - 1;
        reg_d4.h[0] = tmp;
        if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
        reg_d0.w = 0;
        cond_flag = 1;
        reg_d0.h[0] -= 1;
        return;
    }
    reg_a2 = (u8 *)((u16 *)g_ranking_continues);
    reg_d0.h[0] = reg_d1.h[0];
    reg_a3 = (u8 *)((u16 *)g_ranking_score_tops);
    reg_a5 = (u8 *)((u16 *)g_ranking_ship_types);
    reg_a6 = (u8 *)((u16 *)g_ranking_power_styles);
    reg_d0.h[0] += reg_d0.h[0];
    reg_a2 += reg_d0.h[0];
    reg_a3 += reg_d0.h[0];
    reg_a5 += reg_d0.h[0];
    reg_a6 += reg_d0.h[0];
    reg_d2.h[0] = *(u16 *)reg_a3;
    reg_tmp.w = reg_d2.w;
    reg_d2.h[1] = reg_tmp.h[0];
    reg_d2.h[0] = reg_tmp.h[1];
    reg_d2.h[0] = *(u16 *)reg_a2;
    reg_d3.h[0] = ENTITY(reg_a6)->flags.h;
    reg_tmp.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp.h[0];
    reg_d3.h[0] = reg_tmp.h[1];
    reg_d3.h[0] = *(u16 *)reg_a5;
    reg_a2 = (u8 *)((u16 *)g_ranking_loops);
    reg_a3 = (u8 *)((u16 *)g_ranking_hits);
    reg_a2 += reg_d0.h[0];
    reg_a3 += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *)((u8 *)g_ranking_scores);
    reg_a1 += reg_d0.h[0];
}

#pragma push
#pragma opt_common_subs off
extern u8 name_entry_side_setup_table[];
extern u8 name_entry_side_setup_table_2[];
extern u8 D_002BAE82[];

void name_entry_side_setup(void) {
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a4 + 0x30) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x32) = (u16) reg_tmp.h[0];
    *(u16 *)(reg_a4 + 0xC) = (u16) *(u16 *)reg_a1;
    *(u16 *)(reg_a4 + 0xE) = (u16) *(u16 *)(reg_a1 + 2);
    *(u16 *)(reg_a4 + 0xA) = (u16) reg_d2.h[0];
    reg_tmp.w = reg_d2.w;
    reg_d2.h[1] = reg_tmp.h[0];
    reg_d2.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x10) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a4 + 0x38) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a4 + 0x3A) = (u16) reg_d3.h[0];
    reg_tmp.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp.h[0];
    reg_d3.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x3C) = (u16) reg_d3.h[0];
    reg_d0.w = 1;
    reg_a0 = (u8 *)((u32) name_entry_side_setup_table);
    if (*(u16 *)(reg_a4 + 0x2C) != 0) {
        reg_d0.w = 2;
        reg_a0 = (u8 *)((u32) name_entry_side_setup_table_2);
    }
    D_002BAE82[0] |= (1 << (s8) reg_d0.b[0]) & 0xFF;
    *(u16 *)(reg_a4 + 6) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 8) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x14) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x16) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x18) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x1E) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x20) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x22) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x24) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x26) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x28) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x2A) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
}
#pragma pop


void name_entry_name_copy_to_own_ranks(void) {
    u32 t;
    u8 *p;
    u8 *q;

    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x2C);
    reg_d0.b[0] = ~(s8) reg_d0.b[0];
    reg_d5.w = 4;
    reg_a1 = (u8 *)(((u32 *)g_ranking_names));
loop_1:
    reg_tmp.w = *(u32 *)reg_a1;
    if (reg_tmp.w != reg_d0.w) goto next_2;
    reg_a2 = (u8 *)(reg_a0);
    reg_d7.h[0] = 2;
loop_2:
    p = reg_a2;
    q = reg_a1;
    *(u32 *)q = *(u32 *)p;
    reg_a1 = q + 4;
    reg_a2 = p + 4;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    goto next_3;
next_2:
    reg_a1 += 0xC;
next_3:
    t = reg_d5.h[0] - 1;
    reg_d5.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
}

s32 sprite_draw_layer4_keep();
s32 sprite_draw_layer4_zoom_keep();
extern u8 name_entry_name_draw_table[];

void name_entry_name_draw(void) {
    u32 temp_a1;

    reg_d1.h[0] = 0x4840;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[0] = 0x380;
    reg_d1.h[1] = reg_tmp.h[0];
    if (*(u16 *)(reg_a4 + 0x2C) != 0) {
        reg_d1.h[0] = 0x2240;
    }
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = 4;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0x30);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x32);
    reg_a0 = (u8 *)(reg_tmp.w);
    reg_d7.h[0] = *(u16 *)(reg_a4 + 0x16);
    if (reg_d7.h[0] != 0) {
        reg_d7.h[0] -= 1;
        do {
            temp_a1 = *(u32 *)reg_a0;
            reg_d0.w = temp_a1;
            reg_a0 += 4;
            reg_a1 = (u8 *)name_entry_name_draw_table;
            reg_a1 += reg_d0.h[0];
            reg_d2.h[1] = *(u16 *)reg_a1;
            reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d6.w = 0x40004000;
            sprite_draw_layer4_zoom_keep();
            reg_d1.h[0] += 0x600;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    if (*(u16 *)(reg_a4 + 0x16) != 3) {
        reg_a1 = (u8 *)name_entry_name_draw_table;
        reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
        reg_d2.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
        sprite_draw_layer4_keep();
        if ((s32) *(u16 *)(reg_a4 + 0x16) < 2) {
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x3E);
            *(u16 *)(reg_a4 + 0x3E) += 4;
            if (reg_d0.h[0] == 0x68) {
                *(u16 *)(reg_a4 + 0x3E) = 0U;
            }
            reg_a1 = (u8 *)name_entry_name_draw_table;
            reg_d7.h[0] = 1;
            reg_d7.h[0] -= *(u16 *)(reg_a4 + 0x16);
            do {
                reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d1.h[0] += 0x600;
                reg_d6.w = 0x40004000;
                sprite_draw_layer4_zoom_keep();
                reg_d0.h[0] += 0x34;
                if ((s32) reg_d0.h[0] >= 0x6C) {
                    reg_d0.h[0] -= 0x6C;
                }
            } while ((s16)(--reg_d7.h[0]) >= 0);
        }
    }
}

s32 sprite_draw_layer2_keep();
s32 sprite_draw_layer3_keep();
extern u16 name_entry_cursor_draw_table[];
extern u16 name_entry_cursor_draw_table_2[];
extern u16 name_entry_cursor_draw_table_3[];
extern u16 name_entry_cursor_draw_table_4[];
extern u16 name_entry_cursor_draw_table_5[];
extern u16 name_entry_cursor_draw_table_6[];

void name_entry_cursor_draw(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a1_3;
    u16 temp_a2;
    u16 temp_a3;
    u16 temp_a3_2;
    u32 temp_a1;
    u32 temp_a1_2;
    u32 temp_a2_2;

    *(u8 *)(reg_a4 + 0x23) -= 1;
    if (0 > (s64)*(s8 *)(reg_a4 + 0x23)) {
        *(u8 *)(reg_a4 + 0x23) = (u8) *(u8 *)(reg_a4 + 0x22);
        *(u16 *)(reg_a4 + 0x24) -= 4;
        if (0 > (s16) *(u16 *)(reg_a4 + 0x24)) {
            *(u16 *)(reg_a4 + 0x24) = 0xCU;
        }
    }
    do {
        *(u8 *)(reg_a4 + 0x27) -= 1;
    } while (0 <= (s64)*(s8 *)(reg_a4 + 0x27));
    *(u8 *)(reg_a4 + 0x27) = (u8) *(u8 *)(reg_a4 + 0x26);
    *(u16 *)(reg_a4 + 0x28) -= 8;
    if (0 > (s16) *(u16 *)(reg_a4 + 0x28)) {
        *(u16 *)(reg_a4 + 0x28) = 0x18U;
    }
    reg_d7.h[1] = *(u16 *)(reg_a4 + 6);
    reg_d7.h[0] = *(u16 *)(reg_a4 + 8);
    reg_a0 = (u8 *)(name_entry_cursor_draw_table);
    reg_a1 = (u8 *)(name_entry_cursor_draw_table_3);
    reg_a2 = (u8 *)(name_entry_cursor_draw_table_5);
    if (*(u16 *)(reg_a4 + 0x2C) != 0) {
        reg_a0 = (u8 *)(name_entry_cursor_draw_table_2);
        reg_a1 = (u8 *)(name_entry_cursor_draw_table_4);
        reg_a2 = (u8 *)(name_entry_cursor_draw_table_6);
    }
    reg_d4.h[0] = 5;
    reg_d1.w = reg_d7.w;
    temp_a1 = reg_d1.w;
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a2 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a2;
    reg_a2 += 2;
    reg_d1.w = temp_a1 + reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x28);
    reg_a1 += reg_d0.h[0];
    reg_d2.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    temp_a0 = *(u16 *)reg_a1;
    reg_d2.h[0] = temp_a0;
    reg_a1 += 2;
    reg_d3.h[0] = 0x3808;
    sprite_draw_layer2_keep();
    reg_d1.w = reg_d7.w;
    temp_a3 = *(u16 *)reg_a2;
    temp_a2_2 = reg_d1.w;
    reg_a2 += 2;
    reg_tmp.h[1] = temp_a3;
    temp_a3_2 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a3_2;
    reg_a2 += 2;
    temp_a1_2 = temp_a2_2 + reg_tmp.w;
    reg_d1.w = temp_a1_2;
    temp_a0_2 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d2.h[1] = temp_a0_2;
    temp_a0_3 = *(u16 *)reg_a1;
    reg_d2.h[0] = temp_a0_3;
    reg_a1 += 2;
    reg_d3.h[0] = 0x3C0;
    sprite_draw_layer2_keep();
    reg_d1.w = reg_d7.w;
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a1_3 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a1_3;
    reg_a2 += 2;
    reg_d1.w += reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x24);
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x620;
    sprite_draw_layer3_keep();
}

extern u16 name_entry_score_draw_table[];

void name_entry_score_draw(void) {
    u32 t;

    reg_d1.h[0] = 0x4040;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[0] = 0x1540;
    reg_d1.h[1] = reg_tmp.h[0];
    switch (*(u16 *)(reg_a4 + 0x2C)) {
    case 0:
        goto next_1;
    }
    reg_d1.h[0] = 0x3300;
next_1:
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 4;
    reg_a0 = (u8 *)(name_entry_score_draw_table);
    reg_d2.w = 0xF;
    reg_d2.h[0] &= *(u16 *)(reg_a4 + 0xA);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.w += 0x147C;
    sprite_draw_layer4_keep();
    reg_d1.h[0] -= 0x200;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
    reg_d7.w = 7;
loop_1:
    reg_d2.w = 0xF;
    reg_d2.h[0] &= reg_d0.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.w += 0x147C;
    sprite_draw_layer4_keep();
    reg_d1.h[0] -= 0x200;
    reg_d0.w >>= 4;
    if (reg_d0.w == 0) goto next_2;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_2:
    reg_d7.h[0] -= 1;
    if (*(u16 *)(reg_a4 + 0x10) == 0) return;
    if (!(0 > (s16) reg_d7.h[0])) goto loop_1;
    reg_d2.w = 0xF;
    reg_d2.h[0] &= *(u16 *)(reg_a4 + 0x10);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.w += 0x147C;
    sprite_draw_layer4_keep();
}

extern u16 name_entry_player_and_rank_draw_table[];

void name_entry_player_and_rank_draw(void) {
    reg_d1.h[0] = 0x5200;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[0] = 0xC00;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d2.w = 0x144C;
    reg_d7.h[0] = 0x5200;
    reg_tmp.w = reg_d7.w;
    reg_d7.h[0] = 0x440;
    reg_d7.h[1] = reg_tmp.h[0];
    if (*(u16 *)(reg_a4 + 0x2C) == 0) goto next_1;
    reg_d1.h[0] = 0x2240;
    reg_d2.w = 0x144D;
    reg_d7.h[0] = 0x2D40;
next_1:
    reg_d3.h[0] = 0x228;
    reg_d4.h[0] = 5;
    sprite_draw_layer3_keep();
    reg_d1.w = reg_d7.w;
    reg_d2.h[0] = *(u16 *)(reg_a4 + 0x38);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)(name_entry_player_and_rank_draw_table);
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x218;
    reg_d4.h[0] = 4;
    sprite_draw_layer4_keep();
}

s32 sprite_draw_layer1();
s32 sprite_draw_layer3();
s32 sprite_draw_layer4();
void name_entry_letter_board_draw(void) {
    reg_d1.w = 0x2A001C00;
    reg_d1.w += 0xEE00EA00;
    reg_d2.w = 0x145A;
    reg_d3.h[0] = 0x12B0;
    reg_d4.h[0] = 4;
    sprite_draw_layer1();
    reg_d1.w = 0x38001C00;
    reg_d1.w += 0xC800E400;
    reg_d2.w = 0x1457;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 2;
    sprite_draw_layer3();
    reg_d1.w = 0x38001C00;
    reg_d1.w += 0xC800E400;
    reg_d2.w = 0x1486;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 3;
    sprite_draw_layer4();
    reg_d1.w = 0x62801C40;
    reg_d1.w += 0xFA00EA00;
    reg_d2.w = 0x1454;
    reg_d3.h[0] = 0x6B0;
    reg_d4.h[0] = 4;
    sprite_draw_layer4();
}

void name_entry_cover_draw_p1(void) {
    reg_d1.w = 0x4E800C80;
    reg_d1.w += 0xF600F500;
    reg_d2.w = 0x1455;
    reg_d3.h[0] = 0xA58;
    reg_d4.h[0] = 3;
    sprite_draw_layer4();
    reg_d1.w = 0x42000D00;
    reg_d1.w += 0xFC00F500;
    reg_d2.w = 0x1456;
    reg_d3.h[0] = 0x458;
    reg_d4.h[0] = 3;
    sprite_draw_layer4();
}

void name_entry_cover_draw_p2(void) {
    reg_d1.w = 0x4E802B80;
    reg_d1.w += 0xF600F500;
    reg_d2.w = 0x1455;
    reg_d3.h[0] = 0xA58;
    reg_d4.h[0] = 0x43;
    sprite_draw_layer4();
    reg_d1.w = 0x42002B00;
    reg_d1.w += 0xFC00F500;
    reg_d2.w = 0x1456;
    reg_d3.h[0] = 0x458;
    reg_d4.h[0] = 0x43;
    sprite_draw_layer4();
}


void name_entry_lever_input(void) {
    if (*(u8 *)(reg_a4 + 0x21) == 1) {
        goto block_2;
    }
    if (!(reg_d0.w & 1)) {
        goto next_1;
    }
    *(u8 *)(reg_a4 + 0x21) = 1;
    *(u16 *)(reg_a4 + 0x2A) = 1;
    goto next_2;
next_1:
    if (!(reg_d0.w & 2)) {
        goto next_2;
    }
    *(u8 *)(reg_a4 + 0x21) = 1;
    *(u16 *)(reg_a4 + 0x2A) = 2;
next_2:
    if (!(reg_d0.w & 4)) {
        goto next_3;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 4;
    goto next_4;
next_3:
    if (!(reg_d0.w & 8)) {
        goto next_4;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 8;
next_4:
    if (*(u8 *)(reg_a4 + 0x21) == 2) {
        name_entry_cursor_move();
        return;
    }
    *(u8 *)(reg_a4 + 0x20) = 4;
    return;
block_2:
    *(u8 *)(reg_a4 + 0x20) -= 1;
    if (*(u8 *)(reg_a4 + 0x20) == 0) {
        name_entry_cursor_move();
        return;
    }
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x2A);
    if (reg_d1.h[0] == 1) {
        goto next_5;
    }
    if (reg_d1.h[0] != 2) {
        goto next_7;
    }
next_5:
    if (!(reg_d0.w & 4)) {
        goto next_6;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 4;
    name_entry_cursor_move();
    return;
next_6:
    if (!(reg_d0.w & 8)) {
        goto next_4;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 8;
    name_entry_cursor_move();
    return;
next_7:
    if (reg_d1.h[0] == 4) {
        goto next_8;
    }
    if (reg_d1.h[0] == 8) {
        goto next_8;
    }
block_rts:
    return;
next_8:
    if (!(reg_d0.w & 1)) {
        goto next_9;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 1;
    name_entry_cursor_move();
    return;
next_9:
    if (!(reg_d0.w & 2)) {
        goto block_rts;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 2;
    name_entry_cursor_move();
}

s32 sfx_cursor_move();
extern u16 name_entry_cursor_move_table[];

void name_entry_cursor_move(void) {
    u32 t;
    u32 t1;
    *(s8 *)(reg_a4 + 0x21) = 0;
    *(s8 *)(reg_a4 + 0x20) = 0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
    reg_a0 = (u8 *)(name_entry_letter_table);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    t = reg_d0.h[0];
    reg_tmp.h[1] = (t != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)t & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)t + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)t + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x2A);
    *(u16 *)(reg_a4 + 0x2A) = 0U;
    reg_d0.h[0] -= 1;
    if (!(0 > (s16)(reg_d0.h[0])) && ((reg_d0.h[0] & 0xFFFF) < 0xA)) {
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        t1 = reg_d0.h[0];
        if (!(0 > (s16)(t1))) {
            *(u16 *)(reg_a4 + 0x18) = t1;
            reg_a0 = (u8 *)(name_entry_cursor_move_table);
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            *(u16 *)(reg_a4 + 6) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
            *(u16 *)(reg_a4 + 8) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            sfx_cursor_move();
        }
    }
}

/* .bss (the compiler lays these out in reverse) */
u16 D_002BAE80[8];
u8 name_entry_p2_update_buffer[64];
u8 D_002BAE00[64];
u8 D_002BADF0[16];
u8 D_002BADD0[32];
u8 password_bits_unpack_buffer_2[96];
u8 password_bits_unpack_buffer[32];
