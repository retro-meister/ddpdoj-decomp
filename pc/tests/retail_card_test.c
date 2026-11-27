#include "cdvd.h"
#include "game_loop.h"
#include "gs.h"
#include "memory_card.h"
#include "pad.h"
#include "pc_replay_storage.h"
#include "sfx.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdlib.h>

extern u8 g_mc_task, g_mc_step, g_mc_choice, g_setting_difficulty;
extern s32 g_mc_operation_done, g_mc_save_succeeded, g_mc_load_succeeded;
void mc_save_update(s32 slot);
void mc_load_update(s32 slot);
void mc_replay_load_begin(s32 slot);
void save_block_to_settings(void);

static void require(bool condition, const char *message)
{
    if (!condition) {
        SDL_LogError(SDL_LOG_CATEGORY_TEST, "%s (%s)", message, SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

s32 sceGsSyncV(s32 mode)
{
    (void)mode;
    return 0;
}

static void card_operation(bool save, int slot)
{
    g_mc_operation_done = 0;
    for (unsigned frame = 0; frame < 4000 && !g_mc_operation_done; ++frame) {
        /* Select Yes on the original save, overwrite and load prompts. */
        bool prompt = g_mc_task == 0xa || g_mc_task == 0x12 || g_mc_task == 0x14;
        g_pad_trigger[2] = 0;
        if ((prompt && g_mc_step <= 2 && g_mc_choice) || frame % 4 == 0) {
            g_pad_trigger[2] = 0x8000;
        } else if (frame % 4 == 2) {
            g_pad_trigger[2] = 0x20;
        }
        if (save) mc_save_update(slot);
        else if (slot) mc_replay_load_begin(slot);
        else mc_load_update(slot);
        SDL_Delay(1);
    }
    require(g_mc_operation_done && (save ? g_mc_save_succeeded : g_mc_load_succeeded),
            save ? "Complete the original save dialog" : "Complete the original load dialog");
}

static void verify_icon(const char *card, const char *directory)
{
    char *path = NULL;
    require(SDL_asprintf(&path, "%s/card1/%s/icon.sys", card, directory) >= 0, "Find saved icon");
    size_t size;
    u8 *icon = SDL_LoadFile(path, &size);
    require(icon && size == 0x3c4 && SDL_memcmp(icon, "PS2D", 4) == 0 &&
            icon[6] == 14 && icon[12] == 96 && icon[0xc0] != 0 &&
            SDL_memcmp(icon + 0x104, "icon1.ico", 10) == 0 &&
            SDL_memcmp(icon + 0x144, "icon1.ico", 10) == 0 &&
            SDL_memcmp(icon + 0x184, "icon1.ico", 10) == 0, "Write the original icon.sys layout");
    SDL_free(icon);
    SDL_free(path);
}

int main(int argc, char **argv)
{
    require(argc == 3 && SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD | SDL_INIT_AUDIO), "Open SDL");
    SDL_Window *window;
    SDL_Renderer *renderer;
    require(SDL_CreateWindowAndRenderer("Card test", 640, 480, SDL_WINDOW_HIDDEN, &window, &renderer) &&
            pc_mc_open_storage(argv[2]) && pc_cdvd_mount(argv[1]) && pc_sfx_load(argv[1]), "Open test disc and card");
    pc_gs_bind_game(renderer);
    game_boot_begin();

    g_setting_difficulty = 3;
    card_operation(true, 0);
    verify_icon(argv[2], "BISLPS-25233");
    g_setting_difficulty = 0;
    card_operation(false, 0);
    save_block_to_settings();
    require(g_setting_difficulty == 3, "Restore the saved difficulty");

    static u8 expected[PC_REPLAY_CARD_SIZE];
    for (size_t i = 0; i < sizeof(expected); ++i) g_replay_file_loaded[i] = (u8)(i * 7 + i / 256);
    card_operation(true, 1);
    verify_icon(argv[2], "BISLPS-25233REPLAY1");
    SDL_memcpy(expected, g_replay_file_loaded, sizeof(expected));
    SDL_memset(g_replay_file_loaded, 0, sizeof(expected));
    card_operation(false, 1);
    require(SDL_memcmp(expected, g_replay_file_loaded, sizeof(expected)) == 0, "Reload the complete replay file");

    pc_mc_close_storage();
    pc_cdvd_unmount();
    pc_sfx_shutdown();
    pc_gs_bind_game(NULL);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
