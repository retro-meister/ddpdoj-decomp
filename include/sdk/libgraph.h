#ifndef DDPDOJ_SDK_LIBGRAPH_H
#define DDPDOJ_SDK_LIBGRAPH_H

#include "types.h"
#include "sdk/eestruct.h"

#define SCE_GS_NOINTERLACE 0
#define SCE_GS_INTERLACE   1
#define SCE_GS_FIELD       0
#define SCE_GS_FRAME       1
#define SCE_GS_NTSC        0x2
#define SCE_GS_PAL         0x3

typedef struct {
    unsigned __int128 giftag0;
    u64 bitbltbuf;
    s64 bitbltbufaddr;
    u64 trxpos;
    s64 trxposaddr;
    u64 trxreg;
    s64 trxregaddr;
    u64 trxdir;
    s64 trxdiraddr;
    unsigned __int128 giftag1;
} sceGsLoadImage;

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
s32 sceGsSetDefLoadImage(sceGsLoadImage *lp, s16 dbp, s16 dbw, s16 dpsm, s16 x, s16 y, s16 w, s16 h);
s32 sceGsExecLoadImage(sceGsLoadImage *lp, const void *srcaddr);
void sceGsSetHalfOffset(void *draw, s32 centerx, s32 centery, s16 halfoffset);
void sceGsSetHalfOffset2(void *draw, s32 centerx, s32 centery, s16 halfoffset);
void sceGsSetDefDBuffDc(void *db, s32 psm, s32 w, s32 h, s32 ztest, s32 zpsm, s32 clear);
void sceGsSwapDBuffDc(void *db, s32 id);

#endif
