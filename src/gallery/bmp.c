#include "gallery/gallery.h"

typedef struct
{
    u8 unk_0[0x303000];
    u8 unk_303000[0x202154];
    s32 state;
} WorkArea;

typedef struct
{
    u32 biSize;
    u32 biWidth;
    u32 biHeight;
    u16 biPlanes;
    u16 biBitCount;
    u8 unk_10[0x20];
    u8 loadImage[0x40];
} BmpContext;

typedef struct
{
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u64 tex0;
} TexInfo;

extern u16 D_00128AE0[];
extern WorkArea *D_0012B3D8;
extern u8 *D_0012B3E4;
extern u8 *D_0012B3E8;
extern u8 *D_0012B3EC;
extern u8 *D_0012B3F0;
extern u8 *D_0012B3F4;
extern u32 D_0012B3F8;
extern u32 D_0012B3FC;
extern u8 *D_0012B400;
extern u32 D_0012B404;
extern u32 D_0012B408;
extern u32 D_0012B40C;
extern u32 D_0012B410;
extern u32 D_0012B414;
extern u8 *D_0012B418;
extern s32 D_0012B41C;
extern s32 D_0012B420;
extern u32 D_0012B424;
extern s32 D_0012B428;
extern BmpContext D_001C02B0;

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
    switch (D_0012B3D8->state) {
        case 0:
            D_0012B3E4 = bmp;
            D_0012B3E8 = bmp + 0xE;
            memcpy(&D_001C02B0, D_0012B3E8, 0x28);
            D_0012B410 = (((D_001C02B0.biWidth * D_001C02B0.biBitCount) >> 3) + 3) & (~3);
            D_0012B3EC = D_0012B3E8 + 0x28;
            D_0012B414 = D_0012B410;
            memcpy(&offBits, bmp + 0xA, 4);
            D_0012B3F0 = bmp + offBits;
            D_0012B3F0 += (D_001C02B0.biHeight - 1) * D_0012B410;
            D_0012B400 = D_0012B3D8->unk_303000;
            D_0012B3F4 = D_0012B400;
            if (D_001C02B0.biBitCount < 16) {
                D_0012B408 = (D_001C02B0.biBitCount == 4) ? (0x14) : (0x13);
                D_0012B40C = 0;
            } else {
                if (D_001C02B0.biBitCount == 16) {
                    D_0012B408 = 2;
                } else if (D_001C02B0.biBitCount == 24) {
                    D_0012B408 = 1;
                } else {
                    D_0012B408 = 0;
                }
                D_0012B40C = 0;
            }
            D_0012B428 = 0;
            D_0012B3D8->state++;
            break;

        case 1:
            switch (D_001C02B0.biBitCount) {
                case 4:
                    for (D_0012B3FC = 0; D_0012B3FC < (D_001C02B0.biHeight / 8); D_0012B3FC++) {
                        src = D_0012B3F0;
                        dst = D_0012B3F4;
                        for (D_0012B3F8 = 0; D_0012B3F8 < D_0012B410; D_0012B3F8++) {
                            *(dst++) = ((*src) << 4) | ((*src) >> 4);
                            src++;
                        }

                        D_0012B3F0 -= D_0012B410;
                        D_0012B3F4 += D_0012B414;
                    }

                    break;

                case 8:
                    for (D_0012B3FC = 0; D_0012B3FC < (D_001C02B0.biHeight / 8); D_0012B3FC++) {
                        memcpy(D_0012B3F4, D_0012B3F0, D_0012B410);
                        D_0012B3F0 -= D_0012B410;
                        D_0012B3F4 += D_0012B414;
                    }

                    break;
            }

            if ((++D_0012B428) >= 8) {
                D_0012B3D8->state++;
            }
            break;

        case 2:
            D_0012B404 = (D_001C02B0.biWidth / 64) + ((D_001C02B0.biWidth % 64) != 0);
            if (D_001C02B0.biBitCount < 16) {
                if (D_0012B404 & 1) {
                    D_0012B404++;
                }
            }
            D_0012B420 = 0;
            do {
                D_0012B420++;
                D_0012B424 = D_001C02B0.biHeight >> D_0012B420;
            } while ((D_0012B410 * D_0012B424) > 0x7FFF0);
            D_0012B41C = 0;
            D_0012B418 = D_0012B400;
            D_0012B3D8->state++;

        case 3:
            sceGsSetDefLoadImage(&D_001C02B0.loadImage, tbp, D_0012B404, D_0012B408, x, y + (D_0012B424 * D_0012B41C), D_001C02B0.biWidth, D_0012B424);
            FlushCache(0);
            sceGsExecLoadImage(&D_001C02B0.loadImage, D_0012B418);
            sceGsSyncPath(0, 0);
            D_0012B418 += ((th = (chunkHeight = D_0012B424)) * D_0012B410) & (~0xF);
            if ((++D_0012B41C) >= (1 << D_0012B420)) {
                D_0012B3D8->state++;
            }
            break;

        case 4:
            if (D_001C02B0.biBitCount < 16) {
                bmp_upload_clut(cbp, D_0012B3EC, (D_001C02B0.biBitCount == 4) ? (0x10) : (0x100));
            }
            D_0012B3D8->state++;
            break;

        case 5:
            wPow = 2;
            hPow = 2;
            tw = 1;
            th = 1;
            while ((D_001C02B0.biWidth + x) > wPow) {
                wPow <<= 1;
                tw++;
            }

            while ((D_001C02B0.biHeight + y) > hPow) {
                hPow <<= 1;
                th++;
            }

            tex->tex0 = (((((((((u64)tbp) | (((u64)D_0012B404) << 14)) | (((u64)D_0012B408) << 20)) | (((u64)tw) << 26)) | (((u64)th) << 30)) | (((u64)1) << 34)) | (((u64)cbp) << 37)) | (((u64)D_0012B40C) << 51)) | (((u64)1) << 61);
            tex->x = x;
            tex->y = y;
            tex->w = D_001C02B0.biWidth;
            tex->h = D_001C02B0.biHeight;
            return 1;
    }

    return 0;
}

void bmp_upload_clut(s16 destinationBase, const void *palette, s32 colorCount)
{
    u64 loadPacket[12];
    u8 paletteCopy[0x400];
    u8 *new_var[2];
    u8 *swizzledPalette;
    u8 *sourceColor;
    u8 *swizzledBlock;
    s32 colorIndex;
    s32 row;
    memcpy(paletteCopy, palette, colorCount * 4);
    new_var[1] = D_0012B3D8->unk_303000;
    sourceColor = paletteCopy;
    memset(new_var[1], 0, 0x400);
    new_var[0] = new_var[1];
    for (colorIndex = 0; colorIndex < colorCount; colorIndex++, sourceColor += 4) {
        if ((sourceColor[2] || sourceColor[1]) || sourceColor[0]) {
            new_var[0][0] = sourceColor[2];
            new_var[0][1] = sourceColor[1];
            new_var[0][2] = sourceColor[0];
            new_var[0][3] = 0x80;
            new_var[0] += 4;
        } else {
            new_var[0] += 4;
        }
    }

    swizzledPalette = D_0012B3D8->unk_303000 + 0x400;
    row = 0;
    swizzledBlock = swizzledPalette;
    do {
        memcpy(swizzledBlock, new_var[1], 0x20);
        memcpy(swizzledBlock + 0x20, new_var[1] + 0x40, 0x20);
        memcpy(swizzledBlock + 0x40, new_var[1] + 0x20, 0x20);
        memcpy(swizzledBlock + 0x60, new_var[1] + 0x60, 0x20);
        row += 2;
        swizzledBlock += 0x80;
        new_var[1] += 0x80;
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

    firstGlyph = D_00128AE0[glyphIndex];
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
