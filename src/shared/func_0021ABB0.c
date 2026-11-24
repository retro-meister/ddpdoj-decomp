#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern void *g_dma_gif;
extern s32 D_0028DC98;
extern s32 g_frame_counter;
extern s32 D_0028EA54;
extern u8 g_gs_dbuff[];

void func_0021ABB0(void *buffer) {
    sceGifPacket packet;
    s32 index;
    s32 x;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(6, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    index = (g_frame_counter + 1) & 1;
    sceGifPkAddGsData(&packet, ((u64)*(u16 *)(g_gs_dbuff + index * 40 + 0x10) & 0x1FF) | ((u64)((D_0028EA54 + 63) >> 6) << 16) | ((u64)2 << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, ((0x800 - (u64)(D_0028EA54 >> 1)) << 4) | ((u64)0x7200 << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, ((u64)(D_0028EA54 - 1) << 16) | ((u64)0x1BF << 48));
    sceGifPkAddGsData(&packet, 0x40);
    if (D_0028DC98 == 2) {
        sceGifPkAddGsData(&packet, 0);
    } else {
        sceGifPkAddGsData(&packet, 0x60);
    }
    sceGifPkAddGsData(&packet, 0x14);
    sceGifPkAddGsData(&packet, 0x3000E);
    sceGifPkAddGsData(&packet, 0x47);
    sceGifPkAddGsData(&packet, 0);
    sceGifPkAddGsData(&packet, 0x3F);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 4));
    sceGifPkAddGsData(&packet, 0x5510);
    sceGifPkAddGsData(&packet, 0x106);
    sceGifPkAddGsData(&packet, 0x80000000ULL | ((u64)0x3F800000 << 32));
    x = (0x800 - (D_0028EA54 >> 1)) << 4;
    sceGifPkAddGsData(&packet, (u64)x | 0x72000000);
    x += D_0028EA54 << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)0x8E00 << 16));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
