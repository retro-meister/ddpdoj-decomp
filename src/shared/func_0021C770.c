#include "common.h"

extern s32 cd_read_async(s32, s32, s32);
extern s32 D_0028EAA4;
extern s32 D_0029CAD0[];
extern s32 D_0029CAD4[];

void func_0021C770(void) {
    cd_read_async(D_0028EAA4, D_0029CAD0[0], D_0029CAD4[0]);
}
