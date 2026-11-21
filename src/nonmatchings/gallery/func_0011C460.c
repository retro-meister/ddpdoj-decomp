#include "common.h"

typedef struct {
    s16 previous;
    s16 next;
    s16 key;
    s16 x;
    s16 y;
    s16 flags;
} GlyphCacheEntry;

typedef struct {
    s16 x;
    s16 y;
    u16 depth;
    s16 textureX;
    s16 textureY;
    u16 texturePage;
    u16 width;
    u16 height;
    u16 alpha;
} GlyphDrawEntry;

extern s32 D_0012B308;
extern s8 *D_0012B30C;
extern GlyphDrawEntry D_00132E80[];
extern s8 D_001A0A80[];
extern u64 D_001A4A80[12];
extern GlyphCacheEntry D_001AC298[];

extern s32 func_00100E08(s32 mode, s32 timeout);
extern s32 func_00101120(void *packet, s16 base, s16 bufferWidth, s16 format,
                         s16 x, s16 y, s16 width, s16 height);
extern s32 func_00101308(void *packet, const void *pixels);
extern void func_00103220(s32 mode);
extern u64 func_0011C8B0(u64 shiftJis);
extern s32 func_0011EC80(u16 key);

void func_0011C460(s32 x, s16 y, const char *text, u16 texturePage,
                   u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth)
{
    s32 uploadCount = 0;
    s8 *uploadBuffer = D_001A0A80;
    GlyphCacheEntry *cache = D_001AC298;
    s32 leadByte;
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
    GlyphDrawEntry *drawEntry;

    while ((leadByte = *text) != 0 && uploadCount < 30) {
        shiftJis = (s8)leadByte;
        shiftJis = ((shiftJis & 0xFF) << 8) | (u8)text[1];
        text += 2;
        if (shiftJis == 0x818F) {
            break;
        }

        if (D_0012B308 < 512 || shiftJis != 0x8140) {
            jis = func_0011C8B0((s64)shiftJis);
            row = ((jis >> 8) - 0x21) * 94;
            col = (jis & 0xFF) - 0x21;
            glyphIndex = (s32)(row + col);
            cacheIndex = func_0011EC80((u16)glyphIndex);

            if (cacheIndex & 0x8000) {
                bitmapOffset = glyphIndex * 0x152;
                for (byteIndex = 0; byteIndex < 0x14A; byteIndex += 8) {
                    uploadBuffer[byteIndex + 0] = (D_0012B30C + bitmapOffset + byteIndex)[0];
                    uploadBuffer[byteIndex + 1] = (D_0012B30C + bitmapOffset + byteIndex)[1];
                    uploadBuffer[byteIndex + 2] = (D_0012B30C + bitmapOffset + byteIndex)[2];
                    uploadBuffer[byteIndex + 3] = (D_0012B30C + bitmapOffset + byteIndex)[3];
                    uploadBuffer[byteIndex + 4] = (D_0012B30C + bitmapOffset + byteIndex)[4];
                    uploadBuffer[byteIndex + 5] = (D_0012B30C + bitmapOffset + byteIndex)[5];
                    uploadBuffer[byteIndex + 6] = (D_0012B30C + bitmapOffset + byteIndex)[6];
                    uploadBuffer[byteIndex + 7] = (D_0012B30C + bitmapOffset + byteIndex)[7];
                }
                uploadBuffer[byteIndex + 0] = (D_0012B30C + bitmapOffset + byteIndex)[0];
                uploadBuffer[byteIndex + 1] = (D_0012B30C + bitmapOffset + byteIndex)[1];

                cacheIndex &= 0x7FFF;
                func_00101120(D_001A4A80, 0x3800, 16, 20,
                              cache[cacheIndex].x, cache[cacheIndex].y, 26, 26);
                func_00103220(0);
                func_00101308(D_001A4A80, uploadBuffer);
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

            drawEntry = &D_00132E80[D_0012B308];
            drawEntry->x = x;
            drawEntry->y = y;
            drawEntry->depth = depth;
            drawEntry->textureX = textureX;
            drawEntry->textureY = textureY;
            drawEntry->texturePage = texturePage;
            drawEntry->width = glyphWidth;
            drawEntry->height = glyphHeight;
            drawEntry->alpha = alpha;
            D_0012B308++;
        }

        x = (s16)(x + (s16)glyphWidth);
    }

    if (uploadCount != 0) {
        func_00100E08(0, 0);
    }
}
