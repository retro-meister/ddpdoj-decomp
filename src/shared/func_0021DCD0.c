#include "common.h"

s32 func_0021DD40();
s32 func_0021DD90();
s32 func_0021DDE0();
extern s8 D_0028EB78;

void func_0021DCD0(void) {
    switch (D_0028EB78) {                           /* irregular */
    case 0:
        func_0021DD40(D_0028EB78);
        break;
    case 1:
        func_0021DD90(D_0028EB78);
        break;
    case 2:
        func_0021DDE0(D_0028EB78);
        /* fallthrough */
    case 3:
        break;
    }
}
