#include "common.h"

extern s32 D_0028EAA0;
extern s32 D_0029CAC8[];
extern s32 D_0029CACC[];

void cd_read_async(s32, s32, s32);

void func_0021C790(void) {
    cd_read_async(D_0028EAA0, D_0029CAC8[0], D_0029CACC[0]);
}
