/* The screen mode; owner assumed. */
#include "common.h"

u16 g_screen_mode[2] = {
    0x0003, 0x0000,
};

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

const PcFrameRegion pc_screen_mode_regions[] = {
    PC_FRAME_REGION(g_screen_mode),
    { NULL, 0 },
};
#endif
