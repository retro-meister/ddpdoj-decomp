#include "common.h"

s32 func_001A5A00();                            /* extern */
s32 func_001A5B50();                            /* extern */
s32 func_001A6050();                            /* extern */
s32 func_001A7D00();                            /* extern */
s32 func_001A7EE0();                            /* extern */
extern u8 D_0028E854;
extern u8 D_0028E961;

void func_001A5AD0(void) {
    func_001A7D00();
    func_001A7EE0();
    func_001A5A00();
    if (D_0028E854 & 1) {
        func_001A6050();
        return;
    }
    if (D_0028E961 & 8) {
        func_001A6050();
        return;
    }
    func_001A5B50();
}
