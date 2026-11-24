#include "common.h"

s32 func_00202180();                            /* extern */
s32 func_002024C0();                            /* extern */
extern s8 D_0028E408;

void func_00202490(void) {
    func_00202180();
    if (D_0028E408 == 0) {
        func_002024C0();
    }
}
