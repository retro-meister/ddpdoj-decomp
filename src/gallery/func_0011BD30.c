#include "common.h"

extern s32 D_0012B308;
extern void *D_0012B318;
extern u8 D_00180A80[];

extern void func_00100E08(s32 mode, s32 flags);
extern void func_00101F48(void *dmaChannel, void *packet);
extern void func_00103220(s32 mode);
extern void func_0011B930(void *packet, s32 firstEntry, s32 entryCount);
extern void func_0011C7E0(void *packet);

void func_0011BD30(void)
{
    s32 firstEntry;
    s32 remainingEntries;
    s32 batchCount;
    s32 bufferIndex;
    u8 *packet;

    if (D_0012B308 != 0) {
        func_0011C7E0(D_00180A80);
        func_00103220(0);
        func_00101F48(D_0012B318, D_00180A80);
        func_00100E08(0, 0);

        bufferIndex = 0;
        firstEntry = 0;
        while ((remainingEntries = D_0012B308) != 0) {
            if (remainingEntries >= 6) {
                batchCount = 6;
            } else {
                batchCount = remainingEntries;
            }

            packet = D_00180A80 + (bufferIndex << 16);
            func_0011B930(packet, firstEntry, batchCount);
            func_00100E08(0, 0);
            func_00103220(0);
            func_00101F48(D_0012B318, packet);

            D_0012B308 -= batchCount;
            firstEntry += batchCount;
            bufferIndex ^= 1;
        }
    }
}
