/* Global variables of the debug unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"

/* .sbss (the compiler lays these out in reverse) */
u16 g_game_flow_debug_value __attribute__((aligned(4)));
u16 D_0028E834 __attribute__((aligned(4)));
u16 D_0028E830 __attribute__((aligned(4)));
u16 D_0028E82C __attribute__((aligned(4)));
u16 D_0028E828 __attribute__((aligned(4)));
u16 D_0028E824 __attribute__((aligned(4)));
u16 D_0028E820 __attribute__((aligned(4)));
u16 D_0028E81C __attribute__((aligned(4)));
u16 D_0028E818 __attribute__((aligned(4)));
u16 D_0028E814 __attribute__((aligned(4)));
u16 D_0028E810 __attribute__((aligned(4)));
u16 D_0028E80C __attribute__((aligned(4)));
s16 D_0028E808 __attribute__((aligned(4)));
u16 D_0028E804 __attribute__((aligned(4)));
u16 D_0028E800;
u8 *D_0028E7FC;
u32 D_0028E7F8;

/* .bss (the compiler lays these out in reverse) */
s16 D_002BF370[16];
s16 D_002BF350[16];
