#include "common.h"

s32 func_0021E6F0();
s32 func_0021E740();
s32 func_0021E790();
extern s8 D_0028EB70;

void func_0021E680(void) {
    switch (D_0028EB70) {                           /* irregular */
    case 0:
        func_0021E6F0(D_0028EB70);
        break;
    case 1:
        func_0021E740(D_0028EB70);
        break;
    case 2:
        func_0021E790(D_0028EB70);
        /* fallthrough */
    case 3:
        break;
    }
}
