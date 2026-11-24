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
extern s32 D_0028EA50;
extern s32 D_0028EA54;

void func_0021AE20(TexInfo *tex, void *buffer) {
    sceGifPacket packet;
    s32 x;
    s64 right;
    s64 left;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(2, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, ((u64)(D_0028EA54 - 1) << 16) | ((u64)0x1BE << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkAddGsData(&packet, SCE_GS_SET_TEX0(tex->tbp, tex->width >> 6, tex->psm, tex->tw, tex->th, 1, 0, 0, 0, 0, 0, 0));
    sceGifPkAddGsData(&packet, SCE_GS_TEX0_1);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 10));
    sceGifPkAddGsData(&packet, 0x5353535310ULL);
    sceGifPkAddGsData(&packet, 0x115);
    sceGifPkAddGsData(&packet, 0x80808080 | ((u64)0x3F800000 << 32));
    x = ((0x800 - D_0028EA54 / 2) << 4) + 8;
    x += D_0028EA50 << 4;
    sceGifPkAddGsData(&packet, 0x1101C00);
    left = x;
    sceGifPkAddGsData(&packet, left | 0x72000000);
    sceGifPkAddGsData(&packet, 0xF101C00);
    right = x + 0xE00;
    sceGifPkAddGsData(&packet, right | 0x72000000);
    sceGifPkAddGsData(&packet, 0xF100000);
    sceGifPkAddGsData(&packet, right | ((u64)0x8E00 << 16));
    sceGifPkAddGsData(&packet, 0x1100000);
    sceGifPkAddGsData(&packet, left | ((u64)0x8E00 << 16));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
