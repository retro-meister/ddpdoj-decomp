#include "mode_runtime.h"

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
#include "pc_sound.h"
#endif

static bool process_input(SDL_Renderer *renderer)
{
    pc_wait_to_poll_input(renderer);
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            return false;
        }
        pc_pad_handle_event(&event);
    }
    pc_pad_capture();
    return true;
}

static bool run_mode(SDL_Renderer *renderer, const char *iso, GameMode *next_mode)
{
#ifdef DDPDOJ_GALLERY_HOST
    (void)iso;
    pc_gs_bind_gallery(renderer);
    if (gallery_boot() != 1) {
        return false;
    }
    bool ok = true;
    while (process_input(renderer)) {
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
        if (!SDL_RenderPresent(renderer)) {
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
    while (process_input(renderer)) {
        if (loaded) {
            game_run_frame();
        } else {
            loaded = game_boot_frame();
        }
        if (!pc_gs_ok() || !SDL_RenderPresent(renderer)) {
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

bool pc_run_mode(SDL_Renderer *renderer, const char *iso, GameMode *next_mode)
{
    pc_pad_open_connected();
    bool ok = pc_cdvd_mount(iso) && pc_sfx_load(iso) && pc_sfx_open_device() &&
              run_mode(renderer, iso, next_mode);
#ifndef DDPDOJ_GALLERY_HOST
    pc_bgm_close();
    pc_mc_close_storage();
#endif
    pc_sfx_shutdown();
    pc_cdvd_unmount();
    pc_pad_shutdown();
    pc_gs_bind_gallery(NULL);
    SDL_SetRenderClipRect(renderer, NULL);
    return ok;
}
