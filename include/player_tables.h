#ifndef DDPDOJ_PLAYER_TABLES_H
#define DDPDOJ_PLAYER_TABLES_H

#include "types.h"

typedef struct {
    /* 0x00 */ u16 unused_00[3];
    u16 no_hypers;
    u16 values[25];
} HyperSpeedTable;

extern HyperSpeedTable hyper_speed_steps;
/* The activation code subtracts one even when the total is zero. */
#define HYPER_SPEED_VALUES ((u8 *)&hyper_speed_steps + sizeof(hyper_speed_steps.unused_00) + sizeof(u16))

#ifdef DDPDOJ_BONUS_FEATURES
typedef struct {
    u16 no_hypers;
    u16 values[2][35];
} BlackLabelHyperSpeedTable;
extern BlackLabelHyperSpeedTable black_label_speed_steps;
#define BLACK_LABEL_SPEED_VALUES(loop) ((u8 *)&black_label_speed_steps + sizeof(u16) + (loop) * sizeof(black_label_speed_steps.values[0]))
#endif

typedef struct {
    u16 shot_bomb[2];
    u16 laser_bomb[2];
    u16 option_frames[2][2]; /* sprite number, high word first */
} BombDisplayTable;

#endif
