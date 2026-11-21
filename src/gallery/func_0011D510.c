#include "common.h"

typedef struct
{
    s32 type;
    s32 dbw;
    s32 x;
    s32 y;
    s32 width;
    s32 height;
} TexUploadInfo;

extern TexUploadInfo D_00129010[];
extern s32 D_0012B310;
extern u8 D_00135A80[];
extern u8 D_001A4A80[];

extern void func_00100E08(s32, s32);
extern void func_00101120(void *, s16, s16, s16, s16, s16, s16, s16);
extern void func_00101308(void *, void *);
extern void func_00103220(s32);

void func_0011D510(s32 index)
{
    s32 type;
    s32 chunkHeight;
    s32 remaining;
    s32 yOffset;
    u8 *src;
    u8 *src1;

    type = D_00129010[index].type;
    if (D_00129010[index].width != 0x400) {
        switch (type) {
            case 0:
                remaining = D_00129010[index].dbw;
                func_00101120(
                    D_001A4A80,
                    D_0012B310,
                    remaining,
                    0x14,
                    D_00129010[index].x,
                    D_00129010[index].y,
                    D_00129010[index].width,
                    D_00129010[index].height
                );
                func_00103220(0);
                func_00101308(D_001A4A80, D_00135A80);
                func_00100E08(0, 0);
                break;

            case 1:
                chunkHeight = D_00129010[index].height;
                func_00101120(
                    D_001A4A80,
                    D_0012B310,
                    D_00129010[index].dbw,
                    0x13,
                    D_00129010[index].x,
                    D_00129010[index].y,
                    D_00129010[index].width,
                    chunkHeight
                );
                func_00103220(0);
                func_00101308(D_001A4A80, D_00135A80);
                func_00100E08(0, 0);
                break;

            case 2:
                break;
        }
        return;
    }

    switch (type) {
        case 0:
            remaining = D_00129010[index].height;
            yOffset = 0;
            src = D_00135A80;
            loop0:
            if (remaining > 0x100) {
                chunkHeight = 0x100;
            } else {
                chunkHeight = remaining;
            }
            func_00101120(
                D_001A4A80,
                D_0012B310,
                D_00129010[index].dbw,
                0x14,
                D_00129010[index].x,
                yOffset + D_00129010[index].y,
                0x400,
                chunkHeight
            );
            func_00103220(0);
            func_00101308(D_001A4A80, src);
            func_00100E08(0, 0);
            remaining -= chunkHeight;
            src += 0x20000;
            yOffset += 0x100;
            if (remaining != 0) {
                goto loop0;
            } else {
                goto done;
            }

        case 1:
            remaining = D_00129010[index].height;
            yOffset = 0;
            src1 = D_00135A80;
            do {
                if (remaining > 0x80) {
                    chunkHeight = 0x80;
                } else {
                    chunkHeight = remaining;
                }
                func_00101120(
                    D_001A4A80,
                    D_0012B310,
                    D_00129010[index].dbw,
                    0x13,
                    D_00129010[index].x,
                    yOffset + D_00129010[index].y,
                    0x400,
                    chunkHeight
                );
                func_00103220(0);
                func_00101308(D_001A4A80, src1);
                func_00100E08(0, 0);
                remaining -= chunkHeight;
                src1 += 0x20000;
                yOffset += 0x80;
            } while (remaining != 0);
            break;

        case 2:
            break;
    }

done:
    return;
}
