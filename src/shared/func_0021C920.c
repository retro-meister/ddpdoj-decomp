#include "common.h"
#include "sdk/ps2sdk.h"

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

typedef struct {
    s32 offset;
    s16 w;
    s16 h;
} TileImage;

extern void quad_build_packet(void *pkt, s32 first, s32 count);
extern s32 D_0026F960[];
extern u16 D_0026FBC0[][2];
extern u16 D_0026FC00[][2];
extern u16 D_0026FC40[][2];
extern u16 D_00270280[][2];
extern u16 D_00270430[][2];
extern u16 D_00270630[][2];
extern u16 D_00270690[][2];
extern u16 D_002706C0[][2];
extern u16 D_00270720[][2];
extern s16 D_0028E48A_as_s16;
extern void *g_dma_gif;
extern s32 g_quad_count;
extern u8 *D_0028EA9C;
extern u8 *D_0028EAA0;
extern TileImage *D_0028EAA4_as_TileImage_p;
extern u16 D_002B3950_as_u16_a_a5[][5];
extern u8 g_gif_buf[];
extern sceGsLoadImage g_gs_load_image;
extern u32 D_005C4C80[];
extern TileEntry g_quad_queue[];

void func_0021C920(void) {
    s32 tu;
    u16 flags;
    s32 flip;
    s32 tv;
    u16 *p;
    u32 *src;
    u32 *dst;
    s32 tbp;
    s32 count;
    s32 index;
    s32 mode;
    s32 prev;
    s32 palette;
    s32 buf;
    s32 id;
    u16 attr;
    s16 w;
    s16 h;
    s32 out;
    s32 in;
    u32 word;
    u32 fill;
    s32 n;
    s16 x;
    s16 y;
    s16 w2;
    s32 ex;
    s32 ybits;
    s32 ey;
    s32 dx;
    s32 dy;
    s32 sx;
    s32 sy;
    s32 scale;
    u8 *pkt;

    count = 0;
    p = D_002B3950_as_u16_a_a5[0];
    prev = -1;
    buf = 0;
    while (1) {
        attr = p[2];
        if ((p[0] | p[1] | attr | p[3] | p[4]) == 0) {
            break;
        }
        palette = ((attr >> 8) & 0x1F) * 4 + 0x3730;
        D_0028E48A_as_s16 = attr & 0x7F;
        reg_tmp.h[0] = p[3];
        tu = 0x10;
        tbp = 0x2240;
        tv = tu;
        mode = 1;
        id = reg_tmp.w;
        if (id == 0x10AA || (u32)(id - 0x11C3) <= 2 || id == 0x11C6) {
            palette = 0x383A;
        }
        if (id >= 0x1F69) {
            id = 0;
        }
        index = id;
        w = D_0028EAA4_as_TileImage_p[index].w;
        h = D_0028EAA4_as_TileImage_p[index].h;
        if (id >= 0xBBF && id < 0xBCF) {
            tu = D_0026FBC0[id - 0xBBF][0];
            tv = D_0026FBC0[id - 0xBBF][1];
            tbp = 0x2640;
        } else if (id >= 0xBFF && id < 0xC0F) {
            tu = D_0026FC00[id - 0xBFF][0];
            tv = D_0026FC00[id - 0xBFF][1];
            tbp = 0x2640;
        } else if (id >= 0x140 && id < 0x2CF) {
            tu = D_0026FC40[id - 0x140][0];
            tv = D_0026FC40[id - 0x140][1];
            tbp = 0x2640;
        } else if (id >= 0x13E0 && id < 0x144C) {
            tu = D_00270280[id - 0x13E0][0];
            tv = D_00270280[id - 0x13E0][1];
            tbp = 0x2640;
        } else if (id >= 0x1340 && id < 0x13C0) {
            tu = D_00270430[id - 0x1340][0];
            tv = D_00270430[id - 0x1340][1];
            tbp = 0x2640;
        } else if (id >= 0x11E2 && id < 0x11FA) {
            tbp = 0x2A40;
            tu = D_00270630[id - 0x11E2][0];
            tv = D_00270630[id - 0x11E2][1];
            mode = 3;
        } else if (id >= 0x123E && id < 0x124A) {
            tbp = 0x2A40;
            tu = D_00270690[id - 0x123E][0];
            tv = D_00270690[id - 0x123E][1];
            mode = 3;
        } else if (id >= 0x1286 && id < 0x129E) {
            tbp = 0x2A40;
            tu = D_002706C0[id - 0x1286][0];
            tv = D_002706C0[id - 0x1286][1];
            mode = 3;
        } else if (id >= 0x12BA && id < 0x12F0) {
            tbp = 0x2A40;
            tu = D_00270720[id - 0x12BA][0];
            tv = D_00270720[id - 0x12BA][1];
            mode = 3;
        } else if (prev != id) {
            prev = id;
            if (id >= 0x195E) {
                sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, 8, 0x13, 0x10, 0x10, w, h);
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, D_0028EA9C + D_0028EAA4_as_TileImage_p[index].offset);
            } else {
                src = (u32 *)(D_0028EAA0 + D_0028EAA4_as_TileImage_p[index].offset);
                out = 0;
                in = 0;
                dst = D_005C4C80;
                if (!(src[0] & 0x80000000)) {
                    sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, 8, 0x13, 0x10, 0x10, w, h);
                    FlushCache(0);
                    sceGsExecLoadImage(&g_gs_load_image, src);
                } else {
                    do {
                        fill = src[in++];
                        word = fill;
                        if (!(word & 0x40000000)) {
                            dst[out++] = word & 0x1F1F1F1F;
                        } else {
                            fill = src[in++] & 0x1F1F1F1F;
                            for (n = word & 0x3FFF; n >= 0; n--) {
                                dst[out++] = fill;
                            }
                        }
                    } while (out < w * h / 4);
                    sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, 8, 0x13, 0x10, 0x10, w, h);
                    FlushCache(0);
                    sceGsExecLoadImage(&g_gs_load_image, dst);
                }
            }
            sceGsSyncPath(0, 0);
        }
        x = p[0] & 0x7FF;
        y = p[1] & 0x3FF;
        dy = p[4] & 0x1FF;
        dx = ((p[4] >> 9) & 0x3F) << 4;
        w2 = D_0028EAA4_as_TileImage_p[index].w;
        h = D_0028EAA4_as_TileImage_p[index].h;
        if (x & 0x400) {
            x |= 0xF800;
        }
        if (y & 0x100) {
            y |= 0xFE00;
        }
        ex = x;
        ey = y;
        sx = (p[0] & 0xF800) >> 11;
        ybits = p[1] & 0xF800;
        if (sx == 0 || (sy = ybits >> 11) == 0) {
            p += 5;
            continue;
        }
        if (sx != 16) {
            scale = D_0026F960[sx];
            if (scale >= 10000) {
                dx = (dx * scale + 5000) / 10000;
            } else {
                dx = dx * scale / 10000 + 1;
            }
        }
        if (sy != 16) {
            scale = D_0026F960[sy];
            if (scale >= 10000) {
                dy = (dy * scale + 5000) / 10000;
            } else {
                dy = dy * scale / 10000 + 1;
            }
        }
        flags = p[2];
        flip = (flags >> 13) & 3;
        g_quad_queue[count].z = 10;
        g_quad_queue[count].alpha = 0x80;
        g_quad_queue[count].tbp = tbp;
        g_quad_queue[count].mode = mode;
        g_quad_queue[count].cbp = palette;
        g_quad_queue[count].color = 0x80;
        g_quad_queue[count].x[0] = ex;
        g_quad_queue[count].y[0] = ey;
        g_quad_queue[count].x[1] = ex + dx;
        g_quad_queue[count].y[1] = ey + dy;
        switch (flip) {
        case 0:
            g_quad_queue[count].u[0] = tu;
            g_quad_queue[count].v[0] = tv;
            g_quad_queue[count].u[1] = tu + w2;
            g_quad_queue[count].v[1] = tv + h;
            break;
        case 1:
            g_quad_queue[count].u[0] = tu + w2;
            g_quad_queue[count].v[0] = tv;
            g_quad_queue[count].u[1] = tu;
            g_quad_queue[count].v[1] = tv + h;
            break;
        case 2:
            g_quad_queue[count].u[0] = tu;
            g_quad_queue[count].v[0] = tv + h;
            g_quad_queue[count].u[1] = tu + w2;
            g_quad_queue[count].v[1] = tv;
            break;
        case 3:
            g_quad_queue[count].u[0] = tu + w2;
            g_quad_queue[count].v[0] = tv + h;
            g_quad_queue[count].u[1] = tu;
            g_quad_queue[count].v[1] = tv;
            break;
        }
        pkt = g_gif_buf + (buf << 16);
        quad_build_packet(pkt, count, 1);
        sceGsSyncPath(0, 0);
        FlushCache(0);
        sceDmaSend(g_dma_gif, pkt);
        buf ^= 1;
        count++;
        p += 5;
    }
    g_quad_count = count;
}
