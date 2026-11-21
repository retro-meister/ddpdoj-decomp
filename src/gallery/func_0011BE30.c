#include "common.h"

typedef struct {
    s16 unknown[3];
    s16 width;
    s16 height;
    s16 reserved;
} GalleryTexture;

typedef struct {
    s16 x;
    s16 y;
    u16 scale;
    s16 width;
    s16 height;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u16 attributes;
} GalleryQueueEntry;

extern s32 D_0012B308;
extern s8 (*D_0012B30C)[0x152];
extern GalleryQueueEntry D_00132E80[];
extern s8 D_001A0A80[];
extern u8 D_001A4A80[];
extern GalleryTexture D_001AC298[];

extern void func_00100E08(s32, s32);
extern void func_00101120(u8 *, s32, s32, s32, s32, s32, s32, s32);
extern void func_00101308(u8 *, s8 *);
extern void func_00103220(s32);
extern s32 func_0011EC80(u16);

void func_0011BE30(s16 x, s16 y, u16 textureId, u16 attributes, u16 scale)
{
    s32 id = textureId;
    s32 textureIndex;
    s32 uploaded = 0;
    GalleryTexture *textures = D_001AC298;

    if (D_0012B308 < 0x200) {
        s32 queueIndex;
        s16 width;
        s16 height;

        textureIndex = func_0011EC80((u16)id);
        if (textureIndex & 0x8000) {
            s32 byteIndex;

            for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                D_001A0A80[byteIndex] = D_0012B30C[id][byteIndex];
            }

            textureIndex &= 0x7FFF;
            func_00101120(D_001A4A80, 0x3800, 0x10, 0x14,
                          textures[textureIndex].width,
                          textures[textureIndex].height, 0x1A, 0x1A);
            func_00103220(0);
            func_00101308(D_001A4A80, D_001A0A80);
            uploaded++;
        }

        width = textures[textureIndex & 0x7FFF].width;
        height = textures[textureIndex & 0x7FFF].height;
        if (scale == 0) {
            scale = 1;
        }

        queueIndex = D_0012B308;
        D_00132E80[queueIndex].x = x;
        D_00132E80[queueIndex].y = y;
        D_00132E80[queueIndex].scale = scale;
        D_00132E80[queueIndex].width = width;
        D_00132E80[queueIndex].height = height;
        D_00132E80[queueIndex].unkA = 0x3832;
        D_00132E80[queueIndex].unkC = 0x1B;
        D_00132E80[queueIndex].unkE = 0x1B;
        D_00132E80[queueIndex].attributes = attributes;
        D_0012B308++;
    }

    if (uploaded != 0) {
        func_00100E08(0, 0);
    }
}
