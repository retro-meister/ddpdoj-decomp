#include "common.h"

s32 func_0018D010(s32);                     /* extern */
s32 func_00217BB0(s32, s32);            /* extern */
s32 func_00217C20(s32, s32);            /* extern */
extern s32 D_0028DF88;
extern s32 D_0028DF8C;
extern s8 D_0028E310;

void func_0018D660(void) {
    D_0028E310 = 0x3C;
    D_0028DF8C = 0xA8;
    D_0028DF88 = 0;
    func_0018D010(0x2A);
    D_0028DF8C = 0xA8;
    D_0028DF88 = 0;
    func_0018D010(0x2B);
    D_0028DF8C = 0xA8;
    D_0028DF88 = 0;
    func_0018D010(0x2A);
    func_00217BB0(0xC8, 0x50);
    func_00217C20(0xC8, 0x50);
}
