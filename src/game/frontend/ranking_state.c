/* Global variables of the ranking unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"

/* .sbss (the compiler lays these out in reverse) */
u16 D_0028E778 __attribute__((aligned(4)));
s16 D_0028E774;
u32 D_0028E770;
u16 D_0028E76C __attribute__((aligned(4)));
