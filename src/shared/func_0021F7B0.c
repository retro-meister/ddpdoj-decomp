#include "common.h"

s32 func_0021F820();
s32 func_0021F880();
s32 func_0021F8D0();
extern s8 D_0028EB5C;

void func_0021F7B0(void) {
    switch (D_0028EB5C) {                           /* irregular */
    case 0:
        func_0021F820(D_0028EB5C);
        break;
    case 1:
        func_0021F880(D_0028EB5C);
        break;
    case 2:
        func_0021F8D0(D_0028EB5C);
        /* fallthrough */
    case 3:
        break;
    }
}
