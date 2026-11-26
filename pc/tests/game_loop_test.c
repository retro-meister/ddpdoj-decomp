#include "common.h"
#include "game_loop.h"
#include "pc_replay_storage.h"
#include "task.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

u8 *reg_a0;
Reg32 reg_d0;
s8 g_cd_async_state, g_cd_async_busy, g_stage_load_finished;
u8 g_stage_load_state, g_paused, g_disc_notice_kind, D_0028DF08, g_game_frame_ran;
u16 g_attract_demo, g_stage;
#ifdef DEATH_LABEL
u8 g_game_mode;
#endif
u16 g_input_p2_previous, g_input_p2_pressed, g_input_p1_previous, g_input_p1_pressed;
s8 g_arcade_input_port[4], D_0028E249[4];
u8 text_palette_0[1], text_palette_1[1], text_palette_2[1], text_palette_3[1], text_palette_4[1];
u16 g_menu_wallpapers_1[1];

static Task attract_task;
static char events[64];
static unsigned int event_count;
static unsigned int font_polls;
static bool unpause;

s32 executable_launch(s32 mode);

static void require(bool condition, const char *message) {
    if (!condition) {
        fprintf(stderr, "%s\n", message);
        exit(EXIT_FAILURE);
    }
}

static void record(char event) {
    require(event_count + 1 < sizeof events, "Too many frame events");
    events[event_count++] = event;
    events[event_count] = '\0';
}

static void check_events(const char *expected) {
    if (strcmp(events, expected) != 0) {
        fprintf(stderr, "Frame events: expected %s, got %s\n", expected, events);
        exit(EXIT_FAILURE);
    }
    event_count = 0;
    events[0] = '\0';
}

/* These subsystem calls are deliberately inert in the loop test. */
#define NOOP(name) void name(void) {}
NOOP(layers_reset)
NOOP(layers_clear_all)
NOOP(coin_init)
NOOP(frame_counters_init)
NOOP(game_init)
NOOP(ending_state_clear)
NOOP(attract_demo_state_clear)
NOOP(fades_reset)
NOOP(players_clear)
NOOP(input_clear)
NOOP(pointer_tables_init)
NOOP(sound_init)
NOOP(sound_unused)
NOOP(checked_pointers_store)
NOOP(sprite_lists_reset)
NOOP(palettes_init)
NOOP(text_palette_load)
NOOP(hud_setup)
NOOP(rankings_set_defaults)
NOOP(scores_reset)
NOOP(display_control_init)
NOOP(display_control_bit_0_on)
NOOP(display_control_unused)
NOOP(zoom_init)
NOOP(test_mode_init)
NOOP(settings_reset)
NOOP(collision_reset)
NOOP(slowdown_init)
NOOP(startup_pointers_store_a)
NOOP(startup_pointers_store_b)
NOOP(sys_start)
NOOP(arcade_sprite_init)
NOOP(sim_rules_set_defaults)
NOOP(replay_slot_infos_clear)
NOOP(task_reset_all)
#undef NOOP

void task_start(void) {
    require(reg_d0.h[0] == TASK_ATTRACT, "Startup must queue the attract task");
    reg_a0 = (u8 *)&attract_task;
}

void sys_begin_frame(void) { record('['); }
void sys_end_frame(void) { record(']'); }
void disc_notice_begin(void) { record('D'); }
void disc_notice_end(void) { record('d'); }
void sprite_header_load_async(void) { record('H'); g_cd_async_busy = 0; }
void sprite_pixels_load_async(void) { record('P'); g_cd_async_busy = 0; }
void input_update_pressed(void) { record('I'); }
void task_run_all(void) { record('T'); }
void frame_counters_advance(void) { record('C'); }
void fades_update(void) { record('F'); }
void sprite_lists_build(void) { record('G'); }
void slowdown_update(void) { record('S'); }
void text_layer_clear_edge_top(void) { record('U'); }
void text_layer_clear_edge_bottom(void) { record('L'); }
void replay_begin_pending(void) { record('R'); }

void font_load_async(void) {
    record('f');
    g_cd_async_busy = (++font_polls == 1);
}

void stage_load_step(void) {
    require(g_stage == 0, "Startup must load the first stage");
    record('M');
}

void wallpaper_load(s32 index, u16 *source) {
    require(index == 0x14B5 && source == g_menu_wallpapers_1, "Wrong startup wallpaper");
    record('W');
}

void pause_update(void) {
    record('p');
    if (unpause) {
        g_paused = 0;
        g_input_p1_pressed = 0;
    }
}

int main(void) {
    memset(g_replay_file, 0xAD, sizeof(g_replay_file));
    memset(g_replay_file_loaded, 0xBE, sizeof(g_replay_file_loaded));
    game_boot_begin();
    require(g_replay_snapshot == g_replay_file + PC_REPLAY_BODY_OFFSET &&
            D_006A4C00 == g_replay_file_loaded + PC_REPLAY_BODY_OFFSET,
            "Replay snapshots are backed by their original file offsets");
    require(g_replay_file[PC_REPLAY_FILE_SIZE - 1] == 0 &&
            g_replay_file_loaded[PC_REPLAY_FILE_SIZE - 1] == 0 &&
            g_replay_file[PC_REPLAY_FILE_SIZE] == 0xAD &&
            g_replay_file_loaded[PC_REPLAY_FILE_SIZE] == 0xBE,
            "Boot clears the replay payload without clearing adjacent bytes");
#ifdef DEATH_LABEL
    require(g_game_mode == 2, "Death Label must select its game mode at startup");
    const char *running_frame = "[ITCFGS]R";
    const char *paused_frame = "[IpS]";
#else
    const char *running_frame = "[ITCFGSUL]R";
    const char *paused_frame = "[IpSUL]";
#endif
    check_events("D");
    require(!game_boot_frame(), "Font is still loading");
    check_events("[f]");
    require(!game_boot_frame(), "Font completion is followed by sprite loading");
    check_events("[f]");
    require(!game_boot_frame(), "Sprite pixels are still pending");
    check_events("[H]");
    require(!game_boot_frame(), "Stage loading is still pending");
    check_events("[P]");
    require(!game_boot_frame(), "Startup fade is still pending");
    check_events("[Md]");
    g_disc_notice_kind = 1;
    require(!game_boot_frame(), "Startup must wait for the original fade condition");
    check_events("[]");
    g_disc_notice_kind = 0;
    require(game_boot_frame(), "Startup must finish after the fade condition clears");
    check_events("[]W");
    require(game_boot_frame(), "Completed startup is stable");
    check_events("");

    g_attract_demo = 1;
    g_input_p1_pressed = 0x4000;
    g_stage_load_finished = 1;
    game_run_frame();
    check_events(running_frame);
    require(g_game_frame_ran == 1, "Gameplay frame must publish the original frame flag");
    g_paused = 1;
    game_run_frame();
    check_events(paused_frame);
    unpause = true;
    game_run_frame();
    check_events(paused_frame);
    require(g_input_p1_pressed == 0x4000, "Unpause must restore the input snapshot");
    game_run_frame();
    check_events(running_frame);
    require(game_take_mode_request() == GAME_MODE_NONE, "No mode change at startup");
    executable_launch(1);
    require(game_take_mode_request() == GAME_MODE_DEATH_LABEL, "Main menu must launch Death Label");
    executable_launch(2);
    require(game_take_mode_request() == GAME_MODE_MAIN, "Death Label must return to the main game");
    executable_launch(0);
    require(game_take_mode_request() == GAME_MODE_GALLERY, "Main menu must launch Gallery");
    require(game_take_mode_request() == GAME_MODE_NONE, "Mode requests are consumed once");
    return 0;
}
