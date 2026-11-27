/* Global variables of the pickup unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"
#include "pickups.h"

#ifdef DDPDOJ_BONUS_FEATURES
u8 black_label_pickups[(PICKUP_COUNT + BEE_PICKUP_COUNT) * PICKUP_SIZE] __attribute__((aligned(4)));
#endif

/* .sbss (the compiler lays these out in reverse) */
u16 g_bullet_count __attribute__((aligned(4)));
u16 g_stage_bees_collected __attribute__((aligned(4)));
u16 g_bee_value_step __attribute__((aligned(4)));
u16 g_p1_stage_stars_large __attribute__((aligned(4)));
u16 g_p1_stage_stars_small __attribute__((aligned(4)));
u16 g_p2_stage_stars_large __attribute__((aligned(4)));
u16 g_p2_stage_stars_small __attribute__((aligned(4)));

/* .bss (the compiler lays these out in reverse) */
#ifdef DEATH_LABEL
u8 g_pickups[3080];
#else
u8 g_pickups[3088];
#endif

#ifdef DDPDOJ_PC
#include "pc_frame_regions.h"

const PcFrameRegion pc_pickups_regions[] = {
    PC_FRAME_REGION(g_pickups),
#ifdef DDPDOJ_BONUS_FEATURES
    PC_FRAME_REGION(black_label_pickups),
#endif
    { NULL, 0 },
};
#endif
