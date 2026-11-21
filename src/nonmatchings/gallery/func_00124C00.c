#include "common.h"

typedef struct GalleryFrame {
    s32 reserved00[2];
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 reserved18;
    s32 tileAttributes;
} GalleryFrame;

extern void func_0011BE30(s32 x, s32 y, s32 tileId, s32 tileAttributes, s32 depth);

void func_00124C00(GalleryFrame *frame)
{
    s32 innerColumns = (frame->right - frame->left) / 16 - 2;
    s32 innerRows = (frame->bottom - frame->top) / 32 - 2;
    s32 x = frame->left - 6;
    s32 y = frame->top / 2;
    s32 tileIndex;
    s32 bottomY;
    s32 rightY;

    func_0011BE30(x - 64, y, 0x2289, frame->tileAttributes, 300);
    y += 16;
    for (tileIndex = 0; tileIndex < innerRows; tileIndex++) {
        func_0011BE30(x - 64, y, 0x228A, frame->tileAttributes, 300);
        y += 16;
    }
    func_0011BE30(x - 64, y, 0x228B, frame->tileAttributes, 300);

    x = frame->left + 10;
    y = frame->top / 2;
    for (tileIndex = 0; tileIndex < innerColumns; tileIndex++) {
        func_0011BE30(x - 64, y, 0x2287, frame->tileAttributes, 300);
        x += 16;
    }

    x = frame->left + 10;
    bottomY = frame->top / 2 + (innerRows + 1) * 16;
    for (tileIndex = 0; tileIndex < innerColumns; tileIndex++) {
        func_0011BE30(x - 64, bottomY, 0x2288, frame->tileAttributes, 300);
        x += 16;
    }

    x = frame->left + ((innerColumns + 1) * 16 - 6);
    rightY = frame->top / 2;
    func_0011BE30(x - 64, rightY, 0x2284, frame->tileAttributes, 300);
    rightY += 16;
    for (tileIndex = 0; tileIndex < innerRows; tileIndex++) {
        func_0011BE30(x - 64, rightY, 0x2285, frame->tileAttributes, 300);
        rightY += 16;
    }
    func_0011BE30(x - 64, rightY, 0x2286, frame->tileAttributes, 300);
}
