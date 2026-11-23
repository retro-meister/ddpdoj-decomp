#include "common.h"

s32 func_00228E20();
s32 func_00228E50();
s32 func_00228E80();
extern u8 D_0028EC00;

void func_002295F0(void) {
    switch (D_0028EC00) {                           /* irregular */
    case 0:
        func_00228E20(D_0028EC00);
        break;
    case 1:
        func_00228E50(D_0028EC00);
        break;
    case 2:
        func_00228E80(D_0028EC00);
        /* fallthrough */
    case 3:
        break;
    }
}
