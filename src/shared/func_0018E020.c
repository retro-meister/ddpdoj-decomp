#include "common.h"

s32 func_0018C600(s32, s32, s32);   /* extern */
s32 func_0018E060();                            /* extern */
s32 func_0018E0B0();                            /* extern */
extern s8 D_0028DF98;

void func_0018E020(void) {
    func_0018C600(0x530, 0, 0);
    if (D_0028DF98 != 0) {
        func_0018E060();
    }
    func_0018E0B0();
}
