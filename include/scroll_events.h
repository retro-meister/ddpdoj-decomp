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
/* Set the plane's scroll speed, in 1/256 pixel a frame. */
#define SCROLL_SPEED(line, speed) SCROLL_EVENT(line, 0x08), (speed)
/* Hold the scroll line while the map loop runs; when the loop ends the line goes on from four lines later. */
#define SCROLL_LINE_HOLD(line) SCROLL_EVENT(line, 0x0C)
/* Start one of the stage's ground objects at a position (1/64 pixel). */
#define SCROLL_OBJECT(line, object, y, x) SCROLL_EVENT(line, 0x10), (object), (y), (x)
/* Run the next `count` commands of the stage's sound list. */
#define SCROLL_SOUNDS(line, count) SCROLL_EVENT(line, 0x14), (count)
/* Set the first `count` of the four flags at D_00299768. */
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

#endif
