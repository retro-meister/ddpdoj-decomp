#ifndef DDPDOJ_ENTITY_H
#define DDPDOJ_ENTITY_H

#include "types.h"

/* A 16-bit field of a state record, with the byte and signed views the code uses. b[0] is the low byte. */
typedef union {
    u16 h;
    s16 sh;
    u8 b[2];
    s8 sb[2];
} Field16;

/*
 * Common header of every game object: enemies and their parts, bullets, items, the players' ships.
 * The object routines get the current one in reg_a6. What follows the header depends on the kind of object.
 * Positions are in 1/64 pixel.
 */
typedef struct {
    /* 0x00 */ Field16 flags;        /* 0: slot free; bit 15: active */
    /* 0x02 */ Field16 y;
    /* 0x04 */ Field16 x;
    /* 0x06 */ Field16 offset_y;
    /* 0x08 */ Field16 offset_x;
    /* 0x0A */ union {
        u16 h;
        s16 sh;
        struct { u8 flip; u8 priority; } b;
        struct { s8 flip; s8 priority; } sb;
    } draw;
    /* 0x0C */ Field16 sprite;       /* sprite number */
    /* 0x0E */ union {
        u16 h;
        s16 sh;
        struct { u8 palette; u8 size; } b;
        struct { s8 palette; s8 size; } sb;
    } look;
    /* 0x10 */ Field16 hit_y_plus;   /* hit box, as distances from the position */
    /* 0x12 */ Field16 hit_y_minus;
    /* 0x14 */ Field16 hit_x_plus;
    /* 0x16 */ Field16 hit_x_minus;
    /* 0x18 */ Field16 hp;
    /* 0x1A */ union {
        u16 h;
        s16 sh;
        struct { u8 dir; u8 speed; } b;
        struct { s8 dir; s8 speed; } sb;
    } move;
    /* 0x1C */ union {               /* how the sprite queue draws it */
        u16 h;
        s16 sh;
        struct { u8 palette; u8 flip; } b;
        struct { s8 palette; s8 flip; } sb;
    } attr;
    /* 0x1E */ union {
        u16 h;
        s16 sh;
        struct { u8 draw_layer; u8 user; } b;   /* user: free for the object's own routine */
        struct { s8 draw_layer; s8 user; } sb;
    } misc;
} Entity;

#define ENTITY(pointer) ((Entity *)(pointer))

#endif
