#include "common.h"

s32 func_001A4140();
extern u8 D_0028E294;
extern s8 D_0028EB2C;
extern s32 D_0028EB94;

void func_00221080(void) {
    switch (D_0028EB2C) {                           /* irregular */
    case 0:
        break;
    case 1:
        D_0028EB94 += 4;
        if (D_0028EB94 >= 0x80) {
            D_0028EB2C = 0;
            D_0028EB94 = 0x80;
        }
        break;
    case 2:
        D_0028EB94 -= 4;
        if (D_0028EB94 <= 0) {
            D_0028EB94 = 0;
            D_0028EB2C = 0;
        }
        break;
    }
    if (D_0028EB94 != 0) {
        D_0028E294 = 1;
        func_001A4140();
    }
}
