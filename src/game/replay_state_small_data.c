/* Small data of the replay state unit, still to be merged into it. */
#include "common.h"

extern u8 g_p1_lives[];
extern u8 g_p2_lives[];
extern u8 g_player1[];
extern u8 g_player2[];

extern void *replay_targets_players[2];
extern void *replay_targets_lives[2];
#ifndef DEATH_LABEL
extern u16 D_0028DE60[4];
#endif
#ifndef DEATH_LABEL
extern u16 D_0028DE68[4];
#endif
#ifndef DEATH_LABEL
extern u16 D_0028DE70[4];
#endif
#ifndef DEATH_LABEL
extern u16 D_0028DE78[4];
#endif

void *replay_targets_players[2] = {
    g_player1,
    g_player2,
};

void *replay_targets_lives[2] = {
    g_p1_lives,
    g_p2_lives,
};

#ifndef DEATH_LABEL
u16 D_0028DE60[4] = {
    0x0000, 0x0000, 0x0000, 0x0000,
};
#endif

#ifndef DEATH_LABEL
u16 D_0028DE68[4] = {
    0x0000, 0x0000, 0x0000, 0x0000,
};
#endif

#ifndef DEATH_LABEL
u16 D_0028DE70[4] = {
    0x0000, 0x0000, 0x0000, 0x0000,
};
#endif

#ifndef DEATH_LABEL
u16 D_0028DE78[4] = {
    0x0000, 0x0000, 0x0000, 0x0000,
};
#endif
