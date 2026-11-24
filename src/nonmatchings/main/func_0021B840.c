#include "common.h"

typedef struct {
    s32 offset;
    s16 w;
    s16 h;
} ClutEntry;

extern s32 FlushCache(s32 op);
extern void func_00218990(u16 *clut, s32 a, s32 b);
extern s32 sceGsExecLoadImage(u8 *lp, u32 *src);
extern s32 sceGsSetDefLoadImage(u8 *lp, s16 dbp, s16 dbw, s16 dpsm, s16 x, s16 y, s16 w, s16 h);
extern s32 D_0028EA78;
extern u8 *D_0028EAA0;
extern ClutEntry *D_0028EAA4;
extern u8 D_0057C780[];
extern u16 D_0058C800[];
extern u32 D_005C4C80[];

void func_0021B840(s32 index, u16 *src) {
    s32 n;
    s32 i;
    u32 *data;
    s32 word;
    s16 w;
    s16 h;
    s32 row;
    u16 *dst;
    u32 *buf;
    u32 fill;

    n = 0;
    i = 0;
    buf = D_005C4C80;
    w = D_0028EAA4[index].w;
    h = D_0028EAA4[index].h;
    data = (u32 *)(D_0028EAA0 + D_0028EAA4[index].offset);
    if (!(data[0] & 0x80000000)) {
        sceGsSetDefLoadImage(D_0057C780, 0x16C0, 8, 0x13, 16, 16, w, h);
        FlushCache(0);
        sceGsExecLoadImage(D_0057C780, data);
    } else {
        do {
            word = data[i++];
            if (!(word & 0x40000000)) {
                buf[n++] = word & 0x1F1F1F1F;
            } else {
                word &= 0x3FFF;
                fill = data[i++] & 0x1F1F1F1F;
                for (; word >= 0; word--) {
                    buf[n++] = fill;
                }
            }
        } while (n < w * h / 4);
        sceGsSetDefLoadImage(D_0057C780, 0x16C0, 8, 0x13, 16, 16, w, h);
        FlushCache(0);
        sceGsExecLoadImage(D_0057C780, buf);
    }
    row = 0;
    dst = D_0058C800;
    do {
        row++;
        dst[0] = src[0] | 0x8000;
        dst[1] = src[1] | 0x8000;
        dst[2] = src[2] | 0x8000;
        dst[3] = src[3] | 0x8000;
        dst[4] = src[4] | 0x8000;
        dst[5] = src[5] | 0x8000;
        dst[6] = src[6] | 0x8000;
        dst[7] = src[7] | 0x8000;
        dst[16] = src[8] | 0x8000;
        dst[17] = src[9] | 0x8000;
        dst[18] = src[10] | 0x8000;
        dst[19] = src[11] | 0x8000;
        dst[20] = src[12] | 0x8000;
        dst[21] = src[13] | 0x8000;
        dst[22] = src[14] | 0x8000;
        dst[23] = src[15] | 0x8000;
        src += 16;
        dst += 8;
    } while (row < 2);
    D_0028EA78 = 0x18C0;
    func_00218990(D_0058C800, 1, 1);
}
