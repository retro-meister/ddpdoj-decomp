#include "common.h"

s32 func_00226440();
s32 func_00226450();
s32 func_00226490();
s32 func_002264D0();
s32 func_00226620();
s32 func_00226700();
s32 func_00226830();
s32 func_00226850();
s32 func_00226890();
s32 func_002268A0();
s32 func_002269B0();
s32 printf();
extern u8 D_00289D20[];
extern u8 D_0028EC30;
extern u8 D_0028EC3C;

s32 func_00226260(void) {
    if (D_0028EC30 == 0) {
        switch (D_0028EC3C) {
        case 0:
            return 0;
        case 1:
            func_00226440();
            break;
        case 2:
            func_00226450();
            break;
        case 3:
            func_00226490();
            break;
        case 4:
            func_002264D0();
            break;
        case 5:
            return func_00226620();
        case 6:
            return func_00226700();
        case 7:
            func_00226830();
            break;
        }
    } else {
        switch (D_0028EC3C) {
        case 0:
            return 0;
        case 1:
            func_00226440();
            break;
        case 2:
            func_00226850();
            break;
        case 3:
            func_00226890();
            break;
        case 4:
            func_002268A0();
            break;
        case 5:
            printf(D_00289D20);
            break;
        case 6:
            return func_002269B0();
        case 7:
            func_00226830();
            break;
        }
    }
    return 1;
}
