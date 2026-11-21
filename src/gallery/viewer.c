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
    u32 dispX;
    u32 dispY;
    u32 dispW;
    u32 dispH;
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

typedef struct {
    s32 selection;
    s32 selectionCount;
    s32 movementSteps[5];
    s32 actionEnabled[5];
    s32 heldFrames;
} GalleryMenuState;

typedef struct {
    u8 reserved[0x20];
    u32 heldButtons;
    u32 pressedButtons;
} GalleryMenuInput;

extern const char *D_00129130[];
extern u16 D_0012AFE0[8];
extern u16 D_0012AFF0[8];
extern const char D_0012B158[];
extern const char D_0012B160[];
extern const char D_0012B168[];
extern void *D_0012B318;
extern GlobalState *D_0012B3D8;
extern s32 D_0012B3DC;
extern s32 D_0012B3E0;
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
extern void *func_00117060(void *dst, s32 val, u32 size);
extern s32 func_00118760(const char *);
extern void func_0011AF90(void);
extern void func_0011AFB0(void);
extern void func_0011BD30(void);
extern void func_0011C360(void);
extern void func_0011C460(s16 x, s16 y, const char *text, s32 style,
                          u16 glyphWidth, u16 glyphHeight, u16 intensity, s32 flags);
extern void func_0011C7D0(void);
extern void func_00124C00(void *);
extern void func_00124E50(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_001236D0(s32 selection, s32 centerX, s32 y, s32 spacing)
{
    s32 highlightOffset;
    s32 glyphSize;

    if (selection < 0) {
        if (selection == -1) {
            D_0012B3DC = 1;
        } else {
            D_0012B3DC = 0;
        }
        D_0012B3E0 = 4;
        return;
    }

    if (D_0012B3DC != selection) {
        D_0012B3DC = selection;
        D_0012B3E0 = 0;
    }

    if (D_0012B3E0 < 4) {
        D_0012B3E0 += 2;
    }

    highlightOffset = 0;
    if (D_0012B3E0 != 0) {
        highlightOffset = D_0012B3E0 / 2;
    }
    glyphSize = D_0012B3E0 + 24;

    func_0011C7D0();

    if (D_0012B3DC == 0) {
        func_0011C460((s16)(centerX - spacing - 100 - highlightOffset),
                      (s16)(y - highlightOffset), D_0012B158, 4,
                      (u16)glyphSize, (u16)glyphSize, 128, 0);
        func_0011C460((s16)(centerX - 88), (s16)y, D_0012B160, 0, 24, 24, 128, 0);
        func_0011C460((s16)(centerX + spacing - 100), (s16)y,
                      D_0012B168, 0, 24, 24, 128, 0);
    } else {
        func_0011C460((s16)(centerX - spacing - 100), (s16)y,
                      D_0012B158, 0, 24, 24, 128, 0);
        func_0011C460((s16)(centerX - 88), (s16)y, D_0012B160, 0, 24, 24, 128, 0);
        func_0011C460((s16)(centerX + spacing - 100 - highlightOffset),
                      (s16)(y - highlightOffset), D_0012B168, 4,
                      (u16)glyphSize, (u16)glyphSize, 128, 0);
    }

    func_0011C360();
}

s32 func_00123920(GalleryView *view, s32 mode)
{
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

void func_00124280(GalleryView *viewer, GalleryTex *image, const char *title)
{
    func_00117060(viewer, 0, sizeof(GalleryView));

    viewer->tex = image;
    viewer->title = title;
    viewer->state = 1;
    viewer->timer = 0x80;
    viewer->flags[0] = 1;
    viewer->flags[1] = 1;
    viewer->flags[2] = 0;
    viewer->flags[3] = 0;
    viewer->flags[4] = 1;
    viewer->flags[5] = D_0012B3D8->showHelp;
    viewer->zoomed = 0;

    if (viewer->title != 0) {
        viewer->titleBox.y0 = 0x10;
        viewer->titleBox.x0 = 0x10;
        viewer->titleBox.x1 = func_00118760(title) * 0x10 + 0x10;
        viewer->titleBox.y1 = 0x30;
        viewer->titleBox.r = 0x36;
        viewer->titleBox.g = 0xCD;
        viewer->titleBox.b = 0x18;
        viewer->titleBox.a = 0x25;
        viewer->titleBox.alpha = 0x80;
    }

    viewer->menuBox.x0 = 0x90;
    viewer->menuBox.x1 = 0x1F0;
    viewer->menuBox.y0 = 0x80;
    viewer->menuBox.y1 = 0x140;
    viewer->menuBox.r = 1;
    viewer->menuBox.g = 1;
    viewer->menuBox.b = 0x40;
    viewer->menuBox.a = 0x40;
    if (viewer->flags[5] != 0) {
        viewer->menuBox.alpha = 0x80;
    }

    viewer->dispW = viewer->tex->w;
    viewer->dispH = viewer->tex->h;
    if (viewer->dispW > 640 || viewer->dispH > 448) {
        f32 ratioX = (f32)viewer->dispW / 640.0f;
        f32 ratioY = (f32)viewer->dispH / 448.0f;

        if (ratioX > ratioY) {
            viewer->dispW = 640;
            viewer->dispH = (u32)((f32)viewer->dispH / ratioX);
            viewer->baseScale = (s32)(4096.0f / ratioX);
        } else {
            viewer->dispW = (u32)((f32)viewer->dispW / ratioY);
            viewer->dispH = 448;
            viewer->baseScale = (s32)(4096.0f / ratioY);
        }
        viewer->flags[3] = 1;
    }

    viewer->dispX = (640 - viewer->dispW) / 2;
    viewer->dispY = (448 - viewer->dispH) / 2;
    viewer->minX = 320 - viewer->tex->w / 2;
    viewer->minY = 224 - viewer->tex->h / 2;
    viewer->maxX = viewer->minX + viewer->tex->w;
    viewer->maxY = viewer->minY + viewer->tex->h;
    viewer->panX = 0;
    viewer->panY = 0;

    if (viewer->tex->w == 1024) {
        viewer->tex->w--;
    }
    if (viewer->tex->h == 1024) {
        viewer->tex->h--;
    }
}

s32 func_001246C0(GalleryMenuState *menu, GalleryMenuInput *input)
{
    s32 heldFrames;
    s32 buttonIndex;

    if (input->heldButtons == 0) {
        menu->heldFrames = 0;
    } else {
        menu->heldFrames++;
    }

    heldFrames = menu->heldFrames;
    if (heldFrames != 1) {
        if (heldFrames <= 20) {
            goto checkMovement;
        }
        if ((heldFrames & 3) != 0) {
            goto checkMovement;
        }
    }

    input->pressedButtons =
        (input->pressedButtons & 0x0FFF) | (input->heldButtons & 0xF000);

checkMovement:
    for (buttonIndex = 0; buttonIndex < 5; buttonIndex++) {
        if (menu->movementSteps[buttonIndex] != 0 &&
            (input->pressedButtons & D_0012AFE0[buttonIndex]) != 0) {
            menu->selection += menu->movementSteps[buttonIndex];
            if (menu->selection < 0) {
                menu->selection += menu->selectionCount;
                return -1;
            }
            if (menu->selection >= menu->selectionCount) {
                menu->selection -= menu->selectionCount;
                return -1;
            }
            return 1;
        }
    }

    for (buttonIndex = 0; buttonIndex < 5; buttonIndex++) {
        if (menu->actionEnabled[buttonIndex] != 0 &&
            (input->pressedButtons & D_0012AFF0[buttonIndex]) != 0) {
            return buttonIndex + 0x100;
        }
    }

    return 0;
}
