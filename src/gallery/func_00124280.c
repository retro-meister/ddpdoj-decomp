#include "common.h"

typedef struct {
    u8 pad00[0x4];
    s16 width;
    s16 height;
} GalleryImage;

typedef struct {
    s32 x1;
    s32 y1;
    s32 x2;
    s32 y2;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s32 alpha;
} GalleryBox;

typedef struct {
    s8 unk00;
    s8 unk01;
    s8 unk02;
    s8 isScaled;
    s8 unk04;
    s8 showHelp;
    s8 unk06;
    s8 unk07;
    u8 pad08[0x8];
    GalleryBox titleBox;
    u8 pad28[0x8];
    GalleryBox helpBox;
    GalleryImage *image;
    const char *title;
    s32 unk50;
    s32 unk54;
    u32 dispX;
    u32 dispY;
    u32 dispW;
    u32 dispH;
    s32 scrollX;
    s32 scrollY;
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 scale;
} GalleryViewer;

typedef struct {
    u8 pad00[0x505168];
    s32 showHelp;
} GalleryGlobalState;

extern GalleryGlobalState *D_0012B3D8;

extern void *func_00117060(void *dst, s32 val, u32 size);
extern s32 func_00118760(const char *str);

void func_00124280(GalleryViewer *viewer, GalleryImage *image, const char *title) {
    func_00117060(viewer, 0, sizeof(GalleryViewer));

    viewer->image = image;
    viewer->title = title;
    viewer->unk50 = 1;
    viewer->unk54 = 0x80;
    viewer->unk00 = 1;
    viewer->unk01 = 1;
    viewer->unk02 = 0;
    viewer->isScaled = 0;
    viewer->unk04 = 1;
    viewer->showHelp = D_0012B3D8->showHelp;
    viewer->unk07 = 0;

    if (viewer->title != 0) {
        viewer->titleBox.y1 = 0x10;
        viewer->titleBox.x1 = 0x10;
        viewer->titleBox.x2 = func_00118760(title) * 0x10 + 0x10;
        viewer->titleBox.y2 = 0x30;
        viewer->titleBox.r = 0x36;
        viewer->titleBox.g = 0xCD;
        viewer->titleBox.b = 0x18;
        viewer->titleBox.a = 0x25;
        viewer->titleBox.alpha = 0x80;
    }

    viewer->helpBox.x1 = 0x90;
    viewer->helpBox.x2 = 0x1F0;
    viewer->helpBox.y1 = 0x80;
    viewer->helpBox.y2 = 0x140;
    viewer->helpBox.r = 1;
    viewer->helpBox.g = 1;
    viewer->helpBox.b = 0x40;
    viewer->helpBox.a = 0x40;
    if (viewer->showHelp != 0) {
        viewer->helpBox.alpha = 0x80;
    }

    viewer->dispW = viewer->image->width;
    viewer->dispH = viewer->image->height;
    if (viewer->dispW > 640 || viewer->dispH > 448) {
        f32 ratioX = (f32)viewer->dispW / 640.0f;
        f32 ratioY = (f32)viewer->dispH / 448.0f;

        if (ratioX > ratioY) {
            viewer->dispW = 640;
            viewer->dispH = (u32)((f32)viewer->dispH / ratioX);
            viewer->scale = (s32)(4096.0f / ratioX);
        } else {
            viewer->dispW = (u32)((f32)viewer->dispW / ratioY);
            viewer->dispH = 448;
            viewer->scale = (s32)(4096.0f / ratioY);
        }
        viewer->isScaled = 1;
    }

    viewer->dispX = (640 - viewer->dispW) / 2;
    viewer->dispY = (448 - viewer->dispH) / 2;
    viewer->left = 320 - viewer->image->width / 2;
    viewer->top = 224 - viewer->image->height / 2;
    viewer->right = viewer->left + viewer->image->width;
    viewer->bottom = viewer->top + viewer->image->height;
    viewer->scrollX = 0;
    viewer->scrollY = 0;

    if (viewer->image->width == 1024) {
        viewer->image->width--;
    }
    if (viewer->image->height == 1024) {
        viewer->image->height--;
    }
}
