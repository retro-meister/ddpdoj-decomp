#include "common.h"

s32 func_0022A260();
s32 func_0022A2B0();
s32 func_0022A2E0();
extern u8 D_0028EBD8;

void func_0022A410(void) {
    switch (D_0028EBD8) {                           /* irregular */
    case 0:
        func_0022A260(D_0028EBD8);
        break;
    case 1:
        func_0022A2B0(D_0028EBD8);
        break;
    case 2:
        func_0022A2E0(D_0028EBD8);
        /* fallthrough */
    case 3:
        break;
    }
}
