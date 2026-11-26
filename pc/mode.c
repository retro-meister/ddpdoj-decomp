#include "game_loop.h"

static GameMode requested_mode;

void game_request_mode(GameMode mode) {
    requested_mode = mode;
}

GameMode game_take_mode_request(void) {
    GameMode mode = requested_mode;
    requested_mode = GAME_MODE_NONE;
    return mode;
}
