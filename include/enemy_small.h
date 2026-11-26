#ifndef DDPDOJ_ENEMY_SMALL_H
#define DDPDOJ_ENEMY_SMALL_H

#include "types.h"

/* The small tanks (two in the small enemies unit, a third in the ground enemies unit), in the enemy state
   block (reg_a5) after what every enemy has. One hit point count is used up twice: after the first it smokes and stops turning. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u16 seen;              /* it has been on the screen; when it is off it again it is removed */
    /* 0x18 */ u8 turn_interval;      /* frames between two turns of the turret towards the player */
    /* 0x19 */ u8 turn_countdown;
    /* 0x1A */ u8 fire_interval;      /* frames between the shots of a burst */
    /* 0x1B */ u8 other_1B;
    /* 0x1C */ u8 burst_shots;
    /* 0x1D */ u8 burst_left;
    /* 0x1E */ u16 smoke_frame;       /* 0 to 3 */
    /* 0x20 */ u8 other_20;
    /* 0x21 */ u8 damage;             /* bit 7: the first hit points are gone */
    /* 0x22 */ u16 turret_sprite[2];  /* high word first */
    /* 0x26 */ u16 second_hp;
    /* 0x28 */ u8 other_28;
    /* 0x29 */ u8 fire_countdown;
    /* 0x2A */ u16 draw_body[2];      /* the sprite queue routines of its draw layer, addresses high word first */
    /* 0x2E */ u16 draw_turret[2];
    /* 0x32 */ u8 turret_dir;
    /* 0x33 */ u8 entering;           /* it started beyond the lower edge and has not come in yet */
    /* 0x34 */ u8 hit_palette;        /* mixed into the palette on the frame of a hit */
    /* 0x35 */ u8 palette;
} SmallTankState;

#define SMALL_TANK(pointer) ((SmallTankState *)(pointer))

#endif
