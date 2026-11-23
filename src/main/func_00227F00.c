#include "common.h"

s32 func_00227CD0();
s32 func_00227E30();
s32 func_00227E70();
extern u8 D_0028EBE0;

void func_00227F00(void) {
    switch (D_0028EBE0) {                           /* irregular */
    case 0:
        func_00227E30(D_0028EBE0);
        break;
    case 1:
        func_00227CD0(D_0028EBE0);
        break;
    case 2:
        func_00227E70(D_0028EBE0);
        /* fallthrough */
    case 3:
        break;
    }
}
