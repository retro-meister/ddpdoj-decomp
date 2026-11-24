#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern void *g_dma_gif;

void func_0021BD80(void *buffer, s32 x, s32 y, s32 w, s32 h) {
    sceGifPacket packet;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, (u64)x | ((u64)(x + w - 1) << 16) | ((u64)y << 32) | ((u64)(y + h - 1) << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
