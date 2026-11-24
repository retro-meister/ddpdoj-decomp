#include "common.h"

s32 func_0013CFD0();                            /* extern */
s32 func_0013F190();                            /* extern */
s32 func_001AAA20();                            /* extern */
extern s8 D_0028E284;
extern u16 D_0028E5BC;
extern s16 D_0028E5F0;

void func_0013E710(void) {
    if (D_0028E5BC == 0) {
        func_0013CFD0();
    }
    D_0028E5BC += 1;
    D_0028E5F0 = 0x95F;
    func_0013F190();
    func_001AAA20();
    D_0028E284 = 0;
}
