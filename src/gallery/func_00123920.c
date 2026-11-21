#include "common.h"

typedef struct {
    u32 data[4];
} GifPacket;

typedef struct {
    s16 u;
    s16 v;
    s16 w;
    s16 h;
    u64 tex0;
} GalleryTex;

typedef struct {
    u8 pad00[8];
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s32 alpha;
} GalleryBox;

typedef struct {
    s8 flags[6];
    s8 pad06;
    s8 zoomed;
    GalleryBox titleBox;
    GalleryBox menuBox;
    GalleryTex *tex;
    const char *title;
    s32 state;
    s32 timer;
    u8 pad58[0x10];
    s32 panX;
    s32 panY;
    s32 minX;
    s32 minY;
    s32 maxX;
    s32 maxY;
    s32 baseScale;
} GalleryView;

typedef struct {
    u8 pad00[0x505168];
    s32 showHelp;
} GlobalState;

extern const char *D_00129130[];
extern void *D_0012B318;
extern GlobalState *D_0012B3D8;
extern u8 D_00180A80[];
extern volatile u32 D_001A5020[];
extern u32 D_001A5024[];

extern void func_00100E08(s32, s32);
extern void func_00101FB0(void *, void *, s32);
extern void func_00102AC8(void *, void *);
extern void func_00102AD8(void *);
extern void func_00102AE8(void *);
extern s32 func_00102B40(void *);
extern void func_00102B58(void *, u64);
extern void func_00103220(s32);
extern s32 func_00118760(const char *);
extern void func_0011AF90(void);
extern void func_0011AFB0(void);
extern void func_0011BD30(void);
extern void func_0011C360(void);
extern void func_0011C460(s16, s16, const char *, s32, s32, s32, u16, s32);
extern void func_0011C7D0(void);
extern void func_00124C00(void *);
extern void func_00124E50(s32, s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_00123920(GalleryView *view, s32 mode) {
    GifPacket pkt;
    s32 ret;
    s32 alpha;
    s32 drawX;
    s32 drawY;
    s32 drawW;
    s32 drawH;
    s32 u;
    s32 v;
    s32 texW;
    s32 texH;
    s32 scale;
    s32 offX;
    s32 offY;
    s32 i;
    s32 bright;

    ret = 0;

    switch (mode) {
    case 2:
        if (view->state != 0) {
            break;
        }
        if (view->flags[0] && (D_001A5024[0] & 0x8)) {
            func_0011AF90();
            ret = 1;
        }
        if (view->flags[1] && (D_001A5024[0] & 0x4)) {
            func_0011AF90();
            ret = 2;
        }
        if (view->flags[4] && (D_001A5024[0] & 0x40)) {
            func_0011AFB0();
            ret = 3;
        }
        if (view->flags[2]) {
            if (D_001A5020[0] & 0x2000) {
                view->panX -= 4;
                if (view->panX < view->minX) {
                    view->panX = view->minX;
                }
            }
            if (D_001A5020[0] & 0x8000) {
                view->panX += 4;
                if (view->panX + 0x280 > view->maxX) {
                    view->panX = view->maxX - 0x280;
                }
            }
            if (D_001A5020[0] & 0x4000) {
                view->panY -= 4;
                if (view->panY < view->minY) {
                    view->panY = view->minY;
                }
            }
            if (D_001A5020[0] & 0x1000) {
                view->panY += 4;
                if (view->panY + 0x1C0 > view->maxY) {
                    view->panY = view->maxY - 0x1C0;
                }
            }
        }
        if (view->flags[3] && (D_001A5024[0] & 0x10)) {
            view->flags[2] ^= 1;
            view->zoomed ^= 1;
            view->state = 3;
            view->timer = 0x10;
            func_0011AFB0();
        }
        if (D_001A5024[0] & 0x800) {
            D_0012B3D8->showHelp ^= 1;
            view->flags[5] = D_0012B3D8->showHelp;
            if (D_0012B3D8->showHelp) {
                view->state = 4;
            } else {
                view->state = 5;
            }
            func_0011AFB0();
        }
        break;

    case 0:
        alpha = 0x80;
        u = view->tex->u;
        v = view->tex->v;
        texW = view->tex->w;
        texH = view->tex->h;

        if (view->state == 1) {
            alpha = 0x80 - view->timer;
            if (view->title != 0) {
                view->titleBox.x0 = (view->timer * 0x500) / 0x80 + 0x10;
                view->titleBox.x1 = view->titleBox.x0 + func_00118760(view->title) * 0x10;
            }
            if (view->flags[5] && view->menuBox.alpha < 0x80) {
                view->menuBox.alpha += 4;
            }
            view->timer--;
            if (view->timer <= 0) {
                view->state = 0;
                view->timer = 0;
            }
        }

        if (view->state == 2) {
            alpha = view->timer;
            view->timer--;
            if (view->timer <= 0) {
                view->timer = 0;
                ret = 1;
                view->state = 0;
            }
        }

        if (view->state == 3) {
            if (view->zoomed) {
                scale = ((0x10 - view->timer) * 0x1000 + view->baseScale * view->timer) / 0x10;
                offX = (view->panX * (0x10 - view->timer)) / 0x10;
                offY = (view->panY * (0x10 - view->timer)) / 0x10;
            } else {
                scale = (view->timer * 0x1000 + view->baseScale * (0x10 - view->timer)) / 0x10;
                offX = (view->panX * view->timer) / 0x10;
                offY = (view->panY * view->timer) / 0x10;
            }
            drawX = (offX + 0x140) - ((view->tex->w * scale) >> 13);
            drawY = (offY + 0xE0) - ((view->tex->h * scale) >> 13);
            drawW = (view->tex->w * scale) >> 12;
            drawH = (view->tex->h * scale) >> 12;
            if (--view->timer == 0) {
                view->state = 0;
            }
        } else {
            if (view->zoomed) {
                s32 scaledW = view->tex->w * 0x1000;
                s32 scaledH = view->tex->h * 0x1000;
                drawW = scaledW >> 12;
                drawX = (view->panX + 0x140) - ((view->tex->w * 0x1000) >> 13);
                drawH = scaledH >> 12;
                drawY = (view->panY + 0xE0) - ((view->tex->h * 0x1000) >> 13);
            } else {
                drawX = 0x140 - ((view->tex->w * view->baseScale) >> 13);
                drawY = 0xE0 - ((view->tex->h * view->baseScale) >> 13);
                drawW = (view->tex->w * view->baseScale) >> 12;
                drawH = (view->tex->h * view->baseScale) >> 12;
            }
        }

        func_00102AC8(&pkt, D_00180A80);
        func_00102AD8(&pkt);
        func_00102B58(&pkt, 0x1000000000008003ULL);
        func_00102B58(&pkt, 0xEULL);
        func_00102B58(&pkt, view->tex->tex0);
        func_00102B58(&pkt, 0x6ULL);
        func_00102B58(&pkt, 0ULL);
        func_00102B58(&pkt, 0x14ULL);
        func_00102B58(&pkt, 0x44ULL);
        func_00102B58(&pkt, 0x42ULL);
        func_00102B58(&pkt, 0x6400000000008001ULL);
        func_00102B58(&pkt, 0x535310ULL);
        func_00102B58(&pkt, 0x156ULL);
        func_00102B58(&pkt, ((u64)alpha << 24) | 0x3F80000000808080ULL);
        func_00102B58(&pkt, (u64)(u << 4) | ((u64)(v << 4) << 16));
        func_00102B58(&pkt, (u64)((drawX << 4) + 0x6C00) | ((u64)((drawY << 3) + 0x7900) << 16));
        func_00102B58(&pkt, (u64)((u + texW) << 4) | ((u64)((v + texH) << 4) << 16));
        func_00102B58(&pkt, (u64)(((drawX + drawW) << 4) + 0x6C00) | ((u64)(((drawY + drawH) << 3) + 0x7900) << 16));
        func_00102AE8(&pkt);
        func_00103220(0);
        func_00101FB0(D_0012B318, D_00180A80, func_00102B40(&pkt));
        func_00100E08(0, 0);

        if (view->title != 0) {
            func_00124E50(
                view->titleBox.x0,
                view->titleBox.y0,
                view->titleBox.x1,
                view->titleBox.y1,
                view->titleBox.r,
                view->titleBox.g,
                view->titleBox.b,
                (view->titleBox.a * view->titleBox.alpha) >> 7,
                0
            );
            func_0011C7D0();
            func_0011C460(
                view->titleBox.x0 - 0x38,
                view->titleBox.y0 + 4,
                view->title,
                0,
                0x18,
                0x18,
                0x80,
                0
            );
            func_0011C360();
        }
        break;

    case 1:
        if (view->state == 4) {
            view->menuBox.alpha += 4;
            if (view->menuBox.alpha == 0x80) {
                view->state = 0;
            }
        }
        if (view->state == 5) {
            view->menuBox.alpha -= 4;
            if (view->menuBox.alpha == 0) {
                view->state = 0;
            }
        }

        func_0011C7D0();
        func_00124E50(
            view->menuBox.x0 + 8,
            view->menuBox.y0 + 0x10,
            view->menuBox.x1,
            view->menuBox.y1 - 8,
            view->menuBox.r,
            view->menuBox.g,
            view->menuBox.b,
            (view->menuBox.a * view->menuBox.alpha) >> 7,
            0
        );
        func_00124C00(&view->menuBox);
        func_0011BD30();
        func_0011C7D0();

        for (i = 0; i < 6; i++) {
            bright = view->flags[i] ? 0x80 : 0x40;
            func_0011C460(
                view->menuBox.x0 - 0x28,
                view->menuBox.y0 + 0x18 + i * 0x18,
                D_00129130[i],
                0,
                0x18,
                0x18,
                (bright * view->menuBox.alpha) >> 7,
                0
            );
        }

        func_0011C360();
        break;
    }

    return ret;
}
