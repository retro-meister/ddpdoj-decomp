#include "gallery/gallery.h"

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

extern s32 func_002180A0(u16 key);
extern s16 D_0028E234;
extern s16 D_0028E238;
extern s32 D_0028EA80;
extern u8 D_002C4F80[];
extern sceGsLoadImage D_0057C780;
extern GlyphCacheEntry D_0057EF98[];
extern s32 D_00587000[];
extern u32 D_005C4C80[];
extern TileEntry D_00592000[];

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
    x = D_0028E238 & 0x1F;
    x *= -1;
    y = -D_0028E234;
    x += col * 32;
    y += row * 32;
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
                    count = word & 0x3FFF;
                    fill = src[in++] & 0x1F1F1F1F;
                    for (; count >= 0; count--) {
                        dst[out++] = fill;
                    }
                }
            } while (out < 32 * 32 / 4);
            FlushCache(0);
            sceGsExecLoadImage(&D_0057C780, dst);
            sceGsSyncPath(0, 0);
        }
        uploads++;
    } else {
        u = cache[slot & 0x7FFF].x;
        v = cache[slot & 0x7FFF].y;
    }
    D_00592000[n].z = 1;
    D_00592000[n].alpha = 0x80;
    D_00592000[n].tbp = 0x1A40;
    D_00592000[n].mode = 1;
    D_00592000[n].cbp = palette * 4 + 0x36B0;
    D_00592000[n].color = 0x80;
    D_00592000[n].x[0] = x;
    D_00592000[n].y[0] = y;
    D_00592000[n].x[1] = x + 32;
    D_00592000[n].y[1] = y + 32;
    D_00592000[n].u[0] = u;
    D_00592000[n].v[0] = v;
    D_00592000[n].u[1] = u + 32;
    D_00592000[n].v[1] = v + 32;
    D_0028EA80 = n + 1;
    if (uploads != 0) {
        sceGsSyncPath(0, 0);
    }
}
