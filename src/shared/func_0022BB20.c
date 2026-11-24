#include "common.h"

s32 func_0022BB20(const u8 *data)
{
    s32 checksum = 0;
    s32 offset = 0;
    const u8 *block;

    do {
        block = data + offset;
        offset += 8;
        checksum += block[0] + block[1] + block[2] + block[3]
                  + block[4] + block[5] + block[6] + block[7];
    } while (offset < 0x5530);

    return checksum;
}
