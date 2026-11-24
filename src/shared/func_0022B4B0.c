#include "common.h"

s32 func_0022B330();
s32 func_0022C780();
extern u8 D_0028E378;
extern u8 D_0028EC4C;
extern s32 D_0028EC50;
extern s32 D_0028ECC4;
extern s32 D_0028ED0C;
extern u8 D_0028ED68;

s32 func_0022B4B0(void) {
    switch (D_0028EC50) {                           /* irregular */
    case 0:
        D_0028EC4C = 1;
        D_0028ED0C = 0;
        D_0028EC50 += 1;
        D_0028ED68 = 0;
        D_0028E378 = 0xFF;
        /* fallthrough */
    case 1:
        func_0022C780();
        if (D_0028ED0C != 0) {
            D_0028ED0C = 0;
            D_0028EC50 = 0;
            D_0028EC4C = 0;
            if (D_0028ECC4 != 0) {
                func_0022B330();
            }
            return 1;
        }
    default:
        return 0;
    }
}
