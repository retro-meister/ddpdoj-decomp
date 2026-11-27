#ifndef DDPDOJ_PC_STATE_SLOT_H
#define DDPDOJ_PC_STATE_SLOT_H

#include <SDL3/SDL.h>
#include "game_loop.h"

bool pc_state_slot_write(const char *path, GameMode mode, Uint64 build,
                         const void *data, size_t size);
/* The caller owns the returned buffer. The slot is checked before it is exposed. */
void *pc_state_slot_read(const char *path, GameMode mode, Uint64 build, size_t *size);

#endif
