#include "common.h"

s32 func_002075F0();                            /* extern */
extern u8 D_0028E304;
extern u16 D_0028E910;

void func_001B1920(void) {
    func_002075F0();
    if ((D_0028E304 != 0) && (D_0028E910 == 0)) {
        D_0028E910 = 1;
    }
}
