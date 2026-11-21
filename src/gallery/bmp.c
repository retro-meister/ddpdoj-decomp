#include "gallery/gallery.h"

typedef struct
{
    u32 biSize;
    u32 biWidth;
    u32 biHeight;
    u16 biPlanes;
    u16 biBitCount;
    u8 unk_10[0x20];
    u8 loadImage[0x60];
} BmpContext;

typedef struct
{
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u64 tex0;
} TexInfo;

extern u16 g_ascii_glyph_table[];
extern u8 *g_bmp_file_ptr;
extern u8 *g_bmp_info_ptr;
extern u8 *g_bmp_palette_ptr;
extern u8 *g_bmp_src_row;
extern u8 *g_bmp_dst_row;
extern u32 g_bmp_col;
extern u32 g_bmp_row;
extern u8 *g_bmp_pixel_buf;
extern u32 g_bmp_tbw;
extern u32 g_bmp_psm;
extern u32 g_bmp_cpsm;
extern u32 g_bmp_src_stride;
extern u32 g_bmp_dst_stride;
extern u8 *g_bmp_upload_ptr;
extern s32 g_bmp_chunk_idx;
extern s32 g_bmp_chunk_shift;
extern u32 g_bmp_chunk_height;
extern s32 g_bmp_decode_pass;
extern BmpContext g_bmp_ctx;

s32 bmp_upload_texture(void *texPtr, s16 tbp, s16 cbp, u8 *bmp, s32 x, s32 y)
{
    TexInfo *tex = texPtr;
    u32 offBits;
    u32 wPow;
    u32 hPow;
    u32 tw;
    u32 th;
    u8 *src;
    u8 *dst;
    u64 chunkHeight;
    switch (g_gallery->stepState) {
        case 0:
            g_bmp_file_ptr = bmp;
            g_bmp_info_ptr = bmp + 0xE;
            memcpy(&g_bmp_ctx, g_bmp_info_ptr, 0x28);
            g_bmp_src_stride = (((g_bmp_ctx.biWidth * g_bmp_ctx.biBitCount) >> 3) + 3) & (~3);
            g_bmp_palette_ptr = g_bmp_info_ptr + 0x28;
            g_bmp_dst_stride = g_bmp_src_stride;
            memcpy(&offBits, bmp + 0xA, 4);
            g_bmp_src_row = bmp + offBits;
            g_bmp_src_row += (g_bmp_ctx.biHeight - 1) * g_bmp_src_stride;
            g_bmp_pixel_buf = g_gallery->bmpScratchBuf;
            g_bmp_dst_row = g_bmp_pixel_buf;
            if (g_bmp_ctx.biBitCount < 16) {
                g_bmp_psm = (g_bmp_ctx.biBitCount == 4) ? SCE_GS_PSMT4 : SCE_GS_PSMT8;
                g_bmp_cpsm = SCE_GS_PSMCT32;
            } else {
                if (g_bmp_ctx.biBitCount == 16) {
                    g_bmp_psm = SCE_GS_PSMCT16;
                } else if (g_bmp_ctx.biBitCount == 24) {
                    g_bmp_psm = SCE_GS_PSMCT24;
                } else {
                    g_bmp_psm = SCE_GS_PSMCT32;
                }
                g_bmp_cpsm = SCE_GS_PSMCT32;
            }
            g_bmp_decode_pass = 0;
            g_gallery->stepState++;
            break;

        case 1:
            switch (g_bmp_ctx.biBitCount) {
                case 4:
                    for (g_bmp_row = 0; g_bmp_row < (g_bmp_ctx.biHeight / 8); g_bmp_row++) {
                        src = g_bmp_src_row;
                        dst = g_bmp_dst_row;
                        for (g_bmp_col = 0; g_bmp_col < g_bmp_src_stride; g_bmp_col++) {
                            *(dst++) = ((*src) << 4) | ((*src) >> 4);
                            src++;
                        }

                        g_bmp_src_row -= g_bmp_src_stride;
                        g_bmp_dst_row += g_bmp_dst_stride;
                    }

                    break;

                case 8:
                    for (g_bmp_row = 0; g_bmp_row < (g_bmp_ctx.biHeight / 8); g_bmp_row++) {
                        memcpy(g_bmp_dst_row, g_bmp_src_row, g_bmp_src_stride);
                        g_bmp_src_row -= g_bmp_src_stride;
                        g_bmp_dst_row += g_bmp_dst_stride;
                    }

                    break;
            }

            if ((++g_bmp_decode_pass) >= 8) {
                g_gallery->stepState++;
            }
            break;

        case 2:
            g_bmp_tbw = (g_bmp_ctx.biWidth / 64) + ((g_bmp_ctx.biWidth % 64) != 0);
            if (g_bmp_ctx.biBitCount < 16) {
                if (g_bmp_tbw & 1) {
                    g_bmp_tbw++;
                }
            }
            g_bmp_chunk_shift = 0;
            do {
                g_bmp_chunk_shift++;
                g_bmp_chunk_height = g_bmp_ctx.biHeight >> g_bmp_chunk_shift;
            } while ((g_bmp_src_stride * g_bmp_chunk_height) > 0x7FFF0);
            g_bmp_chunk_idx = 0;
            g_bmp_upload_ptr = g_bmp_pixel_buf;
            g_gallery->stepState++;

        case 3:
            sceGsSetDefLoadImage(&g_bmp_ctx.loadImage, tbp, g_bmp_tbw, g_bmp_psm, x, y + (g_bmp_chunk_height * g_bmp_chunk_idx), g_bmp_ctx.biWidth, g_bmp_chunk_height);
            FlushCache(0);
            sceGsExecLoadImage(&g_bmp_ctx.loadImage, g_bmp_upload_ptr);
            sceGsSyncPath(0, 0);
            g_bmp_upload_ptr += ((th = (chunkHeight = g_bmp_chunk_height)) * g_bmp_src_stride) & (~0xF);
            if ((++g_bmp_chunk_idx) >= (1 << g_bmp_chunk_shift)) {
                g_gallery->stepState++;
            }
            break;

        case 4:
            if (g_bmp_ctx.biBitCount < 16) {
                bmp_upload_clut(cbp, g_bmp_palette_ptr, (g_bmp_ctx.biBitCount == 4) ? (0x10) : (0x100));
            }
            g_gallery->stepState++;
            break;

        case 5:
            wPow = 2;
            hPow = 2;
            tw = 1;
            th = 1;
            while ((g_bmp_ctx.biWidth + x) > wPow) {
                wPow <<= 1;
                tw++;
            }

            while ((g_bmp_ctx.biHeight + y) > hPow) {
                hPow <<= 1;
                th++;
            }

            tex->tex0 = SCE_GS_SET_TEX0(tbp, g_bmp_tbw, g_bmp_psm, tw, th, 1, 0, cbp, g_bmp_cpsm, 0, 0, 1);
            tex->x = x;
            tex->y = y;
            tex->w = g_bmp_ctx.biWidth;
            tex->h = g_bmp_ctx.biHeight;
            return 1;
    }

    return 0;
}

void bmp_upload_clut(s16 destinationBase, const void *palette, s32 colorCount)
{
    u64 loadPacket[12];
    u8 paletteCopy[0x400];
    u8 *clutPtrs[2];
    u8 *swizzledPalette;
    u8 *sourceColor;
    u8 *swizzledBlock;
    s32 colorIndex;
    s32 row;
    memcpy(paletteCopy, palette, colorCount * 4);
    clutPtrs[1] = g_gallery->bmpScratchBuf;
    sourceColor = paletteCopy;
    memset(clutPtrs[1], 0, 0x400);
    clutPtrs[0] = clutPtrs[1];
    for (colorIndex = 0; colorIndex < colorCount; colorIndex++, sourceColor += 4) {
        if ((sourceColor[2] || sourceColor[1]) || sourceColor[0]) {
            clutPtrs[0][0] = sourceColor[2];
            clutPtrs[0][1] = sourceColor[1];
            clutPtrs[0][2] = sourceColor[0];
            clutPtrs[0][3] = 0x80;
            clutPtrs[0] += 4;
        } else {
            clutPtrs[0] += 4;
        }
    }

    swizzledPalette = g_gallery->bmpScratchBuf + 0x400;
    row = 0;
    swizzledBlock = swizzledPalette;
    do {
        memcpy(swizzledBlock, clutPtrs[1], 0x20);
        memcpy(swizzledBlock + 0x20, clutPtrs[1] + 0x40, 0x20);
        memcpy(swizzledBlock + 0x40, clutPtrs[1] + 0x20, 0x20);
        memcpy(swizzledBlock + 0x60, clutPtrs[1] + 0x60, 0x20);
        row += 2;
        swizzledBlock += 0x80;
        clutPtrs[1] += 0x80;
    } while (row < 16);
    sceGsSetDefLoadImage(loadPacket, destinationBase, 1, 0, 0, 0, 16, 16);
    FlushCache(0);
    sceGsExecLoadImage(loadPacket, (0, swizzledPalette));
    sceGsSyncPath(0, 0);
}

void bmp_draw_ascii_char(void *packet, s32 x, s32 y, u8 glyphIndex)
{
    u16 glyphs[2];
    u16 firstGlyph;
    u16 *glyph;
    s32 row;
    s32 screenTop;
    s64 screenLeft;
    s64 screenRight;

    firstGlyph = g_ascii_glyph_table[glyphIndex];
    glyphs[0] = firstGlyph;
    glyphs[1] = firstGlyph + 16;

    sceGifPkAddGsData(packet, 0xA400000000008002ULL);
    sceGifPkAddGsData(packet, 0x0000005353535310ULL);

    glyph = glyphs;
    row = 0;
    screenTop = y * 8 + 0x7900;
    screenLeft = x * 16 + 0x6C00;
    screenRight = (x + 16) * 16 + 0x6C00;

    for (; row < 2; row++, screenTop += 64, glyph++, y += 8) {
        s32 tile = *glyph;
        s32 textureLeft = (tile % 126 + 1) * 8;
        s32 textureTop = (tile / 126 + 1) * 8;

        sceGifPkAddGsData(packet, 0x115, tile);
        sceGifPkAddGsData(packet, 0x3F80000080808080ULL);
        sceGifPkAddGsData(packet, (u64)(s64)((textureLeft + 7) * 16) |
                              ((u64)(s64)(textureTop * 16) << 16));
        sceGifPkAddGsData(packet, (u64)screenLeft |
                              ((u64)(s64)screenTop << 16));
        sceGifPkAddGsData(packet, (u64)(s64)((textureLeft + 7) * 16) |
                              ((u64)(s64)((textureTop + 7) * 16) << 16));
        sceGifPkAddGsData(packet, (u64)screenRight |
                              ((u64)(s64)screenTop << 16));
        sceGifPkAddGsData(packet, (u64)(s64)(textureLeft * 16) |
                              ((u64)(s64)((textureTop + 7) * 16) << 16));
        sceGifPkAddGsData(packet, (u64)screenRight |
                              ((u64)(s64)((y + 8) * 8 + 0x7900) << 16));
        sceGifPkAddGsData(packet, (u64)(s64)(textureLeft * 16) |
                              ((u64)(s64)(textureTop * 16) << 16));
        sceGifPkAddGsData(packet, (u64)screenLeft |
                              ((u64)(s64)((y + 8) * 8 + 0x7900) << 16));
    }
}

s32 g_bmp_decode_pass;
u32 g_bmp_chunk_height;
s32 g_bmp_chunk_shift;
s32 g_bmp_chunk_idx;
u8 *g_bmp_upload_ptr;
u32 g_bmp_dst_stride;
u32 g_bmp_src_stride;
u32 g_bmp_cpsm;
u32 g_bmp_psm;
u32 g_bmp_tbw;
u8 *g_bmp_pixel_buf;
u32 g_bmp_row;
u32 g_bmp_col;
u8 *g_bmp_dst_row;
u8 *g_bmp_src_row;
u8 *g_bmp_palette_ptr;
u8 *g_bmp_info_ptr;
u8 *g_bmp_file_ptr;
BmpContext g_bmp_ctx;
