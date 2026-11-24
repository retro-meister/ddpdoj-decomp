#include "common.h"

s32 func_0018D4B0();
s32 fade_start_out();
s32 func_00221120();
extern u16 D_0028E320_as_u16;
extern s8 D_0028EAE8;
extern s8 D_0028EB08;
extern s8 D_0028EB0C;
extern s8 D_0028EB14;
extern s8 D_0028EB18;
extern s8 D_0028EB1C;
extern s8 D_0028EB20;
extern s8 D_0028EB28;
extern s8 D_0028EB4C;
extern s8 D_0028EB50;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB5C;
extern s8 D_0028EB60;
extern s8 D_0028EB68;
extern s8 D_0028EB6C;
extern s8 D_0028EB70;
extern s8 D_0028EB74;
extern s8 D_0028EB84;
extern s8 D_0028EB88;
extern s8 D_0028EC18_as_s8;
extern s8 D_0028EC1A;
extern s8 D_0028EC24;
extern s32 D_0057CC70_as_s32_a[];
extern s32 D_0057CC78[];
extern s32 D_0057CC88[];
#ifdef DEATH_LABEL
extern s8 D_0028E290_as_s8;
extern s8 D_0028E2E4_as_s8;
extern s8 D_0028E304_as_s8;
extern s32 D_0028EAFC;
extern s8 D_0028EB00;
s32 func_00169BC0();
#endif

void func_0021DAA0(void) {
    s32 var_a1;

    func_00221120(0);
    var_a1 = 0;
    D_0028E320_as_u16 = 0xE10;
    if (D_0057CC88[0] == 0) {
        D_0028E320_as_u16 -= 1;
        if ((s32) D_0028E320_as_u16 <= 0) {
            var_a1 = 1;
            D_0028EB58 = MAIN_OR_DEATH_LABEL(8, 5);
        }
    } else {
        D_0028E320_as_u16 = 0xE10;
    }
    if (D_0057CC78[0] & 0x40) {
        var_a1 = 1;
        D_0028EB58 = MAIN_OR_DEATH_LABEL(8, 5);
    } else if (D_0057CC78[0] & 0x20) {
        var_a1 = 1;
    }
    D_0028EB28 = D_0028EB58;
    if (var_a1 != 0) {
        D_0028EB4C = 2;
        D_0028EB54 = 2;
        func_0018D4B0();
        D_0028EB50 = 0;
        D_0028EB54 = 0;
#ifdef DEATH_LABEL
        switch (D_0028EB58) {
        case 0:
            break;
        case 1:
            D_0028E2E4_as_s8 = 0;
            D_0028E290_as_s8 = 2;
            D_0028E304_as_s8 = 1;
            D_0028EAFC = 0xFF;
            func_00169BC0();
            fade_start_out();
            D_0028EB88 = 2;
            D_0028EB00 = 4;
            break;
        case 2:
            D_0028EB5C = 0;
            D_0028EB84 = 0x18;
            D_0028EB08 = 0;
            break;
        case 3:
            D_0028EB68 = 0;
            D_0028EB84 = 0xF;
            D_0028EB14 = 0;
            break;
        case 4:
            D_0028EB74 = 0;
            D_0028EB84 = 2;
            D_0028EB20 = 0;
            break;
        case 6:
            D_0028EB70 = 0;
            D_0028EB84 = 3;
            D_0028EB1C = 0;
            break;
        case 5:
            D_0028EB60 = 0;
            D_0028EB84 = 0x15;
            D_0028EB0C = 0;
            D_0028EAE8 = 1;
            break;
        }
#else
        switch (D_0028EB58) {
        case 0:
            break;
        case 1:
            D_0028EB6C = 0;
            D_0028EB84 = 0xE;
            D_0028EB18 = 0;
            break;
        case 3:
            D_0028EB60 = 0;
            D_0028EB84 = 0x15;
            D_0028EB0C = 0;
            D_0028EAE8 = 2;
            break;
        case 4:
            D_0028EB60 = 0;
            D_0028EB84 = 0x15;
            D_0028EB0C = 0;
            D_0028EAE8 = 1;
            break;
        case 5:
            D_0028EB5C = 0;
            D_0028EB84 = 0x18;
            D_0028EB08 = 0;
            break;
        case 6:
            D_0028EB68 = 0;
            D_0028EB84 = 0xF;
            D_0028EB14 = 0;
            break;
        case 7:
            D_0028EB74 = 0;
            D_0028EB84 = 2;
            D_0028EB20 = 0;
            break;
        case 2:
            D_0028EB84 = 7;
            D_0028EC18_as_s8 = 0xA;
            D_0028EC1A = 0;
            if (D_0057CC70_as_s32_a[0] & 0x20) {
                D_0028EC24 = 0;
            } else {
                D_0028EC24 = 1;
            }
            break;
        case 9:
            D_0028EB70 = 0;
            D_0028EB84 = 3;
            D_0028EB1C = 0;
            break;
        case 8:
            fade_start_out();
            D_0028EB88 = 2;
            break;
        }
#endif
    }
}
