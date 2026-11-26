#ifndef DDPDOJ_STAGE5_MIDBOSS_H
#define DDPDOJ_STAGE5_MIDBOSS_H

#include "types.h"
#include "entity.h"
#include "enemy.h"

/* The last entity of the stage 5 mid-bosses 4 and 5 is not drawn. It holds the damage flags and the values of
   the explosions. */
typedef struct {
    /* 0x00 */ u8 unused_00[7];
    /* 0x07 */ u8 dying_step;          /* 0: explosions, 1: waiting, 2: over */
    /* 0x08 */ EnemyTimer blast_timer;
    /* 0x0A */ u16 blast;              /* offset of the next explosion in the table */
    /* 0x0C */ u16 blast_rounds;
    /* 0x0E */ u16 hit_by;
    /* 0x10 */ u8 unused_10[0xE];
    /* 0x1E */ u8 dying;
    /* 0x1F */ u8 gone;
} Stage5MidbossDamage;

#define STAGE5_MIDBOSS4_DAMAGE(pointer) (&((Stage5MidbossDamage *)(pointer))[5])
#define STAGE5_MIDBOSS5_DAMAGE(pointer) (&((Stage5MidbossDamage *)(pointer))[4])

/* The wave beam of mid-boss 4. Its request gives the owner and the side. */
typedef struct {
    /* 0x00 */ u8 common[0x16];
    /* 0x16 */ u16 owner[2];           /* address of the mid-boss's first entity, high word first */
    /* 0x1A */ u16 left;
    /* 0x1C */ u8 unused_1C;
    /* 0x1D */ u8 parts;               /* bit 0: the charge, 1: the burst, 2: the wave, 3: pushing the cannon back */
    /* 0x1E */ u16 charge_frame;
    /* 0x20 */ EnemyTimer charge_timer;
    /* 0x22 */ u16 burst_frame;
    /* 0x24 */ EnemyTimer burst_timer;
    /* 0x26 */ u16 wave_frame;
    /* 0x28 */ EnemyTimer wave_timer;
    /* 0x2A */ u16 unused_2A;
} Stage5Midboss4WaveBeamState;

#define STAGE5_MIDBOSS4_WAVE_BEAM(pointer) ((Stage5Midboss4WaveBeamState *)(pointer))

#endif
