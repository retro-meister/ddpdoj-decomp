#ifndef DDPDOJ_SCENERY_H
#define DDPDOJ_SCENERY_H

#include "types.h"
#include "entity.h"

/*
 * A piece of stage scenery drawn as a sprite over the background: 0x20 bytes, in reg_a6 when its routines run.
 * Each piece has a set-up routine, which stores its sprite, size, palette and per-frame routine, and that
 * per-frame routine, which lets it go once it has scrolled off the screen and otherwise moves and draws it.
 */
typedef struct {
    /* 0x00 */ Field16 flags;
    /* 0x02 */ Field16 y;
    /* 0x04 */ Field16 x;
    /* 0x06 */ Field16 frame;          /* animated pieces: byte offset into their table of frames */
    /* 0x08 */ u16 routine[2];         /* address of the per-frame routine, high word first */
    /* 0x0C */ Field16 palette;
    /* 0x0E */ u16 unused_0E;
    /* 0x10 */ u16 sprite[2];          /* sprite number as a 32-bit value, high word first */
    /* 0x14 */ union {
        Field16 size;
        u16 second_sprite[2];          /* pieces made of two sprites */
    } part;
    /* 0x18 */ u8 frame_time;
    /* 0x19 */ u8 frame_countdown;
    /* 0x1A */ u8 unused_1A[6];
} Scenery;

#define SCENERY(pointer) ((Scenery *)(pointer))

/* A piece's set-up routine; the scroll events unit has each stage's table of them. */
typedef void (*ScenerySetup)(void);

/* The eight pieces a stage can show at once, and the table of the stage being played. */
typedef struct {
    /* 0x000 */ Scenery pieces[8];
    /* 0x100 */ ScenerySetup *setups;
} SceneryState;

extern SceneryState g_scenery;

/* Draws the piece in reg_a6 with one of the sprite queue's draw routines. */
s32 scenery_draw(s32 *draw_routine);

/* The plays that go straight to the bosses have no scenery. */
extern u8 g_game_mode;
extern u8 g_simulation_active;
extern u8 g_simulation_boss_start;

#define GAME_MODE_BOSS_RUSH 2

#define NO_SCENERY_IN_THIS_PLAY() \
    (((g_simulation_active != 0) && (g_simulation_boss_start != 0)) || (g_game_mode == GAME_MODE_BOSS_RUSH))

#endif
