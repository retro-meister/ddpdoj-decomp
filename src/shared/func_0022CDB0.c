#include "common.h"

s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
s32 sceMcGetInfo(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 *arg4);
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s32 D_0028ECAC;
extern s32 D_0028ECB0;
extern s32 D_0028ECB4;
extern s32 D_0028ECB8;
extern s32 D_0028ECC8;
extern s32 D_0028ECCC;
extern s32 D_0028ECD0;

void func_0022CDB0(s32 arg0) {
    s32 result;
    s32 error;

    switch (D_0028ECCC) {
    case 0:
        if (sceMcSync(1, 0, &result) != 0) {
            D_0028ECC8 = 0;
            D_0028ECD0 = 6;
            D_0028ECCC += 1;
        }
        break;
    case 1:
        D_0028ECAC = sceMcGetInfo(D_0028EC70, D_0028EC74, &D_0028ECB8, &D_0028ECB4, &D_0028ECB0);
        if (D_0028ECAC == 0) {
            D_0028ECCC += 1;
        }
        break;
    case 2:
        if (sceMcSync(1, 0, &result) != 0) {
            error = 0;
            switch (result) {
            case 0:
                if (D_0028ECB0 == 0) {
                    error = 1;
                }
                if (D_0028ECB8 != 2) {
                    error = 2;
                }
                break;
            case -1:
            case -2:
                error = 4;
                break;
            default:
                error = 3;
                break;
            }
            D_0028ECC8 = error;
            if ((error == 0) || ((arg0 == 1) && (error == 4))) {
                D_0028ECCC = 0;
                D_0028ECD0 = 0;
            } else {
                D_0028ECCC = 1;
                D_0028ECD0 -= 1;
                if (D_0028ECD0 <= 0) {
                    D_0028ECCC = 0;
                    D_0028ECD0 = 0;
                }
            }
        }
        break;
    }
}
