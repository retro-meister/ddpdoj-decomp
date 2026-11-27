#ifndef DDPDOJ_PC_GS_H
#define DDPDOJ_PC_GS_H

#include <stdbool.h>

typedef struct SDL_Renderer SDL_Renderer;

/* The game thread owns submission and presentation. */
void pc_gs_bind_gallery(SDL_Renderer *renderer);
void pc_gs_bind_game(SDL_Renderer *renderer);
void pc_gs_skip_window_draws(bool skip);
bool pc_gs_begin_frame(void);
bool pc_gs_ok(void);

#endif
