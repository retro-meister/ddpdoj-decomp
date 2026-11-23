#include "common.h"

s32 func_00227900();
s32 func_00227930();
s32 func_00227960();
s32 func_002279A0();
extern u8 D_0028EBE8;

void func_00227AE0(void) {
    switch (D_0028EBE8) {                           /* irregular */
    case 0:
        func_00227900(D_0028EBE8);
        break;
    case 1:
        func_00227930(D_0028EBE8);
        break;
    case 2:
        func_00227960(D_0028EBE8);
        break;
    case 3:
        func_002279A0(D_0028EBE8);
        /* fallthrough */
    case 4:
        break;
    }
}
