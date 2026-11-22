#include "common.h"

extern u16 D_0028E2FC;
extern u16 D_0028E300;
extern s32 D_0028EC78;

s32 func_002368E0(void) {
    D_0028EC78 = 0;
    D_0028E2FC = D_0028E300;
    return 1;
}
