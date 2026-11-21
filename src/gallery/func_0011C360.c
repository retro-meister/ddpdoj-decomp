#include "common.h"

extern s32 D_0012B308;
extern s32 D_0012B318;
extern u8 D_00180A80[2][0x10000];

extern void func_00100E08(s32, s32);
extern void func_00101F48(s32, void *);
extern void func_00103220(s32);
extern void func_0011C0C0(void *, s32, s32);
extern void func_0011C7E0(void *);

void func_0011C360(void)
{
    s32 entryOffset;
    s32 batchSize;
    s32 remainingEntries;
    s32 bufferIndex;
    u8 *buffer;

    if (D_0012B308 != 0) {
        func_0011C7E0(D_00180A80[0]);
        func_00103220(0);
        func_00101F48(D_0012B318, D_00180A80[0]);
        func_00100E08(0, 0);

        bufferIndex = 0;
        entryOffset = 0;
        while ((remainingEntries = D_0012B308) != 0) {
            if (remainingEntries >= 6) {
                batchSize = 6;
            } else {
                batchSize = remainingEntries;
            }

            buffer = D_00180A80[bufferIndex];
            func_0011C0C0(buffer, entryOffset, batchSize);
            func_00100E08(0, 0);
            func_00103220(0);
            func_00101F48(D_0012B318, buffer);

            entryOffset += batchSize;
            D_0012B308 -= batchSize;
            bufferIndex ^= 1;
        }
    }
}
