#include "gs_texture.h"

enum { GS_BLOCKS = 0x4000, MAX_TEXTURE_SIDE = 1024, TEXTURE_CACHE_SIZE = 48 };

typedef struct {
    u8 *pixels;
    unsigned width;
    unsigned height;
    unsigned format;
    unsigned bytes_per_pixel;
} Image;

typedef struct {
    SDL_Texture *texture;
    u64 tex0;
    u64 texa;
    u64 used;
    SDL_Rect dirty;
} CachedTexture;

/* Gallery's uploads and reads use the same base and format for each image.
 * Store image planes by base and expand indexed colors only when SDL draws them. */
static Image images[GS_BLOCKS];
static CachedTexture textures[TEXTURE_CACHE_SIZE];
static u64 cache_clock;

static unsigned pixel_bytes(unsigned format)
{
    switch (format) {
    case SCE_GS_PSMT4:
    case SCE_GS_PSMT8:
        return 1;
    case SCE_GS_PSMCT16:
        return 2;
    case SCE_GS_PSMCT24:
        return 3;
    case SCE_GS_PSMCT32:
        return 4;
    default:
        return 0;
    }
}

void pc_gs_textures_reset(void)
{
    for (size_t i = 0; i < TEXTURE_CACHE_SIZE; i++) {
        SDL_DestroyTexture(textures[i].texture);
    }
    for (size_t i = 0; i < GS_BLOCKS; i++) {
        SDL_free(images[i].pixels);
    }
    SDL_zeroa(textures);
    SDL_zeroa(images);
    cache_clock = 0;
}

static unsigned plane_size(unsigned extent)
{
    unsigned size = 1;
    while (size < extent) {
        size *= 2;
    }
    return size;
}

static bool reserve_image(Image *image, unsigned format, unsigned bpp,
                          unsigned width, unsigned height)
{
    bool same_format = image->pixels && image->format == format;
    if (same_format && width <= image->width && height <= image->height) {
        return true;
    }
    if (same_format) {
        width = SDL_max(image->width, width);
        height = SDL_max(image->height, height);
    }
    width = plane_size(width);
    height = plane_size(height);
    u8 *pixels = SDL_calloc((size_t)width * height, bpp);
    if (!pixels) {
        return false;
    }
    if (same_format) {
        for (unsigned y = 0; y < image->height; y++) {
            SDL_memcpy(pixels + (size_t)y * width * bpp,
                       image->pixels + (size_t)y * image->width * bpp,
                       (size_t)image->width * bpp);
        }
    }
    SDL_free(image->pixels);
    *image = (Image){ pixels, width, height, format, bpp };
    return true;
}

bool pc_gs_texture_upload(const sceGsLoadImage *transfer, const void *pixels)
{
    unsigned base = (transfer->bitbltbuf >> 32) & 0x3FFF;
    unsigned stride = ((transfer->bitbltbuf >> 48) & 0x3F) * 64;
    unsigned format = (transfer->bitbltbuf >> 56) & 0x3F;
    unsigned x = (transfer->trxpos >> 32) & 0x7FF;
    unsigned y = (transfer->trxpos >> 48) & 0x7FF;
    unsigned width = transfer->trxreg & 0xFFF;
    unsigned height = (transfer->trxreg >> 32) & 0xFFF;
    unsigned bpp = pixel_bytes(format);
    if (!bpp || !pixels || !width || !height || x + width > stride ||
        x + width > MAX_TEXTURE_SIDE || y + height > MAX_TEXTURE_SIDE) {
        return false;
    }
    Image *image = &images[base];
    if (!reserve_image(image, format, bpp, x + width, y + height)) {
        return false;
    }

    const u8 *input = pixels;
    for (unsigned row = 0; row < height; row++) {
        u8 *dest = image->pixels + ((size_t)(y + row) * image->width + x) * bpp;
        size_t offset = (size_t)row * width;
        if (format == SCE_GS_PSMT4) {
            for (unsigned col = 0; col < width; col++) {
                size_t i = offset + col;
                dest[col] = (input[i / 2] >> ((i & 1) * 4)) & 0xF;
            }
        } else {
            SDL_memcpy(dest, input + offset * bpp, (size_t)width * bpp);
        }
    }

    for (size_t i = 0; i < TEXTURE_CACHE_SIZE; i++) {
        CachedTexture *entry = &textures[i];
        if (!entry->texture) {
            continue;
        }
        unsigned tex_base = entry->tex0 & 0x3FFF;
        unsigned palette_base = (entry->tex0 >> 37) & 0x3FFF;
        unsigned tex_format = (entry->tex0 >> 20) & 0x3F;
        if (palette_base == base && (tex_format == SCE_GS_PSMT4 || tex_format == SCE_GS_PSMT8)) {
            entry->dirty = (SDL_Rect){ 0, 0, images[tex_base].width, images[tex_base].height };
        } else if (tex_base == base) {
            SDL_Rect dirty = { x, y, width, height };
            SDL_GetRectUnion(&entry->dirty, &dirty, &entry->dirty);
        }
    }
    return true;
}

static u8 opacity(unsigned alpha)
{
    return (SDL_min(alpha, 128) * 255 + 64) / 128;
}

static SDL_Color decode_color(const u8 *pixel, unsigned format, u64 texa)
{
    if (format == SCE_GS_PSMCT16) {
        unsigned value = pixel[0] | (pixel[1] << 8);
        unsigned alpha = (value & 0x8000) ? (texa >> 32) & 0xFF : texa & 0xFF;
        if ((texa & 0x8000) && value == 0) {
            alpha = 0;
        }
        return (SDL_Color){ (value & 31) << 3, ((value >> 5) & 31) << 3,
                            ((value >> 10) & 31) << 3, opacity(alpha) };
    }
    unsigned alpha = format == SCE_GS_PSMCT32 ? pixel[3] : texa & 0xFF;
    if (format == SCE_GS_PSMCT24 && (texa & 0x8000) && !(pixel[0] | pixel[1] | pixel[2])) {
        alpha = 0;
    }
    return (SDL_Color){ pixel[0], pixel[1], pixel[2], opacity(alpha) };
}

static bool decode_palette(SDL_Color *colors, unsigned count, const Image *palette,
                           unsigned format, u64 texa)
{
    bool permuted = palette->width == 16;
    unsigned slots = permuted && count == 16 ? 24 : count;
    if (!palette->pixels || palette->format != format ||
        (format != SCE_GS_PSMCT16 && format != SCE_GS_PSMCT32) ||
        (!permuted && (count != 16 || palette->width != 8)) ||
        (size_t)palette->width * palette->height < slots) {
        return false;
    }
    for (unsigned i = 0; i < count; i++) {
        unsigned address = i;
        if (permuted) {
            /* The CSM1 CLUT exchanges the middle groups of eight colors. */
            address = (i & ~0x18u) | ((i & 8) << 1) | ((i & 16) >> 1);
        }
        colors[i] = decode_color(palette->pixels + address * palette->bytes_per_pixel,
                                 format, texa);
    }
    return true;
}

static bool update_texture(CachedTexture *entry, const Image *image)
{
    SDL_Rect bounds = { 0, 0, (int)entry->texture->w, (int)entry->texture->h };
    SDL_Rect dirty;
    if (!SDL_GetRectIntersection(&bounds, &entry->dirty, &dirty)) {
        return true;
    }
    SDL_Color palette[256];
    bool indexed = image->format == SCE_GS_PSMT4 || image->format == SCE_GS_PSMT8;
    if (indexed && !decode_palette(palette, image->format == SCE_GS_PSMT4 ? 16 : 256,
                                  &images[(entry->tex0 >> 37) & 0x3FFF],
                                  (entry->tex0 >> 51) & 0xF, entry->texa)) {
        return false;
    }
    void *pixels;
    int pitch;
    if (!SDL_LockTexture(entry->texture, &dirty, &pixels, &pitch)) {
        return false;
    }
    bool use_alpha = (entry->tex0 >> 34) & 1;
    for (int y = 0; y < dirty.h; y++) {
        const u8 *src = image->pixels + ((size_t)(dirty.y + y) * image->width + dirty.x) *
                        image->bytes_per_pixel;
        u8 *dest = (u8 *)pixels + (size_t)y * pitch;
        for (int x = 0; x < dirty.w; x++) {
            SDL_Color color = indexed ? palette[*src] : decode_color(src, image->format, entry->texa);
            *dest++ = color.r;
            *dest++ = color.g;
            *dest++ = color.b;
            *dest++ = use_alpha ? color.a : 255;
            src += image->bytes_per_pixel;
        }
    }
    SDL_UnlockTexture(entry->texture);
    entry->dirty = (SDL_Rect){0};
    return true;
}

SDL_Texture *pc_gs_texture_get(SDL_Renderer *renderer, u64 tex0, u64 texa)
{
    tex0 &= (1ULL << 61) - 1; /* CLD affects the original CLUT cache command, not texture identity. */
    const Image *image = &images[tex0 & 0x3FFF];
    if (!image->pixels || image->format != ((tex0 >> 20) & 0x3F) || ((tex0 >> 55) & 0x3F)) {
        return NULL;
    }

    CachedTexture *entry = &textures[0];
    for (size_t i = 0; i < TEXTURE_CACHE_SIZE; i++) {
        CachedTexture *candidate = &textures[i];
        if (candidate->texture && candidate->tex0 == tex0 && candidate->texa == texa) {
            entry = candidate;
            break;
        }
        if (candidate->used < entry->used) {
            entry = candidate;
        }
    }
    unsigned width = SDL_min(image->width, 1u << ((tex0 >> 26) & 0xF));
    unsigned height = SDL_min(image->height, 1u << ((tex0 >> 30) & 0xF));
    if (!entry->texture || entry->tex0 != tex0 || entry->texa != texa ||
        entry->texture->w != (int)width || entry->texture->h != (int)height) {
        SDL_DestroyTexture(entry->texture);
        *entry = (CachedTexture){
            .texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING,
                                         (int)width, (int)height),
            .tex0 = tex0,
            .texa = texa,
            .dirty = { 0, 0, width, height },
        };
        if (!entry->texture) {
            return NULL;
        }
    }
    entry->used = ++cache_clock;
    return update_texture(entry, image) ? entry->texture : NULL;
}
