#include "common.h"

typedef union {
    __int128 quadword;
    u32 header;
} GalleryDmaTag;

typedef struct {
    GalleryDmaTag startTag;
    u64 gifTag;
    u64 gifRegisters;
    u64 texflush;
    u64 texflushRegister;
    u64 tex0;
    u64 tex0Register;
    u64 tex1;
    u64 tex1Register;
    u64 clamp;
    u64 clampRegister;
    u64 test;
    u64 testRegister;
    u64 texa;
    u64 texaRegister;
    u64 alpha;
    u64 alphaRegister;
    GalleryDmaTag endTag;
} GalleryTexturePacket;

void func_0011C7E0(GalleryTexturePacket *packet)
{
    packet->startTag.quadword = 0;
    packet->startTag.header = 0x10000008;
    packet->gifTag = 0x1000000000008007ULL;
    packet->gifRegisters = 0x0E;
    packet->texflush = 0;
    packet->texflushRegister = 0x3F;
    packet->tex0 = 0x2006FD06A9443800ULL;
    packet->tex0Register = 0x06;
    packet->tex1 = 0x60;
    packet->tex1Register = 0x14;
    packet->clamp = 0;
    packet->clampRegister = 0x08;
    packet->test = 0x3000F;
    packet->testRegister = 0x47;
    packet->texa = 0x0000008000008080ULL;
    packet->texaRegister = 0x3B;
    packet->alpha = 0x44;
    packet->alphaRegister = 0x42;
    packet->endTag.quadword = 0;
    packet->endTag.header = 0x70000000;
}
