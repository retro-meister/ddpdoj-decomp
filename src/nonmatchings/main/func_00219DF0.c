#include "gallery/gallery.h"

extern s32 func_002180A0(u16 key);
extern s16 D_0028E234;
extern s16 D_0028E238;
extern s32 D_0028EA80;
extern u8 D_002C4F80[];
extern sceGsLoadImage D_0057C780;
extern GlyphCacheEntry D_0057EF98[];
extern s32 D_00587000[];
extern u32 D_005C4C80[];
extern s16 D_00592000[];
extern s16 D_00592002[];
extern s16 D_00592008[];
extern s16 D_0059200A[];
extern s16 D_00592010[];
extern s16 D_00592012[];
extern s16 D_00592018[];
extern s16 D_0059201A[];
extern s16 D_00592020[];
extern s32 D_00592024[];
extern s32 D_00592028[];
extern s16 D_0059202C[];
extern s16 D_0059202E[];
extern s16 D_00592030[];

void func_00219DF0(s32 col, s32 row) {
    s32 uploads;
    GlyphCacheEntry *cache;
    s32 u;
    s32 palette;
    s32 key;
    s32 n;
    s32 slot;
    s32 v;
    s32 x;
    s32 y;
    u32 *src;
    u32 *dst;
    s32 out;
    s32 in;
    u32 word;
    u32 fill;
    s32 count;

    uploads = 0;
    cache = D_0057EF98;
    x = -(D_0028E238 & 0x1F);
    y = -D_0028E234;
    x += col << 5;
    y += row << 5;
    palette = (reg_d0.h[0] & 0x3F) >> 1;
    key = reg_d0.h[1] & 0x1FFF;
    n = D_0028EA80;
    slot = func_002180A0(key);
    if (slot & 0x8000) {
        slot &= 0x7FFF;
        u = cache[slot].x;
        v = cache[slot].y;
        sceGsSetDefLoadImage(&D_0057C780, 0x1A40, 8, SCE_GS_PSMT8, u, v, 32, 32);
        FlushCache(0);
        out = 0;
        in = 0;
        dst = D_005C4C80;
        src = (u32 *)(D_002C4F80 + D_00587000[key]);
        if (!(src[0] & 0x80000000)) {
            FlushCache(0);
            sceGsExecLoadImage(&D_0057C780, src);
            sceGsSyncPath(0, 0);
        } else {
            do {
                fill = src[in++];
                word = fill;
                if (!(word & 0x40000000)) {
                    dst[out++] = word & 0x1F1F1F1F;
                } else {
                    fill = src[in++] & 0x1F1F1F1F;
                    for (count = word & 0x3FFF; count >= 0; count--) {
                        dst[out++] = fill;
                    }
                }
            } while (out < 0x100);
            FlushCache(0);
            sceGsExecLoadImage(&D_0057C780, dst);
            sceGsSyncPath(0, 0);
        }
        uploads++;
    } else {
        u = cache[slot & 0x7FFF].x;
        v = cache[slot & 0x7FFF].y;
    }
    D_00592020[n * 26] = 1;
    D_0059202E[n * 26] = 0x80;
    D_00592024[n * 13] = 0x1A40;
    D_0059202C[n * 26] = 1;
    D_00592028[n * 13] = palette * 4 + 0x36B0;
    D_00592030[n * 26] = 0x80;
    D_00592000[n * 26] = x;
    D_00592008[n * 26] = y;
    D_00592002[n * 26] = x + 32;
    D_0059200A[n * 26] = y + 32;
    D_00592010[n * 26] = u;
    D_00592018[n * 26] = v;
    D_00592012[n * 26] = u + 32;
    D_0059201A[n * 26] = v + 32;
    D_0028EA80 = n + 1;
    if (uploads != 0) {
        sceGsSyncPath(0, 0);
    }
}
