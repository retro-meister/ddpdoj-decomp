#include "common.h"

#pragma opt_propagation off

typedef struct {
    s16 x;
    s16 y;
    s16 page;
    s16 code;
    s16 z;
    s16 attr;
    u16 alpha;
    s16 pad;
} GlyphEntry;

typedef struct {
    s16 x0;
    s16 x1;
    s16 pad04[2];
    s16 y0;
    s16 y1;
    s16 pad0C[2];
    s16 u0;
    s16 u1;
    s16 pad14[2];
    s16 v0;
    s16 v1;
    s16 pad1C[2];
    s16 z;
    s16 pad22;
    s32 tex;
    s32 clut;
    s16 flags;
    s16 attr;
    u16 alpha;
    s16 pad32;
} GlyphQuad;

extern s32 D_0028EA80;
extern GlyphEntry D_0058E000[];
extern GlyphQuad D_00592000[];

void func_0021C350(s32 index) {
    s32 n;
    s32 u;
    s32 v;
    s32 x;
    s32 y;

    n = D_0028EA80;
    x = D_0058E000[index].x;
    y = D_0058E000[index].y;
    u = (D_0058E000[index].code % 126 + 1) * 8;
    v = (D_0058E000[index].code / 126 + 1) * 8;
    D_00592000[n].z = D_0058E000[index].z;
    D_00592000[n].attr = D_0058E000[index].attr;
    D_00592000[n].tex = 0x1E40;
    D_00592000[n].flags = 0;
    D_00592000[n].clut = 0x3830;
    D_00592000[n].alpha = D_0058E000[index].alpha;
    D_00592000[n].x0 = x;
    D_00592000[n].y0 = y;
    D_00592000[n].x1 = x + 8;
    D_00592000[n].y1 = y + 8;
    D_00592000[n].u0 = u;
    D_00592000[n].v0 = v;
    D_00592000[n].u1 = u + 8;
    D_00592000[n].v1 = v + 8;
    D_0028EA80 = n + 1;
}
