#include "common.h"

s32 sceCdBreak();                            /* extern */
extern s8 D_0028E374;
extern s8 D_0028E9B8;
extern s8 D_0028E9BC;
extern s8 D_0028EC64;

void func_00225630(void) {
    D_0028EC64 = 0;
    if (D_0028E9B8 != 0) {
        sceCdBreak();
    }
    D_0028E9B8 = 0;
    D_0028E374 = 1;
    D_0028E9BC = 1;
}
