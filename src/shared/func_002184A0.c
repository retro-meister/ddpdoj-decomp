#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

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
extern u8 D_004ED000[];
extern u8 D_004ED180[];
extern sceGsLoadImage g_gs_load_image;

void func_002184A0(void)
{
    D_0028EA74 = 0x2240;
    switch (D_0026F870[4].type) {
    case 0:
        sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, D_0026F870[4].dbw, SCE_GS_PSMT4, D_0026F870[4].x, D_0026F870[4].y,
                             D_0026F870[4].width, D_0026F870[4].height);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, D_004ED000);
        sceGsSyncPath(0, 0);
        break;
    case 1:
        sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, D_0026F870[4].dbw, SCE_GS_PSMT8, D_0026F870[4].x, D_0026F870[4].y,
                             D_0026F870[4].width, D_0026F870[4].height);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, D_004ED180);
        sceGsSyncPath(0, 0);
        break;
    case 2:
        break;
    }
}
