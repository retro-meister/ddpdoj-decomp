#include "common.h"

extern u64 func_00212E50(void);

u64 func_00212F30(void)
{
    u64 packed = func_00212E50();
    u64 upper = (packed >> 8) - 0x21;
    u64 scaled = upper * 0x5E;
    u64 lower = (packed & 0xFF) - 0x21;

    return scaled + lower;
}
