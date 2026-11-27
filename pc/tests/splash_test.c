#include "video.h"
#include "gs.h"
#include "disc_image.h"
#include "gfx.h"
#include "system.h"

#include <SDL3/SDL.h>

enum { SPLASH_FILE_BYTES = 0x20200 };

void splash_begin(void);
void splash_update(void);

static void require(bool condition, const char *message) {
    if (!condition) {
        SDL_LogError(SDL_LOG_CATEGORY_TEST, "%s (%s)", message, SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

static void load_picture(const char *iso_path) {
    if (iso_path) {
        DiscImage *disc = disc_image_open(iso_path);
        require(disc != NULL, "Open retail disc");
        DiscExtent picture;
        require(disc_image_find(disc, "DATA/ARIKA.8", &picture), "Find original splash");
        require(picture.size == SPLASH_FILE_BYTES, "Validate original splash size");
        require(disc_image_read(disc, (uint64_t)picture.lba * DISC_SECTOR_SIZE,
                                g_splash_file_buf, picture.size), "Read original splash");
        disc_image_close(disc);
    } else {
        /* Index 22 maps to physical CLUT slot 14; leave directly addressed slot 22 black. */
        g_splash_file_buf[28] = 0xC1;
        g_splash_file_buf[29] = 0xFC;
        g_splash_file_buf[512 + 512 * 112 + 224] = 22;
        g_splash_file_buf[512 + 512 * 112 + 448] = 22;
    }
}

static void expect_pixel(SDL_Surface *surface, int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
    Uint8 r, g, b, a;
    require(SDL_ReadSurfacePixel(surface, x, y, &r, &g, &b, &a), "Read the rendered frame");
    if (r != red || g != green || b != blue || a != 255) {
        SDL_LogError(SDL_LOG_CATEGORY_TEST, "Pixel (%d,%d) was rgba(%u,%u,%u,%u); expected (%u,%u,%u,255)",
                     x, y, r, g, b, a, red, green, blue);
        exit(EXIT_FAILURE);
    }
}

static void check_menu_overlay(SDL_Renderer *renderer) {
    render_target_init(&g_render_target, g_gif_buf, 0x12C0, 512, 256);
    render_target_begin(&g_render_target, g_gif_buf);
    require(SDL_SetRenderDrawColor(renderer, 240, 240, 240, 255) && SDL_RenderClear(renderer),
            "Clear the menu background");
    gfx_draw_color_box(0, 0, 450, 224, 80, 96, 1, 1, 1);
    require(pc_gs_ok(), "Draw the menu overlay");
    SDL_Surface *pixels = SDL_RenderReadPixels(renderer, NULL);
    require(pixels != NULL, "Read the menu target");

    /* The upright view rotates target rows 16..239 across the playfield. */
    Uint8 r, g, b;
    require(SDL_ReadSurfacePixel(pixels, 200, 120, &r, &g, &b, NULL) &&
            r >= 58 && r <= 62 && g == r && b == r, "Darken the center of the menu");
    expect_pixel(pixels, 200, 18, r, g, b);
    expect_pixel(pixels, 200, 238, r, g, b);
    expect_pixel(pixels, 200, 12, 240, 240, 240);
    expect_pixel(pixels, 200, 244, 240, 240, 240);
    SDL_DestroySurface(pixels);
}

int main(int argc, char **argv) {
    const char *driver = NULL;
    int next_argument = 1;
    if (argc >= 3 && SDL_strcmp(argv[1], "--renderer") == 0) {
        driver = argv[2];
        next_argument = 3;
    }
    require(SDL_Init(driver ? SDL_INIT_VIDEO : 0), "Initialize SDL");
    load_picture(next_argument < argc ? argv[next_argument] : NULL);
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    SDL_Renderer *renderer;
    if (driver) {
        window = SDL_CreateWindow("DaiOuJou splash test", 512, 224, SDL_WINDOW_HIDDEN);
        require(window != NULL, "Create the hidden test window");
        renderer = SDL_CreateRenderer(window, driver);
    } else {
        surface = SDL_CreateSurface(512, 224, SDL_PIXELFORMAT_RGBA32);
        require(surface != NULL, "Create the render target");
        renderer = SDL_CreateSoftwareRenderer(surface);
    }
    require(renderer != NULL, "Create the renderer");
    pc_video_bind(renderer);
    pc_gs_bind_game(renderer);
    g_dma_gif = sceDmaGetChan(SCE_DMA_GIF);
    framebuffer_begin(g_gif_buf);
    splash_begin();
    int frame = 0;
    do {
        require(++frame <= 300, "Splash did not finish");
        require(SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255) && SDL_RenderClear(renderer),
                "Clear the frame");
        splash_update();
        splash_image_draw();
        fade_update_and_draw();
        require(pc_video_ok() && pc_gs_ok(), "Draw the splash and fade");
        SDL_Surface *readback = NULL;
        if (frame == 1 || frame == 40 || !cond_flag) {
            readback = SDL_RenderReadPixels(renderer, NULL);
            require(readback != NULL, "Read the framebuffer");
        }
        if (frame == 1) {
            expect_pixel(readback, 224, 112, 1, 1, 1);
        }
        if (frame == 40) {
            expect_pixel(readback, 224, 112, 8, 48, 248);
            expect_pixel(readback, 448, 112, 0, 0, 0);
        }
        if (!cond_flag) {
            expect_pixel(readback, 224, 112, 0, 0, 0);
        }
        SDL_DestroySurface(readback);
        require(SDL_RenderPresent(renderer), "Present the frame");
    } while (cond_flag);
    require(frame == 277, "The original fade and hold must consume 277 game frames");
    require(g_splash_visible == 0, "The splash must release control to the attract task");
    check_menu_overlay(renderer);
    pc_gs_bind_gallery(NULL);
    pc_video_bind(NULL);
    SDL_DestroyRenderer(renderer);
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_DestroySurface(surface);
    SDL_Log("Splash passed with renderer %s", driver ? driver : "software");
    SDL_Quit();
    return EXIT_SUCCESS;
}
