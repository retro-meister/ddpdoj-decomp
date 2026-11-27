#include "common.h"
#ifdef DDPDOJ_PC
#include "pc_replay_storage.h"
#endif
#include "task.h"
#include "sdk/ps2sdk.h"
#include "debug_views.h"

/* Lists a viewer could show; nothing in this build reads them. */
DebugListView debug_list_views[34] = {
    { 0x0017, 0x002C, 0x0030, { 3, 4 }, 1, 0x0000, "    tagBOM:" },
    { 0x0030, 0x0000, 0x0062, { 3, 4 }, 1, 0x0000, "  tagFIG1p:" },
    { 0x0030, 0x0000, 0x0062, { 3, 4 }, 1, 0x0000, "  tagFIG2p:" },
    { 0x0031, 0x0000, 0x0064, { 3, 4 }, 1, 0x0000, "  tagOPT1p:" },
    { 0x0031, 0x0000, 0x0064, { 3, 4 }, 1, 0x0000, "  tagOPT2p:" },
    { 0x0017, 0x0023, 0x0030, { 3, 4 }, 1, 0x0000, " tagFSHT1p:" },
    { 0x0017, 0x0023, 0x0030, { 3, 4 }, 1, 0x0000, " tagFSHT2p:" },
    { 0x0017, 0x001F, 0x0030, { 3, 4 }, 1, 0x0000, "   tagLA1p:" },
    { 0x0017, 0x001F, 0x0030, { 3, 4 }, 1, 0x0000, "   tagLA2p:" },
    { 0x000F, 0x0000, 0x0020, { 3, 4 }, 1, 0x0000, "   tagLT1p:" },
    { 0x000F, 0x0000, 0x0020, { 3, 4 }, 1, 0x0000, "   tagLT2p:" },
    { 0x000F, 0x0000, 0x0020, { 3, 4 }, 0, 0x2020, "LT_ANI1p:" },
    { 0x000F, 0x0000, 0x0020, { 3, 4 }, 1, 0x0000, "  LT_ANI2p:" },
    { 0x0003, 0x0000, 0x0008, { 3, 4 }, 1, 0x0000, " REN_FIG1p:" },
    { 0x0003, 0x0000, 0x0008, { 3, 4 }, 1, 0x0000, " REN_FIG2p:" },
    { 0x000F, 0x0063, 0x0020, { 3, 4 }, 1, 0x0000, "    tagENE:" },
    { 0x000F, 0x0031, 0x0020, { 3, 4 }, 1, 0x0000, "   tagBOSS:" },
    { 0x001F, 0x0018, 0x0040, { 3, 4 }, 1, 0x0000, "   tagITEM:" },
    { 0x0000, 0x0000, 0x0001, { 3, 4 }, 1, 0x0000, "  LT_LIM1p:" },
    { 0x0000, 0x0000, 0x0001, { 3, 4 }, 1, 0x0000, "  LT_LIM2p:" },
    { 0x0015, 0x0045, 0x002C, { 3, 4 }, 1, 0x0000, "       BUI:" },
    { 0x0010, 0x001D, 0x0022, { 3, 4 }, 1, 0x0000, "    TILI1p:" },
    { 0x0010, 0x001D, 0x0022, { 3, 4 }, 1, 0x0000, "    TILI2p:" },
    { 0x003F, 0x01FF, 0x0080, { 3, 4 }, 1, 0x0001, "  TEXT_BUF:" },
    { 0x002C, 0x0000, 0x000A, { 3, 4 }, 1, 0x0000, "  tagSCO1p:" },
    { 0x002C, 0x0000, 0x000A, { 3, 4 }, 1, 0x0000, "  tagSCO2p:" },
    { 0x0004, 0x0000, 0x000A, { 3, 4 }, 1, 0x0000, "  tagCNT1p:" },
    { 0x0004, 0x0000, 0x000A, { 3, 4 }, 1, 0x0000, "  tagCNT2p:" },
    { 0x001F, MAIN_OR_DEATH_LABEL(0x00D1, 0x0419), 0x0040, { 3, 4 }, 1, 0x0000, "    tagBUL:" },
    { 0x000F, 0x0001, 0x0020, { 3, 4 }, 1, 0x0000, "    tagMEN:" },
    { 0x001F, 0x0013, 0x0040, { 3, 4 }, 1, 0x0000, "  tagHAHEN:" },
    { 0x0001, 0x0000, 0x0002, { 3, 4 }, 1, 0x0000, "  bull_bui:" },
    { 0x001B, 0x004F, 0x0038, { 3, 4 }, 1, 0x0000, "    tagEXP:" },
    { 0x0017, 0x001D, 0x0030, { 3, 4 }, 1, 0x0000, "    tagZAN:" },
};

DebugTableView debug_table_views[3] = {
    { { 0, 0, 2, 0 }, { 4, 5 }, 0x0030, 0x0000 },
    { { 1, 2, 4, 4 }, { 4, 5 }, 0x0030, 0x0800 },
    { { 2, 0, 6, 8 }, { 4, 5 }, 0x0030, 0x1000 },
};

#if defined(DEATH_LABEL) && !defined(DDPDOJ_PC)
extern u8 attract_demos_0[];
extern u8 attract_demos_1[];
extern u8 attract_demos_2[];

/* The demo of each stage. */
u8 *attract_demos[3] = {
    attract_demos_0,
    attract_demos_1,
    attract_demos_2,
};
#endif

/* The first cell of each frame of the demo's picture, 28 by 6 cells: tile in the high word, palette in the low word. */
u32 attract_picture_frames[4] = {
    (0x07C7 << 16) | 0x18,
    (0x086F << 16) | 0x18,
    (0x0917 << 16) | 0x18,
    (0x09BF << 16) | 0x18,
};

extern u16 game_flow_debug_clear_state;
extern u16 game_flow_debug_clear_state_2;
extern u16 game_flow_debug_clear_state_3;
extern u16 g_game_flow_debug_value;

void game_flow_debug_clear(void) {
    reg_d0.w = 0;
    g_game_flow_debug_value = reg_d0.h[0];
    game_flow_debug_clear_state_3 = reg_d0.h[0];
    game_flow_debug_clear_state_2 = reg_d0.h[0];
    game_flow_debug_clear_state = reg_d0.h[0];
}

extern u16 g_debug_number[];

void debug_number_get(void) {
    *(u16 *)&reg_d0 = g_debug_number[0];
}

extern s16 g_ending_started;
extern s16 ending_state_clear_buffer[];
extern s16 ending_state_clear_buffer_2[];

void ending_state_clear(void) {
    g_ending_started = 0;
    (*(s16 **)&reg_a0) = ending_state_clear_buffer_2;
    *(*(s16 **)&reg_a0) = 0;
    (*(s16 **)&reg_a0) = ending_state_clear_buffer;
    *(*(s16 **)&reg_a0) = 0;
    game_flow_debug_clear();
}

extern u32 D_0028E7F8;
extern u8 *D_0028E7FC;
extern u16 D_0028E800;
extern u16 D_0028E804;
extern s16 attract_demo_state_clear_state;
extern u16 D_0028E80C;
extern u16 D_0028E810;
extern u16 D_0028E814;
extern u16 D_0028E818;
extern u16 D_0028E81C;
extern u16 D_0028E820;
extern u16 D_0028E824;
extern u16 D_0028E828;

void attract_demo_state_clear(void) {
    D_0028E7F8 = 0;
    D_0028E7FC = NULL;
    D_0028E800 = 0;
    D_0028E804 = 0;
    attract_demo_state_clear_state = 0;
    D_0028E80C = 0;
    D_0028E810 = 0;
    D_0028E814 = 0;
    D_0028E818 = 0;
    D_0028E81C = 0;
    D_0028E820 = 0;
    D_0028E824 = 0;
    D_0028E828 = 0;
}

#ifdef DEATH_LABEL
s32 stage_doors_clear();
s32 text_palette_load();
extern u8 death_D_0026EE20[];
extern u16 g_attract_demo_stage;
extern u16 g_attract_demo;
extern u32 D_0028E7F8;
extern u8 *D_0028E7FC;
extern u16 D_0028E810;
extern u16 D_0028E814;
extern u16 D_0028E818;
extern u16 D_0028E820;
extern u16 D_0028E824;

void attract_demo_begin(void) {
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
    g_attract_demo = 1;
    attract_demo_state_clear();
    D_0028E824 = 0x10;
    D_0028E820 = 0x960;
#ifdef DDPDOJ_PC
    reg_d2.h[0] = g_attract_demo_stage;
    reg_a0 = (u8 *)&debug_table_views[reg_d2.h[0]];
#else
    reg_a0 = (u8 *) attract_demos;
    reg_d2.h[0] = g_attract_demo_stage;
    reg_tmp.w = (u32)attract_demos[reg_d2.h[0]];
    reg_a0 = (u8 *) reg_tmp.w;
#endif
    reg_d7.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E818 = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E814 = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E810 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E7FC = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E7F8 = reg_tmp.w;
    reg_d0.h[0] = TASK_GAME;
    task_start();
    *(u16 *)(reg_a0 + 4) = reg_d7.h[0];
    stage_doors_clear();
    reg_a0 = death_D_0026EE20;
    reg_d0.h[0] = 0xC;
    text_palette_load();
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
#else
extern u8 D_0028DEF8;
extern u16 g_attract_picture_frame;
extern u16 D_0028DF00;
extern u8 D_0028DF08;
extern u16 g_attract_demo;
extern s8 g_menu_pad;

void attract_demo_begin(void) {
    D_0028DF08 = 0;
    D_0028DF00 = 0x960;
    g_attract_picture_frame = 0;
    g_attract_demo = 1;
    D_0028DEF8 = 1;
    g_menu_pad = 0;
}
#endif

#ifndef DEATH_LABEL
s32 deferred_text_put();
extern u16 g_attract_picture_frame;

void attract_picture_draw(void) {
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
    u32 temp_a1;

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
    reg_a0 = (u8 *)(attract_picture_frames);
    reg_a0 += g_attract_picture_frame;
    temp_a1 = *(u32 *)reg_a0;
    reg_d4.w = temp_a1;
    reg_d0.h[0] = 0x88;
    reg_d2.w = 5;
    reg_d3.w = 0x1B;
    reg_d1.h[0] = 0;
    deferred_text_put();
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
}
#endif

#ifndef DEATH_LABEL

s32 text_palette_load();
s32 delta_encode();
s32 menu_settings_restore();
s32 replay_disc_headers_load();
s32 replay_disc_file_load();
s32 replay_file_pointers_decode();
extern u16 attract_picture_palette[];
extern u8 attract_demo_start_state;
extern u8 D_0028DEF8;
extern u16 g_attract_picture_frame;
extern u16 D_0028DF00;
extern u8 attract_demo_start_state_2;
extern u8 D_0028DF08;
extern u16 g_attract_demo;
extern u8 g_loaded_replay_id_0;
extern u8 g_loaded_replay_id_1;
extern u8 g_loaded_replay_id_2;
extern u8 g_loaded_replay_id_3;
extern u8 g_loaded_replay_id_4;
extern u8 g_loaded_replay_id_5;
extern u8 g_loaded_replay_id_6;
extern u8 g_loaded_replay_id_7;
extern u8 g_replay_buffer_state;
extern u8 g_replay_mode;
#ifndef DDPDOJ_PC
extern u8 g_replay_file_loaded[];
extern u8 g_replay_file[];
extern u8 g_replay_file_id_0[];
extern u8 g_replay_file_id_1[];
extern u8 g_replay_file_id_2[];
extern u8 g_replay_file_id_3[];
extern u8 g_replay_file_id_4[];
extern u8 g_replay_file_id_5[];
extern u8 g_replay_file_id_6[];
extern u8 g_replay_file_id_7[];
extern u8 g_replay_snapshot[];
#endif

void attract_demo_start(void) {
    s32 layers_reset();
    s32 bg_scroll_reset();
    s32 bg_layer_clear();
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
    s32 temp_a1;

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
    temp_a1 = D_0028DF08;
    cond_flag = 1;
    attract_demo_start_state += 1;
    switch (temp_a1) {                              /* irregular */
    case 0:
        D_0028DF08 = temp_a1 + 1;
        replay_disc_headers_load(4, temp_a1, 1);
        reg_a0 = (u8 *)attract_picture_palette;
        reg_d0.h[0] = 0xC;
        text_palette_load();
        /* fallthrough */
    case 1:
        if (replay_disc_file_load(attract_demo_start_state_2) != 0) {
            D_0028DF08 += 1;
            memcpy(g_replay_file, g_replay_file_loaded, 0x202E8);
            delta_encode(g_replay_snapshot);
            replay_file_pointers_decode(g_replay_file);
            g_replay_mode = 2;
            g_loaded_replay_id_0 = g_replay_file_id_0[0];
            reg_d0.h[0] = 0x14;
            g_loaded_replay_id_1 = g_replay_file_id_1[0];
            g_loaded_replay_id_2 = g_replay_file_id_2[0];
            g_loaded_replay_id_3 = g_replay_file_id_3[0];
            g_loaded_replay_id_4 = g_replay_file_id_4[0];
            g_loaded_replay_id_5 = g_replay_file_id_5[0];
            g_loaded_replay_id_6 = g_replay_file_id_6[0];
            g_loaded_replay_id_7 = g_replay_file_id_7[0];
            task_start();
            *(s8 *)(reg_a0 + 5) = 3;
        }
        break;
    case 2:
        if (D_0028DEF8 != 0) {
            D_0028DF08 = temp_a1 + 1;
        }
        break;
    case 3:
        D_0028DF08 = temp_a1 + 1;
        break;
    case 4:
        D_0028DF00 -= 1;
        if (D_0028DF00 == 0) {
            D_0028DF08 = 0;
            cond_flag = 0;
            g_attract_demo = 0;
            g_replay_mode = 0;
            g_replay_buffer_state = 0;
            bg_scroll_reset();
            bg_layer_clear();
            layers_reset();
            menu_settings_restore();
            attract_demo_start_state_2 += 1;
            if ((s32) attract_demo_start_state_2 >= 3) {
                attract_demo_start_state_2 = 0;
            }
        }
        break;
    }
    if ((s32) D_0028DF08 > 0) {
        attract_picture_draw();
        reg_d0.h[0] = (u16) attract_demo_start_state;
        if ((reg_d0.h[0] &= 1) == 0) {
            g_attract_picture_frame += 4;
            g_attract_picture_frame &= 0xF;
        }
    }
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
}
#endif

#ifdef DEATH_LABEL
void frame_counters_reset(void);
extern u8 *D_0028E7FC;
extern u16 D_0028E800;
extern u16 D_0028E804;
extern u16 D_0028E80C;
extern u8 death_D_00291195;

void scripted_input_apply(void) {
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    reg_d6.h[0] = reg_d0.h[0];
    reg_d0.h[0] &= 0xFF;
    reg_d6.h[0] &= 0xFF00;
    if (D_0028E80C != 0) {
        reg_d7.h[0] = D_0028E800;
        if (reg_d7.h[0] == 0x800) {
            reg_d0.h[0] = 0;
        } else if (D_0028E80C == 1) {
            D_0028E80C = 2;
            frame_counters_reset();
            reg_d0.b[0] = 0;
        } else {
            reg_d0.b[0] = death_D_00291195;
            D_0028E804 -= 1;
            if (!(0 < (s16) D_0028E804)) {
                reg_a0 = D_0028E7FC;
                reg_a0 += D_0028E800;
                reg_d7.w = 0;
                reg_d7.b[0] = *(s8 *)reg_a0;
                D_0028E804 = reg_d7.h[0];
                reg_d0.b[0] = *(s8 *)(reg_a0 + 1);
                D_0028E800 += 2;
                death_D_00291195 = reg_d0.b[0];
            }
        }
    }
    reg_d0.h[0] |= reg_d6.h[0];
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
}
#endif

#ifdef DEATH_LABEL
void ship_select_apply(void);
void stage_doors_open_request(void);
void stage_doors_update(void);
extern u8 death_D_0026FDA0[];
extern u8 g_game_frame_ran;
extern u16 g_attract_demo_stage;
extern u16 g_attract_demo;
extern u16 g_game_frame;
extern u16 D_0028E814;
extern u16 D_0028E818;
extern u16 D_0028E81C;
extern u16 D_0028E820;
extern u16 D_0028E824;
extern u16 D_0028E828;
extern u8 death_D_00291191;
extern u8 death_D_00291195;

void attract_demo_start(void) {
    void layers_reset(void);
    void deferred_text_put(void);
    void bg_scroll_reset(void);
    void bg_layer_clear(void);
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
    stage_doors_update();
    reg_a0 = death_D_0026FDA0;
    reg_a0 += D_0028E81C;
    reg_d4.w = *(u32 *)reg_a0;
    reg_d0.h[0] = 0x88;
    reg_d1.h[0] = 0;
    reg_d2.w = 5;
    reg_d3.w = 0x1B;
    deferred_text_put();
    reg_d0.h[0] = g_game_frame;
    if ((reg_d0.h[0] &= 1) == 0) {
        D_0028E81C += 4;
        D_0028E81C &= 0xF;
    }
    if (D_0028E828 == 0) {
        D_0028E824 -= 1;
        if (D_0028E824 != 0) {
            goto check_end;
        }
        D_0028E828 = 2;
        death_D_00291191 = 1;
        reg_d0.w = 0;
        reg_a0 = D_0028E7FC;
        reg_a0 += D_0028E800;
        reg_d0.b[0] = *(s8 *)reg_a0;
        D_0028E804 = reg_d0.h[0];
        death_D_00291195 = *(s8 *)(reg_a0 + 1);
        D_0028E800 += 2;
        frame_counters_reset();
        g_game_frame_ran = 0;
        stage_doors_open_request();
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d0.h[0] = D_0028E818;
        reg_d1.h[0] = D_0028E814;
        reg_d2.h[0] = 0xFF;
        reg_d3.h[0] = 0xFF;
        reg_d4.w = 1;
        ship_select_apply();
    }
    if ((D_0028E828 == 2) && (g_game_frame_ran != 0)) {
        D_0028E80C = 1;
        D_0028E828 = 1;
    }
check_end:
    if (D_0028E828 == 1) {
        D_0028E820 -= 1;
        if (D_0028E820 == 0) {
            bg_scroll_reset();
            bg_layer_clear();
            layers_reset();
            goto finished;
        }
    }
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
    cond_flag = 1;
    return;
finished:
    g_attract_demo_stage += 1;
    D_0028E80C = 0;
    if ((s16) g_attract_demo_stage >= 3) {
        g_attract_demo_stage = 0;
    }
    g_attract_demo = 0;
    cond_flag = 0;
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
#endif

/* .sbss (the compiler lays these out in reverse) */
#ifndef DEATH_LABEL
u8 D_0028DF08 __attribute__((aligned(4)));
u8 attract_demo_start_state_2 __attribute__((aligned(4)));
u16 D_0028DF00 __attribute__((aligned(4)));
u16 g_attract_picture_frame __attribute__((aligned(4)));
u8 D_0028DEF8 __attribute__((aligned(4)));
u8 attract_demo_start_state __attribute__((aligned(4)));
#endif

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

#ifdef DEATH_LABEL
PC_DATA_ALIAS(death_D_0026FDA0, attract_picture_frames, 0x0);
#endif
#endif
