#include "common.h"

extern void func_0022C6B0(s32 arg);
extern s32 func_002345B0(void);
extern void func_00235890(void);
extern s32 func_00235ED0(void);
extern u8 D_0028E278;
extern s32 D_0028EC7C;
extern s32 D_0028ED0C;

s32 func_002365A0(void) {
    if (D_0028E278 == 0) {
        D_0028EC7C = 10;
    }
    switch (D_0028EC7C) {
    case 0:
        if (func_00235ED0() != 0) {
            D_0028EC7C++;
        } else {
            D_0028EC7C = 10;
        }
        break;
    case 1:
        func_002345B0();
        D_0028ED0C = 0;
        D_0028EC7C++;
    case 2:
        func_0022C6B0(0);
        if (D_0028ED0C != 0) {
            D_0028ED0C = 0;
            D_0028EC7C = 10;
        }
        break;
    }
    if (D_0028EC7C == 10) {
        func_00235890();
        D_0028EC7C = 0;
        return 1;
    }
    return 0;
}
