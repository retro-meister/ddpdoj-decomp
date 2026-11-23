#include "common.h"

s32 func_002288B0();
s32 func_002288E0();
s32 func_00228910();
extern u8 D_0028EC08;

void func_00228B50(void) {
    switch (D_0028EC08) {                           /* irregular */
    case 0:
        func_002288B0(D_0028EC08);
        break;
    case 1:
        func_002288E0(D_0028EC08);
        break;
    case 2:
        func_00228910(D_0028EC08);
        /* fallthrough */
    case 3:
        break;
    }
}
