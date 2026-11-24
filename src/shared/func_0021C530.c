#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern sceGsLoadImage g_gs_load_image;
extern s32 g_clut_upload_cbp;
extern u8 *D_0028EA98;
extern u8 *D_0028EA9C;
extern u8 *D_0028EAA0;
extern u8 *D_0028EAA4;
extern s32 D_0029CAB8[];
extern s32 D_0029CABC[];
extern s32 D_0029CAC0[];
extern s32 D_0029CAC4[];
extern s32 D_0029CB08[];
extern s32 D_0029CB0C[];
extern s32 D_0029CB10[];
extern s32 D_0029CB14[];
extern s32 D_0029CB18[];
extern s32 D_0029CB1C[];
extern u8 D_004CCF80[];
#ifdef DEATH_LABEL
extern s32 death_D_002CC808[];
extern s32 death_D_002CC80C[];
extern u8 death_D_0056A800[];
#endif
extern u8 D_004ECF80[];
void *memalign(u32 align, u32 size);
void free(void *pointer);
void cd_read_sync(u8 *dst, s32 a, s32 b);
void clut_upload(u8 *destination, s32 mode, s32 blockCount);

void func_0021C530(void) {
    u8 *buffer;

    buffer = memalign(0x40, 0x80000);
    cd_read_sync(buffer, D_0029CAB8[0], D_0029CABC[0]);
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2640, 8, SCE_GS_PSMT8, 0, 0, 512, 512);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, buffer);
    sceGsSyncPath(0, 0);
    cd_read_sync(buffer, D_0029CAC0[0], D_0029CAC4[0]);
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2A40, 0x10, SCE_GS_PSMT8, 0, 0, 1024, 256);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, buffer);
    sceGsSyncPath(0, 0);
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2A40, 0x10, SCE_GS_PSMT8, 0, 256, 1024, 256);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, buffer + 0x40000);
    sceGsSyncPath(0, 0);
    free(buffer);
    D_0028EAA4 = memalign(0x40, 0x10000);
    D_0028EAA0 = memalign(0x40, 0xC20000);
    D_0028EA9C = memalign(0x40, 0x885800);
    D_0028EA98 = memalign(0x40, 0x10800);
    cd_read_sync(D_0028EA98, D_0029CB08[0], D_0029CB0C[0]);
    g_clut_upload_cbp = 0x3834;
    clut_upload(D_0028EA98, 1, 1);
    cd_read_sync(D_004ECF80, D_0029CB10[0], D_0029CB14[0]);
    g_clut_upload_cbp = 0x3836;
    clut_upload(D_004ECF80, 1, 1);
    cd_read_sync(D_004CCF80, D_0029CB18[0], D_0029CB1C[0]);
    g_clut_upload_cbp = 0x3838;
    clut_upload(D_004CCF80, 1, 1);
#ifdef DEATH_LABEL
    cd_read_sync(death_D_0056A800, death_D_002CC808[0], death_D_002CC80C[0]);
    g_clut_upload_cbp = 0x383C;
    clut_upload(death_D_0056A800, 1, 1);
#endif
}
