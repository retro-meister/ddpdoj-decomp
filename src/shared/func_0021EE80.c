#include "common.h"

s32 func_0021EF10();
s32 func_0021EF60();
s32 func_0021EFB0();
s32 func_0021F180();
extern s8 D_0028EB68;

void func_0021EE80(void) {
    switch (D_0028EB68) {                           /* irregular */
    case 0:
        func_0021EF10(D_0028EB68);
        break;
    case 1:
        func_0021EF60(D_0028EB68);
        break;
    case 2:
        func_0021EFB0(D_0028EB68);
        break;
    case 3:
        func_0021F180(D_0028EB68);
        /* fallthrough */
    case 4:
        break;
    }
}
