#include "common.h"

s32 func_00226260();
s32 func_002263F0();
s32 func_002273E0();
s32 func_00228060();
extern s8 D_0028EB50;
extern s8 D_0028EB54;
extern s8 D_0028EB84;
extern s8 D_0028EBE1;
extern s16 D_0028EBE4;
extern s8 D_0028EC10;
extern s8 D_0028EC12;

void func_00227FE0(void) {
    s32 temp_v0;

    func_002273E0();
    temp_v0 = func_00226260();
    switch (temp_v0) {                              /* irregular */
    case 0:
        D_0028EB54 = 0;
        D_0028EC12 = 4;
        D_0028EB50 = 0;
        D_0028EB84 = 8;
        D_0028EBE1 = 0;
        D_0028EBE4 = 0;
        D_0028EC10 = 0;
        break;
    case 3:
        func_00228060();
        func_002263F0();
        break;
    }
}
