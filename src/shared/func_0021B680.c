#include "common.h"
#include "sdk/ps2sdk.h"

typedef struct {
    s32 interlace;
    s32 ffmode;
    s32 width;
    s32 height;
} VideoMode;

extern void sceGsResetGraph(s32, s32, s32, s32);
extern void func_0021B570(s32 a, s32 b);
extern VideoMode D_0026F9E0[];
extern s32 D_0028DC98;
extern s8 D_0028E250;
extern s8 D_0028E254;
extern u8 D_0028E2DC;
extern s32 D_0028EA50;
extern s32 D_0028EA54;
extern u8 g_gs_dbuff[];
typedef struct { u64 fbp:9; u64 fbw:6; u64 psm:5; } Dispfb;
extern Dispfb D_0057C7F0[];
extern Dispfb D_0057C818[];
extern u8 D_0057C830[];
extern u8 D_0057C9A0[];

void func_0021B680(void) {
    VideoMode *mode;

    mode = &D_0026F9E0[D_0028DC98 + D_0028E2DC * 6];
    sceGsResetGraph(0, (s16)mode->interlace, 2, (s16)mode->ffmode);
    D_0028EA54 = mode->width;
    if (mode->interlace == 0) {
        sceGsSetDefDBuffDc(g_gs_dbuff, 2, (s16)mode->width, (s16)mode->height, 1, 0x31, 1);
        D_0028EA50 = (D_0028EA54 - 0x1C0) >> 1;
    } else {
        sceGsSetDefDBuffDc(g_gs_dbuff, 2, (s16)mode->width, (s16)mode->height, 1, 0x31, 0);
        D_0028EA50 = (D_0028EA54 - 0xE0) >> 1;
        D_0057C7F0[0].fbp = 0;
        D_0057C818[0].fbp = ((((mode->width + 63) / 64 * 64) * ((mode->height + 31) / 32 * 32)) >> 11) / 2;
    }
    func_0021B570(D_0028E254, D_0028E250);
    FlushCache(0);
    sceGsSyncV(0);
    sceGsPutDrawEnv(D_0057C830);
    sceGsSyncPath(0, 0);
    sceGsPutDrawEnv(D_0057C9A0);
    sceGsSyncPath(0, 0);
}
