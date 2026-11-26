#include "gs.h"
#include "gs_texture.h"
#include "gif_stream.h"
#include "sdk/eekernel.h"
#include "sdk/eestruct.h"
#include "sdk/libdma.h"
#include "sdk/libgraph.h"

#include <SDL3/SDL.h>

typedef struct {
    SDL_Renderer *renderer;
    SDL_Vertex vertices[3];
    SDL_FPoint uv;
    SDL_Color color;
    u64 prim;
    u64 alpha;
    u64 tex0;
    u64 tex1;
    u64 texa;
    unsigned vertex_count;
    bool failed;
} GsDrawState;

static GsDrawState gs;

void pc_gs_bind_gallery(SDL_Renderer *renderer)
{
    pc_gs_textures_reset();
    gs = (GsDrawState){ .renderer = renderer };
}

bool pc_gs_ok(void)
{
    return gs.renderer && !gs.failed;
}

bool pc_gs_begin_frame(void)
{
    return pc_gs_ok() && SDL_SetRenderDrawColor(gs.renderer, 0, 0, 0, 255) &&
           SDL_RenderClear(gs.renderer);
}

static SDL_BlendMode draw_blend(const GsDrawState *state)
{
    if ((state->prim & (1 << 6)) == 0) {
        return SDL_BLENDMODE_NONE;
    }
    switch (state->alpha) {
    case SCE_GS_SET_ALPHA(0, 1, 0, 1, 0):
        return SDL_BLENDMODE_BLEND;
    case SCE_GS_SET_ALPHA(0, 2, 0, 1, 0):
        return SDL_BLENDMODE_ADD;
    case SCE_GS_SET_ALPHA(1, 0, 2, 2, 0x80):
        return SDL_ComposeCustomBlendMode(
            SDL_BLENDFACTOR_ONE, SDL_BLENDFACTOR_ONE, SDL_BLENDOPERATION_REV_SUBTRACT,
            SDL_BLENDFACTOR_ZERO, SDL_BLENDFACTOR_ONE, SDL_BLENDOPERATION_ADD);
    default:
        return SDL_BLENDMODE_INVALID;
    }
}

static bool draw_solid_rect(GsDrawState *state)
{
    SDL_FPoint start = state->vertices[0].position;
    SDL_FPoint end = state->vertices[1].position;
    SDL_FRect rect = { SDL_min(start.x, end.x), SDL_min(start.y, end.y),
                       SDL_fabsf(end.x - start.x), SDL_fabsf(end.y - start.y) };
    SDL_Color color = state->color;
    SDL_BlendMode blend = draw_blend(state);
    u8 opacity = (u8)((SDL_min(color.a, 128) * 255 + 64) / 128);
    return blend != SDL_BLENDMODE_INVALID && SDL_SetRenderDrawBlendMode(state->renderer, blend) &&
           SDL_SetRenderDrawColor(state->renderer, color.r, color.g, color.b, opacity) &&
           SDL_RenderFillRect(state->renderer, &rect);
}

static bool draw_textured(GsDrawState *state, unsigned primitive)
{
    SDL_Texture *texture = pc_gs_texture_get(state->renderer, state->tex0, state->texa);
    SDL_BlendMode blend = draw_blend(state);
    if (!texture || blend == SDL_BLENDMODE_INVALID || !(state->prim & (1 << 8))) {
        return false;
    }
    if (blend == SDL_BLENDMODE_NONE && ((state->tex0 >> 34) & 1)) {
        /* Gallery's unblended indexed artwork uses transparent black. */
        blend = SDL_BLENDMODE_BLEND;
    }
    SDL_ScaleMode scale = (state->tex1 & (1 << 5)) ? SDL_SCALEMODE_LINEAR : SDL_SCALEMODE_NEAREST;
    if (!SDL_SetTextureBlendMode(texture, blend) || !SDL_SetTextureScaleMode(texture, scale)) {
        return false;
    }

    SDL_Vertex vertices[4] = { state->vertices[0], state->vertices[1], state->vertices[2] };
    int count = 3;
    const int indices[] = { 0, 2, 1, 1, 2, 3 };
    if (primitive == SCE_GS_PRIM_SPRITE) {
        vertices[3] = vertices[1];
        vertices[1].position.y = vertices[0].position.y;
        vertices[1].tex_coord.y = vertices[0].tex_coord.y;
        vertices[2] = vertices[3];
        vertices[2].position.x = vertices[0].position.x;
        vertices[2].tex_coord.x = vertices[0].tex_coord.x;
        count = 4;
    }
    for (int i = 0; i < count; i++) {
        if (!(state->prim & (1 << 3))) {
            vertices[i].color = vertices[count - 1].color;
        }
        vertices[i].tex_coord.x /= texture->w;
        vertices[i].tex_coord.y /= texture->h;
    }
    return SDL_RenderGeometry(state->renderer, texture, vertices, count,
                              count == 4 ? indices : NULL, count == 4 ? 6 : 0);
}

static void vertex_kick(GsDrawState *state, u64 value)
{
    /* Gallery stores 640x224 field coordinates and draws at 640x448. */
    SDL_FPoint point = { ((int)(value & 0xFFFF) - 0x6C00) / 16.0f,
                         ((int)((value >> 16) & 0xFFFF) - 0x7900) / 8.0f };
    SDL_Color color = state->color;
    SDL_Vertex vertex = {
        .position = point,
        .color = { SDL_min(color.r, 128) / 128.0f, SDL_min(color.g, 128) / 128.0f,
                   SDL_min(color.b, 128) / 128.0f, SDL_min(color.a, 128) / 128.0f },
        .tex_coord = state->uv,
    };
    state->vertices[state->vertex_count++] = vertex;
    unsigned primitive = state->prim & 7;
    bool textured = state->prim & (1 << 4);
    switch (primitive) {
    case SCE_GS_PRIM_SPRITE:
        if (state->vertex_count == 2) {
            state->failed |= !(textured ? draw_textured(state, primitive) : draw_solid_rect(state));
            state->vertex_count = 0;
        }
        break;
    case SCE_GS_PRIM_TRISTRIP:
    case SCE_GS_PRIM_TRIFAN:
        if (state->vertex_count == 3) {
            state->failed |= !textured || !draw_textured(state, primitive);
            if (primitive == SCE_GS_PRIM_TRISTRIP) {
                state->vertices[0] = state->vertices[1];
            }
            state->vertices[1] = state->vertices[2];
            state->vertex_count = 2;
        }
        break;
    default:
        state->failed = true;
        state->vertex_count = 0;
        break;
    }
}

static void write_register(void *context, u8 address, u64 value)
{
    GsDrawState *state = context;
    switch (address) {
    case SCE_GS_PRIM:
        state->prim = value;
        state->vertex_count = 0;
        break;
    case SCE_GS_RGBAQ:
        state->color = (SDL_Color){ (u8)value, (u8)(value >> 8), (u8)(value >> 16), (u8)(value >> 24) };
        break;
    case SCE_GS_UV:
        state->uv = (SDL_FPoint){ (value & 0x3FFF) / 16.0f, ((value >> 16) & 0x3FFF) / 16.0f };
        break;
    case 0x04: /* XYZF2 */
    case SCE_GS_XYZ2:
        vertex_kick(state, value);
        break;
    case SCE_GS_TEX0_1:
        state->tex0 = value;
        break;
    case SCE_GS_TEX1_1:
        state->tex1 = value;
        break;
    case SCE_GS_TEXA:
        state->texa = value;
        break;
    case SCE_GS_ALPHA_1:
        state->alpha = value;
        break;
    }
}

static void write_packed(void *context, u8 descriptor, u64 low, u64 high)
{
    switch (descriptor) {
    case SCE_GS_RGBAQ:
        write_register(context, descriptor, SCE_GS_SET_RGBAQ(low & 0xFF, (low >> 32) & 0xFF,
                                                            high & 0xFF, (high >> 32) & 0xFF, 0));
        break;
    case SCE_GS_UV:
        write_register(context, descriptor, SCE_GS_SET_UV(low & 0x3FFF, (low >> 32) & 0x3FFF));
        break;
    case 0x04:
    case SCE_GS_XYZ2:
        if (!(high & (1ULL << 47))) {
            write_register(context, descriptor, (low & 0xFFFF) | (((low >> 32) & 0xFFFF) << 16));
        }
        break;
    default: {
        GsDrawState *state = context;
        state->failed = true;
        break;
    }
    }
}

static void write_image(void *context, const void *pixels, size_t size)
{
    (void)pixels;
    (void)size;
    GsDrawState *state = context;
    state->failed = true;
}

static void submit(const void *payload, size_t size)
{
    static const PcGifSink sink = { write_register, write_packed, write_image };
    if (pc_gs_ok() && !pc_gif_decode(payload, size, &sink, &gs)) {
        gs.failed = true;
    }
}

void *sceDmaGetChan(s32 id)
{
    return id == SCE_DMA_GIF ? &gs : NULL;
}

void sceDmaSendN(void *chan, void *addr, s32 size)
{
    if (chan != &gs || size < 0 || (size_t)size > SIZE_MAX / 16) {
        gs.failed = true;
        return;
    }
    submit(addr, (size_t)size * 16);
}

void pc_dma_send_chain(void *chan, const void *tag, size_t capacity)
{
    const u8 *cursor = tag;
    if (chan == &gs && cursor) {
        while (capacity >= 16) {
            u32 header;
            SDL_memcpy(&header, cursor, sizeof(header));
            unsigned id = (header >> 28) & 7;
            size_t bytes = (header & 0xFFFF) * 16u;
            cursor += 16;
            capacity -= 16;
            /* Gallery's in-place chains use CNT (1) and END (7). */
            if (bytes > capacity || (id != 1 && id != 7)) {
                break;
            }
            submit(cursor, bytes);
            if (id == 7) {
                return;
            }
            cursor += bytes;
            capacity -= bytes;
        }
    }
    gs.failed = true;
}

s32 sceGsSyncPath(s32 mode, s32 timeout)
{
    (void)mode;
    (void)timeout;
    return pc_gs_ok() ? 0 : -1;
}

s32 sceGsSetDefLoadImage(sceGsLoadImage *packet, s16 base, s16 stride, s16 format,
                         s16 x, s16 y, s16 width, s16 height)
{
    *packet = (sceGsLoadImage){
        .bitbltbuf = ((u64)base << 32) | ((u64)stride << 48) | ((u64)format << 56),
        .trxpos = ((u64)x << 32) | ((u64)y << 48),
        .trxreg = (u64)width | ((u64)height << 32),
    };
    return 0;
}

s32 sceGsExecLoadImage(sceGsLoadImage *packet, const void *source)
{
    if (!pc_gs_ok() || !pc_gs_texture_upload(packet, source)) {
        gs.failed = true;
        return -1;
    }
    return 0;
}

void FlushCache(s32 mode)
{
    (void)mode;
}
