#include "common.h"

s32 func_00201920();                            /* extern */
s32 func_00201B30();                            /* extern */
extern u8 D_0028E855;

void func_002018E0(void) {
    if (!(D_0028E855 & 2)) {
        func_00201920();
        return;
    }
    func_00201B30();
}
