#include "common.h"
#include "task.h"

#ifdef DDPDOJ_PC
#include "pc_task_state.h"
#include <stdlib.h>
#include <string.h>

#define TASK_CALLBACK(index, function) extern void function(void);
#define TASK_RESERVED(index)
#include "task_callbacks.h"
#undef TASK_RESERVED
#undef TASK_CALLBACK

static void (*const task_callbacks[TASK_TABLE_COUNT])(void) = {
#define TASK_CALLBACK(index, function) [index] = function,
#define TASK_RESERVED(index)
#include "task_callbacks.h"
#undef TASK_RESERVED
#undef TASK_CALLBACK
};
#endif

void task_serve_start_requests(void);
void task_serve_stop_requests(void);
void task_remove(void);
void task_blocks_copy_backward(void);
void task_blocks_copy_forward(void);

/* (the compiler lays these out in reverse) */
u16 g_task_start_requests_used __attribute__((aligned(4))); /* in bytes */
u16 g_task_stop_requests_used __attribute__((aligned(4)));
s16 g_task_unused __attribute__((aligned(4)));
u32 g_task_last_id;

#ifdef DDPDOJ_PC
_Static_assert(sizeof(Task) == 0x50, "Task layout differs from the game");
static Task active_tasks[TASK_COUNT];
static Task stop_requests[TASK_COUNT];
static Task start_requests[TASK_COUNT];
static Task dummy_task;
void pc_tasks_capture(PcTaskState *state)
{
    memcpy(state->active, active_tasks, sizeof(active_tasks));
    memcpy(state->starts, start_requests, sizeof(start_requests));
    memcpy(state->stops, stop_requests, sizeof(stop_requests));
    state->dummy = dummy_task;
    state->last_id = g_task_last_id;
    state->start_bytes = g_task_start_requests_used;
    state->stop_bytes = g_task_stop_requests_used;
}

static bool valid_task(const Task *task)
{
    unsigned index = task->state & 0xff;
    return !task->state || (task->state == (0x8000 | index) &&
                            index < TASK_TABLE_COUNT && task_callbacks[index]);
}

bool pc_tasks_restore(const PcTaskState *state)
{
    if (state->start_bytes > sizeof(start_requests) || state->start_bytes % sizeof(Task) ||
        state->stop_bytes > sizeof(stop_requests) || state->stop_bytes % sizeof(Task)) return false;
    for (unsigned i = 0; i < TASK_COUNT; ++i) {
        if (!valid_task(&state->active[i]) ||
            (i < state->start_bytes / sizeof(Task) && !valid_task(&state->starts[i]))) return false;
    }
    memcpy(active_tasks, state->active, sizeof(active_tasks));
    memcpy(start_requests, state->starts, sizeof(start_requests));
    memcpy(stop_requests, state->stops, sizeof(stop_requests));
    dummy_task = state->dummy;
    g_task_last_id = state->last_id;
    g_task_start_requests_used = state->start_bytes;
    g_task_stop_requests_used = state->stop_bytes;
    return true;
}

#define g_tasks ((u8 *)&active_tasks)
#define g_task_start_requests ((u8 *)&start_requests)
#define g_task_stop_requests ((u8 *)&stop_requests)
#define g_task_dummy ((u8 *)&dummy_task)
#define TASK_COUNTER_ACTIVE(counter) ((s16)(counter) >= 0)
#define TASK_MASKED_COUNTER_ACTIVE(counter) TASK_COUNTER_ACTIVE(counter)
#else
extern u8 g_tasks[];
extern u8 g_task_stop_requests[];
extern u8 g_task_start_requests[];
extern u8 g_task_dummy[];   /* what a failed start or search returns, so that the caller's stores land somewhere */
#define TASK_COUNTER_ACTIVE(counter) (((s64)((s64)(u16)(counter) << 0x30) >> 0x30) >= 0)
#define TASK_MASKED_COUNTER_ACTIVE(counter) (((s64)((s64)((counter) & 0xFFFF) << 0x30) >> 0x30) >= 0)
#endif
extern u16 g_task_table[];  /* per task: routine address (two words), priority, one unused word */


void task_reset_all(void) {
    g_task_last_id = 0;
    g_task_unused = 0;
    reg_a0 = g_tasks;
    g_task_start_requests_used = 0;
    reg_d0.w = TASK_COUNT - 1;
    g_task_stop_requests_used = 0;
    do {
        *(s16 *)reg_a0 = 0;
        TASK(reg_a0)->priority = 0;
        TASK(reg_a0)->id[0] = 0;
        TASK(reg_a0)->id[1] = 0;
        reg_a0 += sizeof(Task);
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

#ifndef DDPDOJ_PC
typedef void (*Fn)();
extern u32 reg_call_target_as_u32;
#endif

void task_run_all(void) {
    u32 remaining;
    u16 *task;

    task_serve_stop_requests();
    task_serve_start_requests();
    reg_a5 = (u8 *)(g_tasks);
    reg_d0.w = TASK_COUNT - 1;
    do {
        task = (u16 *)(reg_a5);
        reg_d1.h[0] = *task;
        if (reg_d1.h[0] != 0) {
            reg_d1.h[0] &= 0xFF;
            reg_d1.h[0] *= 8;
            remaining = reg_d0.w;
            reg_a0 = (u8 *)(g_task_table);
#ifdef DDPDOJ_PC
            unsigned int index = reg_d1.h[0] / 8;
            if (index >= TASK_TABLE_COUNT || !task_callbacks[index]) {
                abort();
            }
            task_callbacks[index]();
#else
            reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp.h[0] = (((reg_d1.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d1.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_call_target_as_u32 = reg_tmp.w;
            ((Fn)reg_call_target_as_u32)();
#endif
            reg_d0.w = remaining;
            reg_a5 = (u8 *)(task);
        }
        reg_a5 += sizeof(Task);
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

#ifndef DDPDOJ_PC
void task_blocks_copy_backward(void) {
    u8 *a2;
    u8 *a3;
    s32 d3;
    u32 tmp;

    d3 = reg_d3.w;
    a2 = reg_a2;
    a3 = reg_a3;
    reg_a2 += reg_d3.h[0];
    reg_a3 += reg_d3.h[0];
    reg_d3.w >>= 2;
    reg_d3.w -= 1;
copy_long:
    reg_a3 -= 4;
    reg_a2 -= 4;
    *(u16 *) (reg_a2 + 0) = *(u16 *) (reg_a3 + 0);
    *(u16 *) (reg_a2 + 2) = *(u16 *) (reg_a3 + 2);
    tmp = reg_d3.h[0] - 1;
    reg_d3.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto copy_long;
    reg_d3.w = d3;
    reg_a2 = a2;
    reg_a3 = a3;
}


void task_blocks_copy_forward(void) {
    u8 *destination;
    u8 *source;
    u32 size;

    size = reg_d3.w;
    destination = reg_a2;
    source = reg_a3;
    reg_d3.w = size >> 2;
    reg_d3.w -= 1;
    do {
        *(u16 *)reg_a2 = *(u16 *)reg_a3;
        reg_a3 += 2;
        reg_a2 += 2;
        *(u16 *)reg_a2 = *(u16 *)reg_a3;
        reg_a3 += 2;
        reg_a2 += 2;
    } while ((s16)(--reg_d3.h[0]) >= 0);
    reg_d3.w = size;
    reg_a2 = destination;
    reg_a3 = source;
}
#endif


void task_serve_start_requests(void) {
    u32 tmp;

    if (g_task_start_requests_used == 0) goto no_requests;
    reg_a0 = (u8 *)g_task_start_requests;
serve_request:
    if (*(u16 *)reg_a0 == 0) goto next_request;
    reg_d5.h[0] = TASK(reg_a0)->priority;
    reg_a1 = (u8 *)g_tasks;
    reg_d6.w = TASK_COUNT - 1;
find_place:
    if ((s16) TASK(reg_a1)->priority > (s16) reg_d5.h[0]) goto try_next_task;
    reg_a2 = reg_a1 + sizeof(Task);
    reg_a3 = reg_a1;
#ifdef DDPDOJ_PC
    reg_d3.w = (u32)(g_tasks + TASK_BLOCKS_SIZE - reg_a2);
    memmove(reg_a2, reg_a3, reg_d3.w);
#else
    reg_d4.w = (u32) reg_a2;
    reg_d3.w = (u32) g_task_stop_requests;
    reg_d3.w -= reg_d4.w;
    task_blocks_copy_backward();
#endif
    reg_a2 = reg_a0;
    reg_d2.h[0] = 0x27;
copy_word:
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    tmp = reg_d2.h[0] - 1;
    reg_d2.h[0] = tmp;
    if (TASK_MASKED_COUNTER_ACTIVE(tmp)) goto copy_word;
    goto next_request;
try_next_task:
    reg_a1 += sizeof(Task);
    tmp = reg_d6.h[0] - 1;
    reg_d6.h[0] = tmp;
    if (TASK_MASKED_COUNTER_ACTIVE(tmp)) goto find_place;
next_request:
    reg_a0 += sizeof(Task);
    g_task_start_requests_used -= sizeof(Task);
    if (g_task_start_requests_used != 0) goto serve_request;
no_requests:
    return;
}


void task_start(void) {
    u32 save_d1;
    u32 save_d2;
    s32 t1;

    save_d2 = reg_d2.w;
    reg_d2.h[0] = g_task_start_requests_used;
    save_d1 = reg_d1.w;
    if ((s16) reg_d2.h[0] < (s32) TASK_BLOCKS_SIZE) {
        reg_d1.h[0] = reg_d0.h[0];
#ifdef DDPDOJ_PC
        if (reg_d1.h[0] >= TASK_TABLE_COUNT || !task_callbacks[reg_d1.h[0]]) {
            abort();
        }
#endif
        reg_a0 = (u8 *)g_task_table;
        reg_d1.h[0] *= 8;
        t1 = reg_d1.h[0] + 4;
        reg_d1.h[0] = (t1 != 0) ? *(u16 *)(reg_a0 + ((s16) t1 & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)g_task_start_requests;
        reg_a0 += reg_d2.h[0] & 0xFFFF;
        reg_d0.h[0] |= 0x8000;
        *(u16 *)(reg_a0 + 0) = reg_d0.h[0];
        *(s16 *)(reg_a0 + 2) = 0;
        TASK(reg_a0)->priority = reg_d1.h[0];
        g_task_start_requests_used += sizeof(Task);
        g_task_last_id += 1;
        reg_d0.w = g_task_last_id;
        TASK(reg_a0)->id[0] = reg_d0.h[1];
        TASK(reg_a0)->id[1] = reg_d0.h[0];
        reg_d1.w = save_d1;
        reg_d2.w = save_d2;
        return;
    }
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d0.w = 0;
    reg_a0 = (u8 *)g_task_dummy;
}


void task_remove(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 tmp;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    if (save_d0 == 0) goto done;
    reg_a0 = (u8 *)g_tasks;
    reg_d2.w = TASK_COUNT - 1;
compare_task:
    if (*(u16 *)reg_a0 == 0) goto try_next_task;
    reg_d1.h[1] = TASK(reg_a0)->id[0];
    reg_d1.h[0] = TASK(reg_a0)->id[1];
    if (save_d0 != reg_d1.w) goto try_next_task;
    reg_a2 = reg_a0;
    reg_a3 = reg_a0 + sizeof(Task);
#ifdef DDPDOJ_PC
    reg_d3.w = (u32)(g_tasks + TASK_BLOCKS_SIZE - reg_a3);
    memmove(reg_a2, reg_a3, reg_d3.w);
#else
    reg_d4.w = (u32) reg_a3;
    reg_d3.w = (u32) g_task_stop_requests;
    reg_d3.w -= reg_d4.w;
    task_blocks_copy_forward();
#endif
    reg_a2 += reg_d3.h[0];
    TASK(reg_a2)->state = 0;
    TASK(reg_a2)->priority = 0;
    TASK(reg_a2)->id[0] = 0;
    TASK(reg_a2)->id[1] = 0;
    goto done;
try_next_task:
    reg_a0 += sizeof(Task);
    tmp = reg_d2.h[0] - 1;
    reg_d2.h[0] = tmp;
    if (TASK_MASKED_COUNTER_ACTIVE(tmp)) goto compare_task;
done:
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
}


void task_request_stop(void) {
    u8 *a1;
    u8 *a0;
    s32 d1;
    s32 d2;

    d1 = reg_d1.w;
    a0 = reg_a0;
    a1 = reg_a1;
    d2 = reg_d2.w;
    reg_d2.h[0] = g_task_stop_requests_used;
    if ((s16) reg_d2.h[0] < (s32) TASK_BLOCKS_SIZE) {
        reg_a1 = (u8 *)g_task_stop_requests;
        reg_a1 += reg_d2.h[0] & 0xFFFF;
        *(u16 *) (reg_a1 + 0) = *(u16 *) (reg_a0 + 0);
        *(u16 *) (reg_a1 + 2) = *(u16 *) (reg_a0 + 2);
        g_task_stop_requests_used += sizeof(Task);
    }
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
    reg_a1 = a1;
}


void task_serve_stop_requests(void) {
    if (g_task_stop_requests_used == 0) return;
serve_request:
    g_task_stop_requests_used -= sizeof(Task);
    reg_a1 = (u8 *)g_task_stop_requests;
    reg_d2.h[0] = g_task_stop_requests_used;
    reg_d0.h[1] = (reg_d2.h[0]) ? *(u16 *)(reg_a1 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d0.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)(reg_a1 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    task_remove();
    if (g_task_stop_requests_used != 0) goto serve_request;
}


void task_stop_self(void) {
    reg_a0 = (u8 *)TASK(reg_a5)->id;
    task_request_stop();
}


void task_find(void) {
    s32 d0;
    s32 d1;
    s32 d2;
    u32 tmp;

    d1 = reg_d1.w;
    d0 = reg_d0.w;
    d2 = reg_d2.w;
    reg_a0 = (u8 *)g_tasks;
    reg_d1.w = TASK_COUNT - 1;
compare_task:
    reg_d2.h[1] = TASK(reg_a0)->id[0];
    reg_d2.h[0] = TASK(reg_a0)->id[1];
    if (reg_d2.w == 0) goto try_next_task;
    if (reg_d2.w != reg_d0.w) goto try_next_task;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    cond_flag = 0;
    return;
try_next_task:
    reg_a0 += sizeof(Task);
    tmp = reg_d1.h[0] - 1;
    reg_d1.h[0] = tmp;
    if (TASK_COUNTER_ACTIVE(tmp)) goto compare_task;
    reg_a0 = (u8 *)g_task_dummy;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    cond_flag = 1;
}

u16 g_task_table[88] = {
    0x0000, 0x0000, 0x0009, 0x0000, 0x0000, 0x0000, 0x001A, 0x0000,
    0x0000, 0x0000, 0x001C, 0x0000, 0x0000, 0x0000, 0x001B, 0x0000,
    0x0000, 0x0000, 0x0009, 0x0000, 0x0000, 0x0000, 0x0018, 0x0000,
    0x0000, 0x0000, 0x000A, 0x0000, 0x0000, 0x0000, 0x001E, 0x0000,
    0x0000, 0x0000, 0x000A, 0x0000, 0x0000, 0x0000, 0x000A, 0x0000,
    0x0000, 0x0000, 0x001F, 0x0000, 0x0000, 0x0000, 0x000A, 0x0000,
    0x0000, 0x0000, 0x0009, 0x0000, 0x0000, 0x0000, 0x000B, 0x0000,
    0x0000, 0x0000, 0x0014, 0x0000, 0x0000, 0x0000, 0x001E, 0x0000,
    0x0000, 0x0000, 0x001E, 0x0000, 0x0000, 0x0000, 0x000A, 0x0000,
    0x0000, 0x0000, 0x000A, 0x0000, 0x0000, 0x0000, 0x001E, 0x0000,
    0x0000, 0x0000, 0x0008, 0x0000, 0x0000, 0x0000, 0x0008, 0x0000,
};

/* .bss (the compiler lays these out in reverse) */
#ifndef DDPDOJ_PC
u8 g_task_dummy[80];
u8 D_002A1500[624];
u8 g_task_start_requests[976];
u8 g_task_stop_requests[1600];
u8 g_tasks[1600];
#endif
