#ifndef DDPDOJ_FADE_H
#define DDPDOJ_FADE_H

#include "types.h"

typedef struct {
    /* 0x00 */ u8 *colors;
    /* 0x04 */ u8 *changed;
} FadeArea;

extern u16 palette_black[32];
extern u16 palette_white[32];

#endif
