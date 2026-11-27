#ifndef DDPDOJ_PC_VBLANK_H
#define DDPDOJ_PC_VBLANK_H

#include <stdbool.h>

typedef struct SDL_Renderer SDL_Renderer;
bool pc_frame_should_present(bool fast_forward);
void pc_wait_to_poll_input(SDL_Renderer *renderer);

#endif
