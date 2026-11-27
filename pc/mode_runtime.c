#include "mode_runtime.h"
#include "black_label.h"

#include "cdvd.h"
#include "gs.h"
#include "pc_input.h"
#include "sfx.h"
#include "vblank.h"

#ifdef DDPDOJ_GALLERY_HOST
#include "gallery/gallery.h"
#include "sdk/libgraph.h"
#else
#include "memory_card.h"
#include "game_snapshot.h"
#include "pc_sound.h"
#endif

static bool process_input(SDL_Renderer *renderer, bool *present, SDL_Scancode *state_key)
{
    pc_wait_to_poll_input(renderer);
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            return false;
        }
        if (state_key && event.type == SDL_EVENT_KEY_DOWN && !event.key.repeat &&
            (event.key.scancode == SDL_SCANCODE_F1 || event.key.scancode == SDL_SCANCODE_F2)) {
            *state_key = event.key.scancode;
        }
        pc_pad_handle_event(&event);
    }
    bool held = SDL_GetKeyboardFocus() == SDL_GetRenderWindow(renderer) &&
                SDL_GetKeyboardState(NULL)[SDL_SCANCODE_TAB];
    *present = pc_frame_should_present(held);
    pc_gs_skip_window_draws(!*present);
    pc_pad_capture();
    return true;
}

#ifndef DDPDOJ_GALLERY_HOST
static bool handle_state_key(SDL_Scancode key, const char *module_path, GameMode mode)
{
    static Uint64 build;
    if (!build) {
        size_t size;
        void *module = SDL_LoadFile(module_path, &size);
        if (!module) return false;
        build = (Uint64)size << 32 | SDL_crc32(0, module, size);
        SDL_free(module);
    }
    char *directory = SDL_GetPrefPath("DaiOuJou", "DaiOuJou");
    if (!directory) return false;
    char *path = NULL;
    bool ok = SDL_asprintf(&path, "%squick.state", directory) >= 0;
    SDL_free(directory);
    if (ok) ok = key == SDL_SCANCODE_F1 ? pc_game_save(path, mode, build) :
                                          pc_game_load(path, mode, build);
    SDL_free(path);
    return ok;
}
#endif

static bool run_mode(SDL_Renderer *renderer, const char *iso, const char *module_path, GameMode mode, GameMode *next_mode)
{
#ifdef DDPDOJ_GALLERY_HOST
    (void)iso;
    (void)module_path;
    (void)mode;
    pc_gs_bind_gallery(renderer);
    if (gallery_boot() != 1) {
        return false;
    }
    bool ok = true;
    bool present;
    while (process_input(renderer, &present, NULL)) {
        s32 state = gallery_run_frame();
        if (state < 0) {
            ok = false;
            break;
        }
        if (state == 0) {
            *next_mode = game_take_mode_request();
            break;
        }
        sceGsSyncV(0);
        if (present && !SDL_RenderPresent(renderer)) {
            ok = false;
            break;
        }
    }
    gallery_end_frames();
    return ok;
#else
    if (!pc_bgm_open(iso)) {
        return false;
    }
    pc_gs_bind_game(renderer);
    game_boot_begin();
    bool loaded = false;
    bool present;
    SDL_Scancode state_key = SDL_SCANCODE_UNKNOWN;
    while (process_input(renderer, &present, &state_key)) {
        if (loaded && state_key != SDL_SCANCODE_UNKNOWN) {
            if (!handle_state_key(state_key, module_path, mode)) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Savestate: %s", SDL_GetError());
            }
        }
        state_key = SDL_SCANCODE_UNKNOWN;
        if (loaded) {
            game_run_frame();
        } else {
            loaded = game_boot_frame();
        }
        if (!pc_gs_ok() || (present && !SDL_RenderPresent(renderer))) {
            return false;
        }
        *next_mode = game_take_mode_request();
        if (*next_mode != GAME_MODE_NONE) {
            break;
        }
    }
    return true;
#endif
}

/* Unloading this module after the call restores the mode's initial game RAM. */
#ifdef _WIN32
__declspec(dllexport)
#endif
PcRunMode pc_run_mode;

bool pc_run_mode(SDL_Renderer *renderer, const char *iso, const char *module_path, GameMode mode, GameMode *next_mode)
{
#ifdef DDPDOJ_BONUS_FEATURES
    g_black_label_active = mode == GAME_MODE_BLACK_LABEL;
#else
    (void)mode;
#endif
    pc_pad_open_connected();
    bool ok = pc_cdvd_mount(iso) && pc_sfx_load(iso) && pc_sfx_open_device() &&
              run_mode(renderer, iso, module_path, mode, next_mode);
#ifndef DDPDOJ_GALLERY_HOST
    pc_bgm_close();
    pc_mc_close_storage();
#endif
    pc_gs_skip_window_draws(false);
    pc_sfx_shutdown();
    pc_cdvd_unmount();
    pc_pad_shutdown();
    pc_gs_bind_gallery(NULL);
    SDL_SetRenderClipRect(renderer, NULL);
    return ok;
}
