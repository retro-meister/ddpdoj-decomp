/* Global variables of the wreck unit. They lie in a block apart from the unit's own, and one object file can
   place only one block of a section in our link, so they are defined here. */
#include "common.h"

/* .bss (the compiler lays these out in reverse) */
u8 D_002BAE90[32];
