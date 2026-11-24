#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"
#include "cd.h"
#include "arcade_sprite.h"

extern sceGsLoadImage g_gs_load_image;
extern s32 g_clut_upload_cbp;
extern u8 D_004CCF80[];
#ifdef DEATH_LABEL
extern u8 death_D_0056A800[];
#endif
extern u8 D_004ECF80[];
void clut_upload(u8 *destination, s32 mode, s32 blockCount);

void arcade_sprite_init(void) {
    u8 *buffer;

    buffer = memalign(0x40, 0x80000);
    cd_read_sync(buffer, g_data_files[DATA_FILE_BULLET].size, g_data_files[DATA_FILE_BULLET].lba);
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2640, 8, SCE_GS_PSMT8, 0, 0, 512, 512);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, buffer);
    sceGsSyncPath(0, 0);
    cd_read_sync(buffer, g_data_files[DATA_FILE_EXPLOSION].size, g_data_files[DATA_FILE_EXPLOSION].lba);
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2A40, 0x10, SCE_GS_PSMT8, 0, 0, 1024, 256);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, buffer);
    sceGsSyncPath(0, 0);
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2A40, 0x10, SCE_GS_PSMT8, 0, 256, 1024, 256);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, buffer + 0x40000);
    sceGsSyncPath(0, 0);
    free(buffer);
    g_sprite_images = (SpriteImage *)memalign(0x40, 0x10000);
    g_sprite_pixels = memalign(0x40, 0xC20000);
    g_stage_sprite_buf = memalign(0x40, 0x885800);
    g_frame_file_buf = memalign(0x40, 0x10800);
    cd_read_sync(g_frame_file_buf, g_data_files[DATA_FILE_FRAME].size, g_data_files[DATA_FILE_FRAME].lba);
    g_clut_upload_cbp = 0x3834;
    clut_upload(g_frame_file_buf, 1, 1);
    cd_read_sync(D_004ECF80, g_data_files[MAIN_OR_DEATH_LABEL(DATA_FILE_ARIKA, DATA_FILE_DON)].size,
                 g_data_files[MAIN_OR_DEATH_LABEL(DATA_FILE_ARIKA, DATA_FILE_DON)].lba);
    g_clut_upload_cbp = 0x3836;
    clut_upload(D_004ECF80, 1, 1);
    cd_read_sync(D_004CCF80, g_data_files[DATA_FILE_MAP].size, g_data_files[DATA_FILE_MAP].lba);
    g_clut_upload_cbp = 0x3838;
    clut_upload(D_004CCF80, 1, 1);
#ifdef DEATH_LABEL
    cd_read_sync(death_D_0056A800, g_data_files[DATA_FILE_NOISE].size, g_data_files[DATA_FILE_NOISE].lba);
    g_clut_upload_cbp = 0x383C;
    clut_upload(death_D_0056A800, 1, 1);
#endif
}


void sprite_header_load_async(void) {
    cd_read_async(g_sprite_images, g_data_files[DATA_FILE_SPRITE_HEADER].size, g_data_files[DATA_FILE_SPRITE_HEADER].lba);
}



void sprite_pixels_load_async(void) {
    cd_read_async(g_sprite_pixels, g_data_files[DATA_FILE_SPRITE_DATA].size, g_data_files[DATA_FILE_SPRITE_DATA].lba);
}

extern u8 *g_unpack_src;
extern u8 *g_unpack_dst;
extern u8 *g_unpack_src_start;
extern s32 g_unpack_step;
extern s32 g_unpack_chunk_size;
void stage_sprite_unpack_begin(s32 value) {
    u8 *base = g_stage_sprite_buf;
    g_unpack_chunk_size = value;
    g_unpack_step = 0;
    g_unpack_dst = base;
    g_unpack_src_start = base + 0x5DC800;
    g_unpack_src = g_unpack_src_start;
}

extern s32 g_stage_sprite_packed_size[];
extern u16 D_0028E91C;

s32 stage_sprite_unpack_step(void) {
    u8 *src;
    s32 count;
    u8 code;

    g_unpack_step++;
    while (g_unpack_src - g_unpack_src_start < g_stage_sprite_packed_size[D_0028E91C]) {
        code = *g_unpack_src;
        g_unpack_src++;
        if (code & 0x80) {
            count = *g_unpack_src;
            g_unpack_src++;
            src = g_unpack_dst - (code & 0x7F);
            for (; count >= 0; count--) {
                *g_unpack_dst = *src;
                g_unpack_dst++;
                src++;
            }
        } else if (code & 0x40) {
            src = g_unpack_dst - (code & 0x3F);
            *g_unpack_dst = src[0];
            g_unpack_dst++;
            *g_unpack_dst = src[1];
            g_unpack_dst++;
        } else {
            *g_unpack_dst = code;
            g_unpack_dst++;
        }
        if (g_unpack_dst - g_stage_sprite_buf > g_unpack_step * g_unpack_chunk_size) {
            return 0;
        }
    }
    return 1;
}

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

extern void quad_build_packet(void *pkt, s32 first, s32 count);
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
extern u16 D_002B3950_as_u16_a_a5[][5];
extern u8 g_gif_buf[];
extern TileEntry g_quad_queue[];

void arcade_sprite_draw(void) {
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
        w = g_sprite_images[index].w;
        h = g_sprite_images[index].h;
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
                sceGsExecLoadImage(&g_gs_load_image, g_stage_sprite_buf + g_sprite_images[index].offset);
            } else {
                src = (u32 *)(g_sprite_pixels + g_sprite_images[index].offset);
                out = 0;
                in = 0;
                dst = g_image_unpack_buf;
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
        w2 = g_sprite_images[index].w;
        h = g_sprite_images[index].h;
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
            scale = g_sprite_zoom_table[sx];
            if (scale >= 10000) {
                dx = (dx * scale + 5000) / 10000;
            } else {
                dx = dx * scale / 10000 + 1;
            }
        }
        if (sy != 16) {
            scale = g_sprite_zoom_table[sy];
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

#pragma push
#pragma global_optimizer off
typedef struct {
    unsigned __int128 q;
} GifTag;

extern void sceGifPkOpenGifTag(sceGifPacket *packet, unsigned __int128 tag);
extern void sceGifPkCloseGifTag(sceGifPacket *packet);
extern void sceGifPkAddGsAD(sceGifPacket *packet, s32 addr, u64 data);
extern GifTag D_00270800[];

void frame_image_draw(u16 alpha) {
    GifTag tag;
    sceGifPacket packet;
    u8 *buf;
    s32 c;
    u64 prim;

    tag = D_00270800[0];
    buf = g_gif_buf;
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, 8, 0x13, 0, 0, 320, 208);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, g_frame_file_buf + 0x200);
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
    sceDmaSendN(g_dma_gif, buf, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
#pragma pop
