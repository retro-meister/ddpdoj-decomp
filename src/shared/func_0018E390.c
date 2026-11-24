#include "common.h"

void cd_search_file(s32);
extern s32 D_0025BCC0[];
extern s32 D_0029CB50[][2];
extern s32 g_cd_file_as_s32_a[];
extern s32 D_002C0104[];

void func_0018E390(void) {
    s32 i;

    for (i = 0; i < 0xA; i++) {
        cd_search_file(D_0025BCC0[i]);
        D_0029CB50[i][0] = D_002C0104[0];
        D_0029CB50[i][1] = g_cd_file_as_s32_a[0];
    }
}
