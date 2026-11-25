#ifndef DDPDOJ_ENEMY_H
#define DDPDOJ_ENEMY_H

#include "types.h"
#include "entity.h"

/*
 * State block of one running enemy, 0x50 bytes. The enemy's routines get it in reg_a5 and its first entity in
 * reg_a6. A request to start an enemy is a block of the same layout, copied into a free slot when it is served.
 * Only the fields every enemy shares are named here; `own` belongs to the enemy's routines, and each unit
 * describes its use of it with a record type of its own.
 */
typedef struct {
    /* 0x00 */ Field16 state;        /* 0: slot free */
    /* 0x02 */ u8 target_player;     /* 0 or 1 */
    /* 0x03 */ u8 flags;
    /* 0x04 */ u16 entity_count;     /* number of entities, minus one */
    /* 0x06 */ u16 entities[2];      /* address of the first entity, high word first */
    /* 0x0A */ u8 other_0A[2];       /* not identified yet */
    /* 0x0C */ u8 start_flags;
    /* 0x0D */ u8 kind;              /* which enemy: index into the routine tables */
    /* 0x0E */ u8 other_0E[4];       /* not identified yet */
    /* 0x12 */ u16 script[2];        /* address of its placement or movement data, high word first */
    /* 0x16 */ u8 own[0x32];
    /* 0x48 */ u16 start_y;
    /* 0x4A */ u16 start_x;
    /* 0x4C */ u16 routine[2];       /* address of the routine run every frame, high word first */
} EnemyState;

#define ENEMY_WORK(pointer) ((EnemyState *)(pointer))

#define ENEMY_FLAG_FROM_SPAWNER 0x40 /* EnemyState.flags: started by a spawner, at start_y/start_x */

#endif
