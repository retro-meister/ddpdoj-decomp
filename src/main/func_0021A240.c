#include "gallery/gallery.h"

typedef struct {
    s16 x[4];
    s16 y[4];
    s16 u[4];
    s16 v[4];
    s16 z;
    s16 pad22;
    s32 tbp;
    s32 cbp;
    s16 mode;
    s16 alpha;
    u16 color;
    s16 pad32;
} TileEntry;

extern TileEntry D_00592000[];

void func_0021A240(Qword *pkt, s32 first, s32 count) {
    s32 qwc;
    s32 i;
    s32 j;

    qwc = 1;
    pkt[0].q = 0;
    pkt[0].w[0] = 0x10000000;
    for (i = 0; i < count; i++) {
        s32 x[4];
        s32 y[4];
        s32 u[4];
        s32 v[4];
        s32 z;
        s32 alpha;
        u32 color;
        s32 tbp;
        s32 cbp;
        s32 mode;

        x[0] = D_00592000[first].x[0];
        x[1] = D_00592000[first].x[1];
        x[2] = D_00592000[first].x[2];
        x[3] = D_00592000[first].x[3];
        y[0] = D_00592000[first].y[0];
        y[1] = D_00592000[first].y[1];
        y[2] = D_00592000[first].y[2];
        y[3] = D_00592000[first].y[3];
        u[0] = D_00592000[first].u[0];
        u[1] = D_00592000[first].u[1];
        u[2] = D_00592000[first].u[2];
        u[3] = D_00592000[first].u[3];
        v[0] = D_00592000[first].v[0];
        v[1] = D_00592000[first].v[1];
        v[2] = D_00592000[first].v[2];
        v[3] = D_00592000[first].v[3];
        z = D_00592000[first].z;
        alpha = D_00592000[first].alpha;
        color = D_00592000[first].color;
        cbp = D_00592000[first].cbp;
        tbp = D_00592000[first].tbp;
        mode = D_00592000[first].mode;
        first++;

        pkt[qwc].d[0] = SCE_GIF_SET_TAG(7, 1, 0, 0, SCE_GIF_PACKED, 1);
        pkt[qwc].d[1] = SCE_GIF_PACKED_AD;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = SCE_GS_TEXFLUSH;
        qwc++;

        switch (mode) {
        case 0:
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(tbp, 16, SCE_GS_PSMT4, 10, 10, 1, 0, cbp, SCE_GS_PSMCT16, 0, 0, 1);
            break;
        case 1:
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(tbp, 8, SCE_GS_PSMT8, 9, 9, 1, 0, cbp, SCE_GS_PSMCT16, 0, 0, 1);
            break;
        case 3:
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(tbp, 16, SCE_GS_PSMT8, 10, 9, 1, 0, cbp, SCE_GS_PSMCT16, 0, 0, 1);
            break;
        }
        pkt[qwc].d[1] = SCE_GS_TEX0_1;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = SCE_GS_TEX1_1;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = SCE_GS_CLAMP_1;
        qwc++;

        pkt[qwc].d[0] = 0x3000F;
        pkt[qwc].d[1] = SCE_GS_TEST_1;
        qwc++;

        pkt[qwc].d[0] = (u64)0x80 << 32;
        pkt[qwc].d[1] = SCE_GS_TEXA;
        qwc++;

        pkt[qwc].d[0] = 0x44;
        pkt[qwc].d[1] = SCE_GS_ALPHA_1;
        qwc++;

        pkt[qwc].d[0] = SCE_GIF_SET_TAG(1, 1, 1, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 1, 0, 1, 0, 0), SCE_GIF_PACKED, 6);
        pkt[qwc].d[1] = 0x431431;
        qwc++;

        for (j = 0; j < 2; j++) {
            pkt[qwc].w[0] = color;
            pkt[qwc].w[1] = color;
            pkt[qwc].w[2] = color;
            pkt[qwc].w[3] = alpha;
            qwc++;

            pkt[qwc].w[0] = u[j] << 4;
            pkt[qwc].w[1] = v[j] << 4;
            pkt[qwc].w[2] = 0;
            pkt[qwc].w[3] = 0;
            qwc++;

            pkt[qwc].w[0] = ((x[j] + 0x700) << 4) + 8;
            pkt[qwc].w[1] = ((y[j] + 0x790) << 4) + 8;
            pkt[qwc].w[2] = z << 4;
            pkt[qwc].w[3] = 0;
            qwc++;
        }
    }
    pkt[qwc].q = 0;
    pkt[qwc].w[0] = 0x70000000;
    pkt[0].w[0] = (qwc - 1) | 0x10000000;
}
