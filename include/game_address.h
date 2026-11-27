#ifndef DDPDOJ_GAME_ADDRESS_H
#define DDPDOJ_GAME_ADDRESS_H

#include "types.h"

#ifdef DDPDOJ_PC
#define PS2_SMALL_DATA
#else
#define PS2_SMALL_DATA __attribute__((section(".sdata"), aligned(8)))
#endif

/* Address stored high halfword first, including in native replay data. */
typedef u16 PackedGameAddress[2];

#endif
