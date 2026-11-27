#ifndef DDPDOJ_SHOT_PLACEMENT_H
#define DDPDOJ_SHOT_PLACEMENT_H

#include "game_address.h"

typedef struct {
    s16 offset_y;
    s16 offset_x;
    PackedGameAddress frames;
} ShotPlacement;

extern ShotPlacement wide_option_placements_3_1[];
extern ShotPlacement wide_option_placements_3_2[];
extern ShotPlacement wide_option_placements_3_3[];
extern ShotPlacement wide_option_placements_3_4[];
extern ShotPlacement wide_option_placements_3_5[];
extern ShotPlacement wide_option_placements_4_1[];
extern ShotPlacement wide_option_placements_4_2[];
extern ShotPlacement wide_option_placements_4_3[];
extern ShotPlacement wide_option_placements_4_4[];
extern ShotPlacement wide_option_placements_4_5[];
extern ShotPlacement shot8_placements_1[];
extern ShotPlacement shot8_placements_2[];
extern ShotPlacement shot8_placements_3[];
extern ShotPlacement shot8_placements_4[];
extern ShotPlacement wide_option_placements_8[];

#endif
