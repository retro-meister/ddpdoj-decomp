#ifndef DDPDOJ_PC_COMBAT_STATE_H
#define DDPDOJ_PC_COMBAT_STATE_H

#include "enemy.h"
#include <stdbool.h>

#ifdef DEATH_LABEL
#define PC_BULLET_POOL_BYTES 0x10690
#else
#define PC_BULLET_POOL_BYTES 0x3490
#endif

typedef struct {
    EnemySlots enemies;
    Entity entities[150], spare_entities[50];
    EnemyState requests[40], spare_request;
    u8 explosions[4480];
    u8 pending_explosion[64];
    u8 sparks[2048];
    u16 wrecks[720];
    u16 wreck_counts[8];
    u16 debris[640];
    u16 debris_counts[8];
    u32 debris_spawn;
    u8 placement[32];
    u8 bullets[PC_BULLET_POOL_BYTES];
    u16 request_end, enemy_count, second_count, occupied;
    s16 small_enemy_flag, small_enemy_counter, unread_counter;
} PcCombatPools;

void pc_combat_capture(PcCombatPools *state);
bool pc_combat_restore(const PcCombatPools *state);

#endif
