#include "common.h"

typedef struct {
    u32 *pCurrent;
    u32 *pBase;
    u32 *pDmaTag;
    u32 *pGifTag;
} GifPacket;

typedef struct {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u64 tex0;
} SpriteTex;

typedef struct {
    u8 pad_000000[0x505000];
    s32 cursorIndex;
    u8 pad_505004[0x154];
    s32 animTimer;
    s32 fadeAlpha;
    u8 pad_505160[0xC];
    s16 state;
    s8 messageMode;
    u8 pad_50516F;
    SpriteTex thumbs[46];
    SpriteTex uiSprites[6];
    u8 pad_5054B0[0x88];
    s16 scrollX;
    u8 pad_50553A[2];
    s32 thumbCount;
    s32 subState;
    u8 pad_505544[0xB];
    s8 pageNumber;
    s16 uiX0[8];
    s16 uiY0[8];
    s16 uiX1[8];
    s16 uiY1[8];
    s8 uiMode[0x228];
    s8 thumbState[64];
} GalleryWork;

#define GS_RGBAQ(r, g, b, a, q) \
    ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))

#define GS_UV(u, v) \
    ((u64)(u) | ((u64)(v) << 16))

#define GS_XYZ2(x, y) \
    ((u64)(x) | ((u64)(y) << 16))

extern char *D_00129118[];
extern char *D_00129120[];
extern void *D_0012B318;
extern GalleryWork *D_0012B3D8;
extern s32 D_0012B42C;
extern s32 D_0012B430;
extern u32 D_0012B438;
extern u8 D_00180A80[];

extern void func_00100E08(s32, s32);
extern void func_00101FB0(void *, void *, s32);
extern void func_00102AC8(GifPacket *, void *);
extern void func_00102AD8(GifPacket *);
extern void func_00102AE8(GifPacket *);
extern s32 func_00102B40(GifPacket *);
extern void func_00102B58(GifPacket *, u64);
extern void func_00103220(s32);
extern f32 func_00111348(f32);
extern void func_0011C360(void);
extern void func_0011C460(s16, s16, char *, s32, s32, s32, s32, s32);
extern void func_0011C7D0(void);
extern void func_001236D0(s32, s32, s32, s32);

void func_00122160(void) {
    GifPacket pkt;
    s32 i;
    s32 row;
    s32 col;
    s32 idx;

    func_00102AC8(&pkt, D_00180A80);
    func_00102AD8(&pkt);

    func_00102B58(&pkt, 0x1000000000008001ULL);
    func_00102B58(&pkt, 0xEULL);
    func_00102B58(&pkt, 0x60ULL);
    func_00102B58(&pkt, 0x14ULL);

    for (i = 0; i < 6; i++) {
        SpriteTex *tex = &D_0012B3D8->uiSprites[i];

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
            if (D_0012B3D8->subState <= 6) {
                func_00102B58(&pkt, GS_RGBAQ(0, 0, 0, 0, 0x3F800000));
            } else {
                u8 pulse = (u8)(127.0f * func_00111348((3.1415927f * (f32)(D_0012B438 & 0x3F)) / 64.0f));
                func_00102B58(&pkt, GS_RGBAQ(0x80, pulse, pulse, 0x80, 0x3F800000));
            }
        } else {
            func_00102B58(&pkt, GS_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000));
        }

        func_00102B58(&pkt, GS_UV(tex->x << 4, tex->y << 4));
        func_00102B58(&pkt, GS_XYZ2((D_0012B3D8->uiX0[i] << 4) + 0x6C00, (D_0012B3D8->uiY0[i] << 3) + 0x7900));
        func_00102B58(&pkt, GS_UV((tex->x + tex->w) << 4, (tex->y + tex->h) << 4));
        func_00102B58(&pkt, GS_XYZ2((D_0012B3D8->uiX1[i] << 4) + 0x6C00, (D_0012B3D8->uiY1[i] << 3) + 0x7900));
    }

    func_00102B58(&pkt, 0x1000000000008001ULL);
    func_00102B58(&pkt, 0xEULL);
    func_00102B58(&pkt, 0ULL);
    func_00102B58(&pkt, 0x14ULL);

    if ((D_0012B3D8->animTimer & 0x20) == 0) {
        D_0012B42C = D_0012B3D8->animTimer & 0x1F;
        if (D_0012B42C >= 0x10) {
            D_0012B42C = 0x1F - D_0012B42C;
        }
    }

    idx = 0;
    for (row = 0; row < 2; row++) {
        for (col = 0; col < 3; col++) {
            SpriteTex *tex = &D_0012B3D8->thumbs[idx];
            s16 mode;

            if (idx >= D_0012B3D8->thumbCount) {
                break;
            }

            func_00102B58(&pkt, 0x1000000000008001ULL);
            func_00102B58(&pkt, 0xEULL);
            func_00102B58(&pkt, tex->tex0);
            func_00102B58(&pkt, 0x6ULL);

            func_00102B58(&pkt, 0x6400000000008001ULL);
            func_00102B58(&pkt, 0x535310ULL);

            mode = D_0012B3D8->thumbState[idx];
            if (D_0012B3D8->state == 0 || D_0012B3D8->state == 2) {
                mode = D_0012B3D8->state;
            }

            switch (mode) {
                case 0:
                case 2:
                    func_00102B58(&pkt, 0x156ULL);
                    func_00102B58(&pkt, GS_RGBAQ(0x80, 0x80, 0x80, D_0012B3D8->fadeAlpha << 2, 0x3F800000));
                    break;
                case 4: {
                    s32 bright = (D_0012B42C << 2) + 0x80;
                    func_00102B58(&pkt, 0x156ULL);
                    func_00102B58(&pkt, GS_RGBAQ(bright, bright, bright, 0x80, 0x3F800000));
                    break;
                }
                default:
                    func_00102B58(&pkt, 0x116ULL);
                    func_00102B58(&pkt, GS_RGBAQ(0x80, 0x80, 0x80, 0x80, 0x3F800000));
                    break;
            }

            func_00102B58(&pkt, GS_UV(tex->x << 4, tex->y << 4));
            func_00102B58(
                &pkt,
                GS_XYZ2(
                    ((D_0012B3D8->scrollX + 0x38 + col * 0x90) << 4) + 0x6C00,
                    ((row * 0x6A + 0x5E) << 3) + 0x7900
                )
            );
            func_00102B58(&pkt, GS_UV((tex->x + tex->w - 1) << 4, (tex->y + tex->h) << 4));
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

    if (D_0012B3D8->state == 1) {
        if ((D_0012B3D8->animTimer & 0x40) == 0) {
            D_0012B430 = D_0012B3D8->animTimer & 0x3F;
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
                (((D_0012B3D8->cursorIndex % 3) * 0x90 + 0x70) << 4) + 0x6C00,
                (((D_0012B3D8->cursorIndex / 3) * 0x6A + 0x5E) << 3) + 0x7900
            )
        );
        func_00102B58(
            &pkt,
            GS_XYZ2(
                (((D_0012B3D8->cursorIndex % 3) * 0x90 + 0xF0) << 4) + 0x6C00,
                (((D_0012B3D8->cursorIndex / 3) * 0x6A + 0xB8) << 3) + 0x7900
            )
        );
    }

    func_00102AE8(&pkt);
    func_00103220(0);
    func_00101FB0(D_0012B318, D_00180A80, func_00102B40(&pkt));
    func_00100E08(0, 0);

    switch (D_0012B3D8->messageMode) {
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
            func_001236D0(D_0012B3D8->pageNumber, 0x140, D_0012B3D8->uiY0[2] + 0x33, 0x40);
            break;
    }
}
