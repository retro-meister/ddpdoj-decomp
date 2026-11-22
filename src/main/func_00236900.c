#include "common.h"

extern u8 D_006A0E50[];

void func_00236900(void)
{
    u8 *buffer;
    u8 *cursor;
    s32 blockIndex;
    s32 bytesCleared;
    s32 blockOffset;

    blockIndex = 0;
    blockOffset = 0;

    do {
        buffer = D_006A0E50;
        cursor = buffer + blockOffset;
        bytesCleared = 0;

        do {
            cursor[0] = 0;
            cursor[1] = 0;
            bytesCleared += 8;
            cursor[2] = 0;
            cursor[3] = 0;
            cursor[4] = 0;
            cursor[5] = 0;
            cursor[6] = 0;
            cursor[7] = 0;
            cursor += 8;
        } while (bytesCleared < 0x400);

        blockIndex += 1;
        blockOffset += 0x400;
    } while (blockIndex < 12);
}
