/* Global variables of the enemy common unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"

/* .sbss (the compiler lays these out in reverse) */
s16 settings_notice_begin_state __attribute__((aligned(4)));
u16 g_settings_notice_shown __attribute__((aligned(4)));
u16 g_settings_notice_loaded __attribute__((aligned(4)));
s16 g_settings_notice_time;
u32 g_settings_notice_fade;

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(g_settings_notice_fade_flags, settings_notice_begin_state, 0x1);
#endif

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

const PcFrameRegion pc_notice_regions[] = {
    PC_FRAME_REGION(settings_notice_begin_state),
    PC_FRAME_REGION(g_settings_notice_shown),
    PC_FRAME_REGION(g_settings_notice_loaded),
    PC_FRAME_REGION(g_settings_notice_time),
    PC_FRAME_REGION(g_settings_notice_fade),
    { NULL, 0 },
};
#endif
