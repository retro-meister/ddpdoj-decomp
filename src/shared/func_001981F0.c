#include "common.h"

extern u16 D_0028E920;
s32 printf(u8 *, ...);
extern u8 D_0027D7C0[];
extern u8 D_0028E290;
extern u8 D_0028E384;
extern u8 D_0028E388;
extern u8 D_0028E38C;
extern u16 D_0028E4B0;
extern u16 D_0028E748;
extern u16 D_0028E750;

s32 func_001981F0(void) {
    if ((D_0028E38C == 1) && (D_0028E388 == 0) && (D_0028E384 == 0) && (D_0028E290 == 0) && (D_0028E750 == 0) && (D_0028E748 == 0) && (MAIN_OR_DEATH_LABEL(D_0028E4B0, D_0028E920) != 3)) {
#ifdef DEATH_LABEL
        printf(D_0027D7C0);
#else
        printf(D_0027D7C0, D_0028E4B0);
#endif
        return 1;
    }
    return 0;
}
