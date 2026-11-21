#include "common.h"

typedef struct {
    u32 archivePosition;
    u32 entryLocation;
} GalleryArchiveEntry;

typedef struct {
    u32 words[4];
} GifPacket;

typedef struct {
    u8 unk_00[0x44];
    s32 unk_44;
    u8 unk_48[0x8];
    s32 unk_50;
    s32 unk_54;
    u8 unk_58[0x2C];
} GallerySprite;

typedef struct {
    s16 u;
    s16 v;
    s16 w;
    s16 h;
    u64 tex0;
} SpriteInfo;

typedef struct {
    s16 u;
    s16 v;
    s16 w;
    s16 h;
} Rect16;

typedef struct {
    u8 readBuf[0x101000];
    u8 decodeBuf[0x303000];
    u8 textureBuffer[0x101000];
    s32 menu_params[12];
    u8 pad_505030[4];
    GallerySprite sprites[2];
    GallerySprite *curSprite;
    GallerySprite *prevSprite;
    s32 exitRequested;
    s32 mode;
    s32 state;
    s32 unk_505150;
    s32 unk_505154;
    s32 timer;
    s32 countdown;
    s32 exitMode;
    s16 overlayEnabled;
    s16 overlayAdjustment;
    s32 unk_505168;
    s16 fadeState;
    s8 dialogState;
    s8 drawEnabled;
    SpriteInfo pageSprites[6];
    SpriteInfo allSprites[37];
    SpriteInfo viewerTextures[2];
    SpriteInfo bgSprite;
    SpriteInfo uiSprites[6];
    u8 pad_5054B0[0x30];
    SpriteInfo uiAtlasSprite;
    u8 pad_5054F0[0x8];
    s32 box_x0;
    s32 box_y0;
    s32 box_x1;
    s32 box_y1;
    u8 box_color_r;
    u8 box_color_g;
    u8 box_color_b;
    u8 box_color_a;
    u8 pad_50550C[0x1C];
    u8 cursor_color_r;
    u8 cursor_color_g;
    u8 cursor_color_b;
    u8 cursor_color_a;
    s32 unk_50552C;
    s32 unk_505530;
    u8 pad_505534[4];
    s16 scrollX;
    s16 scrollDirection;
    s32 slotIndex;
    s32 itemCount;
    s32 pageOffset;
    s32 currentThumbId;
    s8 activeBuffer;
    s8 bufferPending;
    s8 isInitialized;
    s8 dialogChoice;
    s16 uiX0[8];
    s16 uiY0[8];
    s16 uiX1[8];
    s16 uiY1[8];
    s8 uiMode[0x28];
    u8 itemStatus[0x100];
    u8 itemThumbIds[0x100];
    s8 slotFlags[6];
} GalleryWork;

#define GS_RGBAQ(r, g, b, a, q) \
    ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))

#define GS_UV(u, v) \
    ((u64)(u) | ((u64)(v) << 16))

#define GS_XYZ2(x, y) \
    ((u64)(x) | ((u64)(y) << 16))

extern const char D_001290E0[];
extern const char D_00129100[];
extern char *D_00129118[];
extern char *D_00129120[];
extern s32 (*D_00129150[])(void);
extern u8 D_00129170[0x100];
extern u8 D_0012B0B0[];
extern const Rect16 D_0012B0C0[6];
extern const Rect16 D_0012B0F0[6];
extern const char *D_0012B200[1];
extern s8 D_0012B2F0;
extern s8 D_0012B2F4;
extern u32 D_0012B304;
extern void *D_0012B318;
extern void *D_0012B31C;
extern u32 D_0012B388;
extern u32 D_0012B38C;
extern u32 D_0012B390;
extern u32 D_0012B394;
extern u32 D_0012B398;
extern u32 D_0012B39C;
extern u32 D_0012B3A0;
extern u32 D_0012B3A4;
extern u32 D_0012B3A8;
extern u32 D_0012B3AC;
extern u32 D_0012B3B0;
extern u32 D_0012B3B4;
extern u32 D_0012B3B8;
extern u32 D_0012B3BC;
extern u32 D_0012B3C0;
extern u32 D_0012B3C4;
extern u32 D_0012B3C8;
extern u32 D_0012B3CC;
extern u32 D_0012B3D0;
extern u32 D_0012B3D4;
extern GalleryWork *D_0012B3D8;
extern s32 D_0012B42C;
extern s32 D_0012B430;
extern s32 D_0012B434;
extern u32 D_0012B438;
extern GalleryArchiveEntry D_0012B440[1];
extern s32 D_0012B444;
extern u32 D_001328C0[];
extern u32 D_001328C4[];
extern u64 D_00180A80[];
extern u8 D_001A4AE0[0x330];
extern u8 D_001A4B30[0x170];
extern u8 D_001A4B40[];
extern u8 D_001A4BC0[];
extern u8 D_001A4CA0[0x170];
extern u8 D_001A4CB0[];
extern u8 D_001A4D30[];
extern u8 D_001A4E10[];
extern u32 D_001A5000[];
extern u32 D_001A5020[];
extern u32 D_001A5024[4];
extern volatile s8 D_001A5032[];
extern volatile s8 D_001A5033[];
extern u8 D_001AF2B0[];
extern u8 D_001B7AB0[];
extern u8 D_001C0340[1][0x800];
extern s32 D_001C0344[4];
extern s32 D_001C0348[4];
extern s32 D_001C034C[];
extern s32 D_001C0350[];
extern s8 D_001C0B40[256];
extern s8 D_001C0C40[0x100];

extern void func_001001E0(s32, s32, s32, s32);
extern void func_00100C88(void *);
extern s32 func_00100D70(s32);
extern s32 func_00100E08(s32, s32);
extern void func_00101488(void *, s32, s32, s16);
extern void func_001016F0(void *, s32, s32, s16);
extern void func_00101778(void *, s32, s32, s32, s32, s32, s32);
extern void func_00101A60(void *, s32);
extern void *func_00101C18(s32);
extern void func_00101FB0(void *, void *, s32);
extern void func_00102AC8(GifPacket *, void *);
extern void func_00102AD8(GifPacket *);
extern void func_00102AE8(GifPacket *);
extern s32 func_00102B40(GifPacket *);
extern void func_00102B58(GifPacket *, u64);
extern void func_00103220(s32);
extern void func_0010EA50(void);
extern f32 func_00111348(f32);
extern void *func_001160A8(u32, u32);
extern void func_00116330(void *);
extern void *func_00117060(void *, s32, u32);
extern void func_0011A8E0(s32);
extern void func_0011AE50(void);
extern void func_0011AF60(void);
extern void func_0011AF70(void);
extern void func_0011AF90(void);
extern void func_0011AFB0(void);
extern void func_0011B0B0(void);
extern void func_0011B580(const char *);
extern void func_0011B5D0(void *, s32, u32);
extern void func_0011B6B0(void *, s32, s32);
extern void func_0011B830(void *, const char *);
extern void func_0011C360(void);
extern void func_0011C460(s16, s16, char *, s32, s32, s32, s32, s32);
extern void func_0011C7D0(void);
extern void func_0011CF30(void);
extern void func_0011D020(void);
extern void func_0011D150(void);
extern void func_0011D170(void);
extern void func_0011D360(void);
extern void func_0011D880(void);
extern void func_0011D9D0(void);
extern void func_0011E120(void);
extern void func_0011E210(void);
extern void func_0011E830(void);
extern void func_0011E870(void);
extern s32 func_00122CC0(SpriteInfo *, s16, s16, void *, s32, s32);
extern void func_00123480(GifPacket *, s32, s32, s32);
extern void func_001236D0(s32, s32, s32, s32);
extern s32 func_00123920(GallerySprite *, s32);
extern void func_00124280(void *, void *, s32);
extern s32 func_001246C0(s32 *, void *);
extern s32 func_00124820(u8 *, u8 *);
extern void func_00124E50(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_0011F070(void);
void func_0011F300(void);
void func_0011F410(void);
s32 func_00121720(void);
void func_00121FB0(u8 alpha);
void func_00122160(void);

static inline u64 getTex0Cbp(u64 tex0)
{
    return (u64)((s32)((tex0 >> 37) & 0x3FFF));
}

void func_0011EDF0(void)
{
    func_0011B830(D_001B7AB0, D_001290E0);
    D_0012B3D0 = D_0012B304;
    func_0011B830(D_001AF2B0, D_00129100);

    *(u8 *)&D_0012B3D4 = 0;
    *(u8 *)&D_0012B3A8 = 1;
    *(u8 *)&D_0012B3A4 = 0;
    *(u8 *)&D_0012B3AC = 0;
    *(u8 *)&D_0012B39C = 0;
    *(u8 *)&D_0012B3A0 = 0;
    *(u8 *)&D_0012B3B0 = 0;
    *(u8 *)&D_0012B398 = 0;
    D_0012B390 = 0;
    D_0012B38C = 0;
    D_0012B388 = 0;
    D_0012B3BC = 0;
    D_0012B3C8 = 0;
    D_0012B3C4 = 0;
    D_0012B3C0 = 0;
    D_0012B3B8 = 0;
    D_0012B3B4 = 0;
    *(u8 *)&D_0012B394 = 0;
    D_0012B3CC = D_0012B304;
}

void func_0011EE90(void)
{
    u32 archiveIndex;

    func_0011D9D0();
    func_0011D170();
    func_0011CF30();
    func_001001E0(0, 1, 2, 1);
    func_00117060(D_001A4AE0, 0, 0x330);
    func_00101778(D_001A4AE0, 0, 640, 224, 1, 0x31, 0);
    func_00103220(0);
    func_00100D70(0);
    func_00100C88(D_001A4B30);
    func_00100E08(0, 0);
    func_00100C88(D_001A4CA0);
    func_00100E08(0, 0);
    func_0011E870();
    func_0011E830();
    D_0012B318 = func_00101C18(2);
    func_0011E120();
    D_0012B31C = D_001A4E10;
    *(volatile u32 *)0x10000010 = 0x83;
    func_0011B0B0();

    archiveIndex = 0;
    do {
        func_0011B580(D_0012B200[archiveIndex]);
        D_0012B440[archiveIndex].archivePosition = D_001328C4[0];
        D_0012B440[archiveIndex].entryLocation = D_001328C0[0];
    } while (++archiveIndex == 0);

    archiveIndex = 0;
    do {
        func_0011B5D0(D_001C0340[archiveIndex], 0x9C,
                      D_0012B440[archiveIndex].entryLocation);
    } while (++archiveIndex == 0);

    func_0011D360();
    func_0011D020();
    func_0010EA50();
    func_0011EDF0();
    func_0011AF60();
    D_0012B3D8 = func_001160A8(0x40, 0x885800);
    func_00117060(D_0012B3D8, 0, 0x5057C0);
    func_0011F070();
    func_00116330(D_0012B3D8);
    func_0011A8E0(0);
}

void func_0011F070(void)
{
    s32 entryIndex;
    s32 ready;
    s8 entryState;

    D_0012B438 = 0;

    for (entryIndex = 0x20; entryIndex >= 0; entryIndex--) {
        D_001C0C40[entryIndex] = 2;
    }

    for (entryIndex = 0; entryIndex < 0x100; entryIndex++) {
        entryState = D_001C0C40[entryIndex];
        if (entryState != 0) {
            D_0012B3D8->itemStatus[entryIndex] = entryState;
            D_0012B3D8->itemThumbIds[entryIndex] = D_00129170[entryIndex];
        }
    }

    D_0012B3D8->itemStatus[0x11] = 0;
    D_0012B3D8->unk_505168 = 1;

    do {
        *(volatile u32 *)0x10000000 = 0;
        func_00101A60(D_001A4AE0, D_0012B438);
        func_0011F300();
        func_0011E210();

        if (D_001A5032[0] < 0) {
            D_001A5020[0] |= 0x8000;
        }
        if (D_001A5032[0] > 0) {
            D_001A5020[0] |= 0x2000;
        }
        if (D_001A5033[0] < 0) {
            D_001A5020[0] |= 0x1000;
        }
        if (D_001A5033[0] > 0) {
            D_001A5020[0] |= 0x4000;
        }

        func_0011F410();
        func_0011AE50();
        func_0011D880();

        D_0012B438++;
        ready = !func_00100D70(0);

        if (D_0012B438 & 1) {
            func_00101488(D_001A4CB0, 0x800, 0x800, (s16)ready);
            func_001016F0(D_001A4D30, 0x800, 0x800, (s16)ready);
        } else {
            func_00101488(D_001A4B40, 0x800, 0x800, (s16)ready);
            func_001016F0(D_001A4BC0, 0x800, 0x800, (s16)ready);
        }

        func_00103220(0);
        func_00100E08(0, 0);
    } while (!D_0012B3D8->exitRequested);

    D_0012B3D8 = 0;
}

void func_0011F300(void)
{
    GifPacket packet;

    func_00102AC8(&packet, D_00180A80);
    func_00102AD8(&packet);
    func_00102B58(&packet, 0x1000000000008005ULL);
    func_00102B58(&packet, 0xEULL);
    func_00102B58(&packet, 0x8000000000ULL);
    func_00102B58(&packet, 0x3BULL);
    func_00102B58(&packet, 0x3000FULL);
    func_00102B58(&packet, 0x47ULL);
    func_00102B58(&packet, 0x100000000ULL);
    func_00102B58(&packet, 0x4EULL);
    func_00102B58(&packet, 0ULL);
    func_00102B58(&packet, 0x14ULL);
    func_00102B58(&packet, 0x44ULL);
    func_00102B58(&packet, 0x42ULL);
    func_00102AE8(&packet);
    func_00103220(0);
    func_00101FB0(D_0012B318, D_00180A80, func_00102B40(&packet));
    func_00100E08(0, 0);
}

void func_0011F410(void)
{
    s32 overlayAdjustment;
    GallerySprite *drawBuffer;
    s16 fadeState;
    s32 brightness;

    while (D_00129150[D_0012B3D8->mode]() != 0) {
    }

    if (D_0012B3D8 == 0) {
        return;
    }

    if (D_0012B3D8->drawEnabled != 0) {
        func_00121FB0(0x80);
        if (D_0012B3D8->overlayEnabled != 0) {
            func_00122160();
            overlayAdjustment = D_0012B3D8->overlayAdjustment;
            if (overlayAdjustment != 0) {
                func_00121FB0((u8)(0x80 - ((s16)overlayAdjustment)));
            }
        }
        if ((D_0012B3D8->bufferPending != 0) && (func_00123920(&D_0012B3D8->sprites[D_0012B3D8->activeBuffer ^ 1], 0) != 0)) {
            D_0012B3D8->bufferPending = 0;
        }
        drawBuffer = D_0012B3D8->curSprite;
        if (drawBuffer != 0) {
            func_00123920(drawBuffer, 0);
        }
        drawBuffer = D_0012B3D8->prevSprite;
        if (drawBuffer != 0) {
            func_00123920(drawBuffer, 1);
        }
    }

    fadeState = D_0012B3D8->fadeState;
    if (fadeState == 0) {
        brightness = 0xFF - ((D_0012B3D8->timer * 8 > 0xFF) ? 0xFF : D_0012B3D8->timer * 8);
        func_00124E50(0, 0, 640, 448, brightness, brightness, brightness, 0x80, 2);
    } else if (fadeState > 8) {
        brightness = (D_0012B3D8->timer * 8 > 0xFF) ? 0xFF : D_0012B3D8->timer * 8;
        func_00124E50(0, 0, 640, 448, brightness, brightness, brightness, 0x80, 2);
    }
}

s32 func_0011F630(void)
{
    s32 byteIndex;

    if (D_0012B3D8->state == 0) {
        for (byteIndex = 0; byteIndex < sizeof(D_001C0B40); byteIndex++) {
            D_001C0B40[byteIndex] = 0;
        }

        D_0012B3D8->fadeState = 9;
        D_0012B3D8->timer = 0;
        D_0012B3D8->state++;
    }

    if (D_0012B3D8->timer < 32) {
        D_0012B3D8->timer++;
        return 0;
    }

    D_0012B3D8->exitRequested = 1;
    return 0;
}

s32 func_0011F750(void)
{
    switch (D_0012B3D8->state) {
    case 0:
        D_0012B434 = D_0012B3D8->pageOffset + D_0012B3D8->menu_params[0];
        D_0012B3D8->overlayEnabled = 0;
        D_0012B3D8->curSprite = 0;
        D_0012B3D8->prevSprite = 0;
        D_0012B3D8->state++;

    case 1: {
        s32 fileId = D_0012B3D8->itemThumbIds[D_0012B434];
        if (fileId > 0x25) {
            fileId = 0;
        }
        D_0012B3D8->currentThumbId = fileId;
        D_0012B3D8->currentThumbId += 3;
        D_0012B2F4 = 1;
        D_0012B2F0 = 0;
        D_0012B3D8->state++;
    }

    case 2: {
        s32 fileId = D_0012B3D8->currentThumbId;
        s32 offset = D_001C0344[fileId];
        s32 size = D_001C0348[fileId] - offset;
        if (offset != 0) {
            offset /= 0x800;
        }
        offset += D_0012B444;
        func_0011B6B0(D_0012B3D8->readBuf, size, offset);
        if (D_0012B2F4 == 0) {
            D_0012B3D8->state++;
        }
        break;
    }

    case 3: {
        u8 *buf = D_0012B3D8->readBuf;
        s32 fileId = D_0012B3D8->currentThumbId;
        s32 size = D_001C0348[fileId] - D_001C0344[fileId];
        s32 prev = buf[4];
        s32 i;
        for (i = 5; i < (size - 5); i++) {
            s32 cur = buf[i];
            buf[i] = cur - prev;
            prev = cur;
        }

        D_0012B3D8->unk_505154 = 0;
        D_0012B3D8->state++;
        break;
    }

    case 4:
        if (func_00124820(D_0012B3D8->decodeBuf, D_0012B3D8->readBuf) != 0) {
            D_0012B3D8->unk_505154 = 0;
            D_0012B3D8->state++;
        }
        break;

    case 5: {
        s32 slot = D_0012B3D8->activeBuffer;
        if (func_00122CC0(&D_0012B3D8->viewerTextures[slot], (slot * 0x1000) + 0x1788, (slot * 4) + 0x3788, D_0012B3D8->decodeBuf, 0, 0) != 0) {
            D_0012B3D8->state = 10;
        }
        break;
    }

    case 10:
        D_0012B3D8->curSprite = &D_0012B3D8->sprites[D_0012B3D8->activeBuffer];
        D_0012B3D8->prevSprite = D_0012B3D8->curSprite;
        func_00124280(D_0012B3D8->curSprite, &D_0012B3D8->viewerTextures[D_0012B3D8->activeBuffer], 0);
        if (D_0012B3D8->isInitialized != 2) {
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
                    D_0012B434 += D_0012B3D8->itemCount - 1;
                }
                D_0012B434 %= D_0012B3D8->itemCount;
                if (D_0012B434 != 0) {
                    D_0012B3D8->pageOffset = (D_0012B434 / 6) * 6;
                } else {
                    D_0012B3D8->pageOffset = 0;
                }
                D_0012B3D8->menu_params[0] = D_0012B434 % 6;
            } while (D_0012B3D8->itemStatus[D_0012B434] != 2);
            D_0012B3D8->curSprite->unk_50 = 2;
            D_0012B3D8->curSprite->unk_54 = 0x80;
            D_0012B3D8->bufferPending = 1;
            D_0012B3D8->isInitialized = 2;
            D_0012B3D8->activeBuffer ^= 1;
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

s32 func_0011FE50(void)
{
    SpriteInfo atlasSprite;
    s32 thumbnailIndex;
    s32 previousCursor;
    s32 menuResult;

    switch (D_0012B3D8->state) {
    case 0:
        D_0012B3D8->isInitialized = 0;
        D_0012B3D8->state = 3;

    case 3:
        D_0012B3D8->unk_505154 = 0;
        while (!func_00122CC0(&atlasSprite, 0x1788, 0x2788, D_0012B3D8->textureBuffer, 0, 0)) {
        }

        for (thumbnailIndex = 0; thumbnailIndex < 37; thumbnailIndex++) {
            SpriteInfo *sprite = &D_0012B3D8->allSprites[thumbnailIndex];
            *sprite = atlasSprite;
            sprite->tex0 = (sprite->tex0 & (~(((u64)0x3FFF) << 37))) | (getTex0Cbp(atlasSprite.tex0) << 37);
            sprite->u += (s16)((thumbnailIndex & 7) * 128);
            sprite->v += (s16)((thumbnailIndex >> 3) * 90);
            sprite->w = 128;
            sprite->h = 90;
        }

        D_0012B3D8->timer = 0;
        D_0012B3D8->overlayEnabled = 1;
        D_0012B3D8->scrollX = 0x38;
        D_0012B3D8->unk_505530 = 0;
        for (D_0012B3D8->slotIndex = 0; D_0012B3D8->slotIndex < 6; D_0012B3D8->slotIndex++) {
            s32 itemIndex = D_0012B3D8->pageOffset + D_0012B3D8->slotIndex;
            s32 thumbnailId;
            if (itemIndex >= D_0012B3D8->itemCount) {
                break;
            }
            thumbnailId = D_0012B3D8->itemThumbIds[itemIndex];
            if (thumbnailId > 37) {
                thumbnailId = 0;
            }
            D_0012B3D8->currentThumbId = thumbnailId;
            D_0012B3D8->pageSprites[D_0012B3D8->slotIndex] = D_0012B3D8->allSprites[D_0012B3D8->currentThumbId];
            if (D_001C0B40[D_0012B3D8->currentThumbId] != 0) {
                D_0012B3D8->slotFlags[D_0012B3D8->slotIndex] = 4;
            } else {
                D_0012B3D8->slotFlags[D_0012B3D8->slotIndex] = 1;
            }
        }

        if (D_0012B3D8->isInitialized == 0) {
            D_0012B3D8->state = 10;
            return 1;
        }
        D_0012B3D8->state = 19;
        break;

    case 10:
        D_0012B3D8->overlayAdjustment = 0;
        D_0012B3D8->state++;

    case 11:
        D_0012B3D8->overlayAdjustment += 4;
        if (D_0012B3D8->overlayAdjustment >= 0x80) {
            D_0012B3D8->isInitialized = 1;
            D_0012B3D8->overlayAdjustment = 0;
            D_0012B3D8->state = 19;
        }
        break;

    case 19:
        D_0012B3D8->unk_505530 = 0;
        D_0012B3D8->fadeState = 1;
        D_0012B3D8->unk_505150 = 0;
        D_0012B3D8->state++;

    case 20:
        previousCursor = D_0012B3D8->menu_params[0];
        menuResult = func_001246C0(&D_0012B3D8->menu_params[0], D_001A5000);
        if (menuResult != 0) {
            if (menuResult < 0x100) {
                int directionButtons;
                D_0012B3D8->unk_505530 = 0;
                if (D_0012B3D8->itemCount <= 6) {
                    break;
                }
                directionButtons = D_001A5020[0];
                if ((directionButtons & 0x8000) && ((previousCursor == 0) || (previousCursor == 3))) {
                    D_0012B3D8->menu_params[0] = previousCursor + 2;
                    D_0012B3D8->scrollDirection = -1;
                    D_0012B3D8->pageOffset -= 6;
                    if (D_0012B3D8->pageOffset < 0) {
                        D_0012B3D8->pageOffset = ((D_0012B3D8->itemCount - 1) / 6) * 6;
                    }
                    D_0012B3D8->state = 29;
                    return 1;
                }
                if ((directionButtons & 0x2000) && ((previousCursor == 2) || (previousCursor == 5))) {
                    D_0012B3D8->menu_params[0] = previousCursor - 2;
                    D_0012B3D8->scrollDirection = 1;
                    D_0012B3D8->pageOffset += 6;
                    if (D_0012B3D8->pageOffset >= D_0012B3D8->itemCount) {
                        D_0012B3D8->pageOffset = 0;
                    }
                    D_0012B3D8->state = 29;
                    return 1;
                }
                func_0011AF70();
            } else {
                s32 itemIndex = D_0012B3D8->menu_params[0] + D_0012B3D8->pageOffset;
                if ((itemIndex < D_0012B3D8->itemCount) && (D_0012B3D8->itemStatus[itemIndex] == 2)) {
                    func_0011AFB0();
                    D_0012B3D8->exitMode = 3;
                    D_0012B3D8->state = 100;
                }
            }
        } else {
            u32 buttons = D_001A5024[0];
            if (buttons & 0x40) {
                func_0011AFB0();
                D_0012B3D8->state = 40;
                break;
            } else if (buttons & 0x4) {
                if (D_0012B3D8->itemCount <= 6) {
                    break;
                }
                D_0012B3D8->scrollDirection = -1;
                D_0012B3D8->pageOffset -= 6;
                if (D_0012B3D8->pageOffset < 0) {
                    D_0012B3D8->pageOffset = ((D_0012B3D8->itemCount - 1) / 6) * 6;
                }
                D_0012B3D8->state = 29;
                return 1;
            } else if (buttons & 0x8) {
                if (D_0012B3D8->itemCount <= 6) {
                    break;
                }
                D_0012B3D8->scrollDirection = 1;
                D_0012B3D8->pageOffset += 6;
                if (D_0012B3D8->pageOffset >= D_0012B3D8->itemCount) {
                    D_0012B3D8->pageOffset = 0;
                }
                D_0012B3D8->state = 29;
                return 1;
            }
        }
        D_0012B3D8->timer++;
        break;

    case 29:
        D_0012B3D8->timer = 0;
        D_0012B3D8->unk_505530 = 0;
        func_0011AF90();
        D_0012B3D8->fadeState = 2;
        D_0012B3D8->countdown = 0x20;
        D_0012B3D8->state = 30;

    case 30:
        D_0012B3D8->timer++;
        D_0012B3D8->scrollX -= (s16)(D_0012B3D8->timer * D_0012B3D8->scrollDirection);
        if ((--D_0012B3D8->countdown) == 0) {
            D_0012B3D8->state = 3;
        }
        break;

    case 40:
        D_0012B3D8->dialogState = 1;
        D_0012B3D8->fadeState = 2;
        D_0012B3D8->countdown = 0x10;
        D_0012B3D8->dialogChoice = 1;
        func_001236D0(-1, 0, 0, 0);
        D_0012B3D8->state++;

    case 41:
        if (D_001A5024[0] & 0x8000) {
            if (menuResult = D_0012B3D8->dialogChoice != 0) {
                func_0011AF70();
            }
            D_0012B3D8->dialogChoice = 0;
        }
        if (D_001A5024[0] & 0x2000) {
            if (D_0012B3D8->dialogChoice != 1) {
                func_0011AF70();
            }
            D_0012B3D8->dialogChoice = 1;
        }
        if (D_001A5024[0] & 0x20) {
            func_0011AFB0();
            if (D_0012B3D8->dialogChoice == 0) {
                D_0012B3D8->dialogState = -1;
                D_0012B3D8->state = 100;
                D_0012B3D8->exitMode = 4;
            } else {
                D_0012B3D8->dialogState = 0;
                D_0012B3D8->fadeState = 1;
                D_0012B3D8->state = 20;
            }
        }
        if (D_001A5024[0] & 0x40) {
            func_0011AFB0();
            D_0012B3D8->dialogState = 0;
            D_0012B3D8->fadeState = 1;
            D_0012B3D8->state = 20;
        }
        break;

    case 100:
        D_0012B3D8->overlayAdjustment = 0x80;
        D_0012B3D8->state++;

    case 101:
        D_0012B3D8->overlayAdjustment -= 4;
        if (D_0012B3D8->overlayAdjustment <= 0) {
            D_0012B3D8->overlayEnabled = 0;
            D_0012B3D8->mode = D_0012B3D8->exitMode;
            D_0012B3D8->state = 0;
        }
        break;
    }

    return (unsigned long)0;
}

s32 func_00121080(void)
{
    if (D_0012B3D8->state == 0) {
        D_0012B3D8->fadeState = 0;
        D_0012B3D8->timer = 0;
        D_0012B3D8->state++;
    }

    if (++D_0012B3D8->timer < 32) {
        return 0;
    }

    D_0012B3D8->fadeState = 1;
    D_0012B3D8->mode = 2;
    D_0012B3D8->state = 0;
    return 0;
}

s32 func_00121150(void)
{
    GifPacket pkt;
    u32 i;
    s32 idx;
    s32 count;
    s32 *params;

    switch (D_0012B3D8->state) {
    case 0:
        D_0012B3D8->drawEnabled = 0;
        D_0012B3D8->fadeState = 0;
        D_0012B3D8->timer = 0;
        D_0012B3D8->state++;
    case 1:
        func_0011D150();
        if (D_0012B2F4 == 0) {
            D_0012B3D8->state++;
        }
        break;
    case 2:
        if (func_00121720() != 0) {
            D_0012B3D8->state++;
        }
        break;
    case 3:
        D_0012B3D8->fadeState = 9;
        D_0012B3D8->timer = 0;
        D_0012B3D8->state++;
    case 4:
        if (D_0012B3D8->timer >= 0x20) {
            D_0012B3D8->fadeState = 0;
            D_0012B3D8->timer = 0;
            D_0012B3D8->state++;
        }
        break;
    case 5:
        D_0012B3D8->state++;
        break;
    case 6:
        D_0012B3D8->box_x0 = 0x38;
        D_0012B3D8->box_x1 = 0x248;
        D_0012B3D8->box_y0 = 0x50;
        D_0012B3D8->box_y1 = 0x130;
        D_0012B3D8->box_color_r = 0x80;
        D_0012B3D8->box_color_g = 0x18;
        D_0012B3D8->box_color_b = 0x80;
        D_0012B3D8->box_color_a = 0x33;
        D_0012B3D8->overlayEnabled = 0;
        D_0012B3D8->cursor_color_r = 0x18;
        D_0012B3D8->cursor_color_g = 0xFF;
        D_0012B3D8->cursor_color_b = 0x30;
        D_0012B3D8->cursor_color_a = 0x33;
        D_0012B3D8->unk_50552C = 0x80;

        params = D_0012B3D8->menu_params;
        params[0] = 0;
        params[1] = 6;
        params[2] = -3;
        params[3] = 3;
        params[4] = -1;
        params[5] = 1;
        params[6] = 0;
        params[7] = 0;
        params[8] = 0;
        params[9] = 1;
        params[10] = 0;
        params[11] = 0;

        D_0012B3D8->slotFlags[0] = 0;
        D_0012B3D8->slotFlags[1] = 0;
        D_0012B3D8->slotFlags[2] = 0;
        D_0012B3D8->slotFlags[3] = 0;
        D_0012B3D8->slotFlags[4] = 0;
        D_0012B3D8->slotFlags[5] = 0;

        count = 0;
        for (idx = 0; idx < 0x100; idx++) {
            if (D_001C0C40[idx] != 0) {
                count++;
            }
        }

        D_0012B3D8->drawEnabled = 1;
        D_0012B3D8->itemCount = count;
        D_0012B3D8->pageOffset = 0;
        D_0012B3D8->mode = 1;
        D_0012B3D8->state = 0;
        break;
    }

    if (D_0012B3D8->state < 5) {
        func_00124E50(0, 0, 0x280, 0x1C0, 0, 0, 0, 0x80, 0);
        func_00102AC8(&pkt, D_00180A80);
        func_00102AD8(&pkt);
        func_00102B58(&pkt, 0x1000000000008002ULL);
        func_00102B58(&pkt, 0xE);
        func_00102B58(&pkt, 0x20170606A9441E40ULL);
        func_00102B58(&pkt, 0x6);
        func_00102B58(&pkt, 0);
        func_00102B58(&pkt, 0x14);

        for (i = 0; i < 11; i++) {
            func_00123480(&pkt, 0x180 + i * 16, 0x1A0, D_0012B0B0[i]);
        }

        for (i = 0; i < ((D_0012B438 & 0x7F) >> 5); i++) {
            func_00123480(&pkt, 0x180 + (i + 11) * 16, 0x1A0, '.');
        }

        func_00102AE8(&pkt);
        func_00103220(0);
        func_00101FB0(D_0012B318, D_00180A80, func_00102B40(&pkt));
        func_00100E08(0, 0);

        if (D_0012B3D8->timer < 0x20) {
            D_0012B3D8->timer++;
        }
    }

    return 0;
}

s32 func_00121720(void)
{
    s32 loopState[2];
    s32 size;
    s32 offset;
    u8 *buf;
    u32 k;

    switch (D_0012B3D8->unk_505150) {
    case 0:
        D_0012B2F4 = 1;
        D_0012B2F0 = 0;
        D_0012B3D8->unk_505150++;

    case 1:
        offset = D_001C0344[0];
        buf = D_0012B3D8->readBuf;
        size = D_001C0348[0] - offset;
        if (offset != 0) {
            offset /= 0x800;
        }
        offset += D_0012B444;
        func_0011B6B0(buf, size, offset);
        if (D_0012B2F4 == 0) {
            D_0012B3D8->unk_505150++;
        }
        break;

    case 2: {
        u8 *buf = D_0012B3D8->readBuf;
        s32 size = D_001C0348[0] - D_001C0344[0];
        s32 prev = buf[4];
        s32 i;
        for (loopState[1] = 5; loopState[1] < (size - 5); loopState[1]++) {
            s32 cur = buf[loopState[1]];
            buf[loopState[1]] = cur - prev;
            prev = cur;
        }

        D_0012B3D8->unk_505154 = 0;
        D_0012B3D8->unk_505150++;
        break;
    }

    case 3:
        if (func_00124820(D_0012B3D8->decodeBuf, D_0012B3D8->readBuf) != 0) {
            D_0012B3D8->unk_505154 = 0;
            D_0012B3D8->unk_505150++;
        }
        break;

    case 4:
        if (func_00122CC0(&D_0012B3D8->bgSprite, 0x1180, 0x1780, D_0012B3D8->decodeBuf, 0, 0) != 0) {
            D_0012B3D8->unk_505150 = 10;
        }
        break;

    case 10:
        D_0012B2F0 = 0;
        D_0012B2F4 = 1;
        D_0012B3D8->unk_505150++;

    case 11:
        offset = D_001C0348[0];
        buf = D_0012B3D8->readBuf;
        size = D_001C034C[0] - offset;
        if (offset != 0) {
            offset /= 0x800;
        }
        offset += D_0012B444;
        func_0011B6B0(buf, size, offset);
        if (D_0012B2F4 == 0) {
            D_0012B3D8->unk_505150++;
        }
        break;

    case 12: {
        u8 *buf = D_0012B3D8->readBuf;
        s32 size = D_001C034C[0] - D_001C0348[0];
        s32 prev = buf[4];
        s32 i;
        for (loopState[1] = 5; loopState[1] < (size - 5); loopState[1]++) {
            s32 cur = buf[loopState[1]];
            buf[loopState[1]] = cur - prev;
            prev = cur;
        }

        D_0012B3D8->unk_505154 = 0;
        D_0012B3D8->unk_505150++;
        break;
    }

    case 13:
        if (func_00124820(D_0012B3D8->decodeBuf, D_0012B3D8->readBuf) != 0) {
            D_0012B3D8->unk_505154 = 0;
            D_0012B3D8->unk_505150++;
        }
        break;

    case 14:
        if (func_00122CC0(&D_0012B3D8->uiAtlasSprite, 0x1380, 0x1784, D_0012B3D8->decodeBuf, 0, 0) != 0) {
            D_0012B3D8->unk_505150 = 20;
        }
        break;

    case 20:
        D_0012B2F0 = 0;
        D_0012B2F4 = 1;
        D_0012B3D8->unk_505150++;

    case 21:
        offset = D_001C034C[0];
        buf = D_0012B3D8->readBuf;
        size = D_001C0350[0] - offset;
        if (offset != 0) {
            offset /= 0x800;
        }
        offset += D_0012B444;
        func_0011B6B0(buf, size, offset);
        if (D_0012B2F4 == 0) {
            D_0012B3D8->unk_505150++;
        }
        break;

    case 22: {
        u8 *buf = D_0012B3D8->readBuf;
        s32 size = D_001C0350[0] - D_001C034C[0];
        s32 prev = buf[4];
        s32 i;
        for (loopState[1] = 5; loopState[1] < (size - 5); loopState[1]++) {
            s32 cur = buf[loopState[1]];
            buf[loopState[1]] = cur - prev;
            prev = cur;
        }

        D_0012B3D8->unk_505154 = 0;
        D_0012B3D8->unk_505150++;
        break;
    }

    case 23:
        if (func_00124820(D_0012B3D8->textureBuffer, D_0012B3D8->readBuf) != 0) {
            D_0012B3D8->unk_505150 = 30;
        }
        break;

    case 30: {
        for (k = 0; k < 6; k++) {
            SpriteInfo *src = &D_0012B3D8->uiAtlasSprite;
            s16 h = D_0012B0C0[k].h;
            s16 w = D_0012B0C0[k].w;
            s16 v = D_0012B0C0[k].v;
            s16 u = D_0012B0C0[k].u;
            SpriteInfo *dst = &D_0012B3D8->uiSprites[k];
            *dst = *src;
            dst->tex0 = (dst->tex0 & (~(((u64)0x3FFF) << 37))) | (getTex0Cbp(src->tex0) << 37);
            dst->u += u;
            dst->v += v;
            dst->w = w;
            dst->h = h;
        }

        for (loopState[1] = 0; ((u32)loopState[1]) < 6; loopState[1]++) {
            loopState[0] = D_0012B0F0[loopState[1]].u;
            D_0012B3D8->uiX0[loopState[1]] = loopState[0];
            D_0012B3D8->uiY0[loopState[1]] = D_0012B0F0[loopState[1]].v;
            D_0012B3D8->uiX1[loopState[1]] = D_0012B0F0[loopState[1]].w;
            D_0012B3D8->uiY1[loopState[1]] = D_0012B0F0[loopState[1]].h;
        }

        D_0012B3D8->uiMode[4] = 2;
        D_0012B3D8->uiMode[5] = 2;
        return 1;
    }
    }

    return 0;
}

void func_00121FB0(u8 alpha)
{
    GifPacket packet;

    func_00102AC8(&packet, D_00180A80);
    func_00102AD8(&packet);
    func_00102B58(&packet, 0x1000000000008003ULL);
    func_00102B58(&packet, 0xEULL);
    func_00102B58(&packet, D_0012B3D8->bgSprite.tex0);
    func_00102B58(&packet, 0x6ULL);
    func_00102B58(&packet, 0x60ULL);
    func_00102B58(&packet, 0x14ULL);
    func_00102B58(&packet, 0x44ULL);
    func_00102B58(&packet, 0x42ULL);
    func_00102B58(&packet, 0x6400000000008001ULL);
    func_00102B58(&packet, 0x535310ULL);

    if (alpha == 0x80) {
        func_00102B58(&packet, 0x116ULL);
    } else {
        func_00102B58(&packet, 0x156ULL);
    }

    func_00102B58(&packet, ((u64)alpha << 24) | 0x3F80000000808080ULL);
    func_00102B58(&packet, 0ULL);
    func_00102B58(&packet, 0x79006C00ULL);
    func_00102B58(&packet, 0x1C002000ULL);
    func_00102B58(&packet, 0x87009400ULL);
    func_00102AE8(&packet);
    func_00103220(0);
    func_00101FB0(D_0012B318, D_00180A80, func_00102B40(&packet));
    func_00100E08(0, 0);
}

void func_00122160(void)
{
    GifPacket pkt;
    SpriteInfo *tex;
    s32 i;
    s32 col;
    s32 row;
    s32 idx;
    s32 mode;

    func_00102AC8(&pkt, D_00180A80);
    func_00102AD8(&pkt);

    func_00102B58(&pkt, 0x1000000000008001ULL);
    func_00102B58(&pkt, 0xEULL);
    func_00102B58(&pkt, 0x60ULL);
    func_00102B58(&pkt, 0x14ULL);

    for (i = 0; i < 6; i++) {
        tex = &D_0012B3D8->uiSprites[i];

        func_00102B58(&pkt, 0x1000000000008001ULL);
        func_00102B58(&pkt, 0xEULL);
        func_00102B58(&pkt, tex->tex0);
        func_00102B58(&pkt, 0x6ULL);

        func_00102B58(&pkt, 0x6400000000008001ULL);
        func_00102B58(&pkt, 0x535310ULL);
        func_00102B58(&pkt, 0x116ULL);

        if (D_0012B3D8->uiMode[i] == 1) {
            u8 color = ((D_0012B438 & 1) << 6) + 0x40;
            func_00102B58(&pkt, GS_RGBAQ(color, color, color, color, 0x3F800000));
        } else if (D_0012B3D8->uiMode[i] == 2) {
            if (D_0012B3D8->itemCount <= 6) {
                func_00102B58(&pkt, GS_RGBAQ(0, 0, 0, 0, 0x3F800000));
            } else {
                u8 pulse = (u8)(127.0f * func_00111348((3.1415927f * (f32)(D_0012B438 & 0x3F)) / 64.0f));
                func_00102B58(&pkt, GS_RGBAQ(0x80, pulse, pulse, 0x80, 0x3F800000));
            }
        } else {
            func_00102B58(&pkt, GS_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000));
        }

        func_00102B58(&pkt, GS_UV(tex->u << 4, tex->v << 4));
        func_00102B58(&pkt, GS_XYZ2((D_0012B3D8->uiX0[i] << 4) + 0x6C00, (D_0012B3D8->uiY0[i] << 3) + 0x7900));
        func_00102B58(&pkt, GS_UV((tex->u + tex->w) << 4, (tex->v + tex->h) << 4));
        func_00102B58(&pkt, GS_XYZ2((D_0012B3D8->uiX1[i] << 4) + 0x6C00, (D_0012B3D8->uiY1[i] << 3) + 0x7900));
    }

    func_00102B58(&pkt, 0x1000000000008001ULL);
    func_00102B58(&pkt, 0xEULL);
    func_00102B58(&pkt, 0ULL);
    func_00102B58(&pkt, 0x14ULL);

    if ((D_0012B3D8->timer & 0x20) == 0) {
        D_0012B42C = D_0012B3D8->timer & 0x1F;
        if (D_0012B42C >= 0x10) {
            D_0012B42C = 0x1F - D_0012B42C;
        }
    }

    idx = 0;
    for (row = 0; row < 2; row++) {
        for (col = 0; col < 3; col++) {
            tex = &D_0012B3D8->pageSprites[idx];

            if (idx >= D_0012B3D8->slotIndex) {
                break;
            }

            func_00102B58(&pkt, 0x1000000000008001ULL);
            func_00102B58(&pkt, 0xEULL);
            func_00102B58(&pkt, tex->tex0);
            func_00102B58(&pkt, 0x6ULL);

            func_00102B58(&pkt, 0x6400000000008001ULL);
            func_00102B58(&pkt, 0x535310ULL);

            mode = D_0012B3D8->slotFlags[idx];
            if (D_0012B3D8->fadeState == 0 || D_0012B3D8->fadeState == 2) {
                mode = D_0012B3D8->fadeState;
            }

            switch (mode) {
            default:
                func_00102B58(&pkt, 0x116ULL);
                func_00102B58(&pkt, GS_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000));
                break;
            case 0:
            case 2:
                func_00102B58(&pkt, 0x156ULL);
                func_00102B58(&pkt, GS_RGBAQ(0x80, 0x80, 0x80, D_0012B3D8->countdown << 2, 0x3F800000));
                break;
            case 4: {
                s32 bright = (D_0012B42C << 2) + 0x80;
                func_00102B58(&pkt, 0x156ULL);
                func_00102B58(&pkt, GS_RGBAQ(bright, bright, bright, 0x80, 0x3F800000));
                break;
            }
            }

            func_00102B58(&pkt, GS_UV(tex->u << 4, tex->v << 4));
            func_00102B58(
                &pkt,
                GS_XYZ2(
                    ((D_0012B3D8->scrollX + 0x38 + col * 0x90) << 4) + 0x6C00,
                    ((row * 0x6A + 0x5E) << 3) + 0x7900
                )
            );
            func_00102B58(&pkt, GS_UV((tex->u + tex->w - 1) << 4, (tex->v + tex->h) << 4));
            func_00102B58(
                &pkt,
                GS_XYZ2(
                    ((tex->w + (D_0012B3D8->scrollX + 0x38 + col * 0x90)) << 4) + 0x6C00,
                    ((tex->h + (row * 0x6A + 0x5E)) << 3) + 0x7900
                )
            );
            idx++;
        }
    }

    func_00102B58(&pkt, 0x1000000000008001ULL);
    func_00102B58(&pkt, 0xEULL);
    func_00102B58(&pkt, 0x60ULL);
    func_00102B58(&pkt, 0x14ULL);

    if (D_0012B3D8->fadeState == 1) {
        if ((D_0012B3D8->timer & 0x40) == 0) {
            D_0012B430 = D_0012B3D8->timer & 0x3F;
            if (D_0012B430 >= 0x20) {
                D_0012B430 = 0x3F - D_0012B430;
            }
        }

        func_00102B58(&pkt, 0x1000000000008001ULL);
        func_00102B58(&pkt, 0xEULL);
        func_00102B58(&pkt, 0x48ULL);
        func_00102B58(&pkt, 0x42ULL);

        func_00102B58(&pkt, 0x4400000000008001ULL);
        func_00102B58(&pkt, 0x5510ULL);
        func_00102B58(&pkt, 0x146ULL);
        func_00102B58(&pkt, GS_RGBAQ(0xC0, 0xC0, 0xC0, 0x60 - D_0012B430 * 2, 0x3F800000));
        func_00102B58(
            &pkt,
            GS_XYZ2(
                (((D_0012B3D8->menu_params[0] % 3) * 0x90 + 0x70) << 4) + 0x6C00,
                (((D_0012B3D8->menu_params[0] / 3) * 0x6A + 0x5E) << 3) + 0x7900
            )
        );
        func_00102B58(
            &pkt,
            GS_XYZ2(
                (((D_0012B3D8->menu_params[0] % 3) * 0x90 + 0xF0) << 4) + 0x6C00,
                (((D_0012B3D8->menu_params[0] / 3) * 0x6A + 0xB8) << 3) + 0x7900
            )
        );
    }

    func_00102AE8(&pkt);
    func_00103220(0);
    func_00101FB0(D_0012B318, D_00180A80, func_00102B40(&pkt));
    func_00100E08(0, 0);

    switch (D_0012B3D8->dialogState) {
    case 0:
        func_0011C7D0();
        for (i = 0; i < 2; i++) {
            func_0011C460(
                D_0012B3D8->uiX0[2] - 0x20,
                D_0012B3D8->uiY0[2] + 0x13 + i * 0x18,
                D_00129118[i],
                0,
                0x18,
                0x18,
                0x80,
                0
            );
        }
        func_0011C360();
        break;
    case 1:
        func_0011C7D0();
        func_0011C460(
            D_0012B3D8->uiX0[2] - 0x20,
            D_0012B3D8->uiY0[2] + 0x13,
            D_00129120[0],
            0,
            0x18,
            0x18,
            0x80,
            0
        );
        func_0011C360();
        func_001236D0(D_0012B3D8->dialogChoice, 0x140, D_0012B3D8->uiY0[2] + 0x33, 0x40);
        break;
    }
}
