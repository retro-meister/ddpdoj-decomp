#include "common.h"

typedef struct {
    u8 padding0[0x505144];
    s32 exitRequested;
    s32 state;
    s32 initialized;
    u8 padding1[8];
    s32 frameCount;
    u8 padding2[0x10];
    u16 transitionComplete;
} GalleryState;

extern GalleryState *D_0012B3D8;
extern u8 D_001C0B40[256];

s32 func_0011F630(void)
{
    s32 byteIndex;

    if (D_0012B3D8->initialized == 0) {
        for (byteIndex = 0; byteIndex < sizeof(D_001C0B40); byteIndex++) {
            D_001C0B40[byteIndex] = 0;
        }

        D_0012B3D8->transitionComplete = 9;
        D_0012B3D8->frameCount = 0;
        D_0012B3D8->initialized++;
    }

    if (D_0012B3D8->frameCount < 32) {
        D_0012B3D8->frameCount++;
        return 0;
    }

    D_0012B3D8->exitRequested = 1;
    return 0;
}
