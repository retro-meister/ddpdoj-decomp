#include "gallery/gallery.h"

typedef struct
{
    s32 type;
    s32 dbw;
    s32 x;
    s32 y;
    s32 width;
    s32 height;
} TexUploadInfo;

extern TexUploadInfo D_0026F870[];
extern s32 D_0028EA74;
extern u16 D_0028E91C;
extern u8 D_004CCF80[];
extern sceGsLoadImage D_0057C780;

void func_002185B0(void)
{
    D_0028EA74 = 0x2240;
    sceGsSetDefLoadImage(&D_0057C780, 0x2240, D_0026F870[5].dbw, SCE_GS_PSMT8, D_0026F870[5].x, D_0026F870[5].y,
                         D_0026F870[5].width, D_0026F870[5].height);
    FlushCache(0);
    sceGsExecLoadImage(&D_0057C780, D_004CCF80 + D_0028E91C * 0x4E00 + 0x200);
    sceGsSyncPath(0, 0);
}
