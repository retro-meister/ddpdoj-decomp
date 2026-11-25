#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"
void func_0014CAE0(void);
extern u16 g_side_scroll_step[];

s32 func_001A5A80();
s32 func_001AEA80();
s32 task_stop_self();
extern u8 g_game_frame_ran;
extern s16 g_score_task_active_as_s16;
extern u16 g_stage;
extern u8 g_replay_mode;

void score_task(void) {
    switch (reg_a5[3]) {
    case 0:
        goto block_1;
    }
    if (reg_a5[3] == 2) goto block_2;
    func_001AEA80();
    if (g_replay_mode != 2) goto next_1;
    if (g_stage != 0) goto next_1;
    if (g_game_frame_ran == 0) return;
next_1:
    func_001A5A80();
    return;
block_1:
    reg_a5[3] = 1;
    g_score_task_active_as_s16 = 1;
    return;
block_2:
    g_score_task_active_as_s16 = 0;
    task_stop_self();
}
