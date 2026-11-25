/* Three small variables whose unit is not known. They follow the splash unit's run in the block of the units'
   global variables, which runs against the order of the code, so their unit lies before the splash unit. */
#include "common.h"

/* .sbss (the compiler lays these out in reverse) */
u32 D_0028E9A0;
s32 D_0028E99C;
s32 D_0028E998;
