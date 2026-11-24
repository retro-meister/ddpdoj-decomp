#include "common.h"

extern s32 D_00684CF0[10][4][5];

void func_0021D500(void) {
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 5; k++) {
                D_00684CF0[i][j][k] = 0;
            }
        }
    }
}
