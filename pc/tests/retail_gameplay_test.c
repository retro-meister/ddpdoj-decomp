#include "cdvd.h"
#include "combat_state.h"
#include "pc_player_state.h"
#include "pc_task_state.h"
#include "pc_replay_frame.h"
#include "pc_frame_regions.h"
#include "state_slot.h"
#include "pc_arcade_address.h"
#include "black_label.h"
#ifdef DDPDOJ_BONUS_FEATURES
#include "explosion.h"
#include "player.h"
#endif
#include "game_loop.h"
#include "gs.h"
#include "game_snapshot.h"
#include "presentation.h"
#include "memory_card.h"
#include "pc_input.h"
#include "pc_sound.h"
#include "sdk/libgraph.h"
#include "sfx.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdlib.h>
#include <string.h>

extern u16 g_attract_step;
extern s8 g_menu_page, g_menu_main_step, g_menu_arcade_step, g_menu_cursor;
extern s16 g_player1[], g_player2[];
extern u32 g_p2_score;
extern u16 g_game_frame, g_player_shot_count, g_player_laser_count, g_scroll_line;
extern u16 g_bomb_entities[];
extern u8 g_game_frame_ran;
extern s32 g_replay_position;

enum {
    ATTRACT_ARCADE = 14,
    ATTRACT_MENU = 15,
    ATTRACT_DEATH_LABEL = 19,
    PAGE_MAIN = 0,
    PAGE_ARCADE = 14,
    MENU_READY = 2,
    PLAY_MENU_ITEM = 1,
    GAMEPLAY_FRAMES = 900,
    MAX_FRAMES = 5600,
};

/* Accelerate simulation while allowing asynchronous asset work to run. */
s32 sceGsSyncV(s32 mode)
{
    static unsigned field;
    (void)mode;
    SDL_Delay(1);
    return ++field & 1;
}

static void require(bool condition, const char *message)
{
    if (!condition) {
        SDL_LogError(SDL_LOG_CATEGORY_TEST, "%s (%s)", message, SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

#ifdef DDPDOJ_BONUS_FEATURES
static bool player_active(void);

static void check_attract_demos(SDL_Renderer *renderer)
{
    extern u16 g_attract_demo, g_attract_demo_stage, g_stage, g_p1_hyper_items, g_input_p1_held;
    extern u32 g_p1_score;
    static const u32 expected_scores[] = {0x00836352, 0x00602489, 0x01087752};
    unsigned completed = 0, frames = 0, fired = 0;
    bool loaded = false, saw_loadout = false;
    for (unsigned field = 0; field < 22000 && completed < 3; ++field) {
        SDL_PumpEvents();
        pc_pad_capture();
        if (loaded) game_run_frame();
        else loaded = game_boot_frame();
        require(pc_gs_ok() && SDL_RenderPresent(renderer), "Render the attract sequence");
        if (g_attract_demo) {
            ++frames;
            require(g_attract_demo_stage == completed, "Cycle through the three attract stages in order");
            if (g_stage == completed && player_active()) {
                if (g_p1_hyper_items == 5) {
                    require(PLAYER(g_player1)->ship_type.h == (completed == 1 ? 0 : 2), "Select the recorded ship");
                    require(PLAYER(g_player1)->power_style.h == (completed + 1) * 2, "Select the recorded doll");
                    saw_loadout = true;
                }
                if (g_input_p1_held & 0x10) ++fired;
            }
        } else if (frames) {
            SDL_Log("Attract stage %u played %u frames, score %08x", completed + 1, frames, g_p1_score);
            require(g_p1_score == expected_scores[completed], "Finish with the recorded Black Label score");
            require(frames == 2414, "Play the full recording");
            require(saw_loadout, "Start with five hypers");
            require(fired > 100, "Apply the recorded fire button");
            ++completed;
            frames = fired = 0;
            saw_loadout = false;
        }
    }
    require(completed == 3 && g_attract_demo_stage == 0, "Return to the first recording after stage three");
}

static void check_boss_death_effect(void)
{
    extern u8 g_explosions[];
    extern u16 g_stage;
    Explosion *blasts = EXPLOSION(g_explosions);
    for (g_stage = 0; g_stage < 5; ++g_stage) {
        black_label_boss_burst(0x6000, 0x7000);
        for (unsigned i = 0; i < 39; ++i) {
            require(blasts[i].kind.h & 0x8000, "Create each explosion in the boss death sequence");
            require(blasts[i].y == 0x6000 && blasts[i].x == 0x7000, "Center the sequence on the boss");
            require(blasts[i].follows_scroll == (g_stage == 4 ? 2 : 1), "Use the stage's scroll mode");
            require(blasts[i].attr.b.flip == (i == 2 ? 0x40 : 0), "Flip the third explosion");
        }
        require(blasts[39].kind.h == 0, "Finish the burst after 39 explosions");
        require(blasts[0].delay == 4 && blasts[38].delay == 6, "Schedule the first and last explosions");
        require(g_slowdown_boss_allowed == 6, "Start boss slowdown with the burst");
        for (unsigned frame = 0; frame < 42; ++frame) {
            black_label_shake_step();
            if (frame < 3) require(g_boss_shake_y == -24 && g_boss_shake_x == 0, "Start the shake vertically");
        }
        require(g_boss_shake_y == 1 && g_boss_shake_x == -1, "Reach the final shake offset");
        black_label_shake_step();
        require(!g_boss_shake_y && !g_boss_shake_x && !g_slowdown_boss_allowed, "Settle both layers and end the slowdown");
    }
}
#endif

static SDL_Joystick *attach_controller(void)
{
    SDL_VirtualJoystickDesc desc;
    SDL_INIT_INTERFACE(&desc);
    desc.type = SDL_JOYSTICK_TYPE_GAMEPAD;
    desc.nbuttons = SDL_GAMEPAD_BUTTON_COUNT;
    desc.naxes = SDL_GAMEPAD_AXIS_COUNT;
    SDL_JoystickID id = SDL_AttachVirtualJoystick(&desc);
    SDL_Joystick *joystick = SDL_OpenJoystick(id);
    require(joystick != NULL, "Open virtual controller");
    SDL_Event added = { .gdevice = { .type = SDL_EVENT_GAMEPAD_ADDED, .which = id } };
    pc_pad_handle_event(&added);
    return joystick;
}

static bool player_active(void)
{
    return g_player1[0] < 0 && g_game_frame_ran;
}

static SDL_GamepadButton next_button(bool *confirmed, unsigned *inputs)
{
    if (player_active() && g_game_frame > 120) {
        return (*inputs)++ % 3 == 0 ? SDL_GAMEPAD_BUTTON_DPAD_LEFT : SDL_GAMEPAD_BUTTON_EAST;
    }
    if (g_attract_step == ATTRACT_ARCADE || g_attract_step == ATTRACT_DEATH_LABEL) {
        return SDL_GAMEPAD_BUTTON_EAST;
    }
    if (g_attract_step != ATTRACT_MENU) {
        return *confirmed ? SDL_GAMEPAD_BUTTON_INVALID : SDL_GAMEPAD_BUTTON_START;
    }
    if (g_menu_page == PAGE_ARCADE && g_menu_arcade_step == MENU_READY) {
        *confirmed = true;
        return SDL_GAMEPAD_BUTTON_EAST;
    }
    if (g_menu_page == PAGE_MAIN && g_menu_main_step == MENU_READY) {
        if (g_menu_cursor != PLAY_MENU_ITEM) {
            return SDL_GAMEPAD_BUTTON_DPAD_DOWN;
        }
#ifdef DEATH_LABEL
        *confirmed = true;
#elif defined(DDPDOJ_BONUS_FEATURES)
        *confirmed = g_black_label_active;
#endif
        return SDL_GAMEPAD_BUTTON_EAST;
    }
    return SDL_GAMEPAD_BUTTON_INVALID;
}

#ifndef DEATH_LABEL
extern u8 g_menu_simulation[];
extern s8 g_replay_slots_state, g_replay_slots_cursor;
extern u8 g_replay_mode, g_replay_mode_begun;
extern s32 g_replay_position, g_replay_pointer_not_found;
extern u32 g_p1_score;

enum {
    PAGE_SIMULATION = 7,
    PAGE_SUPER_REPLAY = 22,
    SIMULATION_MENU_ITEM = 2,
    SUPER_REPLAY_MENU_ITEM = 4,
    REPLAY_SLOTS_READY = 4,
    REPLAY_PLAYBACK = 2,
};

typedef struct {
    int slot;
    s32 inputs;
    u32 final_score;
} RetailReplay;

/* Slots 0–8 finish at the next recording's starting score. Slot 9 is
 * the final score observed when the retail executable finishes playback. */
static const RetailReplay super_replays[] = {
    {0,  8887, 0x03185063}, {1, 10150, 0x10766185},
    {2, 13690, 0x16208329}, {3, 16260, 0x22076753},
    {4, 19759, 0x60589826}, {5,  7390, 0x65051637},
    {6, 10166, 0x69698886}, {7, 13706, 0x75634202},
    {8, 15755, 0x80419415}, {9, 26612, 0x00439819},
};

static SDL_GamepadButton replay_menu_button(bool *confirmed, int slot)
{
    if (*confirmed) return SDL_GAMEPAD_BUTTON_INVALID;
    if (g_attract_step != ATTRACT_MENU) return SDL_GAMEPAD_BUTTON_START;
    if (g_menu_page == PAGE_MAIN && g_menu_main_step == MENU_READY) {
        return g_menu_cursor == SIMULATION_MENU_ITEM ? SDL_GAMEPAD_BUTTON_EAST : SDL_GAMEPAD_BUTTON_DPAD_DOWN;
    }
    if (g_menu_page == PAGE_SIMULATION && g_menu_simulation[0] == MENU_READY) {
        return g_menu_cursor == SUPER_REPLAY_MENU_ITEM ? SDL_GAMEPAD_BUTTON_EAST : SDL_GAMEPAD_BUTTON_DPAD_DOWN;
    }
    if (g_menu_page == PAGE_SUPER_REPLAY && g_replay_slots_state == REPLAY_SLOTS_READY) {
        *confirmed = g_replay_slots_cursor == slot;
        return *confirmed ? SDL_GAMEPAD_BUTTON_EAST : SDL_GAMEPAD_BUTTON_DPAD_DOWN;
    }
    return SDL_GAMEPAD_BUTTON_INVALID;
}
#endif

static bool has_relocated_enemy(void)
{
    const uintptr_t first = (uintptr_t)g_enemy_entities;
    for (size_t i = 0; i < SDL_arraysize(g_enemy_slots.slot.others); ++i) {
        const EnemyState *enemy = &g_enemy_slots.slot.others[i];
        if (!enemy->state.h) continue;
        u32 slot = ((u32)enemy->entities[0] << 16) | enemy->entities[1];
        uintptr_t p = pc_arcade_address_decode(slot);
        if (p - first >= sizeof(g_enemy_entities) || (p - first) % sizeof(Entity)) continue;
        EnemyRoutines *table = enemy->kind < 128 ? g_enemy_routines : g_enemy_routines_high;
        u32 callback = ((u32)enemy->routine[0] << 16) | enemy->routine[1];
        if (((Entity *)p)->flags.h && callback &&
            pc_arcade_address_decode(callback) == (uintptr_t)table[enemy->kind % 128].run) return true;
    }
    return false;
}

typedef struct {
    PcPlayerState at_save;
    PcPlayerState next[120];
    Uint32 combat[120], image[4];
} ExpectedTrajectory;

static void run_trajectory(SDL_Renderer *renderer, ExpectedTrajectory *states, bool compare)
{
    PcCombatPools *combat = SDL_calloc(1, sizeof(*combat));
    require(combat != NULL, "Allocate combat comparison buffer");
    for (unsigned i = 0; i < SDL_arraysize(states->next); ++i) {
        pc_pad_capture();
        game_run_frame();
        if (i % 30 == 0) {
            SDL_Surface *pixels = SDL_RenderReadPixels(renderer, NULL);
            require(pixels != NULL, "Read rendered gameplay");
            Uint32 hash = 0;
            for (int y = 0; y < pixels->h; ++y) {
                const u8 *row = (u8 *)pixels->pixels + (size_t)y * pixels->pitch;
                hash = SDL_crc32(hash, row, (size_t)pixels->w * SDL_BYTESPERPIXEL(pixels->format));
            }
            SDL_DestroySurface(pixels);
            if (compare && hash != states->image[i / 30])
                SDL_Log("Image differs on frame %u (%08x vs %08x)", i, hash, states->image[i / 30]);
            if (compare) require(hash == states->image[i / 30], "Reproduce the rendered frame");
            else states->image[i / 30] = hash;
        }
        require(pc_gs_ok() && SDL_RenderPresent(renderer), "Render after restoring gameplay");
        pc_combat_capture(combat);
        Uint32 hash = SDL_crc32(0, combat, sizeof(*combat));
        if (compare) require(hash == states->combat[i], "Reproduce the combat trajectory");
        else states->combat[i] = hash;
        PcPlayerState player;
        pc_player_state_capture(&player);
        if (compare) {
            require(!memcmp(&player, &states->next[i], sizeof(player)),
                    "Reproduce player and weapon state on each subsequent frame");
        } else states->next[i] = player;
    }
    SDL_free(combat);
}

int main(int argc, char **argv)
{
    bool black_slot = argc == 6 && !strcmp(argv[5], "--black-label");
    if (black_slot) --argc;
    const char *save_pools = argc == 5 && !strcmp(argv[3], "--save-pools") ? argv[4] : NULL;
    const char *load_pools = argc == 5 && !strcmp(argv[3], "--load-pools") ? argv[4] : NULL;
    if (save_pools || load_pools) argc = 3;
#ifdef DEATH_LABEL
    const GameMode pool_mode = GAME_MODE_DEATH_LABEL;
#else
    const GameMode pool_mode = black_slot ? GAME_MODE_BLACK_LABEL : GAME_MODE_MAIN;
#endif
#ifndef DEATH_LABEL
    const bool two_player = argc == 4 && strcmp(argv[3], "--two-player") == 0;
    const RetailReplay *replay = NULL;
    if (argc >= 4 && strcmp(argv[3], "--super-replay") == 0) {
        if (argc == 4) replay = &super_replays[2];
        if (argc == 5 && strlen(argv[4]) == 1 && argv[4][0] >= '0' && argv[4][0] <= '9') {
            replay = &super_replays[argv[4][0] - '0'];
        }
    }
#ifdef DDPDOJ_BONUS_FEATURES
    extern u8 g_ship_select_state[];
    const bool hover_one_round = black_slot || (argc == 4 && strcmp(argv[3], "--black-label") == 0);
    const bool leave_default = argc == 4 && strcmp(argv[3], "--black-label-default") == 0;
    const bool demos = argc == 4 && strcmp(argv[3], "--black-label-demos") == 0;
    unsigned departure_frames = 0;
    g_black_label_active = hover_one_round || leave_default || demos;
#endif
    require(argc == 3 || replay || two_player || GAME_RULE(0, 1), "Expected the retail ISO, a test-only memory card directory and optional replay mode");
    s32 replay_inputs = 0;
    bool replay_finished = false;
#else
    const bool replay = false, two_player = false;
    require(argc == 3, "Expected the retail ISO and a test-only memory card directory");
#endif
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
    require(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD | SDL_INIT_AUDIO), "Initialize SDL");

    SDL_Window *window = SDL_CreateWindow("DaiOuJou gameplay test", 640, 480, SDL_WINDOW_HIDDEN);
    require(window != NULL, "Create test window");
    SDL_Renderer *renderer = (replay || GAME_RULE(0, demos)) ? SDL_CreateRenderer(window, NULL) : pc_create_renderer(window);
    require(renderer != NULL, "Create test renderer");
    require(pc_cdvd_mount(argv[1]) && pc_bgm_open(argv[1]) && pc_sfx_load(argv[1]), "Load retail assets");
    require(pc_mc_open_storage(argv[2]), "Open test memory card");

    SDL_Joystick *joystick = attach_controller();
    SDL_Joystick *second = two_player ? attach_controller() : NULL;

    pc_gs_bind_game(renderer);
    game_boot_begin();
#ifdef DDPDOJ_BONUS_FEATURES
    if (demos) {
        check_attract_demos(renderer);
        goto cleanup;
    }
#endif
    if (load_pools) {
        unsigned boot_frames = 0;
        while (!game_boot_frame()) {
            require(++boot_frames < MAX_FRAMES && pc_gs_ok() && SDL_RenderPresent(renderer),
                    "Boot the fresh process before resuming gameplay");
        }
        require(pc_game_load(load_pools, pool_mode, 1), "Load gameplay in a fresh process");
        require(has_relocated_enemy(), "Resolve the saved entity and callback in this process");
        char *oracle = NULL;
        require(SDL_asprintf(&oracle, "%s.expected", load_pools) >= 0, "Resolve oracle file");
        size_t size;
        ExpectedTrajectory *expected = SDL_LoadFile(oracle, &size);
        require(expected && size == sizeof(*expected), "Read expected gameplay trajectory");
        PcPlayerState restored;
        pc_player_state_capture(&restored);
        require(!memcmp(&restored, &expected->at_save, sizeof(restored)), "Restore the saved frame");
        run_trajectory(renderer, expected, true);
        SDL_free(expected);
        require(SDL_RemovePath(oracle), "Remove test oracle");
        SDL_free(oracle);
        require(SDL_RemovePath(load_pools), "Remove test slot");
        goto cleanup;
    }
    bool loaded = false, confirmed = false, bomb_finished = false;
    SDL_GamepadButton pressed = SDL_GAMEPAD_BUTTON_INVALID;
    unsigned played = 0, inputs = 0, shot_frames = 0, laser_frames = 0, bomb_frames = 0;
#ifdef DEATH_LABEL
    const unsigned bomb_at = 245;
#else
    const unsigned bomb_at = 95;
#endif
    unsigned together = 0;
    const unsigned max_frames = replay ? 30000 : MAX_FRAMES;
    for (unsigned frame = 0; frame < max_frames && played < GAMEPLAY_FRAMES; ++frame) {
#ifdef DDPDOJ_BONUS_FEATURES
        bool departing = g_black_label_active && g_ship_select_state[0] == 7;
        if (departing) ++departure_frames;
#endif
        if (pressed != SDL_GAMEPAD_BUTTON_INVALID) {
            require(SDL_SetJoystickVirtualButton(joystick, pressed, false), "Release controller button");
            pressed = SDL_GAMEPAD_BUTTON_INVALID;
        } else if (loaded && frame % 9 == 0) {
#ifndef DEATH_LABEL
            if (replay) {
                pressed = replay_menu_button(&confirmed, replay->slot);
            } else
#endif
            {
#ifdef DDPDOJ_BONUS_FEATURES
                if (departing) {
                    pressed = hover_one_round && departure_frames < 120
                        ? SDL_GAMEPAD_BUTTON_DPAD_UP : SDL_GAMEPAD_BUTTON_INVALID;
                } else
#endif
                {
                    pressed = next_button(&confirmed, &inputs);
                }
            }
            if (pressed != SDL_GAMEPAD_BUTTON_INVALID) {
                require(SDL_SetJoystickVirtualButton(joystick, pressed, true), "Press controller button");
            }
        }
        if (second && played > 60) {
            require(SDL_SetJoystickVirtualButton(second, SDL_GAMEPAD_BUTTON_START,
                                                  g_player2[0] >= 0 && frame % 12 == 0) &&
                    SDL_SetJoystickVirtualButton(second, SDL_GAMEPAD_BUTTON_EAST, frame % 5 == 0) &&
                    SDL_SetJoystickVirtualButton(second, SDL_GAMEPAD_BUTTON_WEST, frame % 300 < 175),
                    "Join and fire with the second controller");
        }
        bool laser = played >= 210 && played < 400 && player_active();
        bool bomb = played >= bomb_at && played < bomb_at + 6;
        require(SDL_SetJoystickVirtualButton(joystick, SDL_GAMEPAD_BUTTON_WEST, laser), "Set laser input");
        require(SDL_SetJoystickVirtualButton(joystick, SDL_GAMEPAD_BUTTON_SOUTH, bomb), "Set bomb input");
        SDL_PumpEvents();
        SDL_UpdateGamepads();
        pc_pad_capture();
        if (loaded) {
            game_run_frame();
        } else {
            loaded = game_boot_frame();
        }
        require(pc_gs_ok() && SDL_RenderPresent(renderer), "Render game frame");
        require(game_take_mode_request() == GAME_MODE_NONE, "Keep running the selected mode");
        if (save_pools && played >= 300 && has_relocated_enemy()) {
            ExpectedTrajectory *expected = SDL_calloc(1, sizeof(*expected));
            require(expected != NULL, "Allocate expected gameplay trajectory");
            pc_player_state_capture(&expected->at_save);
            require(pc_game_save(save_pools, pool_mode, 1), "Save live gameplay");
            if (pressed != SDL_GAMEPAD_BUTTON_INVALID)
                SDL_SetJoystickVirtualButton(joystick, pressed, false);
            SDL_SetJoystickVirtualButton(joystick, SDL_GAMEPAD_BUTTON_WEST, false);
            SDL_UpdateGamepads();
            run_trajectory(renderer, expected, false);
            require(pc_game_load(save_pools, pool_mode, 1), "Restore in the running process");
            run_trajectory(renderer, expected, true);
            char *oracle = NULL;
            require(SDL_asprintf(&oracle, "%s.expected", save_pools) >= 0 &&
                    SDL_SaveFile(oracle, expected, sizeof(*expected)), "Save reference trajectory");
            SDL_free(oracle);
            SDL_free(expected);
            goto cleanup;
        }

#ifndef DEATH_LABEL
        if (replay) {
            require(g_replay_pointer_not_found == 0, "Resolve every tagged replay address");
            if (g_replay_mode_begun == REPLAY_PLAYBACK && g_replay_position > replay_inputs) {
                replay_inputs = g_replay_position;
            }
            if (replay_inputs && g_replay_mode != REPLAY_PLAYBACK) {
                replay_finished = true;
                break;
            }
            continue;
        }
#endif
        shot_frames += g_player_shot_count != 0;
        laser_frames += g_player_laser_count != 0;
        if (g_bomb_entities[0] != 0) {
            ++bomb_frames;
        } else if (bomb_frames) {
            bomb_finished = true;
        }
        played += player_active();
        together += player_active() && g_player2[0] < 0;
    }

#ifndef DEATH_LABEL
    if (replay) {
        SDL_Log("Super Replay %02d consumed %d inputs and finished with score %x", replay->slot, replay_inputs, g_p1_score);
        require(replay_finished && replay_inputs == replay->inputs, "Finish the retail replay");
        require(g_p1_score == replay->final_score, "Match the retail final score");
    } else
#endif
    {
        SDL_Log("Played %u frames, %u with shots, %u with a laser, %u with a bomb, scroll line %u",
                played, shot_frames, laser_frames, bomb_frames, g_scroll_line);
        require(played == GAMEPLAY_FRAMES && g_scroll_line > 100, "Advance through gameplay");
        require(shot_frames > 100 && laser_frames > 30, "Fire shots and laser during gameplay");
        require(bomb_frames > 30 && bomb_finished, "Fire a bomb and complete its animation");
    }
#ifdef DDPDOJ_BONUS_FEATURES
    if (g_black_label_active) {
        check_boss_death_effect();
        require(departure_frames >= 120, "Run the departure animation during round selection");
        require(g_black_label_single_loop == hover_one_round, "Accept the highlighted round count without confirmation");
    }
#endif
    require(!save_pools, "Reach a live enemy for the combat snapshot");
    if (second) {
        require(together > 100 && g_p2_score != 0, "Both ships play and player two scores");
        SDL_CloseJoystick(second);
    }
cleanup:
    pc_bgm_close();
    pc_mc_close_storage();
    pc_sfx_shutdown();
    pc_cdvd_unmount();
    pc_pad_shutdown();
    pc_gs_bind_game(NULL);
    SDL_CloseJoystick(joystick);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
