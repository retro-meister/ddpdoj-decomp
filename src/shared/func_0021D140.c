#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"
#pragma global_optimizer off

typedef struct {
    unsigned __int128 q;
} GifTag;

extern void sceGifPkOpenGifTag(sceGifPacket *packet, unsigned __int128 tag);
extern void sceGifPkCloseGifTag(sceGifPacket *packet);
extern void sceGifPkAddGsAD(sceGifPacket *packet, s32 addr, u64 data);
extern GifTag D_00270800[];
extern void *D_0028E9F4;
extern u8 *D_0028EA98;
extern u8 D_00558780[];
extern sceGsLoadImage D_0057C780;

void func_0021D140(u16 alpha) {
    GifTag tag;
    sceGifPacket packet;
    u8 *buf;
    s32 c;
    u64 prim;

    tag = D_00270800[0];
    buf = D_00558780;
    sceGsSetDefLoadImage(&D_0057C780, 0x2240, 8, 0x13, 0, 0, 320, 208);
    FlushCache(0);
    sceGsExecLoadImage(&D_0057C780, D_0028EA98 + 0x200);
    sceGsSyncPath(0, 0);
    sceGifPkInit(&packet, buf);
    sceGifPkReset(&packet);
    sceGifPkOpenGifTag(&packet, tag.q);
    sceGifPkAddGsAD(&packet, 8, 0);
    sceGifPkAddGsAD(&packet, 20, 0);
    sceGifPkAddGsAD(&packet, 71, 0x3000F);
    sceGifPkAddGsAD(&packet, 59, (u64)128 << 32);
    sceGifPkAddGsAD(&packet, 66, 68);
    sceGifPkAddGsAD(&packet, 63, 0);
    sceGifPkCloseGifTag(&packet);
    sceGifPkOpenGifTag(&packet, tag.q);
    prim = 0x65322240 | ((u64)0x20170686 << 32);
    sceGifPkAddGsAD(&packet, 6, prim);
    sceGifPkAddGsAD(&packet, 0, 70);
    sceGifPkAddGsAD(&packet, 1, (s64)(alpha / 2) << 24);
    sceGifPkAddGsAD(&packet, 4, 0x79087008);
    sceGifPkAddGsAD(&packet, 4, 0x87088C08);
    sceGifPkCloseGifTag(&packet);
    c = 0x80;
    sceGifPkOpenGifTag(&packet, tag.q);
    sceGifPkAddGsAD(&packet, 6, 0x65322240 | ((u64)0x20170686 << 32));
    sceGifPkAddGsAD(&packet, 0, 342);
    sceGifPkAddGsAD(&packet, 1, (s64)c | ((s64)c << 8) | (0x80 << 16) | ((u64)alpha << 24));
    sceGifPkAddGsAD(&packet, 3, 0);
    sceGifPkAddGsAD(&packet, 4, 0x79887408);
    sceGifPkAddGsAD(&packet, 3, 0x0D001400);
    sceGifPkAddGsAD(&packet, 4, 0x86888808);
    sceGifPkCloseGifTag(&packet);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(D_0028E9F4, buf, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
