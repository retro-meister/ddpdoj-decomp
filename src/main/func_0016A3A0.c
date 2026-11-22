#include "common.h"

s32 func_0012FFE0();                            /* extern */
s32 func_0016A420();                            /* extern */
s32 func_0016A4A0();                            /* extern */

void func_0016A3A0(void) {
    func_0012FFE0();
    if (reg_d1.h[0] != 0) {
        func_0016A4A0();
        return;
    }
    func_0016A420();
}
