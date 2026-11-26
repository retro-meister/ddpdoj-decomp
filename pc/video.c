#include "video.h"
#include "gfx.h"
#include "system.h"

#include <SDL3/SDL.h>

enum {
    SPLASH_WIDTH = 512,
    SPLASH_HEIGHT = 256,
    SPLASH_TEXTURE = 0x2240,
    SPLASH_PALETTE = 0x3836,
    SPLASH_PALETTE_SIZE = 512,
};

static SDL_Renderer *output;
static SDL_Texture *splash;
static bool video_failed;

s8 g_fade_state;
s16 g_fade_step;
s16 g_fade_alpha;
#ifdef DEATH_LABEL
s8 g_fade_white;
#endif

void pc_video_bind(SDL_Renderer *renderer) {
    SDL_DestroyTexture(splash);
    splash = NULL;
    output = renderer;
    video_failed = false;
}

bool pc_video_ok(void) {
    return !video_failed;
}

static void palette_rgba8(const u8 *clut, SDL_Color *colors) {
    /* The 256-color GS CLUT exchanges entries 8–15 and 16–23 in each group of 32. */
    for (unsigned int i = 0; i < 256; ++i) {
        unsigned int slot = (i & ~0x18u) | ((i & 8) << 1) | ((i & 16) >> 1);
        u16 rgb = (u16)(clut[2 * slot] | (clut[2 * slot + 1] << 8));
        colors[i] = (SDL_Color){
            (u8)((rgb & 31) << 3),
            (u8)(((rgb >> 5) & 31) << 3),
            (u8)(((rgb >> 10) & 31) << 3),
            (rgb & 0x8000) ? 255 : 0,
        };
    }
}

void splash_image_upload(void) {
    g_tex_upload_tbp = SPLASH_TEXTURE;
    if (!output) {
        video_failed = true;
        return;
    }
    if (splash) {
        return;
    }
    SDL_Color colors[256];
    palette_rgba8(g_splash_file_buf, colors);
    SDL_Surface *image = SDL_CreateSurface(SPLASH_WIDTH, SPLASH_HEIGHT, SDL_PIXELFORMAT_RGBA32);
    if (!image) {
        video_failed = true;
        return;
    }
    const u8 *indices = g_splash_file_buf + SPLASH_PALETTE_SIZE;
    for (int y = 0; y < SPLASH_HEIGHT; ++y) {
        u8 *destination = (u8 *)image->pixels + y * image->pitch;
        for (int x = 0; x < SPLASH_WIDTH; ++x) {
            SDL_Color color = colors[*indices++];
            *destination++ = color.r;
            *destination++ = color.g;
            *destination++ = color.b;
            *destination++ = color.a;
        }
    }
    splash = SDL_CreateTextureFromSurface(output, image);
    SDL_DestroySurface(image);
    if (!splash || !SDL_SetTextureScaleMode(splash, SDL_SCALEMODE_NEAREST) ||
        !SDL_SetTextureBlendMode(splash, SDL_BLENDMODE_BLEND)) {
        video_failed = true;
    }
}

static Uint8 gs_opacity(s64 value) {
    return (Uint8)(SDL_clamp(value, 0, 128) * 255 / 128);
}

static bool draw_quad(SDL_Texture *texture, const Quad *quad) {
    SDL_FRect source = {
        .x = SDL_min(quad->u[0], quad->u[1]),
        .y = SDL_min(quad->v[0], quad->v[1]),
        .w = SDL_abs(quad->u[1] - quad->u[0]),
        .h = SDL_abs(quad->v[1] - quad->v[0]),
    };
    SDL_FRect destination = {quad->x[0], quad->y[0],
                             quad->x[1] - quad->x[0], quad->y[1] - quad->y[0]};
    SDL_FlipMode flip = SDL_FLIP_NONE;
    if (quad->u[0] > quad->u[1]) {
        flip |= SDL_FLIP_HORIZONTAL;
    }
    if (quad->v[0] > quad->v[1]) {
        flip |= SDL_FLIP_VERTICAL;
    }
    Uint8 shade = gs_opacity(quad->color);
    return SDL_SetTextureColorMod(texture, shade, shade, shade) &&
           SDL_SetTextureAlphaMod(texture, gs_opacity(quad->alpha)) &&
           SDL_RenderTextureRotated(output, texture, &source, &destination, 0, NULL, flip);
}

void quad_flush(void) {
    for (s32 i = 0; i < g_quad_count; ++i) {
        const Quad *quad = &g_quad_queue[i];
        if (!splash || quad->tbp != SPLASH_TEXTURE || quad->cbp != SPLASH_PALETTE ||
            !draw_quad(splash, quad)) {
            video_failed = true;
        }
    }
    g_quad_count = 0;
}

void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s64 alpha,
                        s32 r, s32 g, s32 b) {
    (void)depth;
    SDL_FRect rect = {x, y, w, h};
    if (!output || !SDL_SetRenderDrawBlendMode(output, SDL_BLENDMODE_BLEND) ||
        !SDL_SetRenderDrawColor(output, (Uint8)r, (Uint8)g, (Uint8)b, gs_opacity(alpha)) ||
        !SDL_RenderFillRect(output, &rect)) {
        video_failed = true;
    }
}

#include "screen_fade.inc.h"
#include "splash_draw.inc.h"
