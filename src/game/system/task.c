#include "common.h"
#include "task.h"

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

extern u8 g_tasks[];
extern u8 g_task_stop_requests[];
extern u8 g_task_start_requests[];
extern u8 g_task_dummy[];   /* what a failed start or search returns, so that the caller's stores land somewhere */
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

typedef void (*Fn)();

extern u32 reg_call_target_as_u32;

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
            reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp.h[0] = (((reg_d1.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d1.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_call_target_as_u32 = reg_tmp.w;
            ((Fn)reg_call_target_as_u32)();
            reg_d0.w = remaining;
            reg_a5 = (u8 *)(task);
        }
        reg_a5 += sizeof(Task);
    } while ((s16)(--reg_d0.h[0]) >= 0);
}


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
    reg_d4.w = (u32) reg_a2;
    reg_d3.w = (u32) g_task_stop_requests;
    reg_d3.w -= reg_d4.w;
    task_blocks_copy_backward();
    reg_a2 = reg_a0;
    reg_d2.h[0] = 0x27;
copy_word:
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    tmp = reg_d2.h[0] - 1;
    reg_d2.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto copy_word;
    goto next_request;
try_next_task:
    reg_a1 += sizeof(Task);
    tmp = reg_d6.h[0] - 1;
    reg_d6.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto find_place;
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
    reg_d4.w = (u32) reg_a3;
    reg_d3.w = (u32) g_task_stop_requests;
    reg_d3.w -= reg_d4.w;
    task_blocks_copy_forward();
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
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto compare_task;
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
    reg_a0 = (u8 *)(((s32)reg_a5) + 0x4C);
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
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto compare_task;
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
u8 g_task_dummy[80];
u8 D_002A1500[624];
u8 g_task_start_requests[976];
u8 g_task_stop_requests[1600];
u8 g_tasks[1600];
