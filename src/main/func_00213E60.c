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

extern sceGsLoadImage D_0057C780;
extern s32 D_0028E9D0;
extern s8 *D_0028E9D8;
extern SpriteEntry D_002C0700[];
extern s8 D_00578780[];
extern GlyphCacheEntry D_00583FD8[];
extern s64 func_00212F30(s64 sjis);
extern s32 func_00217F30(u16 key);

void func_00213E60(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth)
{
    s32 cacheIndex;
    s32 uploadCount;
    GlyphCacheEntry *cache = D_00583FD8;
    s32 leadByte;
    s32 uploadOffset = 0;
    s32 glyphIndex;
    s32 byteIndex;
    s16 textureY;
    s16 textureX;
    SpriteEntry *drawEntry;

    uploadCount = 0;
    while (((leadByte = *text) != 0) && (uploadCount < 30) && (leadByte != '@')) {
        text++;
        if ((D_0028E9D0 < 512) || ((leadByte & 0xFF) != ' ')) {
            cacheIndex = func_00217F30((u16)((u8)leadByte + 0x208D));
            if (cacheIndex & 0x8000) {
                for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                    glyphIndex = (leadByte & 0xFF) + 0x208D;
                    (D_00578780 + uploadOffset)[byteIndex] = (D_0028E9D8 + glyphIndex * 0x152)[byteIndex];
                }
                cacheIndex &= 0x7FFF;
                sceGsSetDefLoadImage(&D_0057C780, 0x3800, 16, SCE_GS_PSMT4, cache[cacheIndex].x, cache[cacheIndex].y, 26, 26);
                FlushCache(0);
                sceGsExecLoadImage(&D_0057C780, D_00578780 + uploadOffset);
                uploadOffset += 0x200;
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
            drawEntry = &D_002C0700[D_0028E9D0];
            drawEntry->x = x;
            drawEntry->y = y;
            drawEntry->depth = depth;
            drawEntry->u = textureX;
            drawEntry->v = textureY;
            drawEntry->tex = texturePage;
            drawEntry->w = glyphWidth;
            drawEntry->h = glyphHeight;
            drawEntry->alpha = alpha;
            D_0028E9D0++;
        }
        x = (s16)(x + ((s16)(glyphWidth / 2)));
    }

    if (uploadCount != 0) {
        sceGsSyncPath(0, 0);
    }
}
