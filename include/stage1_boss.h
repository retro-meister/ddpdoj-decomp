#ifndef DDPDOJ_STAGE1_BOSS_H
#define DDPDOJ_STAGE1_BOSS_H

#include "types.h"
#include "enemy.h"

/*
 * The stage 1 boss's own part of the enemy work block (reg_a5). The body and the two sides take damage
 * separately. 32-bit values are two words, high word first, like everywhere in a work block.
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];   /* EnemyWork */
    /* 0x16 */ u16 body_hp[2];
    /* 0x1A */ u16 right_hp[2];
    /* 0x1E */ u16 left_hp[2];
    /* 0x22 */ u16 leave_delay;   /* frames until the boss gives up and leaves */
    /* 0x24 */ u16 shake;         /* frames of shaking left after a part was destroyed */
} Stage1BossWork;

#define STAGE1_BOSS(pointer) ((Stage1BossWork *)(pointer))

#endif
