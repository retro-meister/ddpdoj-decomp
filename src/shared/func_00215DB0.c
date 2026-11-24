#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern void *D_0028E9F4;
extern u8 D_00558780[2][0x10000];

void func_00215DB0(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b) {
    Qword *packet = (Qword *)D_00558780[0];

    packet[0].q = 0;
    packet[0].w[0] = 0x1000000C;
    packet[1].d[0] = SCE_GIF_SET_TAG(2, 0, 0, 0, SCE_GIF_PACKED, 1);
    packet[1].d[1] = SCE_GIF_PACKED_AD;
    packet[2].d[0] = 0;
    packet[2].d[1] = SCE_GS_TEXFLUSH;
    packet[3].d[0] = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    packet[3].d[1] = SCE_GS_ALPHA_1;
    packet[4].d[0] = SCE_GIF_SET_TAG(1, 1, 1, 0x14C, SCE_GIF_PACKED, 8);
    packet[4].d[1] = 0x41414141;
    packet[5].w[0] = r;
    packet[5].w[1] = g;
    packet[5].w[2] = b;
    packet[5].w[3] = alpha;
    packet[6].w[0] = ((x + 0x700) << 4) + 8;
    packet[6].w[1] = ((y + 0x790) << 4) + 8;
    packet[6].w[2] = depth << 4;
    packet[6].w[3] = 0;
    packet[7].w[0] = r;
    packet[7].w[1] = g;
    packet[7].w[2] = b;
    packet[7].w[3] = alpha;
    packet[8].w[0] = ((x + 0x700) << 4) + 8;
    packet[8].w[1] = ((y + 0x790 + h) << 4) + 8;
    packet[8].w[2] = depth << 4;
    packet[8].w[3] = 0;
    packet[9].w[0] = r;
    packet[9].w[1] = g;
    packet[9].w[2] = b;
    packet[9].w[3] = alpha;
    packet[10].w[0] = ((x + 0x700 + w) << 4) + 8;
    packet[10].w[1] = ((y + 0x790) << 4) + 8;
    packet[10].w[2] = depth << 4;
    packet[10].w[3] = 0;
    packet[11].w[0] = r;
    packet[11].w[1] = g;
    packet[11].w[2] = b;
    packet[11].w[3] = alpha;
    packet[12].w[0] = ((x + 0x700 + w) << 4) + 8;
    packet[12].w[1] = ((y + 0x790 + h) << 4) + 8;
    packet[12].w[2] = depth << 4;
    packet[12].w[3] = 0;
    packet[13].q = 0;
    packet[13].w[0] = 0x70000000;
    FlushCache(0);
    sceDmaSend(D_0028E9F4, D_00558780[0]);
    sceGsSyncPath(0, 0);
}
