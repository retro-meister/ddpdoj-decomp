#ifndef DDPDOJ_EXPLOSION_H
#define DDPDOJ_EXPLOSION_H

#include "types.h"
#include "entity.h"

/* An explosion. explosion_spawn returns the new one in reg_a0 for the caller to fill in. */
typedef struct {
    /* 0x00 */ Field16 kind;         /* b[0]: kind; b[1]: 0x80 in use, 0x40 started */
    /* 0x02 */ u16 y;
    /* 0x04 */ u16 x;
    /* 0x06 */ u16 offset_y;
    /* 0x08 */ u16 offset_x;
    /* 0x0A */ u16 draw;
    /* 0x0C */ u16 sprite;
    /* 0x0E */ u16 look;
    /* 0x10 */ u16 follows_scroll;
    /* 0x12 */ u16 debris;           /* 0xFFFF: none */
    /* 0x14 */ u16 debris_arg;
    /* 0x16 */ u8 other_16;
    /* 0x17 */ u8 debris_palette;
    /* 0x18 */ u16 delay;
    /* 0x1A */ union {
        u16 h;
        struct { u8 dir; u8 speed; } b;
    } move;
    /* 0x1C */ union {
        u16 h;
        struct { u8 palette; u8 flip; } b;
    } attr;
    /* 0x1E */ u16 draw_layer;
    /* 0x20 */ union {
        u16 h;
        struct { u8 reload; u8 count; } t;
    } drag_timer;
    /* 0x22 */ u16 drag_y;
    /* 0x24 */ u16 drag_x;
    /* 0x26 */ u16 start_y;          /* added to the position when it starts */
    /* 0x28 */ u16 start_x;
    /* 0x2A */ u16 frames[2];        /* pointer, high word first */
    /* 0x2E */ u16 times[2];         /* pointer, high word first */
    /* 0x32 */ u16 frame_time;
    /* 0x34 */ u16 speed_y;
    /* 0x36 */ u16 speed_x;
} Explosion;

#define EXPLOSION(pointer) ((Explosion *)(pointer))

/* A row of a list of explosions: six words. The list ends with BLAST_END in place of a row. */
#define BLAST(delay, kind, flip, start_y, start_x) delay, kind, flip, start_y, start_x, 0
#define BLAST_NOW(kind, flip, start_y, start_x) kind, flip, start_y, start_x, 0   /* five words */
#define BLAST_SHORT(kind, flip, start_y, start_x) kind, flip, start_y, start_x      /* four words */
#define BLAST_END -1

#endif
