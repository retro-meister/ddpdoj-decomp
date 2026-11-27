#ifndef SPRITE_QUEUE_H
#define SPRITE_QUEUE_H

#include "common.h"


typedef struct {
    u8 last_boss[48];
    u8 laser_trail[128];
    u8 hyper_display[128];
    u8 hyper_ready[32];
    u8 maximum[32];
    u8 stage_clear2[128];
    u8 stage_clear1[128];
    u8 ship_select[128];
    u8 bombs[1088];
    u8 sight[128];
    u8 score[384];
    u8 warning[192];
    u8 bullets2[MAIN_OR_DEATH_LABEL(2528, 12608)];
    u8 bullets[MAIN_OR_DEATH_LABEL(2528, 12608)];
    u8 sparks[720];
    u8 players[192];
    u8 options[48];
    u8 player_lasers[768];
    u8 player_shots[864];
    u8 debris2[240];
    u8 debris1[240];
    u8 player_shadows[80];
    u8 items[304];
    u8 items_first[304];
    u8 special_items[848];
    u8 extra[MAIN_OR_DEATH_LABEL(11952, 28032)];
    u8 layer5[MAIN_OR_DEATH_LABEL(5984, 14016)];
    u8 layer4[MAIN_OR_DEATH_LABEL(5984, 14016)];
    u8 layer3[MAIN_OR_DEATH_LABEL(5984, 14016)];
    u8 layer2[MAIN_OR_DEATH_LABEL(5984, 14016)];
    u8 layer1[MAIN_OR_DEATH_LABEL(11952, 28032)];
} SpriteQueueStorage;

extern SpriteQueueStorage g_sprite_queues;

/* Queue writes may continue into the next queue. */
#ifdef DDPDOJ_PC
#include <stddef.h>
#define SPRITE_QUEUE_BASE(field) ((u8 *)&g_sprite_queues + offsetof(SpriteQueueStorage, field))
#else
#define SPRITE_QUEUE_BASE(field) (g_sprite_queues.field)
#endif

#endif
