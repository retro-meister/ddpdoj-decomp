#include "common.h"
#include "pad.h"

extern char settings_notice_rank_easy[];
extern char settings_notice_rank_normal[];
extern char settings_notice_rank_hard[];
extern char settings_notice_rank_very_hard[];
extern char settings_notice_extend_a[][32];
extern char settings_notice_extend_b[][32];
extern char settings_notice_extend_c[][32];
extern char settings_notice_extend_none[][32];

u16 settings_notice_objects[4][8] = {
    { 0xF00, 0x600, 0, 0, 0, 0xE8, 0x8000, 0x8000 },
    { 0xF00, 0x800, 0, 0, 0, 0xE9, 0x8000, 0x8000 },
    { 0xF80, 0x700, 0, 0, 0, 0x123, 0x4000, 0x4000 },
    { 0xFFFF, 0xFFFF, 0, 0, 0, 0, 0, 0 },
};

u32 settings_notice_sprites[60][2] = {
    { 0x0F000700, 0x0028 },
    { 0x0F000900, 0x0043 },
    { 0x0F000B00, 0x0029 },
    { 0x0F000D00, 0x0032 },
    { 0x0F000F00, 0x0030 },
    { 0x0F001100, 0x0030 },
    { 0x0F001300, 0x0032 },
    { 0x0F001700, 0x0043 },
    { 0x0F001900, 0x0041 },
    { 0x0F001B00, 0x0056 },
    { 0x0F001D00, 0x0045 },
    { 0x0F002100, 0x0043 },
    { 0x0F002300, 0x004F },
    { 0x0F002500, 0x002E },
    { 0x0F002700, 0x002C },
    { 0x0F002900, 0x004C },
    { 0x0F002B00, 0x0054 },
    { 0x0F002D00, 0x0044 },
    { 0x0F002F00, 0x002E },
    { 0x0C000100, 0x0050 },
    { 0x0C000300, 0x0055 },
    { 0x0C000500, 0x0042 },
    { 0x0C000700, 0x004C },
    { 0x0C000900, 0x0049 },
    { 0x0C000B00, 0x0053 },
    { 0x0C000D00, 0x0048 },
    { 0x0C000F00, 0x0049 },
    { 0x0C001100, 0x004E },
    { 0x0C001300, 0x0047 },
    { 0x0C001700, 0x0041 },
    { 0x0C001900, 0x004E },
    { 0x0C001B00, 0x0044 },
    { 0x0C001F00, 0x0044 },
    { 0x0C002100, 0x0049 },
    { 0x0C002300, 0x0053 },
    { 0x0C002500, 0x0054 },
    { 0x0C002700, 0x0052 },
    { 0x0C002900, 0x0049 },
    { 0x0C002B00, 0x0042 },
    { 0x0C002D00, 0x0055 },
    { 0x0C002F00, 0x0054 },
    { 0x0C003100, 0x0049 },
    { 0x0C003300, 0x004F },
    { 0x0C003500, 0x004E },
    { 0x09000D00, 0x0042 },
    { 0x09000F00, 0x0059 },
    { 0x09001300, 0x0041 },
    { 0x09001500, 0x0052 },
    { 0x09001700, 0x0049 },
    { 0x09001900, 0x004B },
    { 0x09001B00, 0x0041 },
    { 0x09001F00, 0x0043 },
    { 0x09002100, 0x004F },
    { 0x09002300, 0x002E },
    { 0x09002500, 0x002C },
    { 0x09002700, 0x004C },
    { 0x09002900, 0x0054 },
    { 0x09002B00, 0x0044 },
    { 0x09002D00, 0x002E },
    { 0xFFFFFFFF, 0x0000 },
};

u16 settings_notice_fade_palettes[32] = {
    0x0004, 0x0000, 0x0000, 0x0000, 0x0004, 0x0005, 0x001F, 0x0006,
    0x0000, 0x0000, 0x0040, 0x000B, 0x000C, 0x001F, 0x0006, 0x0000,
    0x0000, 0x0080, 0x0012, 0x0013, 0x001F, 0x0006, 0x0000, 0x0008,
    0x0000, 0x0019, 0x001A, 0x001F, 0x0006, 0x0000, 0x0000, 0x0000,
};

u16 settings_notice_fade_palettes_b[24] = {
    0x0004, 0x0000, 0x0000, 0x001F, 0x0006, 0x0000, 0x0040, 0x001F,
    0x0006, 0x0000, 0x0080, 0x001F, 0x0006, 0x0008, 0x0000, 0x001F,
    0x0006, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

char *settings_notice_rank_texts[4] = {
    settings_notice_rank_easy,
    settings_notice_rank_normal,
    settings_notice_rank_hard,
    settings_notice_rank_very_hard,
};

char settings_notice_rank_easy[32] = "         RANK: EASY         ";

char settings_notice_rank_normal[32] = "        RANK: NORMAL        ";

char settings_notice_rank_hard[32] = "         RANK: HARD         ";

char settings_notice_rank_very_hard[32] = "      RANK: VERY HARD       ";

char *settings_notice_extend_texts[4] = {
    settings_notice_extend_a[0],
    settings_notice_extend_b[0],
    settings_notice_extend_c[0],
    settings_notice_extend_none[0],
};

char settings_notice_extend_a[2][32] = {
    "      1ST 10000000PTS       ",
    "      2ND 30000000PTS       ",
};

char settings_notice_extend_b[2][32] = {
    "      1ST  50000000PTS      ",
    "      2ND 100000000PTS      ",
};

char settings_notice_extend_c[2][32] = {
    "      1ST  5000000PTS       ",
    "      2ND 20000000PTS       ",
};

char settings_notice_extend_none[2][32] = {
    "          NO EXTEND         ",
    "                            ",
};

#ifdef DEATH_LABEL
char settings_notice_rapid_fire[2][32] = {
    "                            ",
    "     C BUTTON FULL-AUTO     ",
};
#endif

void settings_notice_update_until_fade_out(void);
void settings_notice_draw(void);
void settings_notice_return_running(void);
void settings_notice_return_finished(void);
void settings_notice_palettes_load(void);
void settings_notice_draw_piece_0(void);
void settings_notice_draw_piece_1(void);
void settings_notice_draw_piece_2(void);
void settings_notice_draw_piece_3(void);
void settings_notice_draw_piece_4(void);
void settings_notice_print_rank(void);
void settings_notice_print_extend(void);
void settings_notice_print_rapid_fire(void);
void enemy_remove_entry(void);

void layers_reset(void);
void bg_scroll_reset(void);
void bg_layer_clear(void);
extern u32 D_00268FB0[];
extern u8 g_bg_layer[16384];

void settings_notice_layers_setup(void) {
    u32 t1;

    bg_scroll_reset();
    bg_layer_clear();
    layers_reset();
    reg_tmp.w = 0;
    reg_a1 = (u8 *)D_00268FB0;
    reg_d6.w = 0xD;
    do {
        reg_a2 = (u8 *)((u32 *)g_bg_layer);
        reg_a2 += reg_tmp.w;
        reg_d7.w = 6;
    loop_1:
        reg_d4.w = *(u32 *)reg_a1;
        reg_a1 += 4;
        reg_d4.h[1] += 0xC00;
        *(u32 *)reg_a2 = reg_d4.w;
        reg_a2 += 0x100;
        t1 = reg_d7.h[0] - 1;
        reg_d7.h[0] = t1;
        if (((s64)((s64)(u16)t1 << 0x30) >> 0x30) >= 0) goto loop_1;
        reg_tmp.w += 4;
        reg_tmp.h[0] = reg_tmp.b[0];
    } while ((s16)(--reg_d6.h[0]) >= 0);
}

extern u32 g_settings_notice_fade;
extern s16 g_settings_notice_time;
extern u16 g_settings_notice_loaded;
extern u16 g_settings_notice_shown;
extern s16 D_0028E7D0;

void settings_notice_begin(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;

    g_settings_notice_time = 0xF0;
    save_d0 = reg_d0.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    g_settings_notice_fade = 0;
    save_d1 = reg_d1.w;
    g_settings_notice_loaded = 0;
    g_settings_notice_shown = 0;
    D_0028E7D0 = 0;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    settings_notice_layers_setup();
    settings_notice_print_rank();
    settings_notice_print_extend();
    settings_notice_print_rapid_fire();
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

s32 sprite_draw_keep();

void settings_notice_objects_draw() {
    u8 *var_s0;
    u32 temp_a0;
    u32 temp_a0_2;

    reg_a4 = (u8 *)settings_notice_objects;
    var_s0 = (u8 *)settings_notice_sprites;
loop_1:
    temp_a0 = (*(u32 *)((u8 *)(var_s0) + (0)));
    if (temp_a0 != -1U) {
        reg_d1.w = temp_a0;
        temp_a0_2 = (*(u32 *)((u8 *)(var_s0) + (4)));
        reg_d2.w = temp_a0_2;
        reg_d3.h[0] = 0x208;
        reg_d4.h[0] = 2;
        sprite_draw_keep();
        var_s0 += 8;
        goto loop_1;
    }
}


s32 fade_in();
s32 fade_release();
s32 fade_is_running();
extern u8 *D_0028DF48;
extern u8 *D_0028DF4C;
extern u8 *D_0028DF50;
extern u8 *D_0028DF54;
extern u8 *D_0028DF58;
extern u8 *D_0028DF5C;
extern u8 *D_0028DF60;
extern u32 D_0028DF64;
extern u32 D_0028DF68;
extern u32 D_0028DF6C;
extern u32 D_0028DF70;
extern u32 D_0028DF74;
extern u32 D_0028DF78;
extern u32 D_0028DF7C;
extern u32 D_0028DF80;
extern u32 g_settings_notice_fade;
extern u16 g_settings_notice_shown;
extern u8 g_settings_notice_fade_flags;

void settings_notice_update_with_fade_in(void) {
    D_0028DF80 = reg_d0.w;
    D_0028DF7C = reg_d1.w;
    D_0028DF78 = reg_d2.w;
    D_0028DF74 = reg_d3.w;
    D_0028DF70 = reg_d4.w;
    D_0028DF6C = reg_d5.w;
    D_0028DF68 = reg_d6.w;
    D_0028DF64 = reg_d7.w;
    D_0028DF60 = (u8 *)(reg_a0);
    D_0028DF5C = reg_a1;
    D_0028DF58 = reg_a2;
    D_0028DF54 = reg_a3;
    D_0028DF50 = reg_a4;
    D_0028DF4C = reg_a5;
    D_0028DF48 = reg_a6;
    if (!(g_settings_notice_fade_flags & 1)) {
        g_settings_notice_fade_flags |= 1;
        reg_a0 = (u8 *)settings_notice_fade_palettes;
        fade_in();
        g_settings_notice_fade = reg_d0.w;
    }
    if (!(g_settings_notice_fade_flags & 2)) {
        reg_d0.w = g_settings_notice_fade;
        fade_is_running();
        if (cond_flag == 0) {
            fade_release();
            reg_d0.w = 0;
            g_settings_notice_shown = 1;
            g_settings_notice_fade = reg_d0.w;
            g_settings_notice_fade_flags |= 2;
        }
    }
    if (g_settings_notice_shown == 0) {
        settings_notice_draw();
        return;
    }
    settings_notice_update_until_fade_out();
}

s32 palette_bank_a_load();
extern u8 D_002687B0[];
extern u16 g_settings_notice_loaded;

void settings_notice_draw_static(void) {
    D_0028DF80 = reg_d0.w;
    D_0028DF7C = reg_d1.w;
    D_0028DF78 = reg_d2.w;
    D_0028DF74 = reg_d3.w;
    D_0028DF70 = reg_d4.w;
    D_0028DF6C = reg_d5.w;
    D_0028DF68 = reg_d6.w;
    D_0028DF64 = reg_d7.w;
    D_0028DF60 = (u8 *)(reg_a0);
    D_0028DF5C = reg_a1;
    D_0028DF58 = reg_a2;
    D_0028DF54 = reg_a3;
    D_0028DF50 = reg_a4;
    D_0028DF4C = reg_a5;
    D_0028DF48 = reg_a6;
    if (g_settings_notice_loaded != 0) {
        settings_notice_draw();
        return;
    }
    reg_d0.h[0] = 0;
    g_settings_notice_loaded = 1;
    reg_a0 = (u8 *)D_002687B0;
    palette_bank_a_load();
    settings_notice_palettes_load();
    settings_notice_draw();
}

void settings_notice_graphics_load(void) {
    D_0028DF80 = reg_d0.w;
    D_0028DF7C = reg_d1.w;
    D_0028DF78 = reg_d2.w;
    D_0028DF74 = reg_d3.w;
    D_0028DF70 = reg_d4.w;
    D_0028DF6C = reg_d5.w;
    D_0028DF68 = reg_d6.w;
    D_0028DF64 = reg_d7.w;
    D_0028DF60 = reg_a0;
    D_0028DF5C = reg_a1;
    D_0028DF58 = reg_a2;
    D_0028DF54 = reg_a3;
    D_0028DF50 = reg_a4;
    D_0028DF4C = reg_a5;
    D_0028DF48 = reg_a6;
    reg_a0 = (u8 *)D_002687B0;
    reg_d0.h[0] = 0;
    palette_bank_a_load();
    settings_notice_palettes_load();
    reg_d0.w = D_0028DF80;
    reg_d1.w = D_0028DF7C;
    reg_d2.w = D_0028DF78;
    reg_d3.w = D_0028DF74;
    reg_d4.w = D_0028DF70;
    reg_d5.w = D_0028DF6C;
    reg_d6.w = D_0028DF68;
    reg_d7.w = D_0028DF64;
    reg_a0 = (u8 *)D_0028DF60;
    reg_a1 = (u8 *)D_0028DF5C;
    reg_a2 = (u8 *)D_0028DF58;
    reg_a3 = (u8 *)D_0028DF54;
    reg_a4 = (u8 *)D_0028DF50;
    reg_a5 = (u8 *)D_0028DF4C;
    reg_a6 = (u8 *)D_0028DF48;
}

#ifndef DEATH_LABEL
void settings_notice_update_timed(void) {
    D_0028DF80 = reg_d0.w;
    D_0028DF7C = reg_d1.w;
    D_0028DF78 = reg_d2.w;
    D_0028DF74 = reg_d3.w;
    D_0028DF70 = reg_d4.w;
    D_0028DF6C = reg_d5.w;
    D_0028DF68 = reg_d6.w;
    D_0028DF64 = reg_d7.w;
    D_0028DF60 = (u8 *)(reg_a0);
    D_0028DF5C = reg_a1;
    D_0028DF58 = reg_a2;
    D_0028DF54 = reg_a3;
    D_0028DF50 = reg_a4;
    D_0028DF4C = reg_a5;
    D_0028DF48 = reg_a6;
    if (g_settings_notice_loaded != 0) {
        settings_notice_update_until_fade_out();
        return;
    }
    reg_d0.h[0] = 0;
    g_settings_notice_loaded = 1;
    g_settings_notice_time = 0x258;
    reg_a0 = (u8 *)D_002687B0;
    palette_bank_a_load();
    settings_notice_palettes_load();
    settings_notice_draw();
}
#endif

s32 fade_to_black();                            /* extern */
s32 fade_release();                            /* extern */
s32 fade_is_running();                            /* extern */
extern u8 g_stage_load_state;

void settings_notice_update_until_fade_out(void) {
    if ((u16)g_settings_notice_time != 0) {
        if (g_stage_load_state == 0) {
            (*(u16 *)&g_settings_notice_time) -= 1;
        }
        if (g_pad_held[2] != 0) {
            g_settings_notice_time = 0x258;
        }
        if ((u16)g_settings_notice_time != 0) {
            settings_notice_draw();
            return;
        }
        reg_a0 = (u8 *)settings_notice_fade_palettes_b;
        fade_to_black();
        g_settings_notice_fade = reg_d0.w;
        settings_notice_draw();
        return;
    }
    reg_d0.w = g_settings_notice_fade;
    fade_is_running();
    if (cond_flag != 0) {
        settings_notice_draw();
        return;
    }
    fade_release();
    settings_notice_return_finished();
}


void settings_notice_draw(void) {
    settings_notice_draw_piece_1();
    settings_notice_draw_piece_0();
    settings_notice_draw_piece_2();
    settings_notice_draw_piece_3();
    settings_notice_draw_piece_4();
    settings_notice_objects_draw();
    settings_notice_return_running();
}

void settings_notice_return_running(void) {
    reg_d0.w = D_0028DF80;
    reg_d1.w = D_0028DF7C;
    reg_d2.w = D_0028DF78;
    reg_d3.w = D_0028DF74;
    reg_d4.w = D_0028DF70;
    reg_d5.w = D_0028DF6C;
    reg_d6.w = D_0028DF68;
    reg_d7.w = D_0028DF64;
    reg_a0 = (u8 *)D_0028DF60;
    reg_a1 = (u8 *)D_0028DF5C;
    reg_a2 = (u8 *)D_0028DF58;
    reg_a3 = (u8 *)D_0028DF54;
    reg_a4 = (u8 *)D_0028DF50;
    reg_a5 = (u8 *)D_0028DF4C;
    reg_a6 = (u8 *)D_0028DF48;
    cond_flag = 1;
}








void settings_notice_return_finished(void) {
    reg_d0.w = D_0028DF80;
    reg_d1.w = D_0028DF7C;
    reg_d2.w = D_0028DF78;
    reg_d3.w = D_0028DF74;
    reg_d4.w = D_0028DF70;
    reg_d5.w = D_0028DF6C;
    reg_d6.w = D_0028DF68;
    reg_d7.w = D_0028DF64;
    reg_a0 = (u8 *)(*(s32 *)&D_0028DF60);
    reg_a1 = (u8 *)(*(s32 *)&D_0028DF5C);
    reg_a2 = (u8 *)(*(s32 *)&D_0028DF58);
    reg_a3 = (u8 *)(*(s32 *)&D_0028DF54);
    reg_a4 = (u8 *)(*(s32 *)&D_0028DF50);
    reg_a5 = (u8 *)(*(s32 *)&D_0028DF4C);
    reg_a6 = (u8 *)(*(s32 *)&D_0028DF48);
    cond_flag = 0;
}

extern u8 D_0025F770[];
extern u8 D_002623F0[];
extern u8 D_00262430[];

extern void sprite_palette_load(void);

void settings_notice_palettes_load(void)
{
    reg_a0 = D_00262430;
    reg_d0.h[0] = 0;
    sprite_palette_load();

    reg_a0 = D_002623F0;
    reg_d0.h[0] = 1;
    sprite_palette_load();

    reg_a0 = D_0025F770;
    reg_d0.h[0] = 2;
    sprite_palette_load();
}

extern void sprite_draw(void);
void settings_notice_draw_piece_0(void) {
    reg_d1.w = 0x0E000200;
    reg_d2.sw = 0x155C;
    reg_d4.sh[0] = 0;
    reg_d3.sh[0] = 0x30C0;
    sprite_draw();
}

extern Reg32 reg_d1;
void sprite_draw(void);

void settings_notice_draw_piece_1(void) {
    reg_d1.w = 0x1A000800;
    reg_d2.sw = 0x155A;
    reg_d3.sh[0] = 0x20A0;
    reg_d4.sh[0] = 1;
    sprite_draw();
}

void settings_notice_draw_piece_2(void) {
    reg_d1.w = 0x4A001C00;
    reg_d2.sw = 0x1559;
    reg_d4.sh[0] = 0;
    reg_d3.sh[0] = 0x260;
    sprite_draw();
}

void settings_notice_draw_piece_3(void) {
    reg_d1.w = 0x64003000;
    reg_d2.sw = 0x1558;
    reg_d4.sh[0] = 0;
    reg_d3.sh[0] = 0x410;
    sprite_draw();
}

void settings_notice_draw_piece_4(void) {
    reg_d1.w = 0x04000400;
    reg_d2.sw = 0x155B;
    reg_d4.sh[0] = 0;
    reg_d3.sh[0] = 0x620;
    sprite_draw();
}

extern u8 g_setting_difficulty;


void settings_notice_print_rank(void)
{
    extern void text_layer_print(void);
    reg_d0.w = 0;
    reg_a0 = (u8 *)settings_notice_rank_texts;
    reg_d0.b[0] = g_setting_difficulty;
    reg_d0.w += reg_d0.w;
    reg_d0.w += reg_d0.w;
    reg_a0 = *(u8 **)(reg_a0 + reg_d0.h[0]);
    reg_d1.h[0] = 0xD;
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    text_layer_print();
}

extern u8 g_setting_extend;

void settings_notice_print_extend(void) {
    s32 text_layer_print();
    u16 temp_a0;

    reg_a0 = (u8 *)settings_notice_extend_texts;
    reg_d0.w = 0;
    reg_d0.b[0] = g_setting_extend;
    reg_d0.w += reg_d0.w;
    reg_d0.w += reg_d0.w;
    temp_a0 = reg_d0.h[0];
    reg_a0 = *(u8 **)((u8 *)reg_a0 + temp_a0);
    reg_d1.h[0] = 0xF;
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    text_layer_print();
}

#ifdef DEATH_LABEL
void text_layer_print(void);
extern u8 g_setting_rapid_fire;
extern char *settings_notice_rapid_fire_texts[];
#endif

void settings_notice_print_rapid_fire(void) {
#ifdef DEATH_LABEL
    reg_d0.w = 0;
    reg_a0 = (u8 *)settings_notice_rapid_fire_texts;
    reg_d0.b[0] = g_setting_rapid_fire;
    reg_d0.w += reg_d0.w;
    reg_d0.w += reg_d0.w;
    reg_a0 = *(u8 **)(reg_a0 + reg_d0.h[0]);
    reg_d1.h[0] = 0xC;
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    text_layer_print();
#endif
}


extern void enemy_set_entity_count(s32);

void enemy_pattern_count_0(void) {
    enemy_set_entity_count(0);
}


void enemy_remove_entry_entry(void) {
    enemy_remove_entry();
}

extern void enemy_remove(void);

void enemy_remove_entry(void) {
    enemy_remove();
}

/* .sbss (the compiler lays these out in reverse) */
u32 D_0028DF80;
u32 D_0028DF7C;
u32 D_0028DF78;
u32 D_0028DF74;
u32 D_0028DF70;
u32 D_0028DF6C;
u32 D_0028DF68;
u32 D_0028DF64;
u8 *D_0028DF60;
u8 *D_0028DF5C;
u8 *D_0028DF58;
u8 *D_0028DF54;
u8 *D_0028DF50;
u8 *D_0028DF4C;
u8 *D_0028DF48;

#ifdef DEATH_LABEL
char *settings_notice_rapid_fire_texts[2] = {
    settings_notice_rapid_fire[0],
    settings_notice_rapid_fire[1],
};
#endif
