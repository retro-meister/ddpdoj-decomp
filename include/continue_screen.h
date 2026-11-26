#ifndef DDPDOJ_CONTINUE_SCREEN_H
#define DDPDOJ_CONTINUE_SCREEN_H

#include "types.h"

/* What the continue screen needs to know about one player. The start-up fill puts the addresses in. */
typedef struct {
    /* 0x00 */ u16 other_00;
    /* 0x02 */ u16 other_02;
    /* 0x04 */ u16 other_routine[2];
    /* 0x08 */ u16 held[2];
    /* 0x0C */ u16 pressed[2];
    /* 0x10 */ u16 other_state[2];
    /* 0x14 */ u16 unused_14[6];
} ContinuePlayer;

extern ContinuePlayer continue_player1;
extern ContinuePlayer continue_player2;

#endif
