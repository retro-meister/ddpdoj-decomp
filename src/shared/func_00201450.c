#include "common.h"

extern s8 D_0028E408;
extern u16 D_00299764[];
extern u16 D_00299766[];

void func_00201450(void) {
    D_0028E408 = 0;
    if ((D_00299764[0] != 0) && ((s32) D_00299766[0] >= 0x20) && ((s32) D_00299766[0] < 0x3D)) {
        D_0028E408 = 1;
    }
}
