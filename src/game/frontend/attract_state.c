/* Global variables of the attract unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"

/* .sbss (the compiler lays these out in reverse) */
u16 g_attract_step __attribute__((aligned(4)));
u16 D_0028E7B8 __attribute__((aligned(4)));
u8 D_0028E7B4 __attribute__((aligned(4)));

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

const PcFrameRegion pc_attract_regions[] = {
    PC_FRAME_REGION(g_attract_step),
    PC_FRAME_REGION(D_0028E7B8),
    PC_FRAME_REGION(D_0028E7B4),
    { NULL, 0 },
};
#endif
