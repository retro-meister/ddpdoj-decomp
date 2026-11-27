#ifndef DDPDOJ_PC_GS_TEXTURE_H
#define DDPDOJ_PC_GS_TEXTURE_H

#include "sdk/libgraph.h"

#include <SDL3/SDL_render.h>

void pc_gs_textures_reset(void);
bool pc_gs_texture_upload(const sceGsLoadImage *transfer, const void *pixels);
SDL_Texture *pc_gs_texture_get(SDL_Renderer *renderer, u64 tex0, u64 texa,
                               const SDL_Vertex *vertices, unsigned count, bool linear);

#endif
