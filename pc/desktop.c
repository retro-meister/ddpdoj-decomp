#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "cdvd.h"
#include "game_loop.h"
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
#include "video.h"
#endif

static bool start_mode(GameMode mode, const char *iso)
{
    static const char *const executables[] = {
        [GAME_MODE_MAIN] = "ddpdoj",
        [GAME_MODE_DEATH_LABEL] = "ddpdoj-death",
        [GAME_MODE_GALLERY] = "ddpdoj-gallery",
    };
#ifdef _WIN32
    const char *suffix = ".exe";
#else
    const char *suffix = "";
#endif
    char *path = NULL;
    const char *base = SDL_GetBasePath();
    if (!base) {
        return false;
    }
    const char *directory = "";
#ifdef __APPLE__
    size_t length = SDL_strlen(base);
    if (length >= 5 && SDL_strcmp(base + length - 5, ".app/") == 0) {
        directory = "Contents/MacOS/";
    }
#endif
    if (SDL_asprintf(&path, "%s%s%s%s", base, directory, executables[mode], suffix) < 0) {
        return false;
    }
    const char *args[] = { path, iso, NULL };
    SDL_PropertiesID properties = SDL_CreateProperties();
    SDL_Process *process = NULL;
    if (properties &&
        SDL_SetPointerProperty(properties, SDL_PROP_PROCESS_CREATE_ARGS_POINTER, args) &&
        SDL_SetBooleanProperty(properties, SDL_PROP_PROCESS_CREATE_BACKGROUND_BOOLEAN, true)) {
        process = SDL_CreateProcessWithProperties(properties);
    }
    SDL_DestroyProperties(properties);
    SDL_free(path);
    if (!process) {
        return false;
    }
    SDL_DestroyProcess(process);
    return true;
}

static bool process_input(void)
{
    pc_wait_to_poll_input();
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
    while (process_input()) {
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
    pc_video_bind(renderer);
    game_boot_begin();
    bool loaded = false;
    while (process_input()) {
        if (loaded) {
            game_run_frame();
        } else {
            loaded = game_boot_frame();
        }
        if (!pc_gs_ok() || !pc_video_ok() || !SDL_RenderPresent(renderer)) {
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

typedef struct {
    SDL_AtomicInt done;
    char *path;
    bool canceled;
} DiscSelection;

static void SDLCALL disc_selected(void *userdata, const char *const *files, int filter)
{
    DiscSelection *selection = userdata;
    (void)filter;
    selection->canceled = files && !files[0];
    if (files && files[0]) {
        selection->path = SDL_strdup(files[0]);
    }
    SDL_SetAtomicInt(&selection->done, 1);
}

static void choose_disc(SDL_Window *window, DiscSelection *selection)
{
    static const SDL_DialogFileFilter filters[] = { { "Retail PS2 disc image", "iso" } };
    SDL_ShowOpenFileDialog(disc_selected, selection, window, filters, 1, NULL, false);
    while (!SDL_GetAtomicInt(&selection->done)) {
        SDL_Event event;
        if (SDL_WaitEventTimeout(&event, 20)) {
            pc_pad_handle_event(&event);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc > 2) {
        SDL_Log("Usage: %s [retail PS2 ISO]", argv[0]);
        return 1;
    }
#if defined(DDPDOJ_GALLERY_HOST)
    const char *title = "DoDonPachi Dai-Ou-Jou - Gallery";
#elif defined(DEATH_LABEL)
    const char *title = "DoDonPachi Dai-Ou-Jou - Death Label";
#else
    const char *title = "DoDonPachi Dai-Ou-Jou";
#endif
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    DiscSelection selection = {0};
    const char *iso = argc == 2 ? argv[1] : NULL;
    GameMode next_mode = GAME_MODE_NONE;
    bool ok = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD | SDL_INIT_AUDIO) &&
        SDL_CreateWindowAndRenderer(title, 768, 576, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY,
                                    &window, &renderer);
    if (ok && !iso) {
        choose_disc(window, &selection);
        iso = selection.path;
    }
    if (ok && !selection.canceled) {
        ok = iso && pc_cdvd_mount(iso) && pc_sfx_load(iso) && pc_sfx_open_device() &&
             run_mode(renderer, iso, &next_mode);
    }
    if (!ok) {
        const char *error = SDL_GetError();
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Game stopped. %s", error);
        if (argc == 1 && window) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title,
                                     *error ? error : "Could not load the retail disc image.", window);
        }
    }

#ifndef DDPDOJ_GALLERY_HOST
    pc_bgm_close();
    pc_mc_close_storage();
    pc_video_bind(NULL);
#endif
    pc_sfx_shutdown();
    pc_cdvd_unmount();
    pc_pad_shutdown();
    pc_gs_bind_gallery(NULL);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    if (ok && next_mode != GAME_MODE_NONE && !start_mode(next_mode, iso)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not launch the selected mode. %s", SDL_GetError());
        ok = false;
    }
    SDL_free(selection.path);
    SDL_Quit();
    return ok ? 0 : 1;
}
