/* Global variables of the enemy unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"
#include "enemy.h"

/* .sbss (the compiler lays these out in reverse) */
u16 D_0028E7EC __attribute__((aligned(4)));
u16 D_0028E7E8 __attribute__((aligned(4)));
u16 D_0028E7E4 __attribute__((aligned(4)));
s16 D_0028E7E0 __attribute__((aligned(4)));
s16 D_0028E7DC __attribute__((aligned(4)));
s16 D_0028E7D8 __attribute__((aligned(4)));
u16 g_spawn_request_end __attribute__((aligned(4)));

/* .bss (the compiler lays these out in reverse) */
u8 g_stage_enemy_cursor[32];
EnemySlots g_enemy_slots;
Entity g_spare_entities[50];
#ifdef DEATH_LABEL
u8 death_D_006901F0[1024];
u8 death_D_006901D0[32];
u8 death_D_006901B0[32];
#endif
#ifdef DEATH_LABEL
Entity g_enemy_entities_second[16];
#else
Entity g_enemy_entities_second[50];
#endif
Entity g_enemy_entities[100];
EnemyState g_spawn_requests[40];
EnemyState g_spawn_request_spare;
