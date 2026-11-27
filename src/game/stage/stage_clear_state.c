/* Global variables of the stage clear unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"

/* .sbss (the compiler lays these out in reverse) */
u16 D_0028E960 __attribute__((aligned(4)));
u16 D_0028E95C __attribute__((aligned(4)));
s16 D_0028E958 __attribute__((aligned(4)));
u16 D_0028E954 __attribute__((aligned(4)));
u16 D_0028E950 __attribute__((aligned(4)));
s16 stage_clear_state_clear_state __attribute__((aligned(4)));
s16 g_game_task_handle __attribute__((aligned(4)));

/* .bss (the compiler lays these out in reverse) */
u8 D_002BF490[96];
u8 D_002BF450[64];
u8 D_002BF410[64];
#ifndef DDPDOJ_PC
u16 D_002BF400[8];
#endif

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(D_0028E961, D_0028E960, 1);
#endif

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

const PcFrameRegion pc_stage_clear_regions[] = {
    PC_FRAME_REGION(D_0028E960),
    PC_FRAME_REGION(D_0028E95C),
    PC_FRAME_REGION(D_0028E958),
    PC_FRAME_REGION(D_0028E954),
    PC_FRAME_REGION(D_0028E950),
    PC_FRAME_REGION(stage_clear_state_clear_state),
    PC_FRAME_REGION(g_game_task_handle),
    PC_FRAME_REGION(D_002BF490),
    PC_FRAME_REGION(D_002BF450),
    PC_FRAME_REGION(D_002BF410),
    { NULL, 0 },
};
#endif
