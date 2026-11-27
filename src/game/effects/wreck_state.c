/* Global variables of the wreck unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"

/* .bss (the compiler lays these out in reverse) */
u8 D_002BAE90[32];

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

#ifdef DDPDOJ_BONUS_FEATURES
extern u16 g_loop2_starting_lives[2];
#endif
#ifdef DEATH_LABEL
extern u8 death_D_00290568;
#endif

const PcFrameRegion pc_wreck_regions[] = {
#ifdef DDPDOJ_BONUS_FEATURES
    PC_FRAME_REGION(g_loop2_starting_lives),
#endif
#ifdef DEATH_LABEL
    PC_FRAME_REGION(death_D_00290568),
#endif
    PC_FRAME_REGION(D_002BAE90),
    { NULL, 0 },
};
#endif
