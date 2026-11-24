#include "common.h"

s32 func_0018D130();                            /* extern */
s32 vibration_stop_pad1();                            /* extern */
extern s32 D_0028DF88;

void func_0018DE10(void) {
    D_0028DF88 = 3;
    func_0018D130();
    vibration_stop_pad1();
}
