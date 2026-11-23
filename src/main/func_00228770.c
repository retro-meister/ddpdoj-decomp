#include "common.h"

s32 func_00228520();
s32 func_00228550();
s32 func_00228580();
extern u8 D_0028EC10;

void func_00228770(void) {
    switch (D_0028EC10) {                           /* irregular */
    case 0:
        func_00228520(D_0028EC10);
        break;
    case 1:
        func_00228550(D_0028EC10);
        break;
    case 2:
        func_00228580(D_0028EC10);
        /* fallthrough */
    case 3:
        break;
    }
}
