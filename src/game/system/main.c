#include "common.h"
#include "black_label.h"
#ifdef DDPDOJ_PC
#include "pc_replay_storage.h"
#endif
#include "task.h"

#ifdef DDPDOJ_PC
#include "game_loop.h"
#include <stdio.h>
#include <string.h>
#define FRAME_ROUTINE(name) void name(void)
void wallpaper_load(s32 index, u16 *source);
extern u16 g_menu_wallpapers_1[];
static u32 boot_phase;
#else
s32 memalign();
s32 memset();
s32 printf();
#define FRAME_ROUTINE(name) s32 name()
s32 wallpaper_load();
extern u8 g_menu_wallpapers_1[];
#endif

FRAME_ROUTINE(layers_reset);
FRAME_ROUTINE(layers_clear_all);
FRAME_ROUTINE(coin_init);
FRAME_ROUTINE(frame_counters_init);
FRAME_ROUTINE(frame_counters_advance);
FRAME_ROUTINE(game_init);
FRAME_ROUTINE(ending_state_clear);
FRAME_ROUTINE(attract_demo_state_clear);
FRAME_ROUTINE(fades_reset);
FRAME_ROUTINE(fades_update);
FRAME_ROUTINE(players_clear);
FRAME_ROUTINE(input_clear);
FRAME_ROUTINE(input_update_pressed);
FRAME_ROUTINE(pointer_tables_init);
FRAME_ROUTINE(sound_init);
FRAME_ROUTINE(sound_unused);
FRAME_ROUTINE(checked_pointers_store);
FRAME_ROUTINE(sprite_lists_reset);
FRAME_ROUTINE(sprite_lists_build);
FRAME_ROUTINE(palettes_init);
FRAME_ROUTINE(text_palette_load);
FRAME_ROUTINE(hud_setup);
FRAME_ROUTINE(rankings_set_defaults);
FRAME_ROUTINE(scores_reset);
FRAME_ROUTINE(display_control_init);
FRAME_ROUTINE(display_control_bit_0_on);
FRAME_ROUTINE(display_control_unused);
FRAME_ROUTINE(zoom_init);
FRAME_ROUTINE(test_mode_init);
FRAME_ROUTINE(settings_reset);
FRAME_ROUTINE(collision_reset);
FRAME_ROUTINE(slowdown_init);
FRAME_ROUTINE(slowdown_update);
FRAME_ROUTINE(startup_pointers_store_a);
FRAME_ROUTINE(startup_pointers_store_b);
FRAME_ROUTINE(font_load_async);
FRAME_ROUTINE(sys_start);
FRAME_ROUTINE(sys_begin_frame);
FRAME_ROUTINE(sys_end_frame);
FRAME_ROUTINE(stage_load_step);
FRAME_ROUTINE(text_layer_clear_edge_top);
FRAME_ROUTINE(text_layer_clear_edge_bottom);
FRAME_ROUTINE(arcade_sprite_init);
FRAME_ROUTINE(sprite_header_load_async);
FRAME_ROUTINE(sprite_pixels_load_async);
FRAME_ROUTINE(sim_rules_set_defaults);
FRAME_ROUTINE(pause_update);
FRAME_ROUTINE(disc_notice_begin);
FRAME_ROUTINE(disc_notice_end);
FRAME_ROUTINE(replay_slot_infos_clear);
FRAME_ROUTINE(replay_begin_pending);
#undef FRAME_ROUTINE

extern u8 text_palette_0[];
extern u8 text_palette_1[];
extern u8 text_palette_2[];
extern u8 text_palette_3[];
extern u8 text_palette_4[];
extern u8 D_0028DF08;
#ifdef DEATH_LABEL
extern u8 g_game_mode;
#endif
extern u16 g_input_p2_previous;
extern u16 g_input_p2_pressed;
extern u16 g_input_p1_previous;
extern u16 g_input_p1_pressed;
extern s8 g_arcade_input_port[];
extern s8 D_0028E249[];
extern u8 g_stage_load_state;
extern u8 g_paused;
extern u8 g_game_frame_ran;
extern u8 g_disc_notice_kind;
extern u16 g_attract_demo;
extern u16 g_stage;
extern s8 D_0028E9A4;
extern s8 D_0028E9A5;
extern u16 D_0028E9A8;
extern u16 D_0028E9AC;
extern u16 D_0028E9B0;
extern u16 D_0028E9B4;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern s8 g_stage_load_finished;
#ifndef DDPDOJ_PC
extern u8 g_replay_file_loaded[];
extern u8 g_replay_file[];
#endif

#ifdef DDPDOJ_PC
void game_boot_begin(void) {
    pc_arcade_address_init();
#else
#ifdef DDPDOJ_BONUS_FEATURES
void game_main(s32 argc, char **argv) {
    s32 strcmp(const char *, const char *);
#else
void game_main(void) {
#endif
    s32 t1;
    s32 t2;
    u32 t3;
#ifdef DDPDOJ_BONUS_FEATURES
    g_black_label_active = argc > 0 && strcmp(argv[argc - 1], "black-label") == 0;
#endif
#endif
#ifdef DDPDOJ_BONUS_FEATURES
    if (g_black_label_active) {
        black_label_title_init();
        black_label_menu_init();
        black_label_card_init();
    }
#endif

#ifdef DEATH_LABEL
    g_game_mode = 2;
#endif
    g_cd_async_state = 0;
    printf("--card   size[%d]\n", 0x9A8);
    printf("--replay size[%d]\n", 0x206EC);
    printf("--replay_data size[%d]\n", 0x202E8);
    replay_slot_infos_clear();
    memset(g_replay_file, 0, 0x202E8);
    memset(g_replay_file_loaded, 0, 0x202E8);
    sim_rules_set_defaults();
    sys_start();
    pointer_tables_init();
    checked_pointers_store();
    startup_pointers_store_a();
    startup_pointers_store_b();
    sound_init();
    arcade_sprite_init();
    test_mode_init();
    settings_reset();
    display_control_init();
    hud_setup();
    frame_counters_init();
    sound_unused();
    collision_reset();
    slowdown_init();
    zoom_init();
    layers_clear_all();
    coin_init();
    input_clear();
    palettes_init();
    fades_reset();
    sprite_lists_reset();
    task_reset_all();
    game_init();
    layers_reset();
    ending_state_clear();
    players_clear();
    attract_demo_state_clear();
    scores_reset();
    rankings_set_defaults();
    display_control_bit_0_on();
    display_control_unused();
    reg_a0 = (u8 *)text_palette_0;
    reg_d0.w = 0;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_1;
    reg_d0.w = 1;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_2;
    reg_d0.w = 2;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_3;
    reg_d0.w = 3;
    text_palette_load();
    reg_a0 = (u8 *)text_palette_4;
    reg_d0.w = 4;
    text_palette_load();
    reg_d0.h[0] = TASK_ATTRACT;
    task_start();
    *(s16 *)(reg_a0 + 4) = 0x11;
#ifndef DDPDOJ_PC
    printf("memory[%x]\n", memalign(0x40, 0x10));
#endif
    g_cd_async_state = 0;
#ifdef DDPDOJ_PC
    boot_phase = 0;
    disc_notice_begin();
}

bool game_boot_frame(void) {
    u32 t3 = boot_phase;
    if (t3 == 5) {
        return true;
    }
#else
    t3 = 0;
    disc_notice_begin();
    printf("cd_read start\n");
    do {
#endif
        sys_begin_frame();
        switch (t3) {
        case 0:
            font_load_async();
            if (g_cd_async_busy == 0) {
                g_cd_async_state = 0;
                t3 += 1;
                g_cd_async_busy = 1;
            }
            break;
        case 1:
            sprite_header_load_async();
            if (g_cd_async_busy == 0) {
                g_cd_async_state = 0;
                t3 += 1;
                g_cd_async_busy = 1;
            }
            break;
        case 2:
            sprite_pixels_load_async();
            if (g_cd_async_busy == 0) {
                g_cd_async_state = 0;
                t3 += 1;
                g_stage = 0;
                g_cd_async_busy = 1;
                g_stage_load_state = 0;
            }
            break;
        case 3:
            stage_load_step();
            if (g_stage_load_state == 0) {
                g_cd_async_state = 0;
                g_cd_async_busy = 1;
                t3 += 1;
                disc_notice_end();
            }
            break;
        case 4:
            if (g_disc_notice_kind == 0) {
                t3 += 1;
            }
            break;
        case 5:
            break;
        }
        sys_end_frame();
#ifdef DDPDOJ_PC
    boot_phase = t3;
    if (boot_phase != 5) {
        return false;
    }
    wallpaper_load(0x14B5, g_menu_wallpapers_1);
    return true;
}

void game_run_frame(void) {
    s32 t1;
    s32 t2;
#else
    } while (t3 != 5);
    wallpaper_load(0x14B5, g_menu_wallpapers_1);
loop_15:
#endif
    sys_begin_frame();
    input_update_pressed();
    t1 = 0;
    t2 = 0;
    if (g_paused != 0) {
        pause_update();
        if (g_paused == 0) {
            t1 = 1;
            g_input_p1_previous = D_0028E9B4;
            g_input_p2_previous = D_0028E9B0;
            g_input_p1_pressed = D_0028E9AC;
            g_input_p2_pressed = D_0028E9A8;
            g_arcade_input_port[0] = D_0028E9A4;
            D_0028E249[0] = D_0028E9A5;
        }
    } else {
#ifdef DDPDOJ_BONUS_FEATURES
        if (g_black_label_active) frame_counters_advance();
#endif
        task_run_all();
        if (GAME_RULE(1, 0)) frame_counters_advance();
        fades_update();
        sprite_lists_build();
        if (g_stage_load_finished != 0) {
            g_game_frame_ran = 1;
        }
        t2 = 1;
    }
    if ((g_paused == 0) && (t1 == 0)) {
        D_0028E9B4 = g_input_p1_previous;
        D_0028E9B0 = g_input_p2_previous;
        D_0028E9AC = g_input_p1_pressed;
        D_0028E9A8 = g_input_p2_pressed;
        D_0028E9A4 = g_arcade_input_port[0];
        D_0028E9A5 = D_0028E249[0];
    }
    slowdown_update();
#ifndef DEATH_LABEL
    if ((g_attract_demo != 0) && ((s32) D_0028DF08 < 4)) {
        text_layer_clear_edge_top();
        text_layer_clear_edge_bottom();
    }
#endif
    sys_end_frame();
#ifdef DDPDOJ_PC
    if (t2 != 0) {
        replay_begin_pending();
    }
#else
    if (t2 == 0) {
        goto loop_15;
    }
    replay_begin_pending();
    goto loop_15;
#endif
}

#ifdef DDPDOJ_PC
s32 executable_launch(s32 mode) {
    if (mode == 0) {
        game_request_mode(GAME_MODE_GALLERY);
    } else if (mode == 1) {
        game_request_mode(GAME_MODE_DEATH_LABEL);
#ifdef DDPDOJ_BONUS_FEATURES
    } else if (mode == 3) {
        game_request_mode(GAME_MODE_BLACK_LABEL);
#endif
    } else {
        game_request_mode(GAME_MODE_MAIN);
    }
    return 0;
}
#else
extern u8 executable_launch_table[];
extern u8 D_0026F700[];
extern u8 D_0026F740[];

#include "sdk/eekernel.h"

void executable_launch(s32 mode) {
    sceSifInitRpc(0);
    sceCdInit(0);
    sceSifExitCmd();
    if (mode == 0) {
        LoadExecPS2((const char *)executable_launch_table, 0, 0);
    } else if (mode == 1) {
        LoadExecPS2((const char *)D_0026F700, 0, 0);
#ifdef DDPDOJ_BONUS_FEATURES
    } else if (mode == 3) {
        char *args[] = {"black-label"};
        LoadExecPS2("cdrom0:\\SLPS_252.33;1", 1, args);
    } else if (g_black_label_active) {
        LoadExecPS2("cdrom0:\\SLPS_252.33;1", 0, 0);
#endif
    } else {
        LoadExecPS2((const char *)D_0026F740, 0, 0);
    }
}

#ifdef DEATH_LABEL
u8 executable_launch_table[160] = {
    0x63, 0x64, 0x72, 0x6F, 0x6D, 0x30, 0x3A, 0x5C, 0x47, 0x41, 0x4C, 0x4C, 0x45, 0x52, 0x59, 0x2E,
    0x45, 0x4C, 0x46, 0x3B, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x63, 0x64, 0x72, 0x6F, 0x6D, 0x30, 0x3A, 0x5C, 0x44, 0x45, 0x41, 0x54, 0x48, 0x2E, 0x45, 0x4C,
    0x46, 0x3B, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x63, 0x64, 0x72, 0x6F, 0x6D, 0x30, 0x3A, 0x5C, 0x53, 0x4C, 0x50, 0x53, 0x5F, 0x32, 0x35, 0x32,
    0x2E, 0x33, 0x33, 0x3B, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#else
u8 executable_launch_table[160] = {
    0x63, 0x64, 0x72, 0x6F, 0x6D, 0x30, 0x3A, 0x5C, 0x47, 0x41, 0x4C, 0x4C, 0x45, 0x52, 0x59, 0x2E,
    0x45, 0x4C, 0x46, 0x3B, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x63, 0x64, 0x72, 0x6F, 0x6D, 0x30, 0x3A, 0x5C, 0x44, 0x45, 0x41, 0x54, 0x48, 0x2E, 0x45, 0x4C,
    0x46, 0x3B, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x63, 0x64, 0x72, 0x6F, 0x6D, 0x30, 0x3A, 0x5C, 0x53, 0x4C, 0x50, 0x53, 0x5F, 0x39, 0x39, 0x39,
    0x2E, 0x39, 0x39, 0x3B, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#endif
#endif

/* .sbss (the compiler lays these out in reverse) */
u16 D_0028E9B4 __attribute__((aligned(4)));
u16 D_0028E9B0 __attribute__((aligned(4)));
u16 D_0028E9AC __attribute__((aligned(4)));
u16 D_0028E9A8 __attribute__((aligned(4)));
s8 D_0028E9A5;
s8 D_0028E9A4 __attribute__((aligned(4)));
