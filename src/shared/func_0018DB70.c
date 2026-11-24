#include "common.h"

s32 func_0018D010(s32);                     /* extern */
s32 func_00217BB0(s32, s32);            /* extern */
s32 func_00217C20(s32, s32);            /* extern */
extern s32 D_0028DF88;
extern s32 D_0028DF8C;

void func_0018DB70(void) {
    D_0028DF8C = 0xFF;
    D_0028DF88 = 0xA;
    func_0018D010(0x24);
    func_00217BB0(0xA0, 0x12C);
    func_00217C20(0xA0, 0x12C);
}
