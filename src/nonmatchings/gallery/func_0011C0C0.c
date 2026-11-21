#include "common.h"

typedef struct {
    s16 x;
    s16 y;
    u16 depth;
    u16 textureU;
    u16 textureV;
    u16 texturePage;
    u16 width;
    u16 height;
    u16 alpha;
} GallerySprite;

typedef union {
    unsigned __int128 quadword;
    u64 doublewords[2];
    u32 words[4];
} GalleryPacketQword;

extern GallerySprite D_00132E80[];

void func_0011C0C0(GalleryPacketQword *packet, s32 firstEntry, s32 entryCount)
{
    s32 packetIndex;
    s32 entryIndex;

    packetIndex = 1;
    packet[0].quadword = 0;
    packet[0].words[0] = (entryCount * 10) | 0x10000000;

    for (entryIndex = 0; entryIndex < entryCount; entryIndex++, firstEntry++) {
        s32 x = D_00132E80[firstEntry].x;
        s32 y = D_00132E80[firstEntry].y;
        s32 depth = D_00132E80[firstEntry].depth;
        s32 textureU = D_00132E80[firstEntry].textureU;
        s32 textureV = D_00132E80[firstEntry].textureV;
        s32 texturePage = D_00132E80[firstEntry].texturePage;
        s32 width = D_00132E80[firstEntry].width;
        s32 height = D_00132E80[firstEntry].height;
        s32 alpha = D_00132E80[firstEntry].alpha;
        s32 textureBase;

        if (texturePage == 0x14) {
            textureBase = 0x37FA;
        } else {
            textureBase = texturePage + 0x37E8;
        }

        x += 0x700;
        width += x;
        depth <<= 4;
        height >>= 1;

        packet[packetIndex].doublewords[0] = 0x1000000000000002ULL;
        packet[packetIndex].doublewords[1] = 0x0E;
        packetIndex++;

        packet[packetIndex].doublewords[0] = 0;
        packet[packetIndex].doublewords[1] = 0x3F;
        packetIndex++;

        packet[packetIndex].doublewords[0] =
            ((u64)textureBase << 37) | 0x20000006A9443800ULL;
        packet[packetIndex].doublewords[1] = 0x06;
        packetIndex++;

        packet[packetIndex].doublewords[0] = 0x60EB400000008001ULL;
        packet[packetIndex].doublewords[1] = 0x431431;
        packetIndex++;

        packet[packetIndex].words[0] = 0x7F;
        packet[packetIndex].words[1] = 0x7F;
        packet[packetIndex].words[2] = 0x7F;
        packet[packetIndex].words[3] = alpha;
        packetIndex++;

        packet[packetIndex].words[0] = textureU << 4;
        packet[packetIndex].words[1] = textureV << 4;
        packet[packetIndex].words[2] = 0;
        packet[packetIndex].words[3] = 0;
        packetIndex++;

        packet[packetIndex].words[0] = x << 4;
        packet[packetIndex].words[1] = (y << 3) + 0x7900;
        packet[packetIndex].words[2] = depth;
        packet[packetIndex].words[3] = 0;
        packetIndex++;

        packet[packetIndex].words[0] = 0x7F;
        packet[packetIndex].words[1] = 0x7F;
        packet[packetIndex].words[2] = 0x7F;
        packet[packetIndex].words[3] = alpha;
        packetIndex++;

        packet[packetIndex].words[0] = (textureU + 0x1A) << 4;
        packet[packetIndex].words[1] = (textureV + 0x1A) << 4;
        packet[packetIndex].words[2] = 0;
        packet[packetIndex].words[3] = 0;
        packetIndex++;

        packet[packetIndex].words[0] = width << 4;
        packet[packetIndex].words[1] = (y << 3) + ((height + 0x790) << 4);
        packet[packetIndex].words[2] = depth;
        packet[packetIndex].words[3] = 0;
        packetIndex++;
    }

    packet[packetIndex].quadword = 0;
    packet[packetIndex].words[0] = 0x70000000;
}
