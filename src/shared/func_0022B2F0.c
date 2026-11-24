#include "common.h"

s32 func_0022B4B0();                            /* extern */
s32 func_0022B540();                            /* extern */
extern u8 D_0028EC30;

void func_0022B2F0(void) {
    if (D_0028EC30 == 0) {
        func_0022B4B0();
        return;
    }
    func_0022B540();
}
