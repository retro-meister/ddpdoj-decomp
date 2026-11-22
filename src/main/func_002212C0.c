#include "common.h"

s32 func_0018D4D0();                            /* extern */
extern s8 D_0028EB58;
extern s32 D_0057CC68[];

s32 func_002212C0(void) {
    if (D_0057CC68[0] & 0x1000) {
        func_0018D4D0();
        D_0028EB58 -= 1;
        if (D_0028EB58 < 0) {
            D_0028EB58 = 4;
        }
        return 1;
    }
    if (D_0057CC68[0] & 0x4000) {
        func_0018D4D0();
        D_0028EB58 += 1;
        if (D_0028EB58 >= 5) {
            D_0028EB58 = 0;
        }
        return 1;
    }
    return 0;
}
