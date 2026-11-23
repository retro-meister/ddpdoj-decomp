#include "common.h"

s32 func_00229DC0();
s32 func_00229DF0();
s32 func_00229E20();
extern u8 D_0028EBF8;

void func_0022A040(void) {
    switch (D_0028EBF8) {                           /* irregular */
    case 0:
        func_00229DC0(D_0028EBF8);
        break;
    case 1:
        func_00229DF0(D_0028EBF8);
        break;
    case 2:
        func_00229E20(D_0028EBF8);
        /* fallthrough */
    case 3:
        break;
    }
}
