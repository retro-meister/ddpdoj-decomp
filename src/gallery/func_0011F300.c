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
