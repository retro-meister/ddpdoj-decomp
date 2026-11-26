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
    /* 0x0A */ u16 line_step;        /* its placement's position inside the scroll line */
    /* 0x0C */ u8 start_flags;
    /* 0x0D */ u8 kind;              /* which enemy: index into the routine tables */
    /* 0x0E */ u8 other_0E[2];       /* not identified yet */
    /* 0x10 */ Field16 path_frames;  /* b[1]: frames spent on the present step of the path */
    /* 0x12 */ u16 path[2];          /* address of the next step of its path, high word first */
    /* 0x16 */ u8 own[0x2A];
    /* 0x40 */ u16 path_speed_y;     /* what the present step moves it by every frame */
    /* 0x42 */ u16 path_speed_x;
    /* 0x44 */ u8 own_44[4];
    /* 0x48 */ u16 start_y;
    /* 0x4A */ u16 start_x;
    /* 0x4C */ u16 routine[2];       /* address of the routine run every frame, high word first */
} EnemyState;

/* The running enemies: two slots for the largest enemies, eight for spawners, 48 for every other
   enemy. A claim that finds no free slot gets `none`. */
typedef union {
    struct {
        /* 0x0000 */ EnemyState large[2];
        /* 0x00A0 */ EnemyState spawners[8];
        /* 0x0320 */ EnemyState others[48];
        /* 0x1220 */ EnemyState none;
    } slot;
    struct {             /* the same as bytes: the reset clears them so */
        s8 large[0xA0];
        s8 spawners[0x280];
        s8 others[0xF00];
        s8 none[0x50];
    } bytes;
} EnemySlots;

extern EnemySlots g_enemy_slots;
/* Requests to start an enemy, served at the start of the next frame. */
extern EnemyState g_spawn_requests[40];
extern EnemyState g_spawn_request_spare;
/* The enemies' entities: 100 in the first pool, 50 in the second (start flags 0x20 and 0x80), and 50 more that
   the ending, the credits and two bosses use for themselves. */
extern Entity g_enemy_entities[100];
extern Entity g_enemy_entities_second[];
extern Entity g_spare_entities[50];

/* An enemy kind's routines. */
typedef struct {
    void (*start)();
    void (*run)();
} EnemyRoutines;

extern EnemyRoutines g_enemy_routines[128];
extern void (*g_enemy_first_routines[128])();
extern EnemyRoutines g_enemy_routines_high[128];
extern void (*g_enemy_first_routines_high[128])();

#define ENEMY_STATE(pointer) ((EnemyState *)(pointer))

#define ENEMY_FLAG_NEW_STEP 0x20     /* EnemyState.flags: the path has moved on; work the speed out again */
#define ENEMY_FLAG_FROM_SPAWNER 0x40 /* EnemyState.flags: started by a spawner, at start_y/start_x */

#endif
