#ifndef DDPDOJ_SDK_LIBGRAPH_H
#define DDPDOJ_SDK_LIBGRAPH_H

#include "types.h"

#define SCE_GIF_PACKED_AD 0x0EULL

#define SCE_GS_TEX0_1     0x06ULL
#define SCE_GS_TEX1_1     0x14ULL
#define SCE_GS_TEXA       0x3BULL
#define SCE_GS_TEXFLUSH   0x3FULL
#define SCE_GS_ALPHA_1    0x42ULL
#define SCE_GS_TEST_1     0x47ULL
#define SCE_GS_ZBUF_1     0x4EULL

#define GS_RGBAQ(r, g, b, a, q) \
    ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))

#define GS_UV(u, v) \
    ((u64)(u) | ((u64)(v) << 16))

#define GS_XYZ2(x, y) \
    ((u64)(x) | ((u64)(y) << 16))

typedef struct {
    u8 disp0[0x50];
    u8 draw01[0x10];
    u8 draw01_env[0x80];
    u8 draw02[0xE0];
    u8 draw11[0x10];
    u8 draw11_env[0x80];
    u8 draw12[0xE0];
} sceGsDBuffDc;

void sceGsResetGraph(s32 mode, s32 interlace, s32 omode, s32 ffmode);
void sceGsResetPath(void);
void sceGsPutDrawEnv(void *giftag);
s32 sceGsSyncV(s32 mode);
s32 sceGsSyncPath(s32 mode, s32 timeout);
s32 sceGsSetDefLoadImage(void *lp, s16 dbp, s16 dbw, s16 dpsm, s16 x, s16 y, s16 w, s16 h);
s32 sceGsExecLoadImage(void *lp, const void *srcaddr);
void sceGsSetHalfOffset(void *draw, s32 centerx, s32 centery, s16 halfoffset);
void sceGsSetHalfOffset2(void *draw, s32 centerx, s32 centery, s16 halfoffset);
void sceGsSetDefDBuffDc(void *db, s32 psm, s32 w, s32 h, s32 ztest, s32 zpsm, s32 clear);
void sceGsSwapDBuffDc(void *db, s32 id);

#endif
