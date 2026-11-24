#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

typedef struct {
    u16 tbp;
    u16 psm;
    u32 width;
    u32 height;
    u16 tw;
    u16 th;
} TexInfo;

extern void *g_dma_gif;

void func_0021A920(TexInfo *tex, void *buffer) {
    sceGifPacket packet;
    s32 x;
    s32 y;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(6, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, (u64)(tex->tbp >> 5) | ((u64)((tex->width + 63) >> 6) << 16) | ((u64)tex->psm << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, (u64)((0x800 - (tex->width >> 1)) << 4) | ((u64)((0x800 - (tex->height >> 1)) << 4) << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, ((u64)(tex->width - 1) << 16) | ((u64)(tex->height - 1) << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkAddGsData(&packet, 0x3000F);
    sceGifPkAddGsData(&packet, 0x47);
    sceGifPkAddGsData(&packet, (u64)1 << 32);
    sceGifPkAddGsData(&packet, 0x4E);
    sceGifPkAddGsData(&packet, 0);
    sceGifPkAddGsData(&packet, 0x14);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 4));
    sceGifPkAddGsData(&packet, 0x5510);
    sceGifPkAddGsData(&packet, 0x106);
    sceGifPkAddGsData(&packet, ((u64)0x80 << 24) | ((u64)0x3F800000 << 32));
    x = (0x800 - (tex->width >> 1)) << 4;
    y = (0x800 - (tex->height >> 1)) << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)y << 16));
    x += tex->width << 4;
    y += tex->height << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)y << 16));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
