#include "gallery/gallery.h"

typedef struct GalleryFrame
{
    s32 reserved00[2];
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 reserved18;
    s32 tileAttributes;
} GalleryFrame;

inline static s32 getBits(s32 count)
{
    s32 ret = 0;
    s32 i;
    for (i = 0; i < count; i++) {
        if ((g_gallery->flagBuf[g_gallery->flagBytePos] >> g_gallery->flagBitPos) & 1) {
            ret += 1 << ((count - 1) - i);
        }
        g_gallery->flagBitPos--;
        if (g_gallery->flagBitPos < 0) {
            g_gallery->flagBitPos = 7;
            g_gallery->flagBytePos++;
        }
    }

    return ret;
}

s32 lzss_decompress_step(u8 *dst, u8 *src)
{
    s32 copyLen;
    s32 backOffset;
    switch (g_gallery->stepState) {
        case 0:
            g_gallery->flagSize = *((s32 *)(src + 8));
            g_gallery->flagBytePos = 0;
            g_gallery->flagBitPos = 7;
            g_gallery->dstPos = 0;
            g_gallery->srcPos = 0;
            g_gallery->dstSize = *((s32 *)(src + 0));
            if (g_gallery->srcPos && g_gallery->srcPos) {
            }
            {
                s32 s = *((s32 *)(src + 4));
                g_gallery->srcSize = s;
            }
            g_gallery->chunkLimit = g_gallery->dstSize / 16;
            memcpy(g_gallery->flagBuf, src + 0xC, g_gallery->flagSize);
            g_gallery->srcPos = g_gallery->flagSize + 0xC;
            g_gallery->stepState++;
            break;

        case 1:
            while (g_gallery->srcPos < g_gallery->srcSize) {
                if (getBits(1) != 0) {
                    copyLen = (src[g_gallery->srcPos + 1] & 0x1F) + 3;
                    backOffset = (src[g_gallery->srcPos] << 3) + ((src[g_gallery->srcPos + 1] >> 5) & 7);
                    memcpy(&dst[g_gallery->dstPos], (&dst[g_gallery->dstPos]) - backOffset, copyLen);
                    g_gallery->dstPos += copyLen;
                    g_gallery->srcPos += 2;
                } else {
                    dst[g_gallery->dstPos] = src[g_gallery->srcPos];
                    g_gallery->dstPos++;
                    g_gallery->srcPos++;
                }
                if (g_gallery->dstPos >= g_gallery->chunkLimit) {
                    g_gallery->chunkLimit += g_gallery->dstSize / 16;
                    if (g_gallery->srcPos < g_gallery->srcSize) {
                        return 0;
                    }
                }
            }

            return 1;
    }

    return 0;
}

void lzss_draw_frame_overlay(void *framePtr)
{
    GalleryFrame *frame = framePtr;
    s32 rowState[2];
    s32 x;
    s32 y;
    s32 innerColumns;

    innerColumns = ((frame->right - frame->left) / 16) - 2;
    rowState[1] = (frame->bottom - frame->top) / 32;
    rowState[0] = rowState[1] - 2;
    x = frame->left - 6;
    y = frame->top / 2;
    sprite_queue_glyph(x - 64, y, 0x2289, frame->tileAttributes, 300);
    y += 16;
    for (rowState[1] = 0; rowState[1] < rowState[0]; rowState[1]++) {
        sprite_queue_glyph(x - 64, y, 0x228A, frame->tileAttributes, 300);
        y += 16;
    }

    sprite_queue_glyph(x - 64, y, 0x228B, frame->tileAttributes, 300);
    x = frame->left + 10;
    y = frame->top / 2;
    for (rowState[1] = 0; rowState[1] < innerColumns; rowState[1]++) {
        sprite_queue_glyph(x - 64, y, 0x2287, frame->tileAttributes, 300);
        x += 16;
    }

    x = frame->left + 10;
    y = (frame->top / 2) + ((rowState[0] + 1) * 16);
    for (rowState[1] = 0; rowState[1] < innerColumns; rowState[1]++) {
        sprite_queue_glyph(x - 64, y, 0x2288, frame->tileAttributes, 300);
        x += 16;
    }

    x = frame->left + (((innerColumns + 1) * 16) - 6);
    y = frame->top / 2;
    sprite_queue_glyph(x - 64, y, 0x2284, frame->tileAttributes, 300);
    y += 16;
    for (rowState[1] = 0; rowState[1] < rowState[0]; rowState[1]++) {
        sprite_queue_glyph(x - 64, y, 0x2285, frame->tileAttributes, 300);
        y += 16;
    }

    sprite_queue_glyph(x - 64, y, 0x2286, frame->tileAttributes, 300);
}

void gallery_draw_solid_rect(s32 xStart, s32 yStart, s32 xEnd, s32 yEnd,
                   s32 red, s32 green, s32 blue, s32 alpha, s32 blendMode)
{
    sceGifPacket packet;

    sceGifPkInit(&packet, g_gif_buf);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, 0x1000000000008001ULL);
    sceGifPkAddGsData(&packet, 0xEULL);

    if (blendMode == 0) {
        sceGifPkAddGsData(&packet, 0x44ULL);
    } else if (blendMode == 1) {
        sceGifPkAddGsData(&packet, 0x48ULL);
    } else {
        sceGifPkAddGsData(&packet, 0x80000000A1ULL);
    }

    sceGifPkAddGsData(&packet, 0x42ULL);
    sceGifPkAddGsData(&packet, 0x4400000000008001ULL);
    sceGifPkAddGsData(&packet, 0x5510ULL);
    sceGifPkAddGsData(&packet, 0x146ULL);
    sceGifPkAddGsData(&packet, (u64)(s64)red |
                            ((u64)(s64)green << 8) |
                            ((u64)(s64)blue << 16) |
                            ((u64)(s64)alpha << 24) |
                            0x3F80000000000000ULL);
    sceGifPkAddGsData(&packet, (u64)(s64)(s32)(((u32)xStart << 4) + 0x6C00U) |
                            ((u64)(s64)(s32)(((u32)yStart << 3) + 0x7900U) << 16));
    sceGifPkAddGsData(&packet, (u64)(s64)(s32)(((u32)xEnd << 4) + 0x6C00U) |
                            ((u64)(s64)(s32)(((u32)yEnd << 3) + 0x7900U) << 16));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, g_gif_buf, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}
