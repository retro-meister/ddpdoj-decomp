#include "common.h"

typedef struct {
    u32 words[4];
} GifPacket;

typedef struct {
    u8 padding[0x505448];
    u64 textureParameters;
} GalleryState;

extern void *D_0012B318;
extern GalleryState *D_0012B3D8;
extern u64 D_00180A80[];

extern s32 func_00100E08(s32 mode, s32 timeout);
extern void func_00101FB0(void *channel, void *data, s32 quadwordCount);
extern void func_00102AC8(GifPacket *packet, void *buffer);
extern void func_00102AD8(GifPacket *packet);
extern void func_00102AE8(GifPacket *packet);
extern s32 func_00102B40(GifPacket *packet);
extern void func_00102B58(GifPacket *packet, u64 data);
extern void func_00103220(s32 mode);

void func_00121FB0(u8 alpha)
{
    GifPacket packet;

    func_00102AC8(&packet, D_00180A80);
    func_00102AD8(&packet);
    func_00102B58(&packet, 0x1000000000008003ULL);
    func_00102B58(&packet, 0xEULL);
    func_00102B58(&packet, D_0012B3D8->textureParameters);
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
