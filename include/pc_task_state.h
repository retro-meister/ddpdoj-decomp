#ifndef DDPDOJ_PC_TASK_STATE_H
#define DDPDOJ_PC_TASK_STATE_H

#include "task.h"
#include <stdbool.h>

typedef struct {
    Task active[TASK_COUNT], starts[TASK_COUNT], stops[TASK_COUNT], dummy;
    u32 last_id;
    u16 start_bytes, stop_bytes;
} PcTaskState;

void pc_tasks_capture(PcTaskState *state);
bool pc_tasks_restore(const PcTaskState *state);

#endif
