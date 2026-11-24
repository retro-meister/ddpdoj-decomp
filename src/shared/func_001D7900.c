#include "common.h"

extern void *reg_a6_as_void_p;

void func_001D7900(void)
{
    s16 *frameCounter;

    --*(u16 *)((u8 *)reg_a6_as_void_p + 0xE6);

    frameCounter = (s16 *)((u8 *)reg_a6_as_void_p + 0xE6);
    if (0 > *frameCounter) {
        *frameCounter = 0x17;
    }
}
