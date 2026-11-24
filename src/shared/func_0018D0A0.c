#include "common.h"

s32 func_0018C6C0();
extern s32 D_0028DF88;
extern s32 D_0028DF8C;
extern s32 D_0028DF90;
extern u16 D_0028E3C0;

void func_0018D0A0(s32 arg0) {
    s32 a1;
    s32 a2;
    s32 a3;

    if (D_0028E3C0 == 0) {
        a1 = arg0;
        if (arg0 != 0) {
            a1 -= 1;
        }
        a2 = D_0028DF8C;
        a2 -= 0x1E;
        a3 = D_0028DF88;
        if (a2 < 0) {
            a2 = 0;
        }
        if ((arg0 == 2) || (arg0 == 0xA) || (arg0 == 0x12) || (arg0 == 0x2D) || (arg0 == 0x32) || (arg0 == 0x25)) {
            a1 |= 0x80;
        }
        D_0028DF90 = func_0018C6C0(0x580, a1, a2, a3);
    }
}
