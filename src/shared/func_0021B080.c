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
} TexDesc;

extern void *D_0028E9F4;
extern s32 D_0028DC98;
extern s32 D_0028E9F0;
extern s32 D_0028EA50;
extern s32 D_0028EA54;
extern u8 D_0057C7E0[];

void func_0021B080(TexDesc *tex, void *buffer) {
    sceGifPacket packet;
    s32 index;
    s32 x;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(7, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    if (D_0028DC98 == 4) {
        sceGifPkAddGsData(&packet, 0);
    } else {
        sceGifPkAddGsData(&packet, 0x60);
    }
    sceGifPkAddGsData(&packet, 0x14);
    sceGifPkAddGsData(&packet, 0x3000E);
    sceGifPkAddGsData(&packet, 0x47);
    sceGifPkAddGsData(&packet, 0);
    sceGifPkAddGsData(&packet, 0x3F);
    index = (D_0028E9F0 + 1) & 1;
    sceGifPkAddGsData(&packet, ((u64)*(u16 *)(D_0057C7E0 + index * 40 + 0x10) & 0x1FF) | ((u64)((D_0028EA54 + 63) >> 6) << 16) | ((u64)2 << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, ((0x800 - (u64)(D_0028EA54 >> 1)) << 4) | ((u64)0x7900 << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, ((u64)(D_0028EA50 + 0x1BF) << 16) | 1 | ((u64)1 << 32) | ((u64)0xDF << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkAddGsData(&packet, (u64)tex->tbp | ((u64)(tex->width >> 6) << 14) | ((u64)tex->psm << 20) | ((u64)tex->tw << 26) | ((u64)tex->th << 30) | ((u64)1 << 34));
    sceGifPkAddGsData(&packet, 6);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 10));
    sceGifPkAddGsData(&packet, 0x5353535310ULL);
    sceGifPkAddGsData(&packet, 0x115);
    sceGifPkAddGsData(&packet, 0x80808080ULL | ((u64)0x3F800000 << 32));
    x = ((0x800 - D_0028EA54 / 2) << 4) + 8;
    x += (D_0028EA50 + 0x1B0) << 4;
    sceGifPkAddGsData(&packet, 0x1101C10);
    sceGifPkAddGsData(&packet, (u64)x | 0x79080000);
    sceGifPkAddGsData(&packet, 0xF101C10);
    sceGifPkAddGsData(&packet, (u64)x | 0x87080000);
    sceGifPkAddGsData(&packet, 0xF100010);
    x -= 0x1A00;
    sceGifPkAddGsData(&packet, (u64)x | 0x87080000);
    sceGifPkAddGsData(&packet, 0x1100010);
    sceGifPkAddGsData(&packet, (u64)x | 0x79080000);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(D_0028E9F4, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
