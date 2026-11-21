#include "common.h"

struct GallerySprite {
    u8 unk_00[0x44];
    s32 unk_44;
    u8 unk_48[0x8];
    s32 unk_50;
    s32 unk_54;
    u8 unk_58[0x2C];
};

struct GalleryTex {
    u8 unk_00[0x10];
};

struct GalleryWork {
    u8 readBuf[0x101000];
    u8 decodeBuf[0x404000];
    s32 cursorIdx;
    u8 unk_505004[0x30];
    struct GallerySprite sprites[2];
    struct GallerySprite *curSprite;
    struct GallerySprite *prevSprite;
    s32 unk_505144;
    s32 mode;
    s32 state;
    s32 unk_505150;
    s32 unk_505154;
    u8 unk_505158[0xC];
    s16 unk_505164;
    u8 unk_505166[0x2BA];
    struct GalleryTex textures[2];
    u8 unk_505440[0x100];
    s32 imageCount;
    s32 pageBase;
    s32 fileId;
    s8 slot;
    s8 unk_50554D;
    s8 unk_50554E;
    u8 unk_50554F[0x69];
    u8 unlockFlags[0x100];
    u8 fileTable[0x100];
};

extern s8 D_0012B2F0;
extern s8 D_0012B2F4;
extern struct GalleryWork *D_0012B3D8;
extern s32 D_0012B434;
extern s32 D_0012B444;
extern u32 D_001A5024[4];
extern s32 D_001C0344[4];
extern s32 D_001C0348[4];

extern void func_0011B6B0(void *, s32, s32);
extern s32 func_00122CC0(void *, s16, s16, void *, s32, s32);
extern s32 func_00123920(void *, s32);
extern void func_00124280(void *, void *, s32);
extern s32 func_00124820(void *);

s32 func_0011F750(void) {
    switch (D_0012B3D8->state) {
        case 0:
            D_0012B434 = D_0012B3D8->pageBase + D_0012B3D8->cursorIdx;
            D_0012B3D8->unk_505164 = 0;
            D_0012B3D8->curSprite = 0;
            D_0012B3D8->prevSprite = 0;
            D_0012B3D8->state++;

        case 1: {
            s32 fileId = D_0012B3D8->fileTable[D_0012B434];

            if (fileId >= 0x26) {
                fileId = 0;
            }
            D_0012B3D8->fileId = fileId;
            D_0012B3D8->fileId += 3;
            D_0012B2F4 = 1;
            D_0012B2F0 = 0;
            D_0012B3D8->state++;
        }

        case 2: {
            s32 fileId = D_0012B3D8->fileId;
            s32 offset = D_001C0344[fileId];
            s32 size = D_001C0348[fileId] - offset;

            if (offset != 0) {
                offset /= 0x800;
            }
            func_0011B6B0(D_0012B3D8->readBuf, size, D_0012B444 + offset);
            if (D_0012B2F4 == 0) {
                D_0012B3D8->state++;
            }
            break;
        }

        case 3: {
            u8 *buf = D_0012B3D8->readBuf;
            s32 fileId = D_0012B3D8->fileId;
            s32 size = D_001C0348[fileId] - D_001C0344[fileId];
            u8 prev = buf[4];
            s32 i;

            for (i = 5; i < size - 5; i++) {
                u8 cur = buf[i];

                buf[i] = cur - prev;
                prev = cur;
            }
            D_0012B3D8->unk_505154 = 0;
            D_0012B3D8->state++;
            break;
        }

        case 4:
            if (func_00124820(D_0012B3D8->decodeBuf) != 0) {
                D_0012B3D8->unk_505154 = 0;
                D_0012B3D8->state++;
            }
            break;

        case 5: {
            s32 slot = D_0012B3D8->slot;

            if (func_00122CC0(&D_0012B3D8->textures[slot], slot * 0x1000 + 0x1788, slot * 4 + 0x3788, D_0012B3D8->decodeBuf, 0, 0) != 0) {
                D_0012B3D8->state = 10;
            }
            break;
        }

        case 10:
            D_0012B3D8->curSprite = &D_0012B3D8->sprites[D_0012B3D8->slot];
            D_0012B3D8->prevSprite = D_0012B3D8->curSprite;
            func_00124280(D_0012B3D8->curSprite, &D_0012B3D8->textures[D_0012B3D8->slot], 0);
            if (D_0012B3D8->unk_50554E != 2) {
                D_0012B3D8->curSprite->unk_44 = 0;
            }
            D_0012B3D8->state++;

        case 11: {
            s32 action = func_00123920(D_0012B3D8->curSprite, 2);

            if (action == 3) {
                D_0012B3D8->curSprite = 0;
                D_0012B3D8->prevSprite = 0;
                D_0012B3D8->mode = 2;
                D_0012B3D8->state = 0;
            } else if (action != 0) {
                do {
                    if (action == 1) {
                        D_0012B434++;
                    } else {
                        D_0012B434 += D_0012B3D8->imageCount - 1;
                    }
                    D_0012B434 %= D_0012B3D8->imageCount;
                    if (D_0012B434 != 0) {
                        D_0012B3D8->pageBase = (D_0012B434 / 6) * 6;
                    } else {
                        D_0012B3D8->pageBase = 0;
                    }
                    D_0012B3D8->cursorIdx = D_0012B434 % 6;
                } while (D_0012B3D8->unlockFlags[D_0012B434] != 2);

                D_0012B3D8->curSprite->unk_50 = 2;
                D_0012B3D8->curSprite->unk_54 = 0x80;
                D_0012B3D8->unk_50554D = 1;
                D_0012B3D8->unk_50554E = 2;
                D_0012B3D8->slot ^= 1;
                D_0012B3D8->curSprite = 0;
                D_0012B3D8->state = 1;
            }
            break;
        }

        case 200:
            if (D_001A5024[0] & 0x20) {
                D_0012B3D8->mode = 2;
                D_0012B3D8->state = 0;
            }
            break;
    }

    return 0;
}
