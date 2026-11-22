#include "common.h"

s32 func_0013D000();                            /* extern */
s32 func_0013F120();                            /* extern */
s32 func_001AA8F0();                            /* extern */
extern s8 D_0028E288;
extern u16 D_0028E5C0;
extern s16 D_0028E5F4;

void func_0013E6C0(void) {
    if (D_0028E5C0 == 0) {
        func_0013D000();
    }
    D_0028E5C0 += 1;
    D_0028E5F4 = 0x95F;
    func_0013F120();
    func_001AA8F0();
    D_0028E288 = 0;
}
