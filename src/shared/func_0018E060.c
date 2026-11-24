#include "common.h"

s32 func_0018C600(s32, s32, s32);       /* extern */
extern s8 D_0028DF98;
extern s32 D_0029CA10_as_s32_a[];
extern s32 D_0029CA14_as_s32_a[];

void func_0018E060(void) {
    if (func_0018C600(0x100, 0, 0) == 0) {
        func_0018C600(0x150, 0, 0);
        D_0028DF98 = 0;
        D_0029CA10_as_s32_a[0] = 0;
        D_0029CA14_as_s32_a[0] = 0;
    }
}
