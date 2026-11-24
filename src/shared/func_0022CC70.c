#include "common.h"

s32 sceMcSync(s32, s32, s32 *);
s32 sceMcGetInfo(s32, s32, s32 *, u8 *, s32 *);
s32 sceGsSyncV(s32);
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s32 D_0028ECAC;
extern s32 D_0028ECB0;
extern u8 D_0028ECB4_as_u8;
extern s32 D_0028ECB8;

s32 func_0022CC70(s32 arg0) {
    s32 result;
    s32 ret;
    s32 tries;

    tries = 0;
retry:
    D_0028ECAC = sceMcGetInfo(D_0028EC70, D_0028EC74, &D_0028ECB8, &D_0028ECB4_as_u8, &D_0028ECB0);
    if (D_0028ECAC != 0) {
        sceGsSyncV(0);
        sceMcSync(0, 0, &result);
        goto retry;
    }
    sceMcSync(0, 0, &result);
    ret = 0;
    switch (result) {
    case 0:
        if (D_0028ECB0 == 0) {
            ret = 1;
        }
        if (D_0028ECB8 != 2) {
            ret = 2;
        }
        break;
    case -1:
    case -2:
        ret = 4;
        break;
    default:
        ret = 3;
        break;
    }
    if (ret != 0 && (arg0 != 1 || ret != 4)) {
        sceGsSyncV(0);
        tries++;
        if (tries < 6) {
            goto retry;
        }
    }
    return ret;
}
