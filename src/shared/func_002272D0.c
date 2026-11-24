#include "common.h"

s32 fade_start_out();                            /* extern */
extern s8 D_0028EAC8;
extern s8 D_0028EB00;
extern s8 D_0028EB54;
extern s8 D_0028EB84;
extern s8 D_0028EB88;

void func_002272D0(void) {
    D_0028EB54 = 2;
    D_0028EB00 = 3;
    D_0028EB88 = 2;
    D_0028EB84 = 0;
    fade_start_out();
    D_0028EAC8 = 1;
}
