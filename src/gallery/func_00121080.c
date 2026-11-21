#include "common.h"

typedef struct {
    u8 padding0[0x505148];
    s32 state;
    s32 initialized;
    u8 padding1[8];
    s32 frameCount;
    u8 padding2[0x10];
    u16 transitionComplete;
} GalleryState;

extern GalleryState *D_0012B3D8;

s32 func_00121080(void)
{
    if (D_0012B3D8->initialized == 0) {
        D_0012B3D8->transitionComplete = 0;
        D_0012B3D8->frameCount = 0;
        D_0012B3D8->initialized++;
    }

    if (++D_0012B3D8->frameCount < 32) {
        return 0;
    }

    D_0012B3D8->transitionComplete = 1;
    D_0012B3D8->state = 2;
    D_0012B3D8->initialized = 0;
    return 0;
}
