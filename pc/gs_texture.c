#include "gs_texture.h"

enum {
    GS_BLOCKS = 0x4000,
    MAX_TEXTURE_SIDE = 1024,
    TEXTURE_CACHE_SIZE = 48,
    SPRITE_SIDE = 256,
    SPRITE_BUCKETS = 32,
    SPRITES_PER_BUCKET = 8,
};

typedef struct {
    u8 *pixels;
    unsigned width;
    unsigned height;
    unsigned format;
    unsigned bytes_per_pixel;
    SDL_Rect upload;
    u32 upload_hash;
    u64 revision;
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

/* Sprites stream through the same patch of GS memory. Keep their resolved colors
 * in separate textures so the GPU can finish drawing one while the next uploads. */
typedef struct {
    CachedTexture entry;
    u8 *indices;
    u32 hash;
    u64 palette_revision;
    SDL_Rect upload;
} CachedSprite;

static CachedSprite sprites[SPRITE_BUCKETS][SPRITES_PER_BUCKET];

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
    for (size_t i = 0; i < SPRITE_BUCKETS; ++i) {
        for (size_t j = 0; j < SPRITES_PER_BUCKET; ++j) {
            SDL_DestroyTexture(sprites[i][j].entry.texture);
            SDL_free(sprites[i][j].indices);
        }
    }
    SDL_zeroa(sprites);
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
    bool changed = !image->pixels || image->format != format ||
                   x + width > image->width || y + height > image->height;
    if (!reserve_image(image, format, bpp, x + width, y + height)) {
        return false;
    }

    image->upload = (SDL_Rect){x, y, width, height};
    if ((format == SCE_GS_PSMT4 || format == SCE_GS_PSMT8) &&
        x + width <= SPRITE_SIDE && y + height <= SPRITE_SIDE) {
        size_t bytes = format == SCE_GS_PSMT4 ? (width * height + 1) / 2 : width * height;
        image->upload_hash = SDL_murmur3_32(pixels, bytes, 0);
    }
    const u8 *input = pixels;
    for (unsigned row = 0; row < height; row++) {
        u8 *dest = image->pixels + ((size_t)(y + row) * image->width + x) * bpp;
        size_t offset = (size_t)row * width;
        if (format == SCE_GS_PSMT4) {
            for (unsigned col = 0; col < width; col++) {
                size_t i = offset + col;
                u8 index = (input[i / 2] >> ((i & 1) * 4)) & 0xF;
                changed |= dest[col] != index;
                dest[col] = index;
            }
        } else if (SDL_memcmp(dest, input + offset * bpp, (size_t)width * bpp) != 0) {
            SDL_memcpy(dest, input + offset * bpp, (size_t)width * bpp);
            changed = true;
        }
    }
    if (!changed) {
        return true;
    }

    image->revision = ++cache_clock;
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
    bool use_alpha = (entry->tex0 >> 34) & 1;
    if (indexed) {
        unsigned count = image->format == SCE_GS_PSMT4 ? 16 : 256;
        if (!decode_palette(palette, count, &images[(entry->tex0 >> 37) & 0x3FFF],
                            (entry->tex0 >> 51) & 0xF, entry->texa)) {
            return false;
        }
        if (!use_alpha) {
            for (unsigned i = 0; i < count; ++i) {
                palette[i].a = 255;
            }
        }
    }
    void *pixels;
    int pitch;
    if (!SDL_LockTexture(entry->texture, &dirty, &pixels, &pitch)) {
        return false;
    }
    for (int y = 0; y < dirty.h; y++) {
        const u8 *src = image->pixels + ((size_t)(dirty.y + y) * image->width + dirty.x) *
                        image->bytes_per_pixel;
        SDL_Color *dest = (SDL_Color *)((u8 *)pixels + (size_t)y * pitch);
        if (indexed) {
            for (int x = 0; x < dirty.w; ++x) {
                dest[x] = palette[src[x]];
            }
        } else {
            for (int x = 0; x < dirty.w; ++x) {
                dest[x] = decode_color(src, image->format, entry->texa);
                if (!use_alpha) {
                    dest[x].a = 255;
                }
                src += image->bytes_per_pixel;
            }
        }
    }
    SDL_UnlockTexture(entry->texture);
    entry->dirty = (SDL_Rect){0};
    return true;
}

static bool covers_vertices(const SDL_Rect *rect, const SDL_Vertex *vertices, unsigned count, bool linear)
{
    float border = linear ? 0.5f : 0;
    for (unsigned i = 0; i < count; ++i) {
        SDL_FPoint uv = vertices[i].tex_coord;
        if (uv.x < rect->x + border || uv.x > rect->x + rect->w - border ||
            uv.y < rect->y + border || uv.y > rect->y + rect->h - border) {
            return false;
        }
    }
    return true;
}

static SDL_Texture *sprite_texture(SDL_Renderer *renderer, const Image *image, u64 tex0, u64 texa)
{
    SDL_Rect rect = image->upload;
    int width = SDL_min(image->width, 1u << ((tex0 >> 26) & 0xf));
    int height = SDL_min(image->height, 1u << ((tex0 >> 30) & 0xf));
    /* Flipped sprites can sample the texel just beyond either edge. */
    if (rect.x + rect.w < width) {
        ++rect.w;
    }
    if (rect.y + rect.h < height) {
        ++rect.h;
    }
    if (rect.x > 0) {
        --rect.x;
        ++rect.w;
    }
    if (rect.y > 0) {
        --rect.y;
        ++rect.h;
    }
    const u8 *indices = image->pixels + (size_t)rect.y * image->width + rect.x;
    u64 palette_revision = images[(tex0 >> 37) & 0x3fff].revision;
    unsigned bucket_index = (image->upload_hash ^ (u32)(tex0 >> 37)) % SPRITE_BUCKETS;
    CachedSprite *bucket = sprites[bucket_index];
    CachedSprite *oldest = &bucket[0];
    for (size_t i = 0; i < SPRITES_PER_BUCKET; ++i) {
        CachedSprite *sprite = &bucket[i];
        CachedTexture *entry = &sprite->entry;
        if (entry->used < oldest->entry.used) {
            oldest = sprite;
        }
        if (!entry->texture || sprite->hash != image->upload_hash ||
            sprite->palette_revision != palette_revision || entry->tex0 != tex0 ||
            entry->texa != texa || !SDL_RectsEqual(&sprite->upload, &rect)) {
            continue;
        }
        int row = 0;
        while (row < rect.h && SDL_memcmp(sprite->indices + row * rect.w,
                                         indices + row * image->width, rect.w) == 0) {
            ++row;
        }
        if (row == rect.h) {
            entry->used = ++cache_clock;
            return entry->texture;
        }
    }

    u8 *copy = SDL_realloc(oldest->indices, (size_t)rect.w * rect.h);
    if (!copy) {
        return NULL;
    }
    oldest->indices = copy;
    for (int y = 0; y < rect.h; ++y) {
        SDL_memcpy(copy + y * rect.w, indices + y * image->width, rect.w);
    }
    SDL_DestroyTexture(oldest->entry.texture);
    oldest->entry = (CachedTexture){
        .texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING,
                                     plane_size(rect.x + rect.w), plane_size(rect.y + rect.h)),
        .tex0 = tex0, .texa = texa, .used = ++cache_clock, .dirty = rect,
    };
    oldest->hash = image->upload_hash;
    oldest->palette_revision = palette_revision;
    oldest->upload = rect;
    if (!oldest->entry.texture || !update_texture(&oldest->entry, image)) {
        SDL_DestroyTexture(oldest->entry.texture);
        oldest->entry.texture = NULL;
        return NULL;
    }
    return oldest->entry.texture;
}

SDL_Texture *pc_gs_texture_get(SDL_Renderer *renderer, u64 tex0, u64 texa,
                               const SDL_Vertex *vertices, unsigned count, bool linear)
{
    tex0 &= (1ULL << 61) - 1; /* CLD affects the original CLUT cache command, not texture identity. */
    const Image *image = &images[tex0 & 0x3FFF];
    if (!image->pixels || image->format != ((tex0 >> 20) & 0x3F) || ((tex0 >> 55) & 0x3F)) {
        return NULL;
    }

    unsigned width = SDL_min(image->width, 1u << ((tex0 >> 26) & 0xF));
    unsigned height = SDL_min(image->height, 1u << ((tex0 >> 30) & 0xF));
    const SDL_Rect rect = image->upload;
    if (count && (image->format == SCE_GS_PSMT4 || image->format == SCE_GS_PSMT8) &&
        rect.x + rect.w <= (int)SDL_min(width, SPRITE_SIDE) &&
        rect.y + rect.h <= (int)SDL_min(height, SPRITE_SIDE) &&
        covers_vertices(&rect, vertices, count, linear)) {
        return sprite_texture(renderer, image, tex0, texa);
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
