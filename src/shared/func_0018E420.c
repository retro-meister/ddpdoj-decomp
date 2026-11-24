#include "common.h"

void cd_search_file(s32);
extern s32 D_0025BCF0[];
extern s32 D_0029CAB0_as_s32_a_a2[][2];
extern s32 g_cd_file[];
extern s32 D_002C0104[];

void func_0018E420(void) {
    s32 i;

    for (i = 0; i < MAIN_OR_DEATH_LABEL(0xE, 0x10); i++) {
        cd_search_file(D_0025BCF0[i]);
        D_0029CAB0_as_s32_a_a2[i][0] = D_002C0104[0];
        D_0029CAB0_as_s32_a_a2[i][1] = g_cd_file[0];
    }
}
