#ifndef DDPDOJ_TASK_H
#define DDPDOJ_TASK_H

#include "types.h"

/*
 * A task: one of the program's top-level activities (title, ship select, the game itself, the players, the
 * score display, game over, the ending ...). Its routine runs once a frame with the block in reg_a5. Tasks are
 * kept sorted by priority; starting and stopping one is a request that is served at the start of the next frame.
 */
typedef struct {
    /* 0x00 */ u16 state;       /* 0: free; otherwise 0x8000 + index into the task table */
    /* 0x02 */ u8 own[0x48];    /* the task routine's own variables */
    /* 0x4A */ u16 priority;
    /* 0x4C */ u16 id[2];       /* unique number given when the task was started, high word first */
} Task;

#define TASK(pointer) ((Task *)(pointer))

/* Index into the task table (task_table_init); the numbers not listed are not identified yet. */
enum {
    TASK_SCORE = 0,
    TASK_PLAYER1 = 2,
    TASK_PLAYER2 = 3,
    TASK_ENDING = 7,
    TASK_ATTRACT = 8,
    TASK_SHIP_SELECT = 9,
    TASK_GAME = 10,
    TASK_GAME_OVER = 14,
    TASK_CREDITS = 15,
    TASK_TEST_MODE = 16,
    TASK_REPLAY = 20,
    TASK_TABLE_COUNT = 22
};

#define TASK_COUNT 20
#define TASK_BLOCKS_SIZE (TASK_COUNT * sizeof(Task)) /* 0x640 */

void task_reset_all(void);
void task_run_all(void);
void task_start(void);        /* reg_d0: index into the task table; returns the request in reg_a0, the id in reg_d0 */
void task_request_stop(void); /* reg_a0: address of the id words */
void task_stop_self(void);
void task_find(void);         /* reg_d0: id; returns the task in reg_a0, cond_flag 1 when there is none */

#endif
