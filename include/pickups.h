#ifndef DDPDOJ_PICKUPS_H
#define DDPDOJ_PICKUPS_H

#include "black_label.h"

enum {
    PICKUP_SIZE = 0x2c,
    PICKUP_COUNT = 70,
    BEE_PICKUP_COUNT = 10,
    /* The retail replay header uses bytes 0x00..0x3f of its 0x400 bytes. */
    REPLAY_BEE_PICKUPS_OFFSET = 0x200,
};

#ifdef DDPDOJ_BONUS_FEATURES
extern unsigned char black_label_pickups[(PICKUP_COUNT + BEE_PICKUP_COUNT) * PICKUP_SIZE];
void bee_pickup_spawn(void);
#endif

#define ACTIVE_PICKUPS GAME_RULE(g_pickups, black_label_pickups)
#define ACTIVE_PICKUP_BYTES GAME_RULE(PICKUP_COUNT * PICKUP_SIZE, sizeof(black_label_pickups))
#endif
