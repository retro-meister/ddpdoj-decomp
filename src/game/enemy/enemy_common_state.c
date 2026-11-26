/* Global variables of the enemy common unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"

/* .sbss (the compiler lays these out in reverse) */
s16 D_0028E7D0 __attribute__((aligned(4)));
u16 g_settings_notice_shown __attribute__((aligned(4)));
u16 g_settings_notice_loaded __attribute__((aligned(4)));
s16 g_settings_notice_time;
u32 g_settings_notice_fade;
