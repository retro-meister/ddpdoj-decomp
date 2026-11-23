#include "gallery/gallery.h"

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

void func_00212F90(void *packetPtr)
{
    GalleryTexturePacket *packet = packetPtr;
    packet->startTag.quadword = 0;
    packet->startTag.header = 0x10000008;
    packet->gifTag = SCE_GIF_SET_TAG(7, 1, 0, 0, SCE_GIF_PACKED, 1);
    packet->gifRegisters = SCE_GIF_PACKED_AD;
    packet->texflush = 0;
    packet->texflushRegister = SCE_GS_TEXFLUSH;
    packet->tex0 = SCE_GS_SET_TEX0(0x3800, 16, SCE_GS_PSMT4, 10, 10, 1, 0, 0x37E8, SCE_GS_PSMCT32, 0, 0, 1);
    packet->tex0Register = SCE_GS_TEX0_1;
    packet->tex1 = SCE_GS_SET_TEX1(0, 0, 1, 1, 0, 0, 0);
    packet->tex1Register = SCE_GS_TEX1_1;
    packet->clamp = 0;
    packet->clampRegister = SCE_GS_CLAMP_1;
    packet->test = SCE_GS_SET_TEST(1, 7, 0, 0, 0, 0, 1, 1);
    packet->testRegister = SCE_GS_TEST_1;
    packet->texa = SCE_GS_SET_TEXA(0x80, 1, 0x80);
    packet->texaRegister = SCE_GS_TEXA;
    packet->alpha = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    packet->alphaRegister = SCE_GS_ALPHA_1;
    packet->endTag.quadword = 0;
    packet->endTag.header = 0x70000000;
}
