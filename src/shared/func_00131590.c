#include "common.h"

s32 func_0018DA10();                            /* extern */
extern u16 D_0028E954;

void func_00131590(void) {
    if (D_0028E954 != 0) {
        D_0028E954 -= 1;
        return;
    }
    D_0028E954 = 3;
    func_0018DA10();
}
