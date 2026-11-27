#include "cdvd.h"
#include "gallery/gallery.h"
#include "game_loop.h"
#include "gs.h"
#include "pc_input.h"
#include "presentation.h"
#include "sfx.h"

#include <SDL3/SDL.h>

static void require(bool condition, const char *message)
{
    if (!condition) {
        SDL_LogError(SDL_LOG_CATEGORY_TEST, "%s (%s)", message, SDL_GetError());
        if (g_gallery) {
            SDL_LogError(SDL_LOG_CATEGORY_TEST,
                         "Gallery mode %d state %d substate %d step %d, asset error %d, disc error %d",
                         g_gallery->mode, g_gallery->state, g_gallery->subState, g_gallery->stepState,
                         g_gallery->assetError, g_cd_io_error);
        }
        exit(EXIT_FAILURE);
    }
}

static s32 frame(void)
{
    SDL_UpdateGamepads();
    pc_pad_capture();
    s32 running = gallery_run_frame();
    require(running >= 0, "Advance the original Gallery frame");
    return running;
}

static void wait_for(GalleryMode mode, s32 state)
{
    for (unsigned step = 0; step < 2000; step++) {
        if (g_gallery->mode == (s32)mode && g_gallery->state == state) {
            return;
        }
        require(frame() == 1, "Gallery exited before reaching the requested state");
        if (g_cd_async_busy) {
            SDL_Delay(1);
        }
    }
    SDL_LogError(SDL_LOG_CATEGORY_TEST, "Expected Gallery mode %d state %d", mode, state);
    require(false, "Gallery did not reach the requested state");
}

static void press(SDL_Joystick *controller, SDL_GamepadButton button)
{
    require(SDL_SetJoystickVirtualButton(controller, button, true), "Press a Gallery button");
    require(frame() == 1, "Advance the Gallery input frame");
    require(SDL_SetJoystickVirtualButton(controller, button, false), "Release a Gallery button");
    require(frame() == 1, "Advance the Gallery release frame");
}

static u64 artwork_digest(SDL_Renderer *renderer, SDL_Rect area)
{
    SDL_Surface *pixels = SDL_RenderReadPixels(renderer, &area);
    require(pixels != NULL, "Read Gallery artwork");
    unsigned colors = 0;
    u64 hash = 0xcbf29ce484222325ULL;
    for (int y = 0; y < pixels->h; y += 5) {
        for (int x = 0; x < pixels->w; x += 5) {
            u8 r, g, b;
            require(SDL_ReadSurfacePixel(pixels, x, y, &r, &g, &b, NULL), "Sample Gallery artwork");
            colors += (r != g || g != b);
            hash ^= ((u32)r << 16) | ((u32)g << 8) | b;
            hash *= 0x100000001b3ULL;
        }
    }
    SDL_DestroySurface(pixels);
    require(colors > 16, "Gallery should draw visible colored artwork");
    return hash;
}

static void wait_for_viewer(void)
{
    wait_for(GALLERY_MODE_VIEWER, 11);
    for (unsigned i = 0; i < 160 && g_gallery->curSprite->state != 0; i++) {
        require(frame() == 1, "Finish the original viewer animation");
    }
    require(g_gallery->curSprite->state == 0, "Viewer is ready for input");
}

static void expect_audio(int pcm_at_start, int pcm_at_333, int volume)
{
    float samples[334];
    require(pc_sfx_render(samples, SDL_arraysize(samples)), "Mix the Gallery sound effect");
    float gain = volume / (255.0f * 32768.0f);
    require(SDL_fabsf(samples[28] - pcm_at_start * gain) < 0.000001f &&
            SDL_fabsf(samples[333] - pcm_at_333 * gain) < 0.000001f,
            "Menu action plays the expected retail PCM at the original requested volume");
    pc_sfx_stop_all();
}

int main(int argc, char **argv)
{
    bool audio_device = argc == 3 && SDL_strcmp(argv[2], "--audio-device") == 0;
    require(argc == 2 || audio_device, "Expected the retail ISO path and optional --audio-device");
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
    require(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD), "Initialize desktop video and input");
    SDL_Window *window = SDL_CreateWindow("Gallery boot test", 640, 448, SDL_WINDOW_HIDDEN);
    require(window != NULL, "Create the Gallery test window");
#ifdef _WIN32
    SDL_Renderer *renderer = SDL_CreateRenderer(window, "direct3d11");
#else
    SDL_Renderer *renderer = pc_create_renderer(window);
#endif
    require(renderer != NULL, "Create the Gallery renderer");
    pc_gs_bind_gallery(renderer);
    require(gallery_boot() == 0 && g_gallery == NULL, "Gallery requires a mounted disc");
    require(pc_cdvd_mount(argv[1]), "Mount the retail disc");
    require(pc_sfx_load(argv[1]), "Load and decode the retail sound effects");

    SDL_VirtualJoystickDesc desc;
    SDL_INIT_INTERFACE(&desc);
    desc.type = SDL_JOYSTICK_TYPE_GAMEPAD;
    desc.nbuttons = SDL_GAMEPAD_BUTTON_COUNT;
    desc.naxes = SDL_GAMEPAD_AXIS_COUNT;
    SDL_JoystickID id = SDL_AttachVirtualJoystick(&desc);
    require(id != 0, "Attach a virtual Gallery controller");
    SDL_Joystick *controller = SDL_OpenJoystick(id);
    require(controller != NULL, "Open the Gallery controller");
    SDL_Event event = { .gdevice = { .type = SDL_EVENT_GAMEPAD_ADDED, .which = id } };
    pc_pad_handle_event(&event);

    require(gallery_boot() == 1, "Initialize Gallery from the retail disc");
    require(gallery_boot() == 0, "Reject a duplicate Gallery boot");
    wait_for(GALLERY_MODE_GRID, 20);
    artwork_digest(renderer, (SDL_Rect){ 72, 90, 450, 200 });
    press(controller, SDL_GAMEPAD_BUTTON_DPAD_RIGHT);
    require(g_gallery->menu.selection == 1, "Move the Gallery cursor");
    expect_audio(-448, 612, 0x94 - 30);
    g_system_mute = 1;
    press(controller, SDL_GAMEPAD_BUTTON_DPAD_LEFT);
    require(g_gallery->menu.selection == 0, "Move the Gallery cursor back");
    expect_audio(0, 0, 0x94 - 30);
    g_system_mute = 0;
    press(controller, SDL_GAMEPAD_BUTTON_EAST);
    expect_audio(-192, 6234, 0xFF - 30);
    wait_for_viewer();
    press(controller, SDL_GAMEPAD_BUTTON_START);
    wait_for_viewer();
    require(!g_gallery->showHelp, "Toggle the original viewer help panel");
    SDL_Rect center = { 200, 120, 240, 208 };
    u64 first_artwork = artwork_digest(renderer, center);
    press(controller, SDL_GAMEPAD_BUTTON_NORTH);
    wait_for_viewer();
    require(g_gallery->curSprite->zoomed != 0 && artwork_digest(renderer, center) != first_artwork,
            "Zoom changes the original viewer image");
    pc_sfx_stop_all();
    press(controller, SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER);
    expect_audio(32, -27, 0x80 - 30);
    wait_for_viewer();
    require(g_gallery->activeBuffer == 1 && artwork_digest(renderer, center) != first_artwork,
            "Next image displays a different artwork from the original disc");
    press(controller, SDL_GAMEPAD_BUTTON_SOUTH);
    wait_for(GALLERY_MODE_GRID, 20);
    press(controller, SDL_GAMEPAD_BUTTON_SOUTH);
    wait_for(GALLERY_MODE_GRID, 41);
    press(controller, SDL_GAMEPAD_BUTTON_DPAD_LEFT);
    press(controller, SDL_GAMEPAD_BUTTON_EAST);

    s32 running = 1;
    for (unsigned i = 0; i < 120 && running; i++) {
        running = frame();
    }
    require(running == 0 && game_take_mode_request() == GAME_MODE_MAIN,
            "Gallery requests the Main menu after the exit fade");
    gallery_end_frames();
    require(g_gallery == NULL && g_vram_load_buf == NULL, "Gallery frees its mode data");
    pc_gs_bind_gallery(renderer);
    require(gallery_boot() == 1 && frame() == 1, "Re-enter Gallery in the same process");
    if (audio_device) {
        require(SDL_InitSubSystem(SDL_INIT_AUDIO) && pc_sfx_open_device(), "Open SDL playback");
        wait_for(GALLERY_MODE_GRID, 20);
        press(controller, SDL_GAMEPAD_BUTTON_DPAD_RIGHT);
        require(g_gallery->menu.selection == 1, "Play a cursor cue through the open SDL device");
        SDL_Delay(275);
    }
    gallery_end_frames();

    pc_pad_shutdown();
    SDL_CloseJoystick(controller);
    SDL_DetachVirtualJoystick(id);
    pc_sfx_shutdown();
    pc_cdvd_unmount();
    pc_gs_bind_gallery(NULL);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
