#include "cdvd.h"
#include "game_loop.h"
#include "gs.h"
#include "memory_card.h"
#include "pc_input.h"
#include "pc_sound.h"
#include "sdk/libgraph.h"
#include "sfx.h"
#include "video.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdlib.h>

extern u16 g_attract_step;
extern s8 g_menu_page, g_menu_main_step, g_menu_arcade_step, g_menu_cursor;
extern s16 g_player1[];
extern u16 g_game_frame, g_player_shot_count, g_player_laser_count, g_scroll_line;
extern u16 g_bomb_entities[];
extern u8 g_game_frame_ran;

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
#endif
        return SDL_GAMEPAD_BUTTON_EAST;
    }
    return SDL_GAMEPAD_BUTTON_INVALID;
}

int main(int argc, char **argv)
{
    require(argc == 3, "Expected the retail ISO and a test-only memory card directory");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
    require(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD | SDL_INIT_AUDIO), "Initialize SDL");

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    require(SDL_CreateWindowAndRenderer("DaiOuJou gameplay test", 640, 480, SDL_WINDOW_HIDDEN,
                                        &window, &renderer), "Create test renderer");
    require(pc_cdvd_mount(argv[1]) && pc_bgm_open(argv[1]) && pc_sfx_load(argv[1]), "Load retail assets");
    require(pc_mc_open_storage(argv[2]), "Open test memory card");

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

    pc_gs_bind_game(renderer);
    pc_video_bind(renderer);
    game_boot_begin();
    bool loaded = false, confirmed = false, bomb_finished = false;
    SDL_GamepadButton pressed = SDL_GAMEPAD_BUTTON_INVALID;
    unsigned played = 0, inputs = 0, shot_frames = 0, laser_frames = 0, bomb_frames = 0;
#ifdef DEATH_LABEL
    const unsigned bomb_at = 245;
#else
    const unsigned bomb_at = 95;
#endif
    for (unsigned frame = 0; frame < MAX_FRAMES && played < GAMEPLAY_FRAMES; ++frame) {
        if (pressed != SDL_GAMEPAD_BUTTON_INVALID) {
            require(SDL_SetJoystickVirtualButton(joystick, pressed, false), "Release controller button");
            pressed = SDL_GAMEPAD_BUTTON_INVALID;
        } else if (loaded && frame % 9 == 0) {
            pressed = next_button(&confirmed, &inputs);
            if (pressed != SDL_GAMEPAD_BUTTON_INVALID) {
                require(SDL_SetJoystickVirtualButton(joystick, pressed, true), "Press controller button");
            }
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
        require(pc_gs_ok() && pc_video_ok() && SDL_RenderPresent(renderer), "Render game frame");
        require(game_take_mode_request() == GAME_MODE_NONE, "Keep running the selected mode");

        shot_frames += g_player_shot_count != 0;
        laser_frames += g_player_laser_count != 0;
        if (g_bomb_entities[0] != 0) {
            ++bomb_frames;
        } else if (bomb_frames) {
            bomb_finished = true;
        }
        played += player_active();
    }

    SDL_Log("Played %u frames, %u with shots, %u with a laser, %u with a bomb, scroll line %u",
            played, shot_frames, laser_frames, bomb_frames, g_scroll_line);
    require(played == GAMEPLAY_FRAMES && g_scroll_line > 100, "Advance through gameplay");
    require(shot_frames > 100 && laser_frames > 30, "Fire shots and laser during gameplay");
    require(bomb_frames > 30 && bomb_finished, "Fire a bomb and complete its animation");
    pc_bgm_close();
    pc_mc_close_storage();
    pc_video_bind(NULL);
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
