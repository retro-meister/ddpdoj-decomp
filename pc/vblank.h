#ifndef DDPDOJ_PC_VBLANK_H
#define DDPDOJ_PC_VBLANK_H

typedef struct SDL_Renderer SDL_Renderer;
void pc_enable_vsync(SDL_Renderer *renderer);
void pc_wait_to_poll_input(void);

#endif
