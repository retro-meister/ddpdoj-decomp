/* Desktop translation unit. The PS2 build includes these routines in text.c. */
#include "game_cd_io.inc.h"

#include "pc_frame_regions.h"

const PcFrameRegion pc_cd_regions[] = {
    PC_FRAME_REGION(g_cd_last_read_size),
    PC_FRAME_REGION(g_cd_retry_timer),
    PC_FRAME_REGION(g_cd_total_bytes_read),
    PC_FRAME_REGION(g_cd_async_busy),
    PC_FRAME_REGION(g_cd_async_state),
    PC_FRAME_REGION(g_cd_file),
    { NULL, 0 },
};
