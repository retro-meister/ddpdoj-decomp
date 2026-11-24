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
extern s32 D_0028E9D4;
extern s8 *D_0028E9D8;
extern SpriteEntry D_002C2B00[];
extern s8 D_00578780[];
extern GlyphCacheEntry D_00583FD8[];
extern s32 func_00217F30(u16 key);

void func_00213640(x, y, textureId, texturePage, glyphWidth, glyphHeight, alpha, depth)
    s16 x;
    s16 y;
    u16 textureId;
    u16 texturePage;
    u16 glyphWidth;
    u16 glyphHeight;
    u16 alpha;
    u16 depth;
{
    s32 id = textureId;
    s32 textureIndex;
    s32 uploadOffset = 0;
    GlyphCacheEntry *textures = D_00583FD8;

    if (D_0028E9D4 < 0x200) {
        s32 queueIndex;
        s16 height;
        s16 width;

        textureIndex = func_00217F30((u16)id);
        if (textureIndex & 0x8000) {
            s32 byteIndex;

            for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                (D_00578780 + uploadOffset)[byteIndex] = (D_0028E9D8 + id * 0x152)[byteIndex];
            }

            textureIndex &= 0x7FFF;
            width = textures[textureIndex].x;
            sceGsSetDefLoadImage(&D_0057C780, 0x3800, 0x10, SCE_GS_PSMT4,
                          width,
                          textures[textureIndex].y, 0x1A, 0x1A);
            FlushCache(0);
            sceGsExecLoadImage(&D_0057C780, D_00578780);
        }

        width = textures[textureIndex & 0x7FFF].x;
        height = textures[textureIndex & 0x7FFF].y;
        if (glyphWidth == 0) {
            glyphWidth = 26;
            glyphHeight = glyphWidth;
        }
        if (depth == 0) {
            depth = 1;
        }

        queueIndex = D_0028E9D4;
        D_002C2B00[queueIndex].x = x;
        D_002C2B00[queueIndex].y = y;
        D_002C2B00[queueIndex].depth = depth;
        D_002C2B00[queueIndex].u = width;
        D_002C2B00[queueIndex].v = height;
        D_002C2B00[queueIndex].tex = texturePage;
        D_002C2B00[queueIndex].w = glyphWidth;
        D_002C2B00[queueIndex].h = glyphHeight;
        D_002C2B00[queueIndex].alpha = alpha;
        D_0028E9D4++;
    }
}
