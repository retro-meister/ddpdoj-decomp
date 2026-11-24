#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern s32 D_0028EA80;
extern void *D_0028E9F4;
extern u8 D_00558780[2][0x10000];
void func_0021A240(Qword *packet, s32 firstEntry, s32 count);

void func_0021A170(void)
{
    u8 *packet;
    s32 bufferIndex;
    s32 firstEntry;
    s32 batchCount;
    s32 remainingEntries;

    if (D_0028EA80 == 0) {
        return;
    }
    bufferIndex = 0;
    firstEntry = 0;
    while ((remainingEntries = D_0028EA80) != 0) {
        if (remainingEntries >= 6) {
            batchCount = 6;
        } else {
            batchCount = remainingEntries;
        }

        packet = D_00558780[bufferIndex];
        func_0021A240((Qword *)packet, firstEntry, batchCount);
        sceGsSyncPath(0, 0);
        FlushCache(0);
        sceDmaSend(D_0028E9F4, packet);

        bufferIndex ^= 1;
        firstEntry += batchCount;
        D_0028EA80 -= batchCount;
    }
    sceGsSyncPath(0, 0);
}
