#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern void *D_0028E9F4;
extern s32 D_0028E9F0;
extern s32 D_0028EA50;
extern s32 D_0028EA54;
extern u8 D_0057C7E0[];

void func_0021B400(void *buffer) {
    sceGifPacket packet;
    s32 index;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(3, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    index = (D_0028E9F0 + 1) & 1;
    sceGifPkAddGsData(&packet, ((u64)*(u16 *)(D_0057C7E0 + index * 40 + 0x10) & 0x1FF) | ((u64)((D_0028EA54 + 63) >> 6) << 16) | ((u64)2 << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, ((0x700 - (u64)D_0028EA50) << 4) | ((u64)0x7900 << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, (u64)(D_0028EA50 + 1) | ((u64)(D_0028EA50 + 0x1BF) << 16) | ((u64)1 << 32) | ((u64)0xDF << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(D_0028E9F4, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
