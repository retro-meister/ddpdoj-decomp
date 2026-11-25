/* Global variables of the pickup unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"

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
u8 D_002BF4F0[3080];
#else
u8 D_002BF4F0[3088];
#endif
