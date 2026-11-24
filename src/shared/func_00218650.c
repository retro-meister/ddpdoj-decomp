#include "gallery/gallery.h"

typedef struct
{
    s32 type;
    s32 dbw;
    s32 x;
    s32 y;
    s32 width;
    s32 height;
} TexUploadInfo;

extern TexUploadInfo D_0026F870[];
extern s32 D_0028EA74;
extern u8 D_0050D780[];
extern sceGsLoadImage D_0057C780;

void func_00218650(s32 index)
{
    s32 type;
    s32 chunkHeight;
    s32 remaining;
    s32 yOffset;
    s32 src;
    s32 src1;

    type = D_0026F870[index].type;
    if (D_0026F870[index].width != 0x400) {
        switch (type) {
            case 0:
                remaining = D_0026F870[index].dbw;
                sceGsSetDefLoadImage(
                    &D_0057C780,
                    D_0028EA74,
                    remaining,
                    SCE_GS_PSMT4,
                    D_0026F870[index].x,
                    D_0026F870[index].y,
                    D_0026F870[index].width,
                    D_0026F870[index].height
                );
                FlushCache(0);
                sceGsExecLoadImage(&D_0057C780, D_0050D780);
                sceGsSyncPath(0, 0);
                break;

            case 1:
                chunkHeight = D_0026F870[index].height;
                sceGsSetDefLoadImage(
                    &D_0057C780,
                    D_0028EA74,
                    D_0026F870[index].dbw,
                    SCE_GS_PSMT8,
                    D_0026F870[index].x,
                    D_0026F870[index].y,
                    D_0026F870[index].width,
                    chunkHeight
                );
                FlushCache(0);
                sceGsExecLoadImage(&D_0057C780, D_0050D780);
                sceGsSyncPath(0, 0);
                break;

            case 2:
                break;
        }
        return;
    }

    switch (type) {
        case 0:
            remaining = D_0026F870[index].height;
            yOffset = 0;
            src = 0;
        loop0:
            if (remaining > 0x100) {
                chunkHeight = 0x100;
            } else {
                chunkHeight = remaining;
            }
            sceGsSetDefLoadImage(
                &D_0057C780,
                D_0028EA74,
                D_0026F870[index].dbw,
                SCE_GS_PSMT4,
                D_0026F870[index].x,
                yOffset + D_0026F870[index].y,
                0x400,
                chunkHeight
            );
            FlushCache(0);
            sceGsExecLoadImage(&D_0057C780, D_0050D780 + src);
            sceGsSyncPath(0, 0);
            remaining -= chunkHeight;
            src += 0x20000;
            yOffset += 0x100;
            if (remaining != 0) {
                goto loop0;
            } else {
                goto done;
            }

        case 1:
            remaining = D_0026F870[index].height;
            yOffset = 0;
            src1 = 0;
            do {
                if (remaining > 0x80) {
                    chunkHeight = 0x80;
                } else {
                    chunkHeight = remaining;
                }
                sceGsSetDefLoadImage(
                    &D_0057C780,
                    D_0028EA74,
                    D_0026F870[index].dbw,
                    SCE_GS_PSMT8,
                    D_0026F870[index].x,
                    yOffset + D_0026F870[index].y,
                    0x400,
                    chunkHeight
                );
                FlushCache(0);
                sceGsExecLoadImage(&D_0057C780, D_0050D780 + src1);
                sceGsSyncPath(0, 0);
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
