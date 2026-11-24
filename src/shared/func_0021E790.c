#include "common.h"

s32 func_0018D4B0();
s32 func_0021E8D0();
s32 func_0021EA10();
s32 func_00221120();
s32 func_00222260();
extern u16 D_0028E320_as_u16;
extern s8 D_0028EB04;
extern s8 D_0028EB1C;
extern s8 D_0028EB40;
extern s8 D_0028EB4C;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB70;
extern s8 D_0028EB7C;
extern s8 D_0028EB84;
extern s32 D_0028EB90;
extern s32 D_0057CC78[];
extern s32 D_0057CC88[];
void func_0021E790(void) {
    s32 var_a1;

    if (func_00221120(3) == 0) {
        func_0021E8D0();
    }
    func_0021EA10();
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (D_0057CC88[0] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = MAIN_OR_DEATH_LABEL(5, 7);
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (D_0057CC78[0] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB1C = D_0028EB58;
    if (D_0057CC78[0] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = MAIN_OR_DEATH_LABEL(5, 7);
    }
    if (var_a1 != 0) {
        switch (D_0028EB58) {
        case 1:
        case 2:
        case 3:
        case 4:
#ifdef DEATH_LABEL
        case 5:
        case 6:
#endif
            break;
        case MAIN_OR_DEATH_LABEL(5, 7):
            func_0018D4B0();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB84 = 0;
            D_0028EB90 = 0x40;
            D_0028EB4C = 1;
            D_0028EB54 = 2;
            D_0028EB40 = 2;
            D_0028EB04 = 1;
            D_0028EB70 += 1;
            break;
        }
    }
}
