#ifdef DEATH_LABEL
#endif

void fade_reset(void) {
    g_fade_state = 0;
    g_fade_alpha = 0;
#ifdef DEATH_LABEL
    g_fade_white = 0;
#endif
}

#ifdef DEATH_LABEL
#endif

void fade_start_in(void) {
#ifdef DEATH_LABEL
    g_fade_white = 0;
#endif
    g_fade_state = 1;
}

#ifdef DEATH_LABEL
#endif

void fade_start_out(void) {
#ifdef DEATH_LABEL
    g_fade_white = 0;
#endif
    g_fade_state = 2;
}

#ifdef DEATH_LABEL
void fade_white_start(void) {
    g_fade_state = 2;
    g_fade_white = 1;
}
#endif


#ifdef DEATH_LABEL
#endif

void fade_update_and_draw(void) {
    switch (g_fade_state) {                           /* irregular */
    case 0:
        break;
    case 1:
        g_fade_state = 3;
        g_fade_alpha = 0x80;
        g_fade_step = -8;
        break;
    case 2:
        g_fade_state = 3;
        g_fade_step = 8;
        g_fade_alpha = 0;
        break;
    case 3:
        g_fade_alpha += g_fade_step;
        if (g_fade_alpha < 0) {
            g_fade_alpha = 0;
            g_fade_state = 0;
        }
        if (g_fade_alpha > 0x80) {
            g_fade_state = 0;
            g_fade_alpha = 0x80;
        }
        break;
    }
#ifdef DEATH_LABEL
    if (g_fade_alpha != 0) {
        if (g_fade_white == 0) {
            gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x1F4, g_fade_alpha, 1, 1, 1);
        } else {
            gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x1F4, g_fade_alpha, 0xFF, 0xFF, 0xFF);
        }
    }
#else
    if (g_fade_alpha != 0) {
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x1F4, g_fade_alpha, 1, 1, 1);
    }
#endif
}
