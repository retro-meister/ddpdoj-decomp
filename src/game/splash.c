#include "common.h"
#include "gfx.h"
#include "system.h"

/* The logo screen shown at start-up: fade in, hold for four seconds, fade out. */

enum {
    SPLASH_FADE_IN,
    SPLASH_HOLD,
    SPLASH_FADE_OUT,
    SPLASH_DONE
};

#define SPLASH_HOLD_FRAMES 240

extern u16 g_splash_step;
extern u16 g_splash_timer;
extern s32 g_splash_unused;

void splash_begin(void) {
    g_splash_timer = SPLASH_HOLD_FRAMES;
    g_splash_unused = 0;
    g_splash_step = SPLASH_FADE_IN;
    splash_image_upload();
    fade_reset();
    fade_start_in();
}

/* Sets cond_flag while the screen is still up. */
void splash_update(void) {
    switch (g_splash_step) {
    case SPLASH_FADE_IN:
        g_splash_visible = 1;
        if (g_fade_state != 0) break;
        g_splash_step += 1;
        break;
    case SPLASH_HOLD:
        g_splash_timer -= 1;
        if ((s32) g_splash_timer > 0) break;
        fade_start_out();
        g_splash_step += 1;
        break;
    case SPLASH_FADE_OUT:
        if (g_fade_state != 0) break;
        g_splash_step += 1;
        break;
    }
    if ((s32) g_splash_step >= SPLASH_DONE) {
        fade_reset();
        g_splash_visible = 0;
        cond_flag = 0;
        return;
    }
    cond_flag = 1;
}
