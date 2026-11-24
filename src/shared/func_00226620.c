#include "common.h"

s32 func_0022C750();
s32 func_00233DA0();
s32 func_00233EC0();
s32 func_00236960();
extern s32 D_0028EABC;
extern s8 D_0028EB04;
extern s32 D_0028EB90;
extern u8 D_0028EC38;
extern s8 D_0028EC3C;
extern s8 D_0028EC40;
extern s32 D_0028ECC0;
extern s32 D_0028ED04;
extern s32 D_0028ED0C;

s32 func_00226620(void) {
    switch (D_0028EC38) {
    case 0:
        D_0028ED0C = 0;
        D_0028EC38 += 1;
    case 1:
        func_0022C750(D_0028EC40 + 1);
        if (D_0028ED0C != 0) {
            func_00233EC0();
            D_0028ED0C = 0;
            D_0028ED04 = 0;
            D_0028EC38 += 1;
            D_0028EABC = D_0028ECC0;
            if (D_0028ECC0 != 0) {
                func_00236960(D_0028EC40);
            }
        }
        break;
    case 2:
        if (func_00233DA0() != 0) {
            D_0028EB04 = 1;
            D_0028EB90 = 0x40;
            D_0028EC3C = 4;
            D_0028EC38 = 0;
            if (D_0028EABC != 0) {
                return 2;
            }
        }
        break;
    }
    return 1;
}
