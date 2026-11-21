#include "gallery/gallery.h"

typedef struct {
    s16 x;
    s16 y;
    u16 depth;
    u16 u;
    u16 v;
    u16 tex;
    u16 w;
    u16 h;
    u16 alpha;
} SpriteEntry;

extern SpriteEntry g_sprite_queue[];
extern s8 g_glyph_upload_buf[];

void sprite_build_quad_packet(Qword *pkt, s32 startIndex, s32 count)
{
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

    for (i = 0; i < count; i++) {
        s32 z;
        s32 tex;
        s32 width;
        s32 height;
        s32 alpha;
        s32 cbp;

        x[0] = g_sprite_queue[startIndex].x;
        y[0] = g_sprite_queue[startIndex].y;
        z = g_sprite_queue[startIndex].depth;
        u[0] = g_sprite_queue[startIndex].u;
        v[0] = g_sprite_queue[startIndex].v;
        tex = g_sprite_queue[startIndex].tex;
        width = g_sprite_queue[startIndex].w;
        height = g_sprite_queue[startIndex].h;
        alpha = g_sprite_queue[startIndex].alpha;

        if (tex == 0x14) {
            cbp = 0x37FA;
        } else if (tex == 0x3832) {
            cbp = 0x3832;
        } else {
            cbp = tex + 0x37E8;
        }

        startIndex++;

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

        pkt[qwc].d[0] = SCE_GIF_SET_TAG(2, 0, 0, 0, SCE_GIF_PACKED, 1);
        pkt[qwc].d[1] = SCE_GIF_PACKED_AD;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = SCE_GS_TEXFLUSH;
        qwc++;

        if (cbp == 0x3832) {
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(0x3800, 16, SCE_GS_PSMT4, 10, 10, 1, 0, cbp, SCE_GS_PSMCT16, 0, 0, 1);
        } else {
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(0x3800, 16, SCE_GS_PSMT4, 10, 10, 1, 0, cbp, SCE_GS_PSMCT32, 0, 0, 1);
        }
        pkt[qwc].d[1] = SCE_GS_TEX0_1;
        qwc++;

        pkt[qwc].d[0] = SCE_GIF_SET_TAG(1, 1, 1, SCE_GS_SET_PRIM(SCE_GS_PRIM_TRISTRIP, 0, 1, 0, 1, 0, 1, 0, 0), SCE_GIF_PACKED, 12);
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

void sprite_flush_quads(void)
{
    s32 firstEntry;
    s32 remainingEntries;
    s32 batchCount;
    s32 bufferIndex;
    u8 *packet;

    if (g_sprite_queue_count != 0) {
        font_build_gs_setup_packet(g_gif_buf[0]);
        FlushCache(0);
        sceDmaSend(g_dma_gif, g_gif_buf[0]);
        sceGsSyncPath(0, 0);

        bufferIndex = 0;
        firstEntry = 0;
        while ((remainingEntries = g_sprite_queue_count) != 0) {
            if (remainingEntries >= 6) {
                batchCount = 6;
            } else {
                batchCount = remainingEntries;
            }

            packet = g_gif_buf[bufferIndex];
            sprite_build_quad_packet((Qword *)packet, firstEntry, batchCount);
            sceGsSyncPath(0, 0);
            FlushCache(0);
            sceDmaSend(g_dma_gif, packet);

            g_sprite_queue_count -= batchCount;
            firstEntry += batchCount;
            bufferIndex ^= 1;
        }
    }
}

void sprite_queue_glyph(x, y, textureId, attributes, scale)
    s16 x;
    s16 y;
    u16 textureId;
    u16 attributes;
    u16 scale;
{
    s32 id = textureId;
    s32 textureIndex;
    s32 uploaded = 0;
    GlyphCacheEntry *textures = g_glyph_cache;

    if (g_sprite_queue_count < 0x200) {
        s32 queueIndex;
        s16 width;
        s16 height;

        textureIndex = glyph_cache_lookup((u16)id);
        if (textureIndex & 0x8000) {
            s32 byteIndex;

            for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                g_glyph_upload_buf[byteIndex] = (g_font_glyph_buf + id * 0x152)[byteIndex];
            }

            textureIndex &= 0x7FFF;
            sceGsSetDefLoadImage(g_gs_load_image, 0x3800, 0x10, 0x14,
                          textures[textureIndex].x,
                          textures[textureIndex].y, 0x1A, 0x1A);
            FlushCache(0);
            sceGsExecLoadImage(g_gs_load_image, g_glyph_upload_buf);
            uploaded++;
        }

        width = textures[textureIndex & 0x7FFF].x;
        height = textures[textureIndex & 0x7FFF].y;
        if (scale == 0) {
            scale = 1;
        }

        queueIndex = g_sprite_queue_count;
        g_sprite_queue[queueIndex].x = x;
        g_sprite_queue[queueIndex].y = y;
        g_sprite_queue[queueIndex].depth = scale;
        g_sprite_queue[queueIndex].u = width;
        g_sprite_queue[queueIndex].v = height;
        g_sprite_queue[queueIndex].tex = 0x3832;
        g_sprite_queue[queueIndex].w = 0x1B;
        g_sprite_queue[queueIndex].h = 0x1B;
        g_sprite_queue[queueIndex].alpha = attributes;
        g_sprite_queue_count++;
    }

    if (uploaded != 0) {
        sceGsSyncPath(0, 0);
    }
}

void sprite_build_rect_packet(Qword *packet, s32 firstEntry, s32 entryCount)
{
    s32 packetIndex;
    s32 entryIndex;

    packetIndex = 1;
    packet[0].q = 0;
    packet[0].w[0] = (entryCount * 10) | 0x10000000;

    for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
        s32 x = g_sprite_queue[firstEntry].x;
        s32 y = g_sprite_queue[firstEntry].y;
        s32 depth = g_sprite_queue[firstEntry].depth;
        s32 textureU = g_sprite_queue[firstEntry].u;
        s32 textureV = g_sprite_queue[firstEntry].v;
        s32 texturePage = g_sprite_queue[firstEntry].tex;
        s32 width = g_sprite_queue[firstEntry].w;
        s32 height = g_sprite_queue[firstEntry].h;
        s32 alpha = g_sprite_queue[firstEntry].alpha;
        s32 textureBase;
        s32 left;
        s32 right;

        if (texturePage == 0x14) {
            textureBase = 0x37FA;
        } else {
            textureBase = texturePage + 0x37E8;
        }

        firstEntry++;
        left = x + 0x700;
        right = left + width;
        depth <<= 4;
        height >>= 1;

        packet[packetIndex].d[0] = SCE_GIF_SET_TAG(2, 0, 0, 0, SCE_GIF_PACKED, 1);
        packet[packetIndex].d[1] = SCE_GIF_PACKED_AD;
        packetIndex++;

        packet[packetIndex].d[0] = 0;
        packet[packetIndex].d[1] = SCE_GS_TEXFLUSH;
        packetIndex++;

        packet[packetIndex].d[0] =
            SCE_GS_SET_TEX0(0x3800, 16, SCE_GS_PSMT4, 10, 10, 1, 0, textureBase, SCE_GS_PSMCT32, 0, 0, 1);
        packet[packetIndex].d[1] = SCE_GS_TEX0_1;
        packetIndex++;

        packet[packetIndex].d[0] = SCE_GIF_SET_TAG(1, 1, 1, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 1, 1, 1, 0, 0), SCE_GIF_PACKED, 6);
        packet[packetIndex].d[1] = 0x431431;
        packetIndex++;

        packet[packetIndex].w[0] = 0x7F;
        packet[packetIndex].w[1] = 0x7F;
        packet[packetIndex].w[2] = 0x7F;
        packet[packetIndex].w[3] = alpha;
        packetIndex++;

        packet[packetIndex].w[0] = textureU << 4;
        packet[packetIndex].w[1] = textureV << 4;
        packet[packetIndex].w[2] = 0;
        packet[packetIndex].w[3] = 0;
        packetIndex++;

        packet[packetIndex].w[0] = (u32)left << 4;
        packet[packetIndex].w[1] = ((u32)y << 3) + 0x7900;
        packet[packetIndex].w[2] = depth;
        packet[packetIndex].w[3] = 0;
        packetIndex++;

        packet[packetIndex].w[0] = 0x7F;
        packet[packetIndex].w[1] = 0x7F;
        packet[packetIndex].w[2] = 0x7F;
        packet[packetIndex].w[3] = alpha;
        packetIndex++;

        packet[packetIndex].w[0] = (textureU + 0x1A) << 4;
        packet[packetIndex].w[1] = (textureV + 0x1A) << 4;
        packet[packetIndex].w[2] = 0;
        packet[packetIndex].w[3] = 0;
        packetIndex++;

        packet[packetIndex].w[0] = (u32)right << 4;
        packet[packetIndex].w[1] = ((height + 0x790) << 4) + ((u32)y << 3);
        packet[packetIndex].w[2] = depth;
        packet[packetIndex].w[3] = 0;
        packetIndex++;
    }

    packet[packetIndex].q = 0;
    packet[packetIndex].w[0] = 0x70000000;
}

void sprite_flush_rects(void)
{
    s32 entryOffset;
    s32 batchSize;
    s32 remainingEntries;
    s32 bufferIndex;
    u8 *buffer;

    if (g_sprite_queue_count != 0) {
        font_build_gs_setup_packet(g_gif_buf[0]);
        FlushCache(0);
        sceDmaSend(g_dma_gif, g_gif_buf[0]);
        sceGsSyncPath(0, 0);

        bufferIndex = 0;
        entryOffset = 0;
        while ((remainingEntries = g_sprite_queue_count) != 0) {
            if (remainingEntries >= 6) {
                batchSize = 6;
            } else {
                batchSize = remainingEntries;
            }

            buffer = g_gif_buf[bufferIndex];
            sprite_build_rect_packet((Qword *)buffer, entryOffset, batchSize);
            sceGsSyncPath(0, 0);
            FlushCache(0);
            sceDmaSend(g_dma_gif, buffer);

            entryOffset += batchSize;
            g_sprite_queue_count -= batchSize;
            bufferIndex ^= 1;
        }
    }
}

void sprite_queue_sjis_text(s32 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth)
{
    s32 uploadCount = 0;
    s8 *uploadBuffer = g_glyph_upload_buf;
    GlyphCacheEntry *cache = g_glyph_cache;
    s8 leadByte;
    s32 shiftJis;
    u64 jis;
    u64 row;
    u64 col;
    s32 glyphIndex;
    s32 cacheIndex;
    s32 byteIndex;
    s32 bitmapOffset;
    s16 textureX;
    s16 textureY;
    SpriteEntry *drawEntry;

    while (((leadByte = *text) != 0) && (uploadCount < 30)) {
        shiftJis = (s8)leadByte;
        shiftJis &= 0xFF;
        shiftJis <<= 8;
        shiftJis |= (u8)text[1];
        text += 2;
        if (shiftJis == 0x818F) {
            break;
        }
        if ((g_sprite_queue_count < 512) || (shiftJis != 0x8140)) {
            jis = sjis_to_jis((s64)shiftJis);
            row = ((jis >> 8) - 0x21) * 94;
            col = (jis & 0xFF) - 0x21;
            glyphIndex = (s32)(row + col);
            cacheIndex = glyph_cache_lookup((u16)glyphIndex);
            if (cacheIndex & 0x8000) {
                bitmapOffset = glyphIndex * 0x152;
                for (byteIndex = 0; byteIndex < 0x14A; byteIndex += 8) {
                    uploadBuffer[byteIndex + 0] = ((g_font_glyph_buf + bitmapOffset) + byteIndex)[0];
                    uploadBuffer[byteIndex + 1] = ((g_font_glyph_buf + bitmapOffset) + byteIndex)[1];
                    uploadBuffer[byteIndex + 2] = ((g_font_glyph_buf + bitmapOffset) + byteIndex)[2];
                    uploadBuffer[byteIndex + 3] = ((g_font_glyph_buf + bitmapOffset) + byteIndex)[3];
                    uploadBuffer[byteIndex + 4] = ((g_font_glyph_buf + bitmapOffset) + byteIndex)[4];
                    uploadBuffer[byteIndex + 5] = ((g_font_glyph_buf + bitmapOffset) + byteIndex)[5];
                    uploadBuffer[byteIndex + 6] = ((g_font_glyph_buf + bitmapOffset) + byteIndex)[6];
                    uploadBuffer[byteIndex + 7] = ((g_font_glyph_buf + bitmapOffset) + byteIndex)[7];
                }

                uploadBuffer[byteIndex + 0] = ((g_font_glyph_buf + bitmapOffset) + byteIndex)[0];
                uploadBuffer[byteIndex + 1] = ((g_font_glyph_buf + bitmapOffset) + byteIndex)[1];
                cacheIndex &= 0x7FFF;
                sceGsSetDefLoadImage(g_gs_load_image, 0x3800, 16, 20, cache[cacheIndex].x, cache[cacheIndex].y, 26, 26);
                FlushCache(0);
                sceGsExecLoadImage(g_gs_load_image, uploadBuffer);
                uploadBuffer += 0x200;
                uploadCount++;
            }
            textureX = cache[cacheIndex & 0x7FFF].x;
            textureY = cache[cacheIndex & 0x7FFF].y;
            if (glyphWidth == 0) {
                glyphWidth = 26;
                glyphHeight = glyphWidth;
            }
            if (depth == 0) {
                depth = 1;
            }
            drawEntry = &g_sprite_queue[g_sprite_queue_count];
            drawEntry->x = x;
            drawEntry->y = y;
            drawEntry->depth = depth;
            drawEntry->u = textureX;
            drawEntry->v = textureY;
            drawEntry->tex = texturePage;
            drawEntry->w = glyphWidth;
            drawEntry->h = glyphHeight;
            drawEntry->alpha = alpha;
            g_sprite_queue_count++;
        }
        x = (s16)(x + ((s16)glyphWidth));
    }

    if (uploadCount != 0) {
        sceGsSyncPath(0, 0);
    }
}

void sprite_clear_queue(void)
{
    g_sprite_queue_count = 0;
}

s32 g_sprite_queue_count;
SpriteEntry g_sprite_queue[512];
