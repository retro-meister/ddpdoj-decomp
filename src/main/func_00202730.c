#include "common.h"

s32 func_00202760();                            /* extern */
s32 func_002032A0();                            /* extern */
extern s8 D_0028E408;

void func_00202730(void) {
    func_002032A0();
    if (D_0028E408 == 0) {
        func_00202760();
    }
}
