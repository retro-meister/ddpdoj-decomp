#ifndef DDPDOJ_SDK_LIBGRAPH_H
#define DDPDOJ_SDK_LIBGRAPH_H

#include "types.h"

#define GS_RGBAQ(r, g, b, a, q) \
    ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))

#define GS_UV(u, v) \
    ((u64)(u) | ((u64)(v) << 16))

#define GS_XYZ2(x, y) \
    ((u64)(x) | ((u64)(y) << 16))

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
