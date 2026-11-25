/* Tables all player shot families share. */
#include "common.h"

void player_shot_1_update();
void player_shot_2_update();
void player_shot_3_update();
void player_shot_4_update();
void player_shot_5_update();
void player_shot_6_update();
void player_shot_7_update();
void player_shot_8_update();

extern u16 D_00257800[16];
extern void *player_shot_update_routines[16];

u16 D_00257800[16] = {
    0x8000, 0xA000, 0x8000, 0xB000, 0x8000, 0xC000, 0x8000, 0xD000,
    0x8000, 0xE000, 0x8000, 0xF800, 0x0000, 0x0000, 0x0000, 0x0000,
};

void *player_shot_update_routines[16] = {
    player_shot_1_update,
    player_shot_2_update,
    player_shot_3_update,
    player_shot_4_update,
    player_shot_5_update,
    player_shot_6_update,
    player_shot_7_update,
    player_shot_8_update,
    player_shot_1_update,
    player_shot_2_update,
    player_shot_3_update,
    player_shot_4_update,
    player_shot_5_update,
    player_shot_6_update,
    player_shot_7_update,
    player_shot_8_update,
};
