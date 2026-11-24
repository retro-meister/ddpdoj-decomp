#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern sceGsLoadImage g_gs_load_image;
void *malloc(u32 size);
void free(void *pointer);

void func_00217930(void)
{
    u32 *buffer;
    u32 wordIndex;
    s32 vramBase;
    u32 blockIndex;

    buffer = malloc(0x40000);
    for (wordIndex = 0; wordIndex < 0x10000; wordIndex++) {
        buffer[wordIndex] = 0;
    }

    for (blockIndex = 0, vramBase = 0; blockIndex < 0x10; blockIndex++, vramBase += 0x400) {
        sceGsSetDefLoadImage(&g_gs_load_image, (s16)vramBase, 4, 0, 0, 0, 0x100, 0x100);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, buffer);
        sceGsSyncPath(0, 0);
    }

    free(buffer);
}
