#include "combat_state.h"
#include <string.h>

extern u8 g_explosions[4480];
extern u8 explosion_spawn_buffer[64];
extern u8 g_sparks[2048];
extern u16 g_wrecks[720];
extern u16 g_wreck_count[8];
extern u16 g_debris[640];
extern u16 g_debris_count[8];
extern u32 debris_spawn_state;
extern u8 g_stage_enemy_cursor[32];
extern u8 g_bullets[PC_BULLET_POOL_BYTES];
extern u16 g_spawn_request_end, g_enemy_count, g_enemy_count_second, D_0028E7EC;
extern s16 D_0028E7E0, D_0028E7DC, D_0028E7D8;

void pc_combat_capture(PcCombatPools *state)
{
    memcpy(state->explosions, g_explosions, sizeof(g_explosions));
    memcpy(state->pending_explosion, explosion_spawn_buffer, sizeof(explosion_spawn_buffer));
    memcpy(state->sparks, g_sparks, sizeof(g_sparks));
    memcpy(state->wrecks, g_wrecks, sizeof(g_wrecks));
    memcpy(state->wreck_counts, g_wreck_count, sizeof(g_wreck_count));
    memcpy(state->debris, g_debris, sizeof(g_debris));
    memcpy(state->debris_counts, g_debris_count, sizeof(g_debris_count));
    state->debris_spawn = debris_spawn_state;
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
    memcpy(g_explosions, state->explosions, sizeof(g_explosions));
    memcpy(explosion_spawn_buffer, state->pending_explosion, sizeof(explosion_spawn_buffer));
    memcpy(g_sparks, state->sparks, sizeof(g_sparks));
    memcpy(g_wrecks, state->wrecks, sizeof(g_wrecks));
    memcpy(g_wreck_count, state->wreck_counts, sizeof(g_wreck_count));
    memcpy(g_debris, state->debris, sizeof(g_debris));
    memcpy(g_debris_count, state->debris_counts, sizeof(g_debris_count));
    debris_spawn_state = state->debris_spawn;
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
