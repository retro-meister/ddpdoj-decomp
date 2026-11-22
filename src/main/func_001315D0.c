#include "common.h"

s32 func_0018DA10();                            /* extern */
extern u16 D_0028E950;

void func_001315D0(void) {
    if (D_0028E950 != 0) {
        D_0028E950 -= 1;
        return;
    }
    D_0028E950 = 3;
    func_0018DA10();
}
