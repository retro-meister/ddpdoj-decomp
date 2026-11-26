#include "common.h"
#include "task.h"

#include <stdio.h>
#include <stdlib.h>

static u32 observed_ids[TASK_COUNT];
static unsigned int observed_count;
static int stop_on_run;

static void require(int condition, const char *message) {
    if (!condition) {
        fprintf(stderr, "%s\n", message);
        exit(EXIT_FAILURE);
    }
}

static void observe_task(void) {
    const Task *task = TASK(reg_a5);
    require(observed_count < TASK_COUNT, "Too many active tasks");
    observed_ids[observed_count++] = ((u32)task->id[0] << 16) | task->id[1];
    if (stop_on_run) {
        task_stop_self();
    }
}

#define TASK_CALLBACK(index, function) void function(void) { observe_task(); }
#define TASK_RESERVED(index)
#include "task_callbacks.h"
#undef TASK_RESERVED
#undef TASK_CALLBACK

static u32 start_task(u16 slot) {
    reg_d0.w = slot;
    task_start();
    return reg_d0.w;
}

static void run_frame(void) {
    observed_count = 0;
    task_run_all();
}

int main(void) {
    task_reset_all();
    const u32 score = start_task(TASK_SCORE);
    const u32 game = start_task(TASK_GAME);
    const u32 attract = start_task(TASK_ATTRACT);
    require(score == 1 && game == 2 && attract == 3, "Start must assign consecutive IDs");

    reg_d0.w = game;
    task_find();
    require(cond_flag == 1, "A pending start is invisible until the next frame");
    run_frame();
    require(observed_count == 3, "All three callbacks must run");
    require(observed_ids[0] == game && observed_ids[1] == attract && observed_ids[2] == score,
            "Higher priority runs first");

    reg_d0.w = game;
    task_find();
    require(cond_flag == 0, "An active task can be found by its ID");
    reg_a0 = (u8 *)TASK(reg_a0)->id;
    task_request_stop();
    run_frame();
    require(observed_count == 2 && observed_ids[0] == attract && observed_ids[1] == score,
            "A pending stop takes effect before callbacks run");

    task_reset_all();
    for (unsigned int i = 0; i < TASK_COUNT; ++i) {
        require(start_task(TASK_SCORE) == i + 1, "Every request slot must be usable");
    }
    require(start_task(TASK_SCORE) == 0, "A full request queue must reject another start");
    stop_on_run = 1;
    run_frame();
    require(observed_count == TASK_COUNT && observed_ids[0] == TASK_COUNT && observed_ids[TASK_COUNT - 1] == 1,
            "Equal-priority tasks run newest first");
    run_frame();
    require(observed_count == 0, "Self-stops take effect on the following frame");
    return 0;
}
