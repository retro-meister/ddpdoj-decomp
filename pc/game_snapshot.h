#ifndef DDPDOJ_GAME_SNAPSHOT_H
#define DDPDOJ_GAME_SNAPSHOT_H

#include "state_slot.h"

bool pc_game_save(const char *path, GameMode mode, Uint64 build);
bool pc_game_load(const char *path, GameMode mode, Uint64 build);

#endif
