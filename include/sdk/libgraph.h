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
    u64 FBP : 9;
    u64 FBW : 6;
    u64 PSM : 5;
    u64 p0 : 12;
    u64 DBX : 11;
    u64 DBY : 11;
    u64 p1 : 10;
} tGS_DISPFB;

typedef struct {
    u32 DX : 12;
    u32 DY : 11;
    u32 MAGH : 4;
    u32 MAGV : 2;
    u32 p0 : 3;
    u32 DW : 12;
    u32 DH : 11;
    u32 p1 : 9;
} tGS_DISPLAY;

typedef struct {
    u64 pmode;
    u64 smode2;
    tGS_DISPFB dispfb;
    tGS_DISPLAY display;
    u64 bgcolor;
} sceGsDispEnv;

typedef struct {
    u64 frame1;
    u64 frame1addr;
    u64 zbuf1;
    s64 zbuf1addr;
    u64 xyoffset1;
    s64 xyoffset1addr;
    u64 scissor1;
    s64 scissor1addr;
    u64 prmodecont;
    s64 prmodecontaddr;
    u64 colclamp;
    s64 colclampaddr;
    u64 dthe;
    s64 dtheaddr;
    u64 test1;
    s64 test1addr;
} sceGsDrawEnv1;

typedef struct {
    u64 frame2;
    u64 frame2addr;
    u64 zbuf2;
    s64 zbuf2addr;
    u64 xyoffset2;
    s64 xyoffset2addr;
    u64 scissor2;
    s64 scissor2addr;
    u64 prmodecont;
    s64 prmodecontaddr;
    u64 colclamp;
    s64 colclampaddr;
    u64 dthe;
    s64 dtheaddr;
    u64 test2;
    s64 test2addr;
} sceGsDrawEnv2;

typedef struct {
    u64 testa;
    s64 testaaddr;
    u64 prim;
    s64 primaddr;
    s64 rgbaq;
    s64 rgbaqaddr;
    u64 xyz2a;
    s64 xyz2aaddr;
    u64 xyz2b;
    s64 xyz2baddr;
    u64 testb;
    s64 testbaddr;
} sceGsClear;

typedef struct {
    /* 0x000 */ sceGsDispEnv disp[2];
    /* 0x050 */ unsigned __int128 giftag0;
    /* 0x060 */ sceGsDrawEnv1 draw01;
    /* 0x0E0 */ sceGsDrawEnv2 draw02;
    /* 0x160 */ sceGsClear clear0;
    /* 0x1C0 */ unsigned __int128 giftag1;
    /* 0x1D0 */ sceGsDrawEnv1 draw11;
    /* 0x250 */ sceGsDrawEnv2 draw12;
    /* 0x2D0 */ sceGsClear clear1;
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
