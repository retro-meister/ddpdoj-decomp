#include "common.h"

s32 func_00227C90();
s32 func_00227CD0();
s32 func_00227FE0();
extern u8 D_0028EBE0;

void func_00227F70(void) {
    switch (D_0028EBE0) {                           /* irregular */
    case 0:
        func_00227C90(D_0028EBE0);
        break;
    case 1:
        func_00227CD0(D_0028EBE0);
        break;
    case 2:
        func_00227FE0(D_0028EBE0);
        /* fallthrough */
    case 3:
        break;
    }
}
