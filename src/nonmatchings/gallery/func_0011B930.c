#include "common.h"

typedef union {
    unsigned __int128 q;
    u64 d[2];
    u32 w[4];
} Qword;

typedef struct {
    s16 x;
    s16 y;
    u16 z;
    u16 u;
    u16 v;
    u16 tex;
    u16 w;
    u16 h;
    u16 alpha;
} SpriteEntry;

extern SpriteEntry D_00132E80[];

void func_0011B930(Qword *pkt, s32 startIndex, s32 count) {
    s32 x[4];
    s32 y[4];
    s32 u[4];
    s32 v[4];
    s32 uOffset[4] = { 9, -9, 9, -9 };
    s32 qwc;
    s32 i;
    s32 j;

    qwc = 1;
    pkt[0].q = 0;
    pkt[0].w[0] = (count << 4) | 0x10000000;

    for (i = 0; i < count; i++, startIndex++) {
        s32 z;
        s32 tex;
        s32 width;
        s32 height;
        s32 alpha;
        s32 cbp;

        x[0] = D_00132E80[startIndex].x;
        y[0] = D_00132E80[startIndex].y;
        z = D_00132E80[startIndex].z;
        u[0] = D_00132E80[startIndex].u;
        v[0] = D_00132E80[startIndex].v;
        tex = D_00132E80[startIndex].tex;
        width = D_00132E80[startIndex].w;
        height = D_00132E80[startIndex].h;
        alpha = D_00132E80[startIndex].alpha;

        if (tex == 0x14) {
            cbp = 0x37FA;
        } else if (tex == 0x3832) {
            cbp = 0x3832;
        } else {
            cbp = tex + 0x37E8;
        }

        x[1] = x[0];
        x[2] = x[0];
        x[3] = x[0];
        y[1] = y[0];
        y[2] = y[0];
        y[3] = y[0];
        x[0] += width;
        x[1] += width;
        y[1] += height;
        y[3] += height;

        u[1] = u[0] + 0x1A;
        u[2] = u[0];
        u[3] = u[0] + 0x1A;
        v[1] = v[0];
        v[2] = v[0] + 0x1A;
        v[3] = v[0] + 0x1A;

        pkt[qwc].d[0] = 0x1000000000000002ULL;
        pkt[qwc].d[1] = 0xE;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = 0x3F;
        qwc++;

        if (cbp == 0x3832) {
            pkt[qwc].d[0] = ((u64)cbp << 37) | 0x20100006A9443800ULL;
        } else {
            pkt[qwc].d[0] = ((u64)cbp << 37) | 0x20000006A9443800ULL;
        }
        pkt[qwc].d[1] = 0x6;
        qwc++;

        pkt[qwc].d[0] = 0xC0AA400000008001ULL;
        pkt[qwc].d[1] = 0x0000431431431431ULL;
        qwc++;

        for (j = 0; j < 4; j++) {
            pkt[qwc].w[0] = 0x7F;
            pkt[qwc].w[1] = 0x7F;
            pkt[qwc].w[2] = 0x7F;
            pkt[qwc].w[3] = alpha;
            qwc++;

            pkt[qwc].w[0] = u[j] << 4;
            pkt[qwc].w[1] = v[j] << 4;
            pkt[qwc].w[2] = 0;
            pkt[qwc].w[3] = 0;
            if (cbp == 0x3832) {
                pkt[qwc].w[0] += uOffset[j];
            }
            qwc++;

            pkt[qwc].w[0] = (x[j] + 0x700) << 4;
            pkt[qwc].w[1] = (y[j] << 4) + 0x7900;
            pkt[qwc].w[2] = z << 4;
            pkt[qwc].w[3] = 0;
            qwc++;
        }
    }

    pkt[qwc].q = 0;
    pkt[qwc].w[0] = 0x70000000;
}
