#include "common.h"

typedef struct {
    u32 words[4];
} GifPacket;

extern void *D_0012B318;
extern u64 D_00180A80[];

extern s32 func_00100E08(s32 mode, s32 timeout);
extern void func_00101FB0(void *channel, void *data, s32 quadwordCount);
extern void func_00102AC8(GifPacket *packet, void *buffer);
extern void func_00102AD8(GifPacket *packet);
extern void func_00102AE8(GifPacket *packet);
extern s32 func_00102B40(GifPacket *packet);
extern void func_00102B58(GifPacket *packet, u64 data);
extern void func_00103220(s32 mode);

void func_00124E50(s32 xStart, s32 yStart, s32 xEnd, s32 yEnd,
                   s32 red, s32 green, s32 blue, s32 alpha, s32 blendMode)
{
    GifPacket packet;

    func_00102AC8(&packet, D_00180A80);
    func_00102AD8(&packet);
    func_00102B58(&packet, 0x1000000000008001ULL);
    func_00102B58(&packet, 0xEULL);

    if (blendMode == 0) {
        func_00102B58(&packet, 0x44ULL);
    } else if (blendMode == 1) {
        func_00102B58(&packet, 0x48ULL);
    } else {
        func_00102B58(&packet, 0x80000000A1ULL);
    }

    func_00102B58(&packet, 0x42ULL);
    func_00102B58(&packet, 0x4400000000008001ULL);
    func_00102B58(&packet, 0x5510ULL);
    func_00102B58(&packet, 0x146ULL);
    func_00102B58(&packet, (u64)(s64)red |
                            ((u64)(s64)green << 8) |
                            ((u64)(s64)blue << 16) |
                            ((u64)(s64)alpha << 24) |
                            0x3F80000000000000ULL);
    func_00102B58(&packet, (u64)(s64)(s32)(((u32)xStart << 4) + 0x6C00U) |
                            ((u64)(s64)(s32)(((u32)yStart << 3) + 0x7900U) << 16));
    func_00102B58(&packet, (u64)(s64)(s32)(((u32)xEnd << 4) + 0x6C00U) |
                            ((u64)(s64)(s32)(((u32)yEnd << 3) + 0x7900U) << 16));
    func_00102AE8(&packet);
    func_00103220(0);
    func_00101FB0(D_0012B318, D_00180A80, func_00102B40(&packet));
    func_00100E08(0, 0);
}
