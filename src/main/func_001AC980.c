#include "common.h"

s32 func_001AC9D0();                            /* extern */
extern s8 D_0028E634;
extern u8 D_0028E854;

void func_001AC980(void) {
    if (!(D_0028E854 & 1)) {
        func_001AC9D0();
        return;
    }
    if (D_0028E634 < 0) {
        func_001AC9D0();
    }
}
