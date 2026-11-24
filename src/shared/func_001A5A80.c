#include "common.h"

s32 func_001A5AD0();                            /* extern */
s32 func_001A68B0();                            /* extern */
s32 func_001A8970();                            /* extern */
s32 func_001A89E0();                            /* extern */
extern u16 D_0028E59C;

void func_001A5A80(void) {
    func_001A89E0();
    func_001A8970();
    if (D_0028E59C != 0) {
        func_001A68B0();
        return;
    }
    func_001A5AD0();
}
