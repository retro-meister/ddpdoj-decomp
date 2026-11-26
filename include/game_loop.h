#ifndef DDPDOJ_GAME_LOOP_H
#define DDPDOJ_GAME_LOOP_H

#include <stdbool.h>

typedef enum {
    GAME_MODE_NONE,
    GAME_MODE_MAIN,
    GAME_MODE_DEATH_LABEL,
    GAME_MODE_GALLERY,
} GameMode;

void game_boot_begin(void);
/* Runs one loading frame. Returns true when gameplay frames can begin. */
bool game_boot_frame(void);
void game_run_frame(void);

/* The game requests a launch during a frame. The host handles it after that frame. */
void game_request_mode(GameMode mode);
GameMode game_take_mode_request(void);

#endif
