#ifndef DDPDOJ_SCROLL_EVENTS_H
#define DDPDOJ_SCROLL_EVENTS_H

#include "types.h"

/*
 * A stage has two lists of scroll events, one for each scrolling plane. A list is a run of 16-bit words: two
 * pointer slots (the first plane's list has the stage's palettes and sound commands there, the second plane's
 * holds zeros), then the events in the order of their line, then SCROLL_EVENTS_END. An event happens when the
 * scroll line (g_scroll_line) reaches its line.
 */
#define SCROLL_EVENT(line, event) (line), 0xFFFF, (event)

/* Load the next `count` palettes of the stage's palette list. */
#define SCROLL_PALETTES(line, count) SCROLL_EVENT(line, 0x00), (count)
/* Move the plane's place in the map by `rows` rows, then show the `length` rows from there `times` times
   (-1: without end). */
#define SCROLL_MAP_LOOP(line, rows, length, times) SCROLL_EVENT(line, 0x04), (u16)(rows), (length), (u16)(times)
/* Set the plane's scroll speed, in 1/64 pixel a frame (0x40: one pixel). */
#define SCROLL_SPEED(line, speed) SCROLL_EVENT(line, 0x08), (speed)
/* Hold the scroll line while the map loop runs; when the loop ends the line goes on from four lines later. */
#define SCROLL_LINE_HOLD(line) SCROLL_EVENT(line, 0x0C)
/* Start one of the stage's scenery pieces (its number in the stage's set-up table) at a position (1/64 pixel). */
#define SCROLL_SCENERY(line, object, y, x) SCROLL_EVENT(line, 0x10), (object), (y), (x)
/* Run the next `count` commands of the stage's sound list. */
#define SCROLL_SOUNDS(line, count) SCROLL_EVENT(line, 0x14), (count)
/* Set the first `count` of the four flags at g_bullet_limit_raised_1. */
#define SCROLL_FLAGS(line, count) SCROLL_EVENT(line, 0x18), (count)
#define SCROLL_EVENTS_END 0xFFFF

/* An entry of a stage's palette list: the slot the palette's address goes in, and the palette number it is
   loaded as. */
#define SCROLL_PALETTE(slot, number) POINTER_SLOT(slot), (number)
#define SCROLL_PALETTES_END 0xFFFF, 0xFFFF

/* The commands of a stage's sound list. */
/* Call the routine whose address goes in the slot, `frames` frames from now. */
#define SCROLL_SOUND_CALL(frames, slot) 0, (frames), POINTER_SLOT(slot)
#define SCROLL_SOUND_MUSIC_STOP 1
#define SCROLL_SOUND_MUSIC_FADE(time) 2, (time)
#define SCROLL_SOUNDS_END 0xFFFF

/*
 * What reads one plane's event list: 0x1C bytes. Addresses are kept as two words, high word first.
 */
typedef struct {
    /* 0x00 */ u16 events[2];        /* the next event of the list */
    /* 0x04 */ u16 palettes[2];      /* the next entry of the stage's palette list */
    /* 0x08 */ u16 sounds[2];        /* the next command of the stage's sound list */
    /* 0x0C */ u16 loop_map[2];      /* a map loop is running: where in the map it starts */
    /* 0x10 */ u16 loop_times;       /* times still to show it; -1 is without end */
    /* 0x12 */ u16 unused_12;
    /* 0x14 */ u16 loop_length;      /* its rows */
    /* 0x16 */ u16 loop_rows_left;   /* rows until it starts again */
    /* 0x18 */ u16 line_after_loop;  /* the scroll line goes on from here when a held loop ends */
    /* 0x1A */ u16 unused_1A;
} ScrollEventReader;

#define SCROLL_EVENT_READER(pointer) ((ScrollEventReader *)(pointer))

typedef struct {
    /* 0x00 */ u16 replaying;        /* the events up to the starting line are being run at once */
    /* 0x02 */ ScrollEventReader reader[2];  /* first and second plane */
    /* 0x3A */ u16 sound_call_frames;        /* frames until the routine below is called */
    /* 0x3C */ u16 sound_call[2];            /* a routine a sound command asked for, or 0 */
} ScrollEventsState;

extern ScrollEventsState g_scroll_events;

#endif
