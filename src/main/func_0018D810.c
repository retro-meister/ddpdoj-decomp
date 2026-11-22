#include "common.h"

s32 func_0018D0A0(s32);                     /* extern */
s32 func_00217C20(s32, s32);            /* extern */
extern s32 D_0028DF88;
extern s32 D_0028DF8C;

void func_0018D810(void) {
    D_0028DF8C = 0xFA;
    D_0028DF88 = 4;
    func_0018D0A0(0x12);
    func_00217C20(0x8C, 0x4B0);
}
