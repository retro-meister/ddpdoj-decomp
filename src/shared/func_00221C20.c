#include "common.h"

s32 func_0018D4B0(s32);                         /* extern */
extern s32 D_0028EAEC;
extern s32 D_0028EAF0;
extern s32 D_0028EAF8;
extern s32 D_0028EAFC;
extern s8 D_0028EB58;
extern s32 D_0057CC78[];

s32 func_00221C20(void) {
    s32 var_s0;

    var_s0 = 0;
    if (D_0028EAFC == 0xFF) {
        return 1;
    }
    switch (D_0028EAF8) {                           /* irregular */
    case 0:
        D_0028EAF0 = 1;
        D_0028EB58 = (s8) D_0028EAFC;
        D_0028EAF8 += 1;
        D_0028EAEC = 0;
        break;
    case 1:
        if ((D_0028EAF0 == 3) && (D_0057CC78[0] & 0x20)) {
            func_0018D4B0(D_0028EAFC);
            D_0028EAF0 = 2;
            D_0028EAF8 += 1;
        }
        break;
    case 2:
        if (D_0028EAF0 == 0) {
            D_0028EAF8 = 0;
            var_s0 = 1;
        }
        break;
    }
    return var_s0;
}
