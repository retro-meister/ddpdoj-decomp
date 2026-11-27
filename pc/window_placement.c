#include "window_placement.h"

static void capture(WindowPlacement *placement)
{
    SDL_WindowFlags flags = SDL_GetWindowFlags(placement->window);
    if (flags & SDL_WINDOW_MINIMIZED) {
        return;
    }
    placement->fullscreen = (flags & SDL_WINDOW_FULLSCREEN) != 0;
    if (!placement->fullscreen) {
        placement->maximized = (flags & SDL_WINDOW_MAXIMIZED) != 0;
        if (!placement->maximized) {
            SDL_GetWindowSize(placement->window, &placement->bounds.w, &placement->bounds.h);
            SDL_GetWindowPosition(placement->window, &placement->bounds.x, &placement->bounds.y);
        }
    }
}

static bool SDLCALL placement_changed(void *data, SDL_Event *event)
{
    WindowPlacement *placement = data;
    if (event->type >= SDL_EVENT_WINDOW_MOVED && event->type <= SDL_EVENT_WINDOW_RESTORED &&
        SDL_IsMainThread() && event->window.windowID == SDL_GetWindowID(placement->window)) {
        capture(placement);
    }
    return true;
}

void pc_restore_window(WindowPlacement *placement, SDL_Window *window, const char *saved)
{
    placement->window = window;
    capture(placement);
    SDL_Rect bounds, usable;
    int maximized, fullscreen;
    if (saved && SDL_sscanf(saved, "%d %d %d %d %d %d", &bounds.x, &bounds.y,
                           &bounds.w, &bounds.h, &maximized, &fullscreen) == 6 &&
        bounds.w > 0 && bounds.h > 0 &&
        SDL_GetDisplayUsableBounds(SDL_GetDisplayForRect(&bounds), &usable)) {
        if (!SDL_HasRectIntersection(&bounds, &usable)) {
            bounds.w = SDL_min(bounds.w, usable.w);
            bounds.h = SDL_min(bounds.h, usable.h);
            bounds.x = usable.x + (usable.w - bounds.w) / 2;
            bounds.y = usable.y + (usable.h - bounds.h) / 2;
        }
        placement->bounds = bounds;
        placement->maximized = maximized != 0;
        placement->fullscreen = fullscreen != 0;
        SDL_SetWindowSize(window, bounds.w, bounds.h);
        SDL_SetWindowPosition(window, bounds.x, bounds.y);
        if (placement->maximized) SDL_MaximizeWindow(window);
        if (placement->fullscreen) SDL_SetWindowFullscreen(window, true);
    }
    SDL_AddEventWatch(placement_changed, placement);
}

bool pc_save_window(WindowPlacement *placement, char *buffer, size_t size)
{
    SDL_RemoveEventWatch(placement_changed, placement);
    capture(placement);
    SDL_Rect bounds = placement->bounds;
    int length = SDL_snprintf(buffer, size, "%d %d %d %d %d %d\n",
                              bounds.x, bounds.y, bounds.w, bounds.h,
                              placement->maximized, placement->fullscreen);
    return length > 0 && (size_t)length < size;
}
