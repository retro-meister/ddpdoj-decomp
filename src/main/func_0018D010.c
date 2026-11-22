#include "common.h"

s32 func_0018C600(s32, s32, s32);
extern s32 D_0028DF8C;
extern s32 D_0028DF90;
extern u16 D_0028E3C0;

void func_0018D010(s32 arg0) {
    s32 var_a1;
    s32 var_a2;

    var_a1 = arg0;
    if (D_0028E3C0 == 0) {
        if (arg0 != 0) {
            var_a1 -= 1;
        }
        var_a2 = D_0028DF8C;
        var_a2 -= 0x1E;
        if (var_a2 < 0) {
            var_a2 = 0;
        }
        if ((arg0 == 2) || (arg0 == 0xA) || (arg0 == 0x12) || (arg0 == 0x2D) || (arg0 == 0x32) || (arg0 == 0x25)) {
            var_a1 |= 0x80;
        }
        D_0028DF90 = func_0018C600(0x500, var_a1, var_a2);
    }
}
