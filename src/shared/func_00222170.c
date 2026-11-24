#include "common.h"

extern Obj38 D_00685010[][16];
extern u8 D_0068DC10[][16];

void func_00222170(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 16; j++) {
            D_00685010[i][j].active = 0;
            D_0068DC10[i][j] = 0;
        }
    }
    for (j = 0; j < 16; j++) {
        D_00685010[12][j].active = 0;
    }
}
