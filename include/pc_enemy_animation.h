#ifndef DDPDOJ_PC_ENEMY_ANIMATION_H
#define DDPDOJ_PC_ENEMY_ANIMATION_H

#include "types.h"

/* Arcade animation indices are byte offsets into the PS2's 4-byte entries. */
u8 *pc_enemy_animation_definition(u16 offset);
void (*pc_enemy_animation_draw(u16 offset))(void);

#endif
