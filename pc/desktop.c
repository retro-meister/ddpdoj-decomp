#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdlib.h>
#ifdef _WIN32
#include <process.h>
#else
#include <unistd.h>
#endif

#include "disc_image.h"
#include "mode_runtime.h"
#include "presentation.h"
#include "window_placement.h"

static const char *const titles[] = {
    [GAME_MODE_MAIN] = "DoDonPachi Dai-Ou-Jou",
#ifdef DDPDOJ_BONUS_FEATURES
    [GAME_MODE_BLACK_LABEL] = "DoDonPachi Dai-Ou-Jou - Black Label",
#endif
    [GAME_MODE_DEATH_LABEL] = "DoDonPachi Dai-Ou-Jou - Death Label",
    [GAME_MODE_GALLERY] = "DoDonPachi Dai-Ou-Jou - Gallery",
};

static char *preference_path(const char *name);

static bool run_modes(SDL_Window *window, SDL_Renderer *renderer, const char *iso, GameMode mode)
{
    static const char *const modules[] = {
        [GAME_MODE_MAIN] = "main-mode" MODE_SUFFIX,
#ifdef DDPDOJ_BONUS_FEATURES
        [GAME_MODE_BLACK_LABEL] = "main-mode" MODE_SUFFIX,
#endif
        [GAME_MODE_DEATH_LABEL] = "death-mode" MODE_SUFFIX,
        [GAME_MODE_GALLERY] = "gallery-mode" MODE_SUFFIX,
    };
    const char *base = SDL_GetBasePath();
    if (!base) {
        return false;
    }
    const char *directory = "";
#ifdef __APPLE__
    size_t length = SDL_strlen(base);
    if (length >= 5 && SDL_strcmp(base + length - 5, ".app/") == 0) {
        directory = "Contents/PlugIns/";
    }
#endif
    while (mode != GAME_MODE_NONE) {
        if (window) SDL_SetWindowTitle(window, titles[mode]);
        char *path = NULL;
        if (SDL_asprintf(&path, "%s%s%s", base, directory, modules[mode]) < 0) {
            return false;
        }
        SDL_SharedObject *module = SDL_LoadObject(path);
        if (!module) {
            SDL_free(path);
            return false;
        }
        PcRunMode *run = (PcRunMode *)SDL_LoadFunction(module, "pc_run_mode");
        GameMode next_mode = GAME_MODE_NONE;
        bool ok = run != NULL;
        if (ok && iso) {
            char *slot = preference_path("quick.state");
            ok = run(renderer, iso, path, slot, mode, &next_mode);
            SDL_free(slot);
        }
        SDL_free(path);
        mode = next_mode;
        SDL_UnloadObject(module);
        if (!ok) {
            return false;
        }
    }
    return true;
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
    selection->canceled = files && (!files[0] || !*files[0]);
    if (files && !selection->canceled) {
        selection->path = SDL_strdup(files[0]);
    }
    SDL_SetAtomicInt(&selection->done, 1);
}

static void choose_disc(SDL_Window *window, DiscSelection *selection)
{
    static const SDL_DialogFileFilter filters[] = { { "Retail PS2 disc image", "iso" } };
    SDL_ShowOpenFileDialog(disc_selected, selection, window, filters, 1, NULL, false);
    while (!SDL_GetAtomicInt(&selection->done)) {
        SDL_PumpEvents();
        SDL_Delay(10);
    }
}

static char *preference_path(const char *name)
{
    char *directory = SDL_GetPrefPath("DaiOuJou", "DaiOuJou");
    char *path = NULL;
    if (directory) {
        SDL_asprintf(&path, "%s%s", directory, name);
        SDL_free(directory);
    }
    return path;
}

static bool save_preference(const char *preference, const char *value)
{
#ifdef _WIN32
    int pid = _getpid();
#else
    int pid = getpid();
#endif
    char *temporary = NULL;
    bool saved = SDL_asprintf(&temporary, "%s.%d.tmp", preference, pid) >= 0 &&
                 SDL_SaveFile(temporary, value, SDL_strlen(value)) &&
                 SDL_RenamePath(temporary, preference);
    if (!saved && temporary) {
        SDL_RemovePath(temporary);
    }
    SDL_free(temporary);
    return saved;
}

static bool remember_disc(const char *preference, const char *iso)
{
#ifdef _WIN32
    wchar_t *wide = (wchar_t *)SDL_iconv_string("UTF-16LE", "UTF-8", iso, SDL_strlen(iso) + 1);
    wchar_t *full = wide ? _wfullpath(NULL, wide, 0) : NULL;
    SDL_free(wide);
    char *absolute = full ? SDL_iconv_string("UTF-8", "UTF-16LE", (const char *)full,
                                             (SDL_wcslen(full) + 1) * sizeof *full) : NULL;
    free(full);
#else
    char *absolute = realpath(iso, NULL);
#endif
    bool saved = absolute && save_preference(preference, absolute);
#ifdef _WIN32
    SDL_free(absolute);
#else
    free(absolute);
#endif
    return saved;
}

static bool is_game_disc(const char *iso)
{
    DiscImage *image = disc_image_open(iso);
    DiscExtent extent;
    bool valid = image && disc_image_find(image, "SLPS_252.33", &extent);
    disc_image_close(image);
    return valid || SDL_SetError("Could not open the Dai-Ou-Jou disc at %s", iso);
}

int main(int argc, char **argv)
{
    if (argc == 2 && SDL_strcmp(argv[1], "--check-install") == 0) {
        if (run_modes(NULL, NULL, NULL, START_MODE)) return 0;
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not load game module: %s", SDL_GetError());
        return 1;
    }
    if (argc > 2) {
        SDL_Log("Usage: %s [retail PS2 ISO]", argv[0]);
        return 1;
    }
    const char *title = titles[START_MODE];
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    DiscSelection selection = {0};
    WindowPlacement placement = {0};
    char *window_path = NULL;
    const char *iso = argc == 2 ? argv[1] : NULL;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD | SDL_INIT_AUDIO)) {
        window = SDL_CreateWindow(title, 768, 576, SDL_WINDOW_RESIZABLE |
                                  SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_HIDDEN);
        if (window) {
            window_path = preference_path("window-placement");
            char *geometry = window_path ? SDL_LoadFile(window_path, NULL) : NULL;
            pc_restore_window(&placement, window, geometry);
            SDL_free(geometry);
            renderer = pc_create_renderer(window);
        }
    }
    bool ok = renderer && SDL_ShowWindow(window);
    char *preference = ok ? preference_path("disc-path") : NULL;
    char *saved = preference ? SDL_LoadFile(preference, NULL) : NULL;
    bool validated = false;
    if (ok && !iso) {
        if (saved && is_game_disc(saved)) {
            iso = saved;
            validated = true;
        } else {
            choose_disc(window, &selection);
            iso = selection.path;
        }
    }
    if (ok && !selection.canceled) {
        ok = iso && (validated || is_game_disc(iso));
        if (ok && (!saved || SDL_strcmp(saved, iso) != 0) &&
            (!preference || !remember_disc(preference, iso))) {
            SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Could not save the disc location");
        }
        ok = ok && run_modes(window, renderer, iso, START_MODE);
    }
    if (!ok) {
        const char *error = SDL_GetError();
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Game stopped. %s", error);
        if (argc == 1 && window) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title,
                                     *error ? error : "Could not load the retail disc image.", window);
        }
    }

    if (window) {
        char geometry[96];
        if (pc_save_window(&placement, geometry, sizeof(geometry)) && window_path &&
            !save_preference(window_path, geometry)) {
            SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, "Could not save the window placement");
        }
    }
    SDL_free(window_path);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_free(saved);
    SDL_free(preference);
    SDL_free(selection.path);
    SDL_Quit();
    return ok ? 0 : 1;
}
