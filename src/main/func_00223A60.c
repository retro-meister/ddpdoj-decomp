#include "common.h"

s32 func_0018CAD0();                            /* extern */
s32 func_00217D20();                            /* extern */
extern s8 D_0028E364;
extern s8 D_0028E36C;
extern u8 D_0028ED74;

void func_00223A60(void) {
    D_0028E36C = 0;
    func_0018CAD0();
    D_0028E364 = 0x3C;
    func_00217D20();
    if (D_0028ED74 == 3) {
        D_0028ED74 = 1;
    }
}
