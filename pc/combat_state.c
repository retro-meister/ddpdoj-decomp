#include "combat_state.h"
#include <string.h>

extern u8 g_stage_enemy_cursor[32];
extern u8 g_bullets[PC_BULLET_POOL_BYTES];
extern u16 g_spawn_request_end, g_enemy_count, g_enemy_count_second, D_0028E7EC;
extern s16 D_0028E7E0, D_0028E7DC, D_0028E7D8;

void pc_combat_capture(PcCombatPools *state)
{
    state->enemies = g_enemy_slots;
    memcpy(state->entities, g_enemy_entities, sizeof(g_enemy_entities));
    memcpy(state->spare_entities, g_spare_entities, sizeof(g_spare_entities));
    memcpy(state->requests, g_spawn_requests, sizeof(g_spawn_requests));
    state->spare_request = g_spawn_request_spare;
    memcpy(state->placement, g_stage_enemy_cursor, sizeof(g_stage_enemy_cursor));
    memcpy(state->bullets, g_bullets, sizeof(g_bullets));
    state->request_end = g_spawn_request_end;
    state->enemy_count = g_enemy_count;
    state->second_count = g_enemy_count_second;
    state->occupied = D_0028E7EC;
    state->small_enemy_flag = D_0028E7E0;
    state->small_enemy_counter = D_0028E7DC;
    state->unread_counter = D_0028E7D8;
}

bool pc_combat_restore(const PcCombatPools *state)
{
    if (state->request_end > sizeof(g_spawn_requests) ||
        state->request_end % sizeof(EnemyState)) return false;
    g_enemy_slots = state->enemies;
    memcpy(g_enemy_entities, state->entities, sizeof(g_enemy_entities));
    memcpy(g_spare_entities, state->spare_entities, sizeof(g_spare_entities));
    memcpy(g_spawn_requests, state->requests, sizeof(g_spawn_requests));
    g_spawn_request_spare = state->spare_request;
    memcpy(g_stage_enemy_cursor, state->placement, sizeof(g_stage_enemy_cursor));
    memcpy(g_bullets, state->bullets, sizeof(g_bullets));
    g_spawn_request_end = state->request_end;
    g_enemy_count = state->enemy_count;
    g_enemy_count_second = state->second_count;
    D_0028E7EC = state->occupied;
    D_0028E7E0 = state->small_enemy_flag;
    D_0028E7DC = state->small_enemy_counter;
    D_0028E7D8 = state->unread_counter;
    return true;
}
