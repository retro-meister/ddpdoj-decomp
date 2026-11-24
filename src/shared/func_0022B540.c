#include "common.h"

s32 func_0022B330();
s32 func_0022BE60();
u8 func_00231840();
extern u8 D_0028E378;
extern u8 D_0028EAB8;
extern u8 D_0028EC4C;
extern s32 D_0028EC50;
extern u8 D_0028ED68;

s32 func_0022B540(void) {
    switch (D_0028EC50) {
    case 0:
        D_0028EC4C = 1;
        D_0028ED68 = 0;
        D_0028EC50 += 1;
        D_0028E378 = 0xFF;
        /* fallthrough */
    case 1:
        D_0028EAB8 = func_00231840();
        if (D_0028EAB8 == 0xFF) {
            D_0028EC50 = 3;
        } else {
            D_0028EAB8 -= 1;
            D_0028EC50 += 1;
        }
        break;
    case 2:
        if (func_0022BE60(D_0028EAB8) != 0) {
            D_0028EC50 += 1;
            func_0022B330();
        }
        break;
    case 3:
        D_0028EC50 = 0;
        D_0028EC4C = 0;
        return 1;
    }
    return 0;
}
