#include "gallery/gallery.h"

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
#ifdef DDPDOJ_PC
            if (g_gallery->dstSize < 16 || (u32)g_gallery->dstSize > sizeof(g_gallery->decodeBuf) ||
                g_gallery->flagSize <= 0 || g_gallery->srcSize < 12 ||
                (u32)g_gallery->srcSize > g_cd_last_read_size ||
                g_gallery->flagSize > g_gallery->srcSize - 12) {
                g_gallery->assetError = 1;
                return 0;
            }
#endif
            memcpy(g_gallery->flagBuf, src + 0xC, g_gallery->flagSize);
            g_gallery->srcPos = g_gallery->flagSize + 0xC;
            g_gallery->stepState++;
            break;

        case 1:
            while (g_gallery->srcPos < g_gallery->srcSize) {
#ifdef DDPDOJ_PC
                if (g_gallery->flagBytePos >= g_gallery->flagSize ||
                    g_gallery->dstPos >= g_gallery->dstSize) {
                    g_gallery->assetError = 1;
                    return 0;
                }
#endif
                if (getBits(1) != 0) {
#ifdef DDPDOJ_PC
                    if (g_gallery->srcPos + 1 >= g_gallery->srcSize) {
                        g_gallery->assetError = 1;
                        return 0;
                    }
#endif
                    copyLen = (src[g_gallery->srcPos + 1] & 0x1F) + 3;
                    backOffset = (src[g_gallery->srcPos] << 3) + ((src[g_gallery->srcPos + 1] >> 5) & 7);
#ifdef DDPDOJ_PC
                    if (backOffset == 0 || backOffset > g_gallery->dstPos ||
                        copyLen > g_gallery->dstSize - g_gallery->dstPos) {
                        g_gallery->assetError = 1;
                        return 0;
                    }
                    /* Overlapping LZSS references repeat the bytes produced by this token. */
                    u8 *out = dst + g_gallery->dstPos;
                    for (s32 i = 0; i < copyLen; i++) {
                        out[i] = out[i - backOffset];
                    }
#else
                    memcpy(&dst[g_gallery->dstPos], (&dst[g_gallery->dstPos]) - backOffset, copyLen);
#endif
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

#ifdef DDPDOJ_PC
            if (g_gallery->dstPos != g_gallery->dstSize) {
                g_gallery->assetError = 1;
                return 0;
            }
#endif
            return 1;
    }

    return 0;
}

void lzss_draw_frame_overlay(GalleryBox *frame)
{
    s32 rows[2];
    s32 x;
    s32 y;
    s32 innerColumns;

    innerColumns = ((frame->x1 - frame->x0) / 16) - 2;
    rows[1] = (frame->y1 - frame->y0) / 32;
    rows[0] = rows[1] - 2;
    x = frame->x0 - 6;
    y = frame->y0 / 2;
    sprite_queue_glyph(x - 64, y, 0x2289, frame->alpha, 300);
    y += 16;
    for (rows[1] = 0; rows[1] < rows[0]; rows[1]++) {
        sprite_queue_glyph(x - 64, y, 0x228A, frame->alpha, 300);
        y += 16;
    }

    sprite_queue_glyph(x - 64, y, 0x228B, frame->alpha, 300);
    x = frame->x0 + 10;
    y = frame->y0 / 2;
    for (rows[1] = 0; rows[1] < innerColumns; rows[1]++) {
        sprite_queue_glyph(x - 64, y, 0x2287, frame->alpha, 300);
        x += 16;
    }

    x = frame->x0 + 10;
    y = (frame->y0 / 2) + ((rows[0] + 1) * 16);
    for (rows[1] = 0; rows[1] < innerColumns; rows[1]++) {
        sprite_queue_glyph(x - 64, y, 0x2288, frame->alpha, 300);
        x += 16;
    }

    x = frame->x0 + (((innerColumns + 1) * 16) - 6);
    y = frame->y0 / 2;
    sprite_queue_glyph(x - 64, y, 0x2284, frame->alpha, 300);
    y += 16;
    for (rows[1] = 0; rows[1] < rows[0]; rows[1]++) {
        sprite_queue_glyph(x - 64, y, 0x2285, frame->alpha, 300);
        y += 16;
    }

    sprite_queue_glyph(x - 64, y, 0x2286, frame->alpha, 300);
}

#ifndef DDPDOJ_PC
#include "gallery/solid_rect.inc.h"
#endif
