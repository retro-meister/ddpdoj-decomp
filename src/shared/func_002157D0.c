#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern s32 D_0028E9D0;
extern void *D_0028E9F4;
extern u8 D_00558780[2][0x10000];
void font_build_gs_setup_packet(u8 *packet);
void func_002158C0(Qword *packet, s32 firstEntry, s32 count);

void func_002157D0(void)
{
    u8 *packet;
    s32 firstEntry;
    s32 batchCount;
    s32 bufferIndex;
    s32 remainingEntries;

    if (D_0028E9D0 == 0) {
        return;
    }
    font_build_gs_setup_packet(D_00558780[0]);
    FlushCache(0);
    sceDmaSend(D_0028E9F4, D_00558780[0]);
    sceGsSyncPath(0, 0);

    bufferIndex = 0;
    firstEntry = 0;
    while ((remainingEntries = D_0028E9D0) != 0) {
        if (remainingEntries >= 6) {
            batchCount = 6;
        } else {
            batchCount = remainingEntries;
        }

        packet = D_00558780[bufferIndex];
        func_002158C0((Qword *)packet, firstEntry, batchCount);
        sceGsSyncPath(0, 0);
        FlushCache(0);
        sceDmaSend(D_0028E9F4, packet);

        bufferIndex ^= 1;
        firstEntry += batchCount;
        D_0028E9D0 -= batchCount;
    }
}
