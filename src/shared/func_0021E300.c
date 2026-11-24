#include "common.h"

s32 func_0021E370();
s32 func_0021E3C0();
s32 func_0021E410();
extern s8 D_0028EB74;

void func_0021E300(void) {
    switch (D_0028EB74) {                           /* irregular */
    case 0:
        func_0021E370(D_0028EB74);
        break;
    case 1:
        func_0021E3C0(D_0028EB74);
        break;
    case 2:
        func_0021E410(D_0028EB74);
        /* fallthrough */
    case 3:
        break;
    }
}
