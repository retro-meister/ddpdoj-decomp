#ifndef DDPDOJ_PC_VIDEO_H
#define DDPDOJ_PC_VIDEO_H

#include <stdbool.h>

typedef struct SDL_Renderer SDL_Renderer;

/* Bind one renderer on the game thread. Pass NULL before destroying it. */
void pc_video_bind(SDL_Renderer *renderer);
bool pc_video_ok(void);

#endif
