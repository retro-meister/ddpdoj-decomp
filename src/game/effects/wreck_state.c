/* Global variables of the wreck unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"

/* .bss (the compiler lays these out in reverse) */
u8 D_002BAE90[32];

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

const PcFrameRegion pc_wreck_regions[] = {
    PC_FRAME_REGION(D_002BAE90),
    { NULL, 0 },
};
#endif
