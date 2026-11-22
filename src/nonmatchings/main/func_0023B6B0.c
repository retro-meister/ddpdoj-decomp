#include "common.h"

extern s8 D_002B4D50[];

void func_0023B6B0(const s8 *source)
{
    s32 offset = 0;

    do {
        const s8 *sourceBlock = source + offset;
        s8 *destinationBlock = D_002B4D50 + offset;
        s8 firstByte = sourceBlock[0x3511];

        offset += 8;
        destinationBlock[0] = firstByte;
        destinationBlock[1] = sourceBlock[0x3512];
        destinationBlock[2] = sourceBlock[0x3513];
        destinationBlock[3] = sourceBlock[0x3514];
        destinationBlock[4] = sourceBlock[0x3515];
        destinationBlock[5] = sourceBlock[0x3516];
        destinationBlock[6] = sourceBlock[0x3517];
        destinationBlock[7] = sourceBlock[0x3518];
    } while (offset < 0x2000);
}
