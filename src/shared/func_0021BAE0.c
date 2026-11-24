#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

typedef struct {
    s32 x;
    s32 y;
    s32 u;
    s32 v;
} Vertex;

extern Vertex D_0026FAA0[];
extern u8 D_0028E2DC;
extern void *D_0028E9F4;
extern s32 D_0028EA54;

void func_0021BAE0(void *buffer) {
    sceGifPacket packet;
    s32 left;
    s32 i;
    Vertex *vtx;
    s32 x;
    s32 y;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, 0x253216C0 | ((u64)0x20131806 << 32));
    sceGifPkAddGsData(&packet, 6);
    left = ((0x800 - D_0028EA54 / 2) << 4) + 8;
    vtx = D_0026FAA0;
    vtx += D_0028E2DC * 8;
    for (i = 0; i < 2; i++) {
        s64 t;
        sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 10));
        sceGifPkAddGsData(&packet, 0x53535310 | ((u64)0x53 << 32));
        sceGifPkAddGsData(&packet, 0x115);
        sceGifPkAddGsData(&packet, 0x80808080 | ((u64)0x3F800000 << 32));
        sceGifPkAddGsData(&packet, vtx[0].u | ((s64)vtx[0].v << 16));
        t = (s64)(left + vtx[0].x);
        sceGifPkAddGsData(&packet, t | ((s64)(vtx[0].y + 0x7200) << 16));
        sceGifPkAddGsData(&packet, vtx[1].u | ((s64)vtx[1].v << 16));
        x = left + vtx[1].x;
        y = vtx[1].y + 0x7200;
        sceGifPkAddGsData(&packet, (s64)x | ((s64)y << 16));
        sceGifPkAddGsData(&packet, vtx[2].u | ((s64)vtx[2].v << 16));
        x = left + vtx[2].x;
        y = vtx[2].y + 0x7200;
        sceGifPkAddGsData(&packet, (s64)x | ((s64)y << 16));
        sceGifPkAddGsData(&packet, vtx[3].u | ((s64)vtx[3].v << 16));
        x = left + vtx[3].x;
        y = vtx[3].y + 0x7200;
        sceGifPkAddGsData(&packet, (s64)x | ((s64)y << 16));
        vtx += 4;
    }
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(D_0028E9F4, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
