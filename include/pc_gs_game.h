#ifndef DDPDOJ_PC_GS_GAME_H
#define DDPDOJ_PC_GS_GAME_H

#include <stdbool.h>

void pc_gs_game_reset(void);
bool pc_gs_game_display(int width, int field_height, bool wide);
void pc_gs_game_target(unsigned base, int width, int height);
bool pc_gs_begin_frame(void);

#endif
