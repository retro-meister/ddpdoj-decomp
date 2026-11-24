#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

typedef struct {
    s16 x;
    s16 y;
    u16 depth;
    u16 u;
    u16 v;
    u16 tex;
    u16 w;
    u16 h;
    u16 alpha;
} SpriteEntry;

extern SpriteEntry D_002C2B00[];

void func_00214230(Qword *packet, s32 firstEntry, s32 entryCount)
{
    s32 packetIndex;
    s32 entryIndex;

    packetIndex = 1;
    packet[0].q = 0;
    packet[0].w[0] = (entryCount * 10) | 0x10000000;

    for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
        s32 x = D_002C2B00[firstEntry].x;
        s32 y = D_002C2B00[firstEntry].y;
        s32 depth = D_002C2B00[firstEntry].depth;
        s32 textureU = D_002C2B00[firstEntry].u;
        s32 textureV = D_002C2B00[firstEntry].v;
        s32 width = D_002C2B00[firstEntry].w;
        s32 height = D_002C2B00[firstEntry].h;
        s32 alpha = D_002C2B00[firstEntry].alpha;
        s32 texturePage = D_002C2B00[firstEntry].tex;
        s32 textureBase;

        if (texturePage == 0x14) {
            textureBase = 0x37FA;
        } else {
            textureBase = texturePage + 0x37E8;
        }

        firstEntry++;

        packet[packetIndex].d[0] = SCE_GIF_SET_TAG(2, 0, 0, 0, SCE_GIF_PACKED, 1);
        packet[packetIndex].d[1] = SCE_GIF_PACKED_AD;
        packetIndex++;

        packet[packetIndex].d[0] = 0;
        packet[packetIndex].d[1] = SCE_GS_TEXFLUSH;
        packetIndex++;

        packet[packetIndex].d[0] =
            SCE_GS_SET_TEX0(0x3800, 16, SCE_GS_PSMT4, 10, 10, 1, 0, textureBase, SCE_GS_PSMCT32, 0, 0, 1);
        packet[packetIndex].d[1] = SCE_GS_TEX0_1;
        packetIndex++;

        packet[packetIndex].d[0] = SCE_GIF_SET_TAG(1, 1, 1, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 1, 1, 1, 0, 0), SCE_GIF_PACKED, 6);
        packet[packetIndex].d[1] = 0x431431;
        packetIndex++;

        packet[packetIndex].w[0] = 0x7F;
        packet[packetIndex].w[1] = 0x7F;
        packet[packetIndex].w[2] = 0x7F;
        packet[packetIndex].w[3] = alpha;
        packetIndex++;

        packet[packetIndex].w[0] = textureU << 4;
        packet[packetIndex].w[1] = textureV << 4;
        packet[packetIndex].w[2] = 0;
        packet[packetIndex].w[3] = 0;
        packetIndex++;

        packet[packetIndex].w[0] = (u32)(x + 0x700) << 4;
        packet[packetIndex].w[1] = ((u32)y << 3) + 0x7900;
        packet[packetIndex].w[2] = depth << 4;
        packet[packetIndex].w[3] = 0;
        packetIndex++;

        packet[packetIndex].w[0] = 0x7F;
        packet[packetIndex].w[1] = 0x7F;
        packet[packetIndex].w[2] = 0x7F;
        packet[packetIndex].w[3] = alpha;
        packetIndex++;

        packet[packetIndex].w[0] = (textureU + 0x1A) << 4;
        packet[packetIndex].w[1] = (textureV + 0x1A) << 4;
        packet[packetIndex].w[2] = 0;
        packet[packetIndex].w[3] = 0;
        packetIndex++;

        packet[packetIndex].w[0] = (u32)(x + 0x700 + width) << 4;
        packet[packetIndex].w[1] = (((height >> 1) + 0x790) << 4) + ((u32)y << 3);
        packet[packetIndex].w[2] = depth << 4;
        packet[packetIndex].w[3] = 0;
        packetIndex++;
    }

    packet[packetIndex].q = 0;
    packet[packetIndex].w[0] = 0x70000000;
}
