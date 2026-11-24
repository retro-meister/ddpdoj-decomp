#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern void *g_dma_gif;

void func_002252E0(void *buffer) {
    sceGifPacket packet;
    s32 i;
    u64 x;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 0, 1, 0x101, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, 0x80808080ULL | ((u64)0x3F800000 << 32));
    sceGifPkAddGsData(&packet, 1);
    sceGifPkAddGsData(&packet, 0x801CULL | ((u64)0x24000000 << 32));
    sceGifPkAddGsData(&packet, 0x55);
    for (i = 0; i < 0x1C0; i += 0x20) {
        x = (i + 0x700) << 4;
        sceGifPkAddGsData(&packet, x | 0x79000000);
        sceGifPkAddGsData(&packet, x | 0x87000000ULL);
    }
    for (i = 0; i < 0xE0; i += 0x10) {
        x = (u64)((i + 0x790) << 4) << 16;
        sceGifPkAddGsData(&packet, x | 0x7000);
        sceGifPkAddGsData(&packet, x | 0x8C00);
    }
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
