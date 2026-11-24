#include "common.h"

s32 func_00217A20();
s32 func_00217A40();
extern s8 D_0028E2F4;
extern s8 D_0028E408;
extern u16 D_0028E990;
extern u16 D_0028E994;
extern s8 D_0028E9E8;

void func_00122C20(void) {
    switch (D_0028E994) {
    case 0:
        D_0028E2F4 = 1;
        if (D_0028E9E8 != 0) break;
        D_0028E994 += 1;
        break;
    case 1:
        D_0028E990 -= 1;
        if ((s32) D_0028E990 > 0) break;
        func_00217A40();
        D_0028E994 += 1;
        break;
    case 2:
        if (D_0028E9E8 != 0) break;
        D_0028E994 += 1;
        break;
    }
    if ((s32) D_0028E994 >= 3) {
        func_00217A20();
        D_0028E2F4 = 0;
        D_0028E408 = 0;
        return;
    }
    D_0028E408 = 1;
}
