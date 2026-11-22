#include "common.h"

extern u8 D_00684CF0[];

void func_0021D500(void)
{
    s32 groupIndex = 0;
    s32 groupOffset = 0;

    do {
        s32 entryIndex = 0;
        s32 entryOffset = 0;
        u32 groupAddress = (u32)D_00684CF0 + groupOffset;

        do {
            s32 offset = entryOffset;
            u32 entryAddress = offset + groupAddress;
            u32 firstWordAddress = entryAddress;

            entryIndex++;
            *(s32 *)firstWordAddress = 0;
            entryOffset = offset + 0x14;
            *(s32 *)(entryAddress + 0x04) = 0;
            *(s32 *)(entryAddress + 0x08) = 0;
            *(s32 *)(entryAddress + 0x0C) = 0;
            *(s32 *)(entryAddress + 0x10) = 0;
        } while (entryIndex < 4);

        groupIndex++;
        groupOffset += 0x50;
    } while (groupIndex < 10);
}
