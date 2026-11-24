#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern sceGsLoadImage D_0057C780;
extern s32 D_0028EA78;
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
void func_00216160(u8 *dst, s32 a, s32 b);
void func_00218990(u8 *destination, s32 mode, s32 blockCount);

void func_0021C530(void) {
    u8 *buffer;

    buffer = memalign(0x40, 0x80000);
    func_00216160(buffer, D_0029CAB8[0], D_0029CABC[0]);
    sceGsSetDefLoadImage(&D_0057C780, 0x2640, 8, SCE_GS_PSMT8, 0, 0, 512, 512);
    FlushCache(0);
    sceGsExecLoadImage(&D_0057C780, buffer);
    sceGsSyncPath(0, 0);
    func_00216160(buffer, D_0029CAC0[0], D_0029CAC4[0]);
    sceGsSetDefLoadImage(&D_0057C780, 0x2A40, 0x10, SCE_GS_PSMT8, 0, 0, 1024, 256);
    FlushCache(0);
    sceGsExecLoadImage(&D_0057C780, buffer);
    sceGsSyncPath(0, 0);
    sceGsSetDefLoadImage(&D_0057C780, 0x2A40, 0x10, SCE_GS_PSMT8, 0, 256, 1024, 256);
    FlushCache(0);
    sceGsExecLoadImage(&D_0057C780, buffer + 0x40000);
    sceGsSyncPath(0, 0);
    free(buffer);
    D_0028EAA4 = memalign(0x40, 0x10000);
    D_0028EAA0 = memalign(0x40, 0xC20000);
    D_0028EA9C = memalign(0x40, 0x885800);
    D_0028EA98 = memalign(0x40, 0x10800);
    func_00216160(D_0028EA98, D_0029CB08[0], D_0029CB0C[0]);
    D_0028EA78 = 0x3834;
    func_00218990(D_0028EA98, 1, 1);
    func_00216160(D_004ECF80, D_0029CB10[0], D_0029CB14[0]);
    D_0028EA78 = 0x3836;
    func_00218990(D_004ECF80, 1, 1);
    func_00216160(D_004CCF80, D_0029CB18[0], D_0029CB1C[0]);
    D_0028EA78 = 0x3838;
    func_00218990(D_004CCF80, 1, 1);
#ifdef DEATH_LABEL
    func_00216160(death_D_0056A800, death_D_002CC808[0], death_D_002CC80C[0]);
    D_0028EA78 = 0x383C;
    func_00218990(death_D_0056A800, 1, 1);
#endif
}
