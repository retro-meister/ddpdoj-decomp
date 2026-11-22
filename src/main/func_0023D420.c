#include "common.h"

extern u8 D_002B4D50[];
extern void func_0023CDA0(s32 entryAddress, u8 *buffer, s32 size, s32 mode);

#pragma opt_common_subs off

void func_0023D420(s32 baseAddress)
{
    s32 entryOffset = 0;

    do {
        func_0023CDA0(entryOffset + baseAddress + 0x1EE, D_002B4D50, 0x800, 4);
        func_0023CDA0(entryOffset + baseAddress + 0x248, D_002B4D50, 0x800, 4);
        entryOffset += 0xA;
    } while (entryOffset < 0x5A);
}
