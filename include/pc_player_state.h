#ifndef DDPDOJ_PC_PLAYER_STATE_H
#define DDPDOJ_PC_PLAYER_STATE_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    _Alignas(16) uint8_t replay[0x5534];
    uint8_t player_tail[2][112 - 98];
    uint8_t option_tail[2][112 - 100];
    uint32_t boss_hp;
    uint16_t rng_cursor;
} PcPlayerState;

void pc_player_state_capture(PcPlayerState *state);
bool pc_player_state_restore(PcPlayerState *state);

#endif
