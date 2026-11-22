#include "common.h"

s32 func_00226260();                                /* extern */
s32 func_002272D0();                            /* extern */
s32 func_002273E0();                            /* extern */
extern s8 D_0028EB50;
extern s8 D_0028EB54;
extern s8 D_0028EB84;
extern u8 D_0028EBE0;
extern s8 D_0028EBE1;
extern s16 D_0028EBE4;
extern s8 D_0028EC18;
extern s8 D_0028EC1A;
extern s8 D_0028EC20;
extern s8 D_0028ED7C;

void func_00227D00(void) {
    s32 temp_v0;

    func_002273E0();
    temp_v0 = func_00226260();
    switch (temp_v0) {                              /* irregular */
    case 0:
        D_0028EC1A = 3;
        D_0028EB54 = 0;
        D_0028EB84 = 7;
        D_0028EB50 = 0;
        D_0028EBE1 = 0;
        D_0028EBE4 = 0;
        D_0028EC18 = 0;
        return;
    case 3:
        D_0028ED7C = 2;
        D_0028EC20 = 1;
        D_0028EBE0 += 1;
        func_002272D0();
        return;
    }
}
