#include "common.h"

#pragma opt_propagation off

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
extern GlyphQuad D_00592000[];

void func_00219A80(s32 arg0, s32 arg1) {
    s32 n;
    s32 u;
    s32 v;
    s32 x;
    s32 y;
    s32 code;
    s32 flip;

    n = D_0028EA80;
    x = arg0 * 8;
    y = arg1 * 8;
    flip = (reg_d0.h[0] >> 6) & 3;
    code = reg_d0.h[1] & 0x1FFF;
    u = (code % 126 + 1) * 8;
    v = (code / 126 + 1) * 8;
    D_00592000[n].z = 0x14;
    D_00592000[n].attr = 0x80;
    D_00592000[n].tex = 0x1E40;
    D_00592000[n].flags = 0;
    D_00592000[n].clut = ((reg_d0.h[0] & 0x3F) >> 1) + 0x37B0;
    D_00592000[n].alpha = 0x80;
    D_00592000[n].x0 = x - 1;
    D_00592000[n].y0 = y;
    D_00592000[n].x1 = x + 7;
    D_00592000[n].y1 = y + 8;
    switch (flip) {
    case 0:
        D_00592000[n].u0 = u;
        D_00592000[n].v0 = v;
        D_00592000[n].u1 = u + 8;
        D_00592000[n].v1 = v + 8;
        break;
    case 1:
        D_00592000[n].u0 = u + 8;
        D_00592000[n].v0 = v;
        D_00592000[n].u1 = u;
        D_00592000[n].v1 = v + 8;
        break;
    case 2:
        D_00592000[n].u0 = u;
        D_00592000[n].v0 = v + 8;
        D_00592000[n].u1 = u + 8;
        D_00592000[n].v1 = v;
        break;
    case 3:
        D_00592000[n].u0 = u + 8;
        D_00592000[n].v0 = v + 8;
        D_00592000[n].u1 = u;
        D_00592000[n].v1 = v;
        break;
    }
    D_0028EA80++;
}
