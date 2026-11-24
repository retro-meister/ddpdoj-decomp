#include "common.h"

extern Obj38 D_00685010_as_Obj38_a_a16[][16];
extern u8 D_0068DC10_as_u8_a_a16[][16];

void func_00222170(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 16; j++) {
            D_00685010_as_Obj38_a_a16[i][j].active = 0;
            D_0068DC10_as_u8_a_a16[i][j] = 0;
        }
    }
    for (j = 0; j < 16; j++) {
        D_00685010_as_Obj38_a_a16[12][j].active = 0;
    }
}
