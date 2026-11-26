#include "common.h"
#include "task.h"
s32 memalign();
s32 memset();
s32 printf();

s32 layers_reset();
s32 layers_clear_all();
s32 func_0012FD40();
s32 func_00131490();
s32 frame_counters_advance();
s32 func_00135EC0();
s32 func_00137C20();
s32 func_00137C50();
s32 fades_reset();
s32 fades_update();
s32 func_0013FD80();
s32 input_clear();
s32 input_update_pressed();
s32 pointer_tables_init();
s32 sound_init();
s32 sound_unused();
s32 func_0018E5A0();
s32 sprite_lists_reset();
s32 sprite_lists_build();
s32 func_001A2900();
s32 text_palette_load();
s32 hud_setup();
s32 func_001AD770();
s32 func_001AE490();
s32 func_00206C20();
s32 func_00206D10();
s32 func_00206D60();
s32 zoom_init();
s32 test_mode_init();
s32 settings_reset();
s32 collision_reset();
s32 slowdown_init();
s32 slowdown_update();
s32 func_0020F550();
s32 func_002108C0();
s32 font_load_async();
s32 sys_start();
s32 sys_begin_frame();
s32 sys_end_frame();
s32 stage_load_step();
s32 text_layer_clear_edge_top();
s32 text_layer_clear_edge_bottom();
s32 wallpaper_load();
s32 arcade_sprite_init();
s32 sprite_header_load_async();
s32 sprite_pixels_load_async();
s32 func_0021D8C0();
s32 func_002232F0();
s32 func_00225630();
s32 func_002256B0();
s32 func_00236900();
s32 replay_begin_pending();
extern u8 D_002620F0[];
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
extern s8 g_game_frame_ran_as_s8;
extern u8 D_0028E374;
extern u16 g_attract_demo;
extern s16 g_stage_as_s16;
extern s8 D_0028E9A4;
extern s8 D_0028E9A5;
extern u16 D_0028E9A8;
extern u16 D_0028E9AC;
extern u16 D_0028E9B0;
extern u16 D_0028E9B4;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern s8 D_0028EC58;
extern u8 g_replay_file_loaded[];
extern u8 g_replay_file[];

void func_002120D0(void) {
    s32 t1;
    s32 t2;
    u32 t3;

#ifdef DEATH_LABEL
    g_game_mode = 2;
#endif
    g_cd_async_state = 0;
    printf("--card   size[%d]\n", 0x9A8);
    printf("--replay size[%d]\n", 0x206EC);
    printf("--replay_data size[%d]\n", 0x202E8);
    func_00236900();
    memset(g_replay_file, 0, 0x202E8);
    memset(g_replay_file_loaded, 0, 0x202E8);
    func_0021D8C0();
    sys_start();
    pointer_tables_init();
    func_0018E5A0();
    func_0020F550();
    func_002108C0();
    sound_init();
    arcade_sprite_init();
    test_mode_init();
    settings_reset();
    func_00206C20();
    hud_setup();
    func_00131490();
    sound_unused();
    collision_reset();
    slowdown_init();
    zoom_init();
    layers_clear_all();
    func_0012FD40();
    input_clear();
    func_001A2900();
    fades_reset();
    sprite_lists_reset();
    task_reset_all();
    func_00135EC0();
    layers_reset();
    func_00137C20();
    func_0013FD80();
    func_00137C50();
    func_001AE490();
    func_001AD770();
    func_00206D10();
    func_00206D60();
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
    printf("memory[%x]\n", memalign(0x40, 0x10));
    g_cd_async_state = 0;
    t3 = 0;
    func_00225630();
    printf("cd_read start\n");
    do {
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
                g_stage_as_s16 = 0;
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
                func_002256B0();
            }
            break;
        case 4:
            if (D_0028E374 == 0) {
                t3 += 1;
            }
            break;
        case 5:
            break;
        }
        sys_end_frame();
    } while (t3 != 5);
    wallpaper_load(0x14B5, D_002620F0);
loop_15:
    sys_begin_frame();
    input_update_pressed();
    t1 = 0;
    t2 = 0;
    if (g_paused != 0) {
        func_002232F0();
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
        task_run_all();
        frame_counters_advance();
        fades_update();
        sprite_lists_build();
        if (D_0028EC58 != 0) {
            g_game_frame_ran_as_s8 = 1;
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
    if (t2 == 0) {
        goto loop_15;
    }
    replay_begin_pending();
    goto loop_15;
}

extern u8 D_0026F6C0[];
extern u8 D_0026F700[];
extern u8 D_0026F740[];

#include "sdk/eekernel.h"

void func_00212580(s32 mode) {
    sceSifInitRpc(0);
    sceCdInit(0);
    sceSifExitCmd();
    if (mode == 0) {
        LoadExecPS2((const char *)D_0026F6C0, 0, 0);
    } else if (mode == 1) {
        LoadExecPS2((const char *)D_0026F700, 0, 0);
    } else {
        LoadExecPS2((const char *)D_0026F740, 0, 0);
    }
}

#ifdef DEATH_LABEL
u8 D_0026F6C0[160] = {
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
u8 D_0026F6C0[160] = {
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

/* .sbss (the compiler lays these out in reverse) */
u16 D_0028E9B4 __attribute__((aligned(4)));
u16 D_0028E9B0 __attribute__((aligned(4)));
u16 D_0028E9AC __attribute__((aligned(4)));
u16 D_0028E9A8 __attribute__((aligned(4)));
s8 D_0028E9A5;
s8 D_0028E9A4 __attribute__((aligned(4)));
