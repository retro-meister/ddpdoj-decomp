#include "sdk/libgraph.h"

#include <SDL3/SDL.h>

s32 sceGsSyncV(s32 mode)
{
    /* Each mode uses NTSC. Three fields span 50.05 ms. Keep the clock
     * independent of presentation so an extra wait still models slowdown. */
    const Uint64 three_fields_ns = 50050000;
    static Uint64 epoch;
    Uint64 now = SDL_GetTicksNS();
    if (!epoch) {
        epoch = now;
    }

    SDL_assert(mode == 0);
    Uint64 field = (now - epoch) * 3 / three_fields_ns + 1;
    Uint64 deadline = epoch + (field * three_fields_ns + 2) / 3;
    SDL_DelayPrecise(deadline - now);
    return (s32)(field & 1);
}
