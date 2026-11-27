#ifndef DDPDOJ_WINDOW_PLACEMENT_H
#define DDPDOJ_WINDOW_PLACEMENT_H

#include <SDL3/SDL.h>

typedef struct {
    SDL_Window *window;
    SDL_Rect bounds;
    bool maximized;
    bool fullscreen;
} WindowPlacement;

void pc_restore_window(WindowPlacement *placement, SDL_Window *window, const char *saved);
bool pc_save_window(WindowPlacement *placement, char *buffer, size_t size);

#endif
