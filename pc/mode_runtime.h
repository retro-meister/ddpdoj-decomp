#ifndef DDPDOJ_MODE_RUNTIME_H
#define DDPDOJ_MODE_RUNTIME_H

#include "game_loop.h"
#include <SDL3/SDL.h>

typedef bool PcRunMode(SDL_Renderer *renderer, const char *iso, GameMode *next_mode);

#endif
