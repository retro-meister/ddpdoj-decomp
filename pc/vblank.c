#include "vblank.h"
#include "sdk/libgraph.h"

#include <SDL3/SDL.h>

/* Three NTSC fields span exactly 50.05 ms. */
static const Uint64 three_fields_ns = 50050000;
static Uint64 epoch;
static Uint64 next_field;
static Uint64 poll_time;
static Uint64 render_budget = 4000000;
static SDL_Renderer *display_renderer;

static Uint64 field_deadline(void)
{
    return epoch + (next_field * three_fields_ns + 2) / 3;
}

static void start_clock(Uint64 now)
{
    if (!next_field) {
        epoch = now;
        next_field = 1;
    }
}

void pc_wait_to_poll_input(SDL_Renderer *renderer)
{
    display_renderer = renderer;
    Uint64 now = SDL_GetTicksNS();
    start_clock(now);
    Uint64 deadline = field_deadline();
    /* Poll close to presentation, leaving time for recent frame costs and
     * a millisecond of variation in simulation and rendering. */
    Uint64 lead = render_budget + SDL_NS_PER_MS;
    if (deadline > now + lead) {
        SDL_DelayPrecise(deadline - now - lead);
    }
    poll_time = SDL_GetTicksNS();
}

s32 sceGsSyncV(s32 mode)
{
    Uint64 now = SDL_GetTicksNS();
    start_clock(now);
    SDL_assert(mode == 0);
    if (poll_time) {
        /* Dispatch the queued draws while there is still time left in this field. */
        if (display_renderer) {
            SDL_FlushRenderer(display_renderer);
            now = SDL_GetTicksNS();
        }
        Uint64 cost = SDL_min(now - poll_time, three_fields_ns / 3);
        render_budget = SDL_max(cost, render_budget - render_budget / 32);
        poll_time = 0;
    }
    Uint64 deadline = field_deadline();
    if (deadline > now) {
        SDL_DelayPrecise(deadline - now);
    } else {
        /* A late frame already crossed its field boundary. Additional game
         * waits for arcade slowdown still consume one full field each. */
        next_field = SDL_max(next_field, (now - epoch) * 3 / three_fields_ns);
    }
    return (s32)(next_field++ & 1);
}
