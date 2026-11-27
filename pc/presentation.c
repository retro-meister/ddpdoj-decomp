#include "presentation.h"

SDL_Renderer *pc_create_renderer(SDL_Window *window)
{
    const char *driver = SDL_GetHint(SDL_HINT_RENDER_DRIVER);
    int interval = 1;
#ifdef _WIN32
    if (!driver) {
        driver = "gpu";
    }
    SDL_SetHint(SDL_HINT_GPU_DRIVER, "direct3d12");
    interval = 0;
#elif defined(__APPLE__)
    if (!driver) {
        driver = "metal";
    }
#endif

    SDL_Renderer *renderer = SDL_CreateRenderer(window, driver);
    if (!renderer) {
        return NULL;
    }
    if (!SDL_SetRenderVSync(renderer, interval)) {
        SDL_DestroyRenderer(renderer);
        return NULL;
    }
#ifdef _WIN32
    if (SDL_strcmp(SDL_GetRendererName(renderer), "gpu") == 0) {
        SDL_GPUDevice *device = SDL_GetGPURendererDevice(renderer);
        /* SDL's GPU renderer prefers mailbox at interval zero. Request it
         * explicitly so a driver that cannot supply it reports the failure. */
        if (!SDL_SetGPUSwapchainParameters(device, window, SDL_GPU_SWAPCHAINCOMPOSITION_SDR,
                                           SDL_GPU_PRESENTMODE_MAILBOX)) {
            SDL_DestroyRenderer(renderer);
            return NULL;
        }
        SDL_Log("Presentation: %s mailbox", SDL_GetGPUDeviceDriver(device));
        return renderer;
    }
#endif
    SDL_Log("Presentation: %s (swap interval %d)", SDL_GetRendererName(renderer), interval);
    return renderer;
}
