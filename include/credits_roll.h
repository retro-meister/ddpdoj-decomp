#ifndef DDPDOJ_CREDITS_ROLL_H
#define DDPDOJ_CREDITS_ROLL_H

#include "types.h"

/* State of the scrolling staff credits. */
typedef struct {
    /* 0x00 */ u16 script_offset; /* byte offset of the next line in the script */
    /* 0x02 */ u16 wait;          /* frames counted towards that line's delay */
    /* 0x04 */ u16 scroll_speed;  /* 1/64 pixel per frame; 0 once the last line has stopped the roll */
} CreditsRoll;

extern CreditsRoll g_credits_roll;
extern s16 g_ending_started;

void credits_roll_begin(void);
void credits_roll_update(void);

#endif
