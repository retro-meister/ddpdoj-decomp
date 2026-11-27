/* Global variables of the stage clear unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"
#include "stage_tally.h"

/* .sbss (the compiler lays these out in reverse) */
u16 D_0028E960 __attribute__((aligned(4)));
u16 D_0028E95C __attribute__((aligned(4)));
s16 D_0028E958 __attribute__((aligned(4)));
u16 D_0028E954 __attribute__((aligned(4)));
u16 D_0028E950 __attribute__((aligned(4)));
s16 stage_clear_state_clear_state __attribute__((aligned(4)));
s16 g_game_task_handle __attribute__((aligned(4)));

/* .bss (the compiler lays these out in reverse) */
StageClearStorage g_stage_clear;
#ifndef DDPDOJ_PC
u16 D_002BF400[8];
#endif

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"
PC_DATA_ALIAS(D_0028E961, D_0028E960, 1);
#endif

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

_Static_assert(sizeof(StageStarTally) == 10, "player star tally stride");
_Static_assert(offsetof(StageTally, players) == 0x18, "star tally offset");
_Static_assert(offsetof(StageTally, panel_position) == 0x40, "panel positions offset");
_Static_assert(sizeof(StageTally) == 0x60, "stage tally size");
_Static_assert(offsetof(StageClearStorage, original) == 0x40, "original colors offset");
_Static_assert(offsetof(StageClearStorage, display) == 0x80, "stage tally offset");
_Static_assert(sizeof(StageClearStorage) == 0xe0, "stage clear storage size");

const PcFrameRegion pc_stage_clear_regions[] = {
    PC_FRAME_REGION(D_0028E960),
    PC_FRAME_REGION(D_0028E95C),
    PC_FRAME_REGION(D_0028E958),
    PC_FRAME_REGION(D_0028E954),
    PC_FRAME_REGION(D_0028E950),
    PC_FRAME_REGION(stage_clear_state_clear_state),
    PC_FRAME_REGION(g_game_task_handle),
    PC_FRAME_REGION(g_stage_clear.display),
    PC_FRAME_REGION(g_stage_clear.original),
    PC_FRAME_REGION(g_stage_clear.dimmed),
    { NULL, 0 },
};
#endif
