#include "common.h"

s32 func_00130050();                            /* extern */
s32 func_0016A420();                            /* extern */
s32 func_0016A4A0();                            /* extern */

void func_0016A3E0(void) {
    func_00130050();
    if (reg_d1.h[0] != 0) {
        func_0016A4A0();
        return;
    }
    func_0016A420();
}
