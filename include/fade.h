#ifndef DDPDOJ_FADE_H
#define DDPDOJ_FADE_H

#include "game_address.h"

typedef struct {
    /* 0x00 */ u8 *colors;
    /* 0x04 */ u8 *changed;
} FadeArea;

typedef struct {
    u16 initial_color;
    u16 area_offset;
    u16 color_offset;
    PackedGameAddress palette;
    u16 last_color;
    u16 speed;
} FadePaletteRun;

typedef struct {
    u16 count;
    FadePaletteRun runs[2];
    /* 0x1E */ u16 unused_1E;
} TwoPaletteFade;

extern TwoPaletteFade g_startup_palette_fade;

extern u16 palette_black[32];
extern u16 palette_white[32];

#endif
